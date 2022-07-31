#pragma once

#ifndef __H_ICPPDEVICE__
#define __H_ICPPDEVICE__

#include <string>
#include <deque>
#include <functional>

namespace __N_CPPDEVICE__
{
	typedef enum class _device_xfs_vesrsion
	{
		NXFS	= 0,
		XFS300	= 1,
		XFS310	= 2,
		XFS320	= 3,
		XFS330	= 4
	} XFSVERSION;

	typedef struct _device_event_data
	{
		unsigned short int	uid;                            // event unique id
		int			        rid;                            // request id
		int			        msg;                            // message id
		int			        res;                            // result
		void*		        buf{ nullptr };                 // pointer to buffer
	} DEVEVENTDATA;

	using DEVEVENTLAMBDA = std::function<void(DEVEVENTDATA&)>;
	using DEVLAMBDADEQUE = std::deque<DEVEVENTLAMBDA>;

    typedef struct _cppdevice_init
    {
        std::string logic_name{};
    } CPPDEVICE_INIT, * LP_CPPDEVICE_INIT;

    class ICPPDevice
    {
    private:
    protected:
    public:
        ICPPDevice() = default;
        ICPPDevice(const ICPPDevice&) = delete;
        ICPPDevice(ICPPDevice&&) = delete;
        ICPPDevice& operator = (const ICPPDevice&) = delete;
        ICPPDevice& operator = (ICPPDevice&&) = delete;
        virtual ~ICPPDevice() = default;

        virtual bool Initialize(const CPPDEVICE_INIT&) noexcept = 0;
        virtual bool UnInitialize() noexcept = 0;
        virtual bool IsInitialize() const noexcept = 0;

		virtual void RegisterCallbackFunction(DEVEVENTLAMBDA) noexcept = 0;

		virtual bool Connect_sync() noexcept = 0;
		virtual bool Connect_async() noexcept = 0;
		virtual bool Disconnect_async() noexcept = 0;
		virtual bool Disconnect_sync() noexcept = 0;

		virtual bool IsConnected() const noexcept = 0;
		virtual bool IsConnecting() const noexcept = 0;

		virtual bool LockDevice(long Timeout) noexcept = 0;
		virtual bool UnLockDevice() noexcept = 0;
		virtual bool CancelLock() noexcept = 0;

		virtual std::string GetDeviceLastError() noexcept = 0;
		virtual std::string GetLogicName() const noexcept = 0;
    };
} // !__N_CPPDEVICE__

#endif // !__H_ICPPDEVICE__