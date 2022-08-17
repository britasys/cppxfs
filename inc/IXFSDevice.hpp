#pragma once

#ifndef __H_IXFSDEVICE__
#define __H_IXFSDEVICE__

#include <XFSAPI_W/IXFSAPI_W.hpp>
#include <design/IObserver.hpp>

#include <string>
#include <functional>

namespace __N_XFSDEVICE__
{
    using LPDATA = void*;
    using COMMAND = unsigned short int;
    using TIMEOUT = unsigned long int;
    using LAMBDA = std::function<void(const WFSRESULT_W&)>;

    typedef struct _xfsdevice_init
    {
        std::string logic_name{};
        LAMBDA lambda{};
    } INIT, * LP_INIT;

    typedef enum class _xfsdevice_state
    {
        UNKNOWN         = 0,
        NOTINITIALIZED  = 1,
        INITIALIZED     = 2,
        CONNECTING      = 3,
        CONNECTED       = 4,
        DISCONNECTED    = 5
    } STATE;

    class IXFSDevice : public __N_OBSERVER__::ISubscriber<WFSRESULT_W>
    {
    private:
        STATE m_state{ STATE::UNKNOWN };
        INIT m_init{};
        
		void SetLastError(const HRESULT hr, const std::string str) noexcept { this->m_error = std::make_pair(hr, str); }
        
    protected:
    public:
        IXFSDevice() = default;
        IXFSDevice(const IXFSDevice&) = delete;
        IXFSDevice(IXFSDevice&&) = delete;
        IXFSDevice& operator = (const IXFSDevice&) = delete;
        IXFSDevice& operator = (IXFSDevice&&) = delete;
        virtual ~IXFSDevice() = default;

        bool Initialize(const INIT&) noexcept;
        bool UnInitialize() noexcept;

		virtual HRESULT connect_sync(const TIMEOUT) noexcept = 0;
		virtual HRESULT connect_async(LAMBDA, const TIMEOUT) noexcept = 0;
		virtual HRESULT disconnect_sync(const TIMEOUT) noexcept = 0;
		virtual HRESULT disconnect_async(LAMBDA, const TIMEOUT) noexcept = 0;
        virtual HRESULT get_inf_sync(const COMMAND, const LPDATA, WFSRESULT_W&, const TIMEOUT) const noexcept = 0;
        virtual HRESULT get_inf_async(const COMMAND, const LPDATA, LAMBDA, const TIMEOUT) const noexcept = 0;
        virtual HRESULT execute_sync(const COMMAND, const LPDATA, WFSRESULT_W&, const TIMEOUT) const noexcept = 0;
        virtual HRESULT execute_async(const COMMAND, const LPDATA, LAMBDA, const TIMEOUT) const noexcept = 0;

		STATE GetState() const noexcept;
		std::string GetLogicName() const noexcept;
    };
} // !__N_XFSDEVICE__

#endif // !__H_IXFSDEVICE__