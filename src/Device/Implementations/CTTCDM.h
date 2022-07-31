#pragma once

#ifndef __H_CTTCDM__
#define __H_CTTCDM__

#include "../Interfaces/ITTCDM.h"
#include <DeviceUtility.h>

namespace TTDevice
{
	class CTTCDM : public ITTCDM
	{
	private:
	protected:
		void OnExecuteEvent(LPARAM) noexcept final;
		void OnServiceEvent(LPARAM) noexcept final;
		void OnUserEvent(LPARAM) noexcept final;

	public:
		CTTCDM() = default;
		CTTCDM(const CTTCDM&) = delete;
		CTTCDM(CTTCDM&&) = delete;
		CTTCDM& operator = (const CTTCDM&) = delete;
		CTTCDM& operator = (CTTCDM&&) = delete;
		~CTTCDM() = default;

		/* CDM Info Commands */
		bool GetStatus(LPTTWFSCDMSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSCDMCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCashUnitInfo(LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetTellerInfo(LPTTWFSCDMTELLERINFO, LPTTWFSCDMTELLERDETAILS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCurrencyExp(LPTTWFSCDMP2APCURRENCYEXP, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetMixTypes(LPTTWFSCDMP2APMIXTYPE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetMixTable(LPUSHORT, LPTTWFSCDMMIXTABLE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetPresentStatus(LPWORD, LPTTWFSCDMPRESENTSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCashUnitInfo(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetTellerInfo(LPTTWFSCDMTELLERINFO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCurrencyExp(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetMixTypes(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetMixTable(LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetPresentStatus(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* CDM Execute Commands */
		bool Denominate(const LPTTWFSCDMDENOMINATE, LPTTWFSCDMDENOMINATION, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Dispense(const LPTTWFSCDMDISPENSE, LPTTWFSCDMDENOMINATION, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Count(const LPTTWFSCDMPHYSICALCU, LPTTWFSCDMCOUNT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Present(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reject(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Retract(const LPTTWFSCDMRETRACT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool OpenShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool CloseShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetTelleInfo(const LPTTWFSCDMTELLERUPDATE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetCashUnitInfo(const LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool StartExchange(const LPTTWFSCDMSTARTEX, LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool EndExchange(const LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool OpenSafeDoor(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool CalibirateCashUnit(const LPTTWFSCDMCALIBRATE, LPTTWFSCDMCALIBRATE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetMixTable(const LPTTWFSCDMMIXTABLE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const LPTTWFSCDMITEMPOSITION, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool TestCashUnits(const LPTTWFSCDMITEMPOSITION, LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncDenominate(const LPTTWFSCDMDENOMINATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncDispense(const LPTTWFSCDMDISPENSE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCount(const LPTTWFSCDMPHYSICALCU, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncPresent(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReject(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncRetract(const LPTTWFSCDMRETRACT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncOpenShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCloseShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetTelleInfo(const LPTTWFSCDMTELLERUPDATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetCashUnitInfo(const LPTTWFSCDMCUINFO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncStartExchange(const LPTTWFSCDMSTARTEX, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncEndExchange(const LPTTWFSCDMCUINFO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncOpenSafeDoor(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCalibirateCashUnit(const LPTTWFSCDMCALIBRATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetMixTable(const LPTTWFSCDMMIXTABLE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(const LPTTWFSCDMITEMPOSITION, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncTestCashUnits(const LPTTWFSCDMITEMPOSITION, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTCDM__