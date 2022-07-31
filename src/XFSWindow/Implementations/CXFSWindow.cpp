
#include "CXFSWindow.hpp"

#include <memory>

namespace __N_XFSWINDOW__
{
	bool CXFSWindow::Initialize() noexcept
	{
		if (this->m_pMSGWND->IsInitialized())
			return false;

        __N_CPPMSGWND__::CPPMSGWND_INIT l_init{};
		l_init.window_class.assign("CPPDEVICE_WINDOW_CLASS");
		l_init.window_name.assign("CPPDEVICE_WINDOW_NAME");

		if (!this->m_pMSGWND->Initialize(l_init))
			return false;

		return true;
	}

	bool CXFSWindow::UnInitialize() noexcept
	{
        if (!this->m_pMSGWND->UnInitialize())
            return false;

		return true;
	}

	bool CXFSWindow::RegisterCallBackFunction(XFSWINDOWLAMBDA lambda) noexcept
	{
		__N_CPPMSGWND__::WND_LAMBDA l_lambda = [this, lambda](int hWnd, unsigned int msg, int wparam, int lprama)
		{
			if (hWnd == this->GetWindowHandle())
				lambda(hWnd, msg, lprama);
		};

		if (-1 == this->m_pMSGWND->RegisterCallbackFunction(l_lambda))
            return false;
            
        return true;
	}

	std::shared_ptr<IXFSWindow>CreateXFSWindow() noexcept
	{
		return std::make_shared<CXFSWindow>();
	}
} // !__N_XFSWINDOW__
