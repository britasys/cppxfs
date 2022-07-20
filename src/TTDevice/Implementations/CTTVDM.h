#pragma once

#ifndef __H_CTTVDM__
#define __H_CTTVDM__

#include "../Interfaces/ITTVDM.h"

namespace TTDevice
{
	class CTTVDM : public ITTVDM
	{
	private:
	protected:
	public:
		CTTVDM() = default;
		CTTVDM(const CTTVDM&) = delete;
		CTTVDM(CTTVDM&&) = delete;
		CTTVDM& operator = (const CTTVDM) = delete;
		CTTVDM& operator = (CTTVDM&&) = delete;
		virtual ~CTTVDM() = default;

		/* VDM Info Functions */
		bool GetStatus(LPTTWFSVDMSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSVDMCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* VDM Execute Functions */
		bool EnterModeReq(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool EnterModeAck(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ExitModeReq(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ExitModeAck(const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncEnterModeReq(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncEnterModeAck(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncExitModeReq(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncExitModeAck(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTVDM__
