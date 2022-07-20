
#include <mutex>

#include "IXFSWrapper.h"
#include "../../XFSWindow/IXFSWindow.h"
#include <DeviceUtility.h>
#include <NOVAGLOBALS.h>
#include <TTObjectPool/CODE/ITTObjectPool.h>
#include <TTLogger/CODE/ITTLogger.h>

namespace XFSWrapper
{
	constexpr auto XUP_LOOP = 3;

	bool IXFSWrapper::Initialize(TTObjectPool::ITTObjectPool* pObjectPool) noexcept
	{
		TRACELOG("IXFSWrapper::Initialize - Started");

		ASSERTSAFEPTR("IXFSWrapper::Initialize - FAILED because pObjectPool is NULL", pObjectPool);

		auto _weak = pObjectPool->GetComponent("XFSWindow");
		auto _shared = _weak.lock();
		ASSERTSAFEPTR("IXFSWrapper::Initialize - FAILED because _shared is NULL", _shared);

		auto _ptr = std::static_pointer_cast<XFSWindow::IXFSWindow>(_shared);
		ASSERTSAFEPTR("IXFSWrapper::Initialize - FAILED because _ptr is NULL", _ptr);

		this->m_hwnd = _ptr->GetWindowHandle();
		if (NULL == this->m_hwnd)
			return false;

		LPWFSVERSION _pWFSVersion = (LPWFSVERSION)malloc(sizeof(WFSVERSION));

		std::mutex				_mutex;
		std::condition_variable	_cv;
		HRESULT					_ret{ WFS_ERR_INTERNAL_ERROR };

		for (SIZE_T i = 0; i < XUP_LOOP; ++i)
		{
			std::thread _thread([_pWFSVersion, &_cv, &_ret]()
				{
					_ret = WFSStartUp(XFS_REQUIRED_VERSION, _pWFSVersion);
					_cv.notify_one();
				});

			_thread.detach();

			std::unique_lock<std::mutex> _unique_lock(_mutex);
			if (_cv.wait_for(_unique_lock, std::chrono::seconds(3)) == std::cv_status::timeout)
			{
				WARNLOG("IXFSWrapper::Initialize - WFSStartUp Timeout");
				if(XUP_LOOP != i)
					continue;
				else
				{
					ERRORLOG("IXFSWrapper::Initialize - WFSStartUp problem");
					return false;
				}
			}

			::free(_pWFSVersion);
			if (WFS_SUCCESS != _ret)
			{
				ERRORLOG("IXFSWrapper::Initialize - FAILD with error code: %d", NOVADESCRIBE_XFS_ERROR(_ret));
				return false;
			}
			else
				break;
		}

		this->m_bInitialized = true;

		TRACELOG("IXFSWrapper::Initialize - Ended");
		return true;
	}

	bool IXFSWrapper::UnInitialize() noexcept
	{
		TRACELOG("IXFSWrapper::UnInitialize - Started");

		std::mutex				_mutex;
		std::condition_variable	_cv;
		HRESULT					_ret;

		for (SIZE_T i = 0; i < XUP_LOOP; ++i)
		{
			std::thread _thread([&_cv, &_ret]()
				{
					_ret = WFSCleanUp();
					_cv.notify_one();
				});

			_thread.detach();

			std::unique_lock<std::mutex> _unique_lock(_mutex);
			if (_cv.wait_for(_unique_lock, std::chrono::seconds(3)) == std::cv_status::timeout)
				WARNLOG("IXFSWrapper::UnInitialize - WFSCleanUp Timeout");

			if (WFS_SUCCESS != _ret)
			{
				ERRORLOG("IXFSWrapper::UnInitialize - WFSCleanUp FAILED with error: %d", _ret);
				return false;
			}

			DEBUGLOG("IXFSWrapper::UnInitialize - WFSCleanUp returned: %d", _ret);

			m_bInitialized = FALSE;
			return true;
		}

		return false;

		this->m_bInitialized = FALSE;

		TRACELOG("IXFSWrapper::UnInitialize - Ended");
		return true;
	}
}