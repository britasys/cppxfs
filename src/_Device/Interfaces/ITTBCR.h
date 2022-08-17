#pragma once

#ifndef __H_ITTBCR__
#define __H_ITTBCR__

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace  TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* BCR Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_bcr_status : public XFS300::_wfs_bcr_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_status)
		DEFAULTDESTRUCTOR(_tt_wfs_bcr_status)
		void WFS2TT(const XFS300::_wfs_bcr_status* obj)
		{
			this->fwDevice					= obj->fwDevice;
			this->fwBCRScanner				= obj->fwBCRScanner;
			CopyMemory(this->dwGuidLights, obj->dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE * sizeof(DWORD));
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_status& obj)
		{
			out << " fwDevice: "			<< obj.fwDevice
				<< " fwBCRScanner: "		<< obj.fwBCRScanner
				<< " dwGuidLights: "		<< TTFRMU::Array2Str(obj.dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE);
			out << std::endl;
			out << " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSBCRSTATUS, * LPTTWFSBCRSTATUS;

	typedef struct _tt_wfs_bcr_caps : public XFS300::_wfs_bcr_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_caps)
		~_tt_wfs_bcr_caps() { SAFEFREEMEMORY(&this->lpwBarCodeList) }
		void WFS2TT(const XFS300::_wfs_bcr_caps* obj)
		{
			this->wClass					= obj->wClass;
			this->bCompound					= obj->bCompound;
			this->bFormatDiscrimine			= obj->bFormatDiscrimine;
			SAFEALLOCCOPYMEMORY(&this->lpwBarCodeList, obj->lpwBarCodeList, sizeof(WORD));
			CopyMemory(this->dwGuidLights, obj->dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE * sizeof(DWORD));
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_caps& obj)
		{
			out << " wClass: "				<< obj.wClass
				<< " bCompound: "			<< obj.bCompound
				<< " bFormatDiscrimine: "	<< obj.bFormatDiscrimine
				<< " lpwBarCodeList: "		<< obj.lpwBarCodeList
				<< " dwGuidLights: "		<< TTFRMU::Array2Str(obj.dwGuidLights, WFS_BCR_GUIDLIGHTS_SIZE).c_str();
			out << std::endl;
			out << " lpszExtra: "			<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}

		DeviceUtility::STRVECT lpszExtra;
	} TTWFSBCRCAPS, * LPTTWFSBCRCAPS;

	/*=================================================================*/
	/* BCR Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_bcr_read_input : public XFS300::_wfs_bcr_read_input
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_read_input)
			~_tt_wfs_bcr_read_input()
		{
			SAFEFREEMEMORY(&this->lpwCodeList);
			SAFEPTR(this->lpWFSBCRREADINPUT)
			{
				SAFEFREEMEMORY(&this->lpWFSBCRREADINPUT->lpwCodeList);
				SAFERELEASE(&this->lpWFSBCRREADINPUT);
			}
		}
		void WFS2TT(const XFS300::_wfs_bcr_read_input* obj)
		{
			SAFEALLOCCOPYMEMORY(&this->lpwCodeList, obj->lpwCodeList, sizeof(WORD));
		}
		void WFS(XFS300::LPWFSBCRREADINPUT* lppWFSBCRREADINPUT)
		{
			this->lpWFSBCRREADINPUT = new XFS300::WFSBCRREADINPUT;
			SAFEPTR(this->lpwCodeList) SAFEALLOCCOPYMEMORY(&this->lpWFSBCRREADINPUT->lpwCodeList, this->lpwCodeList, sizeof(WORD));
			*lppWFSBCRREADINPUT = this->lpWFSBCRREADINPUT;
		}
		friend std::ostream& operator		<< (std::ostream& out, const _tt_wfs_bcr_read_input& obj)
		{
			out << " lpwCodeList: "			<< *obj.lpwCodeList;
			return out;
		}
		XFS300::LPWFSBCRREADINPUT lpWFSBCRREADINPUT = nullptr;
	} TTWFSBCRREADINPUT, * LPTTWFSBCRREADINPUT;

	typedef struct _tt_wfs_bcr_read_OUTPUT : public XFS300::_wfs_bcr_read_OUTPUT
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_read_OUTPUT)
		~_tt_wfs_bcr_read_OUTPUT() { SAFEFREEMEMORY(&this->lpszCodeData) }
		void WFS2TT(const XFS300::_wfs_bcr_read_OUTPUT* obj)
		{
			WORD wCodeFormat;
			SAFEALLOCCOPYMEMORY(&this->lpszCodeData, obj->lpszCodeData, DeviceUtility::Size_LPWSTR(obj->lpszCodeData));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_read_OUTPUT& obj)
		{
			out << " wCodeFormat: "			<< obj.wCodeFormat;
			//<< " lpszCodeData: "			<< ; /////////////////////////////////////////////////////////////////////
			return out;
		}
	} TTWFSBCRREADOUTPUT, * LPTTWFSBCRREADOUTPUT;

	typedef struct _tt_wfs_bcr_set_guidlight : public XFS300::_wfs_bcr_set_guidlight
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_bcr_set_guidlight)
		~_tt_wfs_bcr_set_guidlight() { SAFERELEASE(&this->lpWFSBCRSETGUIDLIGHT) }
		void WFS2TT(const XFS300::_wfs_bcr_set_guidlight* obj)
		{
			this->wGuidLight				= obj->wGuidLight;
			this->dwCommand					= obj->dwCommand;
		}
		void WFS(XFS300::LPWFSBCRSETGUIDLIGHT* lppWFSBCRSETGUIDLIGHT)
		{
			this->lpWFSBCRSETGUIDLIGHT = new XFS300::WFSBCRSETGUIDLIGHT;
			this->lpWFSBCRSETGUIDLIGHT->wGuidLight = this->wGuidLight;
			this->lpWFSBCRSETGUIDLIGHT->dwCommand = this->dwCommand;
			*lppWFSBCRSETGUIDLIGHT = this->lpWFSBCRSETGUIDLIGHT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_bcr_set_guidlight& obj)
		{
			out << " wGuidLight: "			<< obj.wGuidLight
				<< " dwCommand: "			<< obj.dwCommand;
			return out;
		}
		XFS300::LPWFSBCRSETGUIDLIGHT lpWFSBCRSETGUIDLIGHT = nullptr;
	} TTWFSBCRSETGUIDLIGHT, * LPTTWFSBCRSETGUIDLIGHT;

#pragma pack(pop)

	/*=================================================================*/
	/* BCR Interface */
	/*=================================================================*/

	class ITTBCR : public ITTDevice
	{
	public:
		ITTBCR() = default;
		ITTBCR(const ITTBCR&) = delete;
		ITTBCR(ITTBCR&&) = delete;
		ITTBCR& operator = (const ITTBCR&) = delete;
		ITTBCR& operator = (ITTBCR&&) = delete;
		virtual ~ITTBCR() = default;
		
		/* BCR Info Commands */
		virtual bool GetStatus(LPTTWFSBCRSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSBCRCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* BCR Execute Commands */
		virtual bool Read(const LPTTWFSBCRREADINPUT, LPTTWFSBCRREADOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncRead(const LPTTWFSBCRREADINPUT, REQUESTID& ReqID, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetGuidanceLight(const LPTTWFSBCRSETGUIDLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};	
}

#endif // !__H_ITTBCR__