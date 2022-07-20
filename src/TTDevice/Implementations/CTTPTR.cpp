
#include "CTTPTR.h"

namespace TTDevice
{
	/*=================================================================*/
	/* PTR Info Functions */
	/*=================================================================*/

	bool  CTTPTR::GetStatus(LPTTWFSPTRSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSPTRSTATUS>(WFS_INF_PTR_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTPTR::GetCapabilities(LPTTWFSPTRCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSPTRCAPS>(WFS_INF_PTR_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTPTR::GetFormList(LPTTWFSPTRLPSTRFORMLIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, LPSTR>(WFS_INF_PTR_FORM_LIST, NULL, lpOut, Timeout);
	}
	bool  CTTPTR::GetMediaList(LPTTWFSPTRLPSTRMEDILIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, LPSTR>(WFS_INF_PTR_MEDIA_LIST, NULL, lpOut, Timeout);
	}
	bool  CTTPTR::QueryForm(const LPSTR lpIn, LPTTWFSFRMHEADER lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSFRMHEADER>(WFS_INF_PTR_QUERY_FORM, lpIn, lpOut, Timeout);
	}
	bool  CTTPTR::QueryMedia(const LPSTR lpIn, LPTTWFSFRMMEDIA lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSFRMMEDIA>(WFS_INF_PTR_QUERY_MEDIA, lpIn, lpOut, Timeout);
	}
	bool  CTTPTR::QueryField(const LPTTWFSPTRQUERYFIELD lpIn, LPTTWFSPTRLPSTRFIELDLIST lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<XFS300::LPWFSPTRQUERYFIELD, XFS300::LPWFSFRMFIELD>(WFS_INF_PTR_QUERY_FIELD, lpIn, lpOut, Timeout);
	}

	bool  CTTPTR::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncGetFormList(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_FORM_LIST, NULL, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncGetMediaList(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_MEDIA_LIST, NULL, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncQueryForm(const LPSTR lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_QUERY_FORM, lpIn, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncQueryMedia(const LPSTR lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_QUERY_MEDIA, lpIn, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncQueryField(const LPTTWFSPTRQUERYFIELD lpIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PTR_QUERY_FIELD, lpIn, ReqID, Timeout);
	}
	/*=================================================================*/
	/* PTR Execute Functions */
	/*=================================================================*/

	bool  CTTPTR::ControlMedia(const LPDWORD lpdwMediaControl, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPDWORD, nullptr_t>(WFS_CMD_PTR_CONTROL_MEDIA, lpdwMediaControl, NULL, Timeout);
	}
	bool  CTTPTR::PrintForm(const LPTTWFSPTRPRINTFORM lpPrintForm, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPTRPRINTFORM, nullptr_t>(WFS_CMD_PTR_PRINT_FORM, lpPrintForm, NULL, Timeout);
	}
	bool  CTTPTR::ReadForm(const LPTTWFSPTRREADFORM lpReadForm, LPTTWFSPTRREADFORMOUT lpReadFormOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPTRREADFORM, XFS300::LPWFSPTRREADFORMOUT>(WFS_CMD_PTR_READ_FORM, lpReadForm, lpReadFormOut, Timeout);
	}
	bool  CTTPTR::RawData(const LPTTWFSPTRRAWDATA lpRawData, LPTTWFSPTRRAWDATAIN lpRawDataIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPTRRAWDATA, XFS300::LPWFSPTRRAWDATAIN>(WFS_CMD_PTR_RAW_DATA, lpRawData, lpRawDataIn, Timeout);
	}
	bool  CTTPTR::MediaExtents(const LPTTWFSPTRMEDIAUNIT lpMediaUnit, LPTTWFSPTRMEDIAEXT lpMediaExt, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPTRMEDIAUNIT, XFS300::LPWFSPTRMEDIAEXT>(WFS_CMD_PTR_MEDIA_EXTENTS, lpMediaUnit, lpMediaExt, Timeout);
	}
	bool  CTTPTR::ResetCount(LPUSHORT lpusBinNumber, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPUSHORT, nullptr_t>(WFS_CMD_PTR_RESET_COUNT, lpusBinNumber, NULL, Timeout);
	}
	bool  CTTPTR::ReadImage(const LPTTWFSPTRIMAGEREQUEST lpImageRequest, LPTTWFSPTRIMAGE lpImage, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPTRIMAGEREQUEST, XFS300::LPWFSPTRIMAGE>(WFS_CMD_PTR_READ_IMAGE, lpImageRequest, lpImage, Timeout);
	}
	bool  CTTPTR::Reset(const LPTTWFSPTRRESET lpReset, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPTRRESET, nullptr_t>(WFS_CMD_PTR_RESET, lpReset, NULL, Timeout);
	}
	bool  CTTPTR::RetractMedia(LPUSHORT lpusBinNumber_in, LPTTWFSPTRLPUSHORTRETRACTMEDIA lpusBinNumber_out, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPUSHORT, LPUSHORT>(WFS_CMD_PTR_RETRACT_MEDIA, lpusBinNumber_in, lpusBinNumber_out, Timeout);
	}
	bool  CTTPTR::DispensePaper(LPWORD lpwPaperSource, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, nullptr_t>(WFS_CMD_PTR_DISPENSE_PAPER, lpwPaperSource, NULL, Timeout);
	}

	bool  CTTPTR::AsyncControlMedia(LPDWORD lpdwMediaControl, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_CONTROL_MEDIA, lpdwMediaControl, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncPrintForm(const LPTTWFSPTRPRINTFORM lpPrintForm, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_PRINT_FORM, lpPrintForm, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncReadForm(const LPTTWFSPTRREADFORM lpReadForm, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_READ_FORM, lpReadForm, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncRawData(const LPTTWFSPTRRAWDATA lpRawData, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_RAW_DATA, lpRawData, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncMediaExtents(const LPTTWFSPTRMEDIAUNIT lpMediaUnit, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_MEDIA_EXTENTS, lpMediaUnit, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncResetCount(LPUSHORT lpusBinNumber, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_RESET_COUNT, lpusBinNumber, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncReadImage(const LPTTWFSPTRIMAGEREQUEST lpImageRequest, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_READ_IMAGE, lpImageRequest, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncReset(const LPTTWFSPTRRESET lpReset, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_RESET, lpReset, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncRetractMedia(LPUSHORT lpusBinNumber, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_RETRACT_MEDIA, lpusBinNumber, ReqID, Timeout);
	}
	bool  CTTPTR::AsyncDispensePaper(WORD wPaperSource, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PTR_DISPENSE_PAPER, &wPaperSource, ReqID, Timeout);
	}
}
