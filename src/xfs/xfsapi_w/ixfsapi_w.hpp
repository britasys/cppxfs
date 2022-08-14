#pragma once

#ifndef __H_IXFSAPI_W__
#define __H_IXFSAPI_W__

#include <xfsapi_w.hpp>

#include <memory>

namespace __N_XFSAPI_W__
{
    /**
     * @brief xfsapi wrapper class
     * 
     */
	class IXFSAPI_W
	{
	private:
	protected:
	public:
		IXFSAPI_W() = default;
		IXFSAPI_W(const IXFSAPI_W&) = delete;
		IXFSAPI_W(const IXFSAPI_W&&) = delete;
		IXFSAPI_W& operator = (const IXFSAPI_W&) = delete;
		IXFSAPI_W& operator = (IXFSAPI_W&&) = delete;
		virtual ~IXFSAPI_W() = default;
        
        /**
         * @brief Establishes a connection between an application and the XFS Manager.
         * 
         * @param WFSSTARTUP_P
         * @return HRESULT
         */
        virtual HRESULT WFSStartUp(WFSSTARTUP_P&) const noexcept(false) = 0;

        /**
         * @brief Disconnects an application from the XFS Manager.
         * 
         * @return HRESULT 
         */
        virtual HRESULT WFSCleanUp() const noexcept = 0;

        /**
         * @brief Initiates a session (a series of service requests terminated with the 
         * WFSClose or WFSAsyncClose function) between the application and the specified service. 
         * This does not necessarily mean that the hardware is opened. This command will return with 
         * WFS_SUCCESS even if the hardware is inoperable, offline or powered off. The status of 
         * the device can be requested through a WFSGetInfo command.
         * The synchronous version of WFSAsyncOpen.
         * 
         * @param WFSOPEN_P
         * @return HRESULT
         */
        virtual HRESULT WFSOpen(WFSOPEN_P&) const noexcept(false) = 0;

        /**
         * @brief As WFSOpen
         * 
         * @param WFSOPEN_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncOpen(WFSOPEN_P&, const HWND, REQUESTID&) const noexcept(false) = 0;

        /**
         * @brief Terminates a session (a series of service requests initiated with the 
         * WFSOpen or WFSAsyncOpen function) between the application and the specified service. 
         * The synchronous version of WFSAsyncClose.
         * 
         * @param WFSCLOSE_P
         * @return HRESULT
         */
        virtual HRESULT WFSClose(const WFSCLOSE_P&) const noexcept = 0;

        /**
         * @brief As WFSClose
         * 
         * @param WFSCLOSE_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncClose(const WFSCLOSE_P&, const HWND, REQUESTID&) const noexcept = 0;

        /**
         * @brief Enables event monitoring for the specified service by the specified window; 
         * all messages of the specified class(es) are sent to the window specified in the hWndReg parameter. 
         * The synchronous version of WFSAsyncRegister.
         * 
         * @param WFSREGISTER_P
         * @return HRESULT 
         */
        virtual HRESULT WFSRegister(const WFSREGISTER_P&) const noexcept(false) = 0;

        /**
         * @brief As WFSRegister
         * 
         * @param WFSREGISTER_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncRegister(const WFSREGISTER_P&, const HWND, REQUESTID&) const noexcept(false) = 0;

        /**
         * @brief Discontinues monitoring of the specified message class(es) (or all classes) 
         * from the specified hService, by the specified hWndReg (or all the calling application's hWnd's). 
         * The synchronous version of WFSAsyncDeregister.
         * 
         * @param WFSREGISTER_P
         * @return HRESULT 
         */
        virtual HRESULT WFSDeRegister(const WFSREGISTER_P&) const noexcept(false) = 0;

        /**
         * @brief As WFSDeRegister
         * 
         * @param WFSREGISTER_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncDeregister(const WFSREGISTER_P&, const HWND, REQUESTID&) const noexcept(false) = 0;

        /**
         * @brief Establishes exclusive control by the calling application over the specified service. 
         * The synchronous version of WFSAsyncLock.
         * 
         * @param WFSLOCK_P
         * @param WFSRESULT_W
         * @return HRESULT 
         */
		virtual HRESULT WFSLock(const WFSLOCK_P&, WFSRESULT_W&) const noexcept(false) = 0;

        /**
         * @brief As WFSLock
         * 
         * @param WFSLOCK_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncLock(const WFSLOCK_P&, HWND, REQUESTID&) const noexcept(false) = 0;

        /**
         * @brief Releases a service that has been locked by a previous WFSLock or WFSAsyncLock function. 
         * The synchronous version of WFSAsyncUnlock.
         * 
         * @param WFSUNLOCK_P
         * @return HRESULT 
         */
		virtual HRESULT WFSUnlock(const WFSUNLOCK_P&) const noexcept(false) = 0;

        /**
         * @brief As WFSUnlock
         * 
         * @param WFSUNLOCK_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncUnlock(const WFSUNLOCK_P&, HWND, REQUESTID&) const noexcept(false) = 0;

        /**
         * @brief Cancels the specified (or every) asynchronous request being performed 
         * on the specified service, before its (their) completion.
         * 
         * @param WFSCANCELASYNCREQUEST_P
         * @return HRESULT 
         */
		virtual HRESULT WFSCancelAsyncRequest(const WFSCANCELASYNCREQUEST_P&) const noexcept(false) = 0;

        /**
         * @brief Cancels a blocking operation for the specified thread, if one is in progress.
         * 
         * @param WFSCANCELBLOCKINGCALL_P
         * @return HRESULT 
         */
        virtual HRESULT WFSCancelBlockingCall(const WFSCANCELBLOCKINGCALL_P&) const noexcept = 0;

        /**
         * @brief Notifies the XFS Manager that a memory buffer (or linked list of buffers) 
         * that was dynamically allocated by a Service Provider is to be freed.
         * 
         * @param WFSFREERESULT_P
         * @return HRESULT 
         */
		virtual HRESULT WFSFreeResult(const WFSFREERESULT_P&) const noexcept = 0;

        /**
         * @brief Requests a new, unique application handle value.
         * 
         * @param LPHAPP
         * @return HRESULT 
         */
        virtual HRESULT WFSCreateAppHandle(LPHAPP) const noexcept(false) = 0;

        /**
         * @brief Requests a new, unique application handle value.
         * 
         * @param HAPP      - The application handle to be made invalid.
         * @return HRESULT 
         */
        virtual HRESULT WFSDestroyAppHandle(const HAPP) const noexcept(false) = 0;

        /**
         * @brief Determines whether a thread has a blocking operation in progress.
         * 
         * @return BOOL 
         */
        virtual BOOL WFSIsBlocking() const noexcept = 0;

        /**
         * @brief Establishes an application-specific blocking routine.
         * 
         * @return HRESULT 
         */
        virtual HRESULT WFSSetBlockingHook(WFSSETBLOCKINGHOOK_P&) const noexcept(false) = 0;

        /**
         * @brief 
         * 
         * @return HRESULT 
         */
        virtual HRESULT WFSUnhookBlockingHook() const noexcept(false) = 0;

        /**
         * @brief Retrieves information from the specified Service Provider. The synchronous version of WFSAsyncGetInfo.
         * 
         * @param WFSGETINFO_P
         * @param WFSRESULT_W   - Data structure to be filled with the result of the execution. The Service Provider allocates the memory for the structure.
         * @return HRESULT 
         */
        virtual HRESULT WFSGetInfo(const WFSGETINFO_P&, WFSRESULT_W&) const noexcept(false) = 0;        

        /**
         * @brief As WFSGetInfo
         * 
         * @param WFSGETINFO_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
        virtual HRESULT WFSAsyncGetInfo(const WFSGETINFO_P&, const HWND, REQUESTID&) const noexcept(false) = 0;

        /**
         * @brief Sends a service-specific command to a Service Provider. 
         * The synchronous version of WFSAsyncExecute.
         * 
         * @param WFSEXECUTE_P
         * @return HRESULT 
         */
		virtual HRESULT WFSExecute(const WFSEXECUTE_P&, WFSRESULT_W&) const noexcept(false) = 0;      

        /**
         * @brief As WFSExecute
         * 
         * @param WFSEXECUTE_P
         * @param HWND          - The window handle which is to receive the completion message for this request.
         * @param REQUESTID     - Request identifier for this request (returned parameter).
         * @return HRESULT 
         */
		virtual HRESULT WFSAsyncExecute(const WFSEXECUTE_P&, const HWND, REQUESTID&) const noexcept(false) = 0;
	};

	std::shared_ptr<IXFSAPI_W> CreateXFSAPIWrapper() noexcept;
} // !__N_XFSAPI_W__

#endif // !__H_IXFSAPI_W__