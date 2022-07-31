
#pragma once

#ifndef __H_ITTDEP__
#define __H_ITTDEP__

#include <DeviceUtility.h>
#include "../ITTDevice.h"

namespace TTDevice
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* DEP Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_dep_status : public XFS300::_wfs_dep_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_dep_status)
		DEFAULTDESTRUCTOR(_tt_wfs_dep_status)
		void WFS2TT(const XFS300::_wfs_dep_status* obj)
		{
			this->fwDevice = obj->fwDevice;
			this->fwDepContainer = obj->fwDepContainer;
			this->fwDepTransport = obj->fwDepTransport;
			this->fwEnvSupply = obj->fwEnvSupply;
			this->fwEnvDispenser = obj->fwEnvDispenser;
			this->fwPrinter = obj->fwPrinter;
			this->fwToner = obj->fwToner;
			this->fwShutter = obj->fwShutter;
			this->wNumOfDeposits = obj->wNumOfDeposits;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_dep_status& obj)
		{
			out << " fwDevice: " << obj.fwDevice
				<< " fwDepContainer: " << obj.fwDepContainer
				<< " fwDepTransport: " << obj.fwDepTransport
				<< " fwEnvSupply: " << obj.fwEnvSupply
				<< " fwEnvDispenser: " << obj.fwEnvDispenser
				<< " fwPrinter: " << obj.fwPrinter
				<< " fwToner: " << obj.fwToner
				<< " fwShutter: " << obj.fwShutter
				<< " wNumOfDeposits: " << obj.wNumOfDeposits
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSDEPSTATUS, * LPTTWFSDEPSTATUS;

	typedef struct _tt_wfs_dep_caps : public XFS300::_wfs_dep_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_dep_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_dep_caps)
		void WFS2TT(const XFS300::_wfs_dep_caps* obj)
		{
			this->wClass = obj->wClass;
			this->fwType = obj->fwType;
			this->fwEnvSupply = obj->fwEnvSupply;
			this->bDepTransport = obj->bDepTransport;
			this->bPrinter = obj->bPrinter;
			this->bToner = obj->bToner;
			this->bShutter = obj->bShutter;
			this->bPrintOnRetracts = obj->bPrintOnRetracts;
			this->fwRetractEnvelope = obj->fwRetractEnvelope;
			this->wMaxNumChars = obj->wMaxNumChars;
			this->fwCharSupport = obj->fwCharSupport;

			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_dep_caps& obj)
		{
			out << " wClass: " << obj.wClass
				<< " fwType: " << obj.fwType
				<< " fwEnvSupply: " << obj.fwEnvSupply
				<< " bDepTransport: " << obj.bDepTransport
				<< " bPrinter: " << obj.bPrinter
				<< " bToner: " << obj.bToner
				<< " bShutter: " << obj.bShutter
				<< " bPrintOnRetracts: " << obj.bPrintOnRetracts
				<< " fwRetractEnvelope: " << obj.fwRetractEnvelope
				<< " wMaxNumChars: " << obj.wMaxNumChars
				<< " fwCharSupport: " << obj.fwCharSupport
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();
			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSDEPCAPS, * LPTTWFSDEPCAPS;

#pragma pack(pop)
	
	/*====================================================================*/
	/* DEP Execute Command Structures */
	/*====================================================================*/
	typedef struct _tt_wfs_dep_envelope : public XFS300::_wfs_dep_envelope
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_dep_envelope)
		~_tt_wfs_dep_envelope()
		{
			SAFEPTR(this->lpWFSDEPENVELOPE)
			{
				SAFEFREEMEMORY(&this->lpWFSDEPENVELOPE->lpszPrintData);
				SAFEFREEMEMORY(&this->lpWFSDEPENVELOPE->lpszUNICODEPrintData);
				SAFERELEASE(&this->lpWFSDEPENVELOPE);
			}
		}
		void WFS2TT(const XFS300::_wfs_dep_envelope* obj)
		{
			SAFEPTR(obj->lpszPrintData) this->lpszPrintData.assign(obj->lpszPrintData);
			SAFEPTR(obj->lpszUNICODEPrintData) this->lpszUNICODEPrintData.assign(obj->lpszUNICODEPrintData);
		}
		void WFS(XFS300::LPWFSDEPENVELOPE* lppWFSDEPENVELOPE)
		{
			this->lpWFSDEPENVELOPE = new XFS300::WFSDEPENVELOPE;
			SAFEALLOCCOPYSTRING(&this->lpWFSDEPENVELOPE->lpszPrintData, this->lpszPrintData);
			SAFEALLOCCOPYSTRING(&this->lpWFSDEPENVELOPE->lpszUNICODEPrintData, this->lpszUNICODEPrintData);
			*lppWFSDEPENVELOPE = this->lpWFSDEPENVELOPE;
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_dep_envelope& obj)
		{
			std::string _lpszUNICODEPrintData(obj.lpszUNICODEPrintData.begin(), obj.lpszUNICODEPrintData.end());
			out << " wClass: " << obj.lpszPrintData
				<< " fwType: " << _lpszUNICODEPrintData;
			return out;
		}
		std::string lpszPrintData;
		std::wstring lpszUNICODEPrintData;
		XFS300::LPWFSDEPENVELOPE lpWFSDEPENVELOPE = nullptr;
	} TTWFSDEPENVELOPE, * LPTTWFSDEPENVELOPE;

	/*=================================================================*/
	/* DEP Interface */
	/*=================================================================*/

	class ITTDEP : public ITTDevice
	{
	public:
		ITTDEP() = default;
		ITTDEP(const ITTDEP&) = delete;
		ITTDEP(ITTDEP&&) = delete;
		ITTDEP& operator = (const ITTDEP&) = delete;
		ITTDEP& operator = (ITTDEP&&) = delete;
		virtual ~ITTDEP() = default;

		/* DEP Info Functions */
		virtual bool GetStatus(LPTTWFSDEPSTATUS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSDEPCAPS lpOut, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		/* DEP Execute Functions */
		virtual bool Entry(const LPTTWFSDEPENVELOPE lpEnvelope, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Dispense(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Retract(const LPTTWFSDEPENVELOPE lpEnvelope, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ResetCount(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool Reset(const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncEntry(const LPTTWFSDEPENVELOPE lpEnvelope, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncDispense(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncRetract(const LPTTWFSDEPENVELOPE lpEnvelope, REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncResetCount(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncReset(REQUESTID& ReqID, const DWORD Timeout = DEFAULT_TIMEOUT) noexcept = 0;
	};	
}

#endif // !__H_ITTDEP__
