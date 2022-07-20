#pragma once

#ifndef __H_CTTCDM_310__
#define __H_CTTCDM_310__

#include "../Interfaces/ITTCDM310.h"
#include <DeviceUtility.h>

namespace TTDevice
{
	class CTTCDM310 : public ITTCDM310
	{
	private:
	protected:
		void OnExecuteEvent(LPARAM) noexcept final;
		void OnServiceEvent(LPARAM) noexcept final;
		void OnUserEvent(LPARAM) noexcept final;

	public:
		CTTCDM310() = default;
		CTTCDM310(const CTTCDM310&) = delete;
		CTTCDM310(CTTCDM310&&) = delete;
		CTTCDM310& operator = (const CTTCDM310&) = delete;
		CTTCDM310& operator = (CTTCDM310&&) = delete;
		~CTTCDM310() = default;

		/* CDM Info Commands */
		bool GetStatus(LPTTWFSCDMSTATUS310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSCDMCAPS310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCashUnitInfo(LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetTellerInfo(LPTTWFSCDMTELLERINFO310, LPTTWFSCDMTELLERDETAILS310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCurrencyExp(LPTTWFSCDMP2APCURRENCYEXP310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetMixTypes(LPTTWFSCDMP2APMIXTYPE310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetMixTable(LPUSHORT, LPTTWFSCDMMIXTABLE310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetPresentStatus(LPWORD, LPTTWFSCDMPRESENTSTATUS310, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCashUnitInfo(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetTellerInfo(LPTTWFSCDMTELLERINFO310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCurrencyExp(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetMixTypes(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetMixTable(LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetPresentStatus(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* CDM Execute Commands */
		bool Denominate(const LPTTWFSCDMDENOMINATE310, LPTTWFSCDMDENOMINATION310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Dispense(const LPTTWFSCDMDISPENSE310, LPTTWFSCDMDENOMINATION310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Count(const LPTTWFSCDMPHYSICALCU310, LPTTWFSCDMCOUNT310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Present(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reject(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Retract(const LPTTWFSCDMRETRACT310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool OpenShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool CloseShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetTelleInfo(const LPTTWFSCDMTELLERUPDATE310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetCashUnitInfo(const LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool StartExchange(const LPTTWFSCDMSTARTEX310, LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool EndExchange(const LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool OpenSafeDoor(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool CalibirateCashUnit(const LPTTWFSCDMCALIBRATE310, LPTTWFSCDMCALIBRATE310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetMixTable(const LPTTWFSCDMMIXTABLE310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const LPTTWFSCDMITEMPOSITION310, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool TestCashUnits(const LPTTWFSCDMITEMPOSITION310, LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncDenominate(const LPTTWFSCDMDENOMINATE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncDispense(const LPTTWFSCDMDISPENSE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCount(const LPTTWFSCDMPHYSICALCU310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncPresent(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReject(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncRetract(const LPTTWFSCDMRETRACT310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncOpenShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCloseShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetTelleInfo(const LPTTWFSCDMTELLERUPDATE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetCashUnitInfo(const LPTTWFSCDMCUINFO310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncStartExchange(const LPTTWFSCDMSTARTEX310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncEndExchange(const LPTTWFSCDMCUINFO310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncOpenSafeDoor(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCalibirateCashUnit(const LPTTWFSCDMCALIBRATE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetMixTable(const LPTTWFSCDMMIXTABLE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(const LPTTWFSCDMITEMPOSITION310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncTestCashUnits(const LPTTWFSCDMITEMPOSITION310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTCDM_310__