#pragma once

#ifndef CXFSWRAPPER_H
#define CXFSWRAPPER_H

#include "../IXFSWrapper.h"

namespace XFSWrapper
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

		BOOL        IsConnected			(HSERVICE hs) const noexcept final;

		HRESULT     XFSOpenAsync		(HSERVICE& hs, const char* LogicName, REQUESTID& ReqID) const noexcept final;
		HRESULT     XFSCloseAsync		(HSERVICE& hs, REQUESTID& ReqID) const noexcept final;

		HRESULT		XFSOpenSync			(HSERVICE& hs, const char* LogicName) const noexcept final;
		HRESULT     XFSCloseSync		(HSERVICE& hs) const noexcept final;

		HRESULT     XFSLock				(HSERVICE hs, long Timeout, REQUESTID& ReqID) const noexcept final;
		HRESULT     XFSUnLock			(HSERVICE hs, REQUESTID& ReqID) const noexcept final;

		HRESULT     XFSRegisterAsync	(HSERVICE hs, REQUESTID& ReqID) const noexcept final;
		HRESULT     XFSDeregisterAsync	(HSERVICE hs, REQUESTID& ReqID) const noexcept final;
		HRESULT     XFSRegisterSync		(HSERVICE hs) const noexcept final;
		HRESULT     XFSDeregisterSync	(HSERVICE hs) const noexcept final;

		HRESULT     XFSCancel			(HSERVICE hs, REQUESTID ReqID) const noexcept final;
		HRESULT     XFSFree				(LPWFSRESULT* pResult) const noexcept final;

		HRESULT     XFSGetInfoAsync		(HSERVICE hs, DWORD dwCategory, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept final;
		HRESULT     XFSExecuteAsync		(HSERVICE hs, DWORD dwCommand, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept final;

		HRESULT     XFSGetInfoSync		(HSERVICE hs, DWORD dwCategory, LPVOID lpQueryDetails, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept final;
		HRESULT     XFSExecuteSync		(HSERVICE hs, DWORD dwCommand, LPVOID lpCmdData, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept final;
	};

}

#endif // !CXFSWRAPPER_H