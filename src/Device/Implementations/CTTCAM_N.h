#pragma once

#ifndef __H_CTTUSBCAMERACONTROLLER__
#define __H_CTTUSBCAMERACONTROLLER__

#include "../Interfaces/ITTCAM.h"

namespace TTUSBCamera { class ITTUSBCamera; }
namespace TTThreadMngr { class ITTThreadMngr; }

namespace TTDevice
{
	typedef enum _tt_usb_camera_position
	{
		NSET = 0,
		FACE = 1,
		ROOM = 2,
		EXIT = 3,
	} TTUSBCAMPOS;

	typedef enum _tt_usb_camera_status
	{
		STATUS_OK = 0,
		STATUS_NOT_OK = 1
	} TTSTATUS;

	typedef struct _tt_usb_camera_device
	{
		TTUSBCAMPOS position = NSET;
		TTSTATUS deviceStatus = STATUS_NOT_OK;
		std::string strDeviceName{};
		std::string strDevicePath{};
		friend std::ostream& operator << (std::ostream& out, const _tt_usb_camera_device& obj)
		{
			out << " position: " << obj.position
				<< " status: " << obj.deviceStatus
				<< " strDeviceName: " << obj.strDeviceName
				<< " strDevicePath: " << obj.strDevicePath;
			return out;
		}
	} TTUSBCAMERADEVICE, * LPTTUSBCAMERADEVICE;

	using USBCAMERADEVICES = std::deque<TTUSBCAMERADEVICE>;

	class CTTCAM_N : public ITTCAM
	{
	private:
		TTSTATUS m_machineStatus = STATUS_NOT_OK;
		USBCAMERADEVICES m_deqUSBCameras{};
		int m_iThreadIndex = -1;
		int m_iLmbdaIndex = -1;
		TTUSBCamera::ITTUSBCamera* m_pTTUSBCamera = nullptr;
		TTThreadMngr::ITTThreadMngr* m_pTTThreadMngr = nullptr;

	protected:
	public:
		CTTCAM_N() = default;
		CTTCAM_N(const CTTCAM_N&) = delete;
		CTTCAM_N(CTTCAM_N&&) = delete;
		CTTCAM_N& operator = (const CTTCAM_N&) = delete;
		CTTCAM_N& operator = (CTTCAM_N&&) = delete;
		virtual ~CTTCAM_N() = default;

		bool Initialize(TTObjectPool::ITTObjectPool*) noexcept final;
		bool UnInitialize() noexcept final;

		bool ConnectAsync() noexcept final;
		bool DisconnectAsync() noexcept final;
		bool ConnectSync() noexcept final;
		bool DisconnectSync() noexcept final;

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

#endif // !__H_CTTUSBCAMERACONTROLLER__
