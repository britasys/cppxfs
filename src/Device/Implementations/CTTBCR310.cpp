
#include "CTTBCR310.h"

namespace TTDevice
{
	/*=================================================================*/
	/* BCR310 Info Commands */
	/*=================================================================*/
	
	HRESULT CTTBCR310::GetStatus(LPTTWFSBCRSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS310::LPWFSBCRSTATUS>(WFS_INF_BCR_STATUS, NULL, lpOut, Timeout);
	}
	HRESULT CTTBCR310::GetCapabilities(LPTTWFSBCRCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS310::LPWFSBCRCAPS>(WFS_INF_BCR_CAPABILITIES, NULL, lpOut, Timeout);
	}
	
	HRESULT CTTBCR310::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_BCR_STATUS, NULL, ReqID, Timeout);
	}
	HRESULT CTTBCR310::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_BCR_CAPABILITIES, NULL, ReqID, Timeout);
	}
	
	/*=================================================================*/
	/* BCR310 Execute Commands */
	/*=================================================================*/
	
	HRESULT CTTBCR310::Read(const LPTTWFSBCRREADINPUT lpReadInput, LPTTWFSBCRREADOUTPUT lpReadOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS310::LPWFSBCRREADOUTPUT>(WFS_CMD_BCR_READ, lpReadInput, lpReadOutput, Timeout);
	}
	HRESULT CTTBCR310::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t>(WFS_CMD_BCR_RESET, NULL, NULL, Timeout);
	}
	HRESULT CTTBCR310::SetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t>(WFS_CMD_BCR_SET_GUIDANCE_LIGHT, (LPVOID)lpSetGuidLight, NULL, Timeout);
	}
	HRESULT CTTBCR310::PowerSaveControl(const LPTTWFSBCRPOWERSAVECONTROL lpPowerSaveControl, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t>(WFS_CMD_BCR_POWER_SAVE_CONTROL, lpPowerSaveControl, NULL, Timeout);
	}
	
	HRESULT CTTBCR310::AsyncRead(const LPTTWFSBCRREADINPUT lpReadInput, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_READ, lpReadInput, ReqID, Timeout);
	}
	HRESULT CTTBCR310::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_RESET, NULL, ReqID, Timeout);
	}
	HRESULT CTTBCR310::AsyncSetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_SET_GUIDANCE_LIGHT, lpSetGuidLight, ReqID, Timeout);
	}
	HRESULT CTTBCR310::AsyncPowerSaveControl(const LPTTWFSBCRPOWERSAVECONTROL lpPowerSaveControl, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_BCR_POWER_SAVE_CONTROL, lpPowerSaveControl, ReqID, Timeout);
	}
}
