
#include "CTTTTU.h"

namespace TTDevice
{
	/*=================================================================*/
	/* TTU Info Functions */
	/*=================================================================*/

	bool  CTTTTU::GetStatus(LPTTWFSTTUSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSTTUSTATUS>(WFS_INF_TTU_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTTTU::GetCapabilities(LPTTWFSTTUCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSTTUCAPS>(WFS_INF_TTU_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTTTU::GetFormList(LPTTWFSTTULPSTRFRMLIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, LPSTR>(WFS_INF_TTU_FORM_LIST, NULL, lpOut, Timeout);
	}
	bool  CTTTTU::QueryForm(LPSTR lpszFormName, LPTTWFSTTUFRMHEADER lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSTTUFRMHEADER>(WFS_INF_TTU_QUERY_FORM, lpszFormName, lpOut, Timeout);
	}
	bool  CTTTTU::QueryField(const LPTTWFSTTUQUERYFIELD lpQueryField, LPTTWFSTTUP2APFIELDS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSTTUQUERYFIELD, XFS300::LPWFSTTUFRMFIELD>(WFS_INF_TTU_QUERY_FIELD, lpQueryField, lpOut, Timeout);
	}
	bool  CTTTTU::GetKeyDetail(LPTTWFSTTUKEYDETAIL lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSTTUKEYDETAIL>(WFS_INF_TTU_KEY_DETAIL, NULL, lpOut, Timeout);
	}

	bool  CTTTTU::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_TTU_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_TTU_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncGetFormList(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_TTU_FORM_LIST, NULL, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncQueryForm(LPSTR lpszFormName, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_TTU_QUERY_FORM, lpszFormName, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncQueryField(const LPTTWFSTTUQUERYFIELD lpQueryField, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_TTU_QUERY_FIELD, lpQueryField, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncGetKeyDetail(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_TTU_KEY_DETAIL, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* TTU Execute Functions */
	/*=================================================================*/

	bool  CTTTTU::Beep(const LPWORD lpwBeep, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_TTU_BEEP, lpwBeep, NULL, Timeout);
	}
	bool  CTTTTU::ClearScreen(const LPTTWFSTTUCLEARSCREEN lpClearScreen, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUCLEARSCREEN, nullptr_t>(WFS_CMD_TTU_CLEARSCREEN, lpClearScreen, NULL, Timeout);
	}
	bool  CTTTTU::DispLight(const LPTTWFSTTUDISPLIGHT lpDispLight, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUDISPLIGHT, nullptr_t>(WFS_CMD_TTU_DISPLIGHT, lpDispLight, NULL, Timeout);
	}
	bool  CTTTTU::SetLED(const LPTTWFSTTUSETLEDS lpSetLEDs, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUSETLEDS, nullptr_t>(WFS_CMD_TTU_SET_LED, lpSetLEDs, NULL, Timeout);
	}
	bool  CTTTTU::SetResolution(const LPTTWFSTTURESOLUTION lpResolution, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTURESOLUTION, nullptr_t>(WFS_CMD_TTU_SET_RESOLUTION, lpResolution, NULL, Timeout);
	}
	bool  CTTTTU::WriteForm(const LPTTWFSTTUWRITEFORM lpWriteform, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUWRITEFORM, nullptr_t>(WFS_CMD_TTU_WRITE_FORM, lpWriteform, NULL, Timeout);
	}
	bool  CTTTTU::ReadForm(const LPTTWFSTTUREADFORM lpReadForm, LPTTWFSTTUREADFORMOUT lpReadFormOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUREADFORM, XFS300::LPWFSTTUREADFORMOUT>(WFS_CMD_TTU_READ_FORM, lpReadForm, lpReadFormOut, Timeout);
	}
	bool  CTTTTU::Write(const LPTTWFSTTUWRITE lpWrite, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUWRITE, nullptr_t>(WFS_CMD_TTU_WRITE, lpWrite, NULL, Timeout);
	}
	bool  CTTTTU::Read(const LPTTWFSTTUREAD lpRead, LPTTWFSTTUREADIN lpReadIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSTTUREAD, nullptr_t>(WFS_CMD_TTU_READ, lpRead, lpReadIn, Timeout);
	}
	bool  CTTTTU::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_TTU_RESET, NULL, NULL, Timeout);
	}

	bool  CTTTTU::AsyncBeep(LPWORD lpwBeep, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_BEEP, lpwBeep, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncClearScreen(const LPTTWFSTTUCLEARSCREEN lpClearScreen, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_CLEARSCREEN, lpClearScreen, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncDispLight(const LPTTWFSTTUDISPLIGHT lpDispLight, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_DISPLIGHT, lpDispLight, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncSetLED(const LPTTWFSTTUSETLEDS lpSetLEDs, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_SET_LED, lpSetLEDs, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncSetResolution(const LPTTWFSTTURESOLUTION lpResolution, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_SET_RESOLUTION, lpResolution, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncWriteForm(const LPTTWFSTTUWRITEFORM lpWriteform, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_WRITE_FORM, lpWriteform, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncReadForm(const LPTTWFSTTUREADFORM lpReadForm, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_READ_FORM, lpReadForm, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncWrite(const LPTTWFSTTUWRITE lpWrite, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_WRITE, lpWrite, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncRead(const LPTTWFSTTUREAD lpRead, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_READ, lpRead, ReqID, Timeout);
	}
	bool  CTTTTU::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_TTU_RESET, NULL, ReqID, Timeout);
	}
}
