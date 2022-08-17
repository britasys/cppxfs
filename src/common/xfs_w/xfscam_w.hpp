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
        // init
        void init(const _wfs_cam_status& obj) noexcept
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
            this->init(*l_lpBuffer);
        }

        // default constructor
        _wfs_cam_status_w() = default;

        // copy constructor
        _wfs_cam_status_w(const _wfs_cam_status_w& obj) noexcept(false) { this->init(obj); }

        // move constructor
        _wfs_cam_status_w(_wfs_cam_status_w&& obj) noexcept(false) : _wfs_cam_status_w{ obj } {}

        // copy assignment
        _wfs_cam_status_w& operator = (const _wfs_cam_status_w& obj) noexcept(false)
        {
            this->init(obj);
            return *this;
        }

        // move assignment
        _wfs_cam_status_w& operator = (_wfs_cam_status_w&& obj) noexcept(false)
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_cam_status_w()
        {
            SAFEFREEMEMORY(&this->lpszExtra);
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

	typedef struct _wfs_cam_caps_w : public _wfs_cam_caps
	{
        // init
        void init(const _wfs_cam_caps& obj) noexcept
        {
			this->wClass						= obj.wClass;
			this->fwType						= obj.fwType;
			SAFECOPYMEMORY(this->fwCameras, obj.fwCameras, WFS_CAM_CAMERAS_SIZE * sizeof(WORD));
			this->usMaxPictures					= obj.usMaxPictures;
			this->fwCamData						= obj.fwCamData;
			this->usMaxDataLength				= obj.usMaxDataLength;
			this->fwCharSupport					= obj.fwCharSupport;
            SAFEALLOCCOPYSTRING(&this->lpszExtra, __N_XFS_W__::WFSLPSZEXTRA_W{ obj.lpszExtra }.to_string());
        }

        // default constructor
        _wfs_cam_caps_w() = default;

        // normal constructor
        _wfs_cam_caps_w(LPVOID lpBuffer) noexcept(false)
        {
            if (!lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            auto l_lpBuffer = static_cast<LPWFSCAMCAPS>(lpBuffer);
            this->init(*l_lpBuffer);
        }

        // copy constructor
        _wfs_cam_caps_w(const _wfs_cam_caps_w& obj) noexcept { this->init(obj); }

        // move constructor
        _wfs_cam_caps_w(_wfs_cam_caps_w&& obj) noexcept : _wfs_cam_caps_w{ obj } {}

        // copy assignment
        _wfs_cam_caps_w& operator = (const _wfs_cam_caps_w& obj) noexcept
        {
            this->init(obj);
            return *this;
        }

        // move assignment
        _wfs_cam_caps_w& operator = (_wfs_cam_caps_w&& obj) noexcept
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_cam_caps_w()
        {
            SAFEFREEMEMORY(&this->lpszExtra);
        }

        // << operator
		friend std::ostream& operator<< (std::ostream& out, const _wfs_cam_caps_w& obj)
		{
			out << " wClass: "					<< obj.wClass
				<< " fwType: "					<< obj.fwType
				<< " fwCameras: "				<< __N_UTILITY__::Array2Str(obj.fwCameras, WFS_CAM_CAMERAS_SIZE)
				<< " usMaxPictures: "			<< obj.usMaxPictures
				<< " fwCamData: "				<< obj.fwCamData
				<< " usMaxDataLength: " 		<< obj.usMaxDataLength
				<< " fwCharSupport: "			<< obj.fwCharSupport
				<< " lpszExtra: "				<< __N_XFS_W__::WFSLPSZEXTRA_W{ obj.lpszExtra }.to_string();
			return out;
		}
	} TTWFSCAMCAPS_W, * LPTTWFSCAMCAPS_W;

	/*=================================================================*/
	/* CAM Execute Command Structures */
	/*=================================================================*/

	typedef struct _wfs_cam_take_picture_w : public _wfs_cam_take_picture
	{
        // init
        void init(const _wfs_cam_take_picture& obj) noexcept
        {
			this->wCamera = obj.wCamera;
			if (obj.lpszCamData)
				SAFEALLOCCOPYSTRING(&this->lpszCamData, std::string{ obj.lpszCamData });
			if (obj.lpszUNICODECamData)
				SAFEALLOCCOPYSTRING(&this->lpszUNICODECamData, std::wstring{ obj.lpszUNICODECamData });
        }

        // default constructor
        _wfs_cam_take_picture_w() = default;

        // normal constructor
        _wfs_cam_take_picture_w(LPVOID lpBuffer) noexcept(false)
        {
            if (!lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            auto l_lpBuffer = static_cast<LPWFSCAMTAKEPICT>(lpBuffer);
            this->init(*l_lpBuffer);
        }

        // destructor
		~_wfs_cam_take_picture_w() 
		{
			SAFEFREEMEMORY(&this->lpszCamData)
			SAFEFREEMEMORY(&this->lpszUNICODECamData)
		}
        
        // << operator
		friend std::ostream& operator<< (std::ostream& out, const _wfs_cam_take_picture_w& obj)
		{
			out << " wCamera: "					<< obj.wCamera
				<< " lpszCamData: "				<< std::string{ obj.lpszCamData }
				<< " lpszUNICODECamData: "		<< std::string{ std::wstring{ obj.lpszUNICODECamData }.begin(), std::wstring{ obj.lpszUNICODECamData }.end() };
			return out;
		}
	} TTWFSCAMTAKEPICT, * LPTTWFSCAMTAKEPICT;

#pragma pack(pop)
}

#endif // !__H_ITTCAM_H