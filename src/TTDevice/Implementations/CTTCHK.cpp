
#include "CTTCHK.h"

namespace TTDevice
{
	/*=================================================================*/
	/* CHK Info Functions */
	/*=================================================================*/

	bool  CTTCHK::GetStatus(LPTTWFSCHKSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCHKSTATUS>(WFS_INF_CHK_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTCHK::GetCapabilities(LPTTWFSCHKCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCHKCAPS>(WFS_INF_CHK_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTCHK::GetFormList(LPTTWFSCHKLPSTRFRMLIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, LPSTR>(WFS_INF_CHK_FORM_LIST, NULL, lpOut, Timeout);
	}
	bool  CTTCHK::GetMediaList(LPTTWFSCHKLPSTRMEDIALIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, LPSTR>(WFS_INF_CHK_MEDIA_LIST, NULL, lpOut, Timeout);
	}
	bool  CTTCHK::QueryForm(const LPSTR lpszFormName, LPTTWFSCHKFRMHEADER lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSCHKFRMHEADER>(WFS_INF_CHK_QUERY_FORM, lpszFormName, lpOut, Timeout);
	}
	bool  CTTCHK::QueryMedia(const LPSTR lpszMediaName, LPTTWFSCHKFRMMEDIA lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSCHKFRMMEDIA>(WFS_INF_CHK_QUERY_MEDIA, lpszMediaName, lpOut, Timeout);
	}
	bool  CTTCHK::QueryField(const LPTTWFSCHKQUERYFIELD lpQueryField, LPTTWFSCHKP2APFRMFIELD lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSCHKQUERYFIELD, XFS300::LPWFSCHKFRMFIELD>(WFS_INF_CHK_QUERY_FIELD, lpQueryField, lpOut, Timeout);
	}

	bool  CTTCHK::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncGetFormList(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_FORM_LIST, NULL, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncGetMediaList(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_MEDIA_LIST, NULL, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncQueryForm(const LPSTR lpszFormName, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_QUERY_FORM, lpszFormName, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncQueryMedia(const LPSTR lpszMediaName, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_QUERY_MEDIA, lpszMediaName, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncQueryField(const LPTTWFSCHKQUERYFIELD lpQueryField, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CHK_QUERY_FIELD, lpQueryField, ReqID, Timeout);
	}

	/*=================================================================*/
	/* CHK Execute Functions */
	/*=================================================================*/

	bool  CTTCHK::ProcessForm(const LPTTWFSCHKINPROCESSFORM lpChkInProcessForm, LPTTWFSCHKOUTPROCESSFORM lpOutProcessForm, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCHKINPROCESSFORM, XFS300::LPWFSCHKOUTPROCESSFORM>(WFS_CMD_CHK_PROCESS_FORM, lpChkInProcessForm, lpOutProcessForm, Timeout);
	}
	bool  CTTCHK::Reset(const LPWORD lpwResetIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_CHK_RESET, lpwResetIn, NULL, Timeout);
	}

	bool  CTTCHK::AsyncProcessForm(const LPTTWFSCHKINPROCESSFORM lpChkInProcessForm, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CHK_PROCESS_FORM, lpChkInProcessForm, ReqID, Timeout);
	}
	bool  CTTCHK::AsyncReset(LPWORD lpwResetIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CHK_RESET, lpwResetIn, ReqID, Timeout);
	}
}