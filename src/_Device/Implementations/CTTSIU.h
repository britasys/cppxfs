#pragma once

#ifndef __H_CTTSIU__
#define __H_CTTSIU__

#include "../Interfaces/ITTSIU.h"

namespace TTDevice
{
	class CTTSIU : public ITTSIU
	{
	private:
	protected:
	public:
		CTTSIU() = default;
		CTTSIU(const CTTSIU&) = delete;
		CTTSIU(CTTSIU&&) = delete;
		CTTSIU& operator = (const CTTSIU&) = delete;
		CTTSIU& operator = (CTTSIU&&) = delete;
		~CTTSIU() = default;

		/* SIU Info Functions */
		bool GetStatus(LPTTWFSSIUSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSSIUCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* SIU Execute Functions */
		bool EnableEvents(const LPTTWFSSIUENABLE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetPorts(const LPTTWFSSIUSETPORTS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetDoor(const LPTTWFSSIUSETDOOR, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetIndicator(const LPTTWFSSIUSETINDICATOR, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetAuxiliary(const LPTTWFSSIUSETAUXILIARY, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetGuidlight(const LPTTWFSSIUSETGUIDLIGHT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncEnableEvents(const LPTTWFSSIUENABLE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetPorts(const LPTTWFSSIUSETPORTS, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetDoor(const LPTTWFSSIUSETDOOR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetIndicator(const LPTTWFSSIUSETINDICATOR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetAuxiliary(const LPTTWFSSIUSETAUXILIARY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetGuidlight(const LPTTWFSSIUSETGUIDLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTSIU__
