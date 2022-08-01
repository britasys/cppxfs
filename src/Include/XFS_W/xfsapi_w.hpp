#pragma once

#ifndef __H_XFSAPI_W__
#define __H_XFSAPI_W__

#include <xfsapi.h>
#include <utility.hpp>
#include <definitions.hpp>

#include <stdexcept>

namespace __N_XFSAPI_W__
{    
    /****** Data Structures *************************************************/
    typedef struct _wfs_result_w : public _wfs_result
    {
        // normal constructor
        _wfs_result_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSRESULT l_lpWFSResult = static_cast<LPWFSRESULT>(lpBuffer);
            this->RequestID = l_lpWFSResult->RequestID;
            this->hService = l_lpWFSResult->hService;
            this->tsTimestamp = l_lpWFSResult->tsTimestamp;
            this->hResult = l_lpWFSResult->hResult;
            this->u.dwCommandCode = l_lpWFSResult->u.dwCommandCode;
            this->lpBuffer = l_lpWFSResult->lpBuffer;                   // shallow copy
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
        // default constructor
        _wfsversion_w() = delete;

        // normal constructor
        _wfsversion_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSVERSION l_lpWFSVersion = static_cast<LPWFSVERSION>(lpBuffer);
            this->wVersion = l_lpWFSVersion->wVersion; 
            this->wLowVersion = l_lpWFSVersion->wLowVersion;
            this->wHighVersion = l_lpWFSVersion->wHighVersion;
            SAFECOPYMEMORY(this->szDescription, l_lpWFSVersion->szDescription, WFSDDESCRIPTION_LEN + 1);
            SAFECOPYMEMORY(this->szSystemStatus, l_lpWFSVersion->szSystemStatus, WFSDSYSSTATUS_LEN + 1);
        }

        // copy constructor
        _wfsversion_w(const _wfsversion_w& obj) noexcept(false) : _wfsversion_w{ (LPVOID)&obj } {}

        // move constructor
        _wfsversion_w(_wfsversion_w&& obj) noexcept(false) : _wfsversion_w{ obj } {}

        // copy assignment
        _wfsversion_w& operator = (const _wfsversion_w& obj) noexcept(false) { return _wfsversion_w{ obj }; }

        // move assignment
        _wfsversion_w& operator = (_wfsversion_w&& obj) noexcept(false) { return _wfsversion_w{ obj }; }

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
        // default constructor
        _wfs_devstatus_w() = delete;

        // normal constructor
        _wfs_devstatus_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSDEVSTATUS l_lpWFSDevStatus = static_cast<LPWFSDEVSTATUS>(lpBuffer);
            SAFEALLOCCOPYSTRING(&this->lpszPhysicalName, std::string{ l_lpWFSDevStatus->lpszPhysicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ l_lpWFSDevStatus->lpszWorkstationName });
            this->dwState = l_lpWFSDevStatus->dwState;
        }

        // copy constructor
        _wfs_devstatus_w(const _wfs_devstatus_w& obj) noexcept(false) : _wfs_devstatus_w{ (LPVOID)&obj } {}

        // move constructor
        _wfs_devstatus_w(_wfs_devstatus_w&& obj) noexcept(false) : _wfs_devstatus_w{ obj } {}

        // copy assignment
        _wfs_devstatus_w& operator = (const _wfs_devstatus_w& obj) noexcept(false) { return _wfs_devstatus_w{ obj }; }
        
        // move assignment
        _wfs_devstatus_w& operator = (_wfs_devstatus_w&& obj) noexcept(false) { return _wfs_devstatus_w{ obj }; }

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
        // default constructor
        _wfs_undevmsg_w() = delete;

        // normal constructor
        _wfs_undevmsg_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSUNDEVMSG l_lpWFSUNDEVMSG = static_cast<LPWFSUNDEVMSG>(lpBuffer);
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ l_lpWFSUNDEVMSG->lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ l_lpWFSUNDEVMSG->lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, l_lpWFSUNDEVMSG->lpszAppID);
            this->dwSize = l_lpWFSUNDEVMSG->dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)l_lpWFSUNDEVMSG->lpbDescription });
            this->dwMsg = l_lpWFSUNDEVMSG->dwMsg;
            this->lpWFSResult = l_lpWFSUNDEVMSG->lpWFSResult;
        }

        // copy constructor
        _wfs_undevmsg_w(const _wfs_undevmsg_w& obj) noexcept(false) : _wfs_undevmsg_w{ (LPVOID)&obj } {}

        // move constructor
        _wfs_undevmsg_w(_wfs_undevmsg_w&& obj) noexcept(false) : _wfs_undevmsg_w{ obj } {}

        // copy assignment
        _wfs_undevmsg_w& operator = (const _wfs_undevmsg_w& obj) noexcept(false) { return _wfs_undevmsg_w{ obj }; }

        // move assignment
        _wfs_undevmsg_w& operator = (_wfs_undevmsg_w&& obj) noexcept(false) { return _wfs_undevmsg_w{ obj }; }

        // destructor
        virtual ~_wfs_undevmsg_w() noexcept
        {            
            SAFEFREEMEMORY(&this->lpszLogicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
            SAFEFREEMEMORY(&this->lpszAppID);
            SAFEFREEMEMORY(&this->lpbDescription);
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
        // default constructor
        _wfs_appdisc_w() = delete;

        // normal constructor
        _wfs_appdisc_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSAPPDISC l_lpWFSAPPDisc = static_cast<LPWFSAPPDISC>(lpBuffer);
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ l_lpWFSAPPDisc->lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ l_lpWFSAPPDisc->lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ l_lpWFSAPPDisc->lpszAppID });
        }

        // copy constructor
        _wfs_appdisc_w(const _wfs_appdisc_w& obj) noexcept(false) : _wfs_appdisc_w{ (LPVOID)&obj } {}

        // move constructor
        _wfs_appdisc_w(_wfs_appdisc_w&& obj) noexcept(false) : _wfs_appdisc_w{ obj } {}

        // copy assignment
        _wfs_appdisc_w& operator = (const _wfs_appdisc_w& obj) noexcept(false) { return _wfs_appdisc_w{ obj };}

        // move assignment
        _wfs_appdisc_w& operator = (_wfs_appdisc_w&& obj) noexcept(false) { return _wfs_appdisc_w{ obj };}

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
        // default constructor
        _wfs_hwerror_w() = delete;

        // normal constructor
        _wfs_hwerror_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSHWERROR l_lpWFSHWError = static_cast<LPWFSHWERROR>(lpBuffer);
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ l_lpWFSHWError->lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszPhysicalName, std::string{ l_lpWFSHWError->lpszPhysicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ l_lpWFSHWError->lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ l_lpWFSHWError->lpszAppID });
            this->dwAction = l_lpWFSHWError->dwAction;
            this->dwSize = l_lpWFSHWError->dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)l_lpWFSHWError->lpbDescription });
        }

        // copy constructor
        _wfs_hwerror_w(const _wfs_hwerror_w& obj) noexcept(false) : _wfs_hwerror_w{ (LPVOID)&obj } {}

        // move constructor
        _wfs_hwerror_w(_wfs_hwerror_w&& obj) noexcept(false) : _wfs_hwerror_w(obj) {}

        // copy assignment
        _wfs_hwerror_w& operator = (const _wfs_hwerror_w& obj) noexcept(false) { return _wfs_hwerror_w{ obj }; }

        // move assignment
        _wfs_hwerror_w& operator = (_wfs_hwerror_w&& obj) noexcept(false) { return _wfs_hwerror_w{ obj }; }

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
        // properties
        LPWFSVERSION_W lpWFSVersion_w{ nullptr };

        // default constructor
        _wfs_vrsnerror_w() = delete;

        // normal constructor
        _wfs_vrsnerror_w(LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSVRSNERROR l_lpWFSVRSNError = static_cast<LPWFSVRSNERROR>(lpBuffer);
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ l_lpWFSVRSNError->lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ l_lpWFSVRSNError->lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ l_lpWFSVRSNError->lpszAppID });
            this->dwSize = l_lpWFSVRSNError->dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)l_lpWFSVRSNError->lpbDescription });
            this->lpWFSVersion = nullptr;
            if (l_lpWFSVRSNError->lpWFSVersion)
                this->lpWFSVersion_w = new WFSVERSION_W{ l_lpWFSVRSNError->lpWFSVersion };
        }

        // copy constructor
        _wfs_vrsnerror_w(const _wfs_vrsnerror_w& obj) noexcept(false) : _wfs_vrsnerror_w{ (LPVOID)&obj } {}

        // move constructor
        _wfs_vrsnerror_w(_wfs_vrsnerror_w&& obj) noexcept(false) : _wfs_vrsnerror_w{ (LPVOID)&obj } {}

        // copy assignment
        _wfs_vrsnerror_w& operator = (const _wfs_vrsnerror_w& obj) noexcept(false) { return _wfs_vrsnerror_w{ obj }; }

        // move assignment
        _wfs_vrsnerror_w& operator = (_wfs_vrsnerror_w&& obj) noexcept(false) { return _wfs_vrsnerror_w{ obj }; }

        // destructor
        virtual ~_wfs_vrsnerror_w() noexcept
        {
            SAFEFREEMEMORY(&this->lpszLogicalName);
            SAFEFREEMEMORY(&this->lpszWorkstationName);
            SAFEFREEMEMORY(&this->lpszAppID);
            SAFEFREEMEMORY(&this->lpbDescription);
            SAFERELEASE(&this->lpWFSVersion_w);
        }

        // << operator
        friend std::ostream& operator << (std::ostream& out, const _wfs_vrsnerror_w& obj) noexcept
        {
            out << " lpszLogicalName: "     << std::string{ obj.lpszLogicalName }
                << " lpszWorkstationName: " << std::string{ obj.lpszWorkstationName }
                << " lpszAppID: "           << std::string{ obj.lpszAppID }
                << " dwSize: "              << obj.dwSize
                << " lpbDescription: "      << std::string{ (char*)obj.lpbDescription };
            if (obj.lpWFSVersion_w)
                out << " lpWFSVersion: "    << *obj.lpWFSVersion_w;
            return out;
        }
    } WFSVRSNERROR_W, * LPWFSVRSNERROR_W;
} // !__N_XFSAPI_W__

#endif // !__H_XFSAPI_W__