#pragma once

#ifndef __H_TTDEVICE__
#define __H_TTDEVICE__

#include <XFSAPI.H>

#include <XFSWrapper/IXFSWrapper.hpp>
#include <XFSWindow/IXFSWindow.hpp>

#include <mutex>

#define TT_DEV_ASSERTSAFEPTR_HRESULT(str, ptr)	UNSAFEPTR(ptr)			{ this->SetDeviceLastError(WFS_ERR_INVALID_POINTER, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INVALID_POINTER)); ERRORLOG("%s", str); return WFS_ERR_INTERNAL_ERROR; }
#define TT_DEV_ASSERTSAFEPTR_BOOL(str, ptr)		UNSAFEPTR(ptr)			{ this->SetDeviceLastError(WFS_ERR_INVALID_POINTER, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INVALID_POINTER)); ERRORLOG("%s", str); return false; }
#define TT_DEV_ASSERTSAFEPTR_VOID(str, ptr)		UNSAFEPTR(ptr)			{ this->SetDeviceLastError(WFS_ERR_INVALID_POINTER, NOVADESCRIBE_XFS_ERROR(WFS_ERR_INVALID_POINTER)); ERRORLOG("%s", str); return; }

#define TT_DEV_ASSERTINITIALIZE_HRESULT			if (!m_bInitialized)	{ ERRORLOG("FAILED because it is NOT initialized")	return WFS_ERR_INTERNAL_ERROR; }
#define TT_DEV_ASSERTINITIALIZE_BOOL			if (!m_bInitialized)	{ ERRORLOG("FAILED because it is NOT initialized")	return false; }
#define TT_DEV_ASSERTINITIALIZE_VOID			if (!m_bInitialized)	{ ERRORLOG("FAILED because it is NOT initialized")	return; }
#define TT_DEV_ASSERTCONNECT_HRESULT			if (!m_bConnected)		{ ERRORLOG("FAILED because it is NOT connected")	return WFS_ERR_INTERNAL_ERROR; }
#define TT_DEV_ASSERTCONNECT_BOOL				if (!m_bConnected)		{ ERRORLOG("FAILED because it is NOT connected")	return false; }
#define TT_DEV_ASSERTCONNECT_VOID				if (!m_bConnected)		{ ERRORLOG("FAILED because it is NOT connected")	return; }

namespace TTDevice
{
	using REQVECT = std::vector<REQUESTID>;
    using LPXFSWRAPPER = std::shared_ptr<__N_XFSWRAPPER__::IXFSWrapper>;
    using LPXFSWINDOW = std::shared_ptr<__N_XFSWINDOW__::IXFSWindow>;

	constexpr auto DEFAULT_TIMEOUT = 30000;

	class ITTDevice
	{
		friend class CXFSWindow;

	private:
		int							m_iIndex{ 0 };
		std::mutex					m_PushMutex{};

		LPXFSWRAPPER                m_pXFS{ __N_XFSWRAPPER__::CreateXFSWrapper() };
		LPXFSWINDOW                 m_pXFSWIND{ __N_XFSWINDOW__::CreateXFSWindow() };
        
		int							m_iXFSWindowRegisteredFunctionIndex{ 0 };

		std::pair<unsigned int, std::string>
									m_pairLastError;

	protected:
		bool						m_bConnected{ false };
		bool						m_bConnecting{ false };

		HSERVICE					m_hs{ NULL };

		std::string					m_szLogicName{};

		void						SetDeviceLastError(HRESULT hr, std::string str) noexcept { this->m_pairLastError = std::make_pair(hr, str); }

		NOVAGLOBALS::DEVLAMBDAMAP	m_contCallbackFunctions{};
		void						InformRegisteredComponents(NOVAGLOBALS::DEVEVENTDATA&) noexcept;

		REQVECT						m_vecRequstID{};

		virtual void				OnOpenComplete(LPARAM) noexcept;
		virtual void				OnCloseComplete(LPARAM) noexcept;
		virtual void				OnLockComplete(LPARAM) noexcept;
		virtual void				OnUnlockComplete(LPARAM) noexcept;
		virtual void				OnRegisterComplete(LPARAM) noexcept;
		virtual void				OnDeregisterComplete(LPARAM) noexcept;
		virtual void				OnGetInfoComplete(LPARAM) noexcept;
		virtual void				OnExecuteComplete(LPARAM) noexcept;
		virtual void				OnExecuteEvent(LPARAM) noexcept;
		virtual void				OnServiceEvent(LPARAM) noexcept;
		virtual void				OnUserEvent(LPARAM) noexcept;
		virtual void				OnSystemEvent(LPARAM) noexcept;
		virtual void				OnTimerEvent(LPARAM) noexcept;

		template <typename LPWFSINPUTDATA, typename LPWFSRESULTBUFFER, typename LPOUT, typename LPIN>
		bool						TTSyncGetInfo(DWORD dwCommandCode, LPIN lpIn, LPOUT lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept;
		bool						TTAsyncGetInfo(DWORD dwCommandCode, LPVOID lpIn, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept;

		template <typename LPWFSINPUTDATA, typename LPWFSRESULTBUFFER, typename LPOUT, typename LPIN>
		bool						TTSyncExecute(DWORD dwCommandCode, LPIN lpIn, LPOUT lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept;
		bool						TTAsyncExecute(DWORD dwCommandCode, LPVOID lpIn, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept;

	public:
		ITTDevice() = default;
		ITTDevice(const ITTDevice&) = delete;
		ITTDevice(ITTDevice&&) = delete;
		ITTDevice& operator = (const ITTDevice&) = delete;
		ITTDevice& operator = (ITTDevice&&) = delete;
		virtual ~ITTDevice() = default;

		virtual bool				Initialize(TTObjectPool::ITTObjectPool*) noexcept override;
		virtual bool				UnInitialize() noexcept override;
		void						EventHandler(HWND hWnd, UINT msg, LPARAM lparam) noexcept;

		virtual bool				ConnectAsync() noexcept;
		virtual bool				DisconnectAsync() noexcept;
		virtual bool				ConnectSync() noexcept;
		virtual bool				DisconnectSync() noexcept;

		bool						IsConnected() const noexcept { return this->m_bConnected; }
		bool						IsConnecting() const noexcept { return this->m_bConnecting; }

		void						SetLogicName(const std::string szLogicname) noexcept { this->m_szLogicName.assign(szLogicname); }
		std::string					GetLogicName() const noexcept { return this->m_szLogicName; }

		int							RegisterCallbackFunction(NOVAGLOBALS::DEVEVENTLAMBDA) noexcept;
		void						DeregisterCallBackFunction(int);

		void						SetDeviceUID(const NDEVICEUID & DeviceUID) noexcept { this->m_DeviceUID = DeviceUID; }
		void						SetDeviceXFSVersion(const NOVAGLOBALS::TTXFSVER eXFSVersion) noexcept { this->m_eXFSVersion = eXFSVersion; }

		bool						FreeWFSResult(LPWFSRESULT) noexcept;
		bool						CancelLock() noexcept;
		bool						UnLockDevice() noexcept;
		bool						LockDevice(long Timeout) noexcept;

		std::pair<unsigned int, std::string>
									GetDeviceLastError() noexcept { return this->m_pairLastError; }
	};

	template <typename LPWFSINPUTDATA, typename LPWFSRESULTBUFFER, typename LPOUT, typename LPIN>
	bool ITTDevice::TTSyncGetInfo(DWORD dwCommandCode, LPIN lpIn, LPOUT lpOut, const DWORD Timeout) noexcept
	{
		TRACELOG("ITTDevice::TTSyncGetInfo - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::TTSyncGetInfo - FAIELD because m_pXFS is NULL", m_pXFS);

		LPWFSINPUTDATA _lpWFSInputData = nullptr;
		DeviceUtility::template Parse_WFSInputData<LPIN>(&_lpWFSInputData, lpIn);

		LPWFSRESULT	_lpWFSResult;
		HRESULT _hr = m_pXFS->XFSGetInfoSync(m_hs, dwCommandCode, _lpWFSInputData, &_lpWFSResult, Timeout);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::TTSyncGetInfo - %d - %s - XFSGetInfoSync FAILED with error code: (%d) - %s",
				dwCommandCode, NOVADESCRIBE_XFS_INFO(dwCommandCode), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			WFSFreeResult(_lpWFSResult);
			return false;
		}

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::TTSyncGetInfo - FAIELD because _lpWFSResult->lpBuffer is NULL", _lpWFSResult->lpBuffer);
		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::TTSyncGetInfo - FAIELD because lpOut is NULL", lpOut);

		DeviceUtility::template Parse_WFSResult<LPWFSRESULTBUFFER>(lpOut, _lpWFSResult);

		//_hr = m_pXFS->XFSFree(&_lpWFSResult);
		_hr = WFSFreeResult(_lpWFSResult);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			WARNLOG("ITTDevice::TTSyncGetInfo - %d - %s - FreeWFSResult FAILED with error code: (%d) - %s",
				dwCommandCode, NOVADESCRIBE_XFS_INFO(dwCommandCode), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		TRACELOG("ITTDevice::TTSyncGetInfo - Ended Successfully - %d - %s",
			dwCommandCode, NOVADESCRIBE_XFS_INFO(dwCommandCode));
		return true;
	}

	template <typename LPWFSINPUTDATA, typename LPWFSRESULTBUFFER, typename LPOUT, typename LPIN>
	bool ITTDevice::TTSyncExecute(DWORD dwCommandCode, LPIN lpIn, LPOUT lpOut, const DWORD Timeout) noexcept
	{
		TRACELOG("ITTDevice::TTSyncExecute - Started - %d - %s",
			dwCommandCode, NOVADESCRIBE_XFS_EXECUTE(dwCommandCode));

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::TTSyncExecute - FAIELD because m_pXFS is NULL", m_pXFS);

		LPWFSINPUTDATA _lpWFSInputData = nullptr;
		DeviceUtility::template Parse_WFSInputData<LPIN>(&_lpWFSInputData, lpIn);

		LPWFSRESULT _lpWFSResult;
		HRESULT _hr = m_pXFS->XFSExecuteSync(m_hs, dwCommandCode, _lpWFSInputData, &_lpWFSResult, Timeout);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			ERRORLOG("ITTDevice::TTSyncExecute - %d - %s - XFSExecuteSync FAILED with error code: (%d) - %s",
				dwCommandCode, NOVADESCRIBE_XFS_EXECUTE(dwCommandCode), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			WFSFreeResult(_lpWFSResult);
			return false;
		}

		TT_DEV_ASSERTSAFEPTR_BOOL("ITTDevice::TTSyncExecute - FAIELD because _lpWFSResult NULL", _lpWFSResult);
		//DEV_CTRL_ASSERTSAFEPTR_HRESULT("ITTDevice::TTSyncExecute - FAIELD because _lpWFSResult->lpBuffer NULL", _lpWFSResult->lpBuffer);
		//DEV_CTRL_ASSERTSAFEPTR_HRESULT("ITTDevice::TTSyncExecute - FAIELD because lpOut NULL", lpOut);

		DeviceUtility::template Parse_WFSResult<LPWFSRESULTBUFFER>(lpOut, _lpWFSResult);

		//_hr = m_pXFS->XFSFree(&_lpWFSResult);
		_hr = WFSFreeResult(_lpWFSResult);
		this->SetDeviceLastError(_hr, NOVADESCRIBE_XFS_ERROR(_hr));
		if (WFS_SUCCESS != _hr)
		{
			WARNLOG("ITTDevice::TTSyncExecute - %d - %s - FreeWFSResult FAILED with error code: (%d) - %s ",
				dwCommandCode, NOVADESCRIBE_XFS_EXECUTE(dwCommandCode), _hr, NOVADESCRIBE_XFS_ERROR(_hr));
			return false;
		}

		TRACELOG("ITTDevice::TTSyncExecute - Ended Successfully - %d - %s",
			dwCommandCode, NOVADESCRIBE_XFS_EXECUTE(dwCommandCode));
		return true;
	}
}

#endif // !__H_TTDEVICE__