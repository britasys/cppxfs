#pragma once

#ifndef __H_IXFSWRAPPER__
#define __H_IXFSWRAPPER__

#include <XFSAPI.H>

#include <string>

namespace __N_XFSWRAPPER__
{
    using TIMEOUT = unsigned long;
    using XFSHWND = int;

    constexpr unsigned int XFS_SUPPORTED_VERSION = 0x00031403;

	class IXFSWrapper
	{
	private:
	protected:
        bool m_bInitialized{ false };
        std::string m_strLastError{};

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

        std::string GetLastError() const noexcept;

		virtual HRESULT XFSOpenAsync		(HSERVICE&, const XFSHWND, const std::string&, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSCloseAsync		(const HSERVICE, const XFSHWND, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSOpenSync			(HSERVICE&, const std::string&) const noexcept = 0;
		virtual HRESULT XFSCloseSync		(const HSERVICE) const noexcept = 0;

		virtual HRESULT XFSLock				(const HSERVICE, const TIMEOUT, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSUnLock			(const HSERVICE, REQUESTID&) const noexcept = 0;

		virtual HRESULT XFSRegisterAsync	(const HSERVICE, const XFSHWND, REQUESTID&) const noexcept = 0;
		virtual	HRESULT XFSDeregisterAsync	(const HSERVICE, const XFSHWND, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSRegisterSync		(const HSERVICE, const XFSHWND) const noexcept = 0;
		virtual	HRESULT XFSDeregisterSync	(const HSERVICE, const XFSHWND) const noexcept = 0;

		virtual HRESULT XFSCancel			(const HSERVICE, const REQUESTID) const noexcept = 0;
		virtual HRESULT XFSFree				(LPWFSRESULT*) const noexcept = 0;

		virtual HRESULT XFSGetInfoAsync		(const HSERVICE, const XFSHWND, const DWORD, const LPVOID, REQUESTID&, const TIMEOUT) const noexcept = 0;
		virtual HRESULT XFSExecuteAsync		(const HSERVICE, const XFSHWND, const DWORD, const LPVOID, REQUESTID&, const TIMEOUT) const noexcept = 0;

		virtual HRESULT XFSGetInfoSync		(const HSERVICE, DWORD, LPVOID, LPWFSRESULT*, const TIMEOUT) const noexcept = 0;
		virtual HRESULT XFSExecuteSync		(const HSERVICE, DWORD, LPVOID, LPWFSRESULT*, const TIMEOUT) const noexcept = 0;
	};

	std::shared_ptr<IXFSWrapper> CreateXFSWrapper() noexcept;
} // !__N_XFSWRAPPER__

#endif // !__H_IXFSWRAPPER__