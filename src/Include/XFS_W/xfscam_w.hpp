#pragma once

#ifndef __H_XFSCAM_W__
#define __H_XFSCAM_W__

#include <xfscam.h>

#include <utility.hpp>
#include <xfs_w.hpp>

#include <sstream>
#include <ostream>
#include <string>

namespace __N_XFSCAM_W__
{

#pragma pack(push, 1)

	/*=================================================================*/
	/* CAM Info Command Structures */
	/*=================================================================*/

	typedef struct _wfs_cam_status_w : public _wfs_cam_status
	{
        // clone
        void clone(const _wfs_cam_status& obj) noexcept(false)
        {
			this->fwDevice = obj.fwDevice;
			SAFECOPYMEMORY(this->fwMedia, obj.fwMedia, WFS_CAM_CAMERAS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->fwCameras, obj.fwCameras, WFS_CAM_CAMERAS_SIZE * sizeof(WORD));
			SAFECOPYMEMORY(this->usPictures, obj.usPictures, WFS_CAM_CAMERAS_SIZE * sizeof(USHORT));
            SAFEALLOCCOPYSTRING(&this->lpszExtra, __N_XFS_W__::WFSLPSZEXTRA_W{ obj.lpszExtra }.to_string());
        }

        // normal constructor
        _wfs_cam_status_w(LPVOID lpBuffer) noexcept(false)
        {            
            if (!lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            auto l_lpBuffer = static_cast<LPWFSCAMSTATUS>(lpBuffer);
            this->clone(*l_lpBuffer);
        }

        // default constructor
        _wfs_cam_status_w() = default;

        // copy constructor
        _wfs_cam_status_w(const _wfs_cam_status_w& obj) noexcept(false) { this->clone(obj); }

        // move constructor
        _wfs_cam_status_w(_wfs_cam_status_w&& obj) noexcept(false) : _wfs_cam_status_w{ obj } {}

        // copy assignment
        _wfs_cam_status_w& operator = (const _wfs_cam_status_w& obj) noexcept(false)
        {
            this->clone(obj);
            return *this;
        }

        // move assignment
        _wfs_cam_status_w& operator = (_wfs_cam_status_w&& obj) noexcept(false)
        {
            this->clone(obj);
            return *this;
        }

        // << operator
		friend std::ostream& operator<< (std::ostream& out, const _wfs_cam_status_w& obj)
		{
			out << " fwDevice: "				<< obj.fwDevice
				<< " fwMedia: "					<< __N_UTILITY__::Array2Str(obj.fwMedia, WFS_CAM_CAMERAS_SIZE)
				<< " fwCameras: "				<< __N_UTILITY__::Array2Str(obj.fwCameras, WFS_CAM_CAMERAS_SIZE)
				<< " usPictures: "				<< __N_UTILITY__::Array2Str(obj.usPictures, WFS_CAM_CAMERAS_SIZE)
				<< " lpszExtra: "				<< __N_XFS_W__::WFSLPSZEXTRA_W{ obj.lpszExtra }.to_string();

			return out;
		}
	} WFSCAMSTATUS_W, * LPWFSCAMSTATUS_W;

	typedef struct _tt_wfs_cam_caps : public _wfs_cam_caps
	{
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