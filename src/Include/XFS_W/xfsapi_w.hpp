#pragma once

#ifndef __H_XFSAPI_W__
#define __H_XFSAPI_W__

#include <xfsapi.h>
#include <utility.hpp>
#include <definitions.hpp>

#include <stdexcept>
#include <iostream>

namespace __N_XFSAPI_W__
{

#pragma pack(push, 1)

    /****** Data Structures *************************************************/
    typedef struct _wfs_result_w : public _wfs_result
    {
        void init(const _wfs_result& obj) noexcept
        {
            this->RequestID             = obj.RequestID;
            this->hService              = obj.hService;
            this->tsTimestamp           = obj.tsTimestamp;
            this->hResult               = obj.hResult;
            this->u.dwCommandCode       = obj.u.dwCommandCode;
            this->lpBuffer              = obj.lpBuffer;                   // shallow copy
        }

        // default constructor
        _wfs_result_w() = default;

        // copy constructor
        _wfs_result_w(const _wfs_result_w&) = default;

        // move constructor
        _wfs_result_w(_wfs_result_w&&) = default;

        // copy assignment
        _wfs_result_w& operator = (const _wfs_result_w&) = default;

        // move assignment
        _wfs_result_w& operator = (_wfs_result_w&&) = default;

        // normal constructor
        _wfs_result_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSRESULT l_lpWFSResult   = static_cast<LPWFSRESULT>(lpBuffer);
            this->init(*l_lpWFSResult);
        }

        // destructor
        virtual ~_wfs_result_w() = default;

        // << operator 
        friend std::ostream& operator << (std::ostream& out, const _wfs_result_w& obj)
        {
            out << " RequestID: "       << obj.RequestID
                << " hService: "        << obj.hService
                << " tsTimestamp: "     << obj.tsTimestamp.wHour << ":" <<obj.tsTimestamp.wMinute << ":" << obj.tsTimestamp.wSecond
                << " hResult: "         << obj.hResult
                << " u.dwCommandCode: " << obj.u.dwCommandCode
                << " lpBuffer: "        << obj.lpBuffer;
            return out;
        }
    } WFSRESULT_W, * LPWFSRESULT_W;

    typedef struct _wfsversion_w : public _wfsversion
    {
        // init
        void init(const _wfsversion& obj) noexcept
        {
            this->wVersion              = obj.wVersion;
            this->wLowVersion           = obj.wLowVersion;
            this->wHighVersion          = obj.wHighVersion;
            SAFECOPYMEMORY(this->szDescription, obj.szDescription, WFSDDESCRIPTION_LEN + 1);
            SAFECOPYMEMORY(this->szSystemStatus, obj.szSystemStatus, WFSDSYSSTATUS_LEN + 1);
        }

        // default constructor
        _wfsversion_w() = default;

        // normal constructor
        _wfsversion_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSVERSION l_lpWFSVersion = static_cast<LPWFSVERSION>(lpBuffer);
            _wfsversion_w::init(*l_lpWFSVersion);
        }

        // copy constructor
        _wfsversion_w(const _wfsversion_w& obj) { _wfsversion_w::init(obj); }

        // move constructor
        _wfsversion_w(_wfsversion_w&& obj)  : _wfsversion_w{ obj } {}

        // copy assignment
        _wfsversion_w& operator = (const _wfsversion_w& obj) 
        {
            _wfsversion_w::init(obj);
            return *this;
        }

        // move assignment
        _wfsversion_w& operator = (_wfsversion_w&& obj) 
        {
            _wfsversion_w::init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfsversion_w() = default;

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfsversion_w& obj) noexcept
        {
            out << " wVersion: "        << obj.wVersion
                << " wLowVersion: "     << obj.wLowVersion
                << " wHighVersion: "    << obj.wHighVersion
                << " szDescription: "   << obj.szDescription
                << " szSystemStatus: "  << obj.szSystemStatus;
            return out;
        }
    } WFSVERSION_W, * LPWFSVERSION_W;

    /****** Message Structures **********************************************/
    typedef struct _wfs_devstatus_w : public _wfs_devstatus
    {
        // init
        void init(const _wfs_devstatus& obj) noexcept
        {
            SAFEALLOCCOPYSTRING(&this->lpszPhysicalName, std::string{ obj.lpszPhysicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            this->dwState = obj.dwState;
        }

        // default constructor
        _wfs_devstatus_w() = default;

        // normal constructor
        _wfs_devstatus_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSDEVSTATUS l_lpWFSDevStatus = static_cast<LPWFSDEVSTATUS>(lpBuffer);
            _wfs_devstatus_w::init(*l_lpWFSDevStatus);
        }

        // copy constructor
        _wfs_devstatus_w(const _wfs_devstatus_w& obj) { _wfs_devstatus_w::init(obj); }

        // move constructor
        _wfs_devstatus_w(_wfs_devstatus_w&& obj)  : _wfs_devstatus_w{ obj } {}

        // copy assignment
        _wfs_devstatus_w& operator = (const _wfs_devstatus_w& obj) 
        {
            this->init(obj);
            return *this;
        }
        
        // move assignment
        _wfs_devstatus_w& operator = (_wfs_devstatus_w&& obj) 
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_devstatus_w() noexcept
        {
            SAFEFREEMEMORY(&this->lpszPhysicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
        }

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfs_devstatus_w& obj) noexcept
        {
            out << " lpszPhysicalName: "    << std::string{ obj.lpszPhysicalName }
                << " lpszWorkstationName: " << std::string{ obj.lpszWorkstationName }
                << " dwState: "             << obj.dwState;
            return out;
        }
    } WFSDEVSTATUS_W, * LPWFSDEVSTATUS_W;

    typedef struct _wfs_undevmsg_w : public _wfs_undevmsg
    {
        // init
        void init(const _wfs_undevmsg& obj) 
        {
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ obj.lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, obj.lpszAppID);
            this->dwSize        = obj.dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)obj.lpbDescription });
            this->dwMsg         = obj.dwMsg;
            this->lpWFSResult   = new WFSRESULT_W{ obj.lpWFSResult };
        }

        // default constructor
        _wfs_undevmsg_w() = default;

        // normal constructor
        _wfs_undevmsg_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSUNDEVMSG l_lpWFSUNDEVMSG = static_cast<LPWFSUNDEVMSG>(lpBuffer);
            _wfs_undevmsg_w::init(*l_lpWFSUNDEVMSG);
        }

        // copy constructor
        _wfs_undevmsg_w(const _wfs_undevmsg_w& obj) { _wfs_undevmsg_w::init(obj); }

        // move constructor
        _wfs_undevmsg_w(_wfs_undevmsg_w&& obj)  : _wfs_undevmsg_w{ obj } {}

        // copy assignment
        _wfs_undevmsg_w& operator = (const _wfs_undevmsg_w& obj)
        {
            this->init(obj);
            return *this;
        }

        // move assignment
        _wfs_undevmsg_w& operator = (_wfs_undevmsg_w&& obj)
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_undevmsg_w() noexcept
        {            
            SAFEFREEMEMORY(&this->lpszLogicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
            SAFEFREEMEMORY(&this->lpszAppID);
            SAFEFREEMEMORY(&this->lpbDescription);
            SAFERELEASE((LPWFSRESULT_W*)&this->lpWFSResult);
        }

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfs_undevmsg_w& obj) noexcept
        {
            out << " lpszLogicalName: "     << std::string{ obj.lpszLogicalName }
                << " lpszWorkstationName: " << std::string{ obj.lpszWorkstationName }
                << " lpszAppID: "           << std::string{ obj.lpszAppID }
                << " dwSize: "              << obj.dwSize
                << " lpbDescription: "      << std::string{ (char*)obj.lpbDescription }
                << " dwMsg: "               << obj.dwMsg
                << " lpWFSResult: "         << obj.lpWFSResult;
            return out;
        }
    } WFSUNDEVMSG_W, * LPWFSUNDEVMSG_W;

    typedef struct _wfs_appdisc_w : public _wfs_appdisc
    {
        // init
        void init(const _wfs_appdisc& obj) noexcept
        {
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ obj.lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ obj.lpszAppID });
        }

        // default constructor
        _wfs_appdisc_w() = default;

        // normal constructor
        _wfs_appdisc_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSAPPDISC l_lpWFSAPPDisc = static_cast<LPWFSAPPDISC>(lpBuffer);
            this->init(*l_lpWFSAPPDisc);
        }

        // copy constructor
        _wfs_appdisc_w(const _wfs_appdisc_w& obj) { this->init(obj); }

        // move constructor
        _wfs_appdisc_w(_wfs_appdisc_w&& obj)  : _wfs_appdisc_w{ obj } {}

        // copy assignment
        _wfs_appdisc_w& operator = (const _wfs_appdisc_w& obj)
        {
            this->init(obj);
            return *this;
        }

        // move assignment
        _wfs_appdisc_w& operator = (_wfs_appdisc_w&& obj)
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_appdisc_w() noexcept
        {
            SAFEFREEMEMORY(&this->lpszLogicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
            SAFEFREEMEMORY(&this->lpszAppID);
        }

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfs_appdisc_w& obj) noexcept
        {
            out << " lpszLogicalName: "     << std::string{ obj.lpszLogicalName }
                << " lpszWorkstationName: " << std::string{ obj.lpszWorkstationName }
                << " lpszAppID: "           << std::string{ obj.lpszAppID };
            return out;
        }
    } WFSAPPDISC_W, * LPWFSAPPDISC_W;

    typedef struct _wfs_hwerror_w : public _wfs_hwerror
    {
        // init
        void init(const _wfs_hwerror& obj) noexcept
        {
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ obj.lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszPhysicalName, std::string{ obj.lpszPhysicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ obj.lpszAppID });
            this->dwAction      = obj.dwAction;
            this->dwSize        = obj.dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)obj.lpbDescription });
        }

        // default constructor
        _wfs_hwerror_w() = default;

        // normal constructor
        _wfs_hwerror_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSHWERROR l_lpWFSHWError = static_cast<LPWFSHWERROR>(lpBuffer);
            this->init(*l_lpWFSHWError);
        }

        // copy constructor
        _wfs_hwerror_w(const _wfs_hwerror_w& obj) { this->init(obj); }

        // move constructor
        _wfs_hwerror_w(_wfs_hwerror_w&& obj)  : _wfs_hwerror_w{ obj } {}

        // copy assignment
        _wfs_hwerror_w& operator = (const _wfs_hwerror_w& obj)
        {
            this->init(obj);
            return *this;
        }

        // move assignment
        _wfs_hwerror_w& operator = (_wfs_hwerror_w&& obj)
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_hwerror_w() noexcept
        {
            SAFEFREEMEMORY(&this->lpszLogicalName);
            SAFEFREEMEMORY(&this->lpszPhysicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
            SAFEFREEMEMORY(&this->lpszAppID);
            SAFEFREEMEMORY(&this->lpbDescription);
        }

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfs_hwerror_w& obj) noexcept
        {
            out << " lpszLogicalName: "         << std::string{ obj.lpszLogicalName }
                << " lpszPhysicalName: "        << std::string{ obj.lpszPhysicalName }
                << " lpszWorkstationName: "     << std::string{ obj.lpszWorkstationName }
                << " lpszAppID: "               << std::string{ obj.lpszAppID }
                << " dwAction: "                << obj.dwAction
                << " dwSize: "                  << obj.dwSize
                << " lpbDescription: "          << std::string{ (char*)obj.lpbDescription };
            return out;
        }
    } WFSHWERROR_W, * LPWFSHWERROR_W;

    typedef struct _wfs_vrsnerror_w : public _wfs_vrsnerror
    {
        // init
        void init(const _wfs_vrsnerror& obj) noexcept
        {
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ obj.lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ obj.lpszAppID });
            this->dwSize = obj.dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)obj.lpbDescription });
            if (obj.lpWFSVersion)
                this->lpWFSVersion = new WFSVERSION_W{ obj.lpWFSVersion };
        }

        // default constructor
        _wfs_vrsnerror_w() = default;

        // normal constructor
        _wfs_vrsnerror_w(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSVRSNERROR l_lpWFSVRSNError = static_cast<LPWFSVRSNERROR>(lpBuffer);
            this->init(*l_lpWFSVRSNError);
        }

        // copy constructor
        _wfs_vrsnerror_w(const _wfs_vrsnerror_w& obj) { this->init(obj); }

        // move constructor
        _wfs_vrsnerror_w(_wfs_vrsnerror_w&& obj) : _wfs_vrsnerror_w{ obj } {}

        // copy assignment
        _wfs_vrsnerror_w& operator = (const _wfs_vrsnerror_w& obj)
        {
            this->init(obj);
            return *this;
        }

        // move assignment
        _wfs_vrsnerror_w& operator = (_wfs_vrsnerror_w&& obj)
        {
            this->init(obj);
            return *this;
        }

        // destructor
        virtual ~_wfs_vrsnerror_w() noexcept
        {
            SAFEFREEMEMORY(&this->lpszLogicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
            SAFEFREEMEMORY(&this->lpszAppID);
            SAFEFREEMEMORY(&this->lpbDescription);
            SAFERELEASE((LPWFSVERSION_W*)&this->lpWFSVersion);
        }

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfs_vrsnerror_w& obj) noexcept
        {
            out << " lpszLogicalName: "     << std::string{ obj.lpszLogicalName }
                << " lpszWorkstationName: " << std::string{ obj.lpszWorkstationName }
                << " lpszAppID: "           << std::string{ obj.lpszAppID }
                << " dwSize: "              << obj.dwSize
                << " lpbDescription: "      << std::string{ (char*)obj.lpbDescription };
            if (obj.lpWFSVersion)
                out << " lpWFSVersion: "    << WFSVERSION_W{ obj.lpWFSVersion };
            return out;
        }
    } WFSVRSNERROR_W, * LPWFSVRSNERROR_W;

#pragma pack(pop)

} // !__N_XFSAPI_W__

#endif // !__H_XFSAPI_W__