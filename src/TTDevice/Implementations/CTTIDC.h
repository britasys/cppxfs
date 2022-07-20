#pragma once

#ifndef __H_CTTIDC__
#define __H_CTTIDC__

#include "../Interfaces/ITTIDC.h"

namespace TTDevice
{
	class CTTIDC : public ITTIDC
	{
	private:
	protected:
	public:
		CTTIDC() = default;
		CTTIDC(const CTTIDC&) = delete;
		CTTIDC(CTTIDC&&) = delete;
		CTTIDC& operator = (const CTTIDC&) = delete;
		CTTIDC& operator = (CTTIDC&&) = delete;
		~CTTIDC() = default;

		/* IDC Info Commands */
		bool GetStatus(LPTTWFSIDCSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSIDCCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetFormList(LPTTWFSIDCLPSTRFRMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetQueryForm(LPSTR, LPTTWFSIDCFORM, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetQueryForm(LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* IDC Execute Commands */
		bool ReadTrack(const LPSTR, LPTTWFSSTRSTR, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool WriteTrack(const LPTTWFSIDCWRITETRACK, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool EjectCard(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool RetainCard(LPTTWFSIDCRETAINCARD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ResetCount(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SetKey(const LPTTWFSIDCSETKEY, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ReadRawData(const LPWORD, LPTTWFSIDCP2APCARDDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool WriteRawData(const LPTTWFSIDCCARDDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ChipIO(const LPTTWFSIDCCHIPIO, LPTTWFSIDCCHIPIO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ChipPower(const LPWORD, LPTTWFSIDCCHIPPOWEROUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ParseData(const LPTTWFSIDCPARSEDATA, LPTTWFSSTRSTR, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncReadTrack(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncWriteTrack(const LPTTWFSIDCWRITETRACK, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncEjectCard(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncRetainCard(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncResetCount(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSetKey(const LPTTWFSIDCSETKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReadRawData(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncWriteRawData(const LPTTWFSIDCCARDDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncChipIO(const LPTTWFSIDCCHIPIO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncChipPower(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncParseData(const LPTTWFSIDCPARSEDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}
#endif // !__H_CTTIDC__
