#pragma once

#ifndef __H_CXFSAPI_W__
#define __H_CXFSAPI_W__

#include "../ixfsapi_w.hpp"

namespace __N_XFSAPI_W__
{
	class CXFSAPI_W : public IXFSAPI_W
	{
	private:
	protected:
	public:
		CXFSAPI_W() = default;
		CXFSAPI_W(const CXFSAPI_W&) = delete;
		CXFSAPI_W(const CXFSAPI_W&&) = delete;
		CXFSAPI_W& operator = (const CXFSAPI_W&) = delete;
		CXFSAPI_W& operator = (CXFSAPI_W&&) = delete;
		virtual ~CXFSAPI_W() = default;

        HRESULT WFSStartUp(WFSSTARTUP_P&) const noexcept(false) final;
        HRESULT WFSCleanUp() const noexcept final;
        HRESULT WFSOpen(WFSOPEN_P&) const noexcept(false) final;
        HRESULT WFSAsyncOpen(WFSOPEN_P&, const HWND, REQUESTID&) const noexcept(false) final;
        HRESULT WFSClose(const WFSCLOSE_P&) const noexcept final;
        HRESULT WFSAsyncClose(const WFSCLOSE_P&, const HWND, REQUESTID&) const noexcept final;
        HRESULT WFSRegister(const WFSREGISTER_P&) const noexcept(false) final;
        HRESULT WFSAsyncRegister(const WFSREGISTER_P&, const HWND, REQUESTID&) const noexcept(false) final;
        HRESULT WFSDeRegister(const WFSREGISTER_P&) const noexcept(false) final;
        HRESULT WFSAsyncDeregister(const WFSREGISTER_P&, const HWND, REQUESTID&) const noexcept(false) final;
		HRESULT WFSLock(const WFSLOCK_P&, WFSRESULT_W&) const noexcept(false) final;
        HRESULT WFSAsyncLock(const WFSLOCK_P&, HWND, REQUESTID&) const noexcept(false) final;
		HRESULT WFSUnlock(const WFSUNLOCK_P&) const noexcept(false) final;
        HRESULT WFSAsyncUnlock(const WFSUNLOCK_P&, HWND, REQUESTID&) const noexcept(false) final;
		HRESULT WFSCancelAsyncRequest(const WFSCANCELASYNCREQUEST_P&) const noexcept final;
        HRESULT WFSCancelBlockingCall(const WFSCANCELBLOCKINGCALL_P&) const noexcept final;
		HRESULT WFSFreeResult(const WFSFREERESULT_P&) const noexcept final;
        HRESULT WFSCreateAppHandle(LPHAPP) const noexcept(false) final;
        HRESULT WFSDestroyAppHandle(const HAPP) const noexcept(false) final;
        BOOL    WFSIsBlocking() const noexcept final;
        HRESULT WFSSetBlockingHook(WFSSETBLOCKINGHOOK_P&) const noexcept(false) final;
        HRESULT WFSUnhookBlockingHook() const noexcept(false) final;
        HRESULT WFSGetInfo(const WFSGETINFO_P&, WFSRESULT_W&) const noexcept(false) final;   
        HRESULT WFSAsyncGetInfo(const WFSGETINFO_P&, const HWND, REQUESTID&) const noexcept(false) final;
		HRESULT WFSExecute(const WFSEXECUTE_P&, WFSRESULT_W&) const noexcept final;
		HRESULT WFSAsyncExecute(const WFSEXECUTE_P&, const HWND, REQUESTID&) const noexcept final;
	};
} // !__N_XFSAPI_W__

#endif // !__H_CXFSAPI_W__