#pragma once

#ifndef __H_CXFSWINDOW__
#define __H_CXFSWINDOW__

#include "../IXFSWindow.h"

#include <ICPPMSGWND.hpp>

#include <memory>

namespace __N_XFSWINDOW__
{
	class CXFSWindow : public IXFSWindow
	{
	private:
        XFSWINDOWINIT m_init{};
		std::shared_ptr<__N_CPPMSGWND__::ICPPMSGWND> m_pMSGWND{ __N_CPPMSGWND__::CreateCPPMSGWND() };
        
        __N_CPPWNDMSG__::WND_LAMBDA m_lambda{ [](
            const __N_CPPWNDMSG__::WND_HWND     hwnd, 
            const __N_CPPWNDMSG__::WND_MSG      msg, 
            const __N_CPPWNDMSG__::WND_WPARAM   wparam, 
            const __N_CPPWNDMSG__::WND_LPARAM   lparam) {
                __N_OBSERVER__::XFSWINDOWEVENTCONTEXT event_context{};
                event_context.msg       = msg;
                event_context.lparam    = lparam;
                this->notify(event_context);
                this->notify();
        }};

	protected:
	public:
		CXFSWindow() = default;
		CXFSWindow(const CXFSWindow&) = delete;
		CXFSWindow(CXFSWindow&&) = delete;
		CXFSWindow& operator = (const CXFSWindow&) = delete;
		CXFSWindow& operator = (CXFSWindow&&) = delete;
		virtual ~CXFSWindow() = default;

        bool Initialize(const XFSWINDOWINIT&) noexcept final;
        bool UnInitialize() noexcept final;
        bool IsInitialized() const noexcept final { return this->m_pMSGWND->IsInitialized(); }

		int	 GetWindowHandle() const noexcept { return this->m_pMSGWND->GetHWND(); }
        virtual std::string GetLastError() const noexcept final { return this->m_pMSGWND->getLastError(); }
	};
} // !__N_XFSWINDOW__

#endif // !__H_CXFSWINDOW__