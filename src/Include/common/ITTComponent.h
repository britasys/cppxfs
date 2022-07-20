#pragma once

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <memory>
#include <string>
#include <mutex>

namespace TTObjectPool { class ITTObjectPool; }

namespace TTFRM
{
	class ITTComponent
	{
	private:
	protected:
		bool			m_bInitialized{ false };
		std::string		m_strDescription{};

		std::mutex		m_mutex{};

		TTObjectPool::ITTObjectPool* m_pObjectPool{};

	public:
		ITTComponent() = default;
		ITTComponent(const ITTComponent&) = delete;
		ITTComponent(ITTComponent&&) = default;
		ITTComponent& operator = (const ITTComponent) = delete;
		ITTComponent& operator = (ITTComponent&&) = delete;
		virtual ~ITTComponent() = default;

		virtual bool Initialize(TTObjectPool::ITTObjectPool* pObjectPool) noexcept
		{
			if (this->m_bInitialized)
				return false;

			if (!pObjectPool)
				return false;

			this->m_pObjectPool = pObjectPool;

			this->m_bInitialized = true;

			return true;
		}
		virtual bool UnInitialize() noexcept
		{
			if (!this->m_bInitialized)
				return false;

			this->m_pObjectPool = nullptr;

			this->m_bInitialized = false;

			return true;
		}

		bool IsInitialized() const noexcept
		{
			return this->m_bInitialized;
		}

		void SetDescription(std::string str) noexcept
		{
			this->m_strDescription.assign(str);
		}

		std::string GetDescription() const noexcept
		{
			return this->m_strDescription;
		}
	};
}

#endif //!ICOMPONENT_H			