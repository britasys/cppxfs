
#include "CTTIDC.h"

namespace TTDevice
{
	/*=================================================================*/
	/* IDC Info Commands */
	/*=================================================================*/

	bool  CTTIDC::GetStatus(LPTTWFSIDCSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSIDCSTATUS>(WFS_INF_IDC_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTIDC::GetCapabilities(LPTTWFSIDCCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSIDCCAPS>(WFS_INF_IDC_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTIDC::GetFormList(LPTTWFSIDCLPSTRFRMLIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, LPSTR>(WFS_INF_IDC_FORM_LIST, NULL, lpOut, Timeout);
	}
	bool  CTTIDC::GetQueryForm(const LPSTR lpIn, LPTTWFSIDCFORM lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSIDCFORM>(WFS_INF_IDC_QUERY_FORM, lpIn, lpOut, Timeout);
	}

	bool  CTTIDC::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_IDC_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_IDC_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncGetFormList(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_IDC_FORM_LIST, NULL, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncGetQueryForm(const LPSTR lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_IDC_QUERY_FORM, lpIn, ReqID, Timeout);
	}

	/*=================================================================*/
	/* IDC Execute Commands */
	/*=================================================================*/

	bool  CTTIDC::ReadTrack(const LPSTR lpstrFormName, LPTTWFSSTRSTR lpstrTrackData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPSTR, LPSTR>(WFS_CMD_IDC_READ_TRACK, lpstrFormName, lpstrTrackData, Timeout);
	}
	bool  CTTIDC::WriteTrack(const LPTTWFSIDCWRITETRACK lpWriteTrack, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSIDCWRITETRACK, nullptr_t>(WFS_CMD_IDC_WRITE_TRACK, lpWriteTrack, NULL, Timeout);
	}
	bool  CTTIDC::EjectCard(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_IDC_EJECT_CARD, NULL, NULL, Timeout);
	}
	bool  CTTIDC::RetainCard(LPTTWFSIDCRETAINCARD lpRetainCard, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, XFS300::LPWFSIDCRETAINCARD>(WFS_CMD_IDC_RETAIN_CARD, NULL, lpRetainCard, Timeout);
	}
	bool  CTTIDC::ResetCount(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_IDC_RESET_COUNT, NULL, NULL, Timeout);
	}
	bool  CTTIDC::SetKey(const LPTTWFSIDCSETKEY lpSetkey, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSIDCSETKEY, nullptr_t>(WFS_CMD_IDC_SETKEY, lpSetkey, NULL, Timeout);
	}
	bool  CTTIDC::ReadRawData(const LPWORD lpwReadData, LPTTWFSIDCP2APCARDDATA lpCardData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, XFS300::LPWFSIDCCARDDATA>(WFS_CMD_IDC_READ_RAW_DATA, lpwReadData, lpCardData, Timeout);
	}
	bool  CTTIDC::WriteRawData(const LPTTWFSIDCCARDDATA lpCardData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSIDCCARDDATA, nullptr_t>(WFS_CMD_IDC_WRITE_RAW_DATA, lpCardData, NULL, Timeout);
	}
	bool  CTTIDC::ChipIO(const LPTTWFSIDCCHIPIO lpChipIoIn, LPTTWFSIDCCHIPIO lpChipIoOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSIDCCHIPIO, XFS300::LPWFSIDCCHIPIO>(WFS_CMD_IDC_CHIP_IO, lpChipIoIn, lpChipIoOut, Timeout);
	}
	bool  CTTIDC::Reset(const LPWORD lpwResetIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_IDC_RESET, lpwResetIn, NULL, Timeout);
	}
	bool  CTTIDC::ChipPower(const LPWORD lpwChipPower, LPTTWFSIDCCHIPPOWEROUT lpChipPowerOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, XFS300::LPWFSIDCCHIPPOWEROUT>(WFS_CMD_IDC_CHIP_POWER, lpwChipPower, lpChipPowerOut, Timeout);
	}
	bool  CTTIDC::ParseData(const LPTTWFSIDCPARSEDATA lpParseData, LPTTWFSSTRSTR lpstrTrackData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSIDCPARSEDATA, LPSTR>(WFS_CMD_IDC_PARSE_DATA, lpParseData, lpstrTrackData, Timeout);
	}

	bool  CTTIDC::AsyncReadTrack(LPSTR lpstrFormName, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_READ_TRACK, lpstrFormName, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncWriteTrack(const LPTTWFSIDCWRITETRACK lpWriteTrack, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_WRITE_TRACK, lpWriteTrack, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncEjectCard(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_EJECT_CARD, NULL, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncRetainCard(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_RETAIN_CARD, NULL, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncResetCount(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_RESET_COUNT, NULL, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncSetKey(const LPTTWFSIDCSETKEY lpSetkey, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_SETKEY, lpSetkey, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncReadRawData(LPWORD lpwReadData, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_READ_RAW_DATA, lpwReadData, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncWriteRawData(const LPTTWFSIDCCARDDATA lpCardData, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_WRITE_RAW_DATA, lpCardData, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncChipIO(const LPTTWFSIDCCHIPIO lpChipIoIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_CHIP_IO, lpChipIoIn, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncReset(const LPWORD lpwResetIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_RESET, lpwResetIn, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncChipPower(const LPWORD lpwChipPower, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_CHIP_POWER, lpwChipPower, ReqID, Timeout);
	}
	bool  CTTIDC::AsyncParseData(const LPTTWFSIDCPARSEDATA lpParseData, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_IDC_PARSE_DATA, lpParseData, ReqID, Timeout);
	}
}