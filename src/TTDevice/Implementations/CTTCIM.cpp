
#include "CTTCIM.h"

namespace TTDevice
{
	/*=================================================================*/
	/* CIM Info Functions */
	/*=================================================================*/

	bool  CTTCIM::GetStatus(LPTTWFSCIMSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMSTATUS>(WFS_INF_CIM_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetCapabilities(LPTTWFSCIMCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMCAPS>(WFS_INF_CIM_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetCashUnitInfo(LPTTWFSCIMCASHINFO lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMCASHINFO>(WFS_INF_CIM_CASH_UNIT_INFO, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetTellerInfo(const LPTTWFSCIMTELLERINFO lpTellerInfo, LPTTWFSCIMP2APTELLERDETAILS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSCIMTELLERINFO, XFS300::LPWFSCIMTELLERDETAILS>(WFS_INF_CIM_TELLER_INFO, lpTellerInfo, lpOut, Timeout);
	}
	bool  CTTCIM::GetCurrencyExp(LPTTWFSCIMCURRENCYEXP lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMCURRENCYEXP>(WFS_INF_CIM_CURRENCY_EXP, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetBankNoteTypes(LPTTWFSCIMNOTETYPELIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMNOTETYPELIST>(WFS_INF_CIM_BANKNOTE_TYPES, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetCashInStatus(LPTTWFSCIMCASHINSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMCASHINSTATUS>(WFS_INF_CIM_CASH_IN_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetP6Info(LPTTWFSCIMP2APP6INFO lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCIMP6INFO>(WFS_INF_CIM_GET_P6_INFO, NULL, lpOut, Timeout);
	}
	bool  CTTCIM::GetP6Signature(const LPTTWFSCIMGETP6SIGNATURE lpGetP6Signature, LPTTWFSCIMP6SIGNATURE lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSCIMGETP6SIGNATURE, LPTTWFSCIMP6SIGNATURE>(WFS_INF_CIM_GET_P6_SIGNATURE, lpGetP6Signature, lpOut, Timeout);
	}

	bool  CTTCIM::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetCashUnitInfo(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_CASH_UNIT_INFO, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetTellerInfo(const LPTTWFSCIMTELLERINFO lpTellerInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_TELLER_INFO, lpTellerInfo, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetCurrencyExp(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_CURRENCY_EXP, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetBankNoteTypes(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_BANKNOTE_TYPES, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetCashInStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_CASH_IN_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetP6Info(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_GET_P6_INFO, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncGetP6Signature(const LPTTWFSCIMGETP6SIGNATURE lpGetP6Signature, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CIM_GET_P6_SIGNATURE, lpGetP6Signature, ReqID, Timeout);
	}

	/*=================================================================*/
	/* CIM Execute Functions */
	/*=================================================================*/

	bool  CTTCIM::CashInStart(const LPTTWFSCIMCASHINSTART lpCashInStart, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMCASHINSTART, nullptr_t>(WFS_CMD_CIM_CASH_IN_START, lpCashInStart, NULL, Timeout);
	}
	bool  CTTCIM::CashIn(LPTTWFSCIMNOTENUMBERLIST lpNoteNumberList, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, LPTTWFSCIMNOTENUMBERLIST>(WFS_CMD_CIM_CASH_IN, NULL, lpNoteNumberList, Timeout);
	}
	bool  CTTCIM::CashInEnd(LPTTWFSCIMCASHINFO lpCashInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, LPTTWFSCIMCASHINFO>(WFS_CMD_CIM_CASH_IN_END, NULL, lpCashInfo, Timeout);
	}
	bool  CTTCIM::CashInRollBack(LPTTWFSCIMCASHINFO lpCashInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, LPTTWFSCIMCASHINFO>(WFS_CMD_CIM_CASH_IN_ROLLBACK, NULL, lpCashInfo, Timeout);
	}
	bool  CTTCIM::Retract(const LPTTWFSCIMRETRACT lpRetract, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMRETRACT, nullptr_t>(WFS_CMD_CIM_RETRACT, lpRetract, NULL, Timeout);
	}
	bool  CTTCIM::OpenShutter(LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CIM_OPEN_SHUTTER, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCIM::CloseShutter(LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CIM_CLOSE_SHUTTER, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCIM::SetTellerInfo(const LPTTWFSCIMTELLERUPDATE lpTellerUpdate, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMTELLERUPDATE, nullptr_t>(WFS_CMD_CIM_SET_TELLER_INFO, lpTellerUpdate, NULL, Timeout);
	}
	bool  CTTCIM::SetCashUnitInfo(const LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMCASHINFO, nullptr_t>(WFS_CMD_CIM_SET_CASH_UNIT_INFO, lpCUInfo, NULL, Timeout);
	}
	bool  CTTCIM::StartExchange(const LPTTWFSCIMSTARTEX lpStartEx, LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMSTARTEX, XFS300::LPWFSCIMCASHINFO>(WFS_CMD_CIM_START_EXCHANGE, lpStartEx, lpCUInfo, Timeout);
	}
	bool  CTTCIM::EndExchange(const LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMCASHINFO, nullptr_t>(WFS_CMD_CIM_END_EXCHANGE, lpCUInfo, NULL, Timeout);
	}
	bool  CTTCIM::OpenSafeDoor(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_CIM_OPEN_SAFE_DOOR, NULL, NULL, Timeout);
	}
	bool  CTTCIM::Reset(const LPTTWFSCIMITEMPOSITION lpResetIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCIMITEMPOSITION, nullptr_t>(WFS_CMD_CIM_RESET, lpResetIn, NULL, Timeout);
	}
	bool  CTTCIM::ConfigureCashInUnits(const LPTTWFSCIMCASHINTYPE* lppCashInType, const DWORD Timeout) noexcept
	{
		// needs attention
		/*return TTSyncExecute<XFS300::LPWFSCIMCASHINTYPE, nullptr_t>(WFS_CMD_CIM_CONFIGURE_CASH_IN_UNITS, lppCashInType, NULL, Timeout);*/
		return true;
	}
	bool  CTTCIM::ConfigureNoteTypes(const LPUSHORT lpusNoteIDs, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPUSHORT, nullptr_t>(WFS_CMD_CIM_CONFIGURE_NOTETYPES, lpusNoteIDs, NULL, Timeout);
	}
	bool  CTTCIM::CreateP6Signature(LPTTWFSCIMP6SIGNATURE lpP6Signature, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, XFS300::LPWFSCIMP6SIGNATURE>(WFS_CMD_CIM_CREATE_P6_SIGNATURE, NULL, lpP6Signature, Timeout);
	}

	bool  CTTCIM::AsyncCashInStart(const LPTTWFSCIMCASHINSTART lpCashInStart, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CASH_IN_START, lpCashInStart, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncCashIn(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CASH_IN, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncCashInEnd(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CASH_IN_END, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncCashInRollBack(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CASH_IN_ROLLBACK, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncRetract(const LPTTWFSCIMRETRACT lpRetract, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_RETRACT, lpRetract, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncOpenShutter(LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_OPEN_SHUTTER, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncCloseShutter(LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CLOSE_SHUTTER, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncSetTellerInfo(const LPTTWFSCIMTELLERUPDATE lpTellerUpdate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_SET_TELLER_INFO, lpTellerUpdate, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncSetCashUnitInfo(const LPTTWFSCIMCASHINFO lpCUInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_SET_CASH_UNIT_INFO, lpCUInfo, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncStartExchange(const LPTTWFSCIMSTARTEX lpStartEx, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_START_EXCHANGE, lpStartEx, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncEndExchange(const LPTTWFSCIMCASHINFO lpCUInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_END_EXCHANGE, lpCUInfo, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncOpenSafeDoor(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_OPEN_SAFE_DOOR, NULL, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncReset(const LPTTWFSCIMITEMPOSITION lpResetIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_RESET, lpResetIn, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncConfigureCashInUnits(const LPTTWFSCIMCASHINTYPE* lppCashInType, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CONFIGURE_CASH_IN_UNITS, (LPVOID)lppCashInType, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncConfigureNoteTypes(const LPUSHORT lpusNoteIDs, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CONFIGURE_NOTETYPES, lpusNoteIDs, ReqID, Timeout);
	}
	bool  CTTCIM::AsyncCreateP6Signature(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CIM_CREATE_P6_SIGNATURE, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* CIM Customized Functions */
	/*=================================================================*/

	bool  CTTCIM::TransInfo(const LPTTWFSCRMQUERYTRANSINFO lpQueryTransInfo, LPTTWFSCRMCASHINFO lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSCRMQUERYTRANSINFO, XFS300::LPWFSCRMCASHINFO>(WFS_INF_CRM_CASHINFO_TRANSINFO, lpQueryTransInfo, lpOut, Timeout);
	}

	bool  CTTCIM::AsyncTransInfo(const LPTTWFSCRMQUERYTRANSINFO lpQueryTransInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CRM_CASHINFO_TRANSINFO, lpQueryTransInfo, ReqID, Timeout);
	}
}