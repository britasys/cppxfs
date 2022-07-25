#pragma once

#ifndef __H_IXFSWINDOW__
#define __H_IXFSWINDOW__

#include <functional>
#include <memory>
#include <string>

namespace __N_XFSWINDOW__
{
	using XFSWINDOWLAMBDA = std::function<void(int, unsigned int, int)>;

	class IXFSWindow
	{
	private:
	protected:
	public:
		IXFSWindow() = default;
		IXFSWindow(const IXFSWindow&) = delete;
		IXFSWindow(IXFSWindow&&) = delete;
		IXFSWindow& operator = (const IXFSWindow&) = delete;
		IXFSWindow& operator = (IXFSWindow&&) = delete;
		virtual ~IXFSWindow() = default;

        virtual bool Initialize() noexcept = 0;
        virtual bool UnInitialize() noexcept = 0;
        virtual bool IsInitialized() const noexcept = 0;

		virtual bool RegisterCallBackFunction(XFSWINDOWLAMBDA) noexcept = 0;

		virtual int	 GetWindowHandle() const noexcept = 0;
        virtual std::string GetLastError() const noexcept = 0;
	};

	std::shared_ptr<IXFSWindow> CreateXFSWindow() noexcept;
} // !__N_XFSWINDOW__

#endif // !__H_IXFSWINDOW__