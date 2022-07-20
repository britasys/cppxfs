
#include "CXFSWrapper.h"
#include <XFSWindow/IXFSWindow.h>
#include <TTLogger/CODE/ITTLogger.h>

namespace XFSWrapper
{
	#define ASSERTOPEN if (!hs) return WFS_ERR_CONNECTION_LOST;

	#define ASSERTNOBLOCKING while (WFSIsBlocking()) ::Sleep(20);

	BOOL CXFSWrapper::IsConnected(HSERVICE hs) const noexcept
	{
		return (hs ? TRUE : FALSE);
	}

	//Open
	HRESULT CXFSWrapper::XFSOpenAsync(HSERVICE& hs, const char* LogicName, REQUESTID& ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSOpenAsync - Started");

		int iret = WFS_SUCCESS;

		WFSVERSION f_srv_ver;
		WFSVERSION f_spi_ver;

		//	try {

		if (hs)
		{
			return WFS_SUCCESS;
		}
		//throw WFS_SUCCESS;

		ASSERTNOBLOCKING

			const char* _lpstrAppName = "NOVA.exe";
			iret = WFSAsyncOpen
			(
				(LPSTR)LogicName,
				WFS_DEFAULT_HAPP,
				(LPSTR)_lpstrAppName,
				0,
				300000,
				&hs,
				this->m_hwnd,
				0x01019903,
				&f_srv_ver,
				&f_spi_ver,
				&ReqID
			);

		//		throw iret;

		//	} catch (int eret) {

		//		iret = eret;
		if (iret != WFS_SUCCESS)
			hs = 0;

		//	}

		TRACELOG("CXFSWrapper::XFSOpenAsync - Ended");
		return iret;
	}

	//Close
	HRESULT CXFSWrapper::XFSCloseAsync(HSERVICE& hs, REQUESTID& ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSCloseAsync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		if (!hs)
		{
			return WFS_SUCCESS;
		}
		//	throw WFS_SUCCESS;

		iret = WFSCancelBlockingCall(NULL);

		iret = WFSCancelAsyncRequest(hs, 0);

		ASSERTNOBLOCKING

			iret = WFSAsyncUnlock(hs, this->m_hwnd, &ReqID);

		/*iret = WFSAsyncDeregister(hs,
								  15,
								  this->m_hwnd,
								  this->m_hwnd,
								  &ReqID);*/

		iret = WFSAsyncClose(hs,
			this->m_hwnd,
			&ReqID);
		if (WFS_SUCCESS != iret)
			return iret;

		// hs = 0;

//		throw iret;

//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSCloseAsync - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSOpenSync(HSERVICE& hs, const char* LogicName) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSOpenSync - Started");

		int iret = WFS_SUCCESS;

		WFSVERSION f_srv_ver;
		WFSVERSION f_spi_ver;

		//	try {

		/*if (hs)
		{
			return WFS_SUCCESS;
		}*/
		//throw WFS_SUCCESS;

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

		//		throw iret;

		//	} catch (int eret) {

		//		iret = eret;
		if (iret != WFS_SUCCESS)
			hs = 0;

		//	}

		TRACELOG("CXFSWrapper::XFSOpenSync - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSCloseSync(HSERVICE& hs) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSCloseSync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		if (!hs)
		{
			return WFS_SUCCESS;
		}
		//	throw WFS_SUCCESS;

		iret = WFSCancelBlockingCall(NULL);

		iret = WFSCancelAsyncRequest(hs, 0);

		ASSERTNOBLOCKING

		iret = WFSUnlock(hs);

		/*iret = WFSAsyncDeregister(hs,
								  15,
								  this->m_hwnd,
								  this->m_hwnd,
								  &ReqID);*/

		iret = WFSClose(hs);
		if (WFS_SUCCESS != iret)
			return iret;

		// hs = 0;

//		throw iret;

//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSCloseSync - Ended");
		return iret;
	}

	//Lock
	HRESULT CXFSWrapper::XFSLock(HSERVICE hs, long Timeout, REQUESTID & ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSLock - Started");

		HRESULT iret = WFS_SUCCESS;

		//try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			iret = WFSAsyncLock(hs,
				Timeout,
				this->m_hwnd,
				&ReqID);

		//throw iret;

//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSLock - Ended");
		return iret;
	}

	//UnLock
	HRESULT CXFSWrapper::XFSUnLock(HSERVICE hs, REQUESTID & ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSUnLock - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			iret = WFSAsyncUnlock(hs,
				this->m_hwnd,
				&ReqID);


		//		throw iret;

		//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSUnLock - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSRegisterAsync(HSERVICE hs, REQUESTID & ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSRegisterAsync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			//Ö´ÐÐRegister
			iret = WFSAsyncRegister
			(
				hs,
				SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
				this->m_hwnd,
				this->m_hwnd,
				&ReqID);
		//	throw iret;

	//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSRegisterAsync - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSDeregisterAsync(HSERVICE hs, REQUESTID & ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSDeregisterAsync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			//Ö´ÐÐRegister
			iret = WFSAsyncDeregister(
				hs,
				15,
				this->m_hwnd,
				this->m_hwnd,
				&ReqID);
		//	throw iret;

		//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSDeregisterAsync - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSRegisterSync(HSERVICE hs) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSRegisterSync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			//Ö´ÐÐRegister
			iret = WFSRegister
			(
				hs,
				SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
				this->m_hwnd
			);
		//	throw iret;

	//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSRegisterSync - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSDeregisterSync(HSERVICE hs) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSDeregisterSync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			//Ö´ÐÐRegister
			iret = WFSDeregister
			(
				hs,
				SERVICE_EVENTS | USER_EVENTS | SYSTEM_EVENTS | EXECUTE_EVENTS,
				this->m_hwnd
			);
		//	throw iret;

		//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSDeregisterSync - Ended");
		return iret;
	}

	//Cancel
	HRESULT CXFSWrapper::XFSCancel(HSERVICE hs, REQUESTID ReqID) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSCancel - Started");

		HRESULT iret = WFS_SUCCESS;
		//::Sleep(137);

	//	try {

		ASSERTOPEN

			// 		if(WFSIsBlocking())
			// 		{
			//
			// 			iret = WFSCancelBlockingCall(NULL);
			// 			throw iret;
			// 		}

			iret = WFSCancelAsyncRequest(hs, ReqID);

		//	throw iret;

	//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSCancel - Ended");
		return iret;
	}

	//Free
	HRESULT CXFSWrapper::XFSFree(LPWFSRESULT * ppResult) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSFree - Started");

		HRESULT hrRet = WFS_SUCCESS;

		if (*ppResult)
		{
			hrRet = WFSFreeResult(*ppResult);
			*ppResult = NULL;
		}

		TRACELOG("CXFSWrapper::XFSFree - Ended");
		return hrRet;
	}

	HRESULT CXFSWrapper::XFSGetInfoAsync(HSERVICE hs, DWORD dwCategory, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSGetInfoAsync - Started");

		HRESULT iret = WFS_SUCCESS;

		//	try {

		ASSERTOPEN

			iret = WFSAsyncGetInfo(hs, dwCategory, pIn, Timeout, this->m_hwnd, &ReqID);

		//	throw iret;

	//	} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSGetInfoAsync - Ended");
		return iret;
	}

	//Execute
	HRESULT CXFSWrapper::XFSExecuteAsync(HSERVICE hs, DWORD dwCommand, void* pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSExecuteAsync - Started");

		HRESULT iret = WFS_SUCCESS;

		//try {

		ASSERTOPEN

			ASSERTNOBLOCKING

			iret = WFSAsyncExecute(hs,
				dwCommand,
				pIn,
				Timeout,
				this->m_hwnd,
				&ReqID);


		//throw iret;

	//} catch (int eret) { iret = eret; }

		TRACELOG("CXFSWrapper::XFSExecuteAsync - Ended");
		return iret;
	}

	HRESULT CXFSWrapper::XFSGetInfoSync(HSERVICE hs, DWORD dwCategory, LPVOID lpQueryDetails, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSGetInfoSync - Started");

		ASSERTOPEN

			auto _hrRet = WFSGetInfo(hs, dwCategory, lpQueryDetails, dwTimeOut, lppResult);

		TRACELOG("CXFSWrapper::XFSGetInfoSync - Ended");
		return _hrRet;
	}

	HRESULT CXFSWrapper::XFSExecuteSync(HSERVICE hs, DWORD dwCommand, LPVOID lpCmdData, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept
	{
		TRACELOG("CXFSWrapper::XFSExecuteSync - Started");

		ASSERTOPEN

			auto _hrRet = WFSExecute(hs, dwCommand, lpCmdData, dwTimeOut, lppResult);

		TRACELOG("CXFSWrapper::XFSExecuteSync - Ended");
		return _hrRet;
	}

	std::shared_ptr<IXFSWrapper>CreateXFSWrapper() noexcept
	{
		return std::make_shared<XFSWrapper::CXFSWrapper>();
	}
}