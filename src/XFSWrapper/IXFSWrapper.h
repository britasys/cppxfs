#pragma once

#ifndef IXFSWRAPPER_H
#define IXFSWRAPPER_H

#include <XFSAPI.H>

#include <TTFRM_Include/ITTComponent.h>

namespace XFSWrapper
{
	class IXFSWrapper : public TTFRM::ITTComponent
	{
	private:
	protected:
		HWND m_hwnd{ NULL };

	public:
		IXFSWrapper() = default;
		IXFSWrapper(const IXFSWrapper&) = delete;
		IXFSWrapper(const IXFSWrapper&&) = delete;
		IXFSWrapper& operator = (const IXFSWrapper&) = delete;
		IXFSWrapper& operator = (IXFSWrapper&&) = delete;
		virtual ~IXFSWrapper() = default;

		bool Initialize(TTObjectPool::ITTObjectPool*) noexcept final;
		bool UnInitialize() noexcept final;

		virtual BOOL        IsConnected			(HSERVICE hs) const noexcept = 0;

		virtual HRESULT		XFSOpenAsync		(HSERVICE& hs, const char* LogicName, REQUESTID& ReqID) const noexcept = 0;
		virtual HRESULT     XFSCloseAsync		(HSERVICE& hs, REQUESTID& ReqID) const noexcept = 0;
		virtual HRESULT		XFSOpenSync			(HSERVICE& hs, const char* LogicName) const noexcept = 0;
		virtual HRESULT     XFSCloseSync		(HSERVICE& hs) const noexcept = 0;

		virtual HRESULT     XFSLock				(HSERVICE hs, long Timeout, REQUESTID& ReqID) const noexcept = 0;
		virtual HRESULT     XFSUnLock			(HSERVICE hs, REQUESTID& ReqID) const noexcept = 0;

		virtual HRESULT     XFSRegisterAsync	(HSERVICE hs, REQUESTID& ReqID) const noexcept = 0;
		virtual	HRESULT     XFSDeregisterAsync	(HSERVICE hs, REQUESTID& ReqID) const noexcept = 0;
		virtual HRESULT     XFSRegisterSync		(HSERVICE hs) const noexcept = 0;
		virtual	HRESULT     XFSDeregisterSync	(HSERVICE hs) const noexcept = 0;

		virtual HRESULT     XFSCancel			(HSERVICE hs, REQUESTID ReqID) const noexcept = 0;
		virtual HRESULT     XFSFree				(LPWFSRESULT* pResult) const noexcept = 0;

		virtual HRESULT     XFSGetInfoAsync		(HSERVICE hs, DWORD dwCategory, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept = 0;
		virtual HRESULT     XFSExecuteAsync		(HSERVICE hs, DWORD dwCommand, LPVOID pIn, REQUESTID& ReqID, unsigned long Timeout) const noexcept = 0;

		virtual HRESULT     XFSGetInfoSync		(HSERVICE hs, DWORD dwCategory, LPVOID lpQueryDetails, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept = 0;
		virtual HRESULT     XFSExecuteSync		(HSERVICE hs, DWORD dwCommand, LPVOID lpCmdData, LPWFSRESULT* lppResult, DWORD dwTimeOut) const noexcept = 0;
	};

	std::shared_ptr<IXFSWrapper>CreateXFSWrapper() noexcept;
}

#endif // !IXFSWRAPPER_H