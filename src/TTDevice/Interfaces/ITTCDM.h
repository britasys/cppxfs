#pragma once

#ifndef __H_ITTCDM__
#define __H_ITTCDM__

#include "../ITTDevice.h"
#include <DeviceUtility.h>

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* CDM Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cdm_position : public XFS300::_wfs_cdm_position
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_position)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_position)
		void WFS2TT(const XFS300::_wfs_cdm_position* obj)
		{
			this->fwPosition						= obj->fwPosition;
			this->fwShutter							= obj->fwShutter;
			this->fwPositionStatus					= obj->fwPositionStatus;
			this->fwTransport						= obj->fwTransport;
			this->fwTransportStatus					= obj->fwTransportStatus;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_position& obj)
		{
			out << " - "
				<< " fwPosition: "					<< obj.fwPosition
				<< " fwShutter: "					<< obj.fwShutter
				<< " fwPositionStatus: "			<< obj.fwPositionStatus
				<< " fwTransport: "					<< obj.fwTransport
				<< " fwTransportStatus: "			<< obj.fwTransportStatus;
			return out;
		}
	} TTWFSCDMOUTPOS, * LPTTWFSCDMOUTPOS;

	typedef struct _tt_wfs_cdm_status : public XFS300::_wfs_cdm_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_status)
		~_tt_wfs_cdm_status() { SAFERELEASECONT(this->lppPositions) }
		void WFS2TT(const XFS300::_wfs_cdm_status* obj)
		{
			this->fwDevice							= obj->fwDevice;
			this->fwSafeDoor						= obj->fwSafeDoor;
			this->fwDispenser						= obj->fwDispenser;
			this->fwIntermediateStacker				= obj->fwIntermediateStacker;
			DeviceUtility::CopyP2NAPs(this->lppPositions, obj->lppPositions);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_status& obj)
		{
			out << " fwDevice: "					<< obj.fwDevice
				<< " fwSafeDoor: "					<< obj.fwSafeDoor
				<< " fwDispenser: "					<< obj.fwDispenser
				<< " fwIntermediateStacker: "		<< obj.fwIntermediateStacker
				<< " lppPositions: "				<< DeviceUtility::TTCONT2Str(obj.lppPositions).c_str();
			out << std::endl;
			out << " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMOUTPOS>	lppPositions;
		DeviceUtility::STRVECT					lpszExtra;
	} TTWFSCDMSTATUS, * LPTTWFSCDMSTATUS;

	typedef struct _tt_wfs_cdm_caps : public XFS300::_wfs_cdm_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_caps)
		void WFS2TT(const XFS300::_wfs_cdm_caps* obj)
		{
			this->wClass							= obj->wClass;
			this->fwType							= obj->fwType;
			this->wMaxDispenseItems					= obj->wMaxDispenseItems;
			this->bCompound							= obj->bCompound;
			this->bShutter							= obj->bShutter;
			this->bShutterControl					= obj->bShutterControl;
			this->fwRetractAreas					= obj->fwRetractAreas;
			this->fwRetractTransportActions			= obj->fwRetractTransportActions;
			this->fwRetractStackerActions			= obj->fwRetractStackerActions;
			this->bSafeDoor							= obj->bSafeDoor;
			this->bCashBox							= obj->bCashBox;
			this->bIntermediateStacker				= obj->bIntermediateStacker;
			this->bItemsTakenSensor					= obj->bItemsTakenSensor;
			this->fwPositions						= obj->fwPositions;
			this->fwMoveItems						= obj->fwMoveItems;
			this->fwExchangeType					= obj->fwExchangeType;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_caps& obj)
		{
			out << " wClass: "						<< obj.wClass
				<< " fwType: "						<< obj.fwType
				<< " wMaxDispenseItems: "			<< obj.wMaxDispenseItems
				<< " bCompound: "					<< obj.bCompound
				<< " bShutter: "					<< obj.bShutter
				<< " bShutterControl: "				<< obj.bShutterControl
				<< " fwRetractAreas: "				<< obj.fwRetractAreas
				<< " fwRetractTransportActions: "	<< obj.fwRetractTransportActions
				<< " fwRetractStackerActions: "		<< obj.fwRetractStackerActions
				<< " bSafeDoor: "					<< obj.bSafeDoor
				<< " bCashBox: "					<< obj.bCashBox
				<< " bIntermediateStacker: "		<< obj.bIntermediateStacker
				<< " bItemsTakenSensor: "			<< obj.bItemsTakenSensor
				<< " fwPositions: "					<< obj.fwPositions
				<< " fwMoveItems: "					<< obj.fwMoveItems
				<< " fwExchangeType: "				<< obj.fwExchangeType
				<< " lpszExtra: "					<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}

		DeviceUtility::STRVECT lpszExtra;
	} TTWFSCDMCAPS, * LPTTWFSCDMCAPS;

	typedef struct _tt_wfs_cdm_physicalcu : public XFS300::_wfs_cdm_physicalcu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_physicalcu)
		~_tt_wfs_cdm_physicalcu()
		{
			TRACELOG("~_tt_wfs_cdm_physicalcu - Started");
			SAFEPTR(this->lpWFSCDMPHCU)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMPHCU->lpPhysicalPositionName);
				SAFERELEASE(&this->lpWFSCDMPHCU);
			}
			TRACELOG("~_tt_wfs_cdm_physicalcu - Ended");
		}
		void WFS2TT(const XFS300::_wfs_cdm_physicalcu* obj)
		{
			SAFEPTR(obj->lpPhysicalPositionName) this->lpPhysicalPositionName.assign(obj->lpPhysicalPositionName, 5);
			this->cUnitID.assign(obj->cUnitID, 5);
			this->ulInitialCount					= obj->ulInitialCount;
			this->ulCount							= obj->ulCount;
			this->ulRejectCount						= obj->ulRejectCount;
			this->ulMaximum							= obj->ulMaximum;
			this->usPStatus							= obj->usPStatus;
			this->bHardwareSensor					= obj->bHardwareSensor;
		}
		void WFS(XFS300::LPWFSCDMPHCU* lppWFSCDMPHCU)
		{
			TRACELOG("_wfs_cdm_physicalcu::WFS - Started");
			this->lpWFSCDMPHCU = new XFS300::WFSCDMPHCU;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMPHCU->lpPhysicalPositionName, this->lpPhysicalPositionName);
			SAFECOPYSTRING(this->lpWFSCDMPHCU->cUnitID, this->cUnitID);
			this->lpWFSCDMPHCU->ulInitialCount		= this->ulInitialCount;
			this->lpWFSCDMPHCU->ulCount				= this->ulCount;
			this->lpWFSCDMPHCU->ulRejectCount		= this->ulRejectCount;
			this->lpWFSCDMPHCU->ulMaximum			= this->ulMaximum;
			this->lpWFSCDMPHCU->usPStatus			= this->usPStatus;
			this->lpWFSCDMPHCU->bHardwareSensor		= this->bHardwareSensor;
			*lppWFSCDMPHCU = this->lpWFSCDMPHCU;
			TRACELOG("_wfs_cdm_physicalcu::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_physicalcu& obj)
		{
			out << " -- "
				<< " lpPhysicalPositionName: "		<< obj.lpPhysicalPositionName
				<< " cUnitID: "						<< std::string{ obj.cUnitID, 0, 5}
				<< " ulInitialCount: "				<< obj.ulInitialCount
				<< " ulCount: "						<< obj.ulCount
				<< " ulRejectCount: "				<< obj.ulRejectCount
				<< " ulMaximum: "					<< obj.ulMaximum
				<< " usPStatus: "					<< obj.usPStatus
				<< " bHardwareSensor: "				<< obj.bHardwareSensor;
			return out;
		}
		std::string lpPhysicalPositionName;
		std::string cUnitID;
		XFS300::LPWFSCDMPHCU lpWFSCDMPHCU = nullptr;
	} TTWFSCDMPHCU, * LPTTWFSCDMPHCU;

	typedef struct _tt_wfs_cdm_cashunit : public XFS300::_wfs_cdm_cashunit
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_cashunit)
		~_tt_wfs_cdm_cashunit()
		{
			TRACELOG("~_tt_wfs_cdm_cashunit - Started");
			SAFERELEASECONT(lppPhysical);
			SAFEPTR(this->lpWFSCDMCASHUNIT)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMCASHUNIT->lpszCashUnitName);
				SAFERELEASELPP(this->lpWFSCDMCASHUNIT->lppPhysical, this->lpWFSCDMCASHUNIT->usNumPhysicalCUs);
				SAFERELEASE(&this->lpWFSCDMCASHUNIT);
			}
			TRACELOG("~_tt_wfs_cdm_cashunit - Ended");
		}
		void WFS2TT(const XFS300::_wfs_cdm_cashunit* obj)
		{
			this->usNumber							= obj->usNumber;
			this->usType							= obj->usType;
			SAFEPTR(obj->lpszCashUnitName) this->lpszCashUnitName.assign(obj->lpszCashUnitName, 5);
			this->cUnitID.assign(obj->cUnitID, 5);
			this->cCurrencyID.assign(obj->cCurrencyID, 3);
			this->ulValues							= obj->ulValues;
			this->ulInitialCount					= obj->ulInitialCount;
			this->ulCount							= obj->ulCount;
			this->ulRejectCount						= obj->ulRejectCount;
			this->ulMinimum							= obj->ulMinimum;
			this->ulMaximum							= obj->ulMaximum;
			this->bAppLock							= obj->bAppLock;
			this->usStatus							= obj->usStatus;
			this->usNumPhysicalCUs					= obj->usNumPhysicalCUs;
			DeviceUtility::CopyP2APs(this->lppPhysical, obj->lppPhysical, obj->usNumPhysicalCUs);
		}
		void WFS(XFS300::LPWFSCDMCASHUNIT* lppWFSCDMCASHUNIT)
		{
			TRACELOG("_wfs_cdm_cashunit::WFS - Started");
			this->lpWFSCDMCASHUNIT = new XFS300::WFSCDMCASHUNIT;
			this->lpWFSCDMCASHUNIT->usNumber		= this->usNumber;
			this->lpWFSCDMCASHUNIT->usType			= this->usType;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMCASHUNIT->lpszCashUnitName, this->lpszCashUnitName);
			SAFECOPYMEMORY(this->lpWFSCDMCASHUNIT->cUnitID, this->cUnitID.c_str(), 5);
			SAFECOPYMEMORY(this->lpWFSCDMCASHUNIT->cCurrencyID, this->cCurrencyID.c_str(), 3);
			this->lpWFSCDMCASHUNIT->ulValues		= this->ulValues;
			this->lpWFSCDMCASHUNIT->ulInitialCount	= this->ulInitialCount;
			this->lpWFSCDMCASHUNIT->ulCount			= this->ulCount;
			this->lpWFSCDMCASHUNIT->ulRejectCount	= this->ulRejectCount;
			this->lpWFSCDMCASHUNIT->ulMinimum		= this->ulMinimum;
			this->lpWFSCDMCASHUNIT->ulMaximum		= this->ulMaximum;
			this->lpWFSCDMCASHUNIT->bAppLock		= this->bAppLock;
			this->lpWFSCDMCASHUNIT->usStatus		= this->usStatus;
			this->lpWFSCDMCASHUNIT->usNumPhysicalCUs= this->usNumPhysicalCUs;
			DeviceUtility::CopyP2APs_r(this->lpWFSCDMCASHUNIT->lppPhysical, this->lppPhysical);
			*lppWFSCDMCASHUNIT = this->lpWFSCDMCASHUNIT;
			TRACELOG("_wfs_cdm_cashunit::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_cashunit& obj)
		{
			out << " - "
				<< " usNumber: "					<< obj.usNumber
				<< " usType: "						<< obj.usType
				<< " lpszCashUnitName: "			<< obj.lpszCashUnitName
				<< " cUnitID: "						<< obj.cUnitID
				<< " cCurrencyID: "					<< obj.cCurrencyID
				<< " ulValues: "					<< obj.ulValues
				<< " ulInitialCount: "				<< obj.ulInitialCount
				<< " ulCount: "						<< obj.ulCount
				<< " ulRejectCount: "				<< obj.ulRejectCount
				<< " ulMinimum: "					<< obj.ulMinimum
				<< " ulMaximum: "					<< obj.ulMaximum
				<< " bAppLock: "					<< obj.bAppLock
				<< " usStatus: "					<< obj.usStatus
				<< " usNumPhysicalCUs: "			<< obj.usNumPhysicalCUs
				<< " lppPhysical: "					<< DeviceUtility::TTCONT2Str(obj.lppPhysical);

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMPHCU>	lppPhysical;
		std::string								lpszCashUnitName;
		std::string								cUnitID;
		std::string								cCurrencyID;
		XFS300::LPWFSCDMCASHUNIT				lpWFSCDMCASHUNIT = nullptr;
	} TTWFSCDMCASHUNIT, * LPTTWFSCDMCASHUNIT;

	typedef struct _tt_wfs_cdm_cu_info : public XFS300::_wfs_cdm_cu_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_cu_info)
		~_tt_wfs_cdm_cu_info()
		{
			TRACELOG("~_tt_wfs_cdm_cu_info - Started");
			SAFERELEASECONT(this->lppList);
			SAFEPTR(this->lpWFSCDMCUINFO)
			{
				SAFERELEASELPP(this->lpWFSCDMCUINFO->lppList, this->lpWFSCDMCUINFO->usCount);
				SAFERELEASE(&this->lpWFSCDMCUINFO);
			}
			TRACELOG("~_tt_wfs_cdm_cu_info - Ended");
		}
		void WFS2TT(const XFS300::_wfs_cdm_cu_info* obj)
		{
			this->usTellerID = obj->usTellerID;
			this->usCount = obj->usCount;
			DeviceUtility::CopyP2APs(this->lppList, obj->lppList, obj->usCount);
		}
		void WFS(XFS300::LPWFSCDMCUINFO* lppWFSCDMCUINFO)
		{
			TRACELOG("_tt_wfs_cdm_cu_info::WFS - Started");
			this->lpWFSCDMCUINFO = new XFS300::WFSCDMCUINFO;
			this->lpWFSCDMCUINFO->usTellerID = this->usTellerID;
			this->lpWFSCDMCUINFO->usCount = this->usCount;
			DeviceUtility::CopyP2APs_r(this->lpWFSCDMCUINFO->lppList, this->lppList);
			*lppWFSCDMCUINFO = this->lpWFSCDMCUINFO;
			TRACELOG("_tt_wfs_cdm_cu_info::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_cu_info& obj)
		{
			out << " usTellerID: " << obj.usTellerID
				<< " usCount: " << obj.usCount
				<< " lppList: " << DeviceUtility::TTCONT2Str(obj.lppList);

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMCASHUNIT>lppList;
		XFS300::LPWFSCDMCUINFO lpWFSCDMCUINFO = nullptr;
	} TTWFSCDMCUINFO, * LPTTWFSCDMCUINFO;

	typedef struct _tt_wfs_cdm_teller_info : public XFS300::_wfs_cdm_teller_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_info)
			~_tt_wfs_cdm_teller_info() { SAFERELEASE(&this->lpWFSCDMTELLERINFO) }
		void WFS2TT(const XFS300::_wfs_cdm_teller_info* obj)
		{
			this->usTellerID = obj->usTellerID;
			::CopyMemory(this->cCurrencyID, obj->cCurrencyID, 3);
		}
		void WFS(XFS300::LPWFSCDMTELLERINFO* lppWFSCDMTELLERINFO)
		{
			this->lpWFSCDMTELLERINFO = new XFS300::WFSCDMTELLERINFO;
			this->lpWFSCDMTELLERINFO->usTellerID = this->usTellerID;
			SAFECOPYMEMORY(&this->lpWFSCDMTELLERINFO->cCurrencyID, this->cCurrencyID, 3);
			*lppWFSCDMTELLERINFO = this->lpWFSCDMTELLERINFO;
		}
		friend std::ostream& operator << (std::ostream& out, const _wfs_cdm_teller_info& obj)
		{
			out << " usTellerID: " << obj.usTellerID
				<< " cCurrencyID: " << std::string{ obj.cCurrencyID };

			return out;
		}
		XFS300::LPWFSCDMTELLERINFO lpWFSCDMTELLERINFO = nullptr;
	} TTWFSCDMTELLERINFO, * LPTTWFSCDMTELLERINFO;

	typedef struct _tt_wfs_cdm_teller_totals : public XFS300::_wfs_cdm_teller_totals
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_totals)
			~_tt_wfs_cdm_teller_totals() { SAFERELEASE(&this->lpWFSCDMTELLERTOTALS) }
		void WFS2TT(const XFS300::_wfs_cdm_teller_totals* obj)
		{
			SAFECOPYMEMORY(this->cCurrencyID, obj->cCurrencyID, 3);
			this->ulItemsReceived = obj->ulItemsReceived;
			this->ulItemsDispensed = obj->ulItemsDispensed;
			this->ulCoinsReceived = obj->ulCoinsReceived;
			this->ulCoinsDispensed = obj->ulCoinsDispensed;
			this->ulCashBoxReceived = obj->ulCashBoxReceived;
			this->ulCashBoxDispensed = obj->ulCashBoxDispensed;
		}
		void WFS(XFS300::LPWFSCDMTELLERTOTALS* lppWFSCDMTELLERTOTALS)
		{
			this->lpWFSCDMTELLERTOTALS = new XFS300::WFSCDMTELLERTOTALS;
			*lppWFSCDMTELLERTOTALS = this->lpWFSCDMTELLERTOTALS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_teller_totals& obj)
		{
			out << " - "
				<< " ulItemsReceived: " << obj.ulItemsReceived
				<< " ulItemsDispensed: " << obj.ulItemsDispensed
				<< " ulCoinsReceived: " << obj.ulCoinsReceived
				<< " ulCoinsDispensed: " << obj.ulCoinsDispensed
				<< " ulCashBoxReceived: " << obj.ulCashBoxReceived
				<< " ulCashBoxDispensed: " << obj.ulCashBoxDispensed;
			return out;
		}
		XFS300::LPWFSCDMTELLERTOTALS lpWFSCDMTELLERTOTALS = nullptr;
	} TTWFSCDMTELLERTOTALS, * LPTTWFSCDMTELLERTOTALS;

	typedef struct _tt_wfs_cdm_teller_details : public XFS300::_wfs_cdm_teller_details
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_details)
			~_tt_wfs_cdm_teller_details()
		{
			SAFERELEASECONT(lppTellerTotals);
			SAFEPTR(this->lpWFSCDMTELLERDETAILS)
			{
				SAFERELEASELPP(this->lpWFSCDMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals.size());
				SAFERELEASELPP(this->lpWFSCDMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals.size());
				SAFERELEASE(&this->lpWFSCDMTELLERDETAILS);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_teller_details* obj)
		{
			this->usTellerID						= obj->usTellerID;
			this->ulInputPosition					= obj->ulInputPosition;
			this->fwOutputPosition					= obj->fwOutputPosition;
			DeviceUtility::CopyP2NAPs(this->lppTellerTotals, obj->lppTellerTotals);
		}
		void WFS(XFS300::LPWFSCDMTELLERDETAILS* lppWFSCDMTELLERDETAILS)
		{
			this->lpWFSCDMTELLERDETAILS = new XFS300::WFSCDMTELLERDETAILS;
			this->lpWFSCDMTELLERDETAILS->usTellerID			= this->usTellerID;
			this->lpWFSCDMTELLERDETAILS->ulInputPosition	= this->ulInputPosition;
			this->lpWFSCDMTELLERDETAILS->fwOutputPosition	= this->fwOutputPosition;
			DeviceUtility::CopyP2NAPs_r(this->lpWFSCDMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals);
			*lppWFSCDMTELLERDETAILS = this->lpWFSCDMTELLERDETAILS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_teller_details& obj)
		{
			out << " usTellerID: "					<< obj.usTellerID
				<< " ulInputPosition: "				<< obj.ulInputPosition
				<< " fwOutputPosition: "			<< obj.fwOutputPosition
				<< " lppTellerTotals: "				<< DeviceUtility::TTCONT2Str(obj.lppTellerTotals).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMTELLERTOTALS>lppTellerTotals;
		XFS300::LPWFSCDMTELLERDETAILS lpWFSCDMTELLERDETAILS = nullptr;
	} TTWFSCDMTELLERDETAILS, * LPTTWFSCDMTELLERDETAILS;

	typedef struct _tt_wfs_cdm_currency_exp : public XFS300::_wfs_cdm_currency_exp
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_currency_exp)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_currency_exp)
		void WFS2TT(const XFS300::_wfs_cdm_currency_exp* obj)
		{
			this->cCurrencyID.assign(obj->cCurrencyID, 3);

			this->sExponent							= obj->sExponent;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_currency_exp& obj)
		{
			out << " cCurrencyID: "					<< obj.cCurrencyID.c_str()
				<< " sExponent: "					<< obj.sExponent;
			return out;
		}
		std::string cCurrencyID;
	} TTWFSCDMCURRENCYEXP, * LPTTWFSCDMCURRENCYEXP;

	typedef struct _tt_wfs_cdm_p2ap_currency_exp
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_p2ap_currency_exp)
		~_tt_wfs_cdm_p2ap_currency_exp() { SAFERELEASECONT(listCurrencyExp) }
		void WFS2TT(const XFS300::_wfs_cdm_currency_exp* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listCurrencyExp, (XFS300::_wfs_cdm_currency_exp**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_p2ap_currency_exp& obj)
		{
			out << DeviceUtility::TTCONT2Str(obj.listCurrencyExp).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMCURRENCYEXP>listCurrencyExp;
	} TTWFSCDMP2APCURRENCYEXP, * LPTTWFSCDMP2APCURRENCYEXP;

	typedef struct _tt_wfs_cdm_mix_type : public XFS300::_wfs_cdm_mix_type
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_mix_type)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_mix_type)
		void WFS2TT(const XFS300::_wfs_cdm_mix_type* obj)
		{
			this->usMixNumber						= obj->usMixNumber;
			this->usMixType							= obj->usMixType;
			this->usSubType							= obj->usSubType;

			lpszName.assign(obj->lpszName, DeviceUtility::Size_LPSTR(obj->lpszName));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_mix_type& obj)
		{
			out << " usMixNumber: "					<< obj.usMixNumber
				<< " usMixType: "					<< obj.usMixType
				<< " usSubType: "					<< obj.usSubType
				<< " lpszName: "					<< obj.lpszName.c_str();
			return out;
		}
		std::string lpszName;
	} TTWFSCDMMIXTYPE, * LPTTWFSCDMMIXTYPE;

	typedef struct _tt_wfs_cdm_p2ap_mix_type
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_p2ap_mix_type)
		~_tt_wfs_cdm_p2ap_mix_type() { SAFERELEASECONT(listMixType) }
		void WFS2TT(const XFS300::_wfs_cdm_mix_type* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listMixType, (XFS300::_wfs_cdm_mix_type**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_p2ap_mix_type& obj)
		{
			out << DeviceUtility::TTCONT2Str(obj.listMixType).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMMIXTYPE>listMixType;
	} TTWFSCDMP2APMIXTYPE, * LPTTWFSCDMP2APMIXTYPE;

	typedef struct _tt_wfs_cdm_mix_row : public XFS300::_wfs_cdm_mix_row
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_mix_row)
		~_tt_wfs_cdm_mix_row() { SAFERELEASE(&this->lpWFSCDMMIXROW) }
		void WFS2TT(const XFS300::_wfs_cdm_mix_row* obj)
		{
			this->ulAmount							= obj->ulAmount;
			this->lpusMixture						= obj->lpusMixture;
		}
		void WFS(XFS300::LPWFSCDMMIXROW* lppWFSCDMMIXROW)
		{
			this->lpWFSCDMMIXROW = new XFS300::WFSCDMMIXROW;
			this->lpWFSCDMMIXROW->ulAmount			= this->ulAmount;
			this->lpWFSCDMMIXROW->lpusMixture		= this->lpusMixture;
			*lppWFSCDMMIXROW = this->lpWFSCDMMIXROW;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_mix_row& obj)
		{
			out << " - "
				<< " ulAmount: "					<< obj.ulAmount
				<< " lpusMixture: "					<< obj.lpusMixture;
			return out;
		}
		XFS300::LPWFSCDMMIXROW lpWFSCDMMIXROW = nullptr;
	} TTWFSCDMMIXROW, * LPTTWFSCDMMIXROW;

	typedef struct _tt_wfs_cdm_mix_table : public XFS300::_wfs_cdm_mix_table
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_mix_table)
		~_tt_wfs_cdm_mix_table()
		{
			SAFERELEASE(&this->lpulMixHeader);
			SAFERELEASECONT(this->lppMixRows);
			SAFEPTR(this->lpWFSCDMMIXTABLE)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMMIXTABLE->lpszName);
				SAFEFREEMEMORY(&this->lpWFSCDMMIXTABLE->lpulMixHeader);
				SAFERELEASELPP(this->lpWFSCDMMIXTABLE->lppMixRows, this->lppMixRows.size());
				SAFERELEASE(&this->lpWFSCDMMIXTABLE);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_mix_table* obj)
		{
			this->usMixNumber						= obj->usMixNumber;
			this->lpszName.assign(obj->lpszName, DeviceUtility::Size_LPSTR(obj->lpszName));
			this->usRows							= obj->usRows;
			this->usCols							= obj->usCols;
			SAFEALLOCCOPYMEMORY(&this->lpulMixHeader, obj->lpulMixHeader, sizeof(ULONG) * obj->usCols);
			DeviceUtility::CopyP2APs(this->lppMixRows, obj->lppMixRows, obj->usRows);
		}
		void WFS(XFS300::LPWFSCDMMIXTABLE* lppWFSCDMMIXTABLE)
		{
			this->lpWFSCDMMIXTABLE = new XFS300::WFSCDMMIXTABLE;
			this->lpWFSCDMMIXTABLE->usMixNumber		= this->usMixNumber;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMMIXTABLE->lpszName, this->lpszName);
			this->lpWFSCDMMIXTABLE->usRows			= this->usRows;
			this->lpWFSCDMMIXTABLE->usCols			= this->usCols;
			SAFEALLOCCOPYMEMORY(&this->lpWFSCDMMIXTABLE->lpulMixHeader, this->lpulMixHeader, sizeof(ULONG) * this->usCols);
			DeviceUtility::CopyP2APs_r(this->lpWFSCDMMIXTABLE->lppMixRows, this->lppMixRows);
			*lppWFSCDMMIXTABLE = this->lpWFSCDMMIXTABLE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_mix_table& obj)
		{
			out << " usMixNumber: "					<< obj.usMixNumber
				<< " lpszName: "					<< obj.lpszName.c_str()
				<< " usRows: "						<< obj.usRows
				<< " usCols: "						<< obj.usCols
				<< " lpulMixHeader: "				<< TTFRMU::Array2Str(obj.lpulMixHeader, obj.usCols)
				<< " lppMixRows: "					<< DeviceUtility::TTCONT2Str(obj.lppMixRows).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMMIXROW> lppMixRows;
		std::string lpszName;
		XFS300::LPWFSCDMMIXTABLE lpWFSCDMMIXTABLE = nullptr;
	} TTWFSCDMMIXTABLE, * LPTTWFSCDMMIXTABLE;

	typedef struct _tt_wfs_cdm_denomination : public XFS300::_wfs_cdm_denomination
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_denomination)
		~_tt_wfs_cdm_denomination()
		{
			TRACELOG("~_tt_wfs_cdm_denomination - Started");
			SAFEPTR(this->lpWFSCDMDENOMINATION)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMDENOMINATION->lpulValues);
				SAFERELEASE(&this->lpWFSCDMDENOMINATION);
			}
			TRACELOG("~_tt_wfs_cdm_denomination - Ended");
		}
		void WFS2TT(const XFS300::_wfs_cdm_denomination* obj)
		{
			this->cCurrencyID.assign(obj->cCurrencyID, 3);
			this->ulAmount							= obj->ulAmount;
			this->usCount							= obj->usCount;
			SAFEALLOCCOPYMEMORY(&this->lpulValues, obj->lpulValues, obj->usCount * sizeof(ULONG));
			this->ulCashBox = obj->ulCashBox;
		}
		void WFS(XFS300::LPWFSCDMDENOMINATION* lppWFSCDMDENOMINATION)
		{
			this->lpWFSCDMDENOMINATION = new XFS300::WFSCDMDENOMINATION;
			SAFECOPYSTRING(this->lpWFSCDMDENOMINATION->cCurrencyID, this->cCurrencyID.c_str());
			this->lpWFSCDMDENOMINATION->ulAmount	= this->ulAmount;
			this->lpWFSCDMDENOMINATION->usCount		= this->usCount;
			SAFEALLOCCOPYMEMORY(&this->lpWFSCDMDENOMINATION->lpulValues, this->lpulValues, this->usCount * sizeof(ULONG));
			this->lpWFSCDMDENOMINATION->ulCashBox	= this->ulCashBox;
			*lppWFSCDMDENOMINATION = this->lpWFSCDMDENOMINATION;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_denomination& obj)
		{
			out << " - "
				<< " cCurrencyID: "					<< obj.cCurrencyID.c_str()
				<< " ulAmount: "					<< obj.ulAmount
				<< " usCount: "						<< obj.usCount
				<< " lpulValues: ";

			SAFEPTR(obj.lpulValues)
			{
				for (SIZE_T i = 0; i < obj.usCount; ++i)
					out << obj.lpulValues[i] << ' ';
			}

			out << " ulCashBox: "					<< obj.ulCashBox;

			return out;
		}
		std::string cCurrencyID;
		XFS300::LPWFSCDMDENOMINATION lpWFSCDMDENOMINATION = nullptr;
	} TTWFSCDMDENOMINATION, * LPTTWFSCDMDENOMINATION;

	typedef struct _tt_wfs_cdm_present_status : public XFS300::_wfs_cdm_present_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_present_status)
		~_tt_wfs_cdm_present_status() { SAFERELEASE(&this->lpDenomination); }
		void WFS2TT(const XFS300::_wfs_cdm_present_status* obj)
		{
			DeviceUtility::CopyP(&this->lpDenomination, obj->lpDenomination);
			this->wPresentState = obj->wPresentState;

			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_present_status& obj)
		{
			out << " wPresentState: "				<< obj.wPresentState
				<< " lpDenomination: "				<< *(obj.lpDenomination)
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		LPTTWFSCDMDENOMINATION	lpDenomination = nullptr;
		DeviceUtility::STRVECT	lpszExtra;
	} TTWFSCDMPRESENTSTATUS, * LPTTWFSCDMPRESENTSTATUS;

	/*=================================================================*/
	/* CDM Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cdm_denominate : public XFS300::_wfs_cdm_denominate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_denominate)
			~_tt_wfs_cdm_denominate()
		{
			TRACELOG("~_tt_wfs_cdm_denominate - Started");
			SAFERELEASE(&this->lpDenomination);
			SAFEPTR(this->lpWFSCDMDENOMINATE)
			{
				SAFERELEASE(&this->lpWFSCDMDENOMINATE->lpDenomination);
				SAFERELEASE(&this->lpWFSCDMDENOMINATE);
			}
			TRACELOG("~_tt_wfs_cdm_denominate - Ended");
		}
		void WFS2TT(const XFS300::_wfs_cdm_denominate* obj)
		{
			this->usTellerID						= obj->usTellerID;
			this->usMixNumber						= obj->usMixNumber;
			DeviceUtility::CopyP(&this->lpDenomination, obj->lpDenomination);
		}
		void WFS(XFS300::LPWFSCDMDENOMINATE* lppWFSCDMDENOMINATE)
		{
			this->lpWFSCDMDENOMINATE = new XFS300::WFSCDMDENOMINATE;
			this->lpWFSCDMDENOMINATE->usTellerID	= this->usTellerID;
			this->lpWFSCDMDENOMINATE->usMixNumber	= this->usMixNumber;
			DeviceUtility::CopyP_r(&this->lpWFSCDMDENOMINATE->lpDenomination, this->lpDenomination);
			*lppWFSCDMDENOMINATE = this->lpWFSCDMDENOMINATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_denominate& obj)
		{
			out	<< " usTeller: "					<< obj.usTellerID
				<< " usMixNumber: "					<< obj.usMixNumber
				<< " lpDenomination: "; 
			SAFEPTR(obj.lpDenomination) 
				out	<< *obj.lpDenomination;
			return out;
		}
		LPTTWFSCDMDENOMINATION lpDenomination = nullptr;
		XFS300::LPWFSCDMDENOMINATE lpWFSCDMDENOMINATE = nullptr;
	} TTWFSCDMDENOMINATE, * LPTTWFSCDMDENOMINATE;

	typedef struct _tt_wfs_cdm_dispense : public XFS300::_wfs_cdm_dispense
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_dispense)
		~_tt_wfs_cdm_dispense()
		{
			SAFERELEASE(&this->lpDenomination);
			SAFEPTR(this->lpTTWFSCDMDISPENSE)
			{
				SAFERELEASE(&this->lpTTWFSCDMDISPENSE->lpDenomination);
				SAFERELEASE(&this->lpTTWFSCDMDISPENSE);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_dispense* obj)
		{
			this->usTellerID						= obj->usTellerID;
			this->usMixNumber						= obj->usMixNumber;
			this->fwPosition						= obj->fwPosition;
			this->bPresent							= obj->bPresent;
			DeviceUtility::CopyP(&this->lpDenomination, obj->lpDenomination);
		}
		void WFS(XFS300::LPWFSCDMDISPENSE* lppWFSCDMDISPENSE)
		{
			this->lpTTWFSCDMDISPENSE = new XFS300::WFSCDMDISPENSE;
			this->lpTTWFSCDMDISPENSE->usTellerID	= this->usTellerID;
			this->lpTTWFSCDMDISPENSE->usMixNumber	= this->usMixNumber;
			this->lpTTWFSCDMDISPENSE->fwPosition	= this->fwPosition;
			this->lpTTWFSCDMDISPENSE->bPresent		= this->bPresent;
			DeviceUtility::CopyP_r(&this->lpTTWFSCDMDISPENSE->lpDenomination, this->lpDenomination);
			*lppWFSCDMDISPENSE = this->lpTTWFSCDMDISPENSE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_dispense& obj)
		{
			out << " usTellerID: "					<< obj.usTellerID
				<< " usMixNumber: "					<< obj.usMixNumber
				<< " fwPosition : "					<< obj.fwPosition
				<< " bPresent: "					<< std::boolalpha << obj.bPresent
				<< " lpDenomination: "				<< *obj.lpDenomination;
			return out;
		}
		LPTTWFSCDMDENOMINATION  lpDenomination = nullptr;
		XFS300::LPWFSCDMDISPENSE lpTTWFSCDMDISPENSE = nullptr;
	} TTWFSCDMDISPENSE, * LPTTWFSCDMDISPENSE;

	typedef struct _tt_wfs_cdm_physical_cu : public XFS300::_wfs_cdm_physical_cu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_physical_cu)
		~_tt_wfs_cdm_physical_cu()
		{
			SAFEPTR(this->lpWFSCDMPHYSICALCU)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMPHYSICALCU->lpPhysicalPositionName);
				SAFERELEASE(&this->lpWFSCDMPHYSICALCU);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_physical_cu* obj)
		{
			this->bEmptyAll							= obj->bEmptyAll;
			this->fwPosition						= obj->fwPosition;
			SAFEPTR(obj->lpPhysicalPositionName)
				this->lpPhysicalPositionName.assign(obj->lpPhysicalPositionName);
		}
		void WFS(XFS300::LPWFSCDMPHYSICALCU* lppWFSCDMPHYSICALCU)
		{
			this->lpWFSCDMPHYSICALCU = new XFS300::WFSCDMPHYSICALCU;
			this->lpWFSCDMPHYSICALCU->bEmptyAll		= this->bEmptyAll;
			this->lpWFSCDMPHYSICALCU->fwPosition	= this->fwPosition;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMPHYSICALCU->lpPhysicalPositionName, this->lpPhysicalPositionName);
			*lppWFSCDMPHYSICALCU = this->lpWFSCDMPHYSICALCU;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_physical_cu& obj)
		{
			out << " bEmptyAll: "					<< std::boolalpha << (bool)obj.bEmptyAll
				<< " fwPosition: "					<< obj.fwPosition
				<< " lpDenomination: "				<< obj.lpPhysicalPositionName;
			return out;
		}
		std::string lpPhysicalPositionName{};
		XFS300::LPWFSCDMPHYSICALCU lpWFSCDMPHYSICALCU = nullptr;
	} TTWFSCDMPHYSICALCU, * LPTTWFSCDMPHYSICALCU;

	typedef struct _tt_wfs_cdm_counted_phys_cu : public XFS300::_wfs_cdm_counted_phys_cu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_counted_phys_cu)
			void WFS2TT(const XFS300::_wfs_cdm_counted_phys_cu* obj)
		{
			this->lpPhysicalPositionName.assign(obj->lpPhysicalPositionName, DeviceUtility::Size_LPSTR(obj->lpPhysicalPositionName));
			this->cUnitId.assign(obj->cUnitId, 5);
			this->ulDispensed						= obj->ulDispensed;
			this->ulCounted							= obj->ulCounted;
			this->usPStatus							= obj->usPStatus;
		}
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_counted_phys_cu)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_counted_phys_cu& obj)
		{
			out << " - "
				<< " lpPhysicalPositionName: "		<< obj.lpPhysicalPositionName.c_str()
				<< " cUnitId: "						<< obj.cUnitId.c_str()
				<< " ulDispensed: "					<< obj.ulDispensed
				<< " ulCounted: "					<< obj.ulCounted
				<< " usPStatus: "					<< obj.usPStatus;
			return out;
		}
		std::string lpPhysicalPositionName;
		std::string cUnitId;
	} TTWFSCDMCOUNTEDPHYSCU, * LPTTWFSCDMCOUNTEDPHYSCU;

	typedef struct _tt_wfs_cdm_count : public XFS300::_wfs_cdm_count
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_count)
		~_tt_wfs_cdm_count() { SAFERELEASECONT(lppCountedPhysCUs) }
		void WFS2TT(const XFS300::_wfs_cdm_count* obj)
		{
			this->usNumPhysicalCUs = obj->usNumPhysicalCUs;

			DeviceUtility::CopyP2APs(this->lppCountedPhysCUs, obj->lppCountedPhysCUs, obj->usNumPhysicalCUs);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_count& obj)
		{
			out << " usNumPhysicalCUs: "			<< obj.usNumPhysicalCUs
				<< " lppCountedPhysCUs: "			<< DeviceUtility::TTCONT2Str(obj.lppCountedPhysCUs).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMCOUNTEDPHYSCU>lppCountedPhysCUs;
	} TTWFSCDMCOUNT, * LPTTWFSCDMCOUNT;

	typedef struct _tt_wfs_cdm_retract : public XFS300::_wfs_cdm_retract
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_retract)
		~_tt_wfs_cdm_retract() { SAFERELEASE(&this->lpWFSCDMRETRACT) }
		void WFS2TT(const XFS300::_wfs_cdm_retract* obj)
		{
			this->fwOutputPosition = obj->fwOutputPosition;
			this->usRetractArea = obj->usRetractArea;
			this->usIndex = obj->usIndex;
		}
		void WFS(XFS300::LPWFSCDMRETRACT* lppWFSCDMRETRACT)
		{
			this->lpWFSCDMRETRACT = new XFS300::WFSCDMRETRACT;
			this->lpWFSCDMRETRACT->fwOutputPosition = this->fwOutputPosition;
			this->lpWFSCDMRETRACT->usRetractArea	= this->usRetractArea;
			this->lpWFSCDMRETRACT->usIndex			= this->usIndex;
			*lppWFSCDMRETRACT = this->lpWFSCDMRETRACT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_retract& obj)
		{
			out << " fwOutputPosition: "			<< obj.fwOutputPosition
				<< " usRetractArea: "				<< obj.usRetractArea
				<< " usIndex: "						<< obj.usIndex;
			return out;
		}
		XFS300::LPWFSCDMRETRACT lpWFSCDMRETRACT = nullptr;
	} TTWFSCDMRETRACT, * LPTTWFSCDMRETRACT;

	typedef struct _tt_wfs_cdm_teller_update : public XFS300::_wfs_cdm_teller_update
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_update)
		~_tt_wfs_cdm_teller_update() 
		{
			SAFERELEASE(&this->lpTellerDetails);
			SAFEPTR(this->lpWFSCDMTELLERUPDATE)
			{
				SAFERELEASE(&this->lpWFSCDMTELLERUPDATE->lpTellerDetails);
				SAFERELEASE(&this->lpWFSCDMTELLERUPDATE);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_teller_update* obj)
		{
			this->usAction							= obj->usAction;
			SAFEPTR(obj->lpTellerDetails)
				::DeviceUtility::CopyP(&this->lpTellerDetails, obj->lpTellerDetails);
		}
		void WFS(XFS300::LPWFSCDMTELLERUPDATE* lppWFSCDMTELLERUPDATE)
		{
			this->lpWFSCDMTELLERUPDATE = new XFS300::WFSCDMTELLERUPDATE;
			this->lpWFSCDMTELLERUPDATE->usAction	= this->usAction;
			::DeviceUtility::CopyP_r(&this->lpWFSCDMTELLERUPDATE->lpTellerDetails, this->lpTellerDetails);
			*lppWFSCDMTELLERUPDATE = this->lpWFSCDMTELLERUPDATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_teller_update& obj)
		{
			out << " usAction: "					<< obj.usAction;
			SAFEPTR(obj.lpTellerDetails)
				out << " lpTellerDetails: "			<< *obj.lpTellerDetails;
			return out;
		}
		LPTTWFSCDMTELLERDETAILS lpTellerDetails;
		XFS300::LPWFSCDMTELLERUPDATE lpWFSCDMTELLERUPDATE = nullptr;
	} TTWFSCDMTELLERUPDATE, * LPTTWFSCDMTELLERUPDATE;

	typedef struct _tt_wfs_cdm_start_ex : public XFS300::_wfs_cdm_start_ex
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_start_ex)
		~_tt_wfs_cdm_start_ex()
		{
			SAFEFREEMEMORY(&this->lpusCUNumList);
			SAFEPTR(this->lpWFSCDMSTARTEX)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMSTARTEX->lpusCUNumList);
				SAFERELEASE(&this->lpWFSCDMSTARTEX);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_start_ex* obj)
		{
			this->fwExchangeType					= obj->fwExchangeType;
			this->usTellerID						= obj->usTellerID;
			this->usCount							= obj->usCount;
			if (obj->usCount) {
				SAFEALLOCCOPYMEMORY(&this->lpusCUNumList, obj->lpusCUNumList, obj->usCount * sizeof(unsigned short));
			}
			else
				this->lpWFSCDMSTARTEX->lpusCUNumList = nullptr;
			DEBUGLOG("_tt_wfs_cdm_start_ex::WFS2TT - %d", this->lpusCUNumList[0]);
		}
		void WFS(XFS300::LPWFSCDMSTARTEX* lppWFSCDMSTARTEX)
		{
			this->lpWFSCDMSTARTEX = new XFS300::WFSCDMSTARTEX;
			this->lpWFSCDMSTARTEX->fwExchangeType	= this->fwExchangeType;
			this->lpWFSCDMSTARTEX->usTellerID		= this->usTellerID;
			this->lpWFSCDMSTARTEX->usCount			= this->usCount;
			if (this->usCount) {
				SAFEALLOCCOPYMEMORY(&this->lpWFSCDMSTARTEX->lpusCUNumList, this->lpusCUNumList, this->usCount * sizeof(unsigned short));
			}
			else
				this->lpWFSCDMSTARTEX->lpusCUNumList = nullptr;
			*lppWFSCDMSTARTEX = this->lpWFSCDMSTARTEX;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_start_ex& obj)
		{
			out << " fwExchangeType: "				<< obj.fwExchangeType
				<< " usTellerID: "					<< obj.usTellerID
				<< " usCount: "						<< obj.usCount
				<< " lpusCUNumList: ";
			if (obj.lpusCUNumList)
				for (size_t i = 0; i < obj.usCount; ++i)
					out << obj.lpusCUNumList[i] << " ";
			return out;
		}
		XFS300::LPWFSCDMSTARTEX lpWFSCDMSTARTEX = nullptr;
	} TTWFSCDMSTARTEX, * LPTTWFSCDMSTARTEX;

	typedef struct _tt_wfs_cdm_itemposition : public XFS300::_wfs_cdm_itemposition
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_itemposition)
			~_tt_wfs_cdm_itemposition()
		{
			SAFERELEASE(&this->lpRetractArea);
			SAFEPTR(this->lpWFSCDMITEMPOSITION)
			{
				SAFERELEASE(&this->lpWFSCDMITEMPOSITION->lpRetractArea);
				SAFERELEASE(&this->lpWFSCDMITEMPOSITION);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_itemposition* obj)
		{
			this->usNumber = obj->usNumber;
			DeviceUtility::CopyP(&this->lpRetractArea, obj->lpRetractArea);
			this->fwOutputPosition = obj->fwOutputPosition;
		}
		void WFS(XFS300::LPWFSCDMITEMPOSITION* lppWFSCDMITEMPOSITION)
		{
			this->lpWFSCDMITEMPOSITION = new XFS300::WFSCDMITEMPOSITION;
			this->lpWFSCDMITEMPOSITION->usNumber = this->usNumber;
			this->lpWFSCDMITEMPOSITION->fwOutputPosition = this->fwOutputPosition;
			DeviceUtility::CopyP_r(&this->lpWFSCDMITEMPOSITION->lpRetractArea, this->lpRetractArea);
			*lppWFSCDMITEMPOSITION = this->lpWFSCDMITEMPOSITION;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_itemposition& obj)
		{
			out << " usNumber: "					<< obj.usNumber
				<< " lpRetractArea: ";
			SAFEPTR(obj.lpRetractArea)
				out << *obj.lpRetractArea;
			out << " fwOutputPosition: "			<< obj.fwOutputPosition;
			return out;
		}
		LPTTWFSCDMRETRACT lpRetractArea = nullptr;
		XFS300::LPWFSCDMITEMPOSITION lpWFSCDMITEMPOSITION = nullptr;
	} TTWFSCDMITEMPOSITION, * LPTTWFSCDMITEMPOSITION;

	typedef struct _tt_wfs_cdm_calibrate : public XFS300::_wfs_cdm_calibrate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_calibrate)
		~_tt_wfs_cdm_calibrate()
		{
			SAFERELEASE(this->lppPosition);
			SAFEPTR(this->lpWFSCDMCALIBRATE) 
			{
				SAFERELEASE(&this->lpWFSCDMCALIBRATE->lppPosition);
				SAFERELEASE(&this->lpWFSCDMCALIBRATE);
			}
		}
		void WFS2TT(const XFS300::_wfs_cdm_calibrate* obj)
		{
			this->usNumber							= obj->usNumber;
			this->usNumOfBills						= obj->usNumOfBills;
			DeviceUtility::CopyP(this->lppPosition, *obj->lppPosition);
		}
		void WFS(XFS300::LPWFSCDMCALIBRATE* lppWFSCDMCALIBRATE)
		{
			this->lpWFSCDMCALIBRATE = new XFS300::WFSCDMCALIBRATE;
			this->lpWFSCDMCALIBRATE->usNumber		= this->usNumber;
			this->lpWFSCDMCALIBRATE->usNumOfBills	= this->usNumOfBills;
			DeviceUtility::CopyP_r(this->lpWFSCDMCALIBRATE->lppPosition, *this->lppPosition);
			*lppWFSCDMCALIBRATE = this->lpWFSCDMCALIBRATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_calibrate& obj)
		{
			out << " usNumber: "					<< obj.usNumber
				<< " usNumOfBills: "				<< obj.usNumOfBills
				<< " lpPosition: "					<< *(obj.lppPosition);
			return out;
		}
		LPTTWFSCDMITEMPOSITION* lppPosition = nullptr;
		XFS300::LPWFSCDMCALIBRATE lpWFSCDMCALIBRATE = nullptr;
	} TTWFSCDMCALIBRATE, * LPTTWFSCDMCALIBRATE;

	/*=================================================================*/
	/* CDM Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cdm_cu_error : public XFS300::_wfs_cdm_cu_error
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_cu_error)
		~_tt_wfs_cdm_cu_error() { SAFERELEASE(&this->lpCashUnit) }
		void WFS2TT(const XFS300::_wfs_cdm_cu_error* obj)
		{
			this->wFailure							= obj->wFailure;
			DeviceUtility::CopyP(&this->lpCashUnit, obj->lpCashUnit);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_cu_error& obj)
		{
			out << " wFailure: "					<< obj.wFailure
				<< " lpCashUnit: "					<< *obj.lpCashUnit;
			return out;
		}
		LPTTWFSCDMCASHUNIT lpCashUnit;
	} TTWFSCDMCUERROR, * LPTTWFSCDMCUERROR;

	typedef struct _tt_wfs_cdm_counts_changed : public XFS300::_wfs_cdm_counts_changed
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_counts_changed)
		~_tt_wfs_cdm_counts_changed() { SAFEFREEMEMORY(&this->lpusCUNumList) }
		void WFS2TT(const XFS300::_wfs_cdm_counts_changed* obj)
		{
			this->usCount							= obj->usCount;
			this->lpusCUNumList = (USHORT*)::malloc(sizeof(USHORT) * obj->usCount);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_counts_changed& obj)
		{
			out << " usCount: " << obj.usCount
				<< " lpusCUNumList: ";
			for (size_t i = 0; i < obj.usCount; ++i)
				out << obj.lpusCUNumList[i];
			return out;
		}
	} TTWFSCDMCOUNTSCHANGED, * LPTTWFSCDMCOUNTSCHANGED;

#pragma pack(pop)

	/*=================================================================*/
	/* ICDM Utilities */
	/*=================================================================*/

	//inline bool assign(LPTTWFSCDMCUINFO* lppCUInfo, LPTTWFSCDMCUINFO lpTTCUInfo)
	//{
	//	UNSAFEPTR(lpTTCUInfo)
	//		return false;

	//	UNSAFEPTR(lppCUInfo)
	//		return false;

	//	SIZE_T					_size = 0;
	//	LPBYTE					_tempPtr = NULL;
	//	LPTTWFSCDMCUINFO		_LPTTWFSCDMCUInfo = NULL;
	//	LPTTWFSCDMCASHUNIT		_LPTTWFSCDMCashUnit = NULL;
	//	LPTTWFSCDMPHCU			_LPTTWFSCDMPCU = NULL;

	//	// Calculating necessary memory size
	//	_size = sizeof(XFS300::WFSCDMCUINFO);
	//	_size += lpTTCUInfo->usCount * 4;				// size of array of pointers to LCUs
	//	for (const auto& lcu : lpTTCUInfo->lppList)
	//	{
	//		_size += sizeof(XFS300::WFSCDMCASHUNIT);
	//		_size += 5;									// Size_LPSTR(lcu->lpszCashUnitName);
	//		_size += lcu->usNumPhysicalCUs * 4;			// size of array of pointers to PCUs
	//		for (const auto& pcu : lcu->lppPhysical)
	//		{
	//			_size += sizeof(XFS300::WFSCDMPHCU);
	//			_size += 5;								// Size_LPSTR(pcu->lpPhysicalPositionName);
	//		}
	//	}

	//	// Allocating necessary memory from Heap
	//	_tempPtr = (LPBYTE)malloc(_size);
	//	UNSAFEPTR(_tempPtr)
	//		return false;
	//	ZeroMemory(_tempPtr, _size);

	//	// Assigning WFSCDMCUINFO properties
	//	_LPTTWFSCDMCUInfo = (LPTTWFSCDMCUINFO)_tempPtr;
	//	_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCDMCUINFO));

	//	_LPTTWFSCDMCUInfo->usTellerID = lpTTCUInfo->usTellerID;
	//	_LPTTWFSCDMCUInfo->usCount = lpTTCUInfo->usCount;
	//	_LPTTWFSCDMCUInfo->lppList = (LPTTWFSCDMCASHUNIT*)_tempPtr;
	//	_tempPtr = (LPBYTE)((ULONG)_tempPtr + (lpTTCUInfo->usCount * 4));
	//	USHORT _usLCUIndex = 0;

	//	// Assigning WFSCDMCASHUNIT properties
	//	for (auto& lcu : lpTTCUInfo->lppList)
	//	{
	//		_LPTTWFSCDMCashUnit = (LPTTWFSCDMCASHUNIT)_tempPtr;
	//		_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCDMCASHUNIT));
	//		_LPTTWFSCDMCUInfo->lppList[_usLCUIndex] = _LPTTWFSCDMCashUnit;
	//		_usLCUIndex++;

	//		_LPTTWFSCDMCashUnit->usNumber = lcu->usNumber;
	//		_LPTTWFSCDMCashUnit->usType = lcu->usType;

	//		_LPTTWFSCDMCashUnit->lpszCashUnitName = (LPSTR)_tempPtr;
	//		_tempPtr = (LPBYTE)((ULONG)_tempPtr + 5);

	//		SAFECOPYMEMORY(_LPTTWFSCDMCashUnit->lpszCashUnitName, lcu->lpszCashUnitName.c_str(), 5);
	//		SAFECOPYMEMORY(_LPTTWFSCDMCashUnit->cUnitID, lcu->cUnitID.c_str(), 5);
	//		SAFECOPYMEMORY(_LPTTWFSCDMCashUnit->cCurrencyID, lcu->cCurrencyID.c_str(), 3);

	//		_LPTTWFSCDMCashUnit->ulValues = lcu->ulValues;
	//		_LPTTWFSCDMCashUnit->ulInitialCount = lcu->ulInitialCount;
	//		_LPTTWFSCDMCashUnit->ulCount = lcu->ulCount;
	//		_LPTTWFSCDMCashUnit->ulRejectCount = lcu->ulRejectCount;
	//		_LPTTWFSCDMCashUnit->ulMinimum = lcu->ulMinimum;
	//		_LPTTWFSCDMCashUnit->ulMaximum = lcu->ulMaximum;
	//		_LPTTWFSCDMCashUnit->bAppLock = lcu->bAppLock;
	//		_LPTTWFSCDMCashUnit->usStatus = lcu->usStatus;
	//		_LPTTWFSCDMCashUnit->usNumPhysicalCUs = lcu->usNumPhysicalCUs;
	//		_LPTTWFSCDMCashUnit->lppPhysical = (LPTTWFSCDMPHCU*)_tempPtr;
	//		_tempPtr = (LPBYTE)((ULONG)_tempPtr + (lcu->usNumPhysicalCUs * 4));
	//		USHORT _usPCUIndex = 0;

	//		// Assigning WFSCDMPHCU properties
	//		for (auto pcu : lcu->lppPhysical)
	//		{
	//			_LPTTWFSCDMPCU = (LPTTWFSCDMPHCU)_tempPtr;
	//			_tempPtr = (LPBYTE)((ULONG)_tempPtr + sizeof(XFS300::WFSCDMPHCU));
	//			_LPTTWFSCDMCashUnit->lppPhysical[_usPCUIndex] = _LPTTWFSCDMPCU;
	//			_usPCUIndex++;

	//			_LPTTWFSCDMPCU->lpPhysicalPositionName = (LPSTR)_tempPtr;
	//			_tempPtr = (LPBYTE)((ULONG)_tempPtr + 5);

	//			SAFECOPYMEMORY(_LPTTWFSCDMPCU->lpPhysicalPositionName, pcu->lpPhysicalPositionName.c_str(), 5);
	//			SAFECOPYMEMORY(_LPTTWFSCDMPCU->cUnitID, pcu->cUnitID.c_str(), 5);
	//			_LPTTWFSCDMPCU->ulInitialCount = pcu->ulInitialCount;
	//			_LPTTWFSCDMPCU->ulCount = pcu->ulCount;
	//			_LPTTWFSCDMPCU->ulRejectCount = pcu->ulRejectCount;
	//			_LPTTWFSCDMPCU->ulMaximum = pcu->ulMaximum;
	//			_LPTTWFSCDMPCU->usPStatus = pcu->usPStatus;
	//			_LPTTWFSCDMPCU->bHardwareSensor = pcu->bHardwareSensor;
	//		}
	//	}
	//	*lppCUInfo = _LPTTWFSCDMCUInfo;

	//	return true;
	//}

	/*=================================================================*/
	/* ICDM Interface */
	/*=================================================================*/

	class ITTCDM : public ITTDevice
	{

	public:
		ITTCDM() = default;
		ITTCDM(const ITTCDM&) = delete;
		ITTCDM(ITTCDM&&) = delete;
		ITTCDM& operator = (const ITTCDM&) = delete;
		ITTCDM& operator = (ITTCDM&&) = delete;
		virtual ~ITTCDM() = default;

		/* CDM Info Commands */
		virtual bool GetStatus(LPTTWFSCDMSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSCDMCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCashUnitInfo(LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetTellerInfo(LPTTWFSCDMTELLERINFO, LPTTWFSCDMTELLERDETAILS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCurrencyExp(LPTTWFSCDMP2APCURRENCYEXP, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetMixTypes(LPTTWFSCDMP2APMIXTYPE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetMixTable(LPUSHORT, LPTTWFSCDMMIXTABLE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetPresentStatus(LPWORD, LPTTWFSCDMPRESENTSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCashUnitInfo(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetTellerInfo(LPTTWFSCDMTELLERINFO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCurrencyExp(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetMixTypes(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetMixTable(LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetPresentStatus(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* CDM Execute Commands */
		virtual bool Denominate(const LPTTWFSCDMDENOMINATE, LPTTWFSCDMDENOMINATION, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Dispense(const LPTTWFSCDMDISPENSE, LPTTWFSCDMDENOMINATION, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Count(const LPTTWFSCDMPHYSICALCU, LPTTWFSCDMCOUNT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Present(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reject(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Retract(const LPTTWFSCDMRETRACT, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool OpenShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CloseShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetTelleInfo(const LPTTWFSCDMTELLERUPDATE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetCashUnitInfo(const LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool StartExchange(const LPTTWFSCDMSTARTEX, LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool EndExchange(const LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool OpenSafeDoor(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CalibirateCashUnit(const LPTTWFSCDMCALIBRATE, LPTTWFSCDMCALIBRATE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetMixTable(const LPTTWFSCDMMIXTABLE, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const LPTTWFSCDMITEMPOSITION, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool TestCashUnits(const LPTTWFSCDMITEMPOSITION, LPTTWFSCDMCUINFO, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncDenominate(const LPTTWFSCDMDENOMINATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDispense(const LPTTWFSCDMDISPENSE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCount(const LPTTWFSCDMPHYSICALCU, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncPresent(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReject(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRetract(const LPTTWFSCDMRETRACT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncOpenShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCloseShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetTelleInfo(const LPTTWFSCDMTELLERUPDATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetCashUnitInfo(const LPTTWFSCDMCUINFO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncStartExchange(const LPTTWFSCDMSTARTEX, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncEndExchange(const LPTTWFSCDMCUINFO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncOpenSafeDoor(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCalibirateCashUnit(const LPTTWFSCDMCALIBRATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetMixTable(const LPTTWFSCDMMIXTABLE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(const LPTTWFSCDMITEMPOSITION, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncTestCashUnits(const LPTTWFSCDMITEMPOSITION, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTCDM__