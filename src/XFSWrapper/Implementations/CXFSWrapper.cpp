
#include "CXFSWrapper.hpp"

namespace __N_XFSWRAPPER__
{
    #define ASSERTINITIALIZE if (!this->m_bInitialized) return WFS_ERR_NOT_STARTED;
	#define ASSERTOPEN if (!hs) return WFS_ERR_CONNECTION_LOST;

	#define ASSERTNOBLOCKING while (WFSIsBlocking()) ::Sleep(20);

	//Open
	HRESULT CXFSWrapper::XFSOpenAsync(HSERVICE& hs, const XFSHWND hwnd, const std::string& LogicName, REQUESTID& ReqID) const noexcept
	{
        ASSERTINITIALIZE

		int iret = WFS_SUCCESS;

		WFSVERSION f_srv_ver;
		WFSVERSION f_spi_ver;

		if (hs)
			return WFS_SUCCESS;

		ASSERTNOBLOCKING

		const char* _lpstrAppName = "NOVA.exe";
		iret = WFSAsyncOpen
		(
			(LPSTR)LogicName.c_str(),
			WFS_DEFAULT_HAPP,
			(LPSTR)_lpstrAppName,
			0,
			300000,
			&hs,
			(HWND)hwnd,
			0x01019903,
			&f_srv_ver,
			&f_spi_ver,
			&ReqID
		);

		if (iret != WFS_SUCCESS)
			hs = 0;

		return iret;
	}

	//Close
	HRESULT CXFSWrapper::XFSCloseAsync(const HSERVICE hs, const XFSHWND hwnd, REQUESTID& ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		HRESULT iret = WFS_SUCCESS;

		if (!hs)
			return WFS_SUCCESS;

		iret = WFSCancelBlockingCall(NULL);

		iret = WFSCancelAsyncRequest(hs, 0);

		ASSERTNOBLOCKING

		iret = WFSAsyncUnlock(hs, (HWND)hwnd, &ReqID);

		iret = WFSAsyncClose(hs, (HWND)hwnd, &ReqID);

		return iret;
	}

	HRESULT CXFSWrapper::XFSOpenSync(HSERVICE& hs, const std::string& LogicName) const noexcept
	{
        ASSERTINITIALIZE

		int iret = WFS_SUCCESS;

		WFSVERSION f_srv_ver;
		WFSVERSION f_spi_ver;

		ASSERTNOBLOCKING

		const char* _lpstrAppName = "NOVA.exe";
		iret = WFSOpen
		(
			(LPSTR)LogicName.c_str(),
			WFS_DEFAULT_HAPP,
			(LPSTR)_lpstrAppName,
			NULL,
			300000,
			0x01019903,
			&f_srv_ver,
			&f_spi_ver,
			&hs
		);

		if (iret != WFS_SUCCESS)
			hs = 0;
        
		return iret;
	}

	HRESULT CXFSWrapper::XFSCloseSync(const HSERVICE hs) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		HRESULT iret = WFS_SUCCESS;

		if (!hs)
			return WFS_SUCCESS;

		iret = WFSCancelBlockingCall(NULL);

		iret = WFSCancelAsyncRequest(hs, 0);

		ASSERTNOBLOCKING

		iret = WFSUnlock(hs);

		/*iret = WFSAsyncDeregister(hs,
								  15,
								  hwnd,
								  hwnd,
								  &ReqID);*/

		iret = WFSClose(hs);

		return iret;
	}

	//Lock
	HRESULT CXFSWrapper::XFSLock(const HSERVICE hs, const XFSHWND hwnd, const TIMEOUT Timeout, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncLock(hs, Timeout, (HWND)hwnd, &ReqID);
	}

	//UnLock
	HRESULT CXFSWrapper::XFSUnLock(const HSERVICE hs, const XFSHWND hwnd, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncUnlock(hs, (HWND)hwnd, &ReqID);
	}

	HRESULT CXFSWrapper::XFSRegisterAsync(const HSERVICE hs, const XFSHWND hwnd, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncRegister(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			(HWND)hwnd,
			(HWND)hwnd,
			&ReqID);
	}

	HRESULT CXFSWrapper::XFSDeregisterAsync(const HSERVICE hs, const XFSHWND hwnd, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncDeregister(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			(HWND)hwnd,
			(HWND)hwnd,
			&ReqID);
	}

	HRESULT CXFSWrapper::XFSRegisterSync(const HSERVICE hs, const XFSHWND hwnd) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSRegister
		(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			(HWND)hwnd
		);
	}

	HRESULT CXFSWrapper::XFSDeregisterSync(const HSERVICE hs, const XFSHWND hwnd) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSDeregister
		(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			(HWND)hwnd
		);
	}

	//Cancel
	HRESULT CXFSWrapper::XFSCancel(const HSERVICE hs, REQUESTID ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSCancelAsyncRequest(hs, ReqID);
	}

	//Free
	HRESULT CXFSWrapper::XFSFree(LPWFSRESULT* ppResult) const noexcept
	{
        ASSERTINITIALIZE

		HRESULT hrRet = WFS_SUCCESS;

		if (*ppResult)
		{
			hrRet = WFSFreeResult(*ppResult);
			*ppResult = NULL;
		}
        
		return hrRet;
	}

	HRESULT CXFSWrapper::XFSGetInfoAsync(const HSERVICE hs, const XFSHWND hwnd, DWORD dwCategory, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSAsyncGetInfo(hs, dwCategory, pIn, Timeout, (HWND)hwnd, &ReqID);
	}

	//Execute
	HRESULT CXFSWrapper::XFSExecuteAsync(const HSERVICE hs, const XFSHWND hwnd, DWORD dwCommand, void* pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncExecute(hs, dwCommand, pIn, Timeout, (HWND)hwnd, &ReqID);
	}

	HRESULT CXFSWrapper::XFSGetInfoSync(const HSERVICE hs, DWORD dwCategory, LPVOID lpQueryDetails, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSGetInfo(hs, dwCategory, lpQueryDetails, dwTimeOut, lppResult);
	}

	HRESULT CXFSWrapper::XFSExecuteSync(const HSERVICE hs, DWORD dwCommand, LPVOID lpCmdData, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSExecute(hs, dwCommand, lpCmdData, dwTimeOut, lppResult);
	}

	std::shared_ptr<IXFSWrapper>CreateXFSWrapper() noexcept
	{
		return std::make_shared<CXFSWrapper>();
	}
} // !__N_XFSWRAPPER__