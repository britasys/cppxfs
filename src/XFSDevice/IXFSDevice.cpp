#include <IXFSDevice.hpp>

namespace __N_XFSDEVICE__
{
    bool IXFSDevice::Initialize(const XFSDEVICE_INIT& init) noexcept
    {
        if (STATE::INITIALIZED < this->m_state)
            return false;
        
        this->m_init = init;
        this->m_state = STATE::INITIALIZED;
        
        return true;
    }

    bool IXFSDevice::UnInitialize() noexcept
    {
        if (STATE::INITIALIZED >= this->m_state)
            return false;

        if (STATE::CONNECTED == this->m_state)
            this->disconnect_sync(0);

        this->m_state = STATE::NOTINITIALIZED;

        return true;
    }    

	STATE IXFSDevice::GetState() const noexcept
    {
        return this->m_state;
    }

    std::string IXFSDevice::GetLogicName() const noexcept
    {
        return this->m_init.logic_name;
    }

    WFSERROR IXFSDevice::GetLastError() noexcept
    {
        return this->m_error;
    }
}