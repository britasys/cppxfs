
#include "CTTDevice_factory.h"

#include "Implementations/CTTBCR.h"
#include "Implementations/CTTCAM.h"
#include "Implementations/CTTCDM.h"
#include "Implementations/CTTCHK.h"
#include "Implementations/CTTCIM.h"
#include "Implementations/CTTDEP.h"
#include "Implementations/CTTIDC.h"
#include "Implementations/CTTPIN.h"
#include "Implementations/CTTPTR.h"
#include "Implementations/CTTSIU.h"
#include "Implementations/CTTTTU.h"
#include "Implementations/CTTVDM.h"

//#include "Implementations/CTTBCR310.h"
#include "Implementations/CTTCDM310.h"

#include "Implementations/CTTCAM_N.h"

namespace TTDevice_factory
{
	std::shared_ptr<TTDevice::ITTBCR> CTTDevice_factory::CreateTTBCR() noexcept
	{
		return std::make_shared<TTDevice::CTTBCR>();
	}
	std::shared_ptr<TTDevice::ITTCAM> CTTDevice_factory::CreateTTCAM() noexcept
	{
		return std::make_shared<TTDevice::CTTCAM>();
	}
	std::shared_ptr<TTDevice::ITTCAM> CTTDevice_factory::CreateTTCAM_N() noexcept
	{
		return std::make_shared<TTDevice::CTTCAM_N>();
	}
	std::shared_ptr<TTDevice::ITTCDM> CTTDevice_factory::CreateTTCDM() noexcept
	{
		return std::make_shared<TTDevice::CTTCDM>();
	}
	std::shared_ptr<TTDevice::ITTCHK> CTTDevice_factory::CreateTTCHK() noexcept
	{
		return std::make_shared<TTDevice::CTTCHK>();
	}
	std::shared_ptr<TTDevice::ITTCIM> CTTDevice_factory::CreateTTCIM() noexcept
	{
		return std::make_shared<TTDevice::CTTCIM>();
	}
	std::shared_ptr<TTDevice::ITTDEP> CTTDevice_factory::CreateTTDEP() noexcept
	{
		return std::make_shared<TTDevice::CTTDEP>();
	}
	std::shared_ptr<TTDevice::ITTIDC> CTTDevice_factory::CreateTTIDC() noexcept
	{
		return std::make_shared<TTDevice::CTTIDC>();
	}
	std::shared_ptr<TTDevice::ITTPIN> CTTDevice_factory::CreateTTPIN() noexcept
	{
		return std::make_shared<TTDevice::CTTPIN>();
	}
	std::shared_ptr<TTDevice::ITTPTR> CTTDevice_factory::CreateTTPTR() noexcept
	{
		return std::make_shared<TTDevice::CTTPTR>();
	}
	std::shared_ptr<TTDevice::ITTSIU> CTTDevice_factory::CreateTTSIU() noexcept
	{
		return std::make_shared<TTDevice::CTTSIU>();
	}
	std::shared_ptr<TTDevice::ITTTTU> CTTDevice_factory::CreateTTTTU() noexcept
	{
		return std::make_shared<TTDevice::CTTTTU>();
	}
	std::shared_ptr<TTDevice::ITTVDM> CTTDevice_factory::CreateTTVDM() noexcept
	{
		return std::make_shared<TTDevice::CTTVDM>();
	}
	/*std::shared_ptr<TTDevice::ITTBCR310> CTTDevice_factory::CreateTTBCR310() noexcept
	{
		return std::make_shared<TTDevice::CTTBCR310>();
	}*/
	std::shared_ptr<TTDevice::ITTCDM310> CTTDevice_factory::CreateTTCDM310() noexcept
	{
		return std::make_shared<TTDevice::CTTCDM310>();
	}
}