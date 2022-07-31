#pragma once

#ifndef __H_CTTCIM__
#define __H_CTTCIM__

#include "../Interfaces/ITTCIM.h"

namespace TTDevice
{
	class CTTCIM : public ITTCIM
	{
	private:
	protected:
	public:
		CTTCIM() = default;
		CTTCIM(const CTTCIM&) = delete;
		CTTCIM(CTTCIM&&) = delete;
		CTTCIM& operator = (const CTTCIM&) = delete;
		CTTCIM& operator = (CTTCIM&&) = delete;
		virtual ~CTTCIM() = default;

		/* CIM Info Functions */
		virtual bool GetStatus(LPTTWFSCIMSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetCapabilities(LPTTWFSCIMCAPS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetCashUnitInfo(LPTTWFSCIMCASHINFO lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetTellerInfo(const LPTTWFSCIMTELLERINFO lpTellerInfo, LPTTWFSCIMP2APTELLERDETAILS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetCurrencyExp(LPTTWFSCIMCURRENCYEXP lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetBankNoteTypes(LPTTWFSCIMNOTETYPELIST lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetCashInStatus(LPTTWFSCIMCASHINSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetP6Info(LPTTWFSCIMP2APP6INFO lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool GetP6Signature(const LPTTWFSCIMGETP6SIGNATURE lpGetP6Signature, LPTTWFSCIMP6SIGNATURE lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		virtual bool AsyncGetStatus(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetCapabilities(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetCashUnitInfo(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetTellerInfo(const LPTTWFSCIMTELLERINFO lpTellerInfo, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetCurrencyExp(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetBankNoteTypes(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetCashInStatus(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetP6Info(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncGetP6Signature(const LPTTWFSCIMGETP6SIGNATURE lpGetP6Signature, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		/* CIM Execute Functions */
		virtual bool CashInStart(const LPTTWFSCIMCASHINSTART lpCashInStart, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool CashIn(LPTTWFSCIMNOTENUMBERLIST lpNoteNumberList, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool CashInEnd(LPTTWFSCIMCASHINFO lpCashInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool CashInRollBack(LPTTWFSCIMCASHINFO lpCashInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool Retract(const LPTTWFSCIMRETRACT lpRetract, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool OpenShutter(const LPWORD lpfwPosition, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool CloseShutter(const LPWORD lpfwPosition, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool SetTellerInfo(const LPTTWFSCIMTELLERUPDATE lpTellerUpdate, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool SetCashUnitInfo(const LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool StartExchange(const LPTTWFSCIMSTARTEX lpStartEx, LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool EndExchange(const LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool OpenSafeDoor(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool Reset(const LPTTWFSCIMITEMPOSITION lpResetIn, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool ConfigureCashInUnits(const LPTTWFSCIMCASHINTYPE * lppCashInType, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool ConfigureNoteTypes(const LPUSHORT lpusNoteIDs, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool CreateP6Signature(LPTTWFSCIMP6SIGNATURE lpP6Signature, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		virtual bool AsyncCashInStart(const LPTTWFSCIMCASHINSTART lpCashInStart, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncCashIn(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncCashInEnd(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncCashInRollBack(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncRetract(const LPTTWFSCIMRETRACT lpRetract, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncOpenShutter(LPWORD lpfwPosition, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncCloseShutter(LPWORD lpfwPosition, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncSetTellerInfo(const LPTTWFSCIMTELLERUPDATE lpTellerUpdate, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncSetCashUnitInfo(const LPTTWFSCIMCASHINFO lpCUInfo, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncStartExchange(const LPTTWFSCIMSTARTEX lpStartEx, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncEndExchange(const LPTTWFSCIMCASHINFO lpCUInfo, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncOpenSafeDoor(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncReset(const LPTTWFSCIMITEMPOSITION lpResetIn, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncConfigureCashInUnits(const LPTTWFSCIMCASHINTYPE * lppCashInType, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncConfigureNoteTypes(const LPUSHORT lpusNoteIDs, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		virtual bool AsyncCreateP6Signature(REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		/* CIM Customized Functions */
		virtual bool TransInfo(const LPTTWFSCRMQUERYTRANSINFO lpQueryTransInfo, LPTTWFSCRMCASHINFO lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		virtual bool AsyncTransInfo(const LPTTWFSCRMQUERYTRANSINFO lpQueryTransInfo, REQUESTID & ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTCIM__
