
#include "CXFSDevice.hpp"

#include <xfsapi.h>
#include <xfs_descriptors.hpp>

namespace __N_XFSDEVICE__
{
    void CXFSDevice::update(const WFSRESULT_W& result) final;
	{
		if (!lParam)
			return;

		if (this->m_hs != result.hService)
			return;

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

	bool CXFSDevice::connect_sync(const TIMEOUT) noexcept
    {
    }

	bool CXFSDevice::connect_async(LAMBDA lambda, const TIMEOUT timeout) noexcept
    {
		REQUESTID l_ReqID = 0;
		HRESULT l_hr = m_pXFS->XFSOpenAsync(this->m_hs, this->m_szLogicName.c_str(), &l_ReqID);

		this->m_requests.push_back(l_ReqID);
		this->m_state = STATE::CONNECTING;

        return true;
    }

	bool CXFSDevice::disconnect_sync(const TIMEOUT) noexcept final;
	bool CXFSDevice::disconnect_async(LAMBDA, const TIMEOUT) noexcept final;
    bool CXFSDevice::get_inf_sync(const COMMAND command, const LPDATA lpData, WFSRESULT_W& result_w, const TIMEOUT timeout) const noexcept
    {
		LPWFSRESULT	l_lpWFSResult{ nullptr };
		HRESULT l_hr = m_pXFS->XFSGetInfoSync(this->m_hs, command, lpData, &l_lpWFSResult, timeout);

        result_w = *l_lpWFSResult;

		return l_hr;
    }

    bool CXFSDevice::get_inf_async(const COMMAND command, const LPDATA lpData, LAMBDA lambda, const TIMEOUT timeout) const noexcept
    {
		REQUESTID l_ReqID = 0;
		HRESULT l_hr = m_pXFS->XFSGetInfoAsync(this->m_hs, command, lpData, l_ReqID, timeout);

		this->m_vecRequstID.push_back(l_ReqID);

		return l_hr;
    }

    bool CXFSDevice::execute_sync(const COMMAND command, const LPDATA lpData, WFSRESULT_W& result_w, const TIMEOUT timeout) const noexcept
    {
		LPWFSRESULT l_lpWFSResult;
		HRESULT _hr = m_pXFS->XFSExecuteSync(this->m_hs, command, lpData, &l_lpWFSResult, timeout);

        result_w = *l_lpWFSResult;

		return true;
    }

    bool CXFSDevice::execute_async(const COMMAND command, const LPDATA lpData, LAMBDA lambda, const TIMEOUT timeout) const noexcept
    {
		REQUESTID l_ReqID = 0;
		HRESULT l_hr = m_pXFS->XFSExecuteAsync(this->m_hs, dwCommandCode, lpIn, l_ReqID, Timeout);

		this->m_vecRequstID.push_back(l_ReqID);
        
		return l_hr;
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
}