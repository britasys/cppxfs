
#pragma once

#ifndef __H_ITTTTU__
#define __H_ITTTTU__

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* TTU Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_ttu_status : public XFS300::_wfs_ttu_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_status)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_status)
		void WFS2TT(const XFS300::_wfs_ttu_status* obj)
		{
			this->fwDevice								= obj->fwDevice;
			this->wKeyboard								= obj->wKeyboard;
			this->wKeylock								= obj->wKeylock;
			SAFECOPYMEMORY(this->wLEDs, obj->wLEDs, WFS_TTU_LEDS_MAX * sizeof(WORD));
			this->wDisplaySizeX							= obj->wDisplaySizeX;
			this->wDisplaySizeY							= obj->wDisplaySizeY;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_status& obj)
		{
			out << " fwDevice: "						<< obj.fwDevice
				<< " wKeyboard: "						<< obj.wKeyboard
				<< " wKeylock: "						<< obj.wKeylock
				<< " wLEDs: "							<< TTFRMU::Array2Str(obj.wLEDs, WFS_TTU_LEDS_MAX)
				<< " wDisplaySizeX: "					<< obj.wDisplaySizeX
				<< " wDisplaySizeY: "					<< obj.wDisplaySizeY
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSTTUSTATUS, * LPTTWFSTTUSTATUS;

	typedef struct _tt_wfs_ttu_resolution : public XFS300::_wfs_ttu_resolution
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_resolution)
		~_tt_wfs_ttu_resolution() { SAFERELEASE(&this->lpWFSTTURESOLUTION) }
		void WFS2TT(const XFS300::_wfs_ttu_resolution* obj)
		{
			this->wSizeX								= obj->wSizeX;
			this->wSizeY								= obj->wSizeY;
		}
		void WFS(XFS300::LPWFSTTURESOLUTION* lppWFSTTURESOLUTION)
		{
			this->lpWFSTTURESOLUTION = new XFS300::WFSTTURESOLUTION;
			this->lpWFSTTURESOLUTION->wSizeX			= this->wSizeX;
			this->lpWFSTTURESOLUTION->wSizeY			= this->wSizeY;
			*lppWFSTTURESOLUTION = this->lpWFSTTURESOLUTION;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_resolution& obj)
		{
			out << " - "
				<< " wSizeX: "							<< obj.wSizeX
				<< " wSizeX: "							<< obj.wSizeX;
			return out;
		}
		XFS300::LPWFSTTURESOLUTION lpWFSTTURESOLUTION = nullptr;
	} TTWFSTTURESOLUTION, * LPTTWFSTTURESOLUTION;

	typedef struct _tt_wfs_ttu_caps : public XFS300::_wfs_ttu_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_caps)
		~_tt_wfs_ttu_caps() { SAFERELEASECONT(this->lppResolutions) }
		void WFS2TT(const XFS300::_wfs_ttu_caps* obj)
		{
			this->wClass								= obj->wClass;
			this->fwType								= obj->fwType;
			DeviceUtility::CopyP2NAPs(this->lppResolutions, obj->lppResolutions);
			this->wNumOfLEDs							= obj->wNumOfLEDs;
			this->bKeyLock								= obj->bKeyLock;
			this->bDisplayLight							= obj->bDisplayLight;
			this->bCursor								= obj->bCursor;
			this->bForms								= obj->bForms;
			this->fwCharSupport							= obj->fwCharSupport;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_caps& obj)
		{
			out << " wClass: "							<< obj.wClass
				<< " fwType: "							<< obj.fwType
				<< " lppResolutions: "					<< DeviceUtility::TTCONT2Str(obj.lppResolutions).c_str()
				<< " wNumOfLEDs: "						<< obj.wNumOfLEDs
				<< " bKeyLock: "						<< obj.bKeyLock
				<< " bDisplayLight: "					<< obj.bDisplayLight
				<< " bCursor: "							<< obj.bCursor
				<< " bForms: "							<< obj.bForms
				<< " fwCharSupport: "					<< obj.fwCharSupport
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSTTURESOLUTION>		lppResolutions;
		DeviceUtility::STRVECT							lpszExtra;
	} TTWFSTTUCAPS, * LPTTWFSTTUCAPS;

	typedef struct _tt_wfs_ttu_frm_header : public XFS300::_wfs_ttu_frm_header
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_frm_header)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_frm_header)
		void WFS2TT(const XFS300::_wfs_ttu_frm_header* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName, DeviceUtility::Size_LPSTR(obj->lpszFormName));
			this->wWidth								= obj->wWidth;
			this->wHeight								= obj->wHeight;
			this->wVersionMajor 						= obj->wVersionMajor;
			this->wVersionMinor 						= obj->wVersionMinor;
			this->fwCharSupport 						= obj->fwCharSupport;
			DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_frm_header& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " wWidth: "							<< obj.wWidth
				<< " wHeight: "							<< obj.wHeight
				<< " wVersionMajor: "					<< obj.wVersionMajor
				<< " wVersionMinor: "					<< obj.wVersionMinor
				<< " fwCharSupport: "					<< obj.fwCharSupport
				<< " lpszFields: "						<< DeviceUtility::STRVECT2Str(obj.lpszFields).c_str();
			return out;
		}
		DeviceUtility::STRVECT	lpszFields;
		std::string				lpszFormName;
	} TTWFSTTUFRMHEADER, * LPTTWFSTTUFRMHEADER;

	typedef struct _tt_wfs_ttu_query_field : public XFS300::_wfs_ttu_query_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_query_field)
		~_tt_wfs_ttu_query_field()
		{
			SAFEFREEMEMORY(&this->lpWFSTTUQUERYFIELD->lpszFieldName);
			SAFEPTR(this->lpWFSTTUQUERYFIELD)
			{
				SAFEFREEMEMORY(&this->lpWFSTTUQUERYFIELD->lpszFormName);
				SAFERELEASE(&this->lpWFSTTUQUERYFIELD);
			}
		}
		void WFS2TT(const XFS300::_wfs_ttu_query_field* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName, DeviceUtility::Size_LPSTR(obj->lpszFormName));
			this->lpszFieldName.assign(obj->lpszFieldName, DeviceUtility::Size_LPSTR(obj->lpszFieldName));
		}
		void WFS(XFS300::LPWFSTTUQUERYFIELD* lppWFSTTUQUERYFIELD)
		{
			this->lpWFSTTUQUERYFIELD = new XFS300::WFSTTUQUERYFIELD;
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUQUERYFIELD->lpszFieldName, this->lpszFieldName);
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUQUERYFIELD->lpszFormName, this->lpszFormName)
			*lppWFSTTUQUERYFIELD = this->lpWFSTTUQUERYFIELD;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_query_field& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " lpszFieldName: "					<< obj.lpszFieldName.c_str();
			return out;
		}
		std::string lpszFormName;
		std::string lpszFieldName;
		XFS300::LPWFSTTUQUERYFIELD lpWFSTTUQUERYFIELD = nullptr;
	} TTWFSTTUQUERYFIELD, * LPTTWFSTTUQUERYFIELD;

	typedef struct _tt_wfs_ttu_frm_field : public XFS300::_wfs_ttu_frm_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_frm_field)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_frm_field)
		void WFS2TT(const XFS300::_wfs_ttu_frm_field* obj)
		{
			this->lpszFieldName.assign(obj->lpszFieldName, DeviceUtility::Size_LPSTR(obj->lpszFieldName));
			this->fwType								= obj->fwType;
			this->fwClass								= obj->fwClass;
			this->fwAccess								= obj->fwAccess;
			this->fwOverflow							= obj->fwOverflow;
			this->lpszFormat.assign(obj->lpszFormat, DeviceUtility::Size_LPSTR(obj->lpszFormat));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_frm_field& obj)
		{
			out << " - "
				<< " lpszFieldName: "					<< obj.lpszFieldName.c_str()
				<< " fwType: "							<< obj.fwType
				<< " fwClass: "							<< obj.fwClass
				<< " fwAccess: "						<< obj.fwAccess
				<< " fwOverflow: "						<< obj.fwOverflow
				<< " lpszFormat: "						<< obj.lpszFormat.c_str();
			return out;
		}
		std::string lpszFieldName;
		std::string lpszFormat;
	} TTWFSTTUFRMFIELD, * LPTTWFSTTUFRMFIELD;

	typedef struct _tt_wfs_ttu_p2ap_fields
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_p2ap_fields)
		~_tt_wfs_ttu_p2ap_fields() { SAFERELEASECONT(this->listFields) }
		void WFS2TT(const XFS300::_wfs_ttu_frm_field* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listFields, (XFS300::_wfs_ttu_frm_field**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_p2ap_fields& obj)
		{
			out << " Fields: "							<< DeviceUtility::TTCONT2Str(obj.listFields).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSTTUFRMFIELD>listFields;
	} TTWFSTTUP2APFIELDS, * LPTTWFSTTUP2APFIELDS;

	typedef struct _tt_wfs_ttu_key_detail : public XFS300::_wfs_ttu_key_detail
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_key_detail)
		~_tt_wfs_ttu_key_detail() { SAFEFREEMEMORY(&this->lpwCommandKeys); }
		void WFS2TT(const XFS300::_wfs_ttu_key_detail* obj)
		{
			this->lpszKeys.assign(obj->lpszKeys, DeviceUtility::Size_LPSTR(obj->lpszKeys));
			this->lpwszUNICODEKeys.assign(obj->lpwszUNICODEKeys, DeviceUtility::Size_LPWSTR(obj->lpwszUNICODEKeys));
			SAFEALLOCCOPYMEMORY(&this->lpwCommandKeys, obj->lpwCommandKeys, DeviceUtility::Size_P2NA(obj->lpwCommandKeys));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_key_detail& obj)
		{
			out << " lpszKeys: "						<< obj.lpszKeys.c_str()
				<< " lpwszUNICODEKeys: "				<< obj.lpwszUNICODEKeys.c_str()
				<< " lpwCommandKeys: "					<< TTFRMU::Array2Str(obj.lpwCommandKeys, DeviceUtility::Size_P2NA(obj.lpwCommandKeys));
			return out;
		}
		std::string lpszKeys;
		std::wstring lpwszUNICODEKeys;
	} TTWFSTTUKEYDETAIL, * LPTTWFSTTUKEYDETAIL;

	typedef struct _tt_wfs_ttu_lpstr_frm_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_lpstr_frm_list)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_lpstr_frm_list)
		void WFS2TT(const LPSTR obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->strvecFormList, obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_lpstr_frm_list& obj)
		{
			out << " lpszFormList: "					<< DeviceUtility::STRVECT2Str(obj.strvecFormList);
			return out;
		}
		DeviceUtility::STRVECT strvecFormList;
	} TTWFSTTULPSTRFRMLIST, * LPTTWFSTTULPSTRFRMLIST;

	/*=================================================================*/
	/* TTU Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_ttu_clear_screen : public XFS300::_wfs_ttu_clear_screen
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_clear_screen)
		~_tt_wfs_ttu_clear_screen() { SAFEFREEMEMORY(&this->lpWFSTTUCLEARSCREEN) }
		void WFS2TT(const _wfs_ttu_clear_screen* obj)
		{
			this->wPositionX							= obj->wPositionX;
			this->wPositionY							= obj->wPositionY;
			this->wWidth								= obj->wWidth;
			this->wHeight								= obj->wHeight;
		}
		void WFS(XFS300::LPWFSTTUCLEARSCREEN* lppWFSTTUCLEARSCREEN)
		{
			this->lpWFSTTUCLEARSCREEN = new XFS300::WFSTTUCLEARSCREEN;
			this->lpWFSTTUCLEARSCREEN->wPositionX		= this->wPositionX;
			this->lpWFSTTUCLEARSCREEN->wPositionY		= this->wPositionY;
			this->lpWFSTTUCLEARSCREEN->wWidth			= this->wWidth;
			this->lpWFSTTUCLEARSCREEN->wHeight			= this->wHeight;
			*lppWFSTTUCLEARSCREEN = this->lpWFSTTUCLEARSCREEN;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_clear_screen& obj)
		{
			out << " wPositionX: "						<< obj.wPositionX
				<< " wPositionY: "						<< obj.wPositionY
				<< " wWidth: "							<< obj.wWidth
				<< " wHeight: "							<< obj.wHeight;
			return out;
		}
		XFS300::LPWFSTTUCLEARSCREEN lpWFSTTUCLEARSCREEN = nullptr;
	} TTWFSTTUCLEARSCREEN, * LPTTWFSTTUCLEARSCREEN;

	typedef struct _tt_wfs_ttu_disp_light : public XFS300::_wfs_ttu_disp_light
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_disp_light)
		~_tt_wfs_ttu_disp_light() { SAFERELEASE(&this->lpWFSTTUDISPLIGHT) }
		void WFS2TT(const _wfs_ttu_disp_light* obj)
		{
			this->bMode									= obj->bMode;
		}
		void WFS(XFS300::LPWFSTTUDISPLIGHT* lppWFSTTUDISPLIGHT)
		{
			this->lpWFSTTUDISPLIGHT = new XFS300::WFSTTUDISPLIGHT;
			this->lpWFSTTUDISPLIGHT->bMode		= this->bMode;
			*lppWFSTTUDISPLIGHT = this->lpWFSTTUDISPLIGHT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_disp_light& obj)
		{
			out << " bMode: "							<< obj.bMode;
			return out;
		}
		XFS300::LPWFSTTUDISPLIGHT lpWFSTTUDISPLIGHT = nullptr;
	} TTWFSTTUDISPLIGHT, * LPTTWFSTTUDISPLIGHT;

	typedef struct _tt_wfs_ttu_set_leds : public XFS300::_wfs_ttu_set_leds
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_set_leds)
		~_tt_wfs_ttu_set_leds() { SAFERELEASE(&this->lpWFSTTUSETLEDS) }
		void WFS2TT(const _wfs_ttu_set_leds* obj)
		{
			this->wLED									= obj->wLED;
			this->fwCommand								= obj->fwCommand;
		}
		void WFS(XFS300::LPWFSTTUSETLEDS* lppWFSTTUSETLEDS)
		{
			this->lpWFSTTUSETLEDS = new XFS300::WFSTTUSETLEDS;
			this->lpWFSTTUSETLEDS->wLED					= this->wLED;
			this->lpWFSTTUSETLEDS->fwCommand			= this->fwCommand;
			*lppWFSTTUSETLEDS = this->lpWFSTTUSETLEDS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_set_leds& obj)
		{
			out << " wLED: "							<< obj.wLED
				<< " fwCommand: "						<< obj.fwCommand;
			return out;
		}
		XFS300::LPWFSTTUSETLEDS lpWFSTTUSETLEDS = nullptr;
	} TTWFSTTUSETLEDS, * LPTTWFSTTUSETLEDS;

	typedef struct _tt_wfs_ttu_write_form : public XFS300::_wfs_ttu_write_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_write_form)
		~_tt_wfs_ttu_write_form()
		{
			SAFEPTR(this->lpWFSTTUWRITEFORM)
			{
				SAFEFREEMEMORY(&this->lpWFSTTUWRITEFORM->lpszFormName);
				SAFEFREEMEMORY(&this->lpWFSTTUWRITEFORM->lpszFields);
				SAFEFREEMEMORY(&this->lpWFSTTUWRITEFORM->lpszUNICODEFields);
				SAFERELEASE(&this->lpWFSTTUWRITEFORM);
			}
		}
		void WFS2TT(const _wfs_ttu_write_form* obj)
		{
			SAFEPTR(obj->lpszFormName)
				this->lpszFormName.assign(obj->lpszFormName);
			this->bClearScreen							= obj->bClearScreen;
			SAFEPTR(obj->lpszFields)
				DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
			lpszUNICODEFields.clear();
		}
		void WFS(XFS300::LPWFSTTUWRITEFORM* lppWFSTTUWRITEFORM)
		{
			this->lpWFSTTUWRITEFORM = new XFS300::WFSTTUWRITEFORM;
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUWRITEFORM->lpszFormName, this->lpszFormName);
			this->lpWFSTTUWRITEFORM->bClearScreen		= this->bClearScreen;
			DeviceUtility::STRVECT2LPSTRNN(&this->lpWFSTTUWRITEFORM->lpszFields, this->lpszFields);
			//DeviceUtility::STRVECT2LPSTRNN(&this->lpWFSTTUWRITEFORM->lpszUNICODEFields, this->lpszUNICODEFields);
			*lppWFSTTUWRITEFORM = this->lpWFSTTUWRITEFORM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_write_form& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " bClearScreen: "					<< obj.bClearScreen
				<< " lpszFields: "						<< DeviceUtility::STRVECT2Str(obj.lpszFields).c_str()
				<< " lpszUNICODEFields: "				<< DeviceUtility::STRVECT2Str(obj.lpszUNICODEFields).c_str();
			return out;
		}
		std::string lpszFormName;
		DeviceUtility::STRVECT lpszFields;
		DeviceUtility::STRVECT lpszUNICODEFields;
		XFS300::LPWFSTTUWRITEFORM lpWFSTTUWRITEFORM = nullptr;
	} TTWFSTTUWRITEFORM, * LPTTWFSTTUWRITEFORM;

	typedef struct _tt_wfs_ttu_read_form : public XFS300::_wfs_ttu_read_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_read_form)
		~_tt_wfs_ttu_read_form()
		{
			SAFEPTR(this->lpWFSTTUREADFORM)
			{
				SAFEFREEMEMORY(&this->lpWFSTTUREADFORM->lpszFormName);
				SAFEFREEMEMORY(&this->lpWFSTTUREADFORM->lpszFieldNames);
				SAFERELEASE(&this->lpWFSTTUREADFORM);
			}
		}
		void WFS2TT(const _wfs_ttu_read_form* obj)
		{
			SAFEPTR(obj->lpszFormName)
				this->lpszFormName.assign(obj->lpszFormName);
			SAFEPTR(obj->lpszFieldNames)
				DeviceUtility::LPSTRNN2Vector(this->lpszFieldNames, obj->lpszFieldNames);
		}
		void WFS(XFS300::LPWFSTTUREADFORM* lppWFSTTUREADFORM)
		{
			this->lpWFSTTUREADFORM = new XFS300::WFSTTUREADFORM;
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUREADFORM->lpszFieldNames, this->lpszFormName);
			DeviceUtility::STRVECT2LPSTRNN(&this->lpWFSTTUREADFORM->lpszFieldNames, this->lpszFieldNames);
			*lppWFSTTUREADFORM = this->lpWFSTTUREADFORM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_read_form& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " lpszFieldNames: "					<< DeviceUtility::STRVECT2Str(obj.lpszFieldNames).c_str();
			return out;
		}
		std::string lpszFormName;
		DeviceUtility::STRVECT lpszFieldNames;
		XFS300::LPWFSTTUREADFORM lpWFSTTUREADFORM = nullptr;
	} TTWFSTTUREADFORM, * LPTTWFSTTUREADFORM;

	typedef struct _tt_wfs_ttu_read_form_out : public XFS300:: _wfs_ttu_read_form_out
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_read_form_out)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_read_form_out)
		void WFS2TT(const _wfs_ttu_read_form_out* obj)
		{
			SAFEPTR(obj->lpszFields)
				DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
			lpszUNICODEFields.clear();
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_read_form_out& obj)
		{
			out << " lpszFields: "						<< DeviceUtility::STRVECT2Str(obj.lpszFields).c_str()
				<< " lpszUNICODEFields: "				<< DeviceUtility::STRVECT2Str(obj.lpszUNICODEFields).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszFields;
		DeviceUtility::STRVECT lpszUNICODEFields;
	} TTWFSTTUREADFORMOUT, * LPTTWFSTTUREADFORMOUT;

	typedef struct _tt_wfs_ttu_write : public XFS300::_wfs_ttu_write
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_write)
		~_tt_wfs_ttu_write()
		{
			SAFEPTR(this->lpWFSTTUWRITE)
			{
				SAFEFREEMEMORY(&this->lpWFSTTUWRITE->lpsText);
				SAFEFREEMEMORY(&this->lpWFSTTUWRITE->lpsUNICODEText);
				SAFERELEASE(&this->lpWFSTTUWRITE);
			}
		}
		void WFS2TT(const _wfs_ttu_write* obj)
		{
			this->fwMode								= obj->fwMode;
			this->wPosX									= obj->wPosX;
			this->wPosY									= obj->wPosY;
			this->fwTextAttr							= obj->fwTextAttr;
			SAFEPTR(obj->lpsText)
				this->lpsText.assign(obj->lpsText);
			SAFEPTR(obj->lpsUNICODEText)
				this->lpsUNICODEText.assign(obj->lpsUNICODEText);
		}
		void WFS(XFS300::LPWFSTTUWRITE* lppWFSTTUWRITE)
		{
			this->lpWFSTTUWRITE = new XFS300::WFSTTUWRITE;
			this->lpWFSTTUWRITE->fwMode					= this->fwMode;
			this->lpWFSTTUWRITE->wPosX					= this->wPosX;
			this->lpWFSTTUWRITE->wPosY					= this->wPosY;
			this->lpWFSTTUWRITE->fwTextAttr				= this->fwTextAttr;
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUWRITE->lpsText, this->lpsText);
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUWRITE->lpsUNICODEText, this->lpsUNICODEText);
			*lppWFSTTUWRITE = this->lpWFSTTUWRITE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_write& obj)
		{
			out << " fwMode: "							<< obj.fwMode
				<< " wPosX: "							<< obj.wPosX
				<< " wPosY: "							<< obj.wPosY
				<< " fwTextAttr: "						<< obj.fwTextAttr
				<< " lpsText: "							<< obj.lpsText.c_str()
				<< " lpsUNICODEText: "					<< obj.lpsUNICODEText.c_str();
			return out;
		}
		std::string		lpsText;
		std::wstring	lpsUNICODEText;
		XFS300::LPWFSTTUWRITE lpWFSTTUWRITE = nullptr;
	} TTWFSTTUWRITE, * LPTTWFSTTUWRITE;

	typedef struct _tt_wfs_ttu_read : public XFS300::_wfs_ttu_read
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_read)
		~_tt_wfs_ttu_read()
		{
			SAFEPTR(this->lpWFSTTUREAD)
			{
				SAFEFREEMEMORY(&this->lpWFSTTUREAD->lpszActiveKeys);
				SAFEFREEMEMORY(&this->lpWFSTTUREAD->lpwActiveCommandKeys);
				SAFEFREEMEMORY(&this->lpWFSTTUREAD->lpwTerminateCommandKeys);
				SAFERELEASE(&this->lpWFSTTUREAD);
			}
		}
		void WFS2TT(const _wfs_ttu_read* obj)
		{
			this->wNumOfChars							= obj->wNumOfChars;
			this->fwMode								= obj->fwMode;
			this->wPosX									= obj->wPosX;
			this->wPosY									= obj->wPosY;
			this->fwEchoMode							= obj->fwEchoMode;
			this->fwEchoAttr							= obj->fwEchoAttr;
			this->bCursor								= obj->bCursor;
			this->bFlush								= obj->bFlush;
			this->bAutoEnd								= obj->bAutoEnd;
			SAFEPTR(obj->lpszActiveKeys)
				this->lpszActiveKeys.assign(obj->lpszActiveKeys);
			SAFEPTR(obj->lpwszActiveUNICODEKeys)
				this->lpwszActiveUNICODEKeys.assign(obj->lpwszActiveUNICODEKeys);
			SAFEALLOCCOPYMEMORY_N(&this->lpwActiveCommandKeys, obj->lpwActiveCommandKeys, TTFRMU::Size_ARRAY_N(obj->lpwActiveCommandKeys) * sizeof(WORD)); 
			SAFEALLOCCOPYMEMORY_N(&this->lpwTerminateCommandKeys, obj->lpwTerminateCommandKeys, TTFRMU::Size_ARRAY_N(obj->lpwTerminateCommandKeys) * sizeof(WORD));
		}
		void WFS(XFS300::LPWFSTTUREAD* lppWFSTTUREAD)
		{
			this->lpWFSTTUREAD = new XFS300::WFSTTUREAD;
			this->lpWFSTTUREAD->wNumOfChars				= this->wNumOfChars;
			this->lpWFSTTUREAD->fwMode					= this->fwMode;
			this->lpWFSTTUREAD->wPosX					= this->wPosX;
			this->lpWFSTTUREAD->wPosY					= this->wPosY;
			this->lpWFSTTUREAD->fwEchoMode				= this->fwEchoMode;
			this->lpWFSTTUREAD->fwEchoAttr				= this->fwEchoAttr;
			this->lpWFSTTUREAD->bCursor					= this->bCursor;
			this->lpWFSTTUREAD->bFlush					= this->bFlush;
			this->lpWFSTTUREAD->bAutoEnd				= this->bAutoEnd;
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUREAD->lpszActiveKeys, this->lpszActiveKeys);
			SAFEALLOCCOPYSTRING(&this->lpWFSTTUREAD->lpwszActiveUNICODEKeys, this->lpwszActiveUNICODEKeys);
			SAFEALLOCCOPYMEMORY_N(&this->lpWFSTTUREAD->lpwActiveCommandKeys, this->lpwActiveCommandKeys, TTFRMU::Size_ARRAY_N(this->lpwActiveCommandKeys) * sizeof(WORD));
			SAFEALLOCCOPYMEMORY_N(&this->lpWFSTTUREAD->lpwTerminateCommandKeys, this->lpwTerminateCommandKeys, TTFRMU::Size_ARRAY_N(this->lpwTerminateCommandKeys) * sizeof(WORD));
			*lppWFSTTUREAD = this->lpWFSTTUREAD;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_read& obj)
		{
			out << " wNumOfChars: "						<< obj.wNumOfChars
				<< " fwMode: "							<< obj.fwMode
				<< " wPosX: "							<< obj.wPosX
				<< " wPosY: "							<< obj.wPosY
				<< " fwEchoMode: "						<< obj.fwEchoMode
				<< " fwEchoAttr: "						<< obj.fwEchoAttr
				<< " bCursor: "							<< obj.bCursor
				<< " bFlush: "							<< obj.bFlush
				<< " bAutoEnd: "						<< obj.bAutoEnd
				<< " lpszActiveKeys: "					<< obj.lpszActiveKeys
				<< " lpwszActiveUNICODEKeys: "			<< std::string{ obj.lpwszActiveUNICODEKeys.begin(), obj.lpwszActiveUNICODEKeys.end() }
				<< " lpwActiveCommandKeys: "			<< TTFRMU::Array2Str(obj.lpwActiveCommandKeys, TTFRMU::Size_ARRAY_N(obj.lpwActiveCommandKeys))
				<< " lpwTerminateCommandKeys: "			<< TTFRMU::Array2Str(obj.lpwTerminateCommandKeys, TTFRMU::Size_ARRAY_N(obj.lpwTerminateCommandKeys));
			return out;
		}
		std::string				lpszActiveKeys;
		std::wstring			lpwszActiveUNICODEKeys;
		XFS300::LPWFSTTUREAD	lpWFSTTUREAD = nullptr;
	} TTWFSTTUREAD, * LPTTWFSTTUREAD;

	typedef struct _tt_wfs_ttu_read_in : public XFS300::_wfs_ttu_read_in
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_read_in)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_read_in)
		void WFS2TT(const XFS300::_wfs_ttu_read_in* obj)
		{
			this->lpszInput.assign(obj->lpszInput, DeviceUtility::Size_LPSTR(obj->lpszInput));
			this->lpszUNICODEInput.assign(obj->lpszUNICODEInput, DeviceUtility::Size_LPWSTR(obj->lpszUNICODEInput));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_read_in& obj)
		{
			out << " lpszInput: "						<< obj.lpszInput.c_str();
			out << " lpszUNICODEInput: "				<< obj.lpszUNICODEInput.c_str();
			return out;
		}
		std::string	lpszInput;
		std::wstring lpszUNICODEInput;
	} TTWFSTTUREADIN, * LPTTWFSTTUREADIN;

	/*=================================================================*/
	/* TTU Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_ttu_field_failure : public XFS300::_wfs_ttu_field_failure
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_field_failure)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_field_failure)
		void WFS2TT(const _wfs_ttu_field_failure* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName);
			this->lpszFieldName.assign(obj->lpszFieldName);
			this->wFailure = obj->wFailure;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_field_failure& obj)
		{
			out << " lpszFormName: "		<< obj.lpszFormName.c_str()
				<< " lpszFieldName: "		<< obj.lpszFieldName.c_str()
				<< " wFailure: "			<< obj.wFailure;
			return out;
		}
		std::string lpszFormName;
		std::string lpszFieldName;
	} TTWFSTTUFIELDFAIL, * LPTTWFSTTUFIELDFAIL;

	typedef struct _tt_wfs_ttu_key : public XFS300::_wfs_ttu_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ttu_key)
		DEFAULTDESTRUCTOR(_tt_wfs_ttu_key)
		void WFS2TT(const _wfs_ttu_key* obj)
		{
			this->cKey						= obj->cKey;
			this->wUNICODEKey				= obj->wUNICODEKey;
			this->wCommandKey				= obj->wCommandKey;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ttu_key& obj)
		{
			out << " cKey: "				<< obj.cKey
				<< " wUNICODEKey: "			<< obj.wUNICODEKey
				<< " wCommandKey: "			<< obj.wCommandKey;
			return out;
		}
	} TTWFSTTUKEY, * LPTTWFSTTUKEY;

#pragma pack(pop)

	/*=================================================================*/
	/* TTU Interface */
	/*=================================================================*/

	class ITTTTU : public ITTDevice
	{
	public:
		ITTTTU() = default;
		ITTTTU(const ITTTTU&) = delete;
		ITTTTU(ITTTTU&&) = delete;
		ITTTTU& operator = (const ITTTTU&) = delete;
		ITTTTU& operator =(ITTTTU&&) = delete;
		virtual ~ITTTTU() = default;

		/* TTU Info Functions */
		virtual bool GetStatus(LPTTWFSTTUSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSTTUCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetFormList(LPTTWFSTTULPSTRFRMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryForm(const LPSTR, LPTTWFSTTUFRMHEADER, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryField(const LPTTWFSTTUQUERYFIELD, LPTTWFSTTUP2APFIELDS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetKeyDetail(LPTTWFSTTUKEYDETAIL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryForm(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryField(const LPTTWFSTTUQUERYFIELD lpQueryField, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetKeyDetail(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* TTU Execute Functions */
		virtual bool Beep(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ClearScreen(const LPTTWFSTTUCLEARSCREEN, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool DispLight(const LPTTWFSTTUDISPLIGHT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetLED(const LPTTWFSTTUSETLEDS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetResolution(const LPTTWFSTTURESOLUTION, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool WriteForm(const LPTTWFSTTUWRITEFORM, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ReadForm(const LPTTWFSTTUREADFORM, LPTTWFSTTUREADFORMOUT lpReadFormOut, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Write(const LPTTWFSTTUWRITE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Read(const LPTTWFSTTUREAD, LPTTWFSTTUREADIN, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncBeep(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncClearScreen(const LPTTWFSTTUCLEARSCREEN, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDispLight(const LPTTWFSTTUDISPLIGHT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetLED(const LPTTWFSTTUSETLEDS, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetResolution(const LPTTWFSTTURESOLUTION, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncWriteForm(const LPTTWFSTTUWRITEFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReadForm(const LPTTWFSTTUREADFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncWrite(const LPTTWFSTTUWRITE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRead(const LPTTWFSTTUREAD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTTTU__
