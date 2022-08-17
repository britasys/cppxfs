
#include "CTTCDM310.h"

namespace TTDevice
{
	/*=================================================================*/
	/* CDM Events */
	/*=================================================================*/

	void CTTCDM310::OnExecuteEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("CTTCDM310::OnExecuteEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpWFSResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpWFSResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpWFSResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpWFSResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpWFSResult->hResult;

		SAFEPTR(_lpWFSResult->lpBuffer)
		{
			switch (_lpWFSResult->u.dwEventID)
			{
			case WFS_EXEE_CDM_DELAYEDDISPENSE:
			{
				ULONG _ulDelay = *(LPULONG)_lpWFSResult->lpBuffer;
				_DEVEVENTDATA.lpBuffer = new ULONG;
				*(LPULONG)_DEVEVENTDATA.lpBuffer = _ulDelay;
			} break;
			case WFS_EXEE_CDM_STARTDISPENSE:
			{
				REQUESTID _ReqID = *(LPREQUESTID)_lpWFSResult->lpBuffer;
				_DEVEVENTDATA.lpBuffer = new REQUESTID;
				*(LPULONG)_DEVEVENTDATA.lpBuffer = _ReqID;
			} break;
			case WFS_EXEE_CDM_CASHUNITERROR:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCUERROR310;
				((LPTTWFSCDMCUERROR310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMCUERROR)_lpWFSResult->lpBuffer);
			} break;
			case WFS_EXEE_CDM_PARTIALDISPENSE:
			{
				_DEVEVENTDATA.lpBuffer = new USHORT;
				*(LPUSHORT)_DEVEVENTDATA.lpBuffer = *(LPUSHORT)_lpWFSResult->lpBuffer;
			} break;
			case WFS_EXEE_CDM_SUBDISPENSEOK:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMDENOMINATION310;
				((LPTTWFSCDMDENOMINATION310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMDENOMINATION)_lpWFSResult->lpBuffer);
			} break;
			case WFS_EXEE_CDM_INCOMPLETEDISPENSE:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMDENOMINATION310;
				((LPTTWFSCDMDENOMINATION310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMDENOMINATION)_lpWFSResult->lpBuffer);
			} break;
			case WFS_EXEE_CDM_NOTEERROR:
			{
				_DEVEVENTDATA.lpBuffer = new USHORT;
				*(LPUSHORT)_DEVEVENTDATA.lpBuffer = *(LPUSHORT)_lpWFSResult->lpBuffer;
			} break;
			case WFS_EXEE_CDM_MEDIADETECTED:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMITEMPOSITION310;
				((LPTTWFSCDMITEMPOSITION310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMITEMPOSITION)_lpWFSResult->lpBuffer);
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void CTTCDM310::OnServiceEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("CTTCDM310::OnServiceEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpWFSResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpWFSResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpWFSResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpWFSResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpWFSResult->hResult;

		SAFEPTR(_lpWFSResult->lpBuffer)
		{
			switch (_lpWFSResult->u.dwEventID)
			{
			case WFS_SRVE_CDM_SAFEDOOROPEN: break;
			case WFS_SRVE_CDM_SAFEDOORCLOSED: break;
			case WFS_SRVE_CDM_CASHUNITINFOCHANGED:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCASHUNIT310;
				((LPTTWFSCDMCASHUNIT310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMCASHUNIT)_lpWFSResult->lpBuffer);
			} break;
			case WFS_SRVE_CDM_TELLERINFOCHANGED:
			{
				_DEVEVENTDATA.lpBuffer = new USHORT;
				*(LPUSHORT)_DEVEVENTDATA.lpBuffer = *(LPUSHORT)_lpWFSResult->lpBuffer;
			} break;
			case WFS_SRVE_CDM_ITEMSTAKEN:
			{
				_DEVEVENTDATA.lpBuffer = new WORD;
				*(LPWORD)_DEVEVENTDATA.lpBuffer = *(LPWORD)_lpWFSResult->lpBuffer;
			} break;
			case WFS_SRVE_CDM_ITEMSPRESENTED: break;
			case WFS_SRVE_CDM_COUNTS_CHANGED:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCOUNTSCHANGED310;
				((LPTTWFSCDMCOUNTSCHANGED310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMCOUNTSCHANGED)_lpWFSResult->lpBuffer);
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void CTTCDM310::OnUserEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("CTTCDM310::OnUserEvent - (%s) - EventID: %d - %s",
			m_szLogicName.c_str(), _lpWFSResult->u.dwEventID, NOVADESCRIBE_XFS_MESSAGE(_lpWFSResult->u.dwEventID));

		NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
		_DEVEVENTDATA.DeviceUID = this->m_DeviceUID;
		_DEVEVENTDATA.iRequestID = _lpWFSResult->RequestID;
		_DEVEVENTDATA.iMessage = _lpWFSResult->u.dwEventID;
		_DEVEVENTDATA.iResult = _lpWFSResult->hResult;

		SAFEPTR(_lpWFSResult->lpBuffer)
		{
			switch (_lpWFSResult->u.dwEventID)
			{
			case WFS_USRE_CDM_CASHUNITTHRESHOLD:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCASHUNIT310;
				((LPTTWFSCDMCASHUNIT310)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS310::LPWFSCDMCASHUNIT)_lpWFSResult->lpBuffer);
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	/*=================================================================*/
	/* CDM Info Commands */
	/*=================================================================*/

	bool  CTTCDM310::GetStatus(LPTTWFSCDMSTATUS310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS310::LPWFSCDMSTATUS>(WFS_INF_CDM_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTCDM310::GetCapabilities(LPTTWFSCDMCAPS310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS310::LPWFSCDMCAPS>(WFS_INF_CDM_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTCDM310::GetCashUnitInfo(LPTTWFSCDMCUINFO310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS310::LPWFSCDMCUINFO>(WFS_INF_CDM_CASH_UNIT_INFO, NULL, lpOut, Timeout);
	}
	bool  CTTCDM310::GetTellerInfo(LPTTWFSCDMTELLERINFO310 lpIn, LPTTWFSCDMTELLERDETAILS310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS310::LPWFSCDMTELLERINFO, XFS310::LPWFSCDMTELLERDETAILS>(WFS_INF_CDM_TELLER_INFO, lpIn, lpOut, Timeout);
	}
	bool  CTTCDM310::GetCurrencyExp(LPTTWFSCDMP2APCURRENCYEXP310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS310::LPWFSCDMCURRENCYEXP>(WFS_INF_CDM_CURRENCY_EXP, NULL, lpOut, Timeout);
	}
	bool  CTTCDM310::GetMixTypes(LPTTWFSCDMP2APMIXTYPE310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS310::LPWFSCDMMIXTYPE>(WFS_INF_CDM_MIX_TYPES, NULL, lpOut, Timeout);
	}
	bool  CTTCDM310::GetMixTable(LPUSHORT lpIn, LPTTWFSCDMMIXTABLE310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPUSHORT, XFS310::LPWFSCDMMIXTABLE>(WFS_INF_CDM_MIX_TABLE, lpIn, lpOut, Timeout);
	}
	bool  CTTCDM310::GetPresentStatus(LPWORD lpIn, LPTTWFSCDMPRESENTSTATUS310 lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPWORD, XFS310::LPWFSCDMPRESENTSTATUS>(WFS_INF_CDM_PRESENT_STATUS, lpIn, lpOut, Timeout);
	}

	bool  CTTCDM310::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetCashUnitInfo(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_CASH_UNIT_INFO, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetTellerInfo(LPTTWFSCDMTELLERINFO310 lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_TELLER_INFO, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetCurrencyExp(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_CURRENCY_EXP, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetMixTypes(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_MIX_TYPES, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetMixTable(LPUSHORT lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_MIX_TABLE, lpIn, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncGetPresentStatus(LPWORD lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_PRESENT_STATUS, lpIn, ReqID, Timeout);
	}

	/*=================================================================*/
	/* CDM Execute Commands */
	/*=================================================================*/

	bool  CTTCDM310::Denominate(LPTTWFSCDMDENOMINATE310 lpDinominate, LPTTWFSCDMDENOMINATION310 lpDenomination, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMDENOMINATE, XFS310::LPWFSCDMDENOMINATION>(WFS_CMD_CDM_DENOMINATE, lpDinominate, lpDenomination, Timeout);
	}
	bool  CTTCDM310::Dispense(LPTTWFSCDMDISPENSE310 lpDispens, LPTTWFSCDMDENOMINATION310 lpDenomination, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMDISPENSE, XFS310::LPWFSCDMDENOMINATION>(WFS_CMD_CDM_DISPENSE, lpDispens, lpDenomination, Timeout);
	}
	bool  CTTCDM310::Count(LPTTWFSCDMPHYSICALCU310 lpPhysicalCU, LPTTWFSCDMCOUNT310 lpCount, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMPHYSICALCU, XFS310::LPWFSCDMCOUNT>(WFS_CMD_CDM_COUNT, lpPhysicalCU, lpCount, Timeout);
	}
	bool  CTTCDM310::Present(const LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CDM_PRESENT, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCDM310::Reject(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_CDM_REJECT, NULL, NULL, Timeout);
	}
	bool  CTTCDM310::Retract(const LPTTWFSCDMRETRACT310 lpRetract, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMRETRACT, nullptr_t>(WFS_CMD_CDM_RETRACT, lpRetract, NULL, Timeout);
	}
	bool  CTTCDM310::OpenShutter(const LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CDM_OPEN_SHUTTER, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCDM310::CloseShutter(const LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CDM_CLOSE_SHUTTER, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCDM310::SetTelleInfo(const LPTTWFSCDMTELLERUPDATE310 lpWFSCDMTellerUpdate, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMTELLERUPDATE, nullptr_t>(WFS_CMD_CDM_SET_TELLER_INFO, lpWFSCDMTellerUpdate, NULL, Timeout);
	}
	bool  CTTCDM310::SetCashUnitInfo(const LPTTWFSCDMCUINFO310 lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMCUINFO, nullptr_t>(WFS_CMD_CDM_SET_CASH_UNIT_INFO, lpCUInfo, NULL, Timeout);
	}
	bool  CTTCDM310::StartExchange(const LPTTWFSCDMSTARTEX310 lpStartEx, LPTTWFSCDMCUINFO310 lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMSTARTEX, XFS310::LPWFSCDMCUINFO>(WFS_CMD_CDM_START_EXCHANGE, lpStartEx, lpCUInfo, Timeout);
	}
	bool  CTTCDM310::EndExchange(const LPTTWFSCDMCUINFO310 lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMCUINFO, nullptr_t>(WFS_CMD_CDM_END_EXCHANGE, lpCUInfo, NULL, Timeout);
	}
	bool  CTTCDM310::OpenSafeDoor(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_CDM_OPEN_SAFE_DOOR, NULL, NULL, Timeout);
	}
	bool  CTTCDM310::CalibirateCashUnit(LPTTWFSCDMCALIBRATE310 lpCalibrateIn, LPTTWFSCDMCALIBRATE310 lpCalibrateOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMCALIBRATE, XFS310::LPWFSCDMCALIBRATE>(WFS_CMD_CDM_CALIBRATE_CASH_UNIT, lpCalibrateIn, lpCalibrateOut, Timeout);
	}
	bool  CTTCDM310::SetMixTable(LPTTWFSCDMMIXTABLE310 lpMixTable, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMMIXTABLE, nullptr_t>(WFS_CMD_CDM_SET_MIX_TABLE, lpMixTable, NULL, Timeout);
	}
	bool  CTTCDM310::Reset(LPTTWFSCDMITEMPOSITION310 lpResetIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMITEMPOSITION, nullptr_t>(WFS_CMD_CDM_RESET, lpResetIn, NULL, Timeout);
	}
	bool  CTTCDM310::TestCashUnits(LPTTWFSCDMITEMPOSITION310 lpPosition, LPTTWFSCDMCUINFO310 lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSCDMITEMPOSITION, XFS310::LPWFSCDMCUINFO>(WFS_CMD_CDM_TEST_CASH_UNITS, lpPosition, lpCUInfo, Timeout);
	}

	bool  CTTCDM310::AsyncDenominate(LPTTWFSCDMDENOMINATE310 lpDinominate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_DENOMINATE, lpDinominate, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncDispense(LPTTWFSCDMDISPENSE310 lpDispens, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_DISPENSE, lpDispens, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncCount(LPTTWFSCDMPHYSICALCU310 lpPhysicalCU, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_COUNT, lpPhysicalCU, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncPresent(LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_PRESENT, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncReject(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_REJECT, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncRetract(const LPTTWFSCDMRETRACT310 lpRetract, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_RETRACT, lpRetract, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncOpenShutter(const LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_OPEN_SHUTTER, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncCloseShutter(const LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_CLOSE_SHUTTER, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncSetTelleInfo(LPTTWFSCDMTELLERUPDATE310 lpWFSCDMTellerUpdate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_SET_TELLER_INFO, lpWFSCDMTellerUpdate, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncSetCashUnitInfo(LPTTWFSCDMCUINFO310 lpCUInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_SET_CASH_UNIT_INFO, lpCUInfo, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncStartExchange(LPTTWFSCDMSTARTEX310 lpStartEx, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_START_EXCHANGE, lpStartEx, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncEndExchange(LPTTWFSCDMCUINFO310 lpCUInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_END_EXCHANGE, lpCUInfo, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncOpenSafeDoor(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_OPEN_SAFE_DOOR, NULL, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncCalibirateCashUnit(LPTTWFSCDMCALIBRATE310 lpCalibrateIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_CALIBRATE_CASH_UNIT, lpCalibrateIn, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncSetMixTable(LPTTWFSCDMMIXTABLE310 lpMixTable, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_SET_MIX_TABLE, lpMixTable, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncReset(LPTTWFSCDMITEMPOSITION310 lpResetIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_RESET, lpResetIn, ReqID, Timeout);
	}
	bool  CTTCDM310::AsyncTestCashUnits(LPTTWFSCDMITEMPOSITION310 lpPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_TEST_CASH_UNITS, lpPosition, ReqID, Timeout);
	}
}