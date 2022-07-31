
#include "CTTCAM.h"

namespace TTDevice
{
	/*=================================================================*/
	/* CAM Info Functions */
	/*=================================================================*/

	bool CTTCAM::GetStatus(LPTTWFSCAMSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCAMSTATUS>(WFS_INF_CAM_STATUS, NULL, lpOut, Timeout);
	}
	bool CTTCAM::GetCapabilities(LPTTWFSCAMCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSCAMCAPS>(WFS_INF_CAM_CAPABILITIES, NULL, lpOut, Timeout);
	}

	bool CTTCAM::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CAM_STATUS, NULL, ReqID, Timeout);
	}
	bool CTTCAM::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_CAM_CAPABILITIES, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* CAM Execute Functions */
	/*=================================================================*/

	bool CTTCAM::TakePicture(const LPTTWFSCAMTAKEPICT lpIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSCAMTAKEPICT, nullptr_t>(WFS_CMD_CAM_TAKE_PICTURE, lpIn, NULL, Timeout);
	}
	bool CTTCAM::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_CAM_RESET, NULL, NULL, Timeout);
	}

	bool CTTCAM::AsyncTakePicture(const LPTTWFSCAMTAKEPICT lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_CAM_TAKE_PICTURE, lpIn, ReqID, Timeout);
	}
	bool CTTCAM::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return CTTCAM::TTAsyncExecute(WFS_CMD_CAM_RESET, NULL, ReqID, Timeout);
	}
}
