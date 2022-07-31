
#pragma once

#ifndef __H_ITTVDM__
#define __H_ITTVDM__

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
	/* VDM Info Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_vdm_appstatus : public XFS300::_wfs_vdm_appstatus
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_vdm_appstatus)
			void WFS2TT(const XFS300::_wfs_vdm_appstatus* obj)
		{
			this->lpszAppID.assign(obj->lpszAppID);
			this->wAppStatus			= obj->wAppStatus;
		}
		DEFAULTDESTRUCTOR(_tt_wfs_vdm_appstatus)
			friend std::ostream& operator << (std::ostream& out, const _tt_wfs_vdm_appstatus& obj)
		{
			out << " - "
				<< " lpszAppID: "		<< obj.lpszAppID.c_str()
				<< " wAppStatus: "		<< obj.wAppStatus;
			return out;
		}
		std::string lpszAppID;
	} TTWFSVDMAPPSTATUS, * LPTTWFSVDMAPPSTATUS;

	typedef struct _tt_wfs_vdm_status : public XFS300::_wfs_vdm_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_vdm_status)
		~_tt_wfs_vdm_status() { SAFERELEASECONT(this->lppAppStatus); }
		void WFS2TT(const XFS300::_wfs_vdm_status* obj)
		{
			this->wDevice				= obj->wDevice;
			this->wService				= obj->wService;
			DeviceUtility::CopyP2NAPs(this->lppAppStatus, obj->lppAppStatus);
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_vdm_status& obj)
		{
			out << " wDevice: "			<< obj.wDevice
				<< " wService: "		<< obj.wService
				<< " lppAppStatus: "	<< DeviceUtility::TTCONT2Str(obj.lppAppStatus).c_str()
				<< std::endl
				<< " lpszExtra: " << DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::TTCONT<LPTTWFSVDMAPPSTATUS>	lppAppStatus;
		DeviceUtility::STRVECT						lpszExtra;
	} TTWFSVDMSTATUS, * LPTTWFSVDMSTATUS;

	typedef struct _tt_wfs_vdm_caps : public XFS300::_wfs_vdm_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_vdm_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_vdm_caps)
		void WFS2TT(const XFS300::_wfs_vdm_caps* obj)
		{
			this->wClass				= obj->wClass;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator << (std::ostream& out, const _tt_wfs_vdm_caps& obj)
		{
			out << " wClass: "			<< obj.wClass
				<< " lpszExtra: "		<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSVDMCAPS, * LPTTWFSVDMCAPS;

#pragma pack(pop)

	/*=================================================================*/
	/* VDM Interface */
	/*=================================================================*/

	class ITTVDM : public ITTDevice
	{
	public:
		ITTVDM() = default;
		ITTVDM(const ITTVDM&) = delete;
		ITTVDM(ITTVDM&&) = delete;
		ITTVDM& operator = (const ITTVDM&) = delete;
		ITTVDM& operator =(ITTVDM&&) = delete;
		virtual ~ITTVDM() = default;

		/* VDM Info Functions */
		virtual bool GetStatus(LPTTWFSVDMSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool GetCapabilities(LPTTWFSVDMCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		/* VDM Execute Functions */
		virtual bool EnterModeReq(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool EnterModeAck(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ExitModeReq(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool ExitModeAck(const DWORD = DEFAULT_TIMEOUT) noexcept = 0;

		virtual bool AsyncEnterModeReq(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncEnterModeAck(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncExitModeReq(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
		virtual bool AsyncExitModeAck(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept = 0;
	};
}

#endif // !__H_ITTVDM__
