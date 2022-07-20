
#pragma once

#ifndef __H_ITTCIM__
#define __H_ITTCIM__

#include <TTFRM_Include\TTFrameworkUtility.h>
#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* CIM Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cim_inpos : public XFS300::_wfs_cim_inpos
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_inpos)
		DEFAULTDESTRUCTOR(_tt_wfs_cim_inpos)
		void WFS2TT(const XFS300::_wfs_cim_inpos* obj)
		{
			this->fwPosition									= obj->fwPosition;
			this->fwShutter										= obj->fwShutter;
			this->fwPositionStatus								= obj->fwPositionStatus;
			this->fwTransport									= obj->fwTransport;
			this->fwTransportStatus								= obj->fwTransportStatus;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_inpos& obj)
		{
			out << " - "
				<< " fwPosition: "								<< obj.fwPosition
				<< " fwShutter: "								<< obj.fwShutter
				<< " fwPositionStatus: "						<< obj.fwPositionStatus
				<< " fwTransport: "								<< obj.fwTransport
				<< " fwTransportStatus: "						<< obj.fwTransportStatus;
			return out;
		}
	} TTWFSCIMINPOS, * LPTTWFSCIMINPOS;

	typedef struct _tt_wfs_cim_status : public XFS300::_wfs_cim_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_status)
		~_tt_wfs_cim_status() { SAFERELEASECONT(this->lppPositions); }
		void WFS2TT(const XFS300::_wfs_cim_status* obj)
		{
			this->fwDevice										= obj->fwDevice;
			this->fwSafeDoor									= obj->fwSafeDoor;
			this->fwAcceptor									= obj->fwAcceptor;
			this->fwIntermediateStacker							= obj->fwIntermediateStacker;
			this->fwStackerItems								= obj->fwStackerItems;
			this->fwBanknoteReader								= obj->fwBanknoteReader;
			this->bDropBox										= obj->bDropBox;
			DeviceUtility::CopyP2NAPs(this->lppPositions, obj->lppPositions);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_status& obj)
		{
			out << " fwDevice: "								<< obj.fwDevice
				<< " fwSafeDoor: "								<< obj.fwSafeDoor
				<< " fwAcceptor: "								<< obj.fwAcceptor
				<< " fwIntermediateStacker: "					<< obj.fwIntermediateStacker
				<< " fwStackerItems: "							<< obj.fwStackerItems
				<< " fwBanknoteReader: "						<< obj.fwBanknoteReader
				<< " bDropBox: "								<< obj.bDropBox
				<< " fwIntermediateStacker: "					<< obj.fwIntermediateStacker
				<< " fwStackerItems: "							<< obj.fwStackerItems
				<< " lppPosition: "								<< DeviceUtility::TTCONT2Str(obj.lppPositions).c_str()
				<< std::endl
				<< " lpszExtra: "								<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMINPOS>	lppPositions;
		DeviceUtility::STRVECT					lpszExtra;
	} TTWFSCIMSTATUS, * LPTTWFSCIMSTATUS;

	typedef struct _tt_wfs_cim_caps : public XFS300::_wfs_cim_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_cim_caps)
		void WFS2TT(const XFS300::_wfs_cim_caps* obj)
		{
			this->wClass										= obj->wClass;
			this->fwType										= obj->fwType;
			this->wMaxCashInItems								= obj->wMaxCashInItems;
			this->bCompound										= obj->bCompound;
			this->bShutter										= obj->bShutter;
			this->bShutterControl								= obj->bShutterControl;
			this->bSafeDoor										= obj->bSafeDoor;
			this->bCashBox										= obj->bCashBox;
			this->bRefill										= obj->bRefill;
			this->fwIntermediateStacker							= obj->fwIntermediateStacker;
			this->bItemsTakenSensor								= obj->bItemsTakenSensor;
			this->bItemsInsertedSensor							= obj->bItemsInsertedSensor;
			this->fwPositions									= obj->fwPositions;
			this->fwExchangeType								= obj->fwExchangeType;
			this->fwRetractAreas								= obj->fwRetractAreas;
			this->fwRetractTransportActions						= obj->fwRetractTransportActions;
			this->fwRetractStackerActions						= obj->fwRetractStackerActions;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_caps& obj)
		{
			out << " wClass: "									<< obj.wClass
				<< " fwType: "									<< obj.fwType
				<< " wMaxCashInItems: "							<< obj.wMaxCashInItems
				<< " bCompound: "								<< obj.bCompound
				<< " bShutter: "								<< obj.bShutter
				<< " bShutterControl: "							<< obj.bShutterControl
				<< " bSafeDoor: "								<< obj.bSafeDoor
				<< " bCashBox: "								<< obj.bCashBox
				<< " bRefill: "									<< obj.bRefill
				<< " fwIntermediateStacker: "					<< obj.fwIntermediateStacker
				<< " bItemsTakenSensor: "						<< obj.bItemsTakenSensor
				<< " bItemsInsertedSensor: "					<< obj.bItemsInsertedSensor
				<< " fwPositions: "								<< obj.fwPositions
				<< " fwExchangeType: "							<< obj.fwExchangeType
				<< " fwRetractAreas: "							<< obj.fwRetractAreas
				<< " fwRetractTransportActions: "				<< obj.fwRetractTransportActions
				<< " fwRetractStackerActions: "					<< obj.fwRetractStackerActions
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSCIMCAPS, * LPTTWFSCIMCAPS;

	typedef struct _tt_wfs_cim_physicalcu : public XFS300::_wfs_cim_physicalcu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_physicalcu)
		~_tt_wfs_cim_physicalcu()
		{
			TRACELOG("~_tt_wfs_cim_physicalcu");
			SAFEPTR(this->lpWFSCIMPHCU)
			{
				SAFEFREEMEMORY(&this->lpWFSCIMPHCU->lpPhysicalPositionName);
				SAFERELEASE(&this->lpWFSCIMPHCU);
			}
			TRACELOG("~_tt_wfs_cim_physicalcu");
		}
		void WFS2TT(const XFS300::_wfs_cim_physicalcu* obj)
		{
			lpPhysicalPositionName.assign(obj->lpPhysicalPositionName, DeviceUtility::Size_LPSTR(obj->lpPhysicalPositionName));
			this->cUnitID.assign(obj->cUnitID, 5);
			this->ulCashInCount									= obj->ulCashInCount;
			this->ulCount										= obj->ulCount;
			this->ulMaximum										= obj->ulMaximum;
			this->usPStatus										= obj->usPStatus;
			this->bHardwareSensors								= obj->bHardwareSensors;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		void WFS(XFS300::LPWFSCIMPHCU* lppWFSCIMPHCU)
		{
			this->lpWFSCIMPHCU = new XFS300::WFSCIMPHCU;
			SAFEALLOCCOPYSTRING(&this->lpWFSCIMPHCU->lpPhysicalPositionName, this->lpPhysicalPositionName);
			SAFECOPYSTRING(this->lpWFSCIMPHCU->cUnitID, this->cUnitID);
			this->ulCashInCount									= this->ulCashInCount;
			this->ulCount										= this->ulCount;
			this->ulMaximum										= this->ulMaximum;
			this->usPStatus										= this->usPStatus;
			this->bHardwareSensors								= this->bHardwareSensors;
			*lppWFSCIMPHCU = this->lpWFSCIMPHCU;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_physicalcu& obj)
		{
			out << " -- "
				<< " lpPhysicalPositionName: "					<< obj.lpPhysicalPositionName.c_str()
				<< " cUnitID: "									<< obj.cUnitID.c_str()
				<< " ulCashInCount: "							<< obj.ulCashInCount
				<< " ulCount: "									<< obj.ulCount
				<< " ulMaximum: "								<< obj.ulMaximum
				<< " usPStatus: "								<< obj.usPStatus
				<< " bHardwareSensors: "						<< obj.bHardwareSensors
				<< " lpszExtra: "								<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::STRVECT		lpszExtra;
		std::string					lpPhysicalPositionName;
		std::string					cUnitID;
		XFS300::LPWFSCIMPHCU		lpWFSCIMPHCU = nullptr;
	} TTWFSCIMPHCU, * LPTTWFSCIMPHCU;

	typedef struct _tt_wfs_cim_note_number : public XFS300::_wfs_cim_note_number
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_note_number)
		~_tt_wfs_cim_note_number() 
		{
			TRACELOG("~_tt_wfs_cim_note_number_list"); 
			SAFERELEASE(&this->lpWFSCIMNOTENUMBER);
			TRACELOG("~_tt_wfs_cim_note_number_list");
		}
		void WFS2TT(const XFS300::_wfs_cim_note_number* obj)
		{
			this->usNoteID										= obj->usNoteID;
			this->ulCount										= obj->ulCount;
		}
		void WFS(XFS300::LPWFSCIMNOTENUMBER* lppWFSCIMNOTENUMBER)
		{
			this->lpWFSCIMNOTENUMBER = new XFS300::WFSCIMNOTENUMBER;
			this->usNoteID										= this->usNoteID;
			this->ulCount										= this->ulCount;
			*lppWFSCIMNOTENUMBER = this->lpWFSCIMNOTENUMBER;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_note_number& obj)
		{
			out << " -- "
				<< " usNoteID: "								<< obj.usNoteID
				<< " ulCount: "									<< obj.ulCount;
			return out;
		}
		XFS300::LPWFSCIMNOTENUMBER lpWFSCIMNOTENUMBER = nullptr;
	} TTWFSCIMNOTENUMBER, * LPTTWFSCIMNOTENUMBER;

	typedef struct _tt_wfs_cim_note_number_list : public XFS300::_wfs_cim_note_number_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_note_number_list)
		~_tt_wfs_cim_note_number_list() 
		{
			TRACELOG("~_tt_wfs_cim_note_number_list");
			SAFERELEASECONT(this->lppNoteNumber);
			SAFEPTR(this->lpWFSCIMNOTENUMBERLIST)
			{
				SAFERELEASELPP(this->lpWFSCIMNOTENUMBERLIST->lppNoteNumber, this->lpWFSCIMNOTENUMBERLIST->usNumOfNoteNumbers);
				SAFERELEASE(&this->lpWFSCIMNOTENUMBERLIST);
			}
			TRACELOG("~_tt_wfs_cim_note_number_list");
		}
		void WFS2TT(const _wfs_cim_note_number_list* obj)
		{
			this->usNumOfNoteNumbers							= obj->usNumOfNoteNumbers;
			DeviceUtility::CopyP2APs(this->lppNoteNumber, obj->lppNoteNumber, obj->usNumOfNoteNumbers);
		}
		void WFS(XFS300::LPWFSCIMNOTENUMBERLIST* lppWFSCIMNOTENUMBERLIST)
		{
			this->lpWFSCIMNOTENUMBERLIST = new XFS300::WFSCIMNOTENUMBERLIST;
			this->lpWFSCIMNOTENUMBERLIST->usNumOfNoteNumbers = this->usNumOfNoteNumbers;
			DeviceUtility::CopyP2APs_r(this->lpWFSCIMNOTENUMBERLIST->lppNoteNumber, this->lppNoteNumber);
			*lppWFSCIMNOTENUMBERLIST = this->lpWFSCIMNOTENUMBERLIST;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_note_number_list& obj)
		{
			out << " - "
				<< " usNumOfNoteNumbers: "						<< obj.usNumOfNoteNumbers
				<< " lppNoteNumber: "							<< DeviceUtility::TTCONT2Str(obj.lppNoteNumber).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMNOTENUMBER>	lppNoteNumber;
		XFS300::LPWFSCIMNOTENUMBERLIST lpWFSCIMNOTENUMBERLIST = nullptr;
	} TTWFSCIMNOTENUMBERLIST, * LPTTWFSCIMNOTENUMBERLIST;

	typedef struct _tt_wfs_cim_cash_in : public XFS300::_wfs_cim_cash_in
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_cash_in)
		~_tt_wfs_cim_cash_in()
		{
			//TRACELOG("~_tt_wfs_cim_cash_in");
			SAFERELEASE(&this->lpNoteNumberList);
			SAFERELEASECONT(this->lppPhysical);
			SAFEPTR(this->lpWFSCIMCASHIN)
			{
				SAFERELEASE(&this->lpWFSCIMCASHIN->lpNoteNumberList);
				SAFERELEASELPP(this->lpWFSCIMCASHIN->lppPhysical, this->lpWFSCIMCASHIN->usNumPhysicalCUs);
				SAFERELEASE(&this->lpWFSCIMCASHIN);
			}
			//TRACELOG("~_tt_wfs_cim_cash_in");
		}
		void WFS2TT(const XFS300::_wfs_cim_cash_in* obj)
		{
			this->usNumber										= obj->usNumber;
			this->fwType										= obj->fwType;
			this->fwItemType									= obj->fwItemType;
			this->cUnitID.assign(obj->cUnitID, 5);
			this->cCurrencyID.assign(obj->cCurrencyID, 3);
			this->ulValues										= obj->ulValues;
			this->ulCashInCount									= obj->ulCashInCount;
			this->ulCount										= obj->ulCount;
			this->ulMaximum										= obj->ulMaximum;
			this->usStatus										= obj->usStatus;
			this->bAppLock										= obj->bAppLock;
			DeviceUtility::CopyP(&this->lpNoteNumberList, obj->lpNoteNumberList);
			this->usNumPhysicalCUs					= obj->usNumPhysicalCUs;
			DeviceUtility::CopyP2APs(this->lppPhysical, obj->lppPhysical, obj->usNumPhysicalCUs);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		void WFS(XFS300::LPWFSCIMCASHIN* lppWFSCIMCASHIN)
		{
			this->lpWFSCIMCASHIN = new XFS300::WFSCIMCASHIN;
			this->lpWFSCIMCASHIN->usNumber						= this->usNumber;
			this->lpWFSCIMCASHIN->fwType						= this->fwType;
			this->lpWFSCIMCASHIN->fwItemType					= this->fwItemType;
			SAFECOPYSTRING(this->lpWFSCIMCASHIN->cUnitID, this->cUnitID);
			SAFECOPYSTRING(this->lpWFSCIMCASHIN->cCurrencyID, this->cCurrencyID);
			this->lpWFSCIMCASHIN->ulValues						= this->ulValues;
			this->lpWFSCIMCASHIN->ulCashInCount					= this->ulCashInCount;
			this->lpWFSCIMCASHIN->ulCount						= this->ulCount;
			this->lpWFSCIMCASHIN->ulMaximum						= this->ulMaximum;
			this->lpWFSCIMCASHIN->usStatus						= this->usStatus;
			this->lpWFSCIMCASHIN->bAppLock						= this->bAppLock;
			DeviceUtility::CopyP_r(&this->lpWFSCIMCASHIN->lpNoteNumberList, this->lpNoteNumberList);
			this->usNumPhysicalCUs					= this->usNumPhysicalCUs;
			DeviceUtility::CopyP2APs_r(this->lpWFSCIMCASHIN->lppPhysical, this->lppPhysical);
			*lppWFSCIMCASHIN = this->lpWFSCIMCASHIN;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_cash_in& obj)
		{
			out << " usNumber: "								<< obj.usNumber
				<< " fwType: "									<< obj.fwType
				<< " cUnitID: "									<< obj.cUnitID.c_str()
				<< " cCurrencyID: "								<< obj.cCurrencyID.c_str()
				<< " ulValues: "								<< obj.ulValues
				<< " ulCashInCount: "							<< obj.ulCashInCount
				<< " ulCount: "									<< obj.ulCount
				<< " ulMaximum: "								<< obj.ulMaximum
				<< " usStatus: "								<< obj.usStatus
				<< " bAppLock: "								<< obj.bAppLock
				<< " lpNoteNumberList: "						<< std::endl;
			SAFEPTR(obj.lpNoteNumberList)
				 out << *(obj.lpNoteNumberList) << std::endl;
			out << " usNumPhysicalCUs: "						<< obj.usNumPhysicalCUs
				<< " lppPhysical: "								<< DeviceUtility::TTCONT2Str(obj.lppPhysical).c_str()
				<< std::endl
				<< " lpszExtra: "								<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMPHCU>		lppPhysical;
		LPTTWFSCIMNOTENUMBERLIST					lpNoteNumberList{ nullptr };
		DeviceUtility::STRVECT						lpszExtra;
		std::string									cUnitID;
		std::string									cCurrencyID;
		XFS300::LPWFSCIMCASHIN						lpWFSCIMCASHIN = nullptr;
	} TTWFSCIMCASHIN, * LPTTWFSCIMCASHIN;

	typedef struct _tt_wfs_cim_cash_info : public XFS300::_wfs_cim_cash_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_cash_info)
		~_tt_wfs_cim_cash_info()
		{
			//TRACELOG("~_tt_wfs_cim_cash_info");
			SAFERELEASECONT(this->lppCashIn);
			SAFEPTR(this->lpWFSCIMCASHINFO)
			{
				SAFERELEASELPP(this->lpWFSCIMCASHINFO->lppCashIn, this->lppCashIn.size());
				SAFERELEASE(&this->lpWFSCIMCASHINFO);
			}
			//TRACELOG("~_tt_wfs_cim_cash_info");
		}
		void WFS2TT(const XFS300::_wfs_cim_cash_info* obj)
		{
			this->usCount										= obj->usCount;
			DeviceUtility::CopyP2APs(this->lppCashIn, obj->lppCashIn, obj->usCount);
		}
		void WFS(XFS300::LPWFSCIMCASHINFO* lppWFSCIMCASHINFO)
		{
			lpWFSCIMCASHINFO = new XFS300::WFSCIMCASHINFO;
			this->lpWFSCIMCASHINFO->usCount						= this->usCount;
			DeviceUtility::CopyP2APs_r(this->lpWFSCIMCASHINFO->lppCashIn, this->lppCashIn);
			*lppWFSCIMCASHINFO = this->lpWFSCIMCASHINFO;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_cash_info& obj)
		{
			out << " usCount: "									<< obj.usCount
				<< " lppCashIn: "								<< DeviceUtility::TTCONT2Str(obj.lppCashIn).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMCASHIN>	lppCashIn;
		XFS300::LPWFSCIMCASHINFO				lpWFSCIMCASHINFO = nullptr;
	} TTWFSCIMCASHINFO, * LPTTWFSCIMCASHINFO;

	typedef struct _tt_wfs_cim_teller_info : public XFS300::_wfs_cim_teller_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_teller_info)
		~_tt_wfs_cim_teller_info() { SAFERELEASE(&this->lpWFSCIMTELLERINFO) }
		void WFS2TT(const XFS300::_wfs_cim_teller_info* obj)
		{
			this->usTellerID									= obj->usTellerID;
			SAFECOPYMEMORY(this->cCurrencyID, obj->cCurrencyID, 3);
		}
		void WFS(XFS300::LPWFSCIMTELLERINFO* lppWFSCIMTELLERINFO)
		{
			this->lpWFSCIMTELLERINFO = new XFS300::WFSCIMTELLERINFO;
			this->lpWFSCIMTELLERINFO->usTellerID				= this->usTellerID;
			SAFECOPYMEMORY(this->lpWFSCIMTELLERINFO->cCurrencyID, this->cCurrencyID, 3);
			*lppWFSCIMTELLERINFO = this->lpWFSCIMTELLERINFO;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_teller_info& obj)
		{
			out << " usTellerID: "								<< obj.usTellerID
				<< " cCurrencyID: "								<< TTFRMU::MakeString(obj.cCurrencyID, 3);

			return out;
		}
		XFS300::LPWFSCIMTELLERINFO lpWFSCIMTELLERINFO = nullptr;
	} TTWFSCIMTELLERINFO, * LPTTWFSCIMTELLERINFO;

	typedef struct _tt_wfs_cim_teller_totals : public XFS300::_wfs_cim_teller_totals
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_teller_totals)
		~_tt_wfs_cim_teller_totals() { SAFERELEASE(&this->lpWFSCIMTELLERTOTALS) }
		void WFS2TT(const XFS300::_wfs_cim_teller_totals* obj)
		{
			CopyMemory(this->cCurrencyID, obj->cCurrencyID, 3);
			this->ulItemsReceived								= obj->ulItemsReceived;
			this->ulItemsDispensed								= obj->ulItemsDispensed;
			this->ulCoinsReceived								= obj->ulCoinsReceived;
			this->ulCoinsDispensed								= obj->ulCoinsDispensed;
			this->ulCashBoxReceived								= obj->ulCashBoxReceived;
			this->ulCashBoxDispensed							= obj->ulCashBoxDispensed;
		}
		void WFS(XFS300::LPWFSCIMTELLERTOTALS* lppWFSCIMTELLERTOTALS)
		{
			this->lpWFSCIMTELLERTOTALS = new XFS300::WFSCIMTELLERTOTALS;
			this->lpWFSCIMTELLERTOTALS->ulItemsReceived			= this->ulItemsReceived;
			this->lpWFSCIMTELLERTOTALS->ulItemsDispensed		= this->ulItemsDispensed;
			this->lpWFSCIMTELLERTOTALS->ulCoinsReceived			= this->ulCoinsReceived;
			this->lpWFSCIMTELLERTOTALS->ulCoinsDispensed		= this->ulCoinsDispensed;
			this->lpWFSCIMTELLERTOTALS->ulCashBoxReceived		= this->ulCashBoxReceived;
			this->lpWFSCIMTELLERTOTALS->ulCashBoxDispensed		= this->ulCashBoxDispensed;
			*lppWFSCIMTELLERTOTALS = this->lpWFSCIMTELLERTOTALS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_teller_totals& obj)
		{
			out << " - "
				<< " cCurrencyID: "								<< TTFRMU::MakeString(obj.cCurrencyID, 3)
				<< " ulItemsReceived: "							<< obj.ulItemsReceived
				<< " ulItemsDispensed: "						<< obj.ulItemsDispensed
				<< " ulCoinsReceived: "							<< obj.ulCoinsReceived
				<< " ulCoinsDispensed: "						<< obj.ulCoinsDispensed
				<< " ulCashBoxReceived: "						<< obj.ulCashBoxReceived
				<< " ulCashBoxDispensed: "						<< obj.ulCashBoxDispensed;
			return out;
		}
			XFS300::LPWFSCIMTELLERTOTALS lpWFSCIMTELLERTOTALS = nullptr;
	} TTWFSCIMTELLERTOTALS, * LPTTWFSCIMTELLERTOTALS;

	typedef struct _tt_wfs_cim_teller_details : public XFS300::_wfs_cim_teller_details
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_teller_details)
		~_tt_wfs_cim_teller_details()
		{
			SAFERELEASECONT(this->lppTellerTotals);
			SAFEPTR(this->lpWFSCIMTELLERDETAILS)
			{
				SAFERELEASELPP(this->lpWFSCIMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals.size());
				SAFERELEASE(&this->lpWFSCIMTELLERDETAILS);
			}
		}
		void WFS2TT(const XFS300::_wfs_cim_teller_details* obj)
		{
			this->usTellerID									= obj->usTellerID;
			this->fwInputPosition								= obj->fwInputPosition;
			this->fwOutputPosition								= obj->fwOutputPosition;
			DeviceUtility::CopyP2NAPs(this->lppTellerTotals, obj->lppTellerTotals);
		}
		void WFS(XFS300::LPWFSCIMTELLERDETAILS* lppWFSCIMTELLERDETAILS)
		{
			this->lpWFSCIMTELLERDETAILS = new XFS300::WFSCIMTELLERDETAILS;
			this->lpWFSCIMTELLERDETAILS->usTellerID				= this->usTellerID;
			this->lpWFSCIMTELLERDETAILS->fwInputPosition		= this->fwInputPosition;
			this->lpWFSCIMTELLERDETAILS->fwOutputPosition		= this->fwOutputPosition;
			DeviceUtility::CopyP2NAPs_r(this->lpWFSCIMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals);
			*lppWFSCIMTELLERDETAILS = this->lpWFSCIMTELLERDETAILS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_teller_details& obj)
		{
			out << " - "
				<< " usTellerID: "								<< obj.usTellerID
				<< " fwInputPosition: "							<< obj.fwInputPosition
				<< " fwOutputPosition: "						<< obj.fwOutputPosition;

			for (const auto& elem : obj.lppTellerTotals)
				out << std::endl << elem;

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMTELLERTOTALS>lppTellerTotals;
		XFS300::LPWFSCIMTELLERDETAILS lpWFSCIMTELLERDETAILS = nullptr;
	} TTWFSCIMTELLERDETAILS, * LPTTWFSCIMTELLERDETAILS;

	typedef struct _tt_wfs_cim_p2ap_teller_details
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_p2ap_teller_details)
		virtual ~_tt_wfs_cim_p2ap_teller_details() { SAFERELEASECONT(this->_listTellerDetails) }
		void WFS2TT(const XFS300::_wfs_cim_teller_details* obj)
		{
			DeviceUtility::CopyP2NAPs(this->_listTellerDetails, (XFS300::_wfs_cim_teller_details**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_p2ap_teller_details& obj)
		{
			for (auto elem : obj._listTellerDetails)
				out << std::endl << elem;

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMTELLERDETAILS>_listTellerDetails;
	} TTWFSCIMP2APTELLERDETAILS, * LPTTWFSCIMP2APTELLERDETAILS;

	typedef struct _tt_wfs_cim_currency_exp : public XFS300::_wfs_cim_currency_exp
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_currency_exp)
		DEFAULTDESTRUCTOR(_tt_wfs_cim_currency_exp)
		void WFS2TT(const XFS300::_wfs_cim_currency_exp* obj)
		{
			SAFECOPYMEMORY(this->cCurrencyID, obj->cCurrencyID, 3);
			this->sExponent = obj->sExponent;
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_currency_exp& obj)
		{
			out << " cCurrencyID: "								<< TTFRMU::MakeString(obj.cCurrencyID, 3)
				<< " sExponent: "								<< obj.sExponent;
			return out;
		}
	} TTWFSCIMCURRENCYEXP, * LPTTWFSCIMCURRENCYEXP;

	typedef struct _tt_wfs_cim_note_type : public XFS300::_wfs_cim_note_type
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_note_type)
		DEFAULTDESTRUCTOR(_tt_wfs_cim_note_type)
		void WFS2TT(const XFS300::_wfs_cim_note_type* obj)
		{
			this->usNoteID										= obj->usNoteID;
			SAFECOPYMEMORY(this->cCurrencyID, obj->cCurrencyID, 3);
			this->ulValues										= obj->ulValues;
			this->usRelease										= obj->usRelease;
			this->bConfigured									= obj->bConfigured;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_note_type& obj)
		{
			out << " usNoteID: "								<< obj.usNoteID
				<< " cCurrencyID: "								<< TTFRMU::MakeString(obj.cCurrencyID, 3)
				<< " ulValues: "								<< obj.ulValues
				<< " usRelease: "								<< obj.usRelease
				<< " bConfigured: "								<< obj.bConfigured;
			return out;
		}
	} TTWFSCIMNOTETYPE, * LPTTWFSCIMNOTETYPE;

	typedef struct _tt_wfs_cim_note_type_list : public XFS300::_wfs_cim_note_type_list
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_note_type_list)
		virtual ~_tt_wfs_cim_note_type_list() { SAFERELEASECONT(this->lppNoteTypes) }
		void WFS2TT(const XFS300::_wfs_cim_note_type_list* obj)
		{
			this->usNumOfNoteTypes								= obj->usNumOfNoteTypes;
			DeviceUtility::CopyP2APs(this->lppNoteTypes, obj->lppNoteTypes, obj->usNumOfNoteTypes);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_note_type_list& obj)
		{
			out << " usNumOfNoteTypes: "						<< obj.usNumOfNoteTypes
				<< " lppNoteTypes: ";
			for (auto elem : obj.lppNoteTypes)
				out << std::endl << *elem;
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMNOTETYPE> lppNoteTypes;
	} TTWFSCIMNOTETYPELIST, * LPTTWFSCIMNOTETYPELIST;

	typedef struct _tt_wfs_cim_cash_in_status : public XFS300::_wfs_cim_cash_in_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_cash_in_status)
		virtual ~_tt_wfs_cim_cash_in_status() { SAFERELEASE(&this->lpNoteNumberList) }
		void WFS2TT(const XFS300::_wfs_cim_cash_in_status* obj)
		{
			this->wStatus										= obj->wStatus;
			this->usNumOfRefused								= obj->usNumOfRefused;
			DeviceUtility::CopyP(&this->lpNoteNumberList, obj->lpNoteNumberList);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_cash_in_status& obj)
		{
			out << " wStatus: "									<< obj.wStatus
				<< " usNumOfRefused: "							<< obj.usNumOfRefused
				<< " lpNoteNumbverList: "						<< *(obj.lpNoteNumberList)
				<< " lpszExtra: ";

			for (const auto& elem : obj.lpszExtra)
				out << ' ' << elem;

			return out;
		}
		LPTTWFSCIMNOTENUMBERLIST lpNoteNumberList;
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSCIMCASHINSTATUS, * LPTTWFSCIMCASHINSTATUS;

	typedef struct _tt_wfs_cim_P6_info : public XFS300::_wfs_cim_P6_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_P6_info)
		~_tt_wfs_cim_P6_info() { SAFERELEASE(&this->lpNoteNumberList); }
		void WFS2TT(const XFS300::_wfs_cim_P6_info* obj)
		{
			this->usLevel = obj->usLevel;
			DeviceUtility::CopyP(&this->lpNoteNumberList, obj->lpNoteNumberList);
			this->usNumOfSignatures = obj->usNumOfSignatures;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_P6_info& obj)
		{
			out << " - "
				<< " usLevel: "									<< obj.usLevel
				<< " lpNoteNumbverList: "						<< *(obj.lpNoteNumberList)
				<< " usNumOfSignatures: "						<< obj.usNumOfSignatures;
			return out;
		}
		LPTTWFSCIMNOTENUMBERLIST lpNoteNumberList;
	} TTWFSCIMP6INFO, * LPTTWFSCIMP6INFO;

	typedef struct _tt_wfs_cim_p2ap_p6_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_p2ap_p6_info)
		virtual ~_tt_wfs_cim_p2ap_p6_info() { SAFERELEASECONT(this->_listP6Info) }
		void WFS2TT(const XFS300::_wfs_cim_P6_info* obj)
		{
			DeviceUtility::CopyP2NAPs(this->_listP6Info, (XFS300::_wfs_cim_P6_info**)obj);
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_p2ap_p6_info& obj)
		{
			for (const auto& elem : obj._listP6Info)
				out << std::endl << elem;

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCIMP6INFO>_listP6Info;
	} TTWFSCIMP2APP6INFO, * LPTTWFSCIMP2APP6INFO;

	typedef struct _tt_wfs_cim_get_P6_signature : public XFS300::_wfs_cim_get_P6_signature
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_get_P6_signature)
		~_tt_wfs_cim_get_P6_signature() { SAFERELEASE(&this->lpWFSCIMGETP6SIGNATURE) }
		void WFS2TT(const XFS300::_wfs_cim_get_P6_signature* obj)
		{
			this->usLevel										= obj->usLevel;
			this->usIndex										= obj->usIndex;
		}
		void WFS(XFS300::LPWFSCIMGETP6SIGNATURE* lppWFSCIMGETP6SIGNATURE)
		{
			this->lpWFSCIMGETP6SIGNATURE = new XFS300::WFSCIMGETP6SIGNATURE;
			this->lpWFSCIMGETP6SIGNATURE->usLevel				= this->usLevel;
			this->lpWFSCIMGETP6SIGNATURE->usIndex				= this->usIndex;
			*lppWFSCIMGETP6SIGNATURE = this->lpWFSCIMGETP6SIGNATURE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_get_P6_signature& obj)
		{
			out << " usLevel: "									<< obj.usLevel
				<< " usIndex: "									<< obj.usIndex;
			return out;
		}
		XFS300::LPWFSCIMGETP6SIGNATURE lpWFSCIMGETP6SIGNATURE = nullptr;
	} TTWFSCIMGETP6SIGNATURE, * LPTTWFSCIMGETP6SIGNATURE;

	/*=================================================================*/
	/* CIM Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cim_cash_in_start : public XFS300::_wfs_cim_cash_in_start
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_cash_in_start)
		~_tt_wfs_cim_cash_in_start() { SAFERELEASE(&this->lpWFSCIMCASHINSTART) }
		void WFS2TT(const XFS300::_wfs_cim_cash_in_start* obj)
		{
			this->usTellerID									= obj->usTellerID;
			this->bUseRecycleUnits								= obj->bUseRecycleUnits;
			this->fwOutputPosition								= obj->fwOutputPosition;
			this->fwInputPosition								= obj->fwInputPosition;
		}
		void WFS(XFS300::LPWFSCIMCASHINSTART* lppWFSCIMCASHINSTART)
		{
			this->lpWFSCIMCASHINSTART = new XFS300::WFSCIMCASHINSTART;
			this->lpWFSCIMCASHINSTART->usTellerID				= this->usTellerID;
			this->lpWFSCIMCASHINSTART->bUseRecycleUnits			= this->bUseRecycleUnits;
			this->lpWFSCIMCASHINSTART->fwOutputPosition			= this->fwOutputPosition;
			this->lpWFSCIMCASHINSTART->fwInputPosition			= this->fwInputPosition;
			*lppWFSCIMCASHINSTART = this->lpWFSCIMCASHINSTART;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_cash_in_start& obj)
		{
			out << " fwOutputPosition: "						<< obj.usTellerID
				<< " bUseRecycleUnits: "						<< obj.bUseRecycleUnits
				<< " fwOutputPosition: "						<< obj.fwOutputPosition
				<< " fwInputPosition: "							<< obj.fwInputPosition;
			return out;
		}
		XFS300::LPWFSCIMCASHINSTART lpWFSCIMCASHINSTART = nullptr;
	} TTWFSCIMCASHINSTART, * LPTTWFSCIMCASHINSTART;

	typedef struct _tt_wfs_cim_retract : public XFS300::_wfs_cim_retract
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_retract)
		~_tt_wfs_cim_retract() { SAFERELEASE(&this->lpWFSCIMRETRACT) }
		void WFS2TT(const _wfs_cim_retract* obj)
		{
			this->fwOutputPosition								= obj->fwOutputPosition;
			this->usRetractArea									= obj->usRetractArea;
			this->usIndex										= obj->usIndex;
		}
		void WFS(XFS300::LPWFSCIMRETRACT* lppWFSCIMRETRACT)
		{
			this->lpWFSCIMRETRACT = new XFS300::WFSCIMRETRACT;
			this->lpWFSCIMRETRACT->fwOutputPosition				= this->fwOutputPosition;
			this->lpWFSCIMRETRACT->usRetractArea				= this->usRetractArea;
			this->lpWFSCIMRETRACT->usIndex						= this->usIndex;
			*lppWFSCIMRETRACT = this->lpWFSCIMRETRACT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_retract& obj)
		{
			out << " fwOutputPosition: "						<< obj.fwOutputPosition
				<< " usRetractArea: "							<< obj.usRetractArea
				<< " usIndex: "									<< obj.usIndex;
			return out;
		}
		XFS300::LPWFSCIMRETRACT lpWFSCIMRETRACT = nullptr;
	} TTWFSCIMRETRACT, * LPTTWFSCIMRETRACT;

	typedef struct _tt_wfs_cim_teller_update : public XFS300::_wfs_cim_teller_update
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_teller_update)
		~_tt_wfs_cim_teller_update()
		{
			SAFERELEASE(&this->lpTellerDetails);
			SAFEPTR(this->lpWFSCIMTELLERUPDATE)
			{
				SAFERELEASE(&this->lpWFSCIMTELLERUPDATE->lpTellerDetails);
				SAFERELEASE(&this->lpWFSCIMTELLERUPDATE);
			}
		}
		void WFS2TT(const XFS300::_wfs_cim_teller_update* obj)
		{
			this->usAction										= obj->usAction;
			SAFEPTR(obj->lpTellerDetails)
				DeviceUtility::CopyP(&this->lpTellerDetails, obj->lpTellerDetails);
		}
		void WFS(XFS300::LPWFSCIMTELLERUPDATE* lppWFSCIMTELLERUPDATE)
		{
			this->lpWFSCIMTELLERUPDATE = new XFS300::WFSCIMTELLERUPDATE;
			this->lpWFSCIMTELLERUPDATE->usAction				= this->usAction;
			SAFEPTR(this->lpTellerDetails)
				DeviceUtility::CopyP_r(&this->lpWFSCIMTELLERUPDATE->lpTellerDetails, this->lpTellerDetails);
			*lppWFSCIMTELLERUPDATE = this->lpWFSCIMTELLERUPDATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_teller_update& obj)
		{
			out << " usAction: "								<< obj.usAction;
			SAFEPTR(obj.lpTellerDetails)
				out << " lpTellerDetails: "						<< *obj.lpTellerDetails;
			return out;
		}
		LPTTWFSCIMTELLERDETAILS lpTellerDetails;
		XFS300::LPWFSCIMTELLERUPDATE lpWFSCIMTELLERUPDATE = nullptr;
	} TTWFSCIMTELLERUPDATE, * LPTTWFSCIMTELLERUPDATE;

	typedef struct _tt_wfs_cim_output : public XFS300::_wfs_cim_output
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_output)
		~_tt_wfs_cim_output() { SAFERELEASE(&this->lpWFSCIMOUTPUT) }
		void WFS2TT(const _wfs_cim_output* obj)
		{
			this->usLogicalNumber								= obj->usLogicalNumber;
			this->fwPosition									= obj->fwPosition;
			this->usNumber										= obj->usNumber;
		}
		void WFS(XFS300::LPWFSCIMOUTPUT* lppWFSCIMOUTPUT)
		{
			this->lpWFSCIMOUTPUT = new XFS300::WFSCIMOUTPUT;
			this->lpWFSCIMOUTPUT->usLogicalNumber				= this->usLogicalNumber;
			this->lpWFSCIMOUTPUT->fwPosition					= this->fwPosition;
			this->lpWFSCIMOUTPUT->usNumber						= this->usNumber;
			*lppWFSCIMOUTPUT = this->lpWFSCIMOUTPUT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_output& obj)
		{
			out << " usLogicalNumber: "							<< obj.usLogicalNumber
				<< " fwPosition: "								<< obj.fwPosition
				<< " usNumber: "								<< obj.usNumber;
			return out;
		}
		XFS300::LPWFSCIMOUTPUT lpWFSCIMOUTPUT = nullptr;
	} TTWFSCIMOUTPUT, * LPTTWFSCIMOUTPUT;

	typedef struct _tt_wfs_cim_start_ex : public XFS300::_wfs_cim_start_ex
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_start_ex)
		~_tt_wfs_cim_start_ex()
		{
			SAFEFREEMEMORY(&this->lpusCUNumList);
			SAFERELEASE(&this->lpOutput);
			SAFEPTR(this->lpWFSCIMSTARTEX)
			{
				SAFEFREEMEMORY(&this->lpWFSCIMSTARTEX->lpusCUNumList);
				SAFERELEASE(&this->lpWFSCIMSTARTEX->lpOutput);
				SAFERELEASE(&this->lpWFSCIMSTARTEX);
			}
		}
		void WFS2TT(const _wfs_cim_start_ex* obj)
		{
			this->fwExchangeType								= obj->fwExchangeType;
			this->usTellerID									= obj->usTellerID;
			this->usCount										= obj->usCount;
			SAFEALLOCCOPYMEMORY(&this->lpusCUNumList, obj->lpusCUNumList, obj->usCount);
			DeviceUtility::CopyP(&this->lpOutput, obj->lpOutput);
		}
		void WFS(XFS300::LPWFSCIMSTARTEX* lppWFSCIMSTARTEX)
		{
			this->lpWFSCIMSTARTEX = new XFS300::WFSCIMSTARTEX;
			this->lpWFSCIMSTARTEX->fwExchangeType				= this->fwExchangeType;
			this->lpWFSCIMSTARTEX->usTellerID					= this->usTellerID;
			this->lpWFSCIMSTARTEX->usCount						= this->usCount;
			SAFEALLOCCOPYMEMORY(&this->lpWFSCIMSTARTEX->lpusCUNumList, this->lpusCUNumList, this->usCount);
			DeviceUtility::CopyP_r(&this->lpWFSCIMSTARTEX->lpOutput, this->lpOutput);
			*lppWFSCIMSTARTEX = this->lpWFSCIMSTARTEX;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_start_ex& obj)
		{
			out << " fwOutputPosition: "						<< obj.fwExchangeType
				<< " usTellerID: "								<< obj.usTellerID
				<< " usCount: "									<< obj.usCount
				<< " lpusCUNumList: "							<< "needs attention"
				<< " lpOutput: "								<< *obj.lpOutput;
			return out;
		}
		LPTTWFSCIMOUTPUT lpOutput;
		XFS300::LPWFSCIMSTARTEX lpWFSCIMSTARTEX = nullptr;
	} TTWFSCIMSTARTEX, * LPTTWFSCIMSTARTEX;

	typedef struct _tt_wfs_cim_itemposition : public XFS300::_wfs_cim_itemposition
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_itemposition)
		~_tt_wfs_cim_itemposition() 
		{
			SAFERELEASE(&this->lpRetractArea);
			SAFEPTR(this->lpWFSCIMITEMPOSITION)
			{
				SAFERELEASE(&this->lpWFSCIMITEMPOSITION->lpRetractArea);
				SAFERELEASE(&this->lpWFSCIMITEMPOSITION);
			}
		}
		void WFS2TT(const _wfs_cim_itemposition* obj)
		{
			this->usNumber										= obj->usNumber;
			DeviceUtility::CopyP(&this->lpRetractArea, obj->lpRetractArea);
			this->fwOutputPosition								= obj->fwOutputPosition;
		}
		void WFS(XFS300::LPWFSCIMITEMPOSITION* lppWFSCIMITEMPOSITION)
		{
			TRACELOG("TTWFSCIMITEMPOSITION::WFS - Started");
			this->lpWFSCIMITEMPOSITION = new XFS300::WFSCIMITEMPOSITION;
			this->lpWFSCIMITEMPOSITION->usNumber				= this->usNumber;
			DeviceUtility::CopyP_r(&this->lpWFSCIMITEMPOSITION->lpRetractArea, this->lpRetractArea);
			this->lpWFSCIMITEMPOSITION->fwOutputPosition		= this->fwOutputPosition;
			*lppWFSCIMITEMPOSITION = this->lpWFSCIMITEMPOSITION;
			TRACELOG("TTWFSCIMITEMPOSITION::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_itemposition& obj)
		{
			out << " usNumber: "								<< obj.usNumber;
			out << " lpRetractArea: ";
			SAFEPTR(obj.lpRetractArea) out << *obj.lpRetractArea;
			out << " fwOutputPosition: "						<< obj.fwOutputPosition;
			return out;
		}
		LPTTWFSCIMRETRACT lpRetractArea = nullptr;
		XFS300::LPWFSCIMITEMPOSITION lpWFSCIMITEMPOSITION = nullptr;
	} TTWFSCIMITEMPOSITION, * LPTTWFSCIMITEMPOSITION;

	typedef struct _tt_wfs_cim_cash_in_type : public XFS300::_wfs_cim_cash_in_type
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_cash_in_type)
		DEFAULTDESTRUCTOR(_tt_wfs_cim_cash_in_type)
		void WFS2TT(const _wfs_cim_cash_in_type* obj)
		{
			this->usNumber										= obj->usNumber;
			this->dwType										= obj->dwType;
			TTFRMU::CopyNArray2vector(this->lpusNoteIDs, obj->lpusNoteIDs);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_cash_in_type& obj)
		{
			out << " usNumber: "								<< obj.usNumber
				<< " dwType: "									<< obj.dwType
				<< " fwOutputPosition: "						<< TTFRMU::Vect2Str(obj.lpusNoteIDs);
			return out;
		}
		std::vector<USHORT> lpusNoteIDs;
	} TTWFSCIMCASHINTYPE, * LPTTWFSCIMCASHINTYPE;

	typedef struct _tt_wfs_cim_P6_signature : public XFS300::_wfs_cim_P6_signature
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_P6_signature)
		DEFAULTDESTRUCTOR(_tt_wfs_cim_P6_signature)
		void WFS2TT(const XFS300::_wfs_cim_P6_signature* obj)
		{
			this->usNoteId										= obj->usNoteId;
			this->ulLength										= obj->ulLength;
			this->dwOrientation									= obj->dwOrientation;
			SAFECOPYMEMORY(this->lpSignature, obj->lpSignature, ulLength);
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_P6_signature& obj)
		{
			out << " usNoteId: "								<< obj.usNoteId
				<< " ulLength: "								<< obj.ulLength
				<< " dwOrientation: "							<< obj.dwOrientation
				<< " lpSignature: "								<< obj.lpSignature;
			return out;
		}
		LPVOID lpSignature;
	} TTWFSCIMP6SIGNATURE, * LPTTWFSCIMP6SIGNATURE;

	/*=================================================================*/
	/* CIM Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cim_cu_error : public XFS300::_wfs_cim_cu_error
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_cu_error)
		~_tt_wfs_cim_cu_error() { SAFERELEASE(&this->lpCashUnit) }
		void WFS2TT(const _wfs_cim_cu_error* obj)
		{
			this->wFailure									= obj->wFailure;
			DeviceUtility::CopyP(&this->lpCashUnit, obj->lpCashUnit);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_cu_error& obj)
		{
			out << " wFailure: "							<< obj.wFailure
				<< " lpCashUnit: "							<< *obj.lpCashUnit;
			return out;
		}
		LPTTWFSCIMCASHIN lpCashUnit;
	} TTWFSCIMCUERROR, * LPTTWFSCIMCUERROR;

	typedef struct _tt_wfs_cim_counts_changed : public XFS300::_wfs_cim_counts_changed
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cim_counts_changed)
		~_tt_wfs_cim_counts_changed() { SAFEFREEMEMORY(&this->lpusCUNumList) }
		void WFS2TT(const _wfs_cim_counts_changed* obj)
		{
			this->usCount									= obj->usCount;
			this->lpusCUNumList								= (USHORT*)::malloc(sizeof(USHORT) * obj->usCount);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cim_counts_changed& obj)
		{
			out << " usCount: "								<< obj.usCount
				<< " lpusCUNumList: ";
			for (size_t i = 0; i < obj.usCount; ++i)
				out << obj.lpusCUNumList[i] << " ";
			return out;
		}
	} TTWFSCIMCOUNTSCHANGED, * LPTTWFSCIMCOUNTSCHANGED;

	/*=================================================================*/
	/* CIM Customized Command Structures */
	/*=================================================================*/

	typedef struct _tt_system_time : public SYSTEMTIME
	{
		_tt_system_time() = default;
		_tt_system_time(const _tt_system_time& obj)
		{
			this->wYear									= obj.wYear;
			this->wMonth								= obj.wMonth;
			this->wDayOfWeek							= obj.wDayOfWeek;
			this->wDay									= obj.wDay;
			this->wHour									= obj.wHour;
			this->wMinute								= obj.wMinute;
			this->wSecond								= obj.wSecond;
			this->wMilliseconds							= obj.wMilliseconds;		
		}
		_tt_system_time(_tt_system_time&&) = delete;
		_tt_system_time& operator = (const _tt_system_time& obj)
		{
			this->wYear									= obj.wYear;
			this->wMonth								= obj.wMonth;
			this->wDayOfWeek							= obj.wDayOfWeek;
			this->wDay									= obj.wDay;
			this->wHour									= obj.wHour;
			this->wMinute								= obj.wMinute;
			this->wSecond								= obj.wSecond;
			this->wMilliseconds							= obj.wMilliseconds;		
		}
		_tt_system_time& operator = (_tt_system_time&&) = delete;
		virtual ~_tt_system_time() = default;
		explicit _tt_system_time(const SYSTEMTIME& sTime)
		{
			this->wYear									= sTime.wYear;
			this->wMonth								= sTime.wMonth;
			this->wDayOfWeek							= sTime.wDayOfWeek;
			this->wDay									= sTime.wDay;
			this->wHour									= sTime.wHour;
			this->wMinute								= sTime.wMinute;
			this->wSecond								= sTime.wSecond;
			this->wMilliseconds							= sTime.wMilliseconds;		
		}
		void WFS2TT(const SYSTEMTIME* obj)
		{
			this->wYear									= obj->wYear;
			this->wMonth								= obj->wMonth;
			this->wDayOfWeek							= obj->wDayOfWeek;
			this->wDay									= obj->wDay;
			this->wHour									= obj->wHour;
			this->wMinute								= obj->wMinute;
			this->wSecond								= obj->wSecond;
			this->wMilliseconds							= obj->wMilliseconds;		
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_system_time& obj)
		{
			out << " wYear: "							<< obj.wYear
				<< " wMonth: "							<< obj.wMonth
				<< " wDayOfWeek: "						<< obj.wDayOfWeek
				<< " wDay: "							<< obj.wDay
				<< " wHour: "							<< obj.wHour
				<< " wMinute: "							<< obj.wMinute
				<< " wSecond: "							<< obj.wSecond
				<< " wMilliseconds: "					<< obj.wMilliseconds;
			return out;
		}
	} TTSYSTEMTIME, * LPTTSYSTEMTIME;

	typedef struct _tt_wfs_crm_query_transinfo : public XFS300::_wfs_crm_query_transinfo
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_crm_query_transinfo)
		~_tt_wfs_crm_query_transinfo()
		{
			DEBUGLOG("~_tt_wfs_crm_query_transinfo - Started");
			SAFERELEASE(&this->sDateBegin);
			DEBUGLOG("~_tt_wfs_crm_query_transinfo - 1");
			SAFERELEASE(&this->sDateEnd);
			DEBUGLOG("~_tt_wfs_crm_query_transinfo - 2");
			SAFERELEASE(&this->lpWFSCRMQUERYTRANSINFO);
			DEBUGLOG("~_tt_wfs_crm_query_transinfo - Ended");
		}
		void WFS2TT(const XFS300::_wfs_crm_query_transinfo* obj)
		{
			::CopyMemory(this->acJournalNo, obj->acAccountNo, 32);
			::CopyMemory(this->acAccountNo, obj->acAccountNo, 48);
			DeviceUtility::CopyP(&this->sDateBegin, &obj->sDateBegin);
			DeviceUtility::CopyP(&this->sDateEnd, &obj->sDateEnd);
		}
		void WFS(XFS300::LPWFSCRMQUERYTRANSINFO* lppWFSCRMQUERYTRANSINFO)
		{
			this->lpWFSCRMQUERYTRANSINFO = new XFS300::WFSCRMQUERYTRANSINFO;
			::CopyMemory(this->lpWFSCRMQUERYTRANSINFO->acJournalNo, this->acAccountNo, 32);
			::CopyMemory(this->lpWFSCRMQUERYTRANSINFO->acAccountNo, this->acAccountNo, 48);
			::CopyMemory(&this->lpWFSCRMQUERYTRANSINFO->sDateBegin, &this->sDateBegin, sizeof(SYSTEMTIME));
			::CopyMemory(&this->lpWFSCRMQUERYTRANSINFO->sDateEnd, &this->sDateEnd, sizeof(SYSTEMTIME));
			*lppWFSCRMQUERYTRANSINFO = this->lpWFSCRMQUERYTRANSINFO;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_crm_query_transinfo& obj)
		{
			out << " acJournalNo: "						<< std::string{ obj.acJournalNo }
				<< " acAccountNo: "						<< std::string{ obj.acAccountNo }
				<< " sDateBegin -> "					<< *obj.sDateBegin
				<< " sDateEnd -> "						<< *obj.sDateEnd;
			return out;
		}
		LPTTSYSTEMTIME sDateBegin = nullptr;
		LPTTSYSTEMTIME sDateEnd = nullptr;
		XFS300::LPWFSCRMQUERYTRANSINFO lpWFSCRMQUERYTRANSINFO = nullptr;
	} TTWFSCRMQUERYTRANSINFO, * LPTTWFSCRMQUERYTRANSINFO;

	typedef struct _tt_wfs_crm_cash_info_details : public XFS300::_wfs_crm_cash_info_details
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_crm_cash_info_details)
		virtual ~_tt_wfs_crm_cash_info_details() { SAFERELEASE(&this->sSysTime) }
		void WFS2TT(const XFS300::_wfs_crm_cash_info_details* obj)
		{
			DeviceUtility::CopyP(&this->sSysTime, &obj->sSysTime);
			::CopyMemory(this->acJournalNo, obj->acAccountNo, WFS_CRM_JOURNALNO_LEN);
			::CopyMemory(this->acAccountNo, obj->acAccountNo, WFS_CRM_ACCOUNTNO_LEN);
			this->byValidation							= obj->byValidation;
			this->wDenomination							= obj->wDenomination;
			::CopyMemory(this->acImageFileName, obj->acImageFileName, WFS_CRM_IMAGEFILENAME_LEN);
			::CopyMemory(this->acSerialNo, obj->acSerialNo, WFS_CRM_SERIALNO_LEN);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_crm_cash_info_details& obj)
		{
			out << " - "
				<< " sSystemTime: "						<< *obj.sSysTime
				<< " acJournalNo: "						<< std::string{ obj.acJournalNo }
				<< " acAccountNo: "						<< std::string{ obj.acAccountNo }
				<< " byValidation: "					<< "0x" << std::hex << std::setw(4) << std::setfill('0') << (0xff & (unsigned int)obj.byValidation)
				<< " wDenomination: "					<< obj.wDenomination
				<< " acImageFileName: "					<< std::string{ obj.acImageFileName }
				<< " acSerialNo: "						<< std::string{ obj.acSerialNo };
			return out;
		}
		LPTTSYSTEMTIME sSysTime;
	} TTWFSCRMCASHINFODETAILS, * LPTTWFSCRMCASHINFODETAILS;

	typedef struct _tt_wfs_crm_cash_info : public XFS300::_wfs_crm_cash_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_crm_cash_info)
		virtual ~_tt_wfs_crm_cash_info() 
		{ 
			DEBUGLOG("~_tt_wfs_crm_cash_info - Started");
			SAFERELEASECONT(this->lppCashInfoDetails)
			DEBUGLOG("~_tt_wfs_crm_cash_info - Ended");
		}
		void WFS2TT(const XFS300::_wfs_crm_cash_info* obj)
		{
			this->usCount								= obj->usCount;
			DeviceUtility::CopyP2APs(this->lppCashInfoDetails, obj->lppCashInfoDetails, obj->usCount);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_crm_cash_info& obj)
		{
			out << " usCount: "							<< obj.usCount;
			
			for (const auto& elem : obj.lppCashInfoDetails)
				out << std::endl << *elem;

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCRMCASHINFODETAILS>lppCashInfoDetails;
	} TTWFSCRMCASHINFO, * LPTTWFSCRMCASHINFO;

#pragma pack(pop)

	/*=================================================================*/
	/* ICIM Utilities */
	/*=================================================================*/

	inline bool assign(XFS300::LPWFSCIMCASHINFO* lppCUInfo, LPTTWFSCIMCASHINFO lpTTCUInfo)
	{
		UNSAFEPTR(lpTTCUInfo)
			return false;
		UNSAFEPTR(lppCUInfo)
			return false;

		SIZE_T							_size = 0;
		LPBYTE							_tempPtr = NULL;
		XFS300::LPWFSCIMCASHINFO		_lpWFSCIMCashInfo = NULL;
		XFS300::LPWFSCIMCASHIN			_lpWFSCIMCashIn = NULL;
		XFS300::LPWFSCIMNOTENUMBERLIST	_lpWFSCIMNoteNumberList = NULL;
		XFS300::LPWFSCIMNOTENUMBER		_lpWFSCIMNoteNumber = NULL;
		XFS300::LPWFSCIMPHCU			_lpWFSCIMPHCU = NULL;

		// Calculating necessary memory size
		_size = sizeof(XFS300::WFSCIMCASHINFO);																	// size of array of WFSCIMCASHINFO structure
		_size += sizeof(XFS300::LPWFSCIMCASHIN) * lpTTCUInfo->usCount;											// size of array of pointers to LCUs
		for (const auto& lcu : lpTTCUInfo->lppCashIn)
		{
			_size += sizeof(XFS300::WFSCIMCASHIN);
			_size += sizeof(XFS300::WFSCIMNOTENUMBERLIST);
			SAFEPTR(lcu->lpNoteNumberList)
			{
				_size += sizeof(XFS300::LPWFSCIMNOTENUMBER) * lcu->lpNoteNumberList->usNumOfNoteNumbers;		// size of array of pointers to WFSCIMNOTENUMBER

				for (const auto& NoteNumber : lcu->lpNoteNumberList->lppNoteNumber)					// size of WFSCIMNOTENUMBER structures
					_size += sizeof(XFS300::WFSCIMNOTENUMBER);
			}

			_size += sizeof(XFS300::LPWFSCIMPHCU) * lcu->usNumPhysicalCUs;										// size of array of pointers to PCUs
			for (const auto& pcu : lcu->lppPhysical)													// size of WFSCIMPHCU structures
			{
				_size += sizeof(XFS300::WFSCIMPHCU);
				_size += pcu->lpPhysicalPositionName.size();											// Size_LPSTR(pcu->lpPhysicalPositionName);
			}
		}

		// Allocating necessary memory from Heap
		_tempPtr = (LPBYTE)malloc(_size);
		UNSAFEPTR(_tempPtr)
			return false;
		ZeroMemory(_tempPtr, _size);

		// Assigning LPWFSCIMCASHINFO properties
		_lpWFSCIMCashInfo = (XFS300::LPWFSCIMCASHINFO)_tempPtr;
		_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCIMCASHINFO));

		_lpWFSCIMCashInfo->usCount = lpTTCUInfo->usCount;

		_lpWFSCIMCashInfo->lppCashIn = (XFS300::LPWFSCIMCASHIN*)_tempPtr;
		_tempPtr = (LPBYTE)((ULONG)_tempPtr + (lpTTCUInfo->usCount * sizeof(XFS300::LPWFSCIMCASHIN)));

		// Assigning LPWFSCIMCASHIN properties
		USHORT _usLCUIndex = 0;
		for (const auto& lcu : lpTTCUInfo->lppCashIn)
		{
			_lpWFSCIMCashIn = (XFS300::LPWFSCIMCASHIN)_tempPtr;
			_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCIMCASHIN));
			_lpWFSCIMCashInfo->lppCashIn[_usLCUIndex] = _lpWFSCIMCashIn;
			_usLCUIndex++;

			_lpWFSCIMCashIn->usNumber			= lcu->usNumber;
			_lpWFSCIMCashIn->fwType				= lcu->fwType;
			_lpWFSCIMCashIn->fwItemType			= lcu->fwItemType;
			SAFECOPYMEMORY(_lpWFSCIMCashIn->cUnitID, lcu->cUnitID.c_str(), lcu->cUnitID.size());
			SAFECOPYMEMORY(_lpWFSCIMCashIn->cCurrencyID, lcu->cCurrencyID.c_str(), 3);
			_lpWFSCIMCashIn->ulValues			= lcu->ulValues;
			_lpWFSCIMCashIn->ulCashInCount		= lcu->ulCashInCount;
			_lpWFSCIMCashIn->ulCount			= lcu->ulCount;
			_lpWFSCIMCashIn->ulMaximum			= lcu->ulMaximum;
			_lpWFSCIMCashIn->usStatus			= lcu->usStatus;
			_lpWFSCIMCashIn->bAppLock			= lcu->bAppLock;
			_lpWFSCIMCashIn->usNumPhysicalCUs	= lcu->usNumPhysicalCUs;
			_lpWFSCIMCashIn->lpszExtra			= NULL;

			// Assigning WFSCIMNOTENUMBERLIST properties
			SAFEPTR(lcu->lpNoteNumberList)
			{
				_lpWFSCIMNoteNumberList = (XFS300::LPWFSCIMNOTENUMBERLIST)_tempPtr;
				_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCIMNOTENUMBERLIST));

				_lpWFSCIMCashIn->lpNoteNumberList = _lpWFSCIMNoteNumberList;

				_lpWFSCIMNoteNumberList->usNumOfNoteNumbers = lcu->lpNoteNumberList->usNumOfNoteNumbers;

				_lpWFSCIMNoteNumberList->lppNoteNumber = (XFS300::LPWFSCIMNOTENUMBER*)_tempPtr;
				_tempPtr = (LPBYTE)((ULONG)_tempPtr + (lcu->lpNoteNumberList->usNumOfNoteNumbers * sizeof(XFS300::LPWFSCIMNOTENUMBER)));

				// Assigning WFSCIMNOTENUMBER properties
				USHORT _usNotNumberIndex = 0;
				for (const auto& NoteNumber : lcu->lpNoteNumberList->lppNoteNumber)
				{
					_lpWFSCIMNoteNumber = (XFS300::LPWFSCIMNOTENUMBER)_tempPtr;
					_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCIMNOTENUMBER));
					_lpWFSCIMNoteNumberList->lppNoteNumber[_usNotNumberIndex] = _lpWFSCIMNoteNumber;
					_usNotNumberIndex++;

					_lpWFSCIMNoteNumber->ulCount = NoteNumber->ulCount;
					_lpWFSCIMNoteNumber->usNoteID = NoteNumber->usNoteID;
				}

			}
			ELSE
				_lpWFSCIMCashIn->lpNoteNumberList = NULL;

			// Assigning WFSCIMPHCU properties
			_lpWFSCIMCashIn->lppPhysical = (XFS300::LPWFSCIMPHCU*)_tempPtr;
			_tempPtr = (LPBYTE)((ULONG)_tempPtr + (lcu->usNumPhysicalCUs * sizeof(XFS300::LPWFSCIMPHCU)));

			USHORT _usPCUIndex = 0;
			for (auto pcu : lcu->lppPhysical)
			{
				_lpWFSCIMPHCU = (XFS300::LPWFSCIMPHCU)_tempPtr;
				_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCIMPHCU));
				_lpWFSCIMCashIn->lppPhysical[_usPCUIndex] = _lpWFSCIMPHCU;
				_usPCUIndex++;

				_lpWFSCIMPHCU->lpPhysicalPositionName = (LPSTR)_tempPtr;
				_tempPtr = (LPBYTE)((ULONG)_tempPtr + pcu->lpPhysicalPositionName.size());

				SAFECOPYMEMORY(_lpWFSCIMPHCU->lpPhysicalPositionName, pcu->lpPhysicalPositionName.c_str(), pcu->lpPhysicalPositionName.size());
				SAFECOPYMEMORY(_lpWFSCIMPHCU->cUnitID, pcu->cUnitID.c_str(), pcu->cUnitID.size());
				_lpWFSCIMPHCU->ulCashInCount	= pcu->ulCashInCount;
				_lpWFSCIMPHCU->ulCount			= pcu->ulCount;
				_lpWFSCIMPHCU->ulMaximum		= pcu->ulMaximum;
				_lpWFSCIMPHCU->usPStatus		= pcu->usPStatus;
				_lpWFSCIMPHCU->bHardwareSensors = pcu->bHardwareSensors;
				_lpWFSCIMPHCU->lpszExtra		= NULL;
			}
		}

		*lppCUInfo = _lpWFSCIMCashInfo;

		return true;
	}



	/*=================================================================*/
	/* ICIM Interface */
	/*=================================================================*/

	class ITTCIM : public ITTDevice
	{
	public:
		ITTCIM() = default;
		ITTCIM(const ITTCIM&) = delete;
		ITTCIM(ITTCIM&&) = delete;
		ITTCIM& operator = (const ITTCIM&) = delete;
		ITTCIM& operator = (ITTCIM&&) = delete;
		virtual ~ITTCIM() = default;

		/* CIM Info Functions */
		virtual bool GetStatus(LPTTWFSCIMSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSCIMCAPS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCashUnitInfo(LPTTWFSCIMCASHINFO lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetTellerInfo(const LPTTWFSCIMTELLERINFO lpTellerInfo, LPTTWFSCIMP2APTELLERDETAILS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCurrencyExp(LPTTWFSCIMCURRENCYEXP lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetBankNoteTypes(LPTTWFSCIMNOTETYPELIST lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCashInStatus(LPTTWFSCIMCASHINSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetP6Info(LPTTWFSCIMP2APP6INFO lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetP6Signature(const LPTTWFSCIMGETP6SIGNATURE lpGetP6Signature, LPTTWFSCIMP6SIGNATURE lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCashUnitInfo(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetTellerInfo(const LPTTWFSCIMTELLERINFO lpTellerInfo, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCurrencyExp(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetBankNoteTypes(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCashInStatus(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetP6Info(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetP6Signature(const LPTTWFSCIMGETP6SIGNATURE lpGetP6Signature, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		/* CIM Execute Functions */
		virtual bool CashInStart(const LPTTWFSCIMCASHINSTART lpCashInStart, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CashIn(LPTTWFSCIMNOTENUMBERLIST lpNoteNumberList, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CashInEnd(LPTTWFSCIMCASHINFO lpCashInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CashInRollBack(LPTTWFSCIMCASHINFO lpCashInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Retract(const LPTTWFSCIMRETRACT lpRetract, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool OpenShutter(const LPWORD lpfwPosition, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CloseShutter(const LPWORD lpfwPosition, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetTellerInfo(const LPTTWFSCIMTELLERUPDATE lpTellerUpdate, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetCashUnitInfo(const LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool StartExchange(const LPTTWFSCIMSTARTEX lpStartEx, LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool EndExchange(const LPTTWFSCIMCASHINFO lpCUInfo, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool OpenSafeDoor(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const LPTTWFSCIMITEMPOSITION lpResetIn, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ConfigureCashInUnits(const LPTTWFSCIMCASHINTYPE* lppCashInType, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ConfigureNoteTypes(const LPUSHORT lpusNoteIDs, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CreateP6Signature(LPTTWFSCIMP6SIGNATURE lpP6Signature, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncCashInStart(const LPTTWFSCIMCASHINSTART lpCashInStart, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCashIn(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCashInEnd(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCashInRollBack(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRetract(const LPTTWFSCIMRETRACT lpRetract, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncOpenShutter(LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCloseShutter(LPWORD lpfwPosition, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetTellerInfo(const LPTTWFSCIMTELLERUPDATE lpTellerUpdate, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetCashUnitInfo(const LPTTWFSCIMCASHINFO lpCUInfo, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncStartExchange(const LPTTWFSCIMSTARTEX lpStartEx, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncEndExchange(const LPTTWFSCIMCASHINFO lpCUInfo, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncOpenSafeDoor(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(const LPTTWFSCIMITEMPOSITION lpResetIn, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncConfigureCashInUnits(const LPTTWFSCIMCASHINTYPE* lppCashInType, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncConfigureNoteTypes(const LPUSHORT lpusNoteIDs, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCreateP6Signature(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		/* CIM Customized Functions */
		virtual bool TransInfo(const LPTTWFSCRMQUERYTRANSINFO lpQueryTransInfo, LPTTWFSCRMCASHINFO lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncTransInfo(const LPTTWFSCRMQUERYTRANSINFO lpQueryTransInfo, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
	};	
}

#endif // !__H_ITTCIM__