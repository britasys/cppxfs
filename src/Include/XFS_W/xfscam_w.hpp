#pragma once

#ifndef __H_XFSCAM_W__
#define __H_XFSCAM_W__

#include <xfscam.h>

#include <sstream>
#include <ostream>
#include <string>

#include <DeviceUtility.h>

namespace __N_XFSCAM_W__
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* CAM Info Command Structures */
	/*=================================================================*/

	typedef struct _wfs_cam_status_w : public _wfs_cam_status
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cam_status)
		DEFAULTDESTRUCTOR(_tt_wfs_cam_status)
		void WFS2TT(const XFS300::_wfs_cam_status* obj)
		{
			this->fwDevice						= obj->fwDevice;
			SAFECOPYMEMORY(this->fwMedia, obj->fwMedia, WFS_CAM_CAMERAS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwCameras, obj->fwCameras, WFS_CAM_CAMERAS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->usPictures, obj->usPictures, WFS_CAM_CAMERAS_SIZE * sizeof(USHORT));
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
		friend std::ostream& operator<< (std::ostream& out, const _tt_wfs_cam_status& obj)
		{
			out << " fwDevice: "				<< obj.fwDevice
				<< " fwMedia: "					<< TTFRMU::Array2Str(obj.fwMedia, WFS_CAM_CAMERAS_SIZE)
				<< " fwCameras: "				<< TTFRMU::Array2Str(obj.fwCameras, WFS_CAM_CAMERAS_SIZE)
				<< " usPictures: "				<< TTFRMU::Array2Str(obj.usPictures, WFS_CAM_CAMERAS_SIZE)
				<< " lpszExtra: "				<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSCAMSTATUS, * LPTTWFSCAMSTATUS;

	typedef struct _tt_wfs_cam_caps : public XFS300::_wfs_cam_caps
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cam_caps)
		DEFAULTDESTRUCTOR(_tt_wfs_cam_caps)
		void WFS2TT(const XFS300::_wfs_cam_caps* obj)
		{
			this->wClass						= obj->wClass;
			this->fwType						= obj->fwType;
			SAFECOPYMEMORY(this->fwCameras, obj->fwCameras, WFS_CAM_CAMERAS_SIZE * sizeof(WORD));
			this->usMaxPictures					= obj->usMaxPictures;
			this->fwCamData						= obj->fwCamData;
			this->usMaxDataLength				= obj->usMaxDataLength;
			this->fwCharSupport					= obj->fwCharSupport;
			DeviceUtility::LPSTRNN2Vector(this->lpszExtra, obj->lpszExtra);
		}
			friend std::ostream& operator<< (std::ostream& out, const _tt_wfs_cam_caps& obj)
		{
			out << " wClass: "					<< obj.wClass
				<< " fwType: "					<< obj.fwType
				<< " fwCameras: "				<< TTFRMU::Array2Str(obj.fwCameras, WFS_CAM_CAMERAS_SIZE)
				<< " usMaxPictures: "			<< obj.usMaxPictures
				<< " fwCamData: "				<< obj.fwCamData
				<< " usMaxDataLength: " 		<< obj.usMaxDataLength
				<< " fwCharSupport: "			<< obj.fwCharSupport
				<< " lpszExtra: "				<< DeviceUtility::STRVECT2Str(obj.lpszExtra).c_str();

			return out;
		}
		DeviceUtility::STRVECT lpszExtra;
	} TTWFSCAMCAPS, * LPTTWFSCAMCAPS;

	/*=================================================================*/
	/* CAM Execute Command Structures */
	/*=================================================================*/

	typedef struct _tt_wfs_cam_take_picture : public XFS300::_wfs_cam_take_picture
	{
		DEFAULTCONSTRUCTOR(_tt_wfs_cam_take_picture)
		~_tt_wfs_cam_take_picture() 
		{
			SAFEPTR(this->lpWFSCAMTAKEPICT)
			{
				SAFEFREEMEMORY(&this->lpWFSCAMTAKEPICT->lpszCamData)
				SAFEFREEMEMORY(&this->lpWFSCAMTAKEPICT->lpszUNICODECamData)
				SAFERELEASE(&this->lpWFSCAMTAKEPICT)
			}
		}
		void WFS2TT(const XFS300::_wfs_cam_take_picture* obj)
		{
			this->wCamera = obj->wCamera;
			SAFEPTR(obj->lpszCamData)
				this->lpszCamData.assign(obj->lpszCamData);
			SAFEPTR(obj->lpszUNICODECamData)
				this->lpszUNICODECamData.assign(obj->lpszUNICODECamData);
		}
		void WFS(XFS300::LPWFSCAMTAKEPICT* lppWFSCAMTAKEPICT)
		{
			this->lpWFSCAMTAKEPICT = new XFS300::WFSCAMTAKEPICT;
			this->lpWFSCAMTAKEPICT->wCamera		= this->wCamera;
			SAFEALLOCCOPYSTRING(&this->lpWFSCAMTAKEPICT->lpszCamData, std::string{ this->lpszCamData });
			SAFEALLOCCOPYSTRING(&this->lpWFSCAMTAKEPICT->lpszUNICODECamData, std::wstring{ this->lpszUNICODECamData });
			*lppWFSCAMTAKEPICT = this->lpWFSCAMTAKEPICT;
		}
		friend std::ostream& operator<< (std::ostream& out, const _tt_wfs_cam_take_picture& obj)
		{
			out << " wCamera: "					<< obj.wCamera
				<< " lpszCamData: "				<< obj.lpszCamData.c_str()
				<< " lpszUNICODECamData: "		<< obj.lpszUNICODECamData.c_str();
			return out;
		}
		std::string lpszCamData{};
		std::wstring lpszUNICODECamData{};
		XFS300::LPWFSCAMTAKEPICT lpWFSCAMTAKEPICT = nullptr;
	} TTWFSCAMTAKEPICT, * LPTTWFSCAMTAKEPICT;

#pragma pack(pop)
}

#endif // !__H_ITTCAM_H