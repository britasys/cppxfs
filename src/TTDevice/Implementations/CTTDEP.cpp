
#include "CTTDEP.h"

namespace TTDevice
{
	/*=================================================================*/
	/* DEP Info Functions */
	/*=================================================================*/

	bool  CTTDEP::GetStatus(LPTTWFSDEPSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSDEPSTATUS>(WFS_INF_DEP_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTDEP::GetCapabilities(LPTTWFSDEPCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSDEPCAPS>(WFS_INF_DEP_CAPABILITIES, NULL, lpOut, Timeout);
	}

	bool  CTTDEP::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_DEP_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTDEP::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_DEP_CAPABILITIES, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* DEP Execute Functions */
	/*=================================================================*/

	bool  CTTDEP::Entry(const LPTTWFSDEPENVELOPE lpEnvelope, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSDEPENVELOPE, nullptr_t>(WFS_CMD_DEP_ENTRY, lpEnvelope, NULL, Timeout);
	}
	bool  CTTDEP::Dispense(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_DEP_DISPENSE, NULL, NULL, Timeout);
	}
	bool  CTTDEP::Retract(const LPTTWFSDEPENVELOPE lpEnvelope, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSDEPENVELOPE, nullptr_t>(WFS_CMD_DEP_RETRACT, lpEnvelope, NULL, Timeout);
	}
	bool  CTTDEP::ResetCount(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_DEP_RESET_COUNT, NULL, NULL, Timeout);
	}
	bool  CTTDEP::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_DEP_RESET, NULL, NULL, Timeout);
	}

	bool  CTTDEP::AsyncEntry(const LPTTWFSDEPENVELOPE lpEnvelope, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_DEP_ENTRY, lpEnvelope, ReqID, Timeout);
	}
	bool  CTTDEP::AsyncDispense(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_DEP_DISPENSE, NULL, ReqID, Timeout);
	}
	bool  CTTDEP::AsyncRetract(const LPTTWFSDEPENVELOPE lpEnvelope, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_DEP_RETRACT, lpEnvelope, ReqID, Timeout);
	}
	bool  CTTDEP::AsyncResetCount(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_DEP_RESET_COUNT, NULL, ReqID, Timeout);
	}
	bool  CTTDEP::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_DEP_RESET, NULL, ReqID, Timeout);
	}
}