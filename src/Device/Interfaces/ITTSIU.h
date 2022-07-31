#pragma once

#ifndef __H_ITTSIU_H
#define __H_ITTSIU_H

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

	#pragma pack(push, 1)

	/*=================================================================*/
	/* SIU Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_siu_status : public XFS300::_wfs_siu_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_status)
		DEFAULTDESTRUCTOR(_tt_wfs_siu_status)
		void WFS2TT(const XFS300::_wfs_siu_status* obj)
		{
			DEBUGLOG("_tt_wfs_siu_status - Started");
			this->fwDevice								= obj->fwDevice;
			SAFECOPYMEMORY(this->fwSensors, obj->fwSensors, WFS_SIU_SENSORS_SIZE * sizeof(WORD));	
			SAFECOPYMEMORY(this->fwDoors, obj->fwDoors, WFS_SIU_DOORS_SIZE * sizeof(WORD));	
			SAFECOPYMEMORY(this->fwIndicators, obj->fwIndicators, WFS_SIU_INDICATORS_SIZE * sizeof(WORD));	
			SAFECOPYMEMORY(this->fwAuxiliaries, obj->fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwGuidLights, obj->fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE * sizeof(WORD));
			//DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_status& obj)
		{
			DEBUGLOG("_tt_wfs_siu_status - operator - Started");
			out << " fwDevice: "						<< obj.fwDevice
				<< " fwSensors: "						<< TTFRMU::Array2Str(obj.fwSensors, WFS_SIU_SENSORS_SIZE)
				<< " fwDoors: "							<< TTFRMU::Array2Str(obj.fwDoors, WFS_SIU_DOORS_SIZE)
				<< " fwIndicators: "					<< TTFRMU::Array2Str(obj.fwIndicators, WFS_SIU_INDICATORS_SIZE)
				<< " fwAuxiliaries: "					<< TTFRMU::Array2Str(obj.fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE)
				<< " fwGuidLights: "					<< TTFRMU::Array2Str(obj.fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE);
				//<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSSIUSTATUS, * LPTTWFSSIUSTATUS;

	typedef struct _tt_wfs_siu_caps : public XFS300::_wfs_siu_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_siu_caps)
		void WFS2TT(const XFS300::_wfs_siu_caps* obj)
		{
			this->wClass								= obj->wClass;
			this->fwType								= obj->fwType;
			SAFECOPYMEMORY(this->fwSensors, obj->fwSensors, WFS_SIU_SENSORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwDoors, obj->fwDoors, WFS_SIU_DOORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwIndicators, obj->fwIndicators, WFS_SIU_INDICATORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwAuxiliaries, obj->fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwGuidLights, obj->fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE * sizeof(WORD));
			//DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_caps& obj)
		{
			out << " wClass: "							<< obj.wClass
				<< " fwType: "							<< obj.fwType
				<< " fwSensors: "						<< TTFRMU::Array2Str(obj.fwSensors, WFS_SIU_SENSORS_SIZE)
				<< " fwDoors: "							<< TTFRMU::Array2Str(obj.fwDoors, WFS_SIU_DOORS_SIZE)
				<< " fwIndicators: "					<< TTFRMU::Array2Str(obj.fwIndicators, WFS_SIU_INDICATORS_SIZE)
				<< " fwAuxiliaries: "					<< TTFRMU::Array2Str(obj.fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE)
				<< " fwGuidLights: "					<< TTFRMU::Array2Str(obj.fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE);
				//<< " lpszExtra: "		<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSSIUCAPS, * LPTTWFSSIUCAPS;

	/*=================================================================*/
	/* SIU Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_siu_enable : public XFS300::_wfs_siu_enable
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_enable)
		~_tt_wfs_siu_enable() { SAFERELEASE(&this->lpWFSSIUENABLE) }
		void WFS2TT(const XFS300::_wfs_siu_enable* obj)
		{
			SAFECOPYMEMORY(this->fwSensors, obj->fwSensors, WFS_SIU_SENSORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwDoors, obj->fwDoors, WFS_SIU_DOORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwIndicators, obj->fwIndicators, WFS_SIU_INDICATORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwAuxiliaries, obj->fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwGuidLights, obj->fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE * sizeof(WORD));
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		void WFS(XFS300::LPWFSSIUENABLE* lppWFSSIUENABLE)
		{
			this->lpWFSSIUENABLE = new XFS300::WFSSIUENABLE;
			SAFECOPYMEMORY(this->lpWFSSIUENABLE->fwSensors, this->fwSensors, WFS_SIU_SENSORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUENABLE->fwDoors, this->fwDoors, WFS_SIU_DOORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUENABLE->fwIndicators, this->fwIndicators, WFS_SIU_INDICATORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUENABLE->fwAuxiliaries, this->fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUENABLE->fwGuidLights, this->fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE * sizeof(WORD));
			this->lpWFSSIUENABLE->lpszExtra = nullptr;
			*lppWFSSIUENABLE = this->lpWFSSIUENABLE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_enable& obj)
		{
			out << " fwSensors: "						<< TTFRMU::Array2Str(obj.fwSensors, WFS_SIU_SENSORS_SIZE)
				<< " fwDoors: "							<< TTFRMU::Array2Str(obj.fwDoors, WFS_SIU_DOORS_SIZE)
				<< " fwIndicators: "					<< TTFRMU::Array2Str(obj.fwIndicators, WFS_SIU_INDICATORS_SIZE)
				<< " fwAuxiliaries: "					<< TTFRMU::Array2Str(obj.fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE)
				<< " fwGuidLights: "					<< TTFRMU::Array2Str(obj.fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE)
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
		XFS300::LPWFSSIUENABLE lpWFSSIUENABLE = nullptr;
	} TTWFSSIUENABLE, * LPTTWFSSIUENABLE;

	typedef struct _tt_wfs_siu_set_ports : public XFS300::_wfs_siu_set_ports
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_set_ports)
		~_tt_wfs_siu_set_ports() { SAFERELEASE(&this->lpWFSSIUSETPORTS) }
		void WFS2TT(const XFS300::_wfs_siu_set_ports* obj)
		{
			SAFECOPYMEMORY(this->fwDoors, obj->fwDoors, WFS_SIU_DOORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwIndicators, obj->fwIndicators, WFS_SIU_INDICATORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwAuxiliaries, obj->fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwGuidLights, obj->fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE * sizeof(WORD));
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		void WFS(XFS300::LPWFSSIUSETPORTS* lppWFSSIUSETPORTS)
		{
			this->lpWFSSIUSETPORTS = new XFS300::WFSSIUSETPORTS;
			SAFECOPYMEMORY(this->lpWFSSIUSETPORTS->fwDoors, this->fwDoors, WFS_SIU_DOORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUSETPORTS->fwIndicators, this->fwIndicators, WFS_SIU_INDICATORS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUSETPORTS->fwAuxiliaries, this->fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->lpWFSSIUSETPORTS->fwGuidLights, this->fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE * sizeof(WORD));
			this->lpWFSSIUSETPORTS->lpszExtra = nullptr;
			*lppWFSSIUSETPORTS = this->lpWFSSIUSETPORTS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_set_ports& obj)
		{
			out << " fwDoors: "							<< TTFRMU::Array2Str(obj.fwDoors, WFS_SIU_DOORS_SIZE)
				<< " fwIndicators: "					<< TTFRMU::Array2Str(obj.fwIndicators, WFS_SIU_INDICATORS_SIZE)
				<< " fwAuxiliaries: "					<< TTFRMU::Array2Str(obj.fwAuxiliaries, WFS_SIU_AUXILIARIES_SIZE)
				<< " fwGuidLights: "					<< TTFRMU::Array2Str(obj.fwGuidLights, WFS_SIU_GUIDLIGHTS_SIZE)
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
		XFS300::LPWFSSIUSETPORTS lpWFSSIUSETPORTS = nullptr;
	} TTWFSSIUSETPORTS, * LPTTWFSSIUSETPORTS;

	typedef struct _tt_wfs_siu_set_door : public XFS300::_wfs_siu_set_door
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_set_door)
		~_tt_wfs_siu_set_door() { SAFERELEASE(&this->lpWFSSIUSETDOOR) }
		void WFS2TT(const XFS300::_wfs_siu_set_door* obj)
		{
			this->wDoor									= obj->wDoor;
			this->fwCommand								= obj->fwCommand;
		}
		void WFS(XFS300::LPWFSSIUSETDOOR* lppWFSSIUSETDOOR)
		{
			this->lpWFSSIUSETDOOR = new XFS300::WFSSIUSETDOOR;
			this->lpWFSSIUSETDOOR->wDoor				= this->wDoor;
			this->lpWFSSIUSETDOOR->fwCommand			= this->fwCommand;
			*lppWFSSIUSETDOOR = this->lpWFSSIUSETDOOR;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_set_door& obj)
		{
			out << " wDoor: "							<< obj.wDoor
				<< " fwCommand: "						<< obj.fwCommand;
			return out;
		}
		XFS300::LPWFSSIUSETDOOR lpWFSSIUSETDOOR = nullptr;
	} TTWFSSIUSETDOOR, * LPTTWFSSIUSETDOOR;

	typedef struct _tt_wfs_siu_set_indicator : public XFS300::_wfs_siu_set_indicator
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_set_indicator)
		~_tt_wfs_siu_set_indicator() { SAFERELEASE(&this->lpWFSSIUSETINDICATOR) }
		void WFS2TT(const XFS300::_wfs_siu_set_indicator* obj)
		{
			this->wIndicator							= obj->wIndicator;
			this->fwCommand								= obj->fwCommand;
		}
		void WFS(XFS300::LPWFSSIUSETINDICATOR* lppWFSSIUSETINDICATOR)
		{
			this->lpWFSSIUSETINDICATOR = new XFS300::WFSSIUSETINDICATOR;
			this->lpWFSSIUSETINDICATOR->wIndicator		= this->wIndicator;
			this->lpWFSSIUSETINDICATOR->fwCommand		= this->fwCommand;
			*lppWFSSIUSETINDICATOR = this->lpWFSSIUSETINDICATOR;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_set_indicator& obj)
		{
			out << " wIndicator: "						<< obj.wIndicator
				<< " fwCommand: "						<< obj.fwCommand;
			return out;
		}
		XFS300::LPWFSSIUSETINDICATOR lpWFSSIUSETINDICATOR = nullptr;
	} TTWFSSIUSETINDICATOR, * LPTTWFSSIUSETINDICATOR;

	typedef struct _tt_wfs_siu_set_auxiliary : public XFS300::_wfs_siu_set_auxiliary
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_set_auxiliary)
		~_tt_wfs_siu_set_auxiliary() { SAFERELEASE(&this->lpWFSSIUSETAUXILIARY) }
		void WFS2TT(const XFS300::_wfs_siu_set_auxiliary* obj)
		{
			this->wAuxiliary							= obj->wAuxiliary;
			this->fwCommand								= obj->fwCommand;
		}
		void WFS(XFS300::LPWFSSIUSETAUXILIARY* lppWFSSIUSETAUXILIARY)
		{
			this->lpWFSSIUSETAUXILIARY = new XFS300::WFSSIUSETAUXILIARY;
			this->lpWFSSIUSETAUXILIARY->wAuxiliary		= this->wAuxiliary;
			this->lpWFSSIUSETAUXILIARY->fwCommand		= this->fwCommand;
			*lppWFSSIUSETAUXILIARY = this->lpWFSSIUSETAUXILIARY;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_set_auxiliary& obj)
		{
			out << " wAuxiliary: "						<< obj.wAuxiliary
				<< " fwCommand: "						<< obj.fwCommand;
			return out;
		}
		XFS300::LPWFSSIUSETAUXILIARY lpWFSSIUSETAUXILIARY = nullptr;
	} TTWFSSIUSETAUXILIARY, * LPTTWFSSIUSETAUXILIARY;

	typedef struct _tt_wfs_siu_set_guidlight : public XFS300::_wfs_siu_set_guidlight
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_set_guidlight)
		~_tt_wfs_siu_set_guidlight() { SAFERELEASE(&this->lpWFSSIUSETGUIDLIGHT) }
		void WFS2TT(const XFS300::_wfs_siu_set_guidlight* obj)
		{
			this->wGuidLight							= obj->wGuidLight;
			this->fwCommand								= obj->fwCommand;
		}
		void WFS(XFS300::LPWFSSIUSETGUIDLIGHT* lppWFSSIUSETGUIDLIGHT)
		{
			this->lpWFSSIUSETGUIDLIGHT = new XFS300::WFSSIUSETGUIDLIGHT;
			this->lpWFSSIUSETGUIDLIGHT->wGuidLight		= this->wGuidLight;
			this->lpWFSSIUSETGUIDLIGHT->fwCommand		= this->fwCommand;
			*lppWFSSIUSETGUIDLIGHT = this->lpWFSSIUSETGUIDLIGHT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_set_guidlight& obj)
		{
			out << " wGuidLight: "						<< obj.wGuidLight
				<< " fwCommand: "						<< obj.fwCommand;
			return out;
		}
		XFS300::LPWFSSIUSETGUIDLIGHT lpWFSSIUSETGUIDLIGHT = nullptr;
	} TTWFSSIUSETGUIDLIGHT, * LPTTWFSSIUSETGUIDLIGHT;
	
	/*=================================================================*/
	/* SIU Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_siu_port_event : public XFS300::_wfs_siu_port_event
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_port_event)
		DEFAULTDESTRUCTOR(_tt_wfs_siu_port_event)
		void WFS2TT(const _wfs_siu_port_event* obj)
		{
			this->wPortType								= obj->wPortType;
			this->wPortIndex							= obj->wPortIndex;
			this->wPortStatus							= obj->wPortStatus;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_port_event& obj)
		{
			out << " wPortType: "						<< obj.wPortType
				<< " wPortIndex: "						<< obj.wPortIndex
				<< " wPortStatus: "						<< obj.wPortStatus
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSSIUPORTEVENT, * LPTTWFSSIUPORTEVENT;

	typedef struct _tt_wfs_siu_port_error : public XFS300::_wfs_siu_port_error
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_siu_port_error)
		DEFAULTDESTRUCTOR(_tt_wfs_siu_port_error)
		void WFS2TT(const _wfs_siu_port_error* obj)
		{
			this->wPortType								= obj->wPortType;
			this->wPortIndex							= obj->wPortIndex;
			this->PortError								= obj->PortError;
			this->wPortStatus							= obj->wPortStatus;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_siu_port_error& obj)
		{
			out << " wPortType: "						<< obj.wPortType
				<< " wPortIndex: "						<< obj.wPortIndex
				<< " PortError: "						<< obj.PortError
				<< " wPortStatus: "						<< obj.wPortStatus
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSSIUPORTERROR, * LPTTWFSSIUPORTERROR;

	#pragma pack(pop)

	/*=================================================================*/
	/* SIU Interface */
	/*=================================================================*/

	class ITTSIU : public ITTDevice
	{
	public:
		ITTSIU() = default;
		ITTSIU(const ITTSIU&) = delete;
		ITTSIU(ITTSIU&&) = delete;
		ITTSIU& operator = (const ITTSIU&) = delete;
		ITTSIU& operator = (ITTSIU&&) = delete;
		virtual ~ITTSIU() = default;

		/* SIU Info Functions */
		virtual bool GetStatus(LPTTWFSSIUSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSSIUCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* SIU Execute Functions */
		virtual bool EnableEvents(const LPTTWFSSIUENABLE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetPorts(const LPTTWFSSIUSETPORTS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetDoor(const LPTTWFSSIUSETDOOR, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetIndicator(const LPTTWFSSIUSETINDICATOR, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetAuxiliary(const LPTTWFSSIUSETAUXILIARY, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetGuidlight(const LPTTWFSSIUSETGUIDLIGHT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncEnableEvents(const LPTTWFSSIUENABLE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetPorts(const LPTTWFSSIUSETPORTS, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetDoor(const LPTTWFSSIUSETDOOR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetIndicator(const LPTTWFSSIUSETINDICATOR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetAuxiliary(const LPTTWFSSIUSETAUXILIARY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetGuidlight(const LPTTWFSSIUSETGUIDLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTSIU_H
