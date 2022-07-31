
#pragma once

#ifndef __H_ITTPTR__
#define __H_ITTPTR__

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* PTR Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_ptr_retract_bins : public XFS300::_wfs_ptr_retract_bins
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_retract_bins)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_retract_bins)
		void WFS2TT(const XFS300::_wfs_ptr_retract_bins* obj)
		{
			this->wRetractBin							= obj->wRetractBin;
			this->usRetractCount						= obj->usRetractCount;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_retract_bins& obj)
		{
			out << " - "
				<< " wRetractBin: "						<< obj.wRetractBin
				<< " usRetractCount: "					<< obj.usRetractCount;
			return out;
		}
		std::string MakeString()
		{
			std::ostringstream str;
			str << " - "
				<< " wRetractBin: "						<< this->wRetractBin
				<< " usRetractCount: "					<< this->usRetractCount;
			return str.str();
		}
	} TTWFSPTRRETRACTBINS, * LPTTWFSPTRRETRACTBINS;

	typedef struct _tt_wfs_ptr_status : public XFS300::_wfs_ptr_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_status)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_status)
		void WFS2TT(const XFS300::_wfs_ptr_status* obj)
		{
			this->fwDevice								= obj->fwDevice;
			this->fwMedia								= obj->fwMedia;
			SAFECOPYMEMORY(this->fwPaper, obj->fwPaper, WFS_PTR_SUPPLYSIZE * 2);
			this->fwToner								= obj->fwToner;
			this->fwInk									= obj->fwInk;
			this->fwLamp								= obj->fwLamp;
			DeviceUtility::CopyP2NAPs(this->lppRetractBins, obj->lppRetractBins);
			this->usMediaOnStacker						= obj->usMediaOnStacker;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_status& obj)
		{
			out << " fwDevice: "						<< obj.fwDevice
				<< " fwMedia: "							<< obj.fwMedia
				<< " fwPaper: "							<< TTFRMU::Array2Str(obj.fwPaper, WFS_PTR_SUPPLYSIZE)
				<< " fwToner: "							<< obj.fwToner
				<< " fwInk: "							<< obj.fwInk
				<< " fwLamp: "							<< obj.fwLamp
				<< " lppRetractBins: ";

			for (auto elem : obj.lppRetractBins)
				out << std::endl << elem;

			out << " usMediaOnStacker: "				<< obj.usMediaOnStacker;
			out << " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra);

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSPTRRETRACTBINS>	lppRetractBins;
		DeviceUtility::STRVECT							lpszExtra;
	} TTWFSPTRSTATUS, * LPTTWFSPTRSTATUS;

	typedef struct _tt_wfs_ptr_caps : public XFS300::_wfs_ptr_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_caps)
		void WFS2TT(const XFS300::_wfs_ptr_caps* obj)
		{
			this->wClass								= obj->wClass;
			this->fwType								= obj->fwType;
			this->bCompound								= obj->bCompound;
			this->wResolution							= obj->wResolution;
			this->fwReadForm							= obj->fwReadForm;
			this->fwWriteForm							= obj->fwWriteForm;
			this->fwExtents								= obj->fwExtents;
			this->fwControl								= obj->fwControl;
			this->usMaxMediaOnStacker					= obj->usMaxMediaOnStacker;
			this->bAcceptMedia							= obj->bAcceptMedia;
			this->bMultiPage							= obj->bMultiPage;
			this->fwPaperSources						= obj->fwPaperSources;
			this->bMediaTaken							= obj->bMediaTaken;
			this->usRetractBins							= obj->usRetractBins;
			SAFECOPYMEMORY(this->lpusMaxRetract, obj->lpusMaxRetract, sizeof(USHORT) * obj->usRetractBins);
			this->fwImageType							= obj->fwImageType;
			this->fwFrontImageColorFormat				= obj->fwFrontImageColorFormat;
			this->fwBackImageColorFormat				= obj->fwBackImageColorFormat;
			this->fwCodelineFormat						= obj->fwCodelineFormat;
			this->fwImageSource							= obj->fwImageSource;
			this->fwCharSupport							= obj->fwCharSupport;
			this->bDispensePaper						= obj->bDispensePaper;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_caps& obj)
		{
			out << " wClass: "							<< obj.wClass
				<< " fwType: "							<< obj.fwType
				<< " bCompound: "						<< obj.bCompound
				<< " wResolution: "						<< obj.wResolution
				<< " fwReadForm: "						<< obj.fwReadForm
				<< " fwWriteForm: "						<< obj.fwWriteForm
				<< " fwExtents: "						<< obj.fwExtents
				<< " fwControl: "						<< obj.fwControl
				<< " usMaxMediaOnStacker: " 			<< obj.usMaxMediaOnStacker
				<< " bAcceptMedia: "					<< obj.bAcceptMedia
				<< " bMultiPage: "						<< obj.bMultiPage
				<< " fwPaperSources: "					<< obj.fwPaperSources
				<< " bMediaTaken: "						<< obj.bMediaTaken
				<< " usRetractBins: "					<< obj.usRetractBins
				<< " lpusMaxRetract: "					<< TTFRMU::Vect2Str(obj.lpusMaxRetract)
				<< " fwImageType: "						<< obj.fwImageType
				<< " fwFrontImageColorFormat: "			<< obj.fwFrontImageColorFormat
				<< " fwBackImageColorFormat: "			<< obj.fwBackImageColorFormat
				<< " fwCodelineFormat: "				<< obj.fwCodelineFormat
				<< " fwImageSource: "					<< obj.fwImageSource
				<< " fwCharSupport: "					<< obj.fwCharSupport
				<< " bDispensePaper: "					<< obj.bDispensePaper
				<< " lpszExtra: "						<< DeviceUtility::STRVECT2Str(obj.lpszExtra);
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
		std::vector<USHORT>lpusMaxRetract;
	} TTWFSPTRCAPS, * LPTTWFSPTRCAPS;

	typedef struct _tt_wfs_frm_header : public XFS300::_wfs_frm_header
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_frm_header)
		DEFAULTDESTRUCTOR(_tt_wfs_frm_header)
		void WFS2TT(const XFS300::_wfs_frm_header* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName);
			this->wBase									= obj->wBase;
			this->wUnitX								= obj->wUnitX;
			this->wUnitY								= obj->wUnitY;
			this->wWidth								= obj->wWidth;
			this->wHeight								= obj->wHeight;
			this->wAlignment							= obj->wAlignment;
			this->wOrientation							= obj->wOrientation;
			this->wOffsetX								= obj->wOffsetX;
			this->wOffsetY								= obj->wOffsetY;
			this->wVersionMajor							= obj->wVersionMajor;
			this->wVersionMinor							= obj->wVersionMinor;
			this->lpszUserPrompt.assign(obj->lpszUserPrompt);
			this->fwCharSupport					= obj->fwCharSupport;
			DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_frm_header& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " wUnitX: "							<< obj.wUnitX
				<< " wUnitY: "							<< obj.wUnitY
				<< " wWidth: "							<< obj.wWidth
				<< " wHeight: "							<< obj.wHeight
				<< " wAlignment: "						<< obj.wAlignment
				<< " wOrientation: "					<< obj.wOrientation
				<< " wOffsetX: "						<< obj.wOffsetX
				<< " wOffsetY: "						<< obj.wOffsetY
				<< " wVersionMajor: "					<< obj.wVersionMajor
				<< " wVersionMinor: "					<< obj.wVersionMinor
				<< " lpszUserPrompt: "					<< obj.lpszUserPrompt.c_str()
				<< " fwCharSupport: "					<< obj.fwCharSupport
				<< " lpszFields: "						<< DeviceUtility::STRVECT2Str(obj.lpszFields);
			return out;
		}
		DeviceUtility::STRVECT	lpszFields;
		std::string				lpszFormName;
		std::string				lpszUserPrompt;
	} TTWFSFRMHEADER, * LPTTWFSFRMHEADER;

	typedef struct _tt_wfs_frm_media : public XFS300::_wfs_frm_media
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_frm_media)
		DEFAULTDESTRUCTOR(_tt_wfs_frm_media)
		void WFS2TT(const XFS300::_wfs_frm_media* obj)
		{
			this->fwMediaType							= obj->fwMediaType;
			this->wBase									= obj->wBase;
			this->wUnitX								= obj->wUnitX;
			this->wUnitY								= obj->wUnitY;
			this->wSizeWidth							= obj->wSizeWidth;
			this->wSizeHeight							= obj->wSizeHeight;
			this->wPageCount							= obj->wPageCount;
			this->wLineCount							= obj->wLineCount;
			this->wPrintAreaX							= obj->wPrintAreaX;
			this->wPrintAreaY							= obj->wPrintAreaY;
			this->wPrintAreaWidth						= obj->wPrintAreaWidth;
			this->wPrintAreaHeight						= obj->wPrintAreaHeight;
			this->wRestrictedAreaX						= obj->wRestrictedAreaX;
			this->wRestrictedAreaY						= obj->wRestrictedAreaY;
			this->wRestrictedAreaWidth					= obj->wRestrictedAreaWidth;
			this->wRestrictedAreaHeight					= obj->wRestrictedAreaHeight;
			this->wStagger								= obj->wStagger;
			this->wFoldType								= obj->wFoldType;
			this->wPaperSources							= obj->wPaperSources;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_frm_media& obj)
		{
			out << " fwMediaType: "						<< obj.fwMediaType
				<< " wBase: "							<< obj.wBase
				<< " wUnitX: "							<< obj.wUnitX
				<< " wUnitY: "							<< obj.wUnitY
				<< " wSizeWidth: "						<< obj.wSizeWidth
				<< " wSizeHeight: "						<< obj.wSizeHeight
				<< " wPageCount: "						<< obj.wPageCount
				<< " wLineCount: "						<< obj.wLineCount
				<< " wPrintAreaX: "						<< obj.wPrintAreaX
				<< " wPrintAreaY: "						<< obj.wPrintAreaY
				<< " wPrintAreaWidth: "					<< obj.wPrintAreaWidth
				<< " wPrintAreaHeight: "				<< obj.wPrintAreaHeight
				<< " wRestrictedAreaX: "				<< obj.wRestrictedAreaX
				<< " wRestrictedAreaY: "				<< obj.wRestrictedAreaY
				<< " wRestrictedAreaWidth: "			<< obj.wRestrictedAreaWidth
				<< " wRestrictedAreaHeight: "			<< obj.wRestrictedAreaHeight
				<< " wStagger: "						<< obj.wStagger
				<< " wFoldType: "						<< obj.wFoldType
				<< " wPaperSources: "					<< obj.wPaperSources;
			return out;
		}
	} TTWFSFRMMEDIA, * LPTTWFSFRMMEDIA;

	typedef struct _tt_wfs_ptr_query_field : public XFS300::_wfs_ptr_query_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_query_field)
		~_tt_wfs_ptr_query_field()
		{
			SAFEPTR(this->lpWFSPTRQUERYFIELD)
			{
				SAFEFREEMEMORY(&this->lpWFSPTRQUERYFIELD->lpszFormName);
				SAFEFREEMEMORY(&this->lpWFSPTRQUERYFIELD->lpszFieldName);
				SAFERELEASE(&this->lpWFSPTRQUERYFIELD);
			}
		}
		void WFS2TT(const XFS300::_wfs_ptr_query_field* obj)
		{
			SAFEPTR(obj->lpszFormName)
				lpszFormName.assign(obj->lpszFormName);
			SAFEPTR(obj->lpszFieldName)
				lpszFormName.assign(obj->lpszFieldName);
		}
		void WFS(XFS300::LPWFSPTRQUERYFIELD* lppWFSPTRQUERYFIELD)
		{
			this->lpWFSPTRQUERYFIELD = new XFS300::WFSPTRQUERYFIELD;
			SAFEALLOCCOPYSTRING(&this->lpWFSPTRQUERYFIELD->lpszFormName, this->lpszFormName);
			SAFEALLOCCOPYSTRING(&this->lpWFSPTRQUERYFIELD->lpszFieldName, this->lpszFieldName);
			*lppWFSPTRQUERYFIELD = this->lpWFSPTRQUERYFIELD;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_query_field& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " lpszFieldName: "					<< obj.lpszFieldName.c_str();
			return out;
		}
		std::string lpszFormName{};
		std::string lpszFieldName{};
		XFS300::LPWFSPTRQUERYFIELD lpWFSPTRQUERYFIELD = nullptr;
	} TTWFSPTRQUERYFIELD, * LPTTWFSPTRQUERYFIELD;

	typedef struct _tt_wfs_frm_field : public XFS300::_wfs_frm_field
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_frm_field)
		DEFAULTDESTRUCTOR(_tt_wfs_frm_field)
		void WFS2TT(const XFS300::_wfs_frm_field* obj)
		{
			lpszFieldName.assign(obj->lpszFieldName);
			this->wIndexCount							= obj->wIndexCount;
			this->fwType								= obj->fwType;
			this->fwClass								= obj->fwClass;
			this->fwAccess								= obj->fwAccess;
			this->fwOverflow							= obj->fwOverflow;
			lpszInitialValue.assign(obj->lpszInitialValue);
			std::wstring _wstrUNICODEInitialValue(obj->lpszUNICODEInitialValue);
			lpszUNICODEInitialValue.assign(_wstrUNICODEInitialValue.begin(), _wstrUNICODEInitialValue.end());
			lpszFormat.assign(obj->lpszFormat);
			std::wstring _wstrUNICODEFormat(obj->lpszUNICODEFormat);
			lpszUNICODEFormat.assign(_wstrUNICODEFormat.begin(), _wstrUNICODEFormat.end());
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_frm_field& obj)
		{
			out << " lpszFieldName: "					<< obj.lpszFieldName.c_str()
				<< " wIndexCount: "						<< obj.wIndexCount
				<< " fwType: "							<< obj.fwType
				<< " fwClass: "							<< obj.fwClass
				<< " fwAccess: "						<< obj.fwAccess
				<< " fwOverflow: "						<< obj.fwOverflow
				<< " lpszInitialValue: "				<< obj.lpszInitialValue.c_str()
				<< " lpszUNICODEInitialValue: "			<< obj.lpszUNICODEInitialValue.c_str()
				<< " lpszFormat: "						<< obj.lpszFormat.c_str()
				<< " lpszUNICODEFormat: "				<< obj.lpszUNICODEFormat.c_str();
			return out;
		}
		std::string lpszFieldName;
		std::string lpszInitialValue;
		std::string lpszUNICODEInitialValue;
		std::string lpszFormat;
		std::string lpszUNICODEFormat;
	} TTWFSFRMFIELD, * LPTTWFSFRMFIELD;

	typedef struct _tt_wfs_ptr_lpstr_form_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_lpstr_form_list)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_lpstr_form_list)
		void WFS2TT(const LPSTR obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->_strvecFormList, obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_lpstr_form_list& obj)
		{
			out << " lpszFormList: "					<< DeviceUtility::STRVECT2Str(obj._strvecFormList);
			return out;
		}
		DeviceUtility::STRVECT _strvecFormList;
	} TTWFSPTRLPSTRFORMLIST, * LPTTWFSPTRLPSTRFORMLIST;

	typedef struct _tt_wfs_ptr_lpstr_media_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_lpstr_media_list)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_lpstr_media_list)
		void WFS2TT(const LPSTR obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->_strvecMediaList, obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_lpstr_media_list& obj)
		{
			out << " lpszMediaList: "					<< DeviceUtility::STRVECT2Str(obj._strvecMediaList);
			return out;
		}
		DeviceUtility::STRVECT _strvecMediaList;
	} TTWFSPTRLPSTRMEDILIST, * LPTTWFSPTRLPSTRMEDILIST;

	typedef struct _tt_wfs_ptr_field_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_field_list)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_field_list)
		void WFS2TT(const XFS300::_wfs_frm_field* obj)
		{
			DeviceUtility::CopyP2NAPs(this->_contFieldList, (XFS300::_wfs_frm_field**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_field_list& obj)
		{
			out << " lpszFieldList: "					<< DeviceUtility::TTCONT2Str(obj._contFieldList);
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSFRMFIELD> _contFieldList;
	} TTWFSPTRLPSTRFIELDLIST, * LPTTWFSPTRLPSTRFIELDLIST;

	/*=================================================================*/
	/* PTR Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_ptr_print_form : public XFS300::_wfs_ptr_print_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_print_form)
		~_tt_wfs_ptr_print_form()
		{
			SAFEPTR(this->lpWFSPTRPRINTFORM)
			{
				SAFEFREEMEMORY(&this->lpWFSPTRPRINTFORM->lpszFormName);
				SAFEFREEMEMORY(&this->lpWFSPTRPRINTFORM->lpszMediaName);
				SAFEFREEMEMORY(&this->lpWFSPTRPRINTFORM->lpszFields);
				SAFERELEASE(&this->lpWFSPTRPRINTFORM);
			}
		}
		void WFS2TT(const _wfs_ptr_print_form* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName);
			this->lpszMediaName.assign(obj->lpszMediaName);
			this->wAlignment							= obj->wAlignment;
			this->wOffsetX								= obj->wOffsetX;
			this->wOffsetY								= obj->wOffsetY;
			this->wResolution							= obj->wResolution;
			this->dwMediaControl						= obj->dwMediaControl;
			DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
			this->lpszUNICODEFields.clear();
			this->wPaperSource							= obj->wPaperSource;
		}
		void WFS(XFS300::LPWFSPTRPRINTFORM* lppWFSPTRPRINTFORM)
		{
			this->lpWFSPTRPRINTFORM = new XFS300::WFSPTRPRINTFORM;
			SAFEALLOCCOPYSTRING(&this->lpWFSPTRPRINTFORM->lpszFormName, this->lpszFormName);
			SAFEALLOCCOPYSTRING(&this->lpWFSPTRPRINTFORM->lpszMediaName, this->lpszMediaName);
			this->lpWFSPTRPRINTFORM->wAlignment			= this->wAlignment;
			this->lpWFSPTRPRINTFORM->wOffsetX			= this->wOffsetX;
			this->lpWFSPTRPRINTFORM->wOffsetY			= this->wOffsetY;
			this->lpWFSPTRPRINTFORM->wResolution		= this->wResolution;
			this->lpWFSPTRPRINTFORM->dwMediaControl		= this->dwMediaControl;
			DeviceUtility::STRVECT2LPSTRNN(&this->lpWFSPTRPRINTFORM->lpszFields, this->lpszFields);
			//DeviceUtility::STRVECT2LPSTRNN(&this->lpWFSPTRPRINTFORM->lpszUNICODEFields, this->lpszUNICODEFields);
			this->wPaperSource							= this->wPaperSource;
			*lppWFSPTRPRINTFORM = this->lpWFSPTRPRINTFORM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_print_form& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " lpszMediaName: "					<< obj.lpszMediaName.c_str()
				<< " wAlignment: "						<< obj.wAlignment
				<< " wOffsetX: "						<< obj.wOffsetX
				<< " wOffsetY: "						<< obj.wOffsetY
				<< " wResolution: "						<< obj.wResolution
				<< " dwMediaControl: "					<< obj.dwMediaControl
				<< " lpszFields: "						<< DeviceUtility::STRVECT2Str(obj.lpszFields).c_str()
				<< " lpszUNICODEFields: "				<< DeviceUtility::STRVECT2Str(obj.lpszUNICODEFields).c_str()
				<< " wPaperSource: "					<< obj.wPaperSource;
			return out;
		}
		std::string lpszFormName;
		std::string lpszMediaName;
		DeviceUtility::STRVECT lpszFields;
		DeviceUtility::STRVECT lpszUNICODEFields;
		XFS300::LPWFSPTRPRINTFORM lpWFSPTRPRINTFORM = nullptr;
	} TTWFSPTRPRINTFORM, * LPTTWFSPTRPRINTFORM;

	typedef struct _tt_wfs_ptr_read_form : public XFS300::_wfs_ptr_read_form
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_read_form)
		~_tt_wfs_ptr_read_form() 
		{
			SAFEPTR(this->lpWFSPTRREADFORM)
			{
				SAFEFREEMEMORY(&this->lpWFSPTRREADFORM->lpszFormName);
				SAFEFREEMEMORY(&this->lpWFSPTRREADFORM->lpszFieldNames);
				SAFEFREEMEMORY(&this->lpWFSPTRREADFORM->lpszMediaName);
				SAFERELEASE(&this->lpWFSPTRREADFORM);
			}
		}
		void WFS2TT(const _wfs_ptr_read_form* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName);
			DeviceUtility::LPSTRNN2Vector(this->lpszFieldNames, obj->lpszFieldNames);
			this->lpszMediaName.assign(obj->lpszMediaName);
			this->dwMediaControl						= obj->dwMediaControl;
		}
		void WFS(XFS300::LPWFSPTRREADFORM* lppWFSPTRREADFORM)
		{
			this->lpWFSPTRREADFORM = new XFS300::WFSPTRREADFORM;
			SAFEALLOCCOPYSTRING(&this->lpWFSPTRREADFORM->lpszFormName, this->lpszFormName);
			DeviceUtility::STRVECT2LPSTRNN(&this->lpWFSPTRREADFORM->lpszFieldNames, this->lpszFieldNames);
			SAFEALLOCCOPYSTRING(&this->lpWFSPTRREADFORM->lpszMediaName, this->lpszMediaName);
			this->lpWFSPTRREADFORM->dwMediaControl		= this->dwMediaControl;
			*lppWFSPTRREADFORM = this->lpWFSPTRREADFORM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_read_form& obj)
		{
			out << " lpszFormName: "					<< obj.lpszFormName.c_str()
				<< " lpszFieldNames: "					<< DeviceUtility::STRVECT2Str(obj.lpszFieldNames).c_str()
				<< " lpszMediaName: "					<< obj.lpszMediaName;
			return out;
		}

		std::string lpszFormName;
		DeviceUtility::STRVECT lpszFieldNames;
		std::string lpszMediaName;
		XFS300::LPWFSPTRREADFORM lpWFSPTRREADFORM = nullptr;
	} TTWFSPTRREADFORM, * LPTTWFSPTRREADFORM;

	typedef struct _tt_wfs_ptr_read_form_out : public XFS300::_wfs_ptr_read_form_out
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_read_form_out)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_read_form_out)
		void WFS2TT(const XFS300::_wfs_ptr_read_form_out* obj)
		{
			DeviceUtility::LPSTRNN2Vector(this->lpszFields, obj->lpszFields);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_read_form_out& obj)
		{
			out << DeviceUtility::STRVECT2Str(obj.lpszFields);
			return out;
		}
		DeviceUtility::STRVECT lpszFields;
	} TTWFSPTRREADFORMOUT, * LPTTWFSPTRREADFORMOUT;

	typedef struct _tt_wfs_ptr_raw_data : public XFS300::_wfs_ptr_raw_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_raw_data)
		~_tt_wfs_ptr_raw_data()
		{ 
			SAFEFREEMEMORY(&this->lpbData);
			SAFEPTR(this->lpWFSPTRRAWDATA)
			{
				SAFEFREEMEMORY(&this->lpWFSPTRRAWDATA->lpbData);
				SAFERELEASE(&this->lpWFSPTRRAWDATA);
			}
		}
		void WFS2TT(const _wfs_ptr_raw_data* obj)
		{
			this->wInputData							= obj->wInputData;
			this->ulSize								= obj->ulSize;
			SAFEALLOCCOPYMEMORY(&this->lpbData, obj->lpbData, obj->ulSize);
		}
		void WFS(XFS300::LPWFSPTRRAWDATA* lppWFSPTRRAWDATA)
		{
			this->lpWFSPTRRAWDATA = new XFS300::WFSPTRRAWDATA;
			this->lpWFSPTRRAWDATA->wInputData			= this->wInputData;
			this->lpWFSPTRRAWDATA->ulSize				= this->ulSize;
			SAFEALLOCCOPYMEMORY(&this->lpWFSPTRRAWDATA->lpbData, this->lpbData, this->ulSize);
			*lppWFSPTRRAWDATA = this->lpWFSPTRRAWDATA;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_raw_data& obj)
		{
			out << " wInputData: "						<< obj.wInputData
				<< " ulSize: "							<< obj.ulSize
				<< " lpbData: "							<< std::string{ (char*)(obj.lpbData), 0, obj.ulSize};
			return out;
		}
		XFS300::LPWFSPTRRAWDATA lpWFSPTRRAWDATA = nullptr;
	} TTWFSPTRRAWDATA, * LPTTWFSPTRRAWDATA;

	typedef struct _tt_wfs_ptr_raw_data_in : public XFS300::_wfs_ptr_raw_data_in
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_raw_data_in)
		~_tt_wfs_ptr_raw_data_in() { SAFERELEASE(&this->lpbData); }
		void WFS2TT(const XFS300::_wfs_ptr_raw_data_in* obj)
		{
			SAFEPTR(obj)
			{
				this->ulSize = obj->ulSize;
				SAFEALLOCCOPYMEMORY(&this->lpbData, obj->lpbData, obj->ulSize);
			}
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_raw_data_in& obj)
		{
			DEBUGLOG("_tt_wfs_ptr_raw_data_in::operator");
			out << " ulSize: " << obj.ulSize
				<< " lpbData: " << TTFRMU::MakeString((char*)obj.lpbData, obj.ulSize);
			return out;
		}
	} TTWFSPTRRAWDATAIN, * LPTTWFSPTRRAWDATAIN;

	typedef struct _tt_wfs_ptr_media_unit : public XFS300::_wfs_ptr_media_unit
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_media_unit)
		~_tt_wfs_ptr_media_unit() { SAFERELEASE(&this->lpWFSPTRMEDIAUNIT) }
		void WFS2TT(const XFS300::_wfs_ptr_media_unit* obj)
		{
			this->wBase									= obj->wBase;
			this->wUnitX								= obj->wUnitX;
			this->wUnitY								= obj->wUnitY;
		}
		void WFS(XFS300::LPWFSPTRMEDIAUNIT* lppWFSPTRMEDIAUNIT)
		{
			this->lpWFSPTRMEDIAUNIT	= new XFS300::WFSPTRMEDIAUNIT;
			this->lpWFSPTRMEDIAUNIT->wBase				= this->wBase;
			this->lpWFSPTRMEDIAUNIT->wUnitX				= this->wUnitX;
			this->lpWFSPTRMEDIAUNIT->wUnitY				= this->wUnitY;
			*lppWFSPTRMEDIAUNIT = this->lpWFSPTRMEDIAUNIT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_media_unit& obj)
		{
			out << " wBase: "							<< obj.wBase
				<< " wUnitX: "							<< obj.wUnitX
				<< " wUnitY: "							<< obj.wUnitY;
			return out;
		}
		XFS300::LPWFSPTRMEDIAUNIT lpWFSPTRMEDIAUNIT = nullptr;
	} TTWFSPTRMEDIAUNIT, * LPTTWFSPTRMEDIAUNIT;

	typedef struct _tt_wfs_ptr_media_ext : public XFS300::_wfs_ptr_media_ext
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_media_ext)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_media_ext)
		void WFS2TT(const XFS300::_wfs_ptr_media_ext* obj)
		{
			this->ulSizeX								= obj->ulSizeX;
			this->ulSizeY								= obj->ulSizeY;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_media_ext& obj)
		{
			out << " ulSizeX: "							<< obj.ulSizeX
				<< " ulSizeY: "							<< obj.ulSizeY;
			return out;
		}
	} TTWFSPTRMEDIAEXT, * LPTTWFSPTRMEDIAEXT;

	// needs attention
	typedef struct _tt_wfs_ptr_image_request : public XFS300::_wfs_ptr_image_request
	{
		WORD wFrontImageType;
		WORD wBackImageType;
		WORD wFrontImageColorFormat;
		WORD wBackImageColorFormat;
		WORD wCodelineFormat;
		WORD fwImageSource;
		LPSTR lpszFrontImageFile;
		LPSTR lpszBackImageFile;
		void WFS(XFS300::LPWFSPTRIMAGEREQUEST* lppWFSPTRIMAGEREQUEST)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_image_request& obj)
		{
			return out;
		}
	} TTWFSPTRIMAGEREQUEST, * LPTTWFSPTRIMAGEREQUEST;

	typedef struct _tt_wfs_ptr_image : public XFS300::_wfs_ptr_image
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_image)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_image)
		void WFS2TT(const XFS300::_wfs_ptr_image* obj)
		{
			this->wImageSource = obj->wImageSource;
			this->wStatus = obj->wStatus;
			this->ulDataLength = obj->ulDataLength;
			this->lpbData = obj->lpbData;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_image& obj)
		{
			out << " wImageSource: "					<< obj.wImageSource
				<< " wStatus: "							<< obj.wStatus
				<< " ulDataLength: "					<< obj.ulDataLength
				<< " lpbData: "							<< obj.lpbData;

			return out;
		}
	} TTWFSPTRIMAGE, * LPTTWFSPTRIMAGE;

	typedef struct _tt_wfs_ptr_reset : public XFS300::_wfs_ptr_reset
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_reset)
		~_tt_wfs_ptr_reset() { SAFERELEASE(&this->lpWFSPTRRESET) }
		void WFS2TT(const XFS300::_wfs_ptr_reset* obj)
		{
			this->dwMediaControl						= obj->dwMediaControl;
			this->usRetractBinNumber					= obj->usRetractBinNumber;
		}
		void WFS(XFS300::LPWFSPTRRESET* lppWFSPTRRESET)
		{
			this->lpWFSPTRRESET = new XFS300::WFSPTRRESET;
			this->lpWFSPTRRESET->dwMediaControl			= this->dwMediaControl;
			this->lpWFSPTRRESET->usRetractBinNumber		= this->usRetractBinNumber;
			*lppWFSPTRRESET = this->lpWFSPTRRESET;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_reset& obj)
		{
			out << " dwMediaControl: "					<< obj.dwMediaControl
				<< " usRetractBinNumber: "				<< obj.usRetractBinNumber;
			return out;
		}
		XFS300::LPWFSPTRRESET lpWFSPTRRESET = nullptr;
	} TTWFSPTRRESET, * LPTTWFSPTRRESET;

	typedef struct _tt_wfs_lpushort_retract_media
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_lpushort_retract_media)
		DEFAULTDESTRUCTOR(_tt_wfs_lpushort_retract_media)
		void WFS2TT(const LPUSHORT obj)
		{
			this->_usBinNumber = *obj;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_lpushort_retract_media& obj)
		{
			out << " usBinNumber: "						<< obj._usBinNumber;
			return out;
		}
		USHORT _usBinNumber;
	} TTWFSPTRLPUSHORTRETRACTMEDIA, * LPTTWFSPTRLPUSHORTRETRACTMEDIA;

	/*=================================================================*/
	/* PTR Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_ptr_field_failure : public XFS300::_wfs_ptr_field_failure
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_field_failure)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_field_failure)
		void WFS2TT(const _wfs_ptr_field_failure* obj)
		{
			this->lpszFormName.assign(obj->lpszFormName);
			this->lpszFieldName.assign(obj->lpszFieldName);
			this->wFailure						= obj->wFailure;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_field_failure& obj)
		{
			out << " lpszFormName: "			<< obj.lpszFormName.c_str()
				<< " lpszFieldName: "			<< obj.lpszFieldName.c_str()
				<< " wFailure: "				<< obj.wFailure;
			return out;
		}
		std::string lpszFormName;
		std::string lpszFieldName;
	} TTWFSPTRFIELDFAIL, * LPTTWFSPTRFIELDFAIL;

	typedef struct _tt_wfs_ptr_bin_threshold : public XFS300::_wfs_ptr_bin_threshold
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_bin_threshold)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_bin_threshold)
		void WFS2TT(const _wfs_ptr_bin_threshold* obj)
		{
			this->usBinNumber					= obj->usBinNumber;
			this->wRetractBin					= obj->wRetractBin;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_bin_threshold& obj)
		{
			out << " usBinNumber: "				<< obj.usBinNumber
				<< " wRetractBin: "				<< obj.wRetractBin;
			return out;
		}
	} TTWFSPTRBINTHRESHOLD, * LPTTWFSPTRBINTHRESHOLD;

	typedef struct _tt_wfs_ptr_paper_threshold : public XFS300::_wfs_ptr_paper_threshold
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_paper_threshold)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_paper_threshold)
		void WFS2TT(const _wfs_ptr_paper_threshold* obj)
		{
			this->wPaperSource					= obj->wPaperSource;
			this->wPaperThreshold				= obj->wPaperThreshold;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_paper_threshold& obj)
		{
			out << " wPaperSource: "			<< obj.wPaperSource
				<< " wPaperThreshold: "			<< obj.wPaperThreshold;
			return out;
		}
	} TTWFSPTRPAPERTHRESHOLD, * LPTTWFSPTRPAPERTHRESHOLD;

	typedef struct _tt_wfs_ptr_media_detected : public XFS300::_wfs_ptr_media_detected
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_ptr_media_detected)
		DEFAULTDESTRUCTOR(_tt_wfs_ptr_media_detected)
			void WFS2TT(const _wfs_ptr_media_detected* obj)
		{
			this->wPosition						= obj->wPosition;
			this->usRetractBinNumber			= obj->usRetractBinNumber;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_ptr_media_detected& obj)
		{
			out << " wPosition: "				<< obj.wPosition
				<< " usRetractBinNumber: "		<< obj.usRetractBinNumber;
			return out;
		}
	} TTWFSPTRMEDIADETECTED, * LPTTWFSPTRMEDIADETECTED;

	/*=================================================================*/
	/* IPTR Utilities */
	/*=================================================================*/

	inline bool assign(XFS300::LPWFSPTRPRINTFORM* lppWFSPTRPrintForm, LPTTWFSFRMHEADER  lpTTWFSFRMHeader, LPSTR lpszMediaName)
	{
		UNSAFEPTR(lpTTWFSFRMHeader)
			return false;
		UNSAFEPTR(lppWFSPTRPrintForm)
			return false;

		*lppWFSPTRPrintForm = (XFS300::LPWFSPTRPRINTFORM)malloc(sizeof(XFS300::WFSPTRPRINTFORM));
		UNSAFEPTR(*lppWFSPTRPrintForm)
			return false;
		XFS300::LPWFSPTRPRINTFORM lpWFSPTRPrintForm = *lppWFSPTRPrintForm;

		SAFEALLOCCOPYMEMORY(&lpWFSPTRPrintForm->lpszFormName, lpTTWFSFRMHeader->lpszFormName.c_str(), lpTTWFSFRMHeader->lpszFormName.size());
		SAFEALLOCCOPYMEMORY(&lpWFSPTRPrintForm->lpszMediaName, lpszMediaName, DeviceUtility::Size_LPSTR(lpszMediaName));
		lpWFSPTRPrintForm->wAlignment = lpTTWFSFRMHeader->wAlignment;
		lpWFSPTRPrintForm->wOffsetX = lpTTWFSFRMHeader->wOffsetX;
		lpWFSPTRPrintForm->wOffsetY = lpTTWFSFRMHeader->wOffsetY;
		lpWFSPTRPrintForm->wResolution = WFS_PTR_RESHIGH;
		lpWFSPTRPrintForm->dwMediaControl = 0;
		DeviceUtility::STRVECT2LPSTRNN(&lpWFSPTRPrintForm->lpszFields, lpTTWFSFRMHeader->lpszFields);
		lpWFSPTRPrintForm->lpszUNICODEFields = NULL;
		lpWFSPTRPrintForm->wPaperSource = WFS_PTR_PAPERANY;

		return true;
	}

#pragma pack(pop)

	/*=================================================================*/
	/* IPTR Interface */
	/*=================================================================*/

	class ITTPTR : public ITTDevice
	{
	public:
		ITTPTR() = default;
		ITTPTR(const ITTPTR&) = delete;
		ITTPTR(ITTPTR&&) = delete;
		ITTPTR& operator = (const ITTPTR&) = delete;
		ITTPTR& operator = (ITTPTR&&) = delete;
		virtual ~ITTPTR() = default;

		/* PTR Info Functions */
		virtual bool GetStatus(LPTTWFSPTRSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSPTRCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetFormList(LPTTWFSPTRLPSTRFORMLIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetMediaList(LPTTWFSPTRLPSTRMEDILIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryForm(const LPSTR, LPTTWFSFRMHEADER, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryMedia(const LPSTR, LPTTWFSFRMMEDIA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool QueryField(const LPTTWFSPTRQUERYFIELD, LPTTWFSPTRLPSTRFIELDLIST, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetFormList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetMediaList(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryForm(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryMedia(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncQueryField(const LPTTWFSPTRQUERYFIELD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* PTR Execute Functions */
		virtual bool ControlMedia(const LPDWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool PrintForm(const LPTTWFSPTRPRINTFORM, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ReadForm(const LPTTWFSPTRREADFORM, LPTTWFSPTRREADFORMOUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool RawData(const LPTTWFSPTRRAWDATA, LPTTWFSPTRRAWDATAIN, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool MediaExtents(const LPTTWFSPTRMEDIAUNIT, LPTTWFSPTRMEDIAEXT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ResetCount(const LPUSHORT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ReadImage(const LPTTWFSPTRIMAGEREQUEST, LPTTWFSPTRIMAGE lpImage, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const LPTTWFSPTRRESET, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool RetractMedia(const LPUSHORT, LPTTWFSPTRLPUSHORTRETRACTMEDIA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool DispensePaper(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncControlMedia(const LPDWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncPrintForm(const LPTTWFSPTRPRINTFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReadForm(const LPTTWFSPTRREADFORM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRawData(const LPTTWFSPTRRAWDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncMediaExtents(const LPTTWFSPTRMEDIAUNIT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncResetCount(LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReadImage(const LPTTWFSPTRIMAGEREQUEST, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(const LPTTWFSPTRRESET, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRetractMedia(const LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDispensePaper(const WORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTPTR__
