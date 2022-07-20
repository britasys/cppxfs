
#include "CTTSIU.h"

namespace TTDevice
{
	/*=================================================================*/
	/* SIU Info Functions */
	/*=================================================================*/

	bool  CTTSIU::GetStatus(LPTTWFSSIUSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSSIUSTATUS>(WFS_INF_SIU_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTSIU::GetCapabilities(LPTTWFSSIUCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSSIUCAPS>(WFS_INF_SIU_CAPABILITIES, NULL, lpOut, Timeout);
	}

	bool  CTTSIU::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_SIU_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_SIU_CAPABILITIES, NULL, ReqID, Timeout);
	}

	/*=================================================================*/
	/* SIU Execute Functions */
	/*=================================================================*/

	bool  CTTSIU::EnableEvents(const LPTTWFSSIUENABLE lpEnable, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSSIUENABLE, nullptr_t>(WFS_CMD_SIU_ENABLE_EVENTS, lpEnable, NULL, Timeout);
	}
	bool  CTTSIU::SetPorts(const LPTTWFSSIUSETPORTS lpSetPort, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSSIUSETPORTS, nullptr_t>(WFS_CMD_SIU_SET_PORTS, lpSetPort, NULL, Timeout);
	}
	bool  CTTSIU::SetDoor(const LPTTWFSSIUSETDOOR lpSetDoor, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSSIUSETDOOR, nullptr_t>(WFS_CMD_SIU_SET_DOOR, lpSetDoor, NULL, Timeout);
	}
	bool  CTTSIU::SetIndicator(const LPTTWFSSIUSETINDICATOR lpSetIndicator, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSSIUSETINDICATOR, nullptr_t>(WFS_CMD_SIU_SET_INDICATOR, lpSetIndicator, NULL, Timeout);
	}
	bool  CTTSIU::SetAuxiliary(const LPTTWFSSIUSETAUXILIARY lpSetAuxiliary, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSSIUSETAUXILIARY, nullptr_t>(WFS_CMD_SIU_SET_AUXILIARY, lpSetAuxiliary, NULL, Timeout);
	}
	bool  CTTSIU::SetGuidlight(const LPTTWFSSIUSETGUIDLIGHT lpSetGuidlight, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSSIUSETGUIDLIGHT, nullptr_t>(WFS_CMD_SIU_SET_GUIDLIGHT, lpSetGuidlight, NULL, Timeout);
	}
	bool  CTTSIU::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_SIU_RESET, NULL, NULL, Timeout);
	}

	bool  CTTSIU::AsyncEnableEvents(const LPTTWFSSIUENABLE lpEnable, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_ENABLE_EVENTS, lpEnable, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncSetPorts(const LPTTWFSSIUSETPORTS lpSetPort, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_SET_PORTS, lpSetPort, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncSetDoor(const LPTTWFSSIUSETDOOR lpSetDoor, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_SET_DOOR, lpSetDoor, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncSetIndicator(const LPTTWFSSIUSETINDICATOR lpSetIndicator, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_SET_INDICATOR, lpSetIndicator, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncSetAuxiliary(const LPTTWFSSIUSETAUXILIARY lpSetAuxiliary, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_SET_AUXILIARY, lpSetAuxiliary, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncSetGuidlight(const LPTTWFSSIUSETGUIDLIGHT lpSetGuidlight, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_SET_GUIDLIGHT, lpSetGuidlight, ReqID, Timeout);
	}
	bool  CTTSIU::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_SIU_RESET, NULL, ReqID, Timeout);
	}
}
