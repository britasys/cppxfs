#pragma once

#ifndef __H_CXFSDEVICE__
#define __H_CXFSDEVICE__

#include <IXFSDevice.hpp>

#include <XFSWindow/IXFSWindow.hpp>

#include <mutex>
#include <functional>

namespace __N_XFSDEVICE__
{
	using REQUESTS = std::vector<REQUESTID>;
    using LPXFSWRAP = std::shared_ptr<__N_XFSWRAPPER__::IXFSWrapper>;
    using LPXFSWIND = std::shared_ptr<__N_XFSWINDOW__::IXFSWindow>;

	class CXFSDevice : public IXFSDevice
	{
	private:
		int         m_iIndex{ 0 };
		std::mutex  m_PushMutex{};

		LPXFSWRAP   m_pXFS{ __N_XFSAPI_W__::CreateXFSAPIWrapper() };
		LPXFSWIND   m_pWND{ __N_XFSWINDOW__::CreateXFSWindow() };
        
		int         m_iXFSWindowRegisteredFunctionIndex{ 0 };

		HSERVICE    m_hs{ NULL };
		REQUESTS    m_requests{};

		void OnOpenComplete(LPARAM) noexcept {}
		void OnCloseComplete(LPARAM) noexcept {}
		void OnLockComplete(LPARAM) noexcept {}
		void OnUnlockComplete(LPARAM) noexcept {}
		void OnRegisterComplete(LPARAM) noexcept {}
		void OnDeregisterComplete(LPARAM) noexcept {}
		void OnGetInfoComplete(LPARAM) noexcept {}
		void OnExecuteComplete(LPARAM) noexcept {}
		void OnExecuteEvent(LPARAM) noexcept {}
		void OnServiceEvent(LPARAM) noexcept {}
		void OnUserEvent(LPARAM) noexcept {}
		void OnSystemEvent(LPARAM) noexcept {}
		void OnTimerEvent(LPARAM) noexcept {}

        __N_XFSWINDOW__::LAMBDA m_event_lambda{
            [this](const __N_XFSWINDOW__::CONTEXT& context) {
                this->update()
            }
        };

	protected:
	public:
		CXFSDevice() = default;
		CXFSDevice(const CXFSDevice&) = delete;
		CXFSDevice(CXFSDevice&&) = delete;
		CXFSDevice& operator = (const CXFSDevice&) = delete;
		CXFSDevice& operator = (CXFSDevice&&) = delete;
		virtual ~CXFSDevice() = default;

        void update(const WFSRESULT_W&) final;

		HRESULT connect_sync(const TIMEOUT) noexcept final;
		HRESULT connect_async(LAMBDA, const TIMEOUT) noexcept final;
		HRESULT disconnect_sync(const TIMEOUT) noexcept final;
		HRESULT disconnect_async(LAMBDA, const TIMEOUT) noexcept final;
        HRESULT get_inf_sync(const COMMAND, const LPDATA, WFSRESULT_W&, const TIMEOUT) const noexcept final;
        HRESULT get_inf_async(const COMMAND, const LPDATA, LAMBDA, const TIMEOUT) const noexcept final;
        HRESULT execute_sync(const COMMAND, const LPDATA, WFSRESULT_W&, const TIMEOUT) const noexcept final;
        HRESULT execute_async(const COMMAND, const LPDATA, LAMBDA, const TIMEOUT) const noexcept final;
	};
} // !__N_XFSDEVICE__

#endif // !__H_CXFSDEVICE__