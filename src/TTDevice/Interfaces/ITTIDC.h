#pragma once

#ifndef __H_ITTIDC_H
#define __H_ITTIDC_H

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* IDC Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_idc_status : public XFS300::_wfs_idc_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_status)
			void WFS2TT(const XFS300::_wfs_idc_status* obj)
		{
			this->fwDevice									= obj->fwDevice;
			this->fwMedia									= obj->fwMedia;
			this->fwRetainBin								= obj->fwRetainBin;
			this->fwSecurity								= obj->fwSecurity;
			this->usCards									= obj->usCards;
			this->fwChipPower								= obj->fwChipPower;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_idc_status)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_status& obj)
		{
			out << " fwDevice: "							<< obj.fwDevice
				<< " fwMedia: "								<< obj.fwMedia
				<< " fwRetainBin: " 						<< obj.fwRetainBin
				<< " fwSecurity: "							<< obj.fwSecurity
				<< " usCards: "								<< obj.usCards
				<< " fwChipPower: " 						<< obj.fwChipPower
				<< " lpsxExtra: "							<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSIDCSTATUS, * LPTTWFSIDCSTATUS;

	typedef struct _tt_wfs_idc_caps : public XFS300::_wfs_idc_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_caps)
			void WFS2TT(const XFS300::_wfs_idc_caps* obj)
		{
			this->wClass									= obj->wClass;
			this->fwType									= obj->fwType;
			this->bCompound									= obj->bCompound;
			this->fwReadTracks								= obj->fwReadTracks;
			this->fwWriteTracks								= obj->fwWriteTracks;
			this->fwChipProtocols							= obj->fwChipProtocols;
			this->usCards									= obj->usCards;
			this->fwSecType									= obj->fwSecType;
			this->fwPowerOnOption							= obj->fwPowerOnOption;
			this->fwPowerOffOption							= obj->fwPowerOffOption;
			this->bFluxSensorProgrammable					= obj->bFluxSensorProgrammable;
			this->bReadWriteAccessFollowingEject			= obj->bReadWriteAccessFollowingEject;
			this->fwWriteMode 								= obj->fwWriteMode;
			this->fwChipPower 								= obj->fwChipPower;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_idc_caps)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_caps& obj)
		{
			out << " wClass: "								<< obj.wClass
				<< " fwType: "								<< obj.fwType
				<< " bCompound: "							<< obj.bCompound
				<< " fwReadTracks: "						<< obj.fwReadTracks
				<< " fwWriteTracks: "						<< obj.fwWriteTracks
				<< " fwChipProtocols: "						<< obj.fwChipProtocols
				<< " usCards: "								<< obj.usCards
				<< " fwSecType: "							<< obj.fwSecType
				<< " fwPowerOnOption: "						<< obj.fwPowerOnOption
				<< " fwPowerOffOption: "					<< obj.fwPowerOffOption
				<< " bFluxSensorProgrammable: "				<< obj.bFluxSensorProgrammable
				<< " bReadWriteAccessFollowingEject: "		<< obj.bReadWriteAccessFollowingEject
				<< " fwWriteMode: " 						<< obj.fwWriteMode
				<< " fwChipPower: " 						<< obj.fwChipPower
				<< " lpsxExtra: "							<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSIDCCAPS, * LPTTWFSIDCCAPS;

	typedef struct _tt_wfs_idc_lpstr_frm_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_lpstr_frm_list)
			void WFS2TT(const LPSTR obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->strvectFormList, obj);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_idc_lpstr_frm_list)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_lpstr_frm_list& obj)
		{
			out << "FormList: " << DeviceUtility::STRVECT2Str(obj.strvectFormList).c_str();
			return out;
		}
		DeviceUtility::STRVECT strvectFormList;
	} TTWFSIDCLPSTRFRMLIST, * LPTTWFSIDCLPSTRFRMLIST;

	typedef struct _tt_wfs_idc_form : public XFS300::_wfs_idc_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_form)
			void WFS2TT(const XFS300::_wfs_idc_form* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName, DeviceUtility::Size_LPSTR(obj->lpszFormName));

			this->cFieldSeparatorTrack1						= obj->cFieldSeparatorTrack1;
			this->cFieldSeparatorTrack2						= obj->cFieldSeparatorTrack2;
			this->cFieldSeparatorTrack3						= obj->cFieldSeparatorTrack3;
			this->fwAction									= obj->fwAction;
			DeviceUtility::LPSTRNN2Vector(this->lpszTracks, obj->lpszTracks);
			this->bSecure									= obj->bSecure;
			DeviceUtility::LPSTRNN2Vector(this->lpszTrack1Fields, obj->lpszTrack1Fields);
			DeviceUtility::LPSTRNN2Vector(this->lpszTrack2Fields, obj->lpszTrack2Fields);
			DeviceUtility::LPSTRNN2Vector(this->lpszTrack3Fields, obj->lpszTrack3Fields);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_idc_form)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_form& obj)
		{
			out << " lpszFormName: "						<< obj.lpszFormName.c_str()
				<< " cFieldSeparatorTrack1: "				<< obj.cFieldSeparatorTrack1
				<< " cFieldSeparatorTrack2: "				<< obj.cFieldSeparatorTrack2
				<< " cFieldSeparatorTrack3: "				<< obj.cFieldSeparatorTrack3
				<< " fwAction: "							<< obj.fwAction
				<< " lpszTracks: "							<< DeviceUtility::STRVECT2Str(obj.lpszTracks).c_str()
				<< " bSecure: "								<< obj.bSecure
				<< " lpszTrack1Fields: " 					<< DeviceUtility::STRVECT2Str(obj.lpszTrack1Fields).c_str()
				<< " lpszTrack2Fields: " 					<< DeviceUtility::STRVECT2Str(obj.lpszTrack2Fields).c_str()
				<< " lpszTrack3Fields: " 					<< DeviceUtility::STRVECT2Str(obj.lpszTrack3Fields).c_str();
			return out;
		}
		std::string				lpszFormName;
		DeviceUtility::STRVECT	lpszTracks;
		DeviceUtility::STRVECT	lpszTrack1Fields;
		DeviceUtility::STRVECT	lpszTrack2Fields;
		DeviceUtility::STRVECT	lpszTrack3Fields;
	} TTWFSIDCFORM, * LPTTWFSIDCFORM;

	/*=================================================================*/
	/* IDC Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_idc_write_track : public XFS300::_wfs_idc_write_track
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_write_track)
		~_tt_wfs_idc_write_track()
		{
			SAFEPTR(this->lpWFSIDCWRITETRACK)
			{
				SAFEFREEMEMORY(&this->lpWFSIDCWRITETRACK->lpstrFormName);
				SAFEFREEMEMORY(&this->lpWFSIDCWRITETRACK->lpstrTrackData);
				SAFERELEASE(&this->lpWFSIDCWRITETRACK);
			}
		}
		void WFS2TT(const XFS300::_wfs_idc_write_track* obj)
		{
			this->lpstrFormName.assign(obj->lpstrFormName);
			this->lpstrTrackData.assign(obj->lpstrTrackData);
			this->fwWriteMethod								= obj->fwWriteMethod;
		}
		void WFS(XFS300::LPWFSIDCWRITETRACK* lppWFSIDCWRITETRACK)
		{
			this->lpWFSIDCWRITETRACK = new XFS300::WFSIDCWRITETRACK;
			SAFEALLOCCOPYSTRING(&this->lpWFSIDCWRITETRACK->lpstrFormName, this->lpstrFormName);
			SAFEALLOCCOPYSTRING(&this->lpWFSIDCWRITETRACK->lpstrTrackData, this->lpstrTrackData);
			this->fwWriteMethod								= this->fwWriteMethod;
			*lppWFSIDCWRITETRACK = this->lpWFSIDCWRITETRACK;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_write_track& obj)
		{
			out << " lpstrFormName: "						<< obj.lpstrFormName
				<< " lpstrTrackData: "						<< obj.lpstrTrackData
				<< " fwWriteMethod: "						<< obj.fwWriteMethod;
			return out;
		}
		std::string lpstrFormName;
		std::string lpstrTrackData;
		XFS300::LPWFSIDCWRITETRACK lpWFSIDCWRITETRACK = nullptr;
	} TTWFSIDCWRITETRACK, * LPTTWFSIDCWRITETRACK;

	typedef struct _tt_wfs_idc_retain_card : public XFS300::_wfs_idc_retain_card
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_retain_card)
		DEFAULTDESTRUCTOR(_tt_wfs_idc_retain_card)
		void WFS2TT(const XFS300::_wfs_idc_retain_card* obj)
		{
			this->usCount									= obj->usCount;
			this->fwPosition								= obj->fwPosition;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_retain_card& obj)
		{
			out << " usCount: "								<< obj.usCount
				<< " fwPosition: "							<< obj.fwPosition;
			return out;
		}
	} TTWFSIDCRETAINCARD, * LPTTWFSIDCRETAINCARD;

	typedef struct _tt_wfs_idc_setkey : public XFS300::_wfs_idc_setkey
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_setkey)
		~_tt_wfs_idc_setkey()
		{
			SAFEPTR(this->lpWFSIDCSETKEY)
			{
				SAFEFREEMEMORY(&this->lpWFSIDCSETKEY->lpbKeyValue);
				SAFERELEASE(&this->lpWFSIDCSETKEY);
			}
		}
		void WFS2TT(const XFS300::_wfs_idc_setkey* obj)
		{
			this->usKeyLen									= obj->usKeyLen;
			SAFEPTR(obj->lpbKeyValue) this->lpbKeyValue.assign((char*)obj->lpbKeyValue);
		}
		void WFS(XFS300::LPWFSIDCSETKEY* lppWFSIDCSETKEY)
		{
			this->lpWFSIDCSETKEY = new XFS300::WFSIDCSETKEY;
			this->lpWFSIDCSETKEY->usKeyLen					= this->usKeyLen;
			SAFEALLOCCOPYSTRING(&this->lpWFSIDCSETKEY->lpbKeyValue, this->lpbKeyValue);
			*lppWFSIDCSETKEY = this->lpWFSIDCSETKEY;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_setkey& obj)
		{
			out << " usKeyLen: "							<< obj.usKeyLen
				<< " lpbKeyValue: "							<< obj.lpbKeyValue;
			return out;
		}
		std::string lpbKeyValue;
		XFS300::LPWFSIDCSETKEY lpWFSIDCSETKEY = nullptr;
	} TTWFSIDCSETKEY, * LPTTWFSIDCSETKEY;

	typedef struct _tt_wfs_idc_card_data : public XFS300::_wfs_idc_card_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_card_data)
		~_tt_wfs_idc_card_data() 
		{ 
			SAFEFREEMEMORY(&this->lpbData);
			SAFEPTR(this->lpWFSIDCCARDDATA)
			{
				SAFEFREEMEMORY(&this->lpWFSIDCCARDDATA->lpbData);
				SAFERELEASE(&this->lpWFSIDCCARDDATA);
			}
		}
		void WFS2TT(const XFS300::_wfs_idc_card_data* obj)
		{
			this->wDataSource								= obj->wDataSource;
			this->wStatus									= obj->wStatus;
			this->ulDataLength								= obj->ulDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpbData, obj->lpbData, obj->ulDataLength);
			this->fwWriteMethod								= obj->fwWriteMethod;
		}
		void WFS(XFS300::LPWFSIDCCARDDATA* lppWFSIDCCARDDATA)
		{
			this->lpWFSIDCCARDDATA = new XFS300::WFSIDCCARDDATA;
			this->lpWFSIDCCARDDATA->wDataSource				= this->wDataSource;
			this->lpWFSIDCCARDDATA->wStatus					= this->wStatus;
			this->lpWFSIDCCARDDATA->ulDataLength			= this->ulDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpWFSIDCCARDDATA->lpbData, this->lpbData, this->ulDataLength);
			this->fwWriteMethod								= this->fwWriteMethod;
			*lppWFSIDCCARDDATA = this->lpWFSIDCCARDDATA;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_card_data& obj)	
		{	
			out << " - "
				<< " wDataSource: "							<< obj.wDataSource
				<< " wStatus: "								<< obj.wStatus
				<< " ulDataLength: "						<< obj.ulDataLength
				<< " lpbData: "								<< TTFRMU::ByteArray2Str(obj.lpbData, obj.ulDataLength)
				<< " fwWriteMethod: "						<< obj.fwWriteMethod;
			return out;
		}
		XFS300::LPWFSIDCCARDDATA lpWFSIDCCARDDATA = nullptr;
	} TTWFSIDCCARDDATA, * LPTTWFSIDCCARDDATA;

	typedef struct _tt_wfs_idc_p2ap_card_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_p2ap_card_data)
		void WFS2TT(const XFS300::_wfs_idc_card_data* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listCardData, (XFS300::_wfs_idc_card_data**)obj);
		}
		~_tt_wfs_idc_p2ap_card_data() { SAFERELEASECONT(this->listCardData) }
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_p2ap_card_data& obj)
		{
			out << "Card Data: "							<< DeviceUtility::TTCONT2Str(obj.listCardData).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSIDCCARDDATA>listCardData;
	} TTWFSIDCP2APCARDDATA, * LPTTWFSIDCP2APCARDDATA;

	typedef struct _tt_wfs_idc_chip_io : public XFS300::_wfs_idc_chip_io
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_chip_io)
		~_tt_wfs_idc_chip_io() 
		{ 
			SAFEFREEMEMORY(&this->lpbChipData);
			SAFEPTR(this->lpWFSIDCCHIPIO)
			{
				SAFEFREEMEMORY(&this->lpWFSIDCCHIPIO->lpbChipData);
				SAFERELEASE(&this->lpWFSIDCCHIPIO);
			}
		}
		void WFS2TT(const XFS300::_wfs_idc_chip_io* obj)
		{
			this->wChipProtocol								= obj->wChipProtocol;
			this->ulChipDataLength							= obj->ulChipDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpbChipData, obj->lpbChipData, obj->ulChipDataLength);
		}
		void WFS(XFS300::LPWFSIDCCHIPIO* lppWFSIDCCHIPIO)
		{
			this->lpWFSIDCCHIPIO = new XFS300::WFSIDCCHIPIO;
			this->lpWFSIDCCHIPIO->wChipProtocol				= this->wChipProtocol;
			this->lpWFSIDCCHIPIO->ulChipDataLength			= this->ulChipDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpWFSIDCCHIPIO->lpbChipData, this->lpbChipData, this->ulChipDataLength);
			*lppWFSIDCCHIPIO = this->lpWFSIDCCHIPIO;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_chip_io& obj)
		{
			out << " wChipProtocol: "						<< obj.wChipProtocol
				<< " ulChipDataLength: "					<< obj.ulChipDataLength
				<< " lpbChipData: "							<< TTFRMU::ByteArray2Str(obj.lpbChipData, obj.ulChipDataLength);
			return out;
		}
		XFS300::LPWFSIDCCHIPIO lpWFSIDCCHIPIO = nullptr;
	} TTWFSIDCCHIPIO, * LPTTWFSIDCCHIPIO;

	typedef struct _tt_wfs_idc_chip_power_out : public XFS300::_wfs_idc_chip_power_out
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_chip_power_out)
		void WFS2TT(const XFS300::_wfs_idc_chip_power_out* obj)
		{
			this->ulChipDataLength							= obj->ulChipDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpbChipData, obj->lpbChipData, obj->ulChipDataLength);
		}
		~_tt_wfs_idc_chip_power_out() { SAFEFREEMEMORY(&this->lpbChipData); }
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_chip_power_out& obj)
		{
			out << " ulDataLength: "						<< obj.ulChipDataLength
				<< " lpbChipData: "							<< TTFRMU::ByteArray2Str(obj.lpbChipData, obj.ulChipDataLength);
			return out;
		}
	} TTWFSIDCCHIPPOWEROUT, * LPTTWFSIDCCHIPPOWEROUT;

	typedef struct _tt_wfs_idc_lpstr
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_lpstr)
		DEFAULTDESTRUCTOR(_tt_wfs_idc_lpstr)
		void WFS2TT(const LPSTR obj)
		{
			_str.assign(obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_lpstr& obj)
		{
			out << "lpstr: "								<< obj._str;
			return out;
		}
		std::string _str;
	} TTWFSIDCSTR, * LPTTWFSSTRSTR;

	typedef struct _tt_wfs_idc_parse_data: public XFS300::_wfs_idc_parse_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_parse_data)
		~_tt_wfs_idc_parse_data()
		{
			SAFERELEASECONT(this->lppCardData);
			SAFEPTR(this->lpWFSIDCPARSEDATA)
			{
				SAFEFREEMEMORY(&this->lpWFSIDCPARSEDATA->lpstrFormName);
				SAFERELEASELPP(this->lpWFSIDCPARSEDATA->lppCardData, this->lppCardData.size());
				SAFERELEASE(&this->lpWFSIDCPARSEDATA);
			}
		}
		void WFS2TT(const XFS300::_wfs_idc_parse_data* obj)
		{
			SAFEPTR(obj->lpstrFormName) this->lpstrFormName.assign(obj->lpstrFormName);
			SAFEPTR(obj->lppCardData) DeviceUtility::CopyP2NAPs(this->lppCardData, obj->lppCardData);
		}
		void WFS(XFS300::LPWFSIDCPARSEDATA* lppWFSIDCPARSEDATA)
		{
			this->lpWFSIDCPARSEDATA = new XFS300::WFSIDCPARSEDATA;
			SAFEALLOCCOPYSTRING(&this->lpWFSIDCPARSEDATA->lpstrFormName, this->lpstrFormName);
			DeviceUtility::CopyP2NAPs_r(this->lpWFSIDCPARSEDATA->lppCardData, this->lppCardData);
			*lppWFSIDCPARSEDATA = this->lpWFSIDCPARSEDATA;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_parse_data& obj)
		{
			out << "lpstrFormName: "						<< obj.lpstrFormName
				<< "lppCardData: "							<< DeviceUtility::TTCONT2Str(obj.lppCardData);
			return out;
		}
		std::string lpstrFormName;
		DeviceUtility::TTCONT<LPTTWFSIDCCARDDATA> lppCardData;
		XFS300::LPWFSIDCPARSEDATA lpWFSIDCPARSEDATA = nullptr;
	} TTWFSIDCPARSEDATA, * LPTTWFSIDCPARSEDATA;

	/*=================================================================*/
	/* IDC Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_idc_track_event : public XFS300::_wfs_idc_track_event
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_track_event)
		DEFAULTDESTRUCTOR(_tt_wfs_idc_track_event)
		void WFS2TT(const _wfs_idc_track_event* obj)
		{
			this->fwStatus									= obj->fwStatus;
			this->lpstrTrack.assign(obj->lpstrTrack);
			this->lpstrData.assign(obj->lpstrData);

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_track_event& obj)
		{
			out << " fwStatus: "							<< obj.fwStatus
				<< " lpstrTrack: "							<< obj.lpstrTrack.c_str()
				<< " lpstrData: "							<< obj.lpstrData.c_str();
			return out;
		}
		std::string lpstrTrack;
		std::string lpstrData;
	} TTWFSIDCTRACKEVENT, * LPTTWFSIDCTRACKEVENT;

	typedef struct _tt_wfs_idc_card_act : public XFS300::_wfs_idc_card_act
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_idc_card_act)
		DEFAULTDESTRUCTOR(_tt_wfs_idc_card_act)
		void WFS2TT(const _wfs_idc_card_act* obj)
		{
			this->wAction									= obj->wAction;
			this->wPosition									= obj->wPosition;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_idc_card_act& obj)
		{
			out << " wAction: "								<< obj.wAction
				<< " wPosition: "							<< obj.wPosition;
			return out;
		}
	} TTWFSIDCCARDACT, * LPTTWFSIDCCARDACT;

#pragma pack(pop)

	/*=================================================================*/
	/* IDC Interface */
	/*=================================================================*/

	class ITTIDC : public ITTDevice
	{
	public:
		ITTIDC() = default;
		ITTIDC(const ITTIDC&) = delete;
		ITTIDC(ITTIDC&&) = delete;
		ITTIDC& operator = (const ITTIDC&) = delete;
		ITTIDC& operator = (ITTIDC&&) = delete;
		virtual ~ITTIDC() = default;

		/* IDC Info Commands */
		virtual bool GetStatus(LPTTWFSIDCSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSIDCCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetFormList(LPTTWFSIDCLPSTRFRMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetQueryForm(LPSTR, LPTTWFSIDCFORM, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetQueryForm(LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* IDC Execute Commands */
		virtual bool ReadTrack(const LPSTR, LPTTWFSSTRSTR, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool WriteTrack(const LPTTWFSIDCWRITETRACK, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool EjectCard(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool RetainCard(LPTTWFSIDCRETAINCARD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ResetCount(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetKey(const LPTTWFSIDCSETKEY, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ReadRawData(const LPWORD, LPTTWFSIDCP2APCARDDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool WriteRawData(const LPTTWFSIDCCARDDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ChipIO(const LPTTWFSIDCCHIPIO, LPTTWFSIDCCHIPIO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ChipPower(const LPWORD, LPTTWFSIDCCHIPPOWEROUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ParseData(const LPTTWFSIDCPARSEDATA, LPTTWFSSTRSTR, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncReadTrack(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncWriteTrack(const LPTTWFSIDCWRITETRACK, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncEjectCard(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRetainCard(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncResetCount(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetKey(const LPTTWFSIDCSETKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReadRawData(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncWriteRawData(const LPTTWFSIDCCARDDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncChipIO(const LPTTWFSIDCCHIPIO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncChipPower(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncParseData(const LPTTWFSIDCPARSEDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTIDC_H
