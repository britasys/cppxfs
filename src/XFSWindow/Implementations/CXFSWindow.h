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
		std::shared_ptr<__N_CPPMSGWND__::ICPPMSGWND> m_pMSGWND{ __N_CPPMSGWND__::CreateCPPMSGWND() };

	protected:
	public:
		CXFSWindow() = default;
		CXFSWindow(const CXFSWindow&) = delete;
		CXFSWindow(CXFSWindow&&) = delete;
		CXFSWindow& operator = (const CXFSWindow&) = delete;
		CXFSWindow& operator = (CXFSWindow&&) = delete;
		virtual ~CXFSWindow() = default;

        bool Initialize() noexcept final;
        bool UnInitialize() noexcept final;
        bool IsInitialized() const noexcept { return this->m_pMSGWND->IsInitialized(); }

		bool RegisterCallBackFunction(XFSWINDOWLAMBDA) noexcept final;

		int	 GetWindowHandle() const noexcept { return this->m_pMSGWND->GetHWND(); }
        virtual std::string GetLastError() const noexcept final { return this->m_pMSGWND->getLastError(); }
	};
} // !__N_XFSWINDOW__

#endif // !__H_CXFSWINDOW__