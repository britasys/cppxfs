#pragma once

#ifndef __H_CTTCAM__
#define __H_CTTCAM__

#include "../Interfaces/ITTCAM.h"

namespace TTDevice
{
	class CTTCAM : public ITTCAM
	{
	private:
	protected:
	public:
		CTTCAM() = default;
		CTTCAM(const CTTCAM&) = delete;
		CTTCAM(CTTCAM&&) = delete;
		CTTCAM& operator =(const CTTCAM&) = delete;
		CTTCAM& operator = (CTTCAM&&) = delete;
		virtual ~CTTCAM() = default;

		/* CAM Info Functions */
		bool GetStatus(LPTTWFSCAMSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSCAMCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* CAM Execute Functions */
		bool TakePicture(const LPTTWFSCAMTAKEPICT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncTakePicture(const LPTTWFSCAMTAKEPICT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}

#endif // !__H_CTTCAM__