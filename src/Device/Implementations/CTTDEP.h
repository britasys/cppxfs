#pragma once

#ifndef __H_CTTDEP__
#define __H_CTTDEP__

#include "../Interfaces/ITTDEP.h"

namespace TTDevice
{
	class CTTDEP : public ITTDEP
	{
	private:
	protected:
	public:
		CTTDEP() = default;
		CTTDEP(const CTTDEP&) = delete;
		CTTDEP(CTTDEP&&) = delete;
		CTTDEP& operator = (const CTTDEP&) = delete;
		CTTDEP& operator = (CTTDEP&&) = delete;
		virtual ~CTTDEP() = default;

		/* DEP Info Functions */
		virtual bool GetStatus(LPTTWFSDEPSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetCapabilities(LPTTWFSDEPCAPS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		virtual bool AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		/* DEP Execute Functions */
		virtual bool Entry(const LPTTWFSDEPENVELOPE lpEnvelope, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool Dispense(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool Retract(const LPTTWFSDEPENVELOPE lpEnvelope, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool ResetCount(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool Reset(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		virtual bool AsyncEntry(const LPTTWFSDEPENVELOPE lpEnvelope, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncDispense(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncRetract(const LPTTWFSDEPENVELOPE lpEnvelope, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncResetCount(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncReset(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
	};
}
#endif // !__H_CTTDEP__
