
#include "CTTCAM_N.h"

#include <TTUSBCamera/CODE/ITTUSBCamera.h>
#include <TTLogger/CODE/ITTLogger.h>
#include <TTThreadMngr/CODE/ITTThreadMngr.h>

#include <algorithm>
#include <thread>

namespace TTDevice
{
	std::string GetDevicePathFromConfigFile(const std::string& key) noexcept
	{
		size_t _uiReadCount = 0;
		char _acTemp[256]{ 0 };
		std::string _strDevicePath{};
		_uiReadCount = ::GetPrivateProfileStringA("capture_info", key.c_str(), "UnSet", _acTemp, 256, ".//CONFIG_NOVA//Camera.ini");
		if (0 < _uiReadCount)
			_strDevicePath.assign(_acTemp);
		else
			_strDevicePath.assign("UnSet");

		return _strDevicePath;
	}

	void GetDeviceConfig(USBCAMERADEVICES& USBCameras) noexcept
	{
		USBCameras.clear();

		{
			// FACE
			TTUSBCAMERADEVICE _TTUSBCAMERADEVICE{};
			_TTUSBCAMERADEVICE.position = TTUSBCAMPOS::FACE;
			_TTUSBCAMERADEVICE.strDevicePath.assign(GetDevicePathFromConfigFile("FACE"));
			USBCameras.push_back(_TTUSBCAMERADEVICE);
			DEBUGLOG("GetDeviceConfig - FACE - %s : %s", _TTUSBCAMERADEVICE.strDeviceName.c_str(), _TTUSBCAMERADEVICE.strDevicePath.c_str());
		}

		{
			// ROOM
			TTUSBCAMERADEVICE _TTUSBCAMERADEVICE{};
			_TTUSBCAMERADEVICE.position = TTUSBCAMPOS::ROOM;
			_TTUSBCAMERADEVICE.strDevicePath.assign(GetDevicePathFromConfigFile("ROOM"));
			USBCameras.push_back(_TTUSBCAMERADEVICE);
			DEBUGLOG("GetDeviceConfig - ROOM - %s : %s", _TTUSBCAMERADEVICE.strDeviceName.c_str(), _TTUSBCAMERADEVICE.strDevicePath.c_str());
		}

		{
			// EXIT
			TTUSBCAMERADEVICE _TTUSBCAMERADEVICE{};
			_TTUSBCAMERADEVICE.position = TTUSBCAMPOS::EXIT;
			_TTUSBCAMERADEVICE.strDevicePath.assign(GetDevicePathFromConfigFile("EXIT"));
			USBCameras.push_back(_TTUSBCAMERADEVICE);
			DEBUGLOG("GetDeviceConfig - EXIT - %s : %s", _TTUSBCAMERADEVICE.strDeviceName.c_str(), _TTUSBCAMERADEVICE.strDevicePath.c_str());
		}
	}

	bool GetDeviceStatus(TTUSBCamera::ITTUSBCamera* pTTUSBCamera, USBCAMERADEVICES& USBCameras, TTSTATUS& machineStatus) noexcept
	{
		//TRACELOG("GetDeviceStatus - Started");

		if (!pTTUSBCamera)
		{
			ERRORLOG("GetDeviceStatus - FAILED because pTTUSBCamera is NULL");
			return false;
		}

		USBCAMERADEVICES _USBCAMERADEVICES{};
		GetDeviceConfig(_USBCAMERADEVICES);

		std::deque<TTUSBCamera::TTUSBCAMERA>_deqCameras{};
		if (!pTTUSBCamera->Enumerate(_deqCameras))
		{
			ERRORLOG("GetDeviceStatus - Enumerate FAILED to enumerate devices");
			return false;
		}

		for (const auto& camera : _deqCameras)
		{
			DEBUGLOG("GetDeviceStatus - %s : %s", camera.strDeviceName.c_str(), camera.strDevicePath.c_str());

			auto _it = std::find_if(_USBCAMERADEVICES.begin(), _USBCAMERADEVICES.end(), [camera](const TTUSBCAMERADEVICE& device)
				{ return !device.strDevicePath.compare(camera.strDevicePath); });
			if (_USBCAMERADEVICES.end() == _it)
				continue;

			_it->deviceStatus = STATUS_OK;
		}

		if (_deqCameras.empty())
			machineStatus = STATUS_NOT_OK;
		else
			machineStatus = STATUS_OK;

		/*for (const auto& camera : _USBCAMERADEVICES)
		{
			std::stringstream _stream{};
			_stream << camera;
			DEBUGLOG("GetDeviceStatus - CONFIG: %s", _stream.str().c_str());
		}

		for (const auto& camera : _deqCameras)
		{
			DEBUGLOG("GetDeviceStatus - LIVE: %s", camera.strDevicePath.c_str());
		}*/

		USBCameras.clear();
		USBCameras.assign(_USBCAMERADEVICES.begin(), _USBCAMERADEVICES.end());

		//TRACELOG("GetDeviceStatus - Ended");
		return true;
	}

	bool CTTCAM_N::Initialize(TTObjectPool::ITTObjectPool* pObjectPool) noexcept
	{
		TRACELOG("CTTCAM_N::Initialize - Started");

		if (!ITTComponent::Initialize(pObjectPool))
		{
			ERRORLOG("CTTCAM_N::Initialize - ITTComponent::Initialize FAILED to initialize");
			return false;
		}

		this->m_pTTUSBCamera = TTUSBCamera::CreateTTUSBCamera();
		if (!this->m_pTTUSBCamera->Initialize())
		{
			ERRORLOG("CTTCAM_N::Initialize - Initialize FAILED to initialize TTUSBCamera");
			return false;
		}

		this->m_pTTThreadMngr = TTThreadMngr::CreateTTThreadMngr();

		if (!this->m_pTTThreadMngr->Initialize())
		{
			ERRORLOG("CTTCAM_N::ConnectAsync - Initialize FAILED initialize TTThreadMngr");
			return false;
		}

		TRACELOG("CTTCAM_N::Initialize - Ended");
		return true;
	}

	bool CTTCAM_N::UnInitialize() noexcept
	{
		TRACELOG("CTTCAM_N::UnInitialize - Started");

		this->m_pTTUSBCamera->UnInitialize();
		TTUSBCamera::DestroyTTUSBCamera(&this->m_pTTUSBCamera);

		m_pTTThreadMngr->UnInitialize();
		TTThreadMngr::DestroyTTThreadMngr(&this->m_pTTThreadMngr);

		if (!ITTComponent::UnInitialize())
		{
			ERRORLOG("CTTCAM_N::UnInitialize - ITTComponent::UnInitialize FAILED to uninitialize");
			return false;
		}

		TRACELOG("CTTCAM_N::UnInitialize - Ended");
		return true;
	}

	bool CTTCAM_N::ConnectAsync() noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL
		TRACELOG("CTTCAM_N::ConnectAsync - Started");
		TRACELOG("CTTCAM_N::ConnectAsync - Ended");
		return false;
	}

	bool CTTCAM_N::DisconnectAsync() noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		TRACELOG("CTTCAM_N::DisconnectAsync - Started");
		this->m_bConnected = false;
		TRACELOG("CTTCAM_N::DisconnectAsync - Ended");
		return false;
	}

	bool CTTCAM_N::ConnectSync() noexcept
	{
		TRACELOG("CTTCAM_N::ConnectSync - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL

		if (!GetDeviceStatus(this->m_pTTUSBCamera, this->m_deqUSBCameras, this->m_machineStatus))
		{
			ERRORLOG("CTTCAM_N::ConnectAsync - GetDeviceStatus FAILED to update status");
			return false;
		}

		TTThreadMngr::TTTHREADLAMBDA _lambda = [this]()
		{
			USBCAMERADEVICES _deqUSBCameras{};

			TTSTATUS _machineStatus = STATUS_NOT_OK;
			if (!GetDeviceStatus(this->m_pTTUSBCamera, _deqUSBCameras, _machineStatus))
			{
				ERRORLOG("CTTCAM_N::ConnectAsync - lambda - GetDeviceStatus FAILED to update status");
				return true;
			}

			for (const auto& camera : _deqUSBCameras)
			{
				//TTUSBCamera::LPTTUSBCAMERAFRAME _lpTTUSBCAMERAFRAME = nullptr;
				//this->m_pTTUSBCamera->GrabFrame(camera.strDevicePath, &_lpTTUSBCAMERAFRAME);
			}

			//DEBUGLOG("CTTCAM_N::Initialize - lambda - m_machineStatus: %d, _machineStatus: %d", this->m_machineStatus, _machineStatus);

			if (_machineStatus != this->m_machineStatus)
			{
				//DEBUGLOG("CTTCAM_N::Initialize - lambda - EVENT");
				NOVAGLOBALS::DEVEVENTDATA _DEVEVENTDATA{};
				_DEVEVENTDATA.iRequestID = 0;
				_DEVEVENTDATA.iMessage = WFS_SYSE_DEVICE_STATUS;
				_DEVEVENTDATA.iResult = 0;

				_DEVEVENTDATA.lpBuffer = new DWORD;
				*(LPDWORD)_DEVEVENTDATA.lpBuffer = _machineStatus == STATUS_OK ? WFS_STAT_DEVONLINE : WFS_STAT_DEVNODEVICE;
				this->InformRegisteredComponents(_DEVEVENTDATA);

				this->m_machineStatus = _machineStatus;
			}

			this->m_deqUSBCameras.clear();
			this->m_deqUSBCameras.assign(_deqUSBCameras.begin(), _deqUSBCameras.end());

			return true;
		};

		this->m_iThreadIndex = this->m_pTTThreadMngr->CreateThread(std::chrono::milliseconds(0));
		if (-1 == this->m_iThreadIndex)
		{
			ERRORLOG("CTTCAM_N::ConnectAsync - CreateThread FAILED to create thread");
			return false;
		}

		this->m_iLmbdaIndex = this->m_pTTThreadMngr->RegisterCallbackFunction(this->m_iThreadIndex, _lambda, std::chrono::milliseconds(500));
		if (-1 == this->m_iLmbdaIndex)
		{
			ERRORLOG("CTTCAM_N::ConnectAsync - RegisterCallbackFunction FAILED to create thread");
			return false;
		}

		if (!this->m_pTTThreadMngr->AsyncStartThread(this->m_iThreadIndex))
		{
			ERRORLOG("CTTCAM_N::ConnectAsync - AsyncStartThread FAILED to start thread");
			return false;
		}

		this->m_bConnected = true;

		TRACELOG("CTTCAM_N::ConnectSync - Ended");
		return true;
	}

	bool CTTCAM_N::DisconnectSync() noexcept
	{
		TRACELOG("CTTCAM_N::DisconnectSync - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		this->m_pTTThreadMngr->StopThread(this->m_iThreadIndex);
		::Sleep(1000);
		this->m_pTTThreadMngr->DeRegisterCallBackFunction(this->m_iThreadIndex, this->m_iLmbdaIndex);
		this->m_pTTThreadMngr->DestroyThread(this->m_iThreadIndex);

		this->m_bConnected = false;

		TRACELOG("CTTCAM_N::DisconnectSync - Ended");
		return true;
	}

	bool CTTCAM_N::GetStatus(LPTTWFSCAMSTATUS lpTTWFSCAMSTATUS, const DWORD Timeout) noexcept
	{
		TRACELOG("CTTCAM_N::GetStatus - Started");

		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL

		TT_DEV_ASSERTSAFEPTR_BOOL("CTTCAM_N::GetStatus - FAILED because lpTTWFSCAMSTATUS is NULL", lpTTWFSCAMSTATUS)

		lpTTWFSCAMSTATUS->fwDevice = this->m_machineStatus == STATUS_OK ? WFS_STAT_DEVONLINE : WFS_STAT_DEVNODEVICE;

		{
			// FACE
			auto _it = std::find_if(this->m_deqUSBCameras.begin(), this->m_deqUSBCameras.end(), [](const TTUSBCAMERADEVICE& device) { return device.position == FACE; });
			if (_it == this->m_deqUSBCameras.end())
			{
				this->SetDeviceLastError(WFS_ERR_HARDWARE_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_HARDWARE_ERROR));
				return false;
			}

			lpTTWFSCAMSTATUS->fwMedia[WFS_CAM_PERSON] = _it->deviceStatus == STATUS_OK ? WFS_CAM_MEDIAOK : WFS_CAM_MEDIAUNKNOWN;
			lpTTWFSCAMSTATUS->fwCameras[WFS_CAM_PERSON] = _it->deviceStatus == STATUS_OK ? WFS_CAM_CAMOK : WFS_CAM_CAMUNKNOWN;
		}
		{
			// ROOM
			auto _it = std::find_if(this->m_deqUSBCameras.begin(), this->m_deqUSBCameras.end(), [](const TTUSBCAMERADEVICE& device) { return device.position == ROOM; });
			if (_it == this->m_deqUSBCameras.end())
			{
				this->SetDeviceLastError(WFS_ERR_HARDWARE_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_HARDWARE_ERROR));
				return false;
			}

			lpTTWFSCAMSTATUS->fwMedia[WFS_CAM_ROOM] = _it->deviceStatus == STATUS_OK ? WFS_CAM_MEDIAOK : WFS_CAM_MEDIAUNKNOWN;
			lpTTWFSCAMSTATUS->fwCameras[WFS_CAM_ROOM] = _it->deviceStatus == STATUS_OK ? WFS_CAM_CAMOK : WFS_CAM_CAMUNKNOWN;
		}
		{
			// EXIT
			auto _it = std::find_if(this->m_deqUSBCameras.begin(), this->m_deqUSBCameras.end(), [](const TTUSBCAMERADEVICE& device) { return device.position == EXIT; });
			if (_it == this->m_deqUSBCameras.end())
			{
				this->SetDeviceLastError(WFS_ERR_HARDWARE_ERROR, NOVADESCRIBE_XFS_ERROR(WFS_ERR_HARDWARE_ERROR));
				return false;
			}

			lpTTWFSCAMSTATUS->fwMedia[WFS_CAM_EXITSLOT] = _it->deviceStatus == STATUS_OK ? WFS_CAM_MEDIAOK : WFS_CAM_MEDIAUNKNOWN;
			lpTTWFSCAMSTATUS->fwCameras[WFS_CAM_EXITSLOT] = _it->deviceStatus == STATUS_OK ? WFS_CAM_CAMOK : WFS_CAM_CAMUNKNOWN;
		}

		TRACELOG("CTTCAM_N::GetStatus - Ended");
		return true;
	}

	bool CTTCAM_N::GetCapabilities(LPTTWFSCAMCAPS lpOut, const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}

	bool CTTCAM_N::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}

	bool CTTCAM_N::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}

	bool CTTCAM_N::TakePicture(const LPTTWFSCAMTAKEPICT lpTakePict, const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}

	bool CTTCAM_N::Reset(const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}

	bool CTTCAM_N::AsyncTakePicture(const LPTTWFSCAMTAKEPICT lpTakePict, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}

	bool CTTCAM_N::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		TT_DEV_ASSERTINITIALIZE_BOOL TT_DEV_ASSERTCONNECT_BOOL
		return true;
	}
}