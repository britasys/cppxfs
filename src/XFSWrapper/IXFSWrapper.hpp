#pragma once

#ifndef __H_IXFSWRAPPER__
#define __H_IXFSWRAPPER__

#include <XFSAPI.H>

#include <string>

#include "../XFSWindow/IXFSWindow.hpp"

namespace __N_XFSWRAPPER__
{
    using TIMEOUT = unsigned long;

    typedef struct _xfserapper_init
    {

    } XFSWRAPPER_INIT, * LP_XFSWRAPPER_INIT;

	class IXFSWrapper
	{
	private:
	protected:
        bool m_bInitialized{ false };
        std::shared_ptr<__N_XFSWINDOW__::IXFSWindow> m_pXFSWindow{ __N_XFSWINDOW__::CreateXFSWindow() };

	public:
		IXFSWrapper() = default;
		IXFSWrapper(const IXFSWrapper&) = delete;
		IXFSWrapper(const IXFSWrapper&&) = delete;
		IXFSWrapper& operator = (const IXFSWrapper&) = delete;
		IXFSWrapper& operator = (IXFSWrapper&&) = delete;
		virtual ~IXFSWrapper() = default;

		bool Initialize() noexcept;
		bool UnInitialize() noexcept;
        bool IsInitialized() const noexcept;

		virtual HRESULT XFSOpenAsync		(HSERVICE&, const std::string&, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSCloseAsync		(const HSERVICE, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSOpenSync			(HSERVICE&, const std::string&) const noexcept = 0;
		virtual HRESULT XFSCloseSync		(const HSERVICE) const noexcept = 0;

		virtual HRESULT XFSLock				(const HSERVICE, const TIMEOUT, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSUnLock			(const HSERVICE, REQUESTID&) const noexcept = 0;

		virtual HRESULT XFSRegisterAsync	(const HSERVICE, REQUESTID&) const noexcept = 0;
		virtual	HRESULT XFSDeregisterAsync	(const HSERVICE, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSRegisterSync		(const HSERVICE) const noexcept = 0;
		virtual	HRESULT XFSDeregisterSync	(const HSERVICE) const noexcept = 0;

		virtual HRESULT XFSCancel			(const HSERVICE, const REQUESTID) const noexcept = 0;
		virtual HRESULT XFSFree				(LPWFSRESULT*) const noexcept = 0;

		virtual HRESULT XFSGetInfoAsync		(const HSERVICE, const DWORD, const LPVOID, REQUESTID&, const TIMEOUT) const noexcept = 0;
		virtual HRESULT XFSExecuteAsync		(const HSERVICE, const DWORD, const LPVOID, REQUESTID&, const TIMEOUT) const noexcept = 0;

		virtual HRESULT XFSGetInfoSync		(const HSERVICE, DWORD, LPVOID, LPWFSRESULT*, const TIMEOUT) const noexcept = 0;
		virtual HRESULT XFSExecuteSync		(const HSERVICE, DWORD, LPVOID, LPWFSRESULT*, const TIMEOUT) const noexcept = 0;
	};

	std::shared_ptr<IXFSWrapper> CreateXFSWrapper() noexcept;
} // !__N_XFSWRAPPER__

#endif // !__H_IXFSWRAPPER__