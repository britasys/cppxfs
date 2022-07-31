
#include "CTTBCR.h"

namespace TTDevice 
{
	/*=================================================================*/
	/* BCR Info Commands */
	/*=================================================================*/

	bool  CTTBCR::GetStatus(LPTTWFSBCRSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSBCRSTATUS>(WFS_INF_BCR_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTBCR::GetCapabilities(LPTTWFSBCRCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSBCRCAPS>(WFS_INF_BCR_CAPABILITIES, NULL, lpOut, Timeout);
	}

	bool  CTTBCR::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_BCR_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTBCR::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_BCR_CAPABILITIES, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* BCR Execute Commands */
	/*=================================================================*/

	bool  CTTBCR::Read(const LPTTWFSBCRREADINPUT lpReadInput, LPTTWFSBCRREADOUTPUT lpReadOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSBCRREADINPUT, XFS300::LPWFSBCRREADOUTPUT>(WFS_CMD_BCR_READ, lpReadInput, lpReadOutput, Timeout);////////////////////////////////////////////////s
	}
	bool  CTTBCR::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_BCR_RESET, NULL, NULL, Timeout);
	}
	bool  CTTBCR::SetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSBCRSETGUIDLIGHT, nullptr_t>(WFS_CMD_BCR_SET_GUIDANCE_LIGHT, lpSetGuidLight, NULL, Timeout);
	}

	bool  CTTBCR::AsyncRead(const LPTTWFSBCRREADINPUT lpReadInput, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_READ, lpReadInput, ReqID, Timeout);
	}
	bool  CTTBCR::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_RESET, NULL, ReqID, Timeout);
	}
	bool  CTTBCR::AsyncSetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_SET_GUIDANCE_LIGHT, lpSetGuidLight, ReqID, Timeout);
	}
}