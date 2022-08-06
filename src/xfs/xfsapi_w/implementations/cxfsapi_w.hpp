#pragma once

#ifndef __H_CXFS_W__
#define __H_CXFS_W__

#include "../ixfsapi_w.hpp"

namespace __N_XFSAPI_W__
{
	class CXFS_W : public IXFS_W
	{
	private:
	protected:
	public:
		CXFS_W() = default;
		CXFS_W(const CXFS_W&) = delete;
		CXFS_W(const CXFS_W&&) = delete;
		CXFS_W& operator = (const CXFS_W&) = delete;
		CXFS_W& operator = (CXFS_W&&) = delete;
		virtual ~CXFS_W() = default;

        HRESULT WFSStartUp(WFSSTARTUP_P&) const noexcept(false) final;
        HRESULT WFSCleanUp() const noexcept(false) final;
        HRESULT WFSOpen(WFSOPEN_P&) const noexcept(false) final;
        HRESULT WFSAsyncOpen(WFSOPEN_P&, const HWND, LPREQUESID) const noexcept(false) final;
        HRESULT WFSClose(const WFSCLOSE_P&) const noexcept final;
        HRESULT WFSAsyncClose(const WFSCLOSE_P&, const HWND, LPREQUESTID) const noexcept final;
        HRESULT WFSRegister(const WFSREGISTER_P&) const noexcept(false) final;
        HRESULT WFSAsyncRegister(const WFSREGISTER_P&, const HWND, LPREQUESTID) const noexcept(false) final;
        HRESULT WFSDeRegister(const WFSREGISTER_P&) const noexcept(false) final;
        HRESULT WFSAsyncDeregister(const WFSREGISTER_P&, const HWND, LPREQUESTID) const noexcept(false) final;
		HRESULT WFSLock(const WFSLOCK_P&, WFSRESULT_W&) const noexcept(false) final;
        HRESULT WFSAsyncLock(const WFSLOCK_P&, HWND, LPREQUESTID) const noexcept(false) final;
		HRESULT XFSUnLock(const WFSUNLOCK_P&) const noexcept final;
        HRESULT WFSAsyncUnlock(const WFSUNLOCK_P&, HWND, LPREQUESTID) const noexcept(false) final;
		HRESULT WFSCancelAsyncRequest(const WFSCANCELASYNCREQUEST_P&) const noexcept final;
        HRESULT WFSCancelBlockingCall(const WFSCANCELBLOCKINGCALL&) const noexcept(false) final;
		HRESULT WFSFreeResult(const WFSFREERESULT_P&) const noexcept(false) final;
        HRESULT WFSCreateAppHandle(LPHAPP) const noexcept(false) final;
        HRESULT WFSDestroyAppHandle(const HAPP) const noexcept(false) final;
        BOOL WFSIsBlocking() const noexcept final;
        HRESULT WFSSetBlockingHook(WFSSETBLOCKINGHOOK_P&) const noexcept(false) final;
        HRESULT WFSUnhookBlockingHook() const noexcept(false) final;
        HRESULT WFSGetInfo(const WFSGETINFO_P&, WFSRESULT_W&) const noexcept(false) final;   
        HRESULT WFSAsyncGetInfo(const WFSGETINFO_P&, const HWND, LPREQUESTID) const noexcept(false) final;
		HRESULT WFSExecute(const WFSEXECUTE_P&, WFSRESULT_W&) const noexcept final;
		HRESULT WFSAsyncExecute(const WFSEXECUTE_P&, const HWND, LPREQUESTID) const noexcept final;
	};
} // !__N_XFSAPI_W__

#endif // !__H_CXFS_W__