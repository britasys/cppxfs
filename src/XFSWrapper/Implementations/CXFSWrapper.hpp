#pragma once

#ifndef __H_CXFSWRAPPER__
#define __H_CXFSWRAPPER__

#include "../IXFSWrapper.hpp"

namespace __N_XFSWRAPPER__
{
	class CXFSWrapper : public IXFSWrapper
	{
	private:
	protected:
	public:
		CXFSWrapper() = default;
		CXFSWrapper(const CXFSWrapper&) = delete;
		CXFSWrapper(const CXFSWrapper&&) = delete;
		CXFSWrapper& operator = (const CXFSWrapper&) = delete;
		CXFSWrapper& operator = (CXFSWrapper&&) = delete;
		virtual ~CXFSWrapper() = default;

		virtual HRESULT XFSOpenAsync		(HSERVICE&, const XFSHWND, const std::string&, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSCloseAsync		(const HSERVICE, const XFSHWND, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSOpenSync			(HSERVICE&, const std::string&) const noexcept = 0;
		virtual HRESULT XFSCloseSync		(const HSERVICE) const noexcept = 0;

		virtual HRESULT XFSLock				(const HSERVICE, const XFSHWND, const TIMEOUT, REQUESTID&) const noexcept = 0;
		virtual HRESULT XFSUnLock			(const HSERVICE, const XFSHWND, REQUESTID&) const noexcept = 0;

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
} // !__N_XFSWRAPPER__

#endif // !__H_CXFSWRAPPER__