#pragma once

#ifndef __H_CXFSTTU__
#define __H_CXFSTTU__

#include "../Interfaces/ITTTTU.h"

namespace TTDevice
{
	class CTTTTU : public ITTTTU
	{
	private:
	protected:
	public:
		CTTTTU() = default;
		CTTTTU(const CTTTTU&) = delete;
		CTTTTU(CTTTTU&&) = delete;
		CTTTTU& operator = (const CTTTTU&) = delete;
		CTTTTU& operator = (CTTTTU&&) = delete;
		~CTTTTU() = default;

		/* TTU Info Functions */
		bool GetStatus(LPTTWFSTTUSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSTTUCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetFormList(LPTTWFSTTULPSTRFRMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool QueryForm(const LPSTR, LPTTWFSTTUFRMHEADER, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool QueryField(const LPTTWFSTTUQUERYFIELD, LPTTWFSTTUP2APFIELDS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetKeyDetail(LPTTWFSTTUKEYDETAIL, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryForm(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryField(const LPTTWFSTTUQUERYFIELD lpQueryField, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetKeyDetail(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* TTU Execute Functions */
		bool Beep(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ClearScreen(const LPTTWFSTTUCLEARSCREEN, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool DispLight(const LPTTWFSTTUDISPLIGHT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetLED(const LPTTWFSTTUSETLEDS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetResolution(const LPTTWFSTTURESOLUTION, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool WriteForm(const LPTTWFSTTUWRITEFORM, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ReadForm(const LPTTWFSTTUREADFORM, LPTTWFSTTUREADFORMOUT lpReadFormOut, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Write(const LPTTWFSTTUWRITE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Read(const LPTTWFSTTUREAD, LPTTWFSTTUREADIN, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncBeep(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncClearScreen(const LPTTWFSTTUCLEARSCREEN, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncDispLight(const LPTTWFSTTUDISPLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetLED(const LPTTWFSTTUSETLEDS, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetResolution(const LPTTWFSTTURESOLUTION, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncWriteForm(const LPTTWFSTTUWRITEFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReadForm(const LPTTWFSTTUREADFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncWrite(const LPTTWFSTTUWRITE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncRead(const LPTTWFSTTUREAD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CXFSTTU__
