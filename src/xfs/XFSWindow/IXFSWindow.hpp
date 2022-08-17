#pragma once

#ifndef __H_IXFSWINDOW__
#define __H_IXFSWINDOW__

#include <design/IObserver.hpp>

#include <functional>
#include <memory>
#include <string>

namespace __N_XFSWINDOW__
{
    typedef struct _xfs_window_event_context
    {
        unsigned int msg{ 0 };
        int lparam{ 0 };
    } XFSWINDOWEVENTCONTEXT, * LPXFSWINDOWEVENTCONTEXT;

	using XFSWINDOWLAMBDA = __N_OBSERVER__::LAMBDA<XFSWINDOWEVENTCONTEXT>;

    typedef struct _xfs_window_init
    {
		std::string window_class{ "XFS_WINDOW_CLASS" };
		std::string window_name{ "XFS_WINDOW_NAME" };
        XFSWINDOWLAMBDA lambda{};
    } XFSWINDOWINIT, * LPXFSWINDOWINIT;

	class IXFSWindow : public __N_OBSERVER__::IPublisher<XFSWINDOWEVENTCONTEXT>
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

        virtual bool Initialize(const XFSWINDOWINIT&) noexcept = 0;
        virtual bool UnInitialize() noexcept = 0;
        virtual bool IsInitialized() const noexcept = 0;

		virtual int	 GetWindowHandle() const noexcept = 0;
        virtual std::string GetLastError() const noexcept = 0;
	};

	std::shared_ptr<IXFSWindow> CreateXFSWindow() noexcept;
} // !__N_XFSWINDOW__

#endif // !__H_IXFSWINDOW__