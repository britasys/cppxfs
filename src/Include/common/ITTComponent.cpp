
#include "ITTComponent.h"

namespace TTFRM
{
	bool ITTComponent::Initialize(TTObjectPool::ITTObjectPool* pObjectPool) noexcept
	{
		if (this->m_bInitialized)
			return false;

		if (!pObjectPool)
			return false;

		this->m_pObjectPool = pObjectPool;

		this->m_bInitialized = true;

		return true;
	}

	bool ITTComponent::UnInitialize() noexcept
	{
		if (!this->m_bInitialized)
			return false;

		this->m_pObjectPool = nullptr;

		this->m_bInitialized = false;

		return true;
	}

	bool ITTComponent::IsInitialized() const noexcept
	{
		return this->m_bInitialized;
	}

	void ITTComponent::SetDescription(std::string str) noexcept
	{
		this->m_strDescription.assign(str);
	}

	std::string ITTComponent::GetDescription() const noexcept
	{
		return this->m_strDescription;
	}
}