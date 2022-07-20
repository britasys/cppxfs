
#include "CTTVDM.h"

namespace TTDevice
{
	/*=================================================================*/
	/* VDM Info Functions */
	/*=================================================================*/

	bool  CTTVDM::GetStatus(LPTTWFSVDMSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSVDMSTATUS>(WFS_INF_VDM_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTVDM::GetCapabilities(LPTTWFSVDMCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSVDMCAPS>(WFS_INF_VDM_CAPABILITIES, NULL, lpOut, Timeout);
	}

	bool  CTTVDM::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_VDM_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTVDM::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_VDM_CAPABILITIES, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* VDM Execute Functions */
	/*=================================================================*/

	bool  CTTVDM::EnterModeReq(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_VDM_ENTER_MODE_REQ, NULL, NULL, Timeout);
	}
	bool  CTTVDM::EnterModeAck(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_VDM_ENTER_MODE_ACK, NULL, NULL, Timeout);
	}
	bool  CTTVDM::ExitModeReq(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_VDM_EXIT_MODE_REQ, NULL, NULL, Timeout);
	}
	bool  CTTVDM::ExitModeAck(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_VDM_EXIT_MODE_ACK, NULL, NULL, Timeout);
	}

	bool  CTTVDM::AsyncEnterModeReq(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_VDM_ENTER_MODE_REQ, NULL, ReqID, Timeout);
	}
	bool  CTTVDM::AsyncEnterModeAck(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_VDM_ENTER_MODE_ACK, NULL, ReqID, Timeout);
	}
	bool  CTTVDM::AsyncExitModeReq(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_VDM_EXIT_MODE_REQ, NULL, ReqID, Timeout);
	}
	bool  CTTVDM::AsyncExitModeAck(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_VDM_EXIT_MODE_ACK, NULL, ReqID, Timeout);
	}
}
