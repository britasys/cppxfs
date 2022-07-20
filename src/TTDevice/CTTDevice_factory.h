#pragma once

#ifndef __H_CTTDEVICE_FACTORY__
#define __H_CTTDEVICE_FACTORY__

#include <memory>

namespace TTDevice { class ITTBCR; };
namespace TTDevice { class ITTCAM; };
namespace TTDevice { class ITTCDM; };
namespace TTDevice { class ITTCHK; };
namespace TTDevice { class ITTCIM; };
namespace TTDevice { class ITTDEP; };
namespace TTDevice { class ITTIDC; };
namespace TTDevice { class ITTPIN; };
namespace TTDevice { class ITTPTR; };
namespace TTDevice { class ITTSIU; };
namespace TTDevice { class ITTTTU; };
namespace TTDevice { class ITTVDM; };

//namespace TTDevice { class ITTBCR310; };
namespace TTDevice { class ITTCDM310; };

namespace TTDevice_factory
{
	class CTTDevice_factory
	{
	private:
	protected:
	public:
		CTTDevice_factory() = delete;
		CTTDevice_factory(const CTTDevice_factory&) = delete;
		CTTDevice_factory(CTTDevice_factory&&) = delete;
		CTTDevice_factory& operator = (const CTTDevice_factory&) = delete;
		CTTDevice_factory& operator = (CTTDevice_factory&&) = delete;
		virtual ~CTTDevice_factory() = delete;

		static std::shared_ptr<TTDevice::ITTBCR> CreateTTBCR() noexcept;
		static std::shared_ptr<TTDevice::ITTCAM> CreateTTCAM() noexcept;
		static std::shared_ptr<TTDevice::ITTCAM> CreateTTCAM_N() noexcept;
		static std::shared_ptr<TTDevice::ITTCDM> CreateTTCDM() noexcept;
		static std::shared_ptr<TTDevice::ITTCHK> CreateTTCHK() noexcept;
		static std::shared_ptr<TTDevice::ITTCIM> CreateTTCIM() noexcept;
		static std::shared_ptr<TTDevice::ITTDEP> CreateTTDEP() noexcept;
		static std::shared_ptr<TTDevice::ITTIDC> CreateTTIDC() noexcept;
		static std::shared_ptr<TTDevice::ITTPIN> CreateTTPIN() noexcept;
		static std::shared_ptr<TTDevice::ITTPTR> CreateTTPTR() noexcept;
		static std::shared_ptr<TTDevice::ITTSIU> CreateTTSIU() noexcept;
		static std::shared_ptr<TTDevice::ITTTTU> CreateTTTTU() noexcept;
		static std::shared_ptr<TTDevice::ITTVDM> CreateTTVDM() noexcept;

		//static std::shared_ptr<TTDevice::ITTBCR310> CreateTTBCR310() noexcept;
		static std::shared_ptr<TTDevice::ITTCDM310> CreateTTCDM310() noexcept;
	};
}
#endif // !__H_CTTDEVICE_FACTORY__
