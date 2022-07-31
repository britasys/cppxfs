#pragma once

#ifndef __H_CTTPTR__
#define __H_CTTPTR__

#include "../Interfaces/ITTPTR.h"

namespace TTDevice
{
	class CTTPTR : public ITTPTR
	{
	private:
	protected:
	public:
		CTTPTR() = default;
		CTTPTR(const CTTPTR&) = delete;
		CTTPTR(CTTPTR&&) = delete;
		CTTPTR& operator = (const CTTPTR) = delete;
		CTTPTR& operator = (CTTPTR&&) = delete;
		virtual ~CTTPTR() = default;

		/* PTR Info Functions */
		bool GetStatus(LPTTWFSPTRSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSPTRCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetFormList(LPTTWFSPTRLPSTRFORMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetMediaList(LPTTWFSPTRLPSTRMEDILIST, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool QueryForm(const LPSTR, LPTTWFSFRMHEADER, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool QueryMedia(const LPSTR, LPTTWFSFRMMEDIA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool QueryField(const LPTTWFSPTRQUERYFIELD, LPTTWFSPTRLPSTRFIELDLIST, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetMediaList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryForm(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryMedia(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryField(const LPTTWFSPTRQUERYFIELD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* PTR Execute Functions */
		bool ControlMedia(const LPDWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool PrintForm(const LPTTWFSPTRPRINTFORM, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ReadForm(const LPTTWFSPTRREADFORM, LPTTWFSPTRREADFORMOUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool RawData(const LPTTWFSPTRRAWDATA, LPTTWFSPTRRAWDATAIN, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool MediaExtents(const LPTTWFSPTRMEDIAUNIT, LPTTWFSPTRMEDIAEXT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ResetCount(const LPUSHORT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ReadImage(const LPTTWFSPTRIMAGEREQUEST, LPTTWFSPTRIMAGE lpImage, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const LPTTWFSPTRRESET, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool RetractMedia(const LPUSHORT, LPTTWFSPTRLPUSHORTRETRACTMEDIA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool DispensePaper(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncControlMedia(const LPDWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncPrintForm(const LPTTWFSPTRPRINTFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReadForm(const LPTTWFSPTRREADFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncRawData(const LPTTWFSPTRRAWDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncMediaExtents(const LPTTWFSPTRMEDIAUNIT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncResetCount(LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReadImage(const LPTTWFSPTRIMAGEREQUEST, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(const LPTTWFSPTRRESET, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncRetractMedia(const LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncDispensePaper(const WORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTPTR__
