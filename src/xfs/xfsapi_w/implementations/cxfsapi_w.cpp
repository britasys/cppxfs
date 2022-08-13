
#include "cxfsapi_w.hpp"

#include <mutex>
#include <thread>
#include <condition_variable>

namespace __N_XFSAPI_W__
{
	#define ASSERTNOBLOCKING while (::WFSIsBlocking()) ::Sleep(20);

    constexpr unsigned short int XUP_LOOP = 3;
        
    HRESULT CXFSAPI_W::WFSStartUp(WFSSTARTUP_P& wfsstartup_p) const noexcept(false)
    {
        if (0x00000000 == wfsstartup_p.dwVersionRequired) throw std::invalid_argument("dwVersionRequired is ZERO");

		std::mutex				l_mutex;
		std::condition_variable	l_cv;
		HRESULT					l_ret{ WFS_ERR_INTERNAL_ERROR };

		for (size_t i = 0; i < XUP_LOOP; ++i)
		{
			std::thread l_thread([&wfsstartup_p, &l_cv, &l_ret]()
			{
				l_ret = ::WFSStartUp(wfsstartup_p.dwVersionRequired, &wfsstartup_p.WFSVersion);
				l_cv.notify_one();
			});

			l_thread.detach();

			std::unique_lock<std::mutex> _unique_lock(l_mutex);
			if (l_cv.wait_for(_unique_lock, std::chrono::seconds(3)) == std::cv_status::timeout)
			{
				if(XUP_LOOP != i)
					continue;
				else
					return WFS_ERR_INTERNAL_ERROR;
			}

			if (WFS_SUCCESS != l_ret)
				return l_ret;
			else
				break;
		}

		return l_ret;
    }

    HRESULT CXFSAPI_W::WFSCleanUp() const noexcept
    {
		std::mutex				l_mutex;
		std::condition_variable	l_cv;
		HRESULT					l_ret;

		for (size_t i = 0; i < XUP_LOOP; ++i)
		{
			std::thread l_thread([&l_cv, &l_ret]()
			{
				l_ret = ::WFSCleanUp();
				l_cv.notify_one();
			});

			l_thread.detach();

			std::unique_lock<std::mutex> _unique_lock(l_mutex);
			if (l_cv.wait_for(_unique_lock, std::chrono::seconds(3)) == std::cv_status::timeout)
			{
				if(XUP_LOOP != i)
					continue;
				else
					return WFS_ERR_INTERNAL_ERROR;
			}

			if (WFS_SUCCESS != l_ret)
				return l_ret;
			else
				break;
		}

		return l_ret;
    }
    
    HRESULT CXFSAPI_W::WFSOpen(WFSOPEN_P& wfsopen_p) const noexcept(false)
    {
        if (wfsopen_p.strLogicName.empty())                     throw std::invalid_argument("strLogicName is EMPTY");
        if (NULL        == wfsopen_p.hApp)                      throw std::invalid_argument("hApp is NULL");
        if (wfsopen_p.strAppID.empty())                         throw std::invalid_argument("strAppID is EMPTY");
        if (0x00000000  == wfsopen_p.dwSrvcVersionsRequired)    throw std::invalid_argument("dwSrvcVersionsRequired is NULL");

		ASSERTNOBLOCKING

		return ::WFSOpen
		(
			(LPSTR)wfsopen_p.strLogicName.c_str(),
			wfsopen_p.hApp,
			(LPSTR)wfsopen_p.strAppID.c_str(),
			wfsopen_p.dwTraceLevel,
			wfsopen_p.dwTimeOut,
			wfsopen_p.dwSrvcVersionsRequired,
			&wfsopen_p.SrvcVersion,
			&wfsopen_p.SPIVersion,
			&wfsopen_p.hService
		);
    }

    HRESULT CXFSAPI_W::WFSAsyncOpen(WFSOPEN_P& wfsopen_p, const HWND hwnd, REQUESTID& RequestID) const noexcept(false)
	{
        if (wfsopen_p.strLogicName.empty())                     throw std::invalid_argument("strLogicName is EMPTY");
        if (NULL        == wfsopen_p.hApp)                      throw std::invalid_argument("hApp is NULL");
        if (wfsopen_p.strAppID.empty())                         throw std::invalid_argument("strAppID is EMPTY");
        if (0x00000000  == wfsopen_p.dwSrvcVersionsRequired)    throw std::invalid_argument("dwSrvcVersionsRequired is NULL");

		ASSERTNOBLOCKING
        
		return ::WFSAsyncOpen
		(
			(LPSTR)wfsopen_p.strLogicName.c_str(),
			wfsopen_p.hApp,
			(LPSTR)wfsopen_p.strAppID.c_str(),
			wfsopen_p.dwTraceLevel,
			wfsopen_p.dwTimeOut,
			&wfsopen_p.hService,
			hwnd,
			wfsopen_p.dwSrvcVersionsRequired,
			&wfsopen_p.SrvcVersion,
			&wfsopen_p.SPIVersion,
			&RequestID
		);
	}
    
    HRESULT CXFSAPI_W::WFSClose(const WFSCLOSE_P& wfsclose_p) const noexcept
    {
		::WFSCancelBlockingCall(NULL);

		::WFSCancelAsyncRequest(wfsclose_p.hService, NULL);

		ASSERTNOBLOCKING

		::WFSUnlock(wfsclose_p.hService);

        REQUESTID l_requestID{ NULL };

		return ::WFSClose(wfsclose_p.hService);
    }

    HRESULT CXFSAPI_W::WFSAsyncClose(const WFSCLOSE_P& wfsclose_p, const HWND hwnd, REQUESTID& RequestID) const noexcept
	{
		::WFSCancelBlockingCall(NULL);

		::WFSCancelAsyncRequest(wfsclose_p.hService, NULL);

		ASSERTNOBLOCKING

		::WFSUnlock(wfsclose_p.hService);

		return ::WFSAsyncClose(wfsclose_p.hService, hwnd, &RequestID);
	}
    
    HRESULT CXFSAPI_W::WFSRegister(const WFSREGISTER_P& wfsregister_p) const noexcept(false)
	{
        if (NULL == wfsregister_p.hService)     throw std::invalid_argument("hService is NULL");
        if (NULL == wfsregister_p.hWndReg)      throw std::invalid_argument("hWndReg is NULL");

		ASSERTNOBLOCKING

		return ::WFSRegister(wfsregister_p.hService, wfsregister_p.dwEventClass, wfsregister_p.hWndReg);
	}

    HRESULT CXFSAPI_W::WFSAsyncRegister(const WFSREGISTER_P& wfsregister_p, const HWND hwnd, REQUESTID& RequestID) const noexcept(false)
	{
        if (NULL == wfsregister_p.hService)     throw std::invalid_argument("hService is NULL");
        if (NULL == wfsregister_p.hWndReg)      throw std::invalid_argument("hWndReg is NULL");

		ASSERTNOBLOCKING

		return ::WFSAsyncRegister(wfsregister_p.hService, wfsregister_p.dwEventClass, wfsregister_p.hWndReg, hwnd, &RequestID);
	}
    
    HRESULT CXFSAPI_W::WFSDeRegister(const WFSREGISTER_P& wfsregister_p) const noexcept(false)
    {
        if (NULL == wfsregister_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

		return ::WFSDeregister(wfsregister_p.hService, wfsregister_p.dwEventClass, wfsregister_p.hWndReg);
    }

    HRESULT CXFSAPI_W::WFSAsyncDeregister(const WFSREGISTER_P& wfsregister_p, const HWND hwnd, REQUESTID& RequestID) const noexcept(false)
    {        
        if (NULL == wfsregister_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

		return ::WFSAsyncDeregister(wfsregister_p.hService, wfsregister_p.dwEventClass, wfsregister_p.hWndReg, hwnd, &RequestID);
    }
    
	HRESULT CXFSAPI_W::WFSLock(const WFSLOCK_P& wfslock_p, WFSRESULT_W& wfsresult_w) const noexcept(false)
    {
        if (NULL == wfslock_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

        ::LPWFSRESULT l_lpwfsresult{ nullptr };
		auto l_ret = ::WFSLock(wfslock_p.hService, wfslock_p.dwTimeOut, &l_lpwfsresult);
        wfsresult_w = &l_lpwfsresult;

        return l_ret;
    }

    HRESULT CXFSAPI_W::WFSAsyncLock(const WFSLOCK_P& wfslock_p, HWND hwnd, REQUESTID& RequestID) const noexcept(false)
    {
        if (NULL == wfslock_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

		return ::WFSAsyncLock(wfslock_p.hService, wfslock_p.dwTimeOut, hwnd, &RequestID);
    }
    
	HRESULT CXFSAPI_W::WFSUnlock(const WFSUNLOCK_P& wfsunlock_p) const noexcept(false)
	{
        if (NULL == wfsunlock_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

		return ::WFSUnlock(wfsunlock_p.hService);
	}

    HRESULT CXFSAPI_W::WFSAsyncUnlock(const WFSUNLOCK_P& wfsunlock_p, HWND hwnd, REQUESTID& RequestID) const noexcept(false)
	{
        if (NULL == wfsunlock_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

		return ::WFSAsyncUnlock(wfsunlock_p.hService, hwnd, &RequestID);
	}
    
	HRESULT CXFSAPI_W::WFSCancelAsyncRequest(const WFSCANCELASYNCREQUEST_P& wfscancelasyncrequest_p) const noexcept
    {
        if (NULL == wfscancelasyncrequest_p.hService) throw std::invalid_argument("hService is NULL");

		ASSERTNOBLOCKING

		return ::WFSCancelAsyncRequest(wfscancelasyncrequest_p.hService, wfscancelasyncrequest_p.RequestID);
    }

    HRESULT CXFSAPI_W::WFSCancelBlockingCall(const WFSCANCELBLOCKINGCALL_P& wfscancelblockingcall_p) const noexcept
    {
		return ::WFSCancelBlockingCall(wfscancelblockingcall_p.dwThreadID);
    }

	HRESULT CXFSAPI_W::WFSFreeResult(const WFSFREERESULT_P& wfsfreeresult_p) const noexcept
	{
		return ::WFSFreeResult(wfsfreeresult_p.lpWFSResult);
	}
    
    HRESULT CXFSAPI_W::WFSCreateAppHandle(LPHAPP lpApp) const noexcept(false)
    {
        if (!lpApp) throw std::invalid_argument("lpApp is NULL");

        return ::WFSCreateAppHandle(lpApp);
    }

    HRESULT CXFSAPI_W::WFSDestroyAppHandle(const HAPP hApp) const noexcept(false)
    {
        if (!hApp) throw std::invalid_argument("hApp is NULL");

        return ::WFSDestroyAppHandle(hApp);
    }

    BOOL CXFSAPI_W::WFSIsBlocking() const noexcept
    {
        return ::WFSIsBlocking();
    }

    HRESULT CXFSAPI_W::WFSSetBlockingHook(WFSSETBLOCKINGHOOK_P& wfssetblockinghook_p) const noexcept(false)
    {
        if (!wfssetblockinghook_p.lpBlockFunc) throw std::invalid_argument("lpBlockFunc is NULL");

        return ::WFSSetBlockingHook(wfssetblockinghook_p.lpBlockFunc, &wfssetblockinghook_p.lpPrevFunc);
    }

    HRESULT CXFSAPI_W::WFSUnhookBlockingHook() const noexcept(false)
    {
        return ::WFSUnhookBlockingHook();
    }

    HRESULT CXFSAPI_W::WFSGetInfo(const WFSGETINFO_P& wfsgetinfo_p, WFSRESULT_W& wfsresult_w) const noexcept(false)
    {
        if (!wfsgetinfo_p.hService)     throw std::invalid_argument("hService is NULL");
        if (!wfsgetinfo_p.dwCategory)   throw std::invalid_argument("dwCategory is NULL");

        LPWFSRESULT l_lpwfsresult{ nullptr };
        auto l_ret = ::WFSGetInfo(wfsgetinfo_p.hService, wfsgetinfo_p.dwCategory, wfsgetinfo_p.lpQueryDetails, wfsgetinfo_p.dwTimeOut, &l_lpwfsresult);
        wfsresult_w = *l_lpwfsresult;
        
        return l_ret;
    }

    HRESULT CXFSAPI_W::WFSAsyncGetInfo(const WFSGETINFO_P& wfsgetinfo_p, const HWND hwnd, REQUESTID& RequestID) const noexcept(false)
    {
        if (!wfsgetinfo_p.hService)     throw std::invalid_argument("hService is NULL");
        if (!wfsgetinfo_p.dwCategory)   throw std::invalid_argument("dwCategory is NULL");

        return ::WFSAsyncGetInfo(wfsgetinfo_p.hService, wfsgetinfo_p.dwCategory, wfsgetinfo_p.lpQueryDetails, wfsgetinfo_p.dwTimeOut, hwnd, &RequestID);
    }

	HRESULT CXFSAPI_W::WFSExecute(const WFSEXECUTE_P& wfsexecute_p, WFSRESULT_W& wfsresult_w) const noexcept
    {
        if (!wfsexecute_p.hService)     throw std::invalid_argument("hService is NULL");
        if (!wfsexecute_p.dwCommand)    throw std::invalid_argument("dwCommand is NULL");

		ASSERTNOBLOCKING

        LPWFSRESULT l_lpwfsresult{ nullptr };
        auto l_ret = ::WFSExecute(wfsexecute_p.hService, wfsexecute_p.dwCommand, wfsexecute_p.lpCmdData, wfsexecute_p.dwTimeOut, &l_lpwfsresult);
        wfsresult_w = *l_lpwfsresult;
        
        return l_ret;
    }

	HRESULT CXFSAPI_W::WFSAsyncExecute(const WFSEXECUTE_P& wfsexecute_p, const HWND hwnd, REQUESTID& RequestID) const noexcept
    {
        if (!wfsexecute_p.hService)     throw std::invalid_argument("hService is NULL");
        if (!wfsexecute_p.dwCommand)    throw std::invalid_argument("dwCommand is NULL");

		ASSERTNOBLOCKING

		return ::WFSAsyncExecute(wfsexecute_p.hService, wfsexecute_p.dwCommand, wfsexecute_p.lpCmdData, wfsexecute_p.dwTimeOut, hwnd, &RequestID);
    }

	std::shared_ptr<IXFSAPI_W> CreateXFSAPIWrapper() noexcept;
	{
		return std::make_shared<CXFSAPI_W>();
	}
} // !__N_XFSAPI_W__