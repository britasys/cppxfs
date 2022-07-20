#pragma once

#ifndef __H_ITTCHK__
#define __H_ITTCHK__

#include <Windows.h>
#include <sstream>
#include <ostream>
#include <string>

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* CHK Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_chk_status : public XFS300::_wfs_chk_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_status)
		DEFAULTDESTRUCTOR(_tt_wfs_chk_status)
		void WFS2TT(const XFS300::_wfs_chk_status* obj)
		{
			this->fwDevice = obj->fwDevice;
			this->fwMedia = obj->fwMedia;
			this->fwInk = obj->fwInk;

			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_status& obj)
		{
			out << " fwDevice: " << obj.fwDevice
				<< " fwMedia: " << obj.fwMedia
				<< " fwInk: " << obj.fwInk
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSCHKSTATUS, * LPTTWFSCHKSTATUS;

	typedef struct _tt_wfs_chk_caps : public XFS300::_wfs_chk_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_chk_caps)
		void WFS2TT(const XFS300::_wfs_chk_caps* obj)
		{
			this->wClass = obj->wClass;
			this->fwType = obj->fwType;
			this->bCompound = obj->bCompound;
			this->bMICR = obj->bMICR;
			this->bOCR = obj->bOCR;
			this->bAutoFeed = obj->bAutoFeed;
			this->bEndorser = obj->bEndorser;
			this->bEncoder = obj->bEncoder;
			this->fwStamp = obj->fwStamp;
			this->wImageCapture = obj->wImageCapture;
			DeviceUtility::LPSTRNN2Vector(this->lpszFontNames, obj->lpszFontNames);
			DeviceUtility::LPSTRNN2Vector(this->lpszEncodeNames, obj->lpszEncodeNames);
			this->fwCharSupport = obj->fwCharSupport;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_caps& obj)
		{
			out << " wClass: " << obj.wClass
				<< " fwType: " << obj.fwType
				<< " bCompound: " << obj.bCompound
				<< " bMICR: " << obj.bMICR
				<< " bOCR: " << obj.bOCR
				<< " bAutoFeed: " << obj.bAutoFeed
				<< " bEndorser: " << obj.bEndorser
				<< " bEncoder: " << obj.bEncoder
				<< " fwStamp: " << obj.fwStamp
				<< " wImageCapture: " << obj.wImageCapture
				<< " lpszFontNames: " << DeviceUtility::STRVECT2Str(obj.lpszFontNames).c_str()
				<< " lpszEncodeNames: " << DeviceUtility::STRVECT2Str(obj.lpszEncodeNames).c_str()
				<< " fwCharSupport: " << obj.fwCharSupport
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
		DeviceUtility::STRVECT lpszFontNames;
		DeviceUtility::STRVECT lpszEncodeNames;
	} TTWFSCHKCAPS, * LPTTWFSCHKCAPS;

	typedef struct _tt_wfs_chk_frm_header : public XFS300::_wfs_chk_frm_header
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_frm_header)
		DEFAULTDESTRUCTOR(_tt_wfs_chk_frm_header)
		void WFS2TT(const XFS300::_wfs_chk_frm_header* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName, DeviceUtility::Size_LPSTR(obj->lpszFormName));
			this->wBase = obj->wBase;
			this->wUnitX = obj->wUnitX;
			this->wUnitY = obj->wUnitY;
			this->wWidth = obj->wWidth;
			this->wHeight = obj->wHeight;
			this->wAlignment = obj->wAlignment;
			this->wOffsetX = obj->wOffsetX;
			this->wOffsetY = obj->wOffsetY;
			this->wVersionMajor = obj->wVersionMajor;
			this->wVersionMinor = obj->wVersionMinor;
			this->fwCharSupport = obj->fwCharSupport;

			DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_frm_header& obj)
		{
			out << " lpszFormName: " << obj.lpszFormName.c_str()
				<< " wBase: " << obj.wBase
				<< " wUnitX: " << obj.wUnitX
				<< " wUnitY: " << obj.wUnitY
				<< " wWidth: " << obj.wWidth
				<< " wHeight: " << obj.wHeight
				<< " wAlignment: " << obj.wAlignment
				<< " wOffsetX: " << obj.wOffsetX
				<< " wOffsetY: " << obj.wOffsetY
				<< " wVersionMajor: " << obj.wVersionMajor
				<< " wVersionMinor: " << obj.wVersionMinor
				<< " fwCharSupport: " << obj.fwCharSupport
				<< " lpszFields: " << DeviceUtility::STRVECT2Str(obj.lpszFields).c_str();

			return out;
		}
		DeviceUtility::STRVECT	lpszFields;
		std::string				lpszFormName;
	} TTWFSCHKFRMHEADER, * LPTTWFSCHKFRMHEADER;

	typedef struct _tt_wfs_chk_frm_media : public XFS300::_wfs_chk_frm_media
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_frm_media)
		DEFAULTDESTRUCTOR(_tt_wfs_chk_frm_media)
			void WFS2TT(const XFS300::_wfs_chk_frm_media* obj)
		{
			this->fwMediaType = obj->fwMediaType;
			this->wBase = obj->wBase;
			this->wUnitX = obj->wUnitX;
			this->wUnitY = obj->wUnitY;
			this->wSizeWidth = obj->wSizeWidth;
			this->wSizeHeight = obj->wSizeHeight;
			this->wCheckAreaX = obj->wCheckAreaX;
			this->wCheckAreaY = obj->wCheckAreaY;
			this->wCheckAreaWidth = obj->wCheckAreaWidth;
			this->wCheckAreaHeight = obj->wCheckAreaHeight;
			this->wRestrictedAreaX = obj->wRestrictedAreaX;
			this->wRestrictedAreaY = obj->wRestrictedAreaY;
			this->wRestrictedAreaWidth = obj->wRestrictedAreaWidth;
			this->wRestrictedAreaHeight = obj->wRestrictedAreaHeight;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_frm_media& obj)
		{
			out << " fwMediaType: " << obj.fwMediaType
				<< " wBase: " << obj.wBase
				<< " wUnitX: " << obj.wUnitX
				<< " wUnitY: " << obj.wUnitY
				<< " wSizeWidth: " << obj.wSizeWidth
				<< " wSizeHeight: " << obj.wSizeHeight
				<< " wCheckAreaX: " << obj.wCheckAreaX
				<< " wCheckAreaY: " << obj.wCheckAreaY
				<< " wCheckAreaWidth: " << obj.wCheckAreaWidth
				<< " wCheckAreaHeight: " << obj.wCheckAreaHeight
				<< " wRestrictedAreaX: " << obj.wRestrictedAreaX
				<< " wRestrictedAreaY: " << obj.wRestrictedAreaY
				<< " wRestrictedAreaWidth: " << obj.wRestrictedAreaWidth
				<< " wRestrictedAreaHeight: " << obj.wRestrictedAreaHeight;
			return out;
		}
	} TTWFSCHKFRMMEDIA, * LPTTWFSCHKFRMMEDIA;

	typedef struct _tt_wfs_chk_query_field : public XFS300::_wfs_chk_query_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_query_field)
			~_tt_wfs_chk_query_field()
		{
			SAFEPTR(this->lpWFSCHKQUERYFIELD)
			{
				SAFERELEASE(&this->lpWFSCHKQUERYFIELD->lpszFieldName);
				SAFERELEASE(&this->lpWFSCHKQUERYFIELD->lpszFormName);
				SAFERELEASE(&this->lpWFSCHKQUERYFIELD);
			}
		}
		void WFS2TT(const XFS300::_wfs_chk_query_field* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName, DeviceUtility::Size_LPSTR(obj->lpszFormName));
			this->lpszFieldName.assign(obj->lpszFieldName, DeviceUtility::Size_LPSTR(obj->lpszFieldName));
		}
		void WFS(XFS300::LPWFSCHKQUERYFIELD* lppWFSCHKQUERYFIELD)
		{
			this->lpWFSCHKQUERYFIELD = new XFS300::WFSCHKQUERYFIELD;
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKQUERYFIELD->lpszFormName, this->lpszFormName);
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKQUERYFIELD->lpszFieldName, this->lpszFieldName);
			*lppWFSCHKQUERYFIELD = this->lpWFSCHKQUERYFIELD;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_query_field& obj)
		{
			out << " lpszFormName: " << obj.lpszFormName.c_str()
				<< " lpszFieldName: " << obj.lpszFieldName.c_str();
			return out;
		}
		std::string lpszFormName;
		std::string lpszFieldName;
		XFS300::LPWFSCHKQUERYFIELD lpWFSCHKQUERYFIELD = nullptr;
	} TTWFSCHKQUERYFIELD, * LPTTWFSCHKQUERYFIELD;

	typedef struct _tt_wfs_chk_frm_field : public XFS300::_wfs_chk_frm_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_frm_field)
			void WFS2TT(const XFS300::_wfs_chk_frm_field* obj)
		{
			this->lpszFieldName.assign(obj->lpszFieldName, DeviceUtility::Size_LPSTR(obj->lpszFieldName));

			this->fwType = obj->fwType;
			this->fwClass = obj->fwClass;
			this->fwAccess = obj->fwAccess;
			this->fwOverflow = obj->fwOverflow;
			this->lpszInitialValue.assign(obj->lpszInitialValue, DeviceUtility::Size_LPSTR(obj->lpszInitialValue));
			this->lpszUNICODEInitialValue.assign(obj->lpszUNICODEInitialValue, DeviceUtility::Size_LPWSTR(obj->lpszUNICODEInitialValue));
			this->lpszFormat.assign(obj->lpszFormat, DeviceUtility::Size_LPSTR(obj->lpszFormat));
			this->lpszUNICODEFormat.assign(obj->lpszUNICODEFormat, DeviceUtility::Size_LPWSTR(obj->lpszUNICODEFormat));
		}
		DEFAULTDESTRUCTOR(_tt_wfs_chk_frm_field)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_frm_field& obj)
		{
			out << " - "
				<< " lpszFieldName: " << obj.lpszFieldName.c_str()
				<< " fwType: " << obj.fwType
				<< " fwClass: " << obj.fwClass
				<< " fwAccess: " << obj.fwAccess
				<< " fwOverflow: " << obj.fwOverflow
				<< " lpszInitialValue: " << obj.lpszInitialValue.c_str()
				<< " lpszUNICODEInitialValue: " << obj.lpszUNICODEInitialValue.c_str()
				<< " lpszFormat: " << obj.lpszFormat.c_str()
				<< " lpszUNICODEFormat: " << obj.lpszUNICODEFormat.c_str();
			return out;
		}
		std::string		lpszFieldName;
		std::string		lpszInitialValue;
		std::wstring	lpszUNICODEInitialValue;
		std::string		lpszFormat;
		std::wstring	lpszUNICODEFormat;
	} TTWFSCHKFRMFIELD, * LPTTWFSCHKFRMFIELD;

	typedef struct _tt_wfs_chk_p2ap_frm_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_p2ap_frm_field)
			void WFS2TT(const XFS300::_wfs_chk_frm_field* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listFormField, (XFS300::_wfs_chk_frm_field**)obj);
		}
		~_tt_wfs_chk_p2ap_frm_field() { SAFERELEASECONT(this->listFormField) }

		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_p2ap_frm_field& obj)
		{
			out << " FormFields: " << DeviceUtility::TTCONT2Str(obj.listFormField).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCHKFRMFIELD>listFormField;
	} TTWFSCHKP2APFRMFIELD, * LPTTWFSCHKP2APFRMFIELD;

	typedef struct _tt_wfs_chk_lpstr_frm_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_lpstr_frm_list)
			void WFS2TT(const LPSTR obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->strvecFormList, obj);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_chk_lpstr_frm_list)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_lpstr_frm_list& obj)
		{
			out << " lpszFormList: " << DeviceUtility::STRVECT2Str(obj.strvecFormList).c_str();
			return out;
		}
		DeviceUtility::STRVECT strvecFormList;
	} TTWFSCHKLPSTRFRMLIST, * LPTTWFSCHKLPSTRFRMLIST;

	typedef struct _tt_wfs_chk_lpstr_media_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_lpstr_media_list)
			void WFS2TT(const LPSTR obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->strvecMediaList, obj);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_chk_lpstr_media_list)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_lpstr_media_list& obj)
		{
			out << " lpszMediaList: " << DeviceUtility::STRVECT2Str(obj.strvecMediaList);
			return out;
		}
		DeviceUtility::STRVECT strvecMediaList;
	} TTWFSCHKLPSTRMEDIALIST, * LPTTWFSCHKLPSTRMEDIALIST;

	/*=================================================================*/
	/* CHK Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_chk_in_process_form : public XFS300::_wfs_chk_in_process_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_in_process_form)
		~_tt_wfs_chk_in_process_form()
		{
			SAFEPTR(this->lpWFSCHKINPROCESSFORM)
			{
				SAFEFREEMEMORY(&this->lpWFSCHKINPROCESSFORM->lpszFormName);
				SAFEFREEMEMORY(&this->lpWFSCHKINPROCESSFORM->lpszMediaName);
				SAFEFREEMEMORY(&this->lpWFSCHKINPROCESSFORM->lpszInputFields);
				SAFEFREEMEMORY(&this->lpWFSCHKINPROCESSFORM->lpszOutputFields);
				SAFEFREEMEMORY(&this->lpWFSCHKINPROCESSFORM->lpszUNICODEOutputFields);
				SAFEFREEMEMORY(&this->lpWFSCHKINPROCESSFORM);
			}
		}
		void WFS2TT(const XFS300::_wfs_chk_in_process_form* obj)
		{
			SAFEPTR(obj->lpszFormName)				this->lpszFormName.assign(lpszFormName);
			SAFEPTR(obj->lpszMediaName)				this->lpszMediaName.assign(lpszMediaName);
			SAFEPTR(obj->lpszInputFields)			this->lpszInputFields.assign(lpszInputFields);
			SAFEPTR(obj->lpszOutputFields)			this->lpszOutputFields.assign(lpszOutputFields);
			SAFEPTR(obj->lpszUNICODEOutputFields)	this->lpszUNICODEOutputFields.assign(lpszUNICODEOutputFields);
			this->dwOptions = obj->dwOptions;
		}
		void WFS(XFS300::LPWFSCHKINPROCESSFORM* lppWFSCHKINPROCESSFORM)
		{
			this->lpWFSCHKINPROCESSFORM = new XFS300::WFSCHKINPROCESSFORM;
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKINPROCESSFORM->lpszFormName, this->lpszFormName);
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKINPROCESSFORM->lpszMediaName, this->lpszMediaName);
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKINPROCESSFORM->lpszInputFields, this->lpszInputFields);
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKINPROCESSFORM->lpszOutputFields, this->lpszOutputFields);
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKINPROCESSFORM->lpszUNICODEOutputFields, this->lpszUNICODEOutputFields);
			this->lpWFSCHKINPROCESSFORM->dwOptions	= this->dwOptions;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_in_process_form& obj)
		{
			out << " - "
				<< " lpszFormName: "				<< obj.lpszFormName
				<< " lpszMediaName: "				<< obj.lpszMediaName
				<< " lpszInputFields: "				<< obj.lpszInputFields
				<< " lpszOutputFields: "			<< obj.lpszOutputFields
				<< " lpszUNICODEOutputFields: "		<< MAKESTRING(obj.lpszUNICODEOutputFields)
				<< " dwOptions: "					<< obj.dwOptions;
			return out;
		}
		std::string		lpszFormName;
		std::string		lpszMediaName;
		std::string		lpszInputFields;
		std::string		lpszOutputFields;
		std::wstring	lpszUNICODEOutputFields;
		XFS300::LPWFSCHKINPROCESSFORM lpWFSCHKINPROCESSFORM = nullptr;
	} TTWFSCHKINPROCESSFORM, * LPTTWFSCHKINPROCESSFORM;

	// Needs attention
	typedef struct _tt_wfs_chk_out_process_form : public XFS300::_wfs_chk_out_process_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_chk_out_process_form)
		~_tt_wfs_chk_out_process_form()
		{
			SAFEPTR(this->lpWFSCHKOUTPROCESSFORM)
			{
				SAFERELEASE(&this->lpWFSCHKOUTPROCESSFORM->lpszUNICODEInputFields);
				SAFERELEASE(&this->lpWFSCHKOUTPROCESSFORM);
			}
		}
		void WFS2TT(const XFS300::_wfs_chk_out_process_form* obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->lpszInputFields, obj->lpszInputFields);
			this->lpszUNICODEInputFields.assign(obj->lpszUNICODEInputFields, DeviceUtility::Size_LPWSTR(obj->lpszUNICODEInputFields));
			this->wFrontImageType					= obj->wFrontImageType;
			this->ulFrontImageSize					= obj->ulFrontImageSize;
			this->lpFrontImage						= obj->lpFrontImage;
			this->wBackImageType					= obj->wBackImageType;
			this->ulBackImageSize					= obj->ulBackImageSize;
			this->lpBackImage						= obj->lpBackImage;
		}
		void WFS(XFS300::LPWFSCHKOUTPROCESSFORM* lppWFSCHKOUTPROCESSFORM)
		{
			this->lpWFSCHKOUTPROCESSFORM = new XFS300::WFSCHKOUTPROCESSFORM;
			//DeviceUtility::LPSTRNN2Vector(this->lpszInputFields, this->lpszInputFields);
			SAFEALLOCCOPYSTRING(&this->lpWFSCHKOUTPROCESSFORM->lpszUNICODEInputFields, this->lpszUNICODEInputFields);
			this->lpWFSCHKOUTPROCESSFORM->wFrontImageType					= this->wFrontImageType;
			this->lpWFSCHKOUTPROCESSFORM->ulFrontImageSize					= this->ulFrontImageSize;
			this->lpWFSCHKOUTPROCESSFORM->lpFrontImage						= this->lpFrontImage;
			this->lpWFSCHKOUTPROCESSFORM->wBackImageType					= this->wBackImageType;
			this->lpWFSCHKOUTPROCESSFORM->ulBackImageSize					= this->ulBackImageSize;
			this->lpWFSCHKOUTPROCESSFORM->lpBackImage						= this->lpBackImage;
			*lppWFSCHKOUTPROCESSFORM = this->lpWFSCHKOUTPROCESSFORM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_chk_out_process_form& obj)
		{
			out << " lpszInputFields: "				<< DeviceUtility::STRVECT2Str(obj.lpszInputFields).c_str()
				<< " lpszUNICODEInputFields: "		<< obj.lpszUNICODEInputFields.c_str()
				<< " wFrontImageType: "				<< obj.wFrontImageType
				<< " ulFrontImageSize: "			<< obj.ulFrontImageSize
				<< " lpFrontImage: "				<< obj.lpFrontImage
				<< " wBackImageType: "				<< obj.wBackImageType
				<< " ulBackImageSize: "				<< obj.ulBackImageSize
				<< " lpBackImage: "					<< obj.lpBackImage;
			return out;
		}
		DeviceUtility::STRVECT	lpszInputFields;
		std::wstring			lpszUNICODEInputFields;
		XFS300::LPWFSCHKOUTPROCESSFORM lpWFSCHKOUTPROCESSFORM = nullptr;
	} TTWFSCHKOUTPROCESSFORM, * LPTTWFSCHKOUTPROCESSFORM;

#pragma pack(pop)

	/*=================================================================*/
	/* CAM Interface */
	/*=================================================================*/

	class ITTCHK : public ITTDevice
	{
	public:
		ITTCHK() = default;
		ITTCHK(const ITTCHK&) = delete;
		ITTCHK(ITTCHK&&) = delete;
		ITTCHK& operator = (const ITTCHK&) = delete;
		ITTCHK& operator = (ITTCHK&&) = delete;
		virtual ~ITTCHK() = default;

		/* CHK Info Functions */
		virtual bool GetStatus(LPTTWFSCHKSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSCHKCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetFormList(LPTTWFSCHKLPSTRFRMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetMediaList(LPTTWFSCHKLPSTRMEDIALIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryForm(const LPSTR, LPTTWFSCHKFRMHEADER, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryMedia(const LPSTR, LPTTWFSCHKFRMMEDIA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryField(const LPTTWFSCHKQUERYFIELD, LPTTWFSCHKP2APFRMFIELD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetMediaList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryForm(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryMedia(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryField(const LPTTWFSCHKQUERYFIELD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* CHK Execute Functions */
		virtual bool ProcessForm(const LPTTWFSCHKINPROCESSFORM, LPTTWFSCHKOUTPROCESSFORM, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncProcessForm(const LPTTWFSCHKINPROCESSFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};	
}

#endif // !__H_ITTCHK__