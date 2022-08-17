#pragma once

#ifndef __H_ITTCDM_310__
#define __H_ITTCDM_310__

#include "../ITTDevice.h"
#include <DeviceUtility.h>

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* CDM Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cdm_position_310 : public XFS310::_wfs_cdm_position
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_position_310)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_position_310)
		void WFS2TT(const XFS310::_wfs_cdm_position* obj)
		{
			this->fwPosition						= obj->fwPosition;
			this->fwShutter							= obj->fwShutter;
			this->fwPositionStatus					= obj->fwPositionStatus;
			this->fwTransport						= obj->fwTransport;
			this->fwTransportStatus					= obj->fwTransportStatus;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_position_310& obj)
		{
			out << " - "
				<< " fwPosition: "					<< obj.fwPosition
				<< " fwShutter: "					<< obj.fwShutter
				<< " fwPositionStatus: "			<< obj.fwPositionStatus
				<< " fwTransport: "					<< obj.fwTransport
				<< " fwTransportStatus: "			<< obj.fwTransportStatus;
			return out;
		}
	} TTWFSCDMOUTPOS310, * LPTTWFSCDMOUTPOS310;

	typedef struct _tt_wfs_cdm_status_310 : public XFS310::_wfs_cdm_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_status_310)
		~_tt_wfs_cdm_status_310() { SAFERELEASECONT(this->lppPositions) }
		void WFS2TT(const XFS310::_wfs_cdm_status* obj)
		{
			this->fwDevice							= obj->fwDevice;
			this->fwSafeDoor						= obj->fwSafeDoor;
			this->fwDispenser						= obj->fwDispenser;
			this->fwIntermediateStacker				= obj->fwIntermediateStacker;
			DeviceUtility::CopyP2NAPs(this->lppPositions, obj->lppPositions);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_status_310& obj)
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
		DeviceUtility::TTCONT<LPTTWFSCDMOUTPOS310>	lppPositions;
		DeviceUtility::STRVECT					lpszExtra;
	} TTWFSCDMSTATUS310, * LPTTWFSCDMSTATUS310;

	typedef struct _tt_wfs_cdm_caps_310 : public XFS310::_wfs_cdm_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_caps_310)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_caps_310)
		void WFS2TT(const XFS310::_wfs_cdm_caps* obj)
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
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_caps_310& obj)
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
	} TTWFSCDMCAPS310, * LPTTWFSCDMCAPS310;

	typedef struct _tt_wfs_cdm_physicalcu_310 : public XFS310::_wfs_cdm_physicalcu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_physicalcu_310)
		~_tt_wfs_cdm_physicalcu_310()
		{
			SAFEPTR(this->lpWFSCDMPHCU)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMPHCU->lpPhysicalPositionName);
				SAFERELEASE(&this->lpWFSCDMPHCU);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_physicalcu* obj)
		{
			SAFEPTR(obj->lpPhysicalPositionName) this->lpPhysicalPositionName.assign(obj->lpPhysicalPositionName, 5);
			this->cUnitID.assign(obj->cUnitID, 5);
			this->ulInitialCount					= obj->ulInitialCount;
			this->ulCount							= obj->ulCount;
			this->ulRejectCount						= obj->ulRejectCount;
			this->ulMaximum							= obj->ulMaximum;
			this->usPStatus							= obj->usPStatus;
			this->bHardwareSensor					= obj->bHardwareSensor;
			// XFS310
			this->ulDispensedCount					= obj->ulDispensedCount;
			this->ulPresentedCount					= obj->ulPresentedCount;
			this->ulRetractedCount					= obj->ulRetractedCount;
		}
		void WFS(XFS310::LPWFSCDMPHCU* lppWFSCDMPHCU)
		{
			TRACELOG("_wfs_cdm_physicalcu::WFS - Started");
			this->lpWFSCDMPHCU = new XFS310::WFSCDMPHCU;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMPHCU->lpPhysicalPositionName, this->lpPhysicalPositionName);
			SAFECOPYSTRING(this->lpWFSCDMPHCU->cUnitID, this->cUnitID);
			this->lpWFSCDMPHCU->ulInitialCount		= this->ulInitialCount;
			this->lpWFSCDMPHCU->ulCount				= this->ulCount;
			this->lpWFSCDMPHCU->ulRejectCount		= this->ulRejectCount;
			this->lpWFSCDMPHCU->ulMaximum			= this->ulMaximum;
			this->lpWFSCDMPHCU->usPStatus			= this->usPStatus;
			this->lpWFSCDMPHCU->bHardwareSensor		= this->bHardwareSensor;
			// XFS310
			this->lpWFSCDMPHCU->ulDispensedCount	= this->ulDispensedCount;
			this->lpWFSCDMPHCU->ulPresentedCount	= this->ulPresentedCount;
			this->lpWFSCDMPHCU->ulRetractedCount	= this->ulRetractedCount;
			*lppWFSCDMPHCU = this->lpWFSCDMPHCU;
			TRACELOG("_wfs_cdm_physicalcu::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_physicalcu_310& obj)
		{
			out << " -- "
				<< " lpPhysicalPositionName: "		<< obj.lpPhysicalPositionName
				<< " cUnitID: "						<< std::string{ obj.cUnitID, 0, 5}
				<< " ulInitialCount: "				<< obj.ulInitialCount
				<< " ulCount: "						<< obj.ulCount
				<< " ulRejectCount: "				<< obj.ulRejectCount
				<< " ulMaximum: "					<< obj.ulMaximum
				<< " usPStatus: "					<< obj.usPStatus
				<< " bHardwareSensor: "				<< obj.bHardwareSensor
				// XFS310
				<< " ulDispensedCount: "			<< obj.ulDispensedCount
				<< " ulPresentedCount: "			<< obj.ulPresentedCount
				<< " ulRetractedCount: "			<< obj.ulRetractedCount;
			return out;
		}
		std::string lpPhysicalPositionName;
		std::string cUnitID;
		XFS310::LPWFSCDMPHCU lpWFSCDMPHCU = nullptr;
	} TTWFSCDMPHCU310, * LPTTWFSCDMPHCU310;

	typedef struct _tt_wfs_cdm_cashunit_310 : public XFS310::_wfs_cdm_cashunit
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_cashunit_310)
		~_tt_wfs_cdm_cashunit_310()
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
		void WFS2TT(const XFS310::_wfs_cdm_cashunit* obj)
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
			// XFS310
			this->ulDispensedCount					= obj->ulDispensedCount;
			this->ulPresentedCount					= obj->ulPresentedCount;
			this->ulRetractedCount					= obj->ulRetractedCount;
		}
		void WFS(XFS310::LPWFSCDMCASHUNIT* lppWFSCDMCASHUNIT)
		{
			TRACELOG("_wfs_cdm_cashunit::WFS - Started");
			this->lpWFSCDMCASHUNIT = new XFS310::WFSCDMCASHUNIT;
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
			// XFS310
			this->lpWFSCDMCASHUNIT->ulDispensedCount = this->ulDispensedCount;
			this->lpWFSCDMCASHUNIT->ulPresentedCount = this->ulPresentedCount;
			this->lpWFSCDMCASHUNIT->ulRetractedCount = this->ulRetractedCount;
			*lppWFSCDMCASHUNIT = this->lpWFSCDMCASHUNIT;
			TRACELOG("_wfs_cdm_cashunit::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_cashunit_310& obj)
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
				<< " lppPhysical: "					<< DeviceUtility::TTCONT2Str(obj.lppPhysical)
				// XFS310
				<< " ulDispensedCount: "			<< obj.ulDispensedCount
				<< " ulPresentedCount: "			<< obj.ulPresentedCount
				<< " ulRetractedCount: "			<< obj.ulRetractedCount;

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMPHCU310>	lppPhysical;
		std::string									lpszCashUnitName;
		std::string									cUnitID;
		std::string									cCurrencyID;
		XFS310::LPWFSCDMCASHUNIT					lpWFSCDMCASHUNIT = nullptr;
	} TTWFSCDMCASHUNIT310, * LPTTWFSCDMCASHUNIT310;

	typedef struct _tt_wfs_cdm_cu_info_310 : public XFS310::_wfs_cdm_cu_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_cu_info_310)
		~_tt_wfs_cdm_cu_info_310()
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
		void WFS2TT(const XFS310::_wfs_cdm_cu_info* obj)
		{
			this->usTellerID = obj->usTellerID;
			this->usCount = obj->usCount;
			DeviceUtility::CopyP2APs(this->lppList, obj->lppList, obj->usCount);
		}
		void WFS(XFS310::LPWFSCDMCUINFO* lppWFSCDMCUINFO)
		{
			TRACELOG("_tt_wfs_cdm_cu_info::WFS - Started");
			this->lpWFSCDMCUINFO = new XFS310::WFSCDMCUINFO;
			this->lpWFSCDMCUINFO->usTellerID = this->usTellerID;
			this->lpWFSCDMCUINFO->usCount = this->usCount;
			DeviceUtility::CopyP2APs_r(this->lpWFSCDMCUINFO->lppList, this->lppList);
			*lppWFSCDMCUINFO = this->lpWFSCDMCUINFO;
			TRACELOG("_tt_wfs_cdm_cu_info::WFS - Ended");
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_cu_info_310& obj)
		{
			out << " usTellerID: " << obj.usTellerID
				<< " usCount: " << obj.usCount
				<< " lppList: " << DeviceUtility::TTCONT2Str(obj.lppList);

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMCASHUNIT310>lppList;
		XFS310::LPWFSCDMCUINFO lpWFSCDMCUINFO = nullptr;
	} TTWFSCDMCUINFO310, * LPTTWFSCDMCUINFO310;

	typedef struct _tt_wfs_cdm_teller_info_310 : public XFS310::_wfs_cdm_teller_info
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_info_310)
		~_tt_wfs_cdm_teller_info_310() { SAFERELEASE(&this->lpWFSCDMTELLERINFO) }
		void WFS2TT(const XFS310::_wfs_cdm_teller_info* obj)
		{
			this->usTellerID = obj->usTellerID;
			::CopyMemory(this->cCurrencyID, obj->cCurrencyID, 3);
		}
		void WFS(XFS310::LPWFSCDMTELLERINFO* lppWFSCDMTELLERINFO)
		{
			this->lpWFSCDMTELLERINFO = new XFS310::WFSCDMTELLERINFO;
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
		XFS310::LPWFSCDMTELLERINFO lpWFSCDMTELLERINFO = nullptr;
	} TTWFSCDMTELLERINFO310, * LPTTWFSCDMTELLERINFO310;

	typedef struct _tt_wfs_cdm_teller_totals_310 : public XFS310::_wfs_cdm_teller_totals
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_totals_310)
		~_tt_wfs_cdm_teller_totals_310() { SAFERELEASE(&this->lpWFSCDMTELLERTOTALS) }
		void WFS2TT(const XFS310::_wfs_cdm_teller_totals* obj)
		{
			SAFECOPYMEMORY(this->cCurrencyID, obj->cCurrencyID, 3);
			this->ulItemsReceived = obj->ulItemsReceived;
			this->ulItemsDispensed = obj->ulItemsDispensed;
			this->ulCoinsReceived = obj->ulCoinsReceived;
			this->ulCoinsDispensed = obj->ulCoinsDispensed;
			this->ulCashBoxReceived = obj->ulCashBoxReceived;
			this->ulCashBoxDispensed = obj->ulCashBoxDispensed;
		}
		void WFS(XFS310::LPWFSCDMTELLERTOTALS* lppWFSCDMTELLERTOTALS)
		{
			this->lpWFSCDMTELLERTOTALS = new XFS310::WFSCDMTELLERTOTALS;
			*lppWFSCDMTELLERTOTALS = this->lpWFSCDMTELLERTOTALS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_teller_totals_310& obj)
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
		XFS310::LPWFSCDMTELLERTOTALS lpWFSCDMTELLERTOTALS = nullptr;
	} TTWFSCDMTELLERTOTALS310, * LPTTWFSCDMTELLERTOTALS310;

	typedef struct _tt_wfs_cdm_teller_details_310 : public XFS310::_wfs_cdm_teller_details
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_details_310)
		~_tt_wfs_cdm_teller_details_310()
		{
			SAFERELEASECONT(lppTellerTotals);
			SAFEPTR(this->lpWFSCDMTELLERDETAILS)
			{
				SAFERELEASELPP(this->lpWFSCDMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals.size());
				SAFERELEASELPP(this->lpWFSCDMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals.size());
				SAFERELEASE(&this->lpWFSCDMTELLERDETAILS);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_teller_details* obj)
		{
			this->usTellerID						= obj->usTellerID;
			this->ulInputPosition					= obj->ulInputPosition;
			this->fwOutputPosition					= obj->fwOutputPosition;
			DeviceUtility::CopyP2NAPs(this->lppTellerTotals, obj->lppTellerTotals);
		}
		void WFS(XFS310::LPWFSCDMTELLERDETAILS* lppWFSCDMTELLERDETAILS)
		{
			this->lpWFSCDMTELLERDETAILS = new XFS310::WFSCDMTELLERDETAILS;
			this->lpWFSCDMTELLERDETAILS->usTellerID			= this->usTellerID;
			this->lpWFSCDMTELLERDETAILS->ulInputPosition	= this->ulInputPosition;
			this->lpWFSCDMTELLERDETAILS->fwOutputPosition	= this->fwOutputPosition;
			DeviceUtility::CopyP2NAPs_r(this->lpWFSCDMTELLERDETAILS->lppTellerTotals, this->lppTellerTotals);
			*lppWFSCDMTELLERDETAILS = this->lpWFSCDMTELLERDETAILS;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_teller_details_310& obj)
		{
			out << " usTellerID: "					<< obj.usTellerID
				<< " ulInputPosition: "				<< obj.ulInputPosition
				<< " fwOutputPosition: "			<< obj.fwOutputPosition
				<< " lppTellerTotals: "				<< DeviceUtility::TTCONT2Str(obj.lppTellerTotals).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMTELLERTOTALS310>lppTellerTotals;
		XFS310::LPWFSCDMTELLERDETAILS lpWFSCDMTELLERDETAILS = nullptr;
	} TTWFSCDMTELLERDETAILS310, * LPTTWFSCDMTELLERDETAILS310;

	typedef struct _tt_wfs_cdm_currency_exp_310 : public XFS310::_wfs_cdm_currency_exp
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_currency_exp_310)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_currency_exp_310)
		void WFS2TT(const XFS310::_wfs_cdm_currency_exp* obj)
		{
			this->cCurrencyID.assign(obj->cCurrencyID, 3);

			this->sExponent							= obj->sExponent;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_currency_exp_310& obj)
		{
			out << " cCurrencyID: "					<< obj.cCurrencyID.c_str()
				<< " sExponent: "					<< obj.sExponent;
			return out;
		}
		std::string cCurrencyID;
	} TTWFSCDMCURRENCYEXP310, * LPTTWFSCDMCURRENCYEXP310;

	typedef struct _tt_wfs_cdm_p2ap_currency_exp_310
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_p2ap_currency_exp_310)
		~_tt_wfs_cdm_p2ap_currency_exp_310() { SAFERELEASECONT(listCurrencyExp) }
		void WFS2TT(const XFS310::_wfs_cdm_currency_exp* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listCurrencyExp, (XFS310::_wfs_cdm_currency_exp**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_p2ap_currency_exp_310& obj)
		{
			out << DeviceUtility::TTCONT2Str(obj.listCurrencyExp).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMCURRENCYEXP310>listCurrencyExp;
	} TTWFSCDMP2APCURRENCYEXP310, * LPTTWFSCDMP2APCURRENCYEXP310;

	typedef struct _tt_wfs_cdm_mix_type_310 : public XFS310::_wfs_cdm_mix_type
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_mix_type_310)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_mix_type_310)
		void WFS2TT(const XFS310::_wfs_cdm_mix_type* obj)
		{
			this->usMixNumber						= obj->usMixNumber;
			this->usMixType							= obj->usMixType;
			this->usSubType							= obj->usSubType;

			lpszName.assign(obj->lpszName, DeviceUtility::Size_LPSTR(obj->lpszName));
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_mix_type_310& obj)
		{
			out << " usMixNumber: "					<< obj.usMixNumber
				<< " usMixType: "					<< obj.usMixType
				<< " usSubType: "					<< obj.usSubType
				<< " lpszName: "					<< obj.lpszName.c_str();
			return out;
		}
		std::string lpszName;
	} TTWFSCDMMIXTYPE310, * LPTTWFSCDMMIXTYPE310;

	typedef struct _tt_wfs_cdm_p2ap_mix_type_310
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_p2ap_mix_type_310)
		~_tt_wfs_cdm_p2ap_mix_type_310() { SAFERELEASECONT(listMixType) }
		void WFS2TT(const XFS310::_wfs_cdm_mix_type* obj)
		{
			DeviceUtility::CopyP2NAPs(this->listMixType, (XFS310::_wfs_cdm_mix_type**)obj);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_p2ap_mix_type_310& obj)
		{
			out << DeviceUtility::TTCONT2Str(obj.listMixType).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMMIXTYPE310>listMixType;
	} TTWFSCDMP2APMIXTYPE310, * LPTTWFSCDMP2APMIXTYPE310;

	typedef struct _tt_wfs_cdm_mix_row_310 : public XFS310::_wfs_cdm_mix_row
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_mix_row_310)
		~_tt_wfs_cdm_mix_row_310() { SAFERELEASE(&this->lpWFSCDMMIXROW) }
		void WFS2TT(const XFS310::_wfs_cdm_mix_row* obj)
		{
			this->ulAmount							= obj->ulAmount;
			this->lpusMixture						= obj->lpusMixture;
		}
		void WFS(XFS310::LPWFSCDMMIXROW* lppWFSCDMMIXROW)
		{
			this->lpWFSCDMMIXROW = new XFS310::WFSCDMMIXROW;
			this->lpWFSCDMMIXROW->ulAmount			= this->ulAmount;
			this->lpWFSCDMMIXROW->lpusMixture		= this->lpusMixture;
			*lppWFSCDMMIXROW = this->lpWFSCDMMIXROW;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_mix_row_310& obj)
		{
			out << " - "
				<< " ulAmount: "					<< obj.ulAmount
				<< " lpusMixture: "					<< obj.lpusMixture;
			return out;
		}
		XFS310::LPWFSCDMMIXROW lpWFSCDMMIXROW = nullptr;
	} TTWFSCDMMIXROW310, * LPTTWFSCDMMIXROW310;

	typedef struct _tt_wfs_cdm_mix_table_310 : public XFS310::_wfs_cdm_mix_table
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_mix_table_310)
		~_tt_wfs_cdm_mix_table_310()
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
		void WFS2TT(const XFS310::_wfs_cdm_mix_table* obj)
		{
			this->usMixNumber						= obj->usMixNumber;
			this->lpszName.assign(obj->lpszName, DeviceUtility::Size_LPSTR(obj->lpszName));
			this->usRows							= obj->usRows;
			this->usCols							= obj->usCols;
			SAFEALLOCCOPYMEMORY(&this->lpulMixHeader, obj->lpulMixHeader, sizeof(ULONG) * obj->usCols);
			DeviceUtility::CopyP2APs(this->lppMixRows, obj->lppMixRows, obj->usRows);
		}
		void WFS(XFS310::LPWFSCDMMIXTABLE* lppWFSCDMMIXTABLE)
		{
			this->lpWFSCDMMIXTABLE = new XFS310::WFSCDMMIXTABLE;
			this->lpWFSCDMMIXTABLE->usMixNumber		= this->usMixNumber;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMMIXTABLE->lpszName, this->lpszName);
			this->lpWFSCDMMIXTABLE->usRows			= this->usRows;
			this->lpWFSCDMMIXTABLE->usCols			= this->usCols;
			SAFEALLOCCOPYMEMORY(&this->lpWFSCDMMIXTABLE->lpulMixHeader, this->lpulMixHeader, sizeof(ULONG) * this->usCols);
			DeviceUtility::CopyP2APs_r(this->lpWFSCDMMIXTABLE->lppMixRows, this->lppMixRows);
			*lppWFSCDMMIXTABLE = this->lpWFSCDMMIXTABLE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_mix_table_310& obj)
		{
			out << " usMixNumber: "					<< obj.usMixNumber
				<< " lpszName: "					<< obj.lpszName.c_str()
				<< " usRows: "						<< obj.usRows
				<< " usCols: "						<< obj.usCols
				<< " lpulMixHeader: "				<< TTFRMU::Array2Str(obj.lpulMixHeader, obj.usCols)
				<< " lppMixRows: "					<< DeviceUtility::TTCONT2Str(obj.lppMixRows).c_str();
			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMMIXROW310> lppMixRows;
		std::string lpszName;
		XFS310::LPWFSCDMMIXTABLE lpWFSCDMMIXTABLE = nullptr;
	} TTWFSCDMMIXTABLE310, * LPTTWFSCDMMIXTABLE310;

	typedef struct _tt_wfs_cdm_denomination_310 : public XFS310::_wfs_cdm_denomination
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_denomination_310)
		~_tt_wfs_cdm_denomination_310()
		{
			TRACELOG("~_tt_wfs_cdm_denomination - Started");
			SAFEPTR(this->lpWFSCDMDENOMINATION)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMDENOMINATION->lpulValues);
				SAFERELEASE(&this->lpWFSCDMDENOMINATION);
			}
			TRACELOG("~_tt_wfs_cdm_denomination - Ended");
		}
		void WFS2TT(const XFS310::_wfs_cdm_denomination* obj)
		{
			this->cCurrencyID.assign(obj->cCurrencyID, 3);
			this->ulAmount							= obj->ulAmount;
			this->usCount							= obj->usCount;
			SAFEALLOCCOPYMEMORY(&this->lpulValues, obj->lpulValues, obj->usCount * sizeof(ULONG));
			this->ulCashBox = obj->ulCashBox;
		}
		void WFS(XFS310::LPWFSCDMDENOMINATION* lppWFSCDMDENOMINATION)
		{
			this->lpWFSCDMDENOMINATION = new XFS310::WFSCDMDENOMINATION;
			SAFECOPYSTRING(this->lpWFSCDMDENOMINATION->cCurrencyID, this->cCurrencyID.c_str());
			this->lpWFSCDMDENOMINATION->ulAmount	= this->ulAmount;
			this->lpWFSCDMDENOMINATION->usCount		= this->usCount;
			SAFEALLOCCOPYMEMORY(&this->lpWFSCDMDENOMINATION->lpulValues, this->lpulValues, this->usCount * sizeof(ULONG));
			this->lpWFSCDMDENOMINATION->ulCashBox	= this->ulCashBox;
			*lppWFSCDMDENOMINATION = this->lpWFSCDMDENOMINATION;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_denomination_310& obj)
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
		XFS310::LPWFSCDMDENOMINATION lpWFSCDMDENOMINATION = nullptr;
	} TTWFSCDMDENOMINATION310, * LPTTWFSCDMDENOMINATION310;

	typedef struct _tt_wfs_cdm_present_status_310 : public XFS310::_wfs_cdm_present_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_present_status_310)
		~_tt_wfs_cdm_present_status_310() { SAFERELEASE(&this->lpDenomination); }
		void WFS2TT(const XFS310::_wfs_cdm_present_status* obj)
		{
			DeviceUtility::CopyP(&this->lpDenomination, obj->lpDenomination);
			this->wPresentState = obj->wPresentState;

			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_present_status_310& obj)
		{
			out << " wPresentState: "				<< obj.wPresentState
				<< " lpDenomination: "				<< *(obj.lpDenomination)
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		LPTTWFSCDMDENOMINATION310	lpDenomination = nullptr;
		DeviceUtility::STRVECT		lpszExtra;
	} TTWFSCDMPRESENTSTATUS310, * LPTTWFSCDMPRESENTSTATUS310;

	/*=================================================================*/
	/* CDM Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cdm_denominate_310 : public XFS310::_wfs_cdm_denominate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_denominate_310)
		~_tt_wfs_cdm_denominate_310()
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
		void WFS2TT(const XFS310::_wfs_cdm_denominate* obj)
		{
			this->usTellerID						= obj->usTellerID;
			this->usMixNumber						= obj->usMixNumber;
			DeviceUtility::CopyP(&this->lpDenomination, obj->lpDenomination);
		}
		void WFS(XFS310::LPWFSCDMDENOMINATE* lppWFSCDMDENOMINATE)
		{
			this->lpWFSCDMDENOMINATE = new XFS310::WFSCDMDENOMINATE;
			this->lpWFSCDMDENOMINATE->usTellerID	= this->usTellerID;
			this->lpWFSCDMDENOMINATE->usMixNumber	= this->usMixNumber;
			DeviceUtility::CopyP_r(&this->lpWFSCDMDENOMINATE->lpDenomination, this->lpDenomination);
			*lppWFSCDMDENOMINATE = this->lpWFSCDMDENOMINATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_denominate_310& obj)
		{
			out	<< " usTeller: "					<< obj.usTellerID
				<< " usMixNumber: "					<< obj.usMixNumber
				<< " lpDenomination: "; 
			SAFEPTR(obj.lpDenomination) 
				out	<< *obj.lpDenomination;
			return out;
		}
		LPTTWFSCDMDENOMINATION310 lpDenomination = nullptr;
		XFS310::LPWFSCDMDENOMINATE lpWFSCDMDENOMINATE = nullptr;
	} TTWFSCDMDENOMINATE310, * LPTTWFSCDMDENOMINATE310;

	typedef struct _tt_wfs_cdm_dispense_310 : public XFS310::_wfs_cdm_dispense
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_dispense_310)
		~_tt_wfs_cdm_dispense_310()
		{
			SAFERELEASE(&this->lpDenomination);
			SAFEPTR(this->lpTTWFSCDMDISPENSE)
			{
				SAFERELEASE(&this->lpTTWFSCDMDISPENSE->lpDenomination);
				SAFERELEASE(&this->lpTTWFSCDMDISPENSE);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_dispense* obj)
		{
			this->usTellerID						= obj->usTellerID;
			this->usMixNumber						= obj->usMixNumber;
			this->fwPosition						= obj->fwPosition;
			this->bPresent							= obj->bPresent;
			DeviceUtility::CopyP(&this->lpDenomination, obj->lpDenomination);
		}
		void WFS(XFS310::LPWFSCDMDISPENSE* lppWFSCDMDISPENSE)
		{
			this->lpTTWFSCDMDISPENSE = new XFS310::WFSCDMDISPENSE;
			this->lpTTWFSCDMDISPENSE->usTellerID	= this->usTellerID;
			this->lpTTWFSCDMDISPENSE->usMixNumber	= this->usMixNumber;
			this->lpTTWFSCDMDISPENSE->fwPosition	= this->fwPosition;
			this->lpTTWFSCDMDISPENSE->bPresent		= this->bPresent;
			DeviceUtility::CopyP_r(&this->lpTTWFSCDMDISPENSE->lpDenomination, this->lpDenomination);
			*lppWFSCDMDISPENSE = this->lpTTWFSCDMDISPENSE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_dispense_310& obj)
		{
			out << " usTellerID: "					<< obj.usTellerID
				<< " usMixNumber: "					<< obj.usMixNumber
				<< " fwPosition : "					<< obj.fwPosition
				<< " bPresent: "					<< std::boolalpha << obj.bPresent
				<< " lpDenomination: "				<< *obj.lpDenomination;
			return out;
		}
		LPTTWFSCDMDENOMINATION310  lpDenomination = nullptr;
		XFS310::LPWFSCDMDISPENSE lpTTWFSCDMDISPENSE = nullptr;
	} TTWFSCDMDISPENSE310, * LPTTWFSCDMDISPENSE310;

	typedef struct _tt_wfs_cdm_physical_cu_310 : public XFS310::_wfs_cdm_physical_cu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_physical_cu_310)
		~_tt_wfs_cdm_physical_cu_310()
		{
			SAFEPTR(this->lpWFSCDMPHYSICALCU)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMPHYSICALCU->lpPhysicalPositionName);
				SAFERELEASE(&this->lpWFSCDMPHYSICALCU);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_physical_cu* obj)
		{
			this->bEmptyAll							= obj->bEmptyAll;
			this->fwPosition						= obj->fwPosition;
			SAFEPTR(obj->lpPhysicalPositionName)
				this->lpPhysicalPositionName.assign(obj->lpPhysicalPositionName);
		}
		void WFS(XFS310::LPWFSCDMPHYSICALCU* lppWFSCDMPHYSICALCU)
		{
			this->lpWFSCDMPHYSICALCU = new XFS310::WFSCDMPHYSICALCU;
			this->lpWFSCDMPHYSICALCU->bEmptyAll		= this->bEmptyAll;
			this->lpWFSCDMPHYSICALCU->fwPosition	= this->fwPosition;
			SAFEALLOCCOPYSTRING(&this->lpWFSCDMPHYSICALCU->lpPhysicalPositionName, this->lpPhysicalPositionName);
			*lppWFSCDMPHYSICALCU = this->lpWFSCDMPHYSICALCU;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_physical_cu_310& obj)
		{
			out << " bEmptyAll: "					<< std::boolalpha << (bool)obj.bEmptyAll
				<< " fwPosition: "					<< obj.fwPosition
				<< " lpDenomination: "				<< obj.lpPhysicalPositionName;
			return out;
		}
		std::string lpPhysicalPositionName{};
		XFS310::LPWFSCDMPHYSICALCU lpWFSCDMPHYSICALCU = nullptr;
	} TTWFSCDMPHYSICALCU310, * LPTTWFSCDMPHYSICALCU310;

	typedef struct _tt_wfs_cdm_counted_phys_cu_310 : public XFS310::_wfs_cdm_counted_phys_cu
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_counted_phys_cu_310)
		DEFAULTDESTRUCTOR(_tt_wfs_cdm_counted_phys_cu_310)
		void WFS2TT(const XFS310::_wfs_cdm_counted_phys_cu* obj)
		{
			this->lpPhysicalPositionName.assign(obj->lpPhysicalPositionName, DeviceUtility::Size_LPSTR(obj->lpPhysicalPositionName));
			this->cUnitId.assign(obj->cUnitId, 5);
			this->ulDispensed						= obj->ulDispensed;
			this->ulCounted							= obj->ulCounted;
			this->usPStatus							= obj->usPStatus;
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_counted_phys_cu_310& obj)
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
	} TTWFSCDMCOUNTEDPHYSCU310, * LPTTWFSCDMCOUNTEDPHYSCU310;

	typedef struct _tt_wfs_cdm_count_310 : public XFS310::_wfs_cdm_count
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_count_310)
		~_tt_wfs_cdm_count_310() { SAFERELEASECONT(lppCountedPhysCUs) }
		void WFS2TT(const XFS310::_wfs_cdm_count* obj)
		{
			this->usNumPhysicalCUs = obj->usNumPhysicalCUs;

			DeviceUtility::CopyP2APs(this->lppCountedPhysCUs, obj->lppCountedPhysCUs, obj->usNumPhysicalCUs);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_count_310& obj)
		{
			out << " usNumPhysicalCUs: "			<< obj.usNumPhysicalCUs
				<< " lppCountedPhysCUs: "			<< DeviceUtility::TTCONT2Str(obj.lppCountedPhysCUs).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSCDMCOUNTEDPHYSCU310>lppCountedPhysCUs;
	} TTWFSCDMCOUNT310, * LPTTWFSCDMCOUNT310;

	typedef struct _tt_wfs_cdm_retract_310 : public XFS310::_wfs_cdm_retract
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_retract_310)
		~_tt_wfs_cdm_retract_310() { SAFERELEASE(&this->lpWFSCDMRETRACT) }
		void WFS2TT(const XFS310::_wfs_cdm_retract* obj)
		{
			this->fwOutputPosition = obj->fwOutputPosition;
			this->usRetractArea = obj->usRetractArea;
			this->usIndex = obj->usIndex;
		}
		void WFS(XFS310::LPWFSCDMRETRACT* lppWFSCDMRETRACT)
		{
			this->lpWFSCDMRETRACT = new XFS310::WFSCDMRETRACT;
			this->lpWFSCDMRETRACT->fwOutputPosition = this->fwOutputPosition;
			this->lpWFSCDMRETRACT->usRetractArea	= this->usRetractArea;
			this->lpWFSCDMRETRACT->usIndex			= this->usIndex;
			*lppWFSCDMRETRACT = this->lpWFSCDMRETRACT;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_retract_310& obj)
		{
			out << " fwOutputPosition: "			<< obj.fwOutputPosition
				<< " usRetractArea: "				<< obj.usRetractArea
				<< " usIndex: "						<< obj.usIndex;
			return out;
		}
		XFS310::LPWFSCDMRETRACT lpWFSCDMRETRACT = nullptr;
	} TTWFSCDMRETRACT310, * LPTTWFSCDMRETRACT310;

	typedef struct _tt_wfs_cdm_teller_update_310 : public XFS310::_wfs_cdm_teller_update
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_teller_update_310)
		~_tt_wfs_cdm_teller_update_310()
		{
			SAFERELEASE(&this->lpTellerDetails);
			SAFEPTR(this->lpWFSCDMTELLERUPDATE)
			{
				SAFERELEASE(&this->lpWFSCDMTELLERUPDATE->lpTellerDetails);
				SAFERELEASE(&this->lpWFSCDMTELLERUPDATE);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_teller_update* obj)
		{
			this->usAction							= obj->usAction;
			SAFEPTR(obj->lpTellerDetails)
				::DeviceUtility::CopyP(&this->lpTellerDetails, obj->lpTellerDetails);
		}
		void WFS(XFS310::LPWFSCDMTELLERUPDATE* lppWFSCDMTELLERUPDATE)
		{
			this->lpWFSCDMTELLERUPDATE = new XFS310::WFSCDMTELLERUPDATE;
			this->lpWFSCDMTELLERUPDATE->usAction	= this->usAction;
			::DeviceUtility::CopyP_r(&this->lpWFSCDMTELLERUPDATE->lpTellerDetails, this->lpTellerDetails);
			*lppWFSCDMTELLERUPDATE = this->lpWFSCDMTELLERUPDATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_teller_update_310& obj)
		{
			out << " usAction: "					<< obj.usAction;
			SAFEPTR(obj.lpTellerDetails)
				out << " lpTellerDetails: "			<< *obj.lpTellerDetails;
			return out;
		}
		LPTTWFSCDMTELLERDETAILS310 lpTellerDetails;
		XFS310::LPWFSCDMTELLERUPDATE lpWFSCDMTELLERUPDATE = nullptr;
	} TTWFSCDMTELLERUPDATE310, * LPTTWFSCDMTELLERUPDATE310;

	typedef struct _tt_wfs_cdm_start_ex_310 : public XFS310::_wfs_cdm_start_ex
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_start_ex_310)
		~_tt_wfs_cdm_start_ex_310()
		{
			SAFEFREEMEMORY(&this->lpusCUNumList);
			SAFEPTR(this->lpWFSCDMSTARTEX)
			{
				SAFEFREEMEMORY(&this->lpWFSCDMSTARTEX->lpusCUNumList);
				SAFERELEASE(&this->lpWFSCDMSTARTEX);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_start_ex* obj)
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
		void WFS(XFS310::LPWFSCDMSTARTEX* lppWFSCDMSTARTEX)
		{
			this->lpWFSCDMSTARTEX = new XFS310::WFSCDMSTARTEX;
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
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_start_ex_310& obj)
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
		XFS310::LPWFSCDMSTARTEX lpWFSCDMSTARTEX = nullptr;
	} TTWFSCDMSTARTEX310, * LPTTWFSCDMSTARTEX310;

	typedef struct _tt_wfs_cdm_itemposition_310 : public XFS310::_wfs_cdm_itemposition
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_itemposition_310)
		~_tt_wfs_cdm_itemposition_310()
		{
			SAFERELEASE(&this->lpRetractArea);
			SAFEPTR(this->lpWFSCDMITEMPOSITION)
			{
				SAFERELEASE(&this->lpWFSCDMITEMPOSITION->lpRetractArea);
				SAFERELEASE(&this->lpWFSCDMITEMPOSITION);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_itemposition* obj)
		{
			this->usNumber = obj->usNumber;
			DeviceUtility::CopyP(&this->lpRetractArea, obj->lpRetractArea);
			this->fwOutputPosition = obj->fwOutputPosition;
		}
		void WFS(XFS310::LPWFSCDMITEMPOSITION* lppWFSCDMITEMPOSITION)
		{
			this->lpWFSCDMITEMPOSITION = new XFS310::WFSCDMITEMPOSITION;
			this->lpWFSCDMITEMPOSITION->usNumber = this->usNumber;
			this->lpWFSCDMITEMPOSITION->fwOutputPosition = this->fwOutputPosition;
			DeviceUtility::CopyP_r(&this->lpWFSCDMITEMPOSITION->lpRetractArea, this->lpRetractArea);
			*lppWFSCDMITEMPOSITION = this->lpWFSCDMITEMPOSITION;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_itemposition_310& obj)
		{
			out << " usNumber: "					<< obj.usNumber
				<< " lpRetractArea: ";
			SAFEPTR(obj.lpRetractArea)
				out << *obj.lpRetractArea;
			out << " fwOutputPosition: "			<< obj.fwOutputPosition;
			return out;
		}
		LPTTWFSCDMRETRACT310 lpRetractArea = nullptr;
		XFS310::LPWFSCDMITEMPOSITION lpWFSCDMITEMPOSITION = nullptr;
	} TTWFSCDMITEMPOSITION310, * LPTTWFSCDMITEMPOSITION310;

	typedef struct _tt_wfs_cdm_calibrate_310 : public XFS310::_wfs_cdm_calibrate
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_calibrate_310)
		~_tt_wfs_cdm_calibrate_310()
		{
			SAFERELEASE(this->lppPosition);
			SAFEPTR(this->lpWFSCDMCALIBRATE) 
			{
				SAFERELEASE(&this->lpWFSCDMCALIBRATE->lppPosition);
				SAFERELEASE(&this->lpWFSCDMCALIBRATE);
			}
		}
		void WFS2TT(const XFS310::_wfs_cdm_calibrate* obj)
		{
			this->usNumber							= obj->usNumber;
			this->usNumOfBills						= obj->usNumOfBills;
			DeviceUtility::CopyP(this->lppPosition, *obj->lppPosition);
		}
		void WFS(XFS310::LPWFSCDMCALIBRATE* lppWFSCDMCALIBRATE)
		{
			this->lpWFSCDMCALIBRATE = new XFS310::WFSCDMCALIBRATE;
			this->lpWFSCDMCALIBRATE->usNumber		= this->usNumber;
			this->lpWFSCDMCALIBRATE->usNumOfBills	= this->usNumOfBills;
			DeviceUtility::CopyP_r(this->lpWFSCDMCALIBRATE->lppPosition, *this->lppPosition);
			*lppWFSCDMCALIBRATE = this->lpWFSCDMCALIBRATE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_calibrate_310& obj)
		{
			out << " usNumber: "					<< obj.usNumber
				<< " usNumOfBills: "				<< obj.usNumOfBills
				<< " lpPosition: "					<< *(obj.lppPosition);
			return out;
		}
		LPTTWFSCDMITEMPOSITION310* lppPosition = nullptr;
		XFS310::LPWFSCDMCALIBRATE lpWFSCDMCALIBRATE = nullptr;
	} TTWFSCDMCALIBRATE310, * LPTTWFSCDMCALIBRATE310;

	/*=================================================================*/
	/* CDM Message Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cdm_cu_error_310 : public XFS310::_wfs_cdm_cu_error
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_cu_error_310)
		~_tt_wfs_cdm_cu_error_310() { SAFERELEASE(&this->lpCashUnit) }
		void WFS2TT(const XFS310::_wfs_cdm_cu_error* obj)
		{
			this->wFailure							= obj->wFailure;
			DeviceUtility::CopyP(&this->lpCashUnit, obj->lpCashUnit);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_cu_error_310& obj)
		{
			out << " wFailure: "					<< obj.wFailure
				<< " lpCashUnit: "					<< *obj.lpCashUnit;
			return out;
		}
		LPTTWFSCDMCASHUNIT310 lpCashUnit;
	} TTWFSCDMCUERROR310, * LPTTWFSCDMCUERROR310;

	typedef struct _tt_wfs_cdm_counts_changed_310 : public XFS310::_wfs_cdm_counts_changed
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cdm_counts_changed_310)
		~_tt_wfs_cdm_counts_changed_310() { SAFEFREEMEMORY(&this->lpusCUNumList) }
		void WFS2TT(const XFS310::_wfs_cdm_counts_changed* obj)
		{
			this->usCount							= obj->usCount;
			this->lpusCUNumList = (USHORT*)::malloc(sizeof(USHORT) * obj->usCount);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_cdm_counts_changed_310& obj)
		{
			out << " usCount: " << obj.usCount
				<< " lpusCUNumList: ";
			for (size_t i = 0; i < obj.usCount; ++i)
				out << obj.lpusCUNumList[i];
			return out;
		}
	} TTWFSCDMCOUNTSCHANGED310, * LPTTWFSCDMCOUNTSCHANGED310;

#pragma pack(pop)

	/*=================================================================*/
	/* ICDM Interface */
	/*=================================================================*/

	class ITTCDM310 : public ITTDevice
	{

	public:
		ITTCDM310() = default;
		ITTCDM310(const ITTCDM310&) = delete;
		ITTCDM310(ITTCDM310&&) = delete;
		ITTCDM310& operator = (const ITTCDM310&) = delete;
		ITTCDM310& operator = (ITTCDM310&&) = delete;
		virtual ~ITTCDM310() = default;

		/* CDM Info Commands */
		virtual bool GetStatus(LPTTWFSCDMSTATUS310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSCDMCAPS310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCashUnitInfo(LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetTellerInfo(LPTTWFSCDMTELLERINFO310, LPTTWFSCDMTELLERDETAILS310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCurrencyExp(LPTTWFSCDMP2APCURRENCYEXP310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetMixTypes(LPTTWFSCDMP2APMIXTYPE310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetMixTable(LPUSHORT, LPTTWFSCDMMIXTABLE310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetPresentStatus(LPWORD, LPTTWFSCDMPRESENTSTATUS310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCashUnitInfo(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetTellerInfo(LPTTWFSCDMTELLERINFO310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCurrencyExp(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetMixTypes(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetMixTable(LPUSHORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetPresentStatus(LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* CDM Execute Commands */
		virtual bool Denominate(const LPTTWFSCDMDENOMINATE310, LPTTWFSCDMDENOMINATION310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Dispense(const LPTTWFSCDMDISPENSE310, LPTTWFSCDMDENOMINATION310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Count(const LPTTWFSCDMPHYSICALCU310, LPTTWFSCDMCOUNT310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Present(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reject(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Retract(const LPTTWFSCDMRETRACT310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool OpenShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CloseShutter(const LPWORD, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetTelleInfo(const LPTTWFSCDMTELLERUPDATE310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetCashUnitInfo(const LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool StartExchange(const LPTTWFSCDMSTARTEX310, LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool EndExchange(const LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool OpenSafeDoor(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool CalibirateCashUnit(const LPTTWFSCDMCALIBRATE310, LPTTWFSCDMCALIBRATE310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool SetMixTable(const LPTTWFSCDMMIXTABLE310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const LPTTWFSCDMITEMPOSITION310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool TestCashUnits(const LPTTWFSCDMITEMPOSITION310, LPTTWFSCDMCUINFO310, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncDenominate(const LPTTWFSCDMDENOMINATE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDispense(const LPTTWFSCDMDISPENSE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCount(const LPTTWFSCDMPHYSICALCU310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncPresent(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReject(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRetract(const LPTTWFSCDMRETRACT310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncOpenShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCloseShutter(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetTelleInfo(const LPTTWFSCDMTELLERUPDATE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetCashUnitInfo(const LPTTWFSCDMCUINFO310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncStartExchange(const LPTTWFSCDMSTARTEX310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncEndExchange(const LPTTWFSCDMCUINFO310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncOpenSafeDoor(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncCalibirateCashUnit(const LPTTWFSCDMCALIBRATE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncSetMixTable(const LPTTWFSCDMMIXTABLE310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(const LPTTWFSCDMITEMPOSITION310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncTestCashUnits(const LPTTWFSCDMITEMPOSITION310, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTCDM_310__