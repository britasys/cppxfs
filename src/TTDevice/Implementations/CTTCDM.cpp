
#include "CTTCDM.h"

namespace TTDevice
{
	/*=================================================================*/
	/* CDM Events */
	/*=================================================================*/

	void CTTCDM::OnExecuteEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("CTTCDM::OnExecuteEvent - (%s) - EventID: %d - %s",
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
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCUERROR;
				((LPTTWFSCDMCUERROR)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMCUERROR)_lpWFSResult->lpBuffer);
			} break;
			case WFS_EXEE_CDM_PARTIALDISPENSE:
			{
				_DEVEVENTDATA.lpBuffer = new USHORT;
				*(LPUSHORT)_DEVEVENTDATA.lpBuffer = *(LPUSHORT)_lpWFSResult->lpBuffer;
			} break;
			case WFS_EXEE_CDM_SUBDISPENSEOK:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMDENOMINATION;
				((LPTTWFSCDMDENOMINATION)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMDENOMINATION)_lpWFSResult->lpBuffer);
			} break;
			case WFS_EXEE_CDM_INCOMPLETEDISPENSE:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMDENOMINATION;
				((LPTTWFSCDMDENOMINATION)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMDENOMINATION)_lpWFSResult->lpBuffer);
			} break;
			case WFS_EXEE_CDM_NOTEERROR:
			{
				_DEVEVENTDATA.lpBuffer = new USHORT;
				*(LPUSHORT)_DEVEVENTDATA.lpBuffer = *(LPUSHORT)_lpWFSResult->lpBuffer;
			} break;
			case WFS_EXEE_CDM_MEDIADETECTED:
			{
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMITEMPOSITION;
				((LPTTWFSCDMITEMPOSITION)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMITEMPOSITION)_lpWFSResult->lpBuffer);
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void CTTCDM::OnServiceEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("CTTCDM::OnServiceEvent - (%s) - EventID: %d - %s",
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
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCASHUNIT;
				((LPTTWFSCDMCASHUNIT)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMCASHUNIT)_lpWFSResult->lpBuffer);
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
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCOUNTSCHANGED;
				((LPTTWFSCDMCOUNTSCHANGED)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMCOUNTSCHANGED)_lpWFSResult->lpBuffer);
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	void CTTCDM::OnUserEvent(LPARAM lParam) noexcept
	{
		LPWFSRESULT _lpWFSResult = ((LPWFSRESULT)lParam);
		DEBUGLOG("CTTCDM::OnUserEvent - (%s) - EventID: %d - %s",
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
				_DEVEVENTDATA.lpBuffer = new TTWFSCDMCASHUNIT;
				((LPTTWFSCDMCASHUNIT)_DEVEVENTDATA.lpBuffer)->WFS2TT((XFS300::LPWFSCDMCASHUNIT)_lpWFSResult->lpBuffer);
			} break;
			default: break;
			}
		}

		this->InformRegisteredComponents(_DEVEVENTDATA);
	}

	/*=================================================================*/
	/* CDM Info Commands */
	/*=================================================================*/

	bool  CTTCDM::GetStatus(LPTTWFSCDMSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCDMSTATUS>(WFS_INF_CDM_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTCDM::GetCapabilities(LPTTWFSCDMCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCDMCAPS>(WFS_INF_CDM_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTCDM::GetCashUnitInfo(LPTTWFSCDMCUINFO lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCDMCUINFO>(WFS_INF_CDM_CASH_UNIT_INFO, NULL, lpOut, Timeout);
	}
	bool  CTTCDM::GetTellerInfo(LPTTWFSCDMTELLERINFO lpIn, LPTTWFSCDMTELLERDETAILS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSCDMTELLERINFO, XFS300::LPWFSCDMTELLERDETAILS>(WFS_INF_CDM_TELLER_INFO, lpIn, lpOut, Timeout);
	}
	bool  CTTCDM::GetCurrencyExp(LPTTWFSCDMP2APCURRENCYEXP lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCDMCURRENCYEXP>(WFS_INF_CDM_CURRENCY_EXP, NULL, lpOut, Timeout);
	}
	bool  CTTCDM::GetMixTypes(LPTTWFSCDMP2APMIXTYPE  lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCDMMIXTYPE>(WFS_INF_CDM_MIX_TYPES, NULL, lpOut, Timeout);
	}
	bool  CTTCDM::GetMixTable(LPUSHORT lpIn, LPTTWFSCDMMIXTABLE lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPUSHORT, XFS300::LPWFSCDMMIXTABLE>(WFS_INF_CDM_MIX_TABLE, lpIn, lpOut, Timeout);
	}
	bool  CTTCDM::GetPresentStatus(LPWORD lpIn, LPTTWFSCDMPRESENTSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPWORD, XFS300::LPWFSCDMPRESENTSTATUS>(WFS_INF_CDM_PRESENT_STATUS, lpIn, lpOut, Timeout);
	}

	bool  CTTCDM::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetCashUnitInfo(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_CASH_UNIT_INFO, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetTellerInfo(LPTTWFSCDMTELLERINFO lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_TELLER_INFO, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetCurrencyExp(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_CURRENCY_EXP, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetMixTypes(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_MIX_TYPES, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetMixTable(LPUSHORT lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_MIX_TABLE, lpIn, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncGetPresentStatus(LPWORD lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CDM_PRESENT_STATUS, lpIn, ReqID, Timeout);
	}

	/*=================================================================*/
	/* CDM Execute Commands */
	/*=================================================================*/

	bool  CTTCDM::Denominate(LPTTWFSCDMDENOMINATE lpDinominate, LPTTWFSCDMDENOMINATION lpDenomination, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMDENOMINATE, XFS300::LPWFSCDMDENOMINATION>(WFS_CMD_CDM_DENOMINATE, lpDinominate, lpDenomination, Timeout);
	}
	bool  CTTCDM::Dispense(LPTTWFSCDMDISPENSE lpDispens, LPTTWFSCDMDENOMINATION lpDenomination, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMDISPENSE, XFS300::LPWFSCDMDENOMINATION>(WFS_CMD_CDM_DISPENSE, lpDispens, lpDenomination, Timeout);
	}
	bool  CTTCDM::Count(LPTTWFSCDMPHYSICALCU lpPhysicalCU, LPTTWFSCDMCOUNT lpCount, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMPHYSICALCU, XFS300::LPWFSCDMCOUNT>(WFS_CMD_CDM_COUNT, lpPhysicalCU, lpCount, Timeout);
	}
	bool  CTTCDM::Present(const LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CDM_PRESENT, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCDM::Reject(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_CDM_REJECT, NULL, NULL, Timeout);
	}
	bool  CTTCDM::Retract(const LPTTWFSCDMRETRACT lpRetract, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMRETRACT, nullptr_t>(WFS_CMD_CDM_RETRACT, lpRetract, NULL, Timeout);
	}
	bool  CTTCDM::OpenShutter(const LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CDM_OPEN_SHUTTER, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCDM::CloseShutter(const LPWORD lpfwPosition, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CDM_CLOSE_SHUTTER, lpfwPosition, NULL, Timeout);
	}
	bool  CTTCDM::SetTelleInfo(const LPTTWFSCDMTELLERUPDATE lpWFSCDMTellerUpdate, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMTELLERUPDATE, nullptr_t>(WFS_CMD_CDM_SET_TELLER_INFO, lpWFSCDMTellerUpdate, NULL, Timeout);
	}
	bool  CTTCDM::SetCashUnitInfo(const LPTTWFSCDMCUINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMCUINFO, nullptr_t>(WFS_CMD_CDM_SET_CASH_UNIT_INFO, lpCUInfo, NULL, Timeout);
	}
	bool  CTTCDM::StartExchange(const LPTTWFSCDMSTARTEX lpStartEx, LPTTWFSCDMCUINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMSTARTEX, XFS300::LPWFSCDMCUINFO>(WFS_CMD_CDM_START_EXCHANGE, lpStartEx, lpCUInfo, Timeout);
	}
	bool  CTTCDM::EndExchange(const LPTTWFSCDMCUINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMCUINFO, nullptr_t>(WFS_CMD_CDM_END_EXCHANGE, lpCUInfo, NULL, Timeout);
	}
	bool  CTTCDM::OpenSafeDoor(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_CDM_OPEN_SAFE_DOOR, NULL, NULL, Timeout);
	}
	bool  CTTCDM::CalibirateCashUnit(LPTTWFSCDMCALIBRATE lpCalibrateIn, LPTTWFSCDMCALIBRATE lpCalibrateOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMCALIBRATE, XFS300::LPWFSCDMCALIBRATE>(WFS_CMD_CDM_CALIBRATE_CASH_UNIT, lpCalibrateIn, lpCalibrateOut, Timeout);
	}
	bool  CTTCDM::SetMixTable(LPTTWFSCDMMIXTABLE lpMixTable, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMMIXTABLE, nullptr_t>(WFS_CMD_CDM_SET_MIX_TABLE, lpMixTable, NULL, Timeout);
	}
	bool  CTTCDM::Reset(LPTTWFSCDMITEMPOSITION lpResetIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMITEMPOSITION, nullptr_t>(WFS_CMD_CDM_RESET, lpResetIn, NULL, Timeout);
	}
	bool  CTTCDM::TestCashUnits(LPTTWFSCDMITEMPOSITION lpPosition, LPTTWFSCDMCUINFO lpCUInfo, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCDMITEMPOSITION, XFS300::LPWFSCDMCUINFO>(WFS_CMD_CDM_TEST_CASH_UNITS, lpPosition, lpCUInfo, Timeout);
	}

	bool  CTTCDM::AsyncDenominate(LPTTWFSCDMDENOMINATE lpDinominate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_DENOMINATE, lpDinominate, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncDispense(LPTTWFSCDMDISPENSE lpDispens, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_DISPENSE, lpDispens, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncCount(LPTTWFSCDMPHYSICALCU lpPhysicalCU, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_COUNT, lpPhysicalCU, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncPresent(LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_PRESENT, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncReject(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_REJECT, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncRetract(const LPTTWFSCDMRETRACT lpRetract, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_RETRACT, lpRetract, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncOpenShutter(const LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_OPEN_SHUTTER, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncCloseShutter(const LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_CLOSE_SHUTTER, lpfwPosition, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncSetTelleInfo(LPTTWFSCDMTELLERUPDATE lpWFSCDMTellerUpdate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_SET_TELLER_INFO, lpWFSCDMTellerUpdate, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncSetCashUnitInfo(LPTTWFSCDMCUINFO lpCUInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_SET_CASH_UNIT_INFO, lpCUInfo, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncStartExchange(LPTTWFSCDMSTARTEX lpStartEx, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_START_EXCHANGE, lpStartEx, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncEndExchange(LPTTWFSCDMCUINFO lpCUInfo, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_END_EXCHANGE, lpCUInfo, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncOpenSafeDoor(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_OPEN_SAFE_DOOR, NULL, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncCalibirateCashUnit(LPTTWFSCDMCALIBRATE lpCalibrateIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_CALIBRATE_CASH_UNIT, lpCalibrateIn, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncSetMixTable(LPTTWFSCDMMIXTABLE lpMixTable, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_SET_MIX_TABLE, lpMixTable, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncReset(LPTTWFSCDMITEMPOSITION lpResetIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_RESET, lpResetIn, ReqID, Timeout);
	}
	bool  CTTCDM::AsyncTestCashUnits(LPTTWFSCDMITEMPOSITION lpPosition, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CDM_TEST_CASH_UNITS, lpPosition, ReqID, Timeout);
	}
}