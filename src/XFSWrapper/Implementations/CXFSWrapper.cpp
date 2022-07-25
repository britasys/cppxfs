
#include "CXFSWrapper.h"

namespace XFSWrapper
{
    #define ASSERTINITIALIZE if (!this->m_bInitialized) return WFS_ERR_NOT_STARTED;
	#define ASSERTOPEN if (!hs) return WFS_ERR_CONNECTION_LOST;

	#define ASSERTNOBLOCKING while (WFSIsBlocking()) ::Sleep(20);

	//Open
	HRESULT CXFSWrapper::XFSOpenAsync(HSERVICE& hs, const std::string& LogicName, REQUESTID& ReqID) const noexcept
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
			this->m_pMSGWND->GetHandle(),
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
	HRESULT CXFSWrapper::XFSCloseAsync(const HSERVICE hs, REQUESTID& ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		HRESULT iret = WFS_SUCCESS;

		if (!hs)
			return WFS_SUCCESS;

		iret = WFSCancelBlockingCall(NULL);

		iret = WFSCancelAsyncRequest(hs, 0);

		ASSERTNOBLOCKING

		iret = WFSAsyncUnlock(hs, this->m_pMSGWND->GetHandle(), &ReqID);

		iret = WFSAsyncClose(hs, this->m_pMSGWND->GetHandle(), &ReqID);

		return iret;
	}

	HRESULT CXFSWrapper::XFSOpenSync(HSERVICE& hs, const char* LogicName) const noexcept
	{
        ASSERTINITIALIZE

		int iret = WFS_SUCCESS;

		WFSVERSION f_srv_ver;
		WFSVERSION f_spi_ver;

		ASSERTNOBLOCKING

		const char* _lpstrAppName = "NOVA.exe";
		iret = WFSOpen
		(
			(LPSTR)LogicName,
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

	HRESULT CXFSWrapper::XFSCloseSync(HSERVICE& hs) const noexcept
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
								  this->m_pMSGWND->GetHandle(),
								  this->m_pMSGWND->GetHandle(),
								  &ReqID);*/

		iret = WFSClose(hs);

		return iret;
	}

	//Lock
	HRESULT CXFSWrapper::XFSLock(HSERVICE hs, long Timeout, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncLock(hs, Timeout, this->m_pMSGWND->GetHandle(), &ReqID);
	}

	//UnLock
	HRESULT CXFSWrapper::XFSUnLock(HSERVICE hs, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncUnlock(hs, this->m_pMSGWND->GetHandle(), &ReqID);
	}

	HRESULT CXFSWrapper::XFSRegisterAsync(HSERVICE hs, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncRegister
		(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			this->m_pMSGWND->GetHandle(),
			this->m_pMSGWND->GetHandle(),
			&ReqID);
	}

	HRESULT CXFSWrapper::XFSDeregisterAsync(HSERVICE hs, REQUESTID & ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncDeregister(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			this->m_pMSGWND->GetHandle(),
			this->m_pMSGWND->GetHandle(),
			&ReqID);
	}

	HRESULT CXFSWrapper::XFSRegisterSync(HSERVICE hs) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSRegister
		(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			this->m_pMSGWND->GetHandle()
		);
	}

	HRESULT CXFSWrapper::XFSDeregisterSync(HSERVICE hs) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSDeregister
		(
			hs,
			SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
			this->m_pMSGWND->GetHandle()
		);
	}

	//Cancel
	HRESULT CXFSWrapper::XFSCancel(HSERVICE hs, REQUESTID ReqID) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSCancelAsyncRequest(hs, ReqID);
	}

	//Free
	HRESULT CXFSWrapper::XFSFree(LPWFSRESULT * ppResult) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		HRESULT hrRet = WFS_SUCCESS;

		if (*ppResult)
		{
			hrRet = WFSFreeResult(*ppResult);
			*ppResult = NULL;
		}
        
		return hrRet;
	}

	HRESULT CXFSWrapper::XFSGetInfoAsync(HSERVICE hs, DWORD dwCategory, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSAsyncGetInfo(hs, dwCategory, pIn, Timeout, this->m_pMSGWND->GetHandle(), &ReqID);
	}

	//Execute
	HRESULT CXFSWrapper::XFSExecuteAsync(HSERVICE hs, DWORD dwCommand, void* pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		ASSERTNOBLOCKING

		return WFSAsyncExecute(
            hs,
			dwCommand,
			pIn,
			Timeout,
			this->m_pMSGWND->GetHandle(),
			&ReqID);
	}

	HRESULT CXFSWrapper::XFSGetInfoSync(HSERVICE hs, DWORD dwCategory, LPVOID lpQueryDetails, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return = WFSGetInfo(hs, dwCategory, lpQueryDetails, dwTimeOut, lppResult);
	}

	HRESULT CXFSWrapper::XFSExecuteSync(HSERVICE hs, DWORD dwCommand, LPVOID lpCmdData, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept
	{
        ASSERTINITIALIZE ASSERTOPEN

		return WFSExecute(hs, dwCommand, lpCmdData, dwTimeOut, lppResult);
	}

	std::shared_ptr<IXFSWrapper>CreateXFSWrapper() noexcept
	{
		return std::make_shared<XFSWrapper::CXFSWrapper>();
	}
}