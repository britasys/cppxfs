#pragma once

#ifndef __H_CTTCHK__
#define __H_CTTCHK__

#include "../Interfaces/ITTCHK.h"

namespace TTDevice
{
	class CTTCHK : public ITTCHK
	{
	private:
	protected:
	public:
		CTTCHK() = default;
		CTTCHK(const CTTCHK&) = delete;
		CTTCHK(CTTCHK&) = delete;
		CTTCHK& operator = (const CTTCHK&) = delete;
		CTTCHK& operator = (CTTCHK&&) = delete;
		virtual ~CTTCHK() = default;

		/* CHK Info Functions */
		bool GetStatus(LPTTWFSCHKSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSCHKCAPS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool GetFormList(LPTTWFSCHKLPSTRFRMLIST lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool GetMediaList(LPTTWFSCHKLPSTRMEDIALIST lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool QueryForm(const LPSTR lpszFormName, LPTTWFSCHKFRMHEADER lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool QueryMedia(const LPSTR lpszMediaName, LPTTWFSCHKFRMMEDIA lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool QueryField(const LPTTWFSCHKQUERYFIELD lpQueryField, LPTTWFSCHKP2APFRMFIELD lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetFormList(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetMediaList(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryForm(LPSTR lpszFormName, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryMedia(LPSTR lpszMediaName, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncQueryField(const LPTTWFSCHKQUERYFIELD lpQueryField, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		/* CHK Execute Functions */
		bool ProcessForm(const LPTTWFSCHKINPROCESSFORM lpChkInProcessForm, LPTTWFSCHKOUTPROCESSFORM lpOutProcessForm, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(LPWORD lpwResetIn, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncProcessForm(const LPTTWFSCHKINPROCESSFORM lpChkInProcessForm, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(LPWORD lpwResetIn, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // __H_CTTCHK__
