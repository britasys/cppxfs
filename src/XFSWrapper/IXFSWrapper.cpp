
#include <mutex>

#include "IXFSWrapper.h"
#include "../XFSWindow/IXFSWindow.h"

namespace __N_XFSWRAPPER__
{
	constexpr auto XUP_LOOP = 3;

	bool IXFSWrapper::Initialize() noexcept
	{
        if (this->m_bInitialized)
        {
            this->m_strLastError.assign("XFSWrapper is already initialized");
            return false;
        }

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
				if(XUP_LOOP != i)
					continue;
				else
				{
					this->m_strLastError.assign("FAILED to run WFSStartUp");
					return false;
				}
			}

			::free(_pWFSVersion);
			if (WFS_SUCCESS != _ret)
			{
				this->m_strLastError.assign("FAILD with error code: %d", NOVADESCRIBE_XFS_ERROR(_ret));
				return false;
			}
			else
				break;
		}

		this->m_bInitialized = true;

		return true;
	}

	bool IXFSWrapper::UnInitialize() noexcept
	{
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
				this->m_strLastError.assign("WFSCleanUp Timeout");

			if (WFS_SUCCESS != _ret)
			{
				this->m_strLastError.assign("WFSCleanUp FAILED with error: %d", _ret);
				return false;
			}

			m_bInitialized = FALSE;
			return true;
		}

		return false;

		this->m_bInitialized = FALSE;

		return true;
	}

    bool IXFSWrapper::IsInitialized() const noexcept
    {
        return this->m_bInitialized;
    }
} // !__N_XFSWRAPPER__