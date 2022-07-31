
#pragma once

#ifndef __H_ITTPIN__
#define __H_ITTPIN__

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* PIN Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_pin_status : public XFS300::_wfs_pin_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_status)
		void WFS2TT(const XFS300::_wfs_pin_status* obj)
		{
			this->fwDevice							= obj->fwDevice;
			this->fwEncStat							= obj->fwEncStat;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_pin_status)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_status& obj)
		{
			out << " fwDevice: "					<< obj.fwDevice
				<< " fwEncStat: "					<< obj.fwEncStat;
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSPINSTATUS, * LPTTWFSPINSTATUS;

	typedef struct _tt_wfs_pin_caps : public XFS300::_wfs_pin_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_caps)
			void WFS2TT(const _wfs_pin_caps* obj)
		{
			this->wClass							= obj->wClass;
			this->fwType							= obj->fwType;
			this->bCompound							= obj->bCompound;
			this->usKeyNum							= obj->usKeyNum;
			this->fwAlgorithms						= obj->fwAlgorithms;
			this->fwPinFormats						= obj->fwPinFormats;
			this->fwDerivationAlgorithms			= obj->fwDerivationAlgorithms;
			this->fwPresentationAlgorithms			= obj->fwPresentationAlgorithms;
			this->fwDisplay							= obj->fwDisplay;
			this->bIDConnect						= obj->bIDConnect;
			this->fwIDKey							= obj->fwIDKey;
			this->fwValidationAlgorithms			= obj->fwValidationAlgorithms;
			this->fwKeyCheckModes					= obj->fwKeyCheckModes;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_pin_caps)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_caps& obj)
		{
			out << " wClass: "						<< obj.wClass
				<< " fwType: "						<< obj.fwType
				<< " bCompound: "					<< obj.bCompound
				<< " usKeyNum: "					<< obj.usKeyNum
				<< " fwAlgorithms: "				<< obj.fwAlgorithms
				<< " fwPinFormats: "				<< obj.fwPinFormats
				<< " fwDerivationAlgorithms: "		<< obj.fwDerivationAlgorithms
				<< " fwPresentationAlgorithms: "	<< obj.fwPresentationAlgorithms
				<< " fwDisplay: "					<< obj.fwDisplay
				<< " bIDConnect: "					<< obj.bIDConnect
				<< " fwIDKey: "						<< obj.fwIDKey
				<< " fwValidationAlgorithms: "		<< obj.fwValidationAlgorithms
				<< " fwKeyCheckModes: "				<< obj.fwKeyCheckModes;
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSPINCAPS, * LPTTWFSPINCAPS;

	typedef struct _tt_wfs_pin_key_detail : public XFS300::_wfs_pin_key_detail
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_key_detail)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_key_detail)
		void WFS2TT(const XFS300::_wfs_pin_key_detail* obj)
		{
			this->lpsKeyName.assign(obj->lpsKeyName);
			this->fwUse								= obj->fwUse;
			this->bLoaded							= obj->bLoaded;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_key_detail& obj)
		{
			out << " -"
				<< " lpsKeyName: "					<< obj.lpsKeyName
				<< " fwUse: "						<< "0x" << std::hex	<< std::setw(4) << std::setfill('0') << std::right << obj.fwUse
				<< " bLoaded: "						<< std::boolalpha << (bool)obj.bLoaded;
			return out;
		}
		std::string lpsKeyName{};
	} TTWFSPINKEYDETAIL, * LPTTWFSPINKEYDETAIL;

	typedef struct _tt_wfs_pin_p2ap_key_detail
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_p2ap_key_detail)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_p2ap_key_detail)
		void WFS2TT(const XFS300::_wfs_pin_key_detail* obj)
		{
			DeviceUtility::CopyP2NAPs(this->_listKeyDetails, (XFS300::_wfs_pin_key_detail**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_p2ap_key_detail& obj)
		{
			out << "KeyDetails: "					<< DeviceUtility::TTCONT2Str(obj._listKeyDetails);
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSPINKEYDETAIL>_listKeyDetails;
	} TTWFSPINP2APKEYDETAIL, * LPTTWFSPINP2APKEYDETAIL;

	typedef struct _tt_wfs_pin_fdk : public XFS300::_wfs_pin_fdk
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_fdk)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_fdk)
		void WFS2TT(const XFS300::_wfs_pin_fdk* obj)
		{
			this->ulFDK								= obj->ulFDK;
			this->usXPosition						= obj->usXPosition;
			this->usYPosition						= obj->usYPosition;
		}
			friend std::ostream& operator			<< (std::ostream& out, const _tt_wfs_pin_fdk& obj)
		{
			out << " - "
				<< " ulFDK: "						<< obj.ulFDK
				<< " usXPosition: "					<< obj.usXPosition
				<< " usYPosition: "					<< obj.usYPosition;
			return out;
		}
	} TTWFSPINFDK, * LPTTWFSPINFDK;

	typedef struct _tt_wfs_pin_func_key_detail : public XFS300::_wfs_pin_func_key_detail
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_func_key_detail)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_func_key_detail)
		void WFS2TT(const XFS300::_wfs_pin_func_key_detail* obj)
		{
			this->ulFuncMask						= obj->ulFuncMask;
			this->usNumberFDKs						= obj->usNumberFDKs;
			DeviceUtility::CopyP2APs(this->lppFDKs, obj->lppFDKs, obj->usNumberFDKs);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_func_key_detail& obj)
		{
			out << " -"
				<< " ulFuncMask: "					<< obj.ulFuncMask
				<< " usNumberFDKs: "				<< obj.usNumberFDKs
				<< " lppFDKs: ";
			for (auto elem : obj.lppFDKs)
				out << std::endl					<< *elem;
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSPINFDK> lppFDKs;
	} TTWFSPINFUNCKEYDETAIL, * LPTTWFSPINFUNCKEYDETAIL;

	typedef struct _tt_wfs_pin_key_detail_ex : public XFS300::_wfs_pin_key_detail_ex
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_key_detail_ex)
		void WFS2TT(const XFS300::_wfs_pin_key_detail_ex* obj)
		{
			SAFEALLOCCOPYMEMORY(&this->lpsKeyName, obj->lpsKeyName, strlen(obj->lpsKeyName) + 1);
			this->dwUse								= obj->dwUse;
			this->bGeneration						= obj->bGeneration;
			this->bVersion							= obj->bVersion;
			SAFECOPYMEMORY(this->bActivatingDate, obj->bActivatingDate, 4);
			SAFECOPYMEMORY(this->bExpiryDate, obj->bExpiryDate, 4);
			this->bLoaded							= obj->bLoaded;
		}
		~_tt_wfs_pin_key_detail_ex() { SAFEFREEMEMORY(&this->lpsKeyName); }
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_key_detail_ex& obj)
		{
			out << " lpsKeyName: "					<< obj.lpsKeyName
				<< " dwUse: " << "0x"				<< std::hex << obj.dwUse
				<< " bGeneration: "					<< obj.bGeneration
				<< " bVersion: "					<< obj.bVersion
				<< " bActivatingDate: "				<< TTFRMU::ByteArray2Str(obj.bActivatingDate, 4)
				<< " bExpiryDate: "					<< TTFRMU::ByteArray2Str(obj.bExpiryDate, 4)
				<< " bLoaded: "						<< obj.bLoaded;
			return out;
		}
	} TTWFSPINKEYDETAILEX, * LPTTWFSPINKEYDETAILEX;

	typedef struct _tt_wfs_pin_p2ap_key_detail_ex
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_p2ap_key_detail_ex)
			void WFS2TT(const XFS300::_wfs_pin_key_detail_ex* obj)
		{
			DeviceUtility::CopyP2NAPs(this->_listKeyDetailsEx, (XFS300::_wfs_pin_key_detail_ex**)obj);
		}
		DEFAULTDESTRUCTOR(_tt_wfs_pin_p2ap_key_detail_ex)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_p2ap_key_detail_ex& obj)
		{
			out << "KeyDetailsEx: "					<< DeviceUtility::TTCONT2Str(obj._listKeyDetailsEx);

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSPINKEYDETAILEX>_listKeyDetailsEx;
	} TTWFSPINP2APKEYDETAILEX, * LPTTWFSPINP2APKEYDETAILEX;

	/*=================================================================*/
	/* PIN Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_hex_data : public XFS300::_wfs_hex_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_hex_data)
		~_tt_wfs_hex_data() 
		{
			SAFEPTR(this->lpWFSXDATA)
			{
				SAFEFREEMEMORY(&this->lpWFSXDATA->lpbData);
				SAFERELEASE(&this->lpWFSXDATA);
			}
		}
		void WFS2TT(const XFS300::_wfs_hex_data* obj)
		{
			this->usLength							= obj->usLength;
			this->lpbData.assign((char*)obj->lpbData, obj->usLength);
		}
		void WFS(XFS300::LPWFSXDATA* lppWFSXDATA)
		{
			this->lpWFSXDATA = new XFS300::WFSXDATA;
			this->lpWFSXDATA->usLength				= this->usLength;
			SAFEALLOCCOPYSTRING(&this->lpWFSXDATA->lpbData, this->lpbData);
			*lppWFSXDATA = this->lpWFSXDATA;
		}
		friend std::ostream& operator				<< (std::ostream& out, const _tt_wfs_hex_data& obj)
		{
			out << "("
				<< " usLength: "					<< obj.usLength
				<< " lpbData: "						<< obj.lpbData
				<< ")";
			return out;
		}
		std::string lpbData{};
		XFS300::LPWFSXDATA lpWFSXDATA = nullptr;
	} TTWFSXDATA, * LPTTWFSXDATA;

	typedef struct _tt_wfs_pin_crypt : public XFS300::_wfs_pin_crypt
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_crypt)
		~_tt_wfs_pin_crypt() 
		{
			SAFERELEASE(&this->lpxKeyEncKey);
			SAFERELEASE(&this->lpxStartValue);
			SAFERELEASE(&this->lpxCryptData);
			SAFEPTR(this->lpWFSPINCRYPT)
			{
				SAFEFREEMEMORY(&this->lpWFSPINCRYPT->lpsKey);
				SAFERELEASE(&this->lpWFSPINCRYPT->lpxKeyEncKey);
				SAFEFREEMEMORY(&this->lpWFSPINCRYPT->lpsStartValueKey);
				SAFERELEASE(&this->lpWFSPINCRYPT->lpxStartValue);
				SAFERELEASE(&this->lpWFSPINCRYPT->lpxCryptData);
				SAFERELEASE(&this->lpWFSPINCRYPT);
			}
		}
		void WFS2TT(const XFS300::LPWFSPINCRYPT obj)
		{
			this->wMode								= obj->wMode;
			SAFEPTR(obj->lpsKey)
				this->lpsKey.assign(obj->lpsKey, DeviceUtility::Size_LPSTR(obj->lpsKey));
			SAFEPTR(obj->lpxKeyEncKey)
				DeviceUtility::CopyP(&this->lpxKeyEncKey, obj->lpxKeyEncKey);
			this->wAlgorithm						= obj->wAlgorithm;
			SAFEPTR(obj->lpsStartValueKey)
				this->lpsStartValueKey.assign(obj->lpsStartValueKey);
			SAFEPTR(obj->lpxStartValue)
				DeviceUtility::CopyP(&this->lpxStartValue, obj->lpxStartValue);
			this->bPadding							= obj->bPadding;
			this->bCompression						= obj->bCompression;
			SAFEPTR(obj->lpxCryptData)
				DeviceUtility::CopyP(&this->lpxCryptData, obj->lpxCryptData);
		}
		void WFS(XFS300::LPWFSPINCRYPT* lppWFSPINCRYPT)
		{
			this->lpWFSPINCRYPT = new XFS300::WFSPINCRYPT;
			this->lpWFSPINCRYPT->wMode				= this->wMode;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINCRYPT->lpsKey, this->lpsKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINCRYPT->lpxKeyEncKey, this->lpxKeyEncKey);
			this->lpWFSPINCRYPT->wAlgorithm			= this->wAlgorithm;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINCRYPT->lpsStartValueKey, this->lpsStartValueKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINCRYPT->lpxStartValue, this->lpxStartValue);
			this->lpWFSPINCRYPT->bPadding			= this->bPadding;
			this->lpWFSPINCRYPT->bCompression		= this->bCompression;
			DeviceUtility::CopyP_r(&this->lpWFSPINCRYPT->lpxCryptData, this->lpxCryptData);
			*lppWFSPINCRYPT = this->lpWFSPINCRYPT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_crypt& obj)
		{
			out << " wMode: "						<< obj.wMode
				<< " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpxKeyEncKey: ";
			SAFEPTR(obj.lpxKeyEncKey){ out << *obj.lpxKeyEncKey; } ELSE{ out << "NULL"; }
			out	<< " wAlgorithm: "					<< obj.wAlgorithm
				<< " lpsStartValueKey: ";
			if (!obj.lpsStartValueKey.empty()) { out << obj.lpsStartValueKey; } else{ out << "NULL"; }
			out	<< " lpxStartValue: ";
			SAFEPTR(obj.lpxStartValue) { out << *obj.lpxStartValue; } ELSE{ out << "NULL"; }
			out	<< " bPadding: "					<< "0x" << std::hex << std::setw(2) << std::setfill('0') << (0xff & (unsigned int)obj.bPadding)
				<< " bCompression: "				<< "0x" << std::hex << std::setw(2) << std::setfill('0') << (0xff & (unsigned int)obj.bCompression)
				<< " lpxCryptData: ";
			SAFEPTR(obj.lpxCryptData) { out << *obj.lpxCryptData; } ELSE{ out << "NULL"; }
			return out;
		}
		std::string		lpsKey;
		LPTTWFSXDATA	lpxKeyEncKey;
		std::string		lpsStartValueKey;
		LPTTWFSXDATA	lpxStartValue;
		LPTTWFSXDATA	lpxCryptData;
		XFS300::LPWFSPINCRYPT lpWFSPINCRYPT = nullptr;
	} TTWFSPINCRYPT, * LPTTWFSPINCRYPT;

	typedef struct _tt_wfs_pin_import : public XFS300::_wfs_pin_import
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import)
		~_tt_wfs_pin_import()
		{
			SAFERELEASE(&this->lpxIdent);
			SAFERELEASE(&this->lpxValue);
			SAFEPTR(this->lpWFSPINIMPORT)
			{
				SAFEFREEMEMORY(&this->lpWFSPINIMPORT->lpsKey);
				SAFEFREEMEMORY(&this->lpWFSPINIMPORT->lpsEncKey);
				SAFERELEASE(&this->lpWFSPINIMPORT->lpxIdent);
				SAFERELEASE(&this->lpWFSPINIMPORT->lpxValue);
				SAFERELEASE(&this->lpWFSPINIMPORT);
			}
		}
		void WFS2TT(const _tt_wfs_pin_import* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			this->lpsEncKey.assign(obj->lpsEncKey);
			DeviceUtility::CopyP(&this->lpxIdent, obj->lpxIdent);
			DeviceUtility::CopyP(&this->lpxValue, obj->lpxValue);
			this->fwUse										= obj->fwUse;
		}
		void WFS(XFS300::LPWFSPINIMPORT* lppWFSPINIMPORT)
		{
			this->lpWFSPINIMPORT = new XFS300::WFSPINIMPORT;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINIMPORT->lpsKey, this->lpsKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINIMPORT->lpsEncKey, this->lpsEncKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINIMPORT->lpxIdent, this->lpxIdent);
			DeviceUtility::CopyP_r(&this->lpWFSPINIMPORT->lpxValue, this->lpxValue);
			this->lpWFSPINIMPORT->fwUse						= this->fwUse;
			*lppWFSPINIMPORT = this->lpWFSPINIMPORT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import& obj)
		{
			out << " lpsKey: "								<< obj.lpsKey.c_str()
				<< " lpsEncKey: "							<< obj.lpsEncKey.c_str()
				<< " lpxKeyEncKey: "						<< *obj.lpxIdent
				<< " lpsStartValueKey: "					<< *obj.lpxValue
				<< " fwUse: "								<< obj.fwUse;
			return out;
		}
		std::string		lpsKey;
		std::string		lpsEncKey;
		LPTTWFSXDATA	lpxIdent;
		LPTTWFSXDATA	lpxValue;
		XFS300::LPWFSPINIMPORT lpWFSPINIMPORT = nullptr;
	} TTWFSPINIMPORT, * LPTTWFSPINIMPORT;

	typedef struct _tt_wfs_pin_derive : public XFS300::_wfs_pin_derive
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_derive)
		~_tt_wfs_pin_derive()
		{
			SAFERELEASE(&this->lpxStartValue);
			SAFERELEASE(&this->lpxInputData);
			SAFERELEASE(&this->lpxIdent);
			SAFEPTR(this->lpWFSPINDERIVE)
			{
				SAFEFREEMEMORY(&this->lpWFSPINDERIVE->lpsKey);
				SAFEFREEMEMORY(&this->lpWFSPINDERIVE->lpsKeyGenKey);
				SAFEFREEMEMORY(&this->lpWFSPINDERIVE->lpsStartValueKey);
				SAFERELEASE(&this->lpWFSPINDERIVE->lpxStartValue);
				SAFERELEASE(&this->lpWFSPINDERIVE->lpxInputData);
				SAFERELEASE(&this->lpWFSPINDERIVE->lpxIdent);
				SAFERELEASE(&this->lpWFSPINDERIVE);
			}
		}
		void WFS2TT(const XFS300::_wfs_pin_derive * obj)
		{
			this->wDerivationAlgorithm				= obj->wDerivationAlgorithm;
			this->lpsKey.assign(obj->lpsKey);
			this->lpsKeyGenKey.assign(obj->lpsKeyGenKey);
			this->lpsStartValueKey.assign(obj->lpsStartValueKey);
			DeviceUtility::CopyP(&this->lpxStartValue, obj->lpxStartValue);
			this->bPadding							= obj->bPadding;
			DeviceUtility::CopyP(&this->lpxInputData, obj->lpxInputData);
			DeviceUtility::CopyP(&this->lpxIdent, obj->lpxIdent);
		}
		void WFS(XFS300::LPWFSPINDERIVE* lppWFSPINDERIVE)
		{
			this->lpWFSPINDERIVE = new XFS300::WFSPINDERIVE;
			this->lpWFSPINDERIVE->wDerivationAlgorithm				= this->wDerivationAlgorithm;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINDERIVE->lpsKey, this->lpsKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINDERIVE->lpsKeyGenKey, this->lpsKeyGenKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINDERIVE->lpsStartValueKey, this->lpsStartValueKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINDERIVE->lpxStartValue, this->lpxStartValue);
			this->bPadding							= this->bPadding;
			DeviceUtility::CopyP_r(&this->lpWFSPINDERIVE->lpxInputData, this->lpxInputData);
			DeviceUtility::CopyP_r(&this->lpWFSPINDERIVE->lpxIdent, this->lpxIdent);
			*lppWFSPINDERIVE = this->lpWFSPINDERIVE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_derive& obj)
		{
			out << " wDerivationAlgorithm: "		<< obj.wDerivationAlgorithm
				<< " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpsKeyGenKey: "				<< obj.lpsKeyGenKey.c_str()
				<< " lpsStartValueKey: "			<< obj.lpsStartValueKey.c_str()
				<< " lpxStartValue: "				<< *obj.lpxStartValue
				<< " bPadding: "					<< obj.bPadding
				<< " lpxInputData: "				<< *obj.lpxInputData
				<< " lpxIdent: "					<< *obj.lpxIdent;
			return out;
		}
		std::string		lpsKey;
		std::string		lpsKeyGenKey;
		std::string		lpsStartValueKey;
		LPTTWFSXDATA	lpxStartValue;
		LPTTWFSXDATA	lpxInputData;
		LPTTWFSXDATA	lpxIdent;
		XFS300::LPWFSPINDERIVE lpWFSPINDERIVE = nullptr;
	} TTWFSPINDERIVE, * LPTTWFSPINDERIVE;

	typedef struct _tt_wfs_pin_getpin : public XFS300::_wfs_pin_getpin
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_getpin)
		~_tt_wfs_pin_getpin() { SAFERELEASE(&this->lpWFSPINGETPIN) }
		void WFS2TT(const _wfs_pin_getpin* obj)
		{
			this->usMinLen											= obj->usMinLen;
			this->usMaxLen											= obj->usMaxLen;
			this->bAutoEnd											= obj->bAutoEnd;
			this->cEcho												= obj->cEcho;
			this->ulActiveFDKs										= obj->ulActiveFDKs;
			this->ulActiveKeys										= obj->ulActiveKeys;
			this->ulTerminateFDKs									= obj->ulTerminateFDKs;
			this->ulTerminateKeys									= obj->ulTerminateKeys;
		}
		void WFS(XFS300::LPWFSPINGETPIN* lppWFSPINGETPIN)
		{
			this->lpWFSPINGETPIN = new XFS300::WFSPINGETPIN;
			this->lpWFSPINGETPIN->usMinLen							= this->usMinLen;
			this->lpWFSPINGETPIN->usMaxLen							= this->usMaxLen;
			this->lpWFSPINGETPIN->bAutoEnd							= this->bAutoEnd;
			this->lpWFSPINGETPIN->cEcho								= this->cEcho;
			this->lpWFSPINGETPIN->ulActiveFDKs						= this->ulActiveFDKs;
			this->lpWFSPINGETPIN->ulActiveKeys						= this->ulActiveKeys;
			this->lpWFSPINGETPIN->ulTerminateFDKs					= this->ulTerminateFDKs;
			this->lpWFSPINGETPIN->ulTerminateKeys					= this->ulTerminateKeys;
			*lppWFSPINGETPIN = this->lpWFSPINGETPIN;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_getpin& obj)
		{
			out << " usMinLen: "									<< obj.usMinLen
				<< " usMaxLen: "									<< obj.usMaxLen
				<< " bAutoEnd: "									<< obj.bAutoEnd
				<< " cEcho: "										<< obj.cEcho
				<< " ulActiveFDKs: "								<< obj.ulActiveFDKs
				<< " ulActiveKeys: "								<< obj.ulActiveKeys
				<< " ulTerminateFDKs: "								<< obj.ulTerminateFDKs
				<< " ulTerminateKeys: "								<< obj.ulTerminateKeys;
			return out;
		}
		XFS300::LPWFSPINGETPIN lpWFSPINGETPIN = nullptr;
	} TTWFSPINGETPIN, * LPTTWFSPINGETPIN;

	typedef struct _tt_wfs_pin_entry : public XFS300::_wfs_pin_entry
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_entry)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_entry)
		void WFS2TT(const XFS300::_wfs_pin_entry* obj)
		{
			this->usDigits							= obj->usDigits;
			this->wCompletion						= obj->wCompletion;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_entry& obj)
		{
			out << " usDigits: "					<< obj.usDigits
				<< " wCompletion: "					<< obj.wCompletion;
			return out;
		}
	} TTWFSPINENTRY, * LPTTWFSPINENTRY;

	typedef struct _tt_wfs_pin_local_des : public XFS300::_wfs_pin_local_des
	{
		DEFAULTDESTRUCTOR(_tt_wfs_pin_local_des)
		_tt_wfs_pin_local_des() 
		{
			SAFERELEASE(&this->lpxKeyEncKey);
			SAFEPTR(this->lpWFSPINLOCALDES)
			{
				SAFEFREEMEMORY(&this->lpWFSPINLOCALDES->lpsValidationData);
				SAFEFREEMEMORY(&this->lpWFSPINLOCALDES->lpsOffset);
				SAFEFREEMEMORY(&this->lpWFSPINLOCALDES->lpsKey);
				SAFERELEASE(&this->lpWFSPINLOCALDES->lpxKeyEncKey);
				SAFEFREEMEMORY(&this->lpWFSPINLOCALDES->lpsDecTable);
				SAFERELEASE(&this->lpWFSPINLOCALDES);
			}
		}
		void WFS2TT(const _wfs_pin_local_des* obj)
		{
			this->lpsValidationData.assign(obj->lpsValidationData);
			this->lpsOffset.assign(obj->lpsOffset);
			this->bPadding											= obj->bPadding;
			this->usMaxPIN											= obj->usMaxPIN;
			this->usValDigits										= obj->usValDigits;
			this->bNoLeadingZero									= obj->bNoLeadingZero;
			this->lpsKey.assign(obj->lpsKey);
			DeviceUtility::CopyP(&this->lpxKeyEncKey, obj->lpxKeyEncKey);
			this->lpsDecTable.assign(obj->lpsDecTable);
		}
		void WFS(XFS300::LPWFSPINLOCALDES* lppWFSPINLOCALDES)
		{
			this->lpWFSPINLOCALDES = new XFS300::WFSPINLOCALDES;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINLOCALDES->lpsValidationData, this->lpsValidationData);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINLOCALDES->lpsOffset, this->lpsOffset);
			this->lpWFSPINLOCALDES->bPadding						= this->bPadding;
			this->lpWFSPINLOCALDES->usMaxPIN						= this->usMaxPIN;
			this->lpWFSPINLOCALDES->usValDigits						= this->usValDigits;
			this->lpWFSPINLOCALDES->bNoLeadingZero					= this->bNoLeadingZero;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINLOCALDES->lpsKey, this->lpsKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINLOCALDES->lpxKeyEncKey, this->lpxKeyEncKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINLOCALDES->lpsDecTable, this->lpsDecTable);
			*lppWFSPINLOCALDES = this->lpWFSPINLOCALDES;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_local_des& obj)
		{
			out << " lpsValidationData: "							<< obj.lpsValidationData.c_str()
				<< " lpsOffset "									<< obj.lpsOffset.c_str()
				<< " bPadding "										<< obj.bPadding
				<< " usMaxPIN "										<< obj.usMaxPIN
				<< " usValDigits "									<< obj.usValDigits
				<< " bNoLeadingZero "								<< obj.bNoLeadingZero
				<< " lpsKey "										<< obj.lpsKey.c_str()
				<< " lpxKeyEncKey "									<< *obj.lpxKeyEncKey
				<< " lpsDecTable "									<< obj.lpsDecTable.c_str();
			return out;
		}
		std::string		lpsValidationData;
		std::string		lpsOffset;
		std::string		lpsKey;
		LPTTWFSXDATA	lpxKeyEncKey;
		std::string		lpsDecTable;
		XFS300::LPWFSPINLOCALDES lpWFSPINLOCALDES = nullptr;
	} TTWFSPINLOCALDES, * LPTTWFSPINLOCALDES;

	typedef struct _tt_wfs_pin_create_offset : public XFS300::_wfs_pin_create_offset
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_create_offset)
		~_tt_wfs_pin_create_offset() 
		{ 
			SAFERELEASE(&this->lpxKeyEncKey);
			SAFEPTR(this->lpWFSPINCREATEOFFSET)
			{
				SAFEFREEMEMORY(&this->lpWFSPINCREATEOFFSET->lpsValidationData);
				SAFEFREEMEMORY(&this->lpWFSPINCREATEOFFSET->lpsKey);
				SAFERELEASE(&this->lpWFSPINCREATEOFFSET->lpxKeyEncKey);
				SAFEFREEMEMORY(&this->lpWFSPINCREATEOFFSET->lpsDecTable);
				SAFERELEASE(&this->lpWFSPINCREATEOFFSET);
			}
		}
		void WFS2TT(const _wfs_pin_create_offset* obj)
		{
			this->lpsValidationData.assign(obj->lpsValidationData);
			this->bPadding							= obj->bPadding;
			this->usMaxPIN							= obj->usMaxPIN;
			this->usValDigits						= obj->usValDigits;
			this->lpsKey.assign(obj->lpsKey);
			DeviceUtility::CopyP(&this->lpxKeyEncKey, obj->lpxKeyEncKey);
			this->lpsDecTable.assign(obj->lpsDecTable);
		}
		void WFS(XFS300::LPWFSPINCREATEOFFSET* lppWFSPINCREATEOFFSET)
		{
			this->lpWFSPINCREATEOFFSET = new XFS300::WFSPINCREATEOFFSET;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINCREATEOFFSET->lpsValidationData, this->lpsValidationData);
			this->lpWFSPINCREATEOFFSET->bPadding	= this->bPadding;
			this->lpWFSPINCREATEOFFSET->usMaxPIN	= this->usMaxPIN;
			this->lpWFSPINCREATEOFFSET->usValDigits	= this->usValDigits;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINCREATEOFFSET->lpsKey, this->lpsKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINCREATEOFFSET->lpxKeyEncKey, this->lpxKeyEncKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINCREATEOFFSET->lpsDecTable, this->lpsDecTable);
			*lppWFSPINCREATEOFFSET = this->lpWFSPINCREATEOFFSET;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_create_offset& obj)
		{
			out << " lpsValidationData: "			<< obj.lpsValidationData.c_str()
				<< " bPadding: "					<< obj.bPadding
				<< " usMaxPIN: "					<< obj.usMaxPIN
				<< " usValDigits: "					<< obj.usValDigits
				<< " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpxKeyEncKey: "				<< *obj.lpxKeyEncKey
				<< " lpsDecTable: "					<< obj.lpsDecTable.c_str();
			return out;
		}
		std::string         lpsValidationData;
		std::string         lpsKey;
		LPTTWFSXDATA        lpxKeyEncKey;
		std::string         lpsDecTable;
		XFS300::LPWFSPINCREATEOFFSET lpWFSPINCREATEOFFSET = nullptr;
	} TTWFSPINCREATEOFFSET, * LPTTWFSPINCREATEOFFSET;

	typedef struct _tt_wfs_pin_local_eurocheque : XFS300::_wfs_pin_local_eurocheque
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_local_eurocheque)
		~_tt_wfs_pin_local_eurocheque() { SAFERELEASE(&this->lpxKeyEncKey) }
		void WFS2TT(const _wfs_pin_local_eurocheque* obj)
		{
			this->lpsEurochequeData.assign(obj->lpsEurochequeData);
			this->lpsPVV.assign(obj->lpsPVV);
			this->wFirstEncDigits					= obj->wFirstEncDigits;
			this->wFirstEncOffset					= obj->wFirstEncOffset;
			this->wPVVDigits						= obj->wPVVDigits;
			this->wPVVOffset						= obj->wPVVOffset;
			this->lpsKey.assign(obj->lpsKey);	
			DeviceUtility::CopyP(&this->lpxKeyEncKey, obj->lpxKeyEncKey);
			this->lpsDecTable.assign(obj->lpsDecTable);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINLOCALEUROCHEQUE* lppWFSPINLOCALEUROCHEQUE)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_local_eurocheque& obj)
		{
			out << " lpsEurochequeData: "			<< obj.lpsEurochequeData.c_str()
				<< " lpsPVV: "						<< obj.lpsPVV.c_str()
				<< " wFirstEncDigits: "				<< obj.wFirstEncDigits
				<< " wFirstEncOffset: "				<< obj.wFirstEncOffset
				<< " wPVVDigits: "					<< obj.wPVVDigits
				<< " wPVVOffset: "					<< obj.wPVVOffset
				<< " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpxKeyEncKey: "				<< *obj.lpxKeyEncKey
				<< " lpsDecTable: "					<< obj.lpsDecTable.c_str();
			return out;
		}
		std::string         lpsEurochequeData;
		std::string         lpsPVV;
		std::string         lpsKey;
		LPTTWFSXDATA        lpxKeyEncKey;
		std::string         lpsDecTable;
	} TTWFSPINLOCALEUROCHEQUE, *LPTTWFSPINLOCALEUROCHEQUE;
	
	typedef struct _tt_wfs_pin_local_visa : public XFS300::_wfs_pin_local_visa
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_local_visa)
		~_tt_wfs_pin_local_visa() { SAFERELEASE(&this->lpxKeyEncKey) }
		void WFS2TT(const _wfs_pin_local_visa* obj)
		{
			this->lpsPAN.assign(obj->lpsPAN);
			this->lpsPVV.assign(obj->lpsPVV);
			this->wPVVDigits						= obj->wPVVDigits;
			this->lpsKey.assign(obj->lpsKey);
			DeviceUtility::CopyP(&this->lpxKeyEncKey, obj->lpxKeyEncKey);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINLOCALVISA* lppWFSPINLOCALVISA)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_local_visa& obj)
		{
			out << " lpsPAN: "						<< obj.lpsPAN.c_str()
				<< " lpsPVV: "						<< obj.lpsPVV.c_str()
				<< " wPVVDigits: "					<< obj.wPVVDigits
				<< " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpxKeyEncKey: "				<< *obj.lpxKeyEncKey;
			return out;
		}
		std::string         lpsPAN;
		std::string         lpsPVV;
		std::string         lpsKey;
		LPTTWFSXDATA        lpxKeyEncKey;
	} TTWFSPINLOCALVISA, * LPTTWFSPINLOCALVISA;

	typedef struct _tt_wfs_pin_presentclear : public XFS300::_wfs_pin_presentclear
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_presentclear)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_presentclear)
		void WFS2TT(const _wfs_pin_presentclear* obj)
		{
			this->ulPINPointer						= obj->ulPINPointer;
			this->usPINOffset						= obj->usPINOffset;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_presentclear& obj)
		{
			out << " - "
				<< " ulPINPointer: "				<< obj.ulPINPointer
				<< " usPINOffset: "					<< obj.usPINOffset;
			return out;
		}
	} TTWFSPINPRESENTCLEAR, * LPTTWFSPINPRESENTCLEAR;

	typedef struct _tt_wfs_pin_presentidc : public XFS300::_wfs_pin_presentidc
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_presentidc)
		~_tt_wfs_pin_presentidc() { SAFERELEASE(&this->lpbChipData) SAFERELEASE(&this->lpAlgorithmData) }
		void WFS2TT(const _wfs_pin_presentidc* obj)
		{
			this->wPresentAlgorithm					= obj->wPresentAlgorithm;
			this->wChipProtocol						= obj->wChipProtocol;
			this->ulChipDataLength					= obj->ulChipDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpbChipData, obj->lpbChipData, obj->ulChipDataLength);
			DeviceUtility::CopyP<TTWFSPINPRESENTCLEAR, XFS300::WFSPINPRESENTCLEAR>((LPTTWFSPINPRESENTCLEAR*)&this->lpAlgorithmData, (XFS300::LPWFSPINPRESENTCLEAR)obj->lpAlgorithmData);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINPRESENTIDC* lppWFSPINPRESENTIDC)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_presentidc& obj)
		{
			out << " wPresentAlgorithm: "			<< obj.wPresentAlgorithm
				<< " wChipProtocol: "				<< obj.wPresentAlgorithm
				<< " ulChipDataLength: "			<< obj.ulChipDataLength
				<< " lpbChipData: "					<< "TODO"
				<< " lpAlgorithmData: "				<< *(LPTTWFSPINPRESENTCLEAR)obj.lpAlgorithmData;
			return out;
		}
	} TTWFSPINPRESENTIDC, * LPTTWFSPINPRESENTIDC;

	typedef struct _tt_wfs_pin_present_result : public XFS300::_wfs_pin_present_result
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_present_result)
		~_tt_wfs_pin_present_result() { SAFEFREEMEMORY(&this->lpbChipData) }
		void WFS2TT(const XFS300::_wfs_pin_present_result* obj)
		{
			this->wChipProtocol						= obj->wChipProtocol;
			this->ulChipDataLength					= obj->ulChipDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpbChipData, obj->lpbChipData, obj->ulChipDataLength);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_present_result& obj)
		{
			out << " wChipProtocol: "				<< obj.wChipProtocol
				<< " ulChipDataLength: "			<< obj.ulChipDataLength
				<< " lpbChipData: "					<< TTFRMU::ByteArray2Str(obj.lpbChipData, obj.ulChipDataLength);
			return out;
		}
	} TTWFSPINPRESENTRESULT, * LPTTWFSPINPRESENTRESULT;

	typedef struct _tt_wfs_pin_block : XFS300::_wfs_pin_block
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_block)
		~_tt_wfs_pin_block()
		{
			SAFEPTR(this->lpWFSPINBLOCK)
			{
				SAFEFREEMEMORY(&this->lpWFSPINBLOCK->lpsCustomerData);
				SAFEFREEMEMORY(&this->lpWFSPINBLOCK->lpsXORData);
				SAFEFREEMEMORY(&this->lpWFSPINBLOCK->lpsKey);
				SAFEFREEMEMORY(&this->lpWFSPINBLOCK->lpsKeyEncKey);
				SAFERELEASE(&this->lpWFSPINBLOCK);
			}
		}
		void WFS2TT(const _wfs_pin_block* obj)
		{
			this->lpsCustomerData.assign(obj->lpsCustomerData);
			this->lpsXORData.assign(obj->lpsXORData);
			this->bPadding							= obj->bPadding;
			this->wFormat							= obj->wFormat;
			this->lpsKey.assign(obj->lpsKey);
			this->lpsKeyEncKey.assign(obj->lpsKeyEncKey);
		}
		void WFS(XFS300::LPWFSPINBLOCK* lppWFSPINBLOCK)
		{
			this->lpWFSPINBLOCK = new XFS300::WFSPINBLOCK;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINBLOCK->lpsCustomerData, this->lpsCustomerData);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINBLOCK->lpsXORData, this->lpsXORData);
			this->lpWFSPINBLOCK->bPadding							= this->bPadding;
			this->lpWFSPINBLOCK->wFormat							= this->wFormat;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINBLOCK->lpsKey, this->lpsKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINBLOCK->lpsKeyEncKey, this->lpsKeyEncKey);
			*lppWFSPINBLOCK = this->lpWFSPINBLOCK;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_block& obj)
		{
			out << " lpsCustomerData: "				<< obj.lpsCustomerData.c_str()
				<< " lpsXORData: "					<< obj.lpsXORData.c_str()
				<< " bPadding: "					<< obj.bPadding
				<< " wFormat: "						<< obj.wFormat
				<< " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpsKeyEncKey: "				<< obj.lpsKeyEncKey.c_str();
			return out;
		}
		std::string lpsCustomerData;
		std::string lpsXORData;
		std::string lpsKey;
		std::string lpsKeyEncKey;
		XFS300::LPWFSPINBLOCK lpWFSPINBLOCK = nullptr;
	} TTWFSPINBLOCK, * LPTTWFSPINBLOCK;
	
	typedef struct _tt_wfs_pin_getdata : public XFS300::_wfs_pin_getdata
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_getdata)
		~_tt_wfs_pin_getdata() { SAFEFREEMEMORY(&this->lpWFSPINGETDATA) }
		void WFS2TT(const _wfs_pin_getdata* obj)
		{
			this->usMaxLen											= obj->usMaxLen;
			this->bAutoEnd											= obj->bAutoEnd;
			this->ulActiveFDKs										= obj->ulActiveFDKs;
			this->ulActiveKeys										= obj->ulActiveKeys;
			this->ulTerminateFDKs									= obj->ulTerminateFDKs;
			this->ulTerminateKeys									= obj->ulTerminateKeys;
		}
		void WFS(XFS300::LPWFSPINGETDATA* lppWFSPINGETDATA)
		{
			this->lpWFSPINGETDATA = new XFS300::WFSPINGETDATA;
			this->lpWFSPINGETDATA->usMaxLen							= this->usMaxLen;
			this->lpWFSPINGETDATA->bAutoEnd							= this->bAutoEnd;
			this->lpWFSPINGETDATA->ulActiveFDKs						= this->ulActiveFDKs;
			this->lpWFSPINGETDATA->ulActiveKeys						= this->ulActiveKeys;
			this->lpWFSPINGETDATA->ulTerminateFDKs					= this->ulTerminateFDKs;
			this->lpWFSPINGETDATA->ulTerminateKeys					= this->ulTerminateKeys;
			*lppWFSPINGETDATA = this->lpWFSPINGETDATA;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_getdata& obj)
		{
			out << " usMaxLen: "									<< obj.usMaxLen
				<< " bAutoEnd: "									<< obj.bAutoEnd
				<< " ulActiveFDKs: "								<< obj.ulActiveFDKs
				<< " ulActiveKeys: "								<< obj.ulActiveKeys
				<< " ulTerminateFDKs: "								<< obj.ulTerminateFDKs
				<< " ulTerminateKeys: "								<< obj.ulTerminateKeys;
			return out;
		}
		XFS300::LPWFSPINGETDATA lpWFSPINGETDATA = nullptr;
	} TTWFSPINGETDATA, * LPTTWFSPINGETDATA;

	typedef struct _tt_wfs_pin_key : public XFS300::_wfs_pin_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_key)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_key)
		void WFS2TT(const XFS300::_wfs_pin_key* obj)
		{
			this->wCompletion						= obj->wCompletion;
			this->ulDigit							= obj->ulDigit;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_key& obj)
		{
			out << " - "
				<< " wCompletion: "					<< obj.wCompletion
				<< " ulDigit: "						<< obj.ulDigit;
			return out;
		}
	} TTWFSPINKEY, * LPTTWFSPINKEY;

	typedef struct _tt_wfs_pin_data : public XFS300::_wfs_pin_data
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_data)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_data)
		void WFS2TT(const XFS300::_wfs_pin_data* obj)
		{
			this->usKeys = obj->usKeys;
			DeviceUtility::CopyP2APs(this->lpPinKeys, obj->lpPinKeys, obj->usKeys);
			this->wCompletion = obj->wCompletion;
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_data& obj)
		{
			out << " usKeys: "						<< obj.usKeys
				<< " wCompletion: "					<< obj.wCompletion
				<< " lpPinKeys: "					<< DeviceUtility::TTCONT2Str(obj.lpPinKeys);

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSPINKEY> lpPinKeys;
	} TTWFSPINDATA, * LPTTWFSPINDATA;

	typedef struct _tt_wfs_pin_init : public XFS300::_wfs_pin_init
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_init)
		~_tt_wfs_pin_init() 
		{
			SAFERELEASE(&this->lpxIdent); 
			SAFERELEASE(&this->lpxKey);
			SAFEPTR(this->lpWFSPININIT)
			{
				SAFERELEASE(&this->lpWFSPININIT->lpxIdent);
				SAFERELEASE(&this->lpWFSPININIT->lpxKey);
				SAFERELEASE(&this->lpWFSPININIT);
			}
		}
		void WFS2TT(const _wfs_pin_init* obj)
		{
			DeviceUtility::CopyP(&this->lpxIdent, obj->lpxIdent);
			DeviceUtility::CopyP(&this->lpxKey, obj->lpxKey);
		}
		void WFS(XFS300::LPWFSPININIT* lppWFSPININIT)
		{
			this->lpWFSPININIT = new XFS300::WFSPININIT;
			DeviceUtility::CopyP_r(&this->lpWFSPININIT->lpxIdent, this->lpxIdent);
			DeviceUtility::CopyP_r(&this->lpWFSPININIT->lpxKey, this->lpxKey);
			*lppWFSPININIT = this->lpWFSPININIT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_init& obj)
		{
			out << " lpxIdent: "					<< *obj.lpxIdent
				<< " lpxKey: "						<< obj.lpxKey;
			return out;
		}
		LPTTWFSXDATA lpxIdent;
		LPTTWFSXDATA lpxKey;
		XFS300::LPWFSPININIT lpWFSPININIT = nullptr;
	} TTWFSPININIT, * LPTTWFSPININIT;

	typedef struct _tt_wfs_pin_local_banksys : public XFS300::_wfs_pin_local_banksys
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_local_banksys)
		~_tt_wfs_pin_local_banksys()
		{
			SAFERELEASE(&this->lpxATMVAC);
			SAFEPTR(this->lpWFSPINLOCALBANKSYS)
			{
				SAFERELEASE(&this->lpWFSPINLOCALBANKSYS->lpxATMVAC);
				SAFERELEASE(&this->lpWFSPINLOCALBANKSYS);
			}
		}
		void WFS2TT(const _tt_wfs_pin_local_banksys* obj)
		{
			DeviceUtility::CopyP(&this->lpxATMVAC, obj->lpxATMVAC);
		}
		void WFS(XFS300::LPWFSPINLOCALBANKSYS* lppWFSPINLOCALBANKSYS)
		{
			this->lpWFSPINLOCALBANKSYS = new XFS300::WFSPINLOCALBANKSYS;
			DeviceUtility::CopyP_r(&this->lpWFSPINLOCALBANKSYS->lpxATMVAC, this->lpxATMVAC);
			*lppWFSPINLOCALBANKSYS = this->lpWFSPINLOCALBANKSYS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_local_banksys& obj)
		{
			out << " lpxATMVAC: "					<< *obj.lpxATMVAC;
			return out;
		}
		LPTTWFSXDATA lpxATMVAC;
		XFS300::LPWFSPINLOCALBANKSYS lpWFSPINLOCALBANKSYS = nullptr;
	} TTWFSPINLOCALBANKSYS, * LPTTWFSPINLOCALBANKSYS;

	typedef struct _tt_wfs_pin_banksys_io : public XFS300::_wfs_pin_banksys_io
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_banksys_io)
		~_tt_wfs_pin_banksys_io() 
		{
			SAFEFREEMEMORY(&this->lpbData);
			SAFEPTR(this->lpWFSPINBANKSYSIO)
			{
				SAFEFREEMEMORY(&this->lpWFSPINBANKSYSIO->lpbData);
				SAFERELEASE(&this->lpWFSPINBANKSYSIO);
			}
		}
		void WFS2TT(const XFS300::_wfs_pin_banksys_io* obj)
		{
			this->ulLength							= obj->ulLength;
			SAFEALLOCCOPYMEMORY(&this->lpbData, obj->lpbData, obj->ulLength);
		}
		void WFS(XFS300::LPWFSPINBANKSYSIO* lppWFSPINBANKSYSIO)
		{
			this->lpWFSPINBANKSYSIO = new XFS300::WFSPINBANKSYSIO;
			this->lpWFSPINBANKSYSIO->ulLength		= this->ulLength;
			SAFEALLOCCOPYMEMORY(&this->lpWFSPINBANKSYSIO->lpbData, this->lpbData, this->ulLength);
			*lppWFSPINBANKSYSIO = this->lpWFSPINBANKSYSIO;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_banksys_io& obj)
		{
			out << " ulLength: "					<< obj.ulLength
				<< " lpbData: "						<< TTFRMU::ByteArray2Str(obj.lpbData, obj.ulLength);
			return out;
		}
		XFS300::LPWFSPINBANKSYSIO lpWFSPINBANKSYSIO = nullptr;
	} TTWFSPINBANKSYSIO, * LPTTWFSPINBANKSYSIO;

	typedef struct _tt_wfs_pin_secure_message : public XFS300::_wfs_pin_secure_message
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_secure_message)
		~_tt_wfs_pin_secure_message() { SAFEFREEMEMORY(&this->lpbMsg) }
		void WFS2TT(const XFS300::_wfs_pin_secure_message* obj)
		{
			this->wProtocol							= obj->wProtocol;
			this->ulLength							= obj->ulLength;
			SAFEALLOCCOPYMEMORY(&this->lpbMsg, obj->lpbMsg, obj->ulLength);
		}
		void WFS(XFS300::LPWFSPINSECMSG* lppWFSPINSECMSG)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_secure_message& obj)
		{
			out << " wProtocol: "					<< obj.wProtocol
				<< " ulLength: "					<< obj.ulLength
				<< " lpbChipData: " << TTFRMU::ByteArray2Str(obj.lpbMsg, obj.ulLength);
			return out;
		}
	} TTWFSPINSECMSG, * LPTTWFSPINSECMSG;

	typedef struct _tt_wfs_pin_import_key_ex : public XFS300::_wfs_pin_import_key_ex
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_key_ex)
		~_tt_wfs_pin_import_key_ex() 
		{
			SAFERELEASE(&this->lpxValue); 
			SAFERELEASE(&this->lpxControlVector);
			SAFERELEASE(&this->lpxKeyCheckValue);
			SAFEPTR(this->lpWFSPINIMPORTKEYEX)
			{
				SAFEFREEMEMORY(&this->lpWFSPINIMPORTKEYEX->lpsKey);
				SAFEFREEMEMORY(&this->lpWFSPINIMPORTKEYEX->lpsEncKey);
				SAFERELEASE(&this->lpWFSPINIMPORTKEYEX->lpxValue);
				SAFERELEASE(&this->lpWFSPINIMPORTKEYEX->lpxControlVector);
				SAFERELEASE(&this->lpWFSPINIMPORTKEYEX->lpxKeyCheckValue);
				SAFERELEASE(&this->lpWFSPINIMPORTKEYEX);
			}
		}
		void WFS2TT(const _tt_wfs_pin_import_key_ex* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			this->lpsEncKey.assign(obj->lpsEncKey);
			DeviceUtility::CopyP(&this->lpxValue, obj->lpxValue);
			DeviceUtility::CopyP(&this->lpxControlVector, obj->lpxControlVector);
			this->dwUse												= obj->dwUse;
			this->wKeyCheckMode										= obj->wKeyCheckMode;
			DeviceUtility::CopyP(&this->lpxKeyCheckValue, obj->lpxKeyCheckValue);
		}
		void WFS(XFS300::LPWFSPINIMPORTKEYEX* lppWFSPINIMPORTKEYEX)
		{
			this->lpWFSPINIMPORTKEYEX = new XFS300::WFSPINIMPORTKEYEX;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINIMPORTKEYEX->lpsKey, this->lpsKey);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINIMPORTKEYEX->lpsEncKey, this->lpsEncKey);
			DeviceUtility::CopyP_r(&this->lpWFSPINIMPORTKEYEX->lpxValue, this->lpxValue);
			DeviceUtility::CopyP_r(&this->lpWFSPINIMPORTKEYEX->lpxControlVector, this->lpxControlVector);
			this->lpWFSPINIMPORTKEYEX->dwUse						= this->dwUse;
			this->lpWFSPINIMPORTKEYEX->wKeyCheckMode				= this->wKeyCheckMode;
			DeviceUtility::CopyP_r(&this->lpWFSPINIMPORTKEYEX->lpxKeyCheckValue, this->lpxKeyCheckValue);
			*lppWFSPINIMPORTKEYEX = this->lpWFSPINIMPORTKEYEX;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_key_ex& obj)
		{
			out << " lpsKey: "										<< obj.lpsKey.c_str();
			out << " lpsEncKey: "									<< obj.lpsEncKey.c_str();
			out << " lpxValue: "									<< *obj.lpxValue;
			out << " lpxControlVector: "							<< *obj.lpxControlVector;
			out << " dwUse: "										<< obj.dwUse;
			out << " wKeyCheckMode: "								<< obj.wKeyCheckMode;
			out << " lpxKeyCheckValue: "							<< *obj.lpxKeyCheckValue;
			return out;
		}
		std::string		lpsKey;
		std::string		lpsEncKey;
		LPTTWFSXDATA	lpxValue;
		LPTTWFSXDATA	lpxControlVector;
		LPTTWFSXDATA	lpxKeyCheckValue;
		XFS300::LPWFSPINIMPORTKEYEX lpWFSPINIMPORTKEYEX = nullptr;
	} TTWFSPINIMPORTKEYEX, * LPTTWFSPINIMPORTKEYEX;

	typedef struct _tt_wfs_pin_enc_io : public XFS300::_wfs_pin_enc_io
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_enc_io)
		~_tt_wfs_pin_enc_io() 
		{
			SAFEFREEMEMORY(&this->lpvData);
			SAFEPTR(this->lpWFSPINENCIO)
			{
				SAFEFREEMEMORY(&this->lpWFSPINENCIO->lpvData);
				SAFERELEASE(&this->lpWFSPINENCIO);
			}
		}
		void WFS2TT(const XFS300::_wfs_pin_enc_io* obj)
		{
			this->wProtocol							= obj->wProtocol;
			this->ulDataLength						= obj->ulDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpvData, obj->lpvData, obj->ulDataLength);
		}
		void WFS(XFS300::LPWFSPINENCIO* lppWFSPINENCIO)
		{
			this->lpWFSPINENCIO = new XFS300::WFSPINENCIO;
			this->lpWFSPINENCIO->wProtocol			= this->wProtocol;
			this->lpWFSPINENCIO->ulDataLength		= this->ulDataLength;
			SAFEALLOCCOPYMEMORY(&this->lpWFSPINENCIO->lpvData, this->lpvData, this->ulDataLength);
			*lppWFSPINENCIO = this->lpWFSPINENCIO;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_enc_io& obj)
		{
			out << " wProtocol: "					<< obj.wProtocol
				<< " ulDataLength: "				<< obj.ulDataLength
				<< " lpvData: "						<< TTFRMU::ByteArray2Str((LPBYTE)obj.lpvData, obj.ulDataLength);
			return out;
		}
		XFS300::LPWFSPINENCIO lpWFSPINENCIO = nullptr;
	} TTWFSPINENCIO, * LPTTWFSPINENCIO;
	
	/* WFS_CMD_PIN_SECUREKEY_ENTRY command input structure */
	typedef struct _tt_wfs_pin_secure_key_entry : public XFS300::_wfs_pin_secure_key_entry
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_secure_key_entry)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_secure_key_entry)
		void WFS2TT(const _wfs_pin_secure_key_entry* obj)
		{
			this->usKeyLen							= obj->usKeyLen;
			this->bAutoEnd							= obj->bAutoEnd;
			this->ulActiveFDKs						= obj->ulActiveFDKs;
			this->ulActiveKeys						= obj->ulActiveKeys;
			this->ulTerminateFDKs					= obj->ulTerminateFDKs;
			this->ulTerminateKeys					= obj->ulTerminateKeys;
			this->wVerificationType					= obj->wVerificationType;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_secure_key_entry& obj)
		{
			out << " usKeyLen: "					<< obj.usKeyLen
				<< " bAutoEnd: "					<< obj.bAutoEnd
				<< " ulActiveFDKs: "				<< obj.ulActiveFDKs
				<< " ulActiveKeys: "				<< obj.ulActiveKeys
				<< " ulTerminateFDKs: "				<< obj.ulTerminateFDKs
				<< " ulTerminateKeys: "				<< obj.ulTerminateKeys
				<< " wVerificationType: "			<< obj.wVerificationType;
			return out;
		}
	} TTWFSPINSECUREKEYENTRY, * LPTTWFSPINSECUREKEYENTRY;
	
	/* WFS_CMD_PIN_SECUREKEY_ENTRY command output structure */
	typedef struct _tt_wfs_pin_secure_key_entry_out : XFS300::_wfs_pin_secure_key_entry_out
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_secure_key_entry_out)
		~_tt_wfs_pin_secure_key_entry_out() { SAFERELEASE(&this->lpxKCV) }
		void WFS2TT(const _wfs_pin_secure_key_entry_out* obj)
		{
			this->usDigits							= obj->usDigits;
			this->wCompletion						= obj->wCompletion;
			DeviceUtility::CopyP(&this->lpxKCV, obj->lpxKCV);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_secure_key_entry_out& obj)
		{
			out << " usDigits: "					<< obj.usDigits
				<< " wCompletion: "					<< obj.wCompletion
				<< " lpxKCV: "						<< *obj.lpxKCV;
			return out;
		}
		LPTTWFSXDATA	lpxKCV;
	} TTWFSPINSECUREKEYENTRYOUT, * LPTTWFSPINSECUREKEYENTRYOUT;
	
	typedef struct _tt_wfs_pin_import_rsa_public_key : public XFS300::_wfs_pin_import_rsa_public_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_rsa_public_key)
		~_tt_wfs_pin_import_rsa_public_key() { SAFERELEASE(&this->lpxValue) SAFERELEASE(&this->lpxSignature) }
		void WFS2TT(const _wfs_pin_import_rsa_public_key* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			DeviceUtility::CopyP(&this->lpxValue, obj->lpxValue);
			this->dwUse								= obj->dwUse;
			this->lpsSigKey.assign(obj->lpsSigKey);
			this->dwRSASignatureAlgorithm			= obj->dwRSASignatureAlgorithm;
			DeviceUtility::CopyP(&this->lpxSignature, obj->lpxSignature);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINIMPORTRSAPUBLICKEY* lppWFSPINIMPORTRSAPUBLICKEY)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_rsa_public_key& obj)
		{
			out << " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpxValue: "					<< *obj.lpxValue
				<< " dwUse: "						<< obj.dwUse
				<< " lpsSigKey: "					<< obj.lpsSigKey.c_str()
				<< " dwRSASignatureAlgorithm: "		<< obj.dwRSASignatureAlgorithm
				<< " lpxSignature: "				<< *obj.lpxSignature;
			return out;
		}
		std::string		lpsKey;
		LPTTWFSXDATA	lpxValue;
		std::string		lpsSigKey;
		LPTTWFSXDATA	lpxSignature;
	} TTWFSPINIMPORTRSAPUBLICKEY, * LPTTWFSPINIMPORTRSAPUBLICKEY;

	typedef struct _tt_wfs_pin_import_rsa_public_key_output : public XFS300::_wfs_pin_import_rsa_public_key_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_rsa_public_key_output)
		~_tt_wfs_pin_import_rsa_public_key_output() { SAFERELEASE(&this->lpxKeyCheckValue) }
		void WFS2TT(const XFS300::_wfs_pin_import_rsa_public_key_output* obj)
		{
			this->dwRSAKeyCheckMode					= obj->dwRSAKeyCheckMode;
			DeviceUtility::CopyP(&this->lpxKeyCheckValue, obj->lpxKeyCheckValue);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_rsa_public_key_output& obj)
		{
			out << " dwRSAKeyCheckMode: "			<< obj.dwRSAKeyCheckMode
				<< " lpxKeyCheckValue: "			<< *obj.lpxKeyCheckValue;
			return out;
		}
		LPTTWFSXDATA lpxKeyCheckValue;
	} TTWFSPINIMPORTRSAPUBLICKEYOUTPUT, * LPTTWFSPINIMPORTRSAPUBLICKEYOUTPUT;

	typedef struct _tt_wfs_pin_export_rsa_issuer_signed_item : public XFS300::_wfs_pin_export_rsa_issuer_signed_item
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_export_rsa_issuer_signed_item)
		~_tt_wfs_pin_export_rsa_issuer_signed_item()
		{
			SAFEPTR(this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM)
			{
				SAFEFREEMEMORY(&this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM->lpsName);
				SAFERELEASE(&this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM);
			}
		}
		void WFS2TT(const _wfs_pin_export_rsa_issuer_signed_item* obj)
		{
			this->wExportItemType					= obj->wExportItemType;
			this->lpsName.assign(obj->lpsName);
		}
		void WFS(XFS300::LPWFSPINEXPORTRSAISSUERSIGNEDITEM* lppWFSPINEXPORTRSAISSUERSIGNEDITEM)
		{
			this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM = new XFS300::WFSPINEXPORTRSAISSUERSIGNEDITEM;
			this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM->wExportItemType	= this->wExportItemType;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM->lpsName, this->lpsName);
			*lppWFSPINEXPORTRSAISSUERSIGNEDITEM = this->lpWFSPINEXPORTRSAISSUERSIGNEDITEM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_export_rsa_issuer_signed_item& obj)
		{
			out << " wExportItemType: "				<< obj.wExportItemType
				<< " lpsName: "						<< obj.lpsName.c_str();
			return out;
		}
		std::string lpsName;
		XFS300::LPWFSPINEXPORTRSAISSUERSIGNEDITEM lpWFSPINEXPORTRSAISSUERSIGNEDITEM = nullptr;
	} TTWFSPINEXPORTRSAISSUERSIGNEDITEM, * LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM;

	typedef struct _tt_wfs_pin_export_rsa_issuer_signed_item_output : public XFS300::_wfs_pin_export_rsa_issuer_signed_item_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_export_rsa_issuer_signed_item_output)
		~_tt_wfs_pin_export_rsa_issuer_signed_item_output() { SAFERELEASE(&this->lpxValue) SAFERELEASE(&this->lpxSignature) }
		void WFS2TT(const XFS300::_wfs_pin_export_rsa_issuer_signed_item_output* obj)
		{
			DeviceUtility::CopyP(&this->lpxValue, obj->lpxValue);
			this->dwRSASignatureAlgorithm			= obj->dwRSASignatureAlgorithm;
			DeviceUtility::CopyP(&this->lpxSignature, obj->lpxSignature);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_export_rsa_issuer_signed_item_output& obj)
		{
			out << " lpxValue: "					<< *obj.lpxValue
				<< " dwRSASignatureAlgorithm: "		<< obj.dwRSASignatureAlgorithm
				<< " lpxSignature: "				<< *obj.lpxSignature;
			return out;
		}
		LPTTWFSXDATA lpxValue;
		LPTTWFSXDATA lpxSignature;
	} TTWFSPINEXPORTRSAISSUERSIGNEDITEMOUTPUT, * LPTTWFSPINEXPORTRSAISSUERSIGNEDITEMOUTPUT;

	typedef struct _tt_wfs_pin_import_rsa_signed_des_key : public XFS300:: _wfs_pin_import_rsa_signed_des_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_rsa_signed_des_key)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_import_rsa_signed_des_key)
		void WFS2TT(const _wfs_pin_import_rsa_signed_des_key* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			this->lpsDecryptKey.assign(obj->lpsDecryptKey);
			this->dwRSAEncipherAlgorithm			= obj->dwRSAEncipherAlgorithm;
			DeviceUtility::CopyP(&this->lpxValue, obj->lpxValue);
			this->dwUse								= obj->dwUse;
			this->lpsSigKey.assign(obj->lpsSigKey);
			this->dwRSASignatureAlgorithm			= obj->dwRSASignatureAlgorithm;
			DeviceUtility::CopyP(&this->lpxSignature, obj->lpxSignature);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINIMPORTRSASIGNEDDESKEY* lppWFSPINIMPORTRSASIGNEDDESKEY)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_rsa_signed_des_key& obj)
		{
			out << " lpsKey: "						<< obj.lpsKey.c_str()
				<< " lpsDecryptKey: "				<< obj.lpsDecryptKey.c_str()
				<< " dwRSAEncipherAlgorithm: "		<< obj.dwRSAEncipherAlgorithm
				<< " lpxValue: "					<< *obj.lpxValue
				<< " dwUse: "						<< obj.dwUse
				<< " lpsSigKey: "					<< obj.lpsSigKey.c_str()
				<< " dwRSASignatureAlgorithm: "		<< obj.dwRSASignatureAlgorithm
				<< " lpxSignature: "				<< *obj.lpxSignature;
			return out;
		}
		std::string     lpsKey;
		std::string     lpsDecryptKey;
		LPTTWFSXDATA	lpxValue;
		std::string     lpsSigKey;
		LPTTWFSXDATA	lpxSignature;
	} TTWFSPINIMPORTRSASIGNEDDESKEY, * LPTTWFSPINIMPORTRSASIGNEDDESKEY;

	typedef struct _tt_wfs_pin_import_rsa_signed_des_key_output : public XFS300::_wfs_pin_import_rsa_signed_des_key_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_rsa_signed_des_key_output)
		~_tt_wfs_pin_import_rsa_signed_des_key_output() { SAFERELEASE(&this->lpxKeyCheckValue) }
		void WFS2TT(const XFS300::_wfs_pin_import_rsa_signed_des_key_output* obj)
		{
			this->wKeyLength						= obj->wKeyLength;
			this->wKeyCheckMode						= obj->wKeyCheckMode;
			DeviceUtility::CopyP(&this->lpxKeyCheckValue, obj->lpxKeyCheckValue);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_rsa_signed_des_key_output& obj)
		{
			out << " wKeyLength: "					<< obj.wKeyLength
				<< " wKeyCheckMode: "				<< obj.wKeyCheckMode
				<< " lpxKeyCheckValue: "			<< *obj.lpxKeyCheckValue;
			return out;
		}
		LPTTWFSXDATA lpxKeyCheckValue;
	} TTWFSPINIMPORTRSASIGNEDDESKEYOUTPUT, * LPTTWFSPINIMPORTRSASIGNEDDESKEYOUTPUT;

	typedef struct _tt_wfs_pin_generate_rsa_key : XFS300::_wfs_pin_generate_rsa_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_generate_rsa_key)
		~_tt_wfs_pin_generate_rsa_key()
		{
			SAFEPTR(this->lpWFSPINGENERATERSAKEYPAIR)
			{
				SAFEFREEMEMORY(&this->lpWFSPINGENERATERSAKEYPAIR->lpsKey);
				SAFERELEASE(&this->lpWFSPINGENERATERSAKEYPAIR);
			}
		}
		void WFS2TT(const _wfs_pin_generate_rsa_key* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			this->dwUse								= obj->dwUse;
			this->wModulusLength					= obj->wModulusLength;
			this->wExponentValue					= obj->wExponentValue;
		}
		void WFS(XFS300::LPWFSPINGENERATERSAKEYPAIR* lppWFSPINGENERATERSAKEYPAIR)
		{
			this->lpWFSPINGENERATERSAKEYPAIR = new XFS300::WFSPINGENERATERSAKEYPAIR;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINGENERATERSAKEYPAIR->lpsKey, this->lpsKey);
			this->lpWFSPINGENERATERSAKEYPAIR->dwUse								= this->dwUse;
			this->lpWFSPINGENERATERSAKEYPAIR->wModulusLength					= this->wModulusLength;
			this->lpWFSPINGENERATERSAKEYPAIR->wExponentValue					= this->wExponentValue;
			*lppWFSPINGENERATERSAKEYPAIR = this->lpWFSPINGENERATERSAKEYPAIR;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_generate_rsa_key& obj)
		{
			out << " lpsKey: "						<< obj.lpsKey.c_str()
				<< " dwUse: "						<< obj.dwUse
				<< " wModulusLength: "				<< obj.wModulusLength
				<< " wExponentValue: "				<< obj.wExponentValue;
			return out;
		}
		std::string  lpsKey;
		XFS300::LPWFSPINGENERATERSAKEYPAIR lpWFSPINGENERATERSAKEYPAIR = nullptr;
	} TTWFSPINGENERATERSAKEYPAIR, * LPTTWFSPINGENERATERSAKEYPAIR;

	typedef struct _tt_wfs_pin_export_rsa_epp_signed_item : public XFS300::_wfs_pin_export_rsa_epp_signed_item
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_export_rsa_epp_signed_item)
		~_tt_wfs_pin_export_rsa_epp_signed_item()
		{
			SAFEPTR(this->lpWFSPINEXPORTRSAEPPSIGNEDITEM)
			{
				SAFEFREEMEMORY(&this->lpWFSPINEXPORTRSAEPPSIGNEDITEM->lpsName);
				SAFEFREEMEMORY(&this->lpWFSPINEXPORTRSAEPPSIGNEDITEM->lpsSigKey);
				SAFERELEASE(&this->lpWFSPINEXPORTRSAEPPSIGNEDITEM);
			}
		}
		void WFS2TT(const _wfs_pin_export_rsa_epp_signed_item* obj)
		{
			this->wExportItemType					= obj->wExportItemType;
			this->lpsName.assign(obj->lpsName);
			this->lpsSigKey.assign(obj->lpsSigKey);
			this->dwSignatureAlgorithm				= obj->dwSignatureAlgorithm;
		}
		void WFS(XFS300::LPWFSPINEXPORTRSAEPPSIGNEDITEM* lppWFSPINEXPORTRSAEPPSIGNEDITEM)
		{
			this->lpWFSPINEXPORTRSAEPPSIGNEDITEM = new XFS300::WFSPINEXPORTRSAEPPSIGNEDITEM;
			this->lpWFSPINEXPORTRSAEPPSIGNEDITEM->wExportItemType					= this->wExportItemType;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINEXPORTRSAEPPSIGNEDITEM->lpsName, this->lpsName);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINEXPORTRSAEPPSIGNEDITEM->lpsSigKey, this->lpsSigKey);
			this->lpWFSPINEXPORTRSAEPPSIGNEDITEM->dwSignatureAlgorithm				= this->dwSignatureAlgorithm;
			*lppWFSPINEXPORTRSAEPPSIGNEDITEM = this->lpWFSPINEXPORTRSAEPPSIGNEDITEM;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_export_rsa_epp_signed_item& obj)
		{
			out << " wExportItemType: "				<< obj.wExportItemType
				<< " lpsName: "						<< obj.lpsName.c_str()
				<< " lpsSigKey: "					<< obj.lpsSigKey.c_str()
				<< " dwSignatureAlgorithm: "		<< obj.dwSignatureAlgorithm;
			return out;
		}
		std::string     lpsName;
		std::string     lpsSigKey;
		XFS300::LPWFSPINEXPORTRSAEPPSIGNEDITEM lpWFSPINEXPORTRSAEPPSIGNEDITEM = nullptr;
	} TTWFSPINEXPORTRSAEPPSIGNEDITEM, * LPTTWFSPINEXPORTRSAEPPSIGNEDITEM;

	typedef struct _tt_wfs_pin_export_rsa_epp_signed_item_output : public XFS300::_wfs_pin_export_rsa_epp_signed_item_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_export_rsa_epp_signed_item_output)
		~_tt_wfs_pin_export_rsa_epp_signed_item_output() { SAFERELEASE(&this->lpxValue) SAFERELEASE(&this->lpxSelfSignature) SAFERELEASE(&this->lpxSignature) }
		void WFS2TT(const XFS300::_wfs_pin_export_rsa_epp_signed_item_output* obj)
		{
			DeviceUtility::CopyP(&this->lpxValue, obj->lpxValue);
			DeviceUtility::CopyP(&this->lpxSelfSignature, obj->lpxSelfSignature);
			DeviceUtility::CopyP(&this->lpxSignature, obj->lpxSignature);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_export_rsa_epp_signed_item_output& obj)
		{
			out << " lpxValue: "					<< *obj.lpxValue
				<< " lpxSelfSignature: "			<< *obj.lpxSelfSignature
				<< " lpxSignature: "				<< *obj.lpxSignature;
			return out;
		}
		LPTTWFSXDATA lpxValue;
		LPTTWFSXDATA lpxSelfSignature;
		LPTTWFSXDATA lpxSignature;
	} TTWFSPINEXPORTRSAEPPSIGNEDITEMOUTPUT, * LPTTWFSPINEXPORTRSAEPPSIGNEDITEMOUTPUT;

	typedef struct _tt_wfs_pin_load_certificate : public XFS300::_wfs_pin_load_certificate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_load_certificate)
		~_tt_wfs_pin_load_certificate() { SAFERELEASE(&this->lpxLoadCertificate) }
		void WFS2TT(const _wfs_pin_load_certificate* obj)
		{
			DeviceUtility::CopyP(&this->lpxLoadCertificate, obj->lpxLoadCertificate);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINLOADCERTIFICATE* lppWFSPINLOADCERTIFICATE)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_load_certificate& obj)
		{
			out << " lpxLoadCertificate: " << obj.lpxLoadCertificate;
			return out;
		}
		LPTTWFSXDATA   lpxLoadCertificate;
	} TTWFSPINLOADCERTIFICATE, * LPTTWFSPINLOADCERTIFICATE;

	typedef struct _tt_wfs_pin_load_certificate_output : public XFS300::_wfs_pin_load_certificate_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_load_certificate_output)
		~_tt_wfs_pin_load_certificate_output() { SAFERELEASE(&this->lpxCertificateData) }
		void WFS2TT(const XFS300::_wfs_pin_load_certificate_output* obj)
		{
			DeviceUtility::CopyP(&this->lpxCertificateData, obj->lpxCertificateData);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_load_certificate_output& obj)
		{
			out << " lpxCertificateData: "			<< *obj.lpxCertificateData;
			return out;
		}
		LPTTWFSXDATA lpxCertificateData;
	} TTWFSPINLOADCERTIFICATEOUTPUT, * LPTTWFSPINLOADCERTIFICATEOUTPUT;

	typedef struct _tt_wfs_pin_get_certificate : public XFS300::_wfs_pin_get_certificate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_get_certificate)
		~_tt_wfs_pin_get_certificate() { SAFERELEASE(&this->lpWFSPINGETCERTIFICATE) }
		void WFS2TT(const _wfs_pin_get_certificate* obj)
		{
			this->wGetCertificate					= obj->wGetCertificate;
		}
		void WFS(XFS300::LPWFSPINGETCERTIFICATE* lppWFSPINGETCERTIFICATE)
		{
			this->lpWFSPINGETCERTIFICATE = new XFS300::WFSPINGETCERTIFICATE;
			this->lpWFSPINGETCERTIFICATE->wGetCertificate					= this->wGetCertificate;
			*lppWFSPINGETCERTIFICATE = this->lpWFSPINGETCERTIFICATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_get_certificate& obj)
		{
			out << " wGetCertificate: "				<< obj.wGetCertificate;
			return out;
		}
		XFS300::LPWFSPINGETCERTIFICATE lpWFSPINGETCERTIFICATE = nullptr;
	} TTWFSPINGETCERTIFICATE, * LPTTWFSPINGETCERTIFICATE;

	typedef struct _tt_wfs_pin_get_certificate_output : public XFS300::_wfs_pin_get_certificate_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_get_certificate_output)
			void WFS2TT(const XFS300::_wfs_pin_get_certificate_output* obj)
		{
			DeviceUtility::CopyP(&this->lpxCertificate, obj->lpxCertificate);
		}
		~_tt_wfs_pin_get_certificate_output() { SAFERELEASE(&this->lpxCertificate) }
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_get_certificate_output& obj)
		{
			out << " lpxCertificateData: "			<< *obj.lpxCertificate;
			return out;
		}
		LPTTWFSXDATA lpxCertificate;
	} TTWFSPINGETCERTIFICATEOUTPUT, * LPTTWFSPINGETCERTIFICATEOUTPUT;

	typedef struct _tt_wfs_pin_replace_certificate : public XFS300::wfs_pin_replace_certificate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_replace_certificate)
		~_tt_wfs_pin_replace_certificate() { SAFERELEASE(&this->lpxReplaceCertificate) }
		void WFS2TT(const wfs_pin_replace_certificate* obj)
		{
			DeviceUtility::CopyP(&this->lpxReplaceCertificate, obj->lpxReplaceCertificate);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINREPLACECERTIFICATE* lppWFSPINREPLACECERTIFICATE)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_replace_certificate& obj)
		{
			out << " lpxReplaceCertificate: "		<< *obj.lpxReplaceCertificate;
			return out;
		}
		LPTTWFSXDATA   lpxReplaceCertificate;
	} TTWFSPINREPLACECERTIFICATE, * LPTTWFSPINREPLACECERTIFICATE;

	typedef struct _tt_wfs_pin_replace_certificate_output : public XFS300::_wfs_pin_replace_certificate_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_replace_certificate_output)
		~_tt_wfs_pin_replace_certificate_output() { SAFERELEASE(&this->lpxNewCertificateData) }
		void WFS2TT(const XFS300::_wfs_pin_replace_certificate_output* obj)
		{
			DeviceUtility::CopyP(&this->lpxNewCertificateData, obj->lpxNewCertificateData);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_replace_certificate_output& obj)
		{
			out << " lpxNewCertificateData: "		<< *obj.lpxNewCertificateData;
			return out;
		}
		LPTTWFSXDATA lpxNewCertificateData;
	} TTWFSPINREPLACECERTIFICATEOUTPUT, * LPTTWFSPINREPLACECERTIFICATEOUTPUT;

	typedef struct _tt_wfs_pin_start_key_exchange : public XFS300::_wfs_pin_start_key_exchange
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_start_key_exchange)
		~_tt_wfs_pin_start_key_exchange() { SAFERELEASE(&this->lpxRandomItem) }
		void WFS2TT(const _wfs_pin_start_key_exchange* obj)
		{
			DeviceUtility::CopyP(&this->lpxRandomItem, obj->lpxRandomItem);
		}
		// needs attention
		void WFS(XFS300::LPWFSPINSTARTKEYEXCHANGE* lppWFSPINSTARTKEYEXCHANGE)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_start_key_exchange& obj)
		{
			out << " lpxRandomItem: "				<< obj.lpxRandomItem;
			return out;
		}
		LPTTWFSXDATA   lpxRandomItem;
	} TTWFSPINSTARTKEYEXCHANGE, * LPTTWFSPINSTARTKEYEXCHANGE;

	typedef struct _tt_wfs_pin_import_rsa_enciphered_pkcs7_key : public XFS300::_wfs_pin_import_rsa_enciphered_pkcs7_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_rsa_enciphered_pkcs7_key)
		~_tt_wfs_pin_import_rsa_enciphered_pkcs7_key() { SAFERELEASE(&this->lpxImportRSAKeyIn) }
		void WFS2TT(const _wfs_pin_import_rsa_enciphered_pkcs7_key* obj)
		{
			DeviceUtility::CopyP(&this->lpxImportRSAKeyIn, obj->lpxImportRSAKeyIn);
			this->lpsKey.assign(obj->lpsKey);
			this->dwUse								= obj->dwUse;
		}
		// needs attention
		void WFS(XFS300::LPWFSPINIMPORTRSAENCIPHEREDPKCS7KEY* lppWFSPINIMPORTRSAENCIPHEREDPKCS7KEY)
		{

		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_rsa_enciphered_pkcs7_key& obj)
		{
			out << " lpxImportRSAKeyIn: "			<< *obj.lpxImportRSAKeyIn
				<< " lpsKey: "						<< obj.lpsKey
				<< " dwUse: "						<< obj.dwUse;
			return out;
		}
		LPTTWFSXDATA	lpxImportRSAKeyIn;
		std::string		lpsKey;
	} TTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY, * LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY;

	typedef struct _tt_wfs_pin_import_rsa_enciphered_pkcs7_key_output : public XFS300::_wfs_pin_import_rsa_enciphered_pkcs7_key_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_import_rsa_enciphered_pkcs7_key_output)
		~_tt_wfs_pin_import_rsa_enciphered_pkcs7_key_output() { SAFERELEASE(&this->lpxRSAData) }
		void WFS2TT(const XFS300::_wfs_pin_import_rsa_enciphered_pkcs7_key_output* obj)
		{
			this->wKeyLength						= obj->wKeyLength;
			DeviceUtility::CopyP(&this->lpxRSAData, obj->lpxRSAData);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_import_rsa_enciphered_pkcs7_key_output& obj)
		{
			out << " wKeyLength: "					<< obj.wKeyLength
				<< " lpxKeyCheckValue: "			<< *obj.lpxRSAData;
			return out;
		}
		LPTTWFSXDATA lpxRSAData;
	} TTWFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT, * LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT;
	
	typedef struct _tt_wfs_pin_emv_import_public_key : public XFS300::_wfs_pin_emv_import_public_key
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_emv_import_public_key)
		~_tt_wfs_pin_emv_import_public_key()
		{
			SAFERELEASE(&this->lpxImportData);
			SAFEPTR(this->lpWFSPINEMVIMPORTPUBLICKEY)
			{
				SAFEFREEMEMORY(&this->lpWFSPINEMVIMPORTPUBLICKEY->lpsKey);
				SAFERELEASE(&this->lpWFSPINEMVIMPORTPUBLICKEY->lpxImportData);
				SAFEFREEMEMORY(&this->lpWFSPINEMVIMPORTPUBLICKEY->lpsSigKey);
				SAFERELEASE(&this->lpWFSPINEMVIMPORTPUBLICKEY);
			}
		}
		void WFS2TT(const _wfs_pin_emv_import_public_key* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			this->dwUse								= obj->dwUse;
			this->wImportScheme						= obj->wImportScheme;
			DeviceUtility::CopyP(&this->lpxImportData, obj->lpxImportData);
			this->lpsSigKey.assign(obj->lpsSigKey);
		}
		void WFS(XFS300::LPWFSPINEMVIMPORTPUBLICKEY* lppWFSPINEMVIMPORTPUBLICKEY)
		{
			this->lpWFSPINEMVIMPORTPUBLICKEY = new XFS300::WFSPINEMVIMPORTPUBLICKEY;
			SAFEALLOCCOPYSTRING(&this->lpWFSPINEMVIMPORTPUBLICKEY->lpsKey, this->lpsKey);
			this->lpWFSPINEMVIMPORTPUBLICKEY->dwUse = this->dwUse;
			this->lpWFSPINEMVIMPORTPUBLICKEY->wImportScheme = this->wImportScheme;
			DeviceUtility::CopyP_r(&this->lpWFSPINEMVIMPORTPUBLICKEY->lpxImportData, this->lpxImportData);
			SAFEALLOCCOPYSTRING(&this->lpWFSPINEMVIMPORTPUBLICKEY->lpsSigKey, this->lpsSigKey);
			*lppWFSPINEMVIMPORTPUBLICKEY = this->lpWFSPINEMVIMPORTPUBLICKEY;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_emv_import_public_key& obj)
		{
			out << " lpsKey: " << obj.lpsKey.c_str()
				<< " dwUse: " << obj.dwUse
				<< " wImportScheme: " << obj.wImportScheme
				<< " lpxImportData: " << *obj.lpxImportData
				<< " lpsSigKey: " << obj.lpsSigKey.c_str();
			return out;
		}
		std::string         lpsKey;
		LPTTWFSXDATA		lpxImportData;
		std::string         lpsSigKey;
		XFS300::LPWFSPINEMVIMPORTPUBLICKEY lpWFSPINEMVIMPORTPUBLICKEY = nullptr;
	} TTWFSPINEMVIMPORTPUBLICKEY, * LPTTWFSPINEMVIMPORTPUBLICKEY;

	typedef struct _tt_wfs_pin_emv_import_public_key_output : public XFS300::_wfs_pin_emv_import_public_key_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_emv_import_public_key_output)
			~_tt_wfs_pin_emv_import_public_key_output() { SAFERELEASE(&this->lpsExpiryDate) }
		void WFS2TT(const XFS300::_wfs_pin_emv_import_public_key_output* obj)
		{
			SAFEALLOCCOPYMEMORY(&this->lpsExpiryDate, obj->lpsExpiryDate, DeviceUtility::Size_LPSTR(obj->lpsExpiryDate));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_emv_import_public_key_output& obj)
		{
			out << " lpxNewCertificateData: " << *obj.lpsExpiryDate;
			return out;
		}
	} TTWFSPINEMVIMPORTPUBLICKEYOUTPUT, * LPTTWFSPINEMVIMPORTPUBLICKEYOUTPUT;

	typedef struct _tt_wfs_pin_digest : public XFS300::_wfs_pin_digest
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_digest)
			~_tt_wfs_pin_digest()
		{
			SAFERELEASE(&this->lpxDigestInput);
			SAFEPTR(this->lpWFSPINDIGEST)
			{
				SAFERELEASE(&this->lpWFSPINDIGEST->lpxDigestInput);
				SAFERELEASE(&this->lpWFSPINDIGEST);
			}
		}
		void WFS2TT(const _wfs_pin_digest* obj)
		{
			this->wHashAlgorithm = obj->wHashAlgorithm;
			DeviceUtility::CopyP(&this->lpxDigestInput, obj->lpxDigestInput);
		}
		void WFS(XFS300::LPWFSPINDIGEST* lppWFSPINDIGEST)
		{
			this->lpWFSPINDIGEST = new XFS300::WFSPINDIGEST;
			this->lpWFSPINDIGEST->wHashAlgorithm = this->wHashAlgorithm;
			DeviceUtility::CopyP_r(&this->lpWFSPINDIGEST->lpxDigestInput, this->lpxDigestInput);
			*lppWFSPINDIGEST = this->lpWFSPINDIGEST;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_digest& obj)
		{
			out << " wHashAlgorithm: " << obj.wHashAlgorithm
				<< " lpxDigestInput: " << *obj.lpxDigestInput;
			return out;
		}
		LPTTWFSXDATA    lpxDigestInput;
		XFS300::LPWFSPINDIGEST lpWFSPINDIGEST = nullptr;
	} TTWFSPINDIGEST, * LPTTWFSPINDIGEST;

	typedef struct _tt_wfs_pin_digest_output : public XFS300::_wfs_pin_digest_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_digest_output)
		~_tt_wfs_pin_digest_output() { SAFERELEASE(&this->lpxDigestOutput) }
		void WFS2TT(const XFS300::_wfs_pin_digest_output* obj)
		{
			DeviceUtility::CopyP(&this->lpxDigestOutput, obj->lpxDigestOutput);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_digest_output& obj)
		{
			out << " lpxDigestOutput: " << *obj.lpxDigestOutput;
			return out;
		}
		LPTTWFSXDATA lpxDigestOutput;
	} TTWFSPINDIGESTOUTPUT, * LPTTWFSPINDIGESTOUTPUT;

	typedef struct _tt_wfs_pin_hsm_init : public XFS300::_wfs_pin_hsm_init
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_hsm_init)
		~_tt_wfs_pin_hsm_init()
		{
			SAFERELEASE(&this->lpxOnlineTime);
			SAFEPTR(this->lpWFSPINHSMINIT)
			{
				SAFERELEASE(&this->lpWFSPINHSMINIT->lpxOnlineTime);
				SAFERELEASE(&this->lpWFSPINHSMINIT);
			}
		}
		void WFS2TT(const _wfs_pin_hsm_init* obj)
		{
			this->wInitMode							= obj->wInitMode;
			DeviceUtility::CopyP(&this->lpxOnlineTime, obj->lpxOnlineTime);
		}
		void WFS(XFS300::LPWFSPINHSMINIT* lppWFSPINHSMINIT)
		{
			this->lpWFSPINHSMINIT = new XFS300::WFSPINHSMINIT;
			this->lpWFSPINHSMINIT->wInitMode							= this->wInitMode;
			DeviceUtility::CopyP_r(&this->lpWFSPINHSMINIT->lpxOnlineTime, this->lpxOnlineTime);
			*lppWFSPINHSMINIT = this->lpWFSPINHSMINIT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_hsm_init& obj)
		{
			out << " wInitMode: "					<< obj.wInitMode
				<< " lpxOnlineTime: "				<< *obj.lpxOnlineTime;
			return out;
		}
		LPTTWFSXDATA lpxOnlineTime;
		XFS300::LPWFSPINHSMINIT lpWFSPINHSMINIT = nullptr;
	} TTWFSPINHSMINIT, * LPTTWFSPINHSMINIT;

	typedef struct _tt_wfs_pin_generate_KCV : public XFS300::_wfs_pin_generate_KCV
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_generate_KCV)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_generate_KCV)
		void WFS2TT(const _tt_wfs_pin_generate_KCV* obj)
		{
			this->lpsKey.assign(obj->lpsKey);
			this->wKeyCheckMode						= obj->wKeyCheckMode;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_generate_KCV& obj)
		{
			out << " lpsKey: "						<< obj.lpsKey.c_str()
				<< " wKeyCheckMode: "				<< obj.wKeyCheckMode;
			return out;
		}
		std::string lpsKey;
	} TTWFSPINGENERATEKCV, * LPTTWFSPINGENERATEKCV;

	typedef struct _tt_wfs_pin_kcv : public XFS300::_wfs_pin_kcv
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_kcv)
		~_tt_wfs_pin_kcv() { SAFERELEASE(&this->lpxKCV) }
		void WFS2TT(const _wfs_pin_kcv* obj)
		{
			DeviceUtility::CopyP(&this->lpxKCV, obj->lpxKCV);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_kcv& obj)
		{
			out << " lpxKCV: "						<< *obj.lpxKCV;
			return out;
		}
		LPTTWFSXDATA lpxKCV;
	} TTWFSPINKCV, * LPTTWFSPINKCV;

	typedef struct _tt_wfs_pin_lpbool
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_lpbool)
			void WFS2TT(const LPBOOL obj)
		{
			this->_bool								= *obj;
		}
		DEFAULTDESTRUCTOR(_tt_wfs_pin_lpbool)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_lpbool& obj)
		{
			out << "lpBool: "						<< obj._bool;
			return out;
		}
		BOOL _bool;
	} TTWFSPINBOOL, * LPTTWFSPINBOOL;

	typedef struct _tt_wfs_pin_lpstr
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_lpstr)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_lpstr)
		void WFS2TT(const LPSTR obj)
		{
			this->_str.assign(obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_lpstr& obj)
		{
			out << "lpstr: "						<< obj._str;
			return out;
		}
		std::string _str;
	} TTWFSPINLPSTR, * LPTTWFSPINLPSTR;

	/*=================================================================*/
	/* PIN Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_pin_access : public XFS300::_wfs_pin_access
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_pin_access)
		DEFAULTDESTRUCTOR(_tt_wfs_pin_access)
		void WFS2TT(const _wfs_pin_access* obj)
		{
			this->lpsKeyName.assign(obj->lpsKeyName);
			this->lErrorCode						= obj->lErrorCode;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_pin_access& obj)
		{
			out << " lpsKeyName: "					<< obj.lpsKeyName.c_str()
				<< " lErrorCode: "					<< obj.lErrorCode;
			return out;
		}
		std::string lpsKeyName;
	} TTWFSPINACCESS, * LPTTWFSPINACCESS;

#pragma pack(pop)

	/*=================================================================*/
	/* PIN Interface */
	/*=================================================================*/

	class ITTPIN : public ITTDevice
	{
	public:
		ITTPIN() = default;
		ITTPIN(const ITTPIN&) = delete;
		ITTPIN(ITTPIN&&) = delete;
		ITTPIN& operator = (const ITTPIN&) = delete;
		ITTPIN& operator = (ITTPIN&&) = delete;
		virtual ~ITTPIN() = default;

		/* PIN Info Commands */
		virtual bool GetStatus(LPTTWFSPINSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSPINCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetKeyDetail(const LPSTR, LPTTWFSPINP2APKEYDETAIL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetFuncKeyDetail(const LPULONG, LPTTWFSPINFUNCKEYDETAIL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetHSMTData(LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetKeyDetailEx(const LPSTR, LPTTWFSPINP2APKEYDETAILEX, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetKeyDetail(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetFuncKeyDetail(LPULONG, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetHSMTData(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetKeyDetailEx(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* PIN Execute Commands */

		/// Normal PIN Commands
		virtual bool Crypt(const LPTTWFSPINCRYPT, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ImportKey(const LPTTWFSPINIMPORT, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool DeriveKey(const LPTTWFSPINDERIVE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetPin(const LPTTWFSPINGETPIN, LPTTWFSPINENTRY, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool LocalDES(const LPTTWFSPINLOCALDES, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CreateOffset(const LPTTWFSPINCREATEOFFSET, LPTTWFSPINLPSTR, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool LocalEuroCheque(const LPTTWFSPINLOCALEUROCHEQUE, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool LocalVisa(const LPTTWFSPINLOCALVISA, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool PresentIDC(const LPTTWFSPINPRESENTIDC, LPTTWFSPINPRESENTRESULT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetPinBlock(const LPTTWFSPINBLOCK, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetData(const LPTTWFSPINGETDATA, LPTTWFSPINDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Initialization(const LPTTWFSPININIT, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool LocalBankSYS(const LPTTWFSPINLOCALBANKSYS, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool BankSYSIO(const LPTTWFSPINBANKSYSIO, LPTTWFSPINBANKSYSIO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool HSMSetTData(const LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SecureMSGSend(const LPTTWFSPINSECMSG, LPTTWFSPINSECMSG, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SecureMSGReceive(const LPTTWFSPINSECMSG, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetJournal(const LPWORD, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ImportKeyEx(const LPTTWFSPINIMPORTKEYEX, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ENCIO(const LPTTWFSPINENCIO, LPTTWFSPINENCIO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool HSMInit(const LPTTWFSPINHSMINIT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncCrypt(const LPTTWFSPINCRYPT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncImportKey(const LPTTWFSPINIMPORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDeriveKey(const LPTTWFSPINDERIVE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetPin(const LPTTWFSPINGETPIN, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncLocalDES(const LPTTWFSPINLOCALDES, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCreateOffset(const LPTTWFSPINCREATEOFFSET, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncLocalEuroCheque(const LPTTWFSPINLOCALEUROCHEQUE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncLocalVisa(const LPTTWFSPINLOCALVISA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncPresentIDC(const LPTTWFSPINPRESENTIDC, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetPinBlock(const LPTTWFSPINBLOCK, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetData(const LPTTWFSPINGETDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncInitialization(const LPTTWFSPININIT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncLocalBankSYS(const LPTTWFSPINLOCALBANKSYS, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncBankSYSIO(const LPTTWFSPINBANKSYSIO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncHSMSetTData(const LPTTWFSXDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSecureMSGSend(const LPTTWFSPINSECMSG, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSecureMSGReceive(const LPTTWFSPINSECMSG, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetJournal(const LPWORD , REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncImportKeyEx(const LPTTWFSPINIMPORTKEYEX, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncENCIO(const LPTTWFSPINENCIO , REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncHSMInit(const LPTTWFSPINHSMINIT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/// Common Commands forRemote Key Loading Schemes
		virtual bool StartKeyExchange(const LPTTWFSPINSTARTKEYEXCHANGE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncStartKeyExchange(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/// Remote Key Loading Using Signature
		virtual bool ImportRSAPublicKey(const LPTTWFSPINIMPORTRSAPUBLICKEY, LPTTWFSPINIMPORTRSAPUBLICKEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ExportRSAIssuerSignedItem(const LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM, LPTTWFSPINEXPORTRSAISSUERSIGNEDITEMOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ImportRSASignedDESKey(const LPTTWFSPINIMPORTRSASIGNEDDESKEY, LPTTWFSPINIMPORTRSASIGNEDDESKEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GenerateRSAKeyPair(const LPTTWFSPINGENERATERSAKEYPAIR, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ExportRSAEPPSignedItem(const LPTTWFSPINEXPORTRSAEPPSIGNEDITEM, LPTTWFSPINEXPORTRSAEPPSIGNEDITEMOUTPUT, const DWORD = DEFAULT_TIMEOUT)  noexcept = 0;

		virtual bool AsyncImportRSAPublicKey(const LPTTWFSPINIMPORTRSAPUBLICKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncExportRSAIssuerSignedItem(const LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncImportRSASignedDESKey(const LPTTWFSPINIMPORTRSASIGNEDDESKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGenerateRSAKeyPair(const LPTTWFSPINGENERATERSAKEYPAIR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncExportRSAEPPSignedItem(const LPTTWFSPINEXPORTRSAEPPSIGNEDITEM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT)  noexcept = 0;

		/// Remote Key Loading Using CERTIFICATES
		virtual bool LoadCertificate(const LPTTWFSPINLOADCERTIFICATE, LPTTWFSPINLOADCERTIFICATEOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCertificate(const LPTTWFSPINGETCERTIFICATE, LPTTWFSPINGETCERTIFICATEOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ReplaceCertificate(const LPTTWFSPINREPLACECERTIFICATE, LPTTWFSPINREPLACECERTIFICATEOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ImportRSAEncipheredPKCS7Key(const LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY, LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncLoadCertificate(const LPTTWFSPINLOADCERTIFICATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCertificate(const LPTTWFSPINGETCERTIFICATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReplaceCertificate(const LPTTWFSPINREPLACECERTIFICATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncImportRSAEncipheredPKCS7Key(const LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/// EMV
		virtual bool EMVImportPublicKey(const LPTTWFSPINEMVIMPORTPUBLICKEY, LPTTWFSPINEMVIMPORTPUBLICKEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Digest(const LPTTWFSPINDIGEST, LPTTWFSPINDIGESTOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncEMVImportPublicKey(const LPTTWFSPINEMVIMPORTPUBLICKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDigest(const LPTTWFSPINDIGEST, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTPIN__
