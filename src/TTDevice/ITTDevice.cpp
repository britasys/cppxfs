
#include "ITTDevice.h"
#include <TTLogger\CODE\ITTLogger.h>
#include <TTObjectPool/CODE/ITTObjectPool.h>

namespace TTDevice
{
	void ITTDevice::InformRegisteredComponents(NOVAGLOBALS::DEVEVENTDATA& data) noexcept
	{
		TRACELOG("ITTDevice::InformRegisteredComponents - Started");

		for (auto elem : this->m_contCallbackFunctions)
		{
			data.DeviceUID = this->m_DeviceUID;
			data.XFSVersion = this->m_eXFSVersion;
			elem.second(data);
		}

		TRACELOG("ITTDevice::InformRegisteredComponents - Ended");
	}
	
	void ITTDevice::OnOpenComplete(LPARAM lParam) noexcept
	{
		TRACELOG("ITTDevice::OnOpenComplete - Started - (%s)", m_szLogicName.c_str());

		HRESULT		l_hResult = WFS_SUCCESS;
		REQUESTID	l_ReqID = 0;

		l_hResult = ((LPWFSRESULT)lParam)->hResult;
		if (WFS_SUCCESS != l_hResult)
		{
			ERRORLOG("ITTDevice::OnOpenComplete - (%s) FAILED WFSRESULT.hResult is: (%d) - %s",
				m_szLogicName.c_str(), l_hResult, NOVADESCRIBE_XFS_ERROR(l_hResult));
			return;
		}

		TT_DEV_ASSERTSAFEPTR_VOID("ITTDevice::TTGetInfo - FAIELD because m_pXFS is NULL", m_pXFS);

		l_hResult = m_pXFS->XFSRegisterAsync(this->m_hs, l_ReqID);
		if (WFS_SUCCESS != l_hResult)
		{
			ERRORLOG("ITTDevice::OnOpenComplete - (%s) XFSRegisterAsync FAILED with error code: (%d) - %s",
				m_szLogicName.c_str(), l_hResult, NOVADESCRIBE_XFS_ERROR(l_hResult));
			return;
		}
		m_vecRequstID.push_back(l_ReqID);
		//INFOLOG("(%s) Opened Successfully", m_szLogicName.c_str());
		TRACELOG("ITTDevice::OnOpenComplete - Ended");
	}

	void ITTDevice::OnCloseComplete(LPARAM lParam) noexcept
	{
		TRACELOG("ITTDevice::OnCloseComplete - Started - %s", m_szLogicName.c_str());

		LPWFSRESULT l_pWFSResult = (LPWFSRESULT)lParam;
		ASSERTSAFEPTR_VOID("ITTDevice::OnRegisterComplete - FAIELD because l_pWFSResult is NULL", l_pWFSResult);

		HRESULT l_hResult = l_pWFSResult->hResult;

		// Informing registered Components
		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA;
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = l_pWFSResult->RequestID;
		_DEVEVENTDATA.iMessage = WFS_CLOSE_COMPLETE;
		_DEVEVENTDATA.iResult = l_hResult;
		_DEVEVENTDATA.lpBuffer = l_pWFSResult;
		this->InformRegisteredComponents(_DEVEVENTDATA);

		if (WFS_SUCCESS != l_hResult)
		{
			ERRORLOG("ITTDevice::OnCloseComplete - (%s) FAILED WFSRESULT.hResult is: (%d) - %s",
				m_szLogicName.c_str(), l_hResult, NOVADESCRIBE_XFS_ERROR(l_hResult));
			return;
		}

		this->m_hs = 0;
		this->m_bConnected = false;

		//INFOLOG("%s Closed Successfully", m_szLogicName.c_str());
		TRACELOG("ITTDevice::OnCloseComplete - Ended - (%s)", m_szLogicName.c_str());
	}

	void ITTDevice::OnLockComplete(LPARAM lParam) noexcept
	{
	}

	void ITTDevice::OnUnlockComplete(LPARAM lParam) noexcept
	{
	}

	void ITTDevice::OnRegisterComplete(LPARAM lParam) noexcept
	{
		TRACELOG("ITTDevice::OnRegisterComplete - Started - %s", m_szLogicName.c_str());

		this->m_bConnecting = false;

		LPWFSRESULT l_pWFSResult = (LPWFSRESULT)lParam;
		ASSERTSAFEPTR_VOID("ITTDevice::OnRegisterComplete - FAIELD because l_pWFSResult is NULL", l_pWFSResult);

		HRESULT l_hResult = l_pWFSResult->hResult;

		// Informing registered Components
		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA;
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = l_pWFSResult->RequestID;
		_DEVEVENTDATA.iMessage = WFS_REGISTER_COMPLETE;
		_DEVEVENTDATA.iResult = l_hResult;
		_DEVEVENTDATA.lpBuffer = l_pWFSResult;
		this->InformRegisteredComponents(_DEVEVENTDATA);

		if (WFS_SUCCESS != l_hResult)
		{
			DEBUGLOG("ITTDevice::OnRegisterComplete - (%s) FAILED WFSRESULT.hResult is: (%d) - %s",
				m_szLogicName.c_str(), l_hResult, NOVADESCRIBE_XFS_ERROR(l_hResult));
			return;
		}

		this->m_bConnected = true;

		//INFOLOG("(%s) Registered Successfully", m_szLogicName.c_str());
		TRACELOG("ITTDevice::OnRegisterComplete - Ended");
	}

	void ITTDevice::OnDeregisterComplete(LPARAM lParam) noexcept
	{
		TRACELOG("ITTDevice::OnDeregisterComplete - Started - %s", m_szLogicName.c_str());

		HRESULT l_hResult = ((LPWFSRESULT)lParam)->hResult;
		if (WFS_SUCCESS != l_hResult)
		{
			DEBUGLOG("ITTDevice::OnDeregisterComplete - (%s) FAILED WFSRESULT.hResult is: (%d) - %s",
				m_szLogicName.c_str(), l_hResult, NOVADESCRIBE_XFS_ERROR(l_hResult));
			return;
		}

		this->m_bConnecting = false;

		//INFOLOG("(%s) Deregistered Successfully", m_szLogicName.c_str());
		TRACELOG("ITTDevice::OnDeregisterComplete - Ended");
	}

	void ITTDevice::OnGetInfoComplete(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnGetInfoComplete - (%s) WFSRESULT.hResult is: (%d) - %s - CommandID: %s",
			m_szLogicName.c_str(), _lpResult->hResult, NOVADESCRIBE_XFS_ERROR(_lpResult->hResult), NOVADESCRIBE_XFS_INFO(_lpResult->u.dwCommandCode));
	}

	void ITTDevice::OnExecuteComplete(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnExecuteComplete - (%s) WFSRESULT.hResult is: (%d) - %s - CommandID: %s",
			m_szLogicName.c_str(), _lpResult->hResult, NOVADESCRIBE_XFS_ERROR(_lpResult->hResult), NOVADESCRIBE_XFS_EXECUTE(_lpResult->u.dwCommandCode));
	}

	void ITTDevice::OnExecuteEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnExecuteEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpResult->hResult;

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void ITTDevice::OnServiceEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnServiceEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpResult->hResult;

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void ITTDevice::OnUserEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnUserEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpResult->hResult;

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void ITTDevice::OnSystemEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnSystemEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpWFSResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpWFSResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpWFSResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpWFSResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpWFSResult->hResult;

		SAFEPTR(_lpWFSResult->lpBuffer)
		{
			switch (_lpWFSResult->u.dwEventID)
			{
			case WFS_SYSE_DEVICE_STATUS:
			{
				_DEVEVENTDATA.lpBuffer = new DWORD;
				*(LPDWORD)_DEVEVENTDATA.lpBuffer = ((LPWFSDEVSTATUS)_lpWFSResult->lpBuffer)->dwState;
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void ITTDevice::OnTimerEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("ITTDevice::OnTimerEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpResult->u.dwEventID));
	}

	bool ITTDevice::TTAsyncGetInfo(DWORD dwCommandCode, LPVOID lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		TRACELOG("ITTDevice::TTAsyncGetInfo - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		REQUESTID   l_ReqID = 0;

		HRESULT _hr = m_pXFS->XFSGetInfoAsync(this->m_hs, dwCommandCode, lpIn, l_ReqID, Timeout);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::TTAsyncGetInfo - %d - %s - XFSGetInfoAsync FAILED with error code: (%d) - %s",
				dwCommandCode, NOVADESCRIBE_XFS_INFO(dwCommandCode), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		ReqID = l_ReqID;
		this->m_vecRequstID.push_back(l_ReqID);

		TRACELOG("ITTDevice::TTAsyncGetInfo - Ended Successfully - %d - %s",
			dwCommandCode, NOVADESCRIBE_XFS_INFO(dwCommandCode));
		return true;
	}

	bool ITTDevice::TTAsyncExecute(DWORD dwCommandCode, LPVOID lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		TRACELOG("ITTDevice::TTAsyncExecute - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		REQUESTID   l_ReqID = 0;

		HRESULT _hr = m_pXFS->XFSExecuteAsync(this->m_hs, dwCommandCode, lpIn, l_ReqID, Timeout);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::TTAsyncExecute - %d - %s - XFSExecuteAsync FAILED with error code: (%d) - %s",
				dwCommandCode, NOVADESCRIBE_XFS_EXECUTE(dwCommandCode), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		ReqID = l_ReqID;
		this->m_vecRequstID.push_back(l_ReqID);

		TRACELOG("ITTDevice::TTAsyncExecute - Ended Successfully - %d - %s",
			dwCommandCode, NOVADESCRIBE_XFS_EXECUTE(dwCommandCode));
		return true;
	}

	bool ITTDevice::Initialize(TTObjectPool::ITTObjectPool* pTTObjectPool) noexcept
	{
		TRACELOG("ITTDevice::Initialize - Started");

		if (this->m_bInitialized)
		{
			WARNLOG("ITTDevice::Initialize - FAILED because it is already initialized");
			return false;
		}

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::Initialize - FAIELD because pTTObjectPool is NULL", pTTObjectPool);

		// Saving XFSWrapper pointer
		auto _pXFS = pTTObjectPool->GetComponent("XFSWrapper");
		this->m_pXFS = std::static_pointer_cast<XFSWrapper::IXFSWrapper>(_pXFS.lock());
		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::Initialize - FAIELD because m_pXFS is NULL", this->m_pXFS);

		// Saving XFSWindow pointer
		auto _weakXFSWND = pTTObjectPool->GetComponent("XFSWindow");
		this->m_pXFSWIND = std::static_pointer_cast<XFSWindow::IXFSWindow>(_weakXFSWND.lock());
		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::Initialize - FAIELD because _sharedXFSWND is NULL", this->m_pXFSWIND);

		// Registering EventHandler function as a lambda in XFSWindow module
		XFSWindow::XFSWINDOWLAMBDA _lambda = [this](HWND hWnd, UINT msg, LPARAM lparam)
		{
			this->EventHandler(hWnd, msg, lparam);
		};
		this->m_iXFSWindowRegisteredFunctionIndex = this->m_pXFSWIND->RegisterCallBackFunction(_lambda);

		this->m_bInitialized = true;

		TRACELOG("ITTDevice::Initialize - Ended");
		return true;
	}

	bool ITTDevice::UnInitialize() noexcept
	{
		TRACELOG("ITTDevice::UnInitialize - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL

		this->m_pXFSWIND->DeRegisterCallBackFunction(this->m_iXFSWindowRegisteredFunctionIndex);
		this->m_pXFS->XFSDeregisterSync(this->m_hs);
		this->m_pXFS->XFSCloseSync(this->m_hs);

		this->m_bInitialized	= false;
		this->m_bConnected		= false;
		this->m_bConnecting		= false;
		this->m_hs				= NULL;

		TRACELOG("ITTDevice::UnInitialize - Ended");
		return true;
	}

	void ITTDevice::EventHandler(HWND hWnd, UINT msg, LPARAM lParam) noexcept
	{
		TRACELOG("ITTDevice::EventHandler - %d - %d", msg, lParam);
		
		TT_DEV_ASSERTINITIALIZE_VOID

		if (this->m_pXFSWIND->GetWindowHandle() != hWnd)
		{
			DEBUGLOG("ITTDevice::EventHandler - %d - %d", this->m_pXFSWIND->GetWindowHandle(), hWnd);
			return;
		}

		if (!lParam)
		{
			WARNLOG("ITTDevice::EventHandler - FAILED because lParam is NULL - Event ID is: %s", NOVADESCRIBE_XFS_MESSAGE(msg));
			return;
		}

		LPWFSRESULT l_pWFSResult = (LPWFSRESULT)lParam;

		if (this->m_hs != l_pWFSResult->hService)
		{
			//ERRORLOG("ITTDevice::EventHandler - FAILED because hService is different from m_hs - Event ID is: %s", XFSMessageParser(msg).c_str());
			return;
		}

		TRACELOG("ITTDevice::EventHandler - Started for device: (%s) - (%s)", this->m_szLogicName.c_str(), NOVADESCRIBE_XFS_MESSAGE(msg));

		std::vector<REQUESTID>::iterator vit = find(m_vecRequstID.begin(), m_vecRequstID.end(), l_pWFSResult->RequestID);
		if (m_vecRequstID.end() != vit)
			m_vecRequstID.erase(vit);
		else
			WARNLOG("ITTDevice::EventHandler - Couldn't find RequestID in m_vecRequstID (%d) for device (%s) - The message is: %d - %s ",
				l_pWFSResult->RequestID, m_szLogicName.c_str(), msg, NOVADESCRIBE_XFS_MESSAGE(msg));

		INFOLOG("%s - event received from (%s)", NOVADESCRIBE_XFS_MESSAGE(msg), m_szLogicName.c_str());

		switch (msg)
		{
		case WFS_OPEN_COMPLETE			: this->OnOpenComplete(lParam);       break;
		case WFS_CLOSE_COMPLETE			: this->OnCloseComplete(lParam);      break;
		case WFS_LOCK_COMPLETE			: this->OnLockComplete(lParam);       break;
		case WFS_UNLOCK_COMPLETE		: this->OnUnlockComplete(lParam);     break;
		case WFS_REGISTER_COMPLETE		: this->OnRegisterComplete(lParam);   break;
		case WFS_DEREGISTER_COMPLETE	: this->OnDeregisterComplete(lParam); break;
		case WFS_GETINFO_COMPLETE		: this->OnGetInfoComplete(lParam);    break;
		case WFS_EXECUTE_COMPLETE		: this->OnExecuteComplete(lParam);    break;
		case WFS_EXECUTE_EVENT			: this->OnExecuteEvent(lParam);       break;
		case WFS_SERVICE_EVENT			: this->OnServiceEvent(lParam);       break;
		case WFS_USER_EVENT				: this->OnUserEvent(lParam);          break;
		case WFS_SYSTEM_EVENT			: this->OnSystemEvent(lParam);        break;
		case WFS_TIMER_EVENT			: this->OnTimerEvent(lParam);         break;
		default							: return;
		}

		// Freeing WFSRESULT
		HRESULT _hr = WFSFreeResult(l_pWFSResult);
		if (WFS_SUCCESS != _hr)
			WARNLOG("ITTDevice::EventHandler - FAILED to free Result - device: (%s), Event: %s",
				m_szLogicName.c_str(), NOVADESCRIBE_XFS_MESSAGE(msg));

		TRACELOG("ITTDevice::EventHandler - Ended");
	}

	bool ITTDevice::ConnectAsync() noexcept
	{
		TRACELOG("ITTDevice::ConnectAsync - Started - LogicName is: %s", m_szLogicName.c_str());

		TT_DEV_ASSERTINITIALIZE_BOOL

		if (this->m_bConnecting)
		{
			ERRORLOG("ITTDevice::ConnectAsync - FAILED to connect %s because it is connecting", m_szLogicName.c_str());
			this->SetDeviceLastError(WFS_ERR_INTERNAL_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INTERNAL_ERROR));
			return false;
		}
		if (this->m_bConnected)
		{
			ERRORLOG("ITTDevice::ConnectAsync - FAILED to connect %s because it is connected", m_szLogicName.c_str());
			this->SetDeviceLastError(WFS_ERR_INTERNAL_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INTERNAL_ERROR));
			return false;
		}

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::ConnectAsync - FAIELD because m_pXFS is NULL", this->m_pXFS);

		REQUESTID	_ReqID = 0;
		HRESULT _hr = m_pXFS->XFSOpenAsync(this->m_hs, this->m_szLogicName.c_str(), _ReqID);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::ConnectAsync - (%s) XFSOpenAsync returned: (%d) - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		this->m_vecRequstID.push_back(_ReqID);
		this->m_bConnecting = true;

		TRACELOG("ITTDevice::ConnectAsync - Ended Successfully - (%s) - RequestID: %d", m_szLogicName.c_str(), _ReqID);
		return true;
	}

	bool ITTDevice::DisconnectAsync() noexcept
	{
		TRACELOG("ITTDevice::DisconnectAsync - Started - (%s)", m_szLogicName.c_str());

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::DisconnectAsync - FAIELD because m_pXFS is NULL", this->m_pXFS);

		REQUESTID	l_ReqID = 0;
		HRESULT		_hr = m_pXFS->XFSDeregisterAsync(this->m_hs, l_ReqID);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::DisconnectAsync - (%s) XFSDeregisterAsync returned: %d - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			// return _hr;
		}
		else
			m_vecRequstID.push_back(l_ReqID);

		_hr = m_pXFS->XFSCloseAsync(this->m_hs, l_ReqID);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::DisconnectAsync - (%s) XFSCloseAsync returned: (%d) - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		m_vecRequstID.push_back(l_ReqID);

		TRACELOG("ITTDevice::DisconnectAsync - Ended Successfully - (%s)", m_szLogicName.c_str());
		return true;
	}

	bool ITTDevice::ConnectSync() noexcept
	{
		TRACELOG("ITTDevice::ConnectSync - Started - LogicName is: %s", m_szLogicName.c_str());

		TT_DEV_ASSERTINITIALIZE_BOOL

		if (this->m_bConnecting)
		{
			ERRORLOG("ITTDevice::ConnectSync - FAILED to connect %s because it is connecting", m_szLogicName.c_str());
			this->SetDeviceLastError(WFS_ERR_INTERNAL_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INTERNAL_ERROR));
			return false;
		}
		if (this->m_bConnected)
		{
			ERRORLOG("ITTDevice::ConnectSync - FAILED to connect %s because it is connected", m_szLogicName.c_str());
			this->SetDeviceLastError(WFS_ERR_INTERNAL_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INTERNAL_ERROR));
			return false;
		}

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::ConnectSync - FAIELD because m_pXFS is NULL", this->m_pXFS);

		HRESULT _hr = m_pXFS->XFSOpenSync(this->m_hs, this->m_szLogicName.c_str());
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::ConnectSync - (%s) XFSOpenSync returned: (%d) - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		_hr = m_pXFS->XFSRegisterSync(this->m_hs);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::ConnectSync - (%s) XFSRegisterSync returned: (%d) - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		this->m_bConnected = true;

		TRACELOG("ITTDevice::ConnectSync - Ended Successfully - (%s)", m_szLogicName.c_str());
		return true;
	}

	bool ITTDevice::DisconnectSync() noexcept
	{
		TRACELOG("ITTDevice::DisconnectSync - Started - (%s)", m_szLogicName.c_str());

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::DisconnectSync - FAIELD because m_pXFS is NULL", this->m_pXFS);

		HRESULT _hr = m_pXFS->XFSDeregisterSync(this->m_hs);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::DisconnectSync - (%s) XFSDeregisterSync returned: %d - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			// return _hr;
		}

		_hr = m_pXFS->XFSCloseSync(this->m_hs);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::DisconnectSync - (%s) XFSCloseSync returned: (%d) - %s", m_szLogicName.c_str(), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		this->m_hs = NULL;
		this->m_bConnected = false;

		TRACELOG("ITTDevice::DisconnectSync - Ended Successfully - (%s)", m_szLogicName.c_str());
		return true;
	}

	int ITTDevice::RegisterCallbackFunction(NOVAGLOBALS::DEVEVENTLAMBDA lambda) noexcept
	{
		TRACELOG("ITTDevice::RegisterCallbackFunction - Started for (%s)", this->m_strDescription.c_str());

		std::lock_guard<std::mutex>lock(m_PushMutex);

		int _index = m_iIndex;
		auto _mapRet = m_contCallbackFunctions.insert(make_pair(m_iIndex, lambda));
		if (false == _mapRet.second)
		{
			ERRORLOG("ITTDevice::RegisterCallbackFunction - FAILED to insert into m_contCallbackFunctions");
			return -1;
		}

		m_iIndex++;

		TRACELOG("ITTDevice::RegisterCallbackFunction - Ended Successfully for (%s)", this->m_strDescription.c_str());
		return _index;
	}

	void ITTDevice::DeregisterCallBackFunction(int index)
	{
		TRACELOG("ITTDevice::DeregisterCallBackFunction - Started");

		std::lock_guard<std::mutex>_lock(m_PushMutex);

		try
		{
			auto it = m_contCallbackFunctions.find(index);
			if (it != m_contCallbackFunctions.end())
				m_contCallbackFunctions.erase(it);
		}
		catch (...)
		{
			FATALLOG("ITTDevice::DeregisterCallBackFunction - EXCEPTION occurred while trying to erase");
		}

		TRACELOG("ITTDevice::DeregisterCallBackFunction - Ended Successfully");
	}

	bool ITTDevice::FreeWFSResult(LPWFSRESULT lpResult) noexcept
	{
		HRESULT		_hr = WFS_SUCCESS;

		_hr = WFSFreeResult(lpResult);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
			return false;

		TRACELOG("ITTDevice::UnLockDevice - Ended Successfully");
		return true;
	}

	bool ITTDevice::UnLockDevice() noexcept
	{
		TRACELOG("ITTDevice::UnLockDevice - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::UnLockDevice - FAIELD because m_pXFS is NULL", this->m_pXFS);

		REQUESTID	_ReqID = 0;
		HRESULT		_hr = WFS_SUCCESS;

		_hr = m_pXFS->XFSUnLock(this->m_hs, _ReqID);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
			return false;

		m_vecRequstID.push_back(_ReqID);

		TRACELOG("ITTDevice::UnLockDevice - Ended Successfully");
		return true;
	}

	bool ITTDevice::LockDevice(long Timeout) noexcept
	{
		TRACELOG("ITTDevice::LockDevice - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::LockDevice - FAIELD because m_pXFS is NULL", this->m_pXFS);

		REQUESTID	_ReqID = 0;
		HRESULT		_hr = WFS_SUCCESS;

		_hr = m_pXFS->XFSLock(this->m_hs, Timeout, _ReqID);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
			return false;

		m_vecRequstID.push_back(_ReqID);

		TRACELOG("ITTDevice::LockDevice - Ended Successfully");
		return true;
	}
}