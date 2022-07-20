#pragma once

#ifndef __H_CTTBCR310__
#define __H_CTTBCR310__

#include "../Interfaces/ITTBCR310.h"

namespace  TTDevice
{
	class CTTBCR310 : public ITTBCR310
	{
	private:
	public:
		CTTBCR310() = default;
		CTTBCR310(const CTTBCR310&) = delete;
		CTTBCR310(CTTBCR310&&) = delete;
		CTTBCR310& operator = (const CTTBCR310) = delete;
		CTTBCR310& operator = (CTTBCR310&&) = delete;
		virtual ~CTTBCR310() = default;

		/* BCR310 Info Commands */
		HRESULT GetStatus(LPTTWFSBCRSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT GetCapabilities(LPTTWFSBCRCAPS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		HRESULT AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		/* BCR310 Execute Commands */
		HRESULT Read(const LPTTWFSBCRREADINPUT lpReadInput, LPTTWFSBCRREADOUTPUT lpReadOutput, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT Reset(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT SetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT PowerSaveControl(const LPTTWFSBCRPOWERSAVECONTROL lpPowerSaveControl, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;

		HRESULT AsyncRead(const LPTTWFSBCRREADINPUT lpReadInput, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT AsyncReset(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT AsyncSetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT lpSetGuidLight, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
		HRESULT AsyncPowerSaveControl(const LPTTWFSBCRPOWERSAVECONTROL lpPowerSaveControl, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept final;
	};	
}

#endif // !__H_CTTBCR310__
