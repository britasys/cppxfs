#pragma once

#ifndef __H_IXFSDEVICE__
#define __H_IXFSDEVICE__

#include <string>
#include <functional>

namespace __N_XFSDEVICE__
{
    using XFSTIMEOUT = unsigned long int;
    using XFSDEVICE_UNSOLICITED_LAMBDA = std::function<void()>;
    using XFSDEVICE_SOLICITED_LAMBDA = std::function<void()>;

    typedef struct _xfsdevice_init
    {
        std::string logic_name{};
        XFSDEVICE_UNSOLICITED_LAMBDA lambda{};
    } XFSDEVICE_INIT, * LP_XFSDEVICE_INIT;

    typedef enum class _xfsdevice_state
    {
        UNKNOWN, NOTINITIALIZED, INITIALIZED, CONNECTING, CONNECTED
    } XFSDEVICE_STATE;

    class IXFSDevice
    {
    private:
    protected:
        XFSDEVICE_STATE m_state{ XFSDEVICE_STATE::UNKNOWN };
        XFSDEVICE_INIT m_init{};
        std::string m_strLastError{};

    public:
        IXFSDevice() = default;
        IXFSDevice(const IXFSDevice&) = delete;
        IXFSDevice(IXFSDevice&&) = delete;
        IXFSDevice& operator = (const IXFSDevice&) = delete;
        IXFSDevice& operator = (IXFSDevice&&) = delete;
        virtual ~IXFSDevice() = default;

        virtual bool Initialize(const XFSDEVICE_INIT&) noexcept = 0;
        virtual bool UnInitialize() noexcept = 0;

		virtual bool connect_sync() noexcept = 0;
		virtual bool connect_async() noexcept = 0;
		virtual bool disconnect_sync() noexcept = 0;
		virtual bool disconnect_async() noexcept = 0;

		XFSDEVICE_STATE GetState() const noexcept { return this->m_state; }
		std::string GetLogicName() const noexcept { return this->m_init.logic_name; }
		std::string GetLastError() const noexcept { return this->m_strLastError; }
    };
} // !__N_XFSDEVICE__

#endif // !__H_IXFSDEVICE__