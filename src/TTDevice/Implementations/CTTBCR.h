#pragma once

#ifndef __H_CTTBCR__
#define __H_CTTBCR__

#include "../Interfaces/ITTBCR.h"

namespace TTDevice
{
	class CTTBCR : public ITTBCR
	{
	private:
	protected:
	public:
		CTTBCR() = default;
		CTTBCR(const CTTBCR&) = delete;
		CTTBCR(CTTBCR&&) = delete;
		CTTBCR& operator = (const CTTBCR&) = delete;
		CTTBCR& operator = (CTTBCR&&) = delete;
		virtual ~CTTBCR() = default;

		/* BCR Info Commands */
		bool 	GetStatus(LPTTWFSBCRSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool 	GetCapabilities(LPTTWFSBCRCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool 	AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool 	AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* BCR Execute Commands */
		bool 	Read(const LPTTWFSBCRREADINPUT, LPTTWFSBCRREADOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool 	Reset(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool 	SetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool 	AsyncRead(const LPTTWFSBCRREADINPUT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool 	AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool 	AsyncSetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTBCR__
