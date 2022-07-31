#pragma once

#ifndef __H_IXFSBCR310__
#define __H_IXFSBCR310__

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace  TTDevice
{
	/*=================================================================*/
	/* BCR310 Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_bcr_status : public XFS310::_wfs_bcr_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_status)
			void WFS2TT(const XFS310::_wfs_bcr_status* obj)
		{
			this->fwDevice							= obj->fwDevice;
			this->fwBCRScanner						= obj->fwBCRScanner;
			CopyMemory(this->dwGuidLights, obj->dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE * 2);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
			this->wDevicePosition					= obj->wDevicePosition;
			this->usPowerSaveRecoveryTime			= obj->usPowerSaveRecoveryTime;
		}
		~_tt_wfs_bcr_status() { }
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_status& obj)
		{
			out << " fwDevice: "					<< obj.fwDevice
				<< " fwBCRScanner: "				<< obj.fwBCRScanner
				<< " dwGuidLights: "				<< TTFRMU::Array2Str<DWORD>(obj.dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE)
				<< " wDevicePosition: "				<< obj.wDevicePosition
				<< " usPowerSaveRecoveryTime: "		<< obj.usPowerSaveRecoveryTime;
			out << std::endl;
			out << " lpszExtra: "					<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSBCRSTATUS, * LPTTWFSBCRSTATUS;

	typedef struct _tt_wfs_bcr_caps : public XFS310::_wfs_bcr_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_caps)
			void WFS2TT(const XFS310::_wfs_bcr_caps* obj)
		{
			this->wClass							= obj->wClass;
			this->bCompound							= obj->bCompound;
			this->bCanFilterSymbologies				= obj->bCanFilterSymbologies;

			LPWORD _pTemp = obj->lpwSymbologies;
			while (_pTemp)
			{
				lpwSymbologies.push_back((WORD)_pTemp);
				_pTemp++;
			}

			CopyMemory(this->dwGuidLights, obj->dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE * 2);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
			this->bPowerSaveControl					= obj->bPowerSaveControl;
		}
		DEFAULTDESTRUCTOR(_tt_wfs_bcr_caps)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_caps& obj)
		{
			out << " wClass: "					<< obj.wClass
				<< " bCompound: "				<< obj.bCompound
				<< " bCanFilterSymbologies: "	<< obj.bCanFilterSymbologies
				<< " lpwSymbologies: ";
			for (const auto& elem : obj.lpwSymbologies)
				out << ' ' << elem;
			out << " dwGuidLights: "			<< TTFRMU::Array2Str<DWORD>(obj.dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE);
			out << std::endl;
			out << " lpszExtra: "				<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			out << std::endl;
			out << " bPowerSaveControl: "		<< obj.bPowerSaveControl;
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
		std::deque<WORD>lpwSymbologies;
	} TTWFSBCRCAPS, * LPTTWFSBCRCAPS;

	/*=================================================================*/
	/* BCR310 Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_bcr_hex_data : public XFS310::_wfs_bcr_hex_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_hex_data)
			void WFS2TT(const XFS310::_wfs_bcr_hex_data* obj)
		{
			this->usLength						= obj->usLength;
			SAFEALLOCCOPYMEMORY(this->lpbData, obj->lpbData, obj->usLength);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_hex_data& obj)
		{
			out << " -usLength: "				<< obj.usLength
				<< " -lpbData: "				<< TTFRMU::ByteArray2Str(obj.lpbData, obj.usLength).c_str();
			return out;
		}
		~_tt_wfs_bcr_hex_data() { SAFERELEASE(this->lpbData) }
	} TTWFSBCRXDATA, * LPTTWFSBCRXDATA;

	typedef struct _tt_wfs_bcr_read_input : public XFS310::_wfs_bcr_read_input
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_read_input)
			void WFS2TT(const XFS310::_wfs_bcr_read_input* obj)
		{
			LPWORD _pTemp = obj->lpwSymbologies;
			while (_pTemp)
			{
				lpwSymbologies.push_back((WORD)_pTemp);
				_pTemp++;
			}
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_read_input& obj)
		{
			out << " lpwSymbologies: ";
			for (auto elem : obj.lpwSymbologies)
				out << ' ' << elem;
			return out;
		}
		std::deque<WORD>lpwSymbologies;
	} TTWFSBCRREADINPUT, * LPTTWFSBCRREADINPUT;

	typedef struct _tt_wfs_bcr_read_output : public XFS310::_wfs_bcr_read_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_read_output)
			void WFS2TT(const XFS310::_wfs_bcr_read_output* obj)
		{
			this->wSymbology = obj->wSymbology;

			if (obj->lpxBarcodeData)
			{
				this->lpxBarcodeData = new TTWFSBCRXDATA;
				this->lpxBarcodeData->WFS2TT(obj->lpxBarcodeData);
			}

			lpszSymbologyName.assign(obj->lpszSymbologyName);
		}
		~_tt_wfs_bcr_read_output() { SAFERELEASE(this->lpxBarcodeData) }
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_read_output& obj)
		{
			out << " wSymbology: " << obj.wSymbology
				<< " lpxBarcodeData: " << std::endl
				<< *obj.lpxBarcodeData << std::endl
				<< " lpszSymbologyName: " << obj.lpszSymbologyName.c_str();
			return out;
		}
		LPTTWFSBCRXDATA		lpxBarcodeData;
		std::string			lpszSymbologyName;
	} TTWFSBCRREADOUTPUT, * LPTTWFSBCRREADOUTPUT;

	typedef struct _tt_wfs_bcr_set_guidlight : public XFS310::_wfs_bcr_set_guidlight
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_set_guidlight)
			void WFS2TT(const XFS310::_wfs_bcr_set_guidlight* obj)
		{
			this->wGuidLight = obj->wGuidLight;
			this->dwCommand = obj->dwCommand;
		}
		friend std::ostream& operator << (std::ostream out, const _tt_wfs_bcr_set_guidlight& obj)
		{
			out << " wGuidLight: " << obj.wGuidLight
				<< " dwCommand: " << obj.dwCommand;
			return out;
		}
	} TTWFSBCRSETGUIDLIGHT, * LPTTWFSBCRSETGUIDLIGHT;

	typedef struct _tt_wfs_bcr_power_save_control : public XFS310::_wfs_bcr_power_save_control
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_power_save_control)
			void WFS2TT(const XFS310::_wfs_bcr_power_save_control* obj)
		{
			this->usMaxPowerSaveRecoveryTime = obj->usMaxPowerSaveRecoveryTime;
		}
		friend std::ostream& operator << (std::ostream out, const _tt_wfs_bcr_power_save_control& obj)
		{
			out << " usMaxPowerSaveRecoveryTime: " << obj.usMaxPowerSaveRecoveryTime;
			return out;
		}
	} TTWFSBCRPOWERSAVECONTROL, * LPTTWFSBCRPOWERSAVECONTROL;

	/*=================================================================*/
	/* BCR310 Interface */
	/*=================================================================*/

	class ITTBCR310 : public ITTDevice
	{

	public:
		ITTBCR310() = default;
		ITTBCR310(const ITTBCR310&) = delete;
		ITTBCR310(ITTBCR310&&) = delete;
		ITTBCR310& operator = (const ITTBCR310) = delete;
		ITTBCR310& operator = (ITTBCR310&&) = delete;
		virtual ~ITTBCR310() = default;

		/* BCR Info Commands */
		virtual HRESULT GetStatus(LPTTWFSBCRSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT GetCapabilities(LPTTWFSBCRCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual HRESULT AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* BCR Execute Commands */
		virtual HRESULT Read(const LPTTWFSBCRREADINPUT, LPTTWFSBCRREADOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT Reset(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT SetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT PowerSaveControl(const LPTTWFSBCRPOWERSAVECONTROL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual HRESULT AsyncRead(const LPTTWFSBCRREADINPUT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT AsyncSetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual HRESULT AsyncPowerSaveControl(const LPTTWFSBCRPOWERSAVECONTROL, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};	
}

#endif // !__H_IXFSBCR310__
