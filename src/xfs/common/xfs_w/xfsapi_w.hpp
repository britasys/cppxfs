#pragma once

#ifndef __H_XFSAPI_W__
#define __H_XFSAPI_W__

/****** xfs **********************************************/
#include <xfsapi.h>

#pragma comment(lib, "msxfs")
#pragma comment(lib, "xfs_conf")
#pragma comment(lib, "xfs_supp")

/****** inc **********************************************/
#include <utility.hpp>
#include <definitions.hpp>

/****** stl **********************************************/
#include <stdexcept>
#include <iostream>

namespace __N_XFSAPI_W__
{
#pragma pack(push, 1)

    /****** Data Structures **********************************************/

    /**
     * @brief _wfs_result wrapper
     * 
     */
    typedef struct _wfs_result_w : public _wfs_result
    {
    private:
        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
        void init(const _wfs_result& obj)
        {
            this->RequestID             = obj.RequestID;
            this->hService              = obj.hService;
            this->tsTimestamp           = obj.tsTimestamp;
            this->hResult               = obj.hResult;
            this->u.dwCommandCode       = obj.u.dwCommandCode;
            this->lpBuffer              = obj.lpBuffer;                   // shallow copy
        }

        /**
         * @brief initializes structure properties
         * 
         * @param lpBuffer
         */
        void init(const LPVOID lpBuffer) noexcept(false)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSRESULT l_lpWFSResult = static_cast<LPWFSRESULT>(lpBuffer);
            this->init(*l_lpWFSResult);
        }

    public:
        /**
         * @brief normal constructor
         * 
         * @param obj
         */
        _wfs_result_w(const _wfs_result& obj) { this->init(obj); }

        /**
         * @brief normal constructor
         * 
         * @param lpBuffer
         */
        _wfs_result_w(const LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief default constructor
         * 
         */
        _wfs_result_w() = default;
        
        /**
         * @brief copy constructor
         * 
         */
        _wfs_result_w(const _wfs_result_w&) = default;

        /**
         * @brief move constructor
         * 
         */
        _wfs_result_w(_wfs_result_w&&) = default;

        /**
         * @brief copy assignment
         * 
         */
        _wfs_result_w& operator = (const _wfs_result_w&) = default;

        /**
         * @brief move assignment
         * 
         */
        _wfs_result_w& operator = (_wfs_result_w&&) = default;

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

    /**
     * @brief _wfsversion wrapper
     * 
     */
    typedef struct _wfsversion_w : public _wfsversion
    {
    private:
        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
        void init(const _wfsversion& obj) noexcept
        {
            this->wVersion              = obj.wVersion;
            this->wLowVersion           = obj.wLowVersion;
            this->wHighVersion          = obj.wHighVersion;
            SAFECOPYMEMORY(this->szDescription, obj.szDescription, WFSDDESCRIPTION_LEN + 1);
            SAFECOPYMEMORY(this->szSystemStatus, obj.szSystemStatus, WFSDSYSSTATUS_LEN + 1);
        }

        /**
         * @brief initializes structure properties
         * 
         * @param obj
         */
        void init(const LPVOID lpBuffer)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSVERSION l_lpWFSVersion = static_cast<LPWFSVERSION>(lpBuffer);
            this->init(*l_lpWFSVersion);
        }

    public:
        /**
         * @brief normal constructor
         * 
         * @param obj
         */
        _wfsversion_w(const _wfsversion& obj) { this->init(obj); }

        /**
         * @brief normal constructor
         * 
         * @param lpBuffer
         */
        _wfsversion_w(const LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief default constructor
         * 
         */
        _wfsversion_w() = default;

        /**
         * @brief copy constructor
         * 
         * @param obj
         */
        _wfsversion_w(const _wfsversion_w& obj) { this->init(obj); }

        /**
         * @brief move constructor
         * 
         * @param obj
         */
        _wfsversion_w(_wfsversion_w&& obj) : _wfsversion_w{ obj } {}

        /**
         * @brief copy assignment
         * 
         * @param obj
         */
        _wfsversion_w& operator = (const _wfsversion_w& obj) 
        {
            this->init(obj);
            return *this;
        }

        /**
         * @brief move assignment
         * 
         * @param obj
         */
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

    /**
     * @brief _wfs_devstatus wrapper
     * 
     */
    typedef struct _wfs_devstatus_w : public _wfs_devstatus
    {
    private:
        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
        void init(const _wfs_devstatus& obj) noexcept
        {
            SAFEALLOCCOPYSTRING(&this->lpszPhysicalName, std::string{ obj.lpszPhysicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            this->dwState = obj.dwState;
        }

        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
        void init(const LPVOID lpBuffer)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSDEVSTATUS l_lpWFSDevStatus = static_cast<LPWFSDEVSTATUS>(lpBuffer);
            _wfs_devstatus_w::init(*l_lpWFSDevStatus);
        }

    public:
        /**
         * @brief normal constructor
         * 
         * @param obj 
         */
        _wfs_devstatus_w(const _wfs_devstatus& obj) { this->init(obj); }

        /**
         * @brief normal constructor
         * 
         * @param lpBuffer 
         */
        _wfs_devstatus_w(const LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief default constructor
         * 
         */
        _wfs_devstatus_w() = default;

        /**
         * @brief copy constructor
         * 
         * @param obj 
         */
        _wfs_devstatus_w(const _wfs_devstatus_w& obj) { this->init(obj); }

        /**
         * @brief move constructor
         * 
         * @param obj 
         */
        _wfs_devstatus_w(_wfs_devstatus_w&& obj) : _wfs_devstatus_w{ obj } {}

        /**
         * @brief copy assignment
         * 
         * @param obj 
         */
        _wfs_devstatus_w& operator = (const _wfs_devstatus_w& obj) 
        {
            this->init(obj);
            return *this;
        }
        
        /**
         * @brief move assignment
         * 
         * @param obj 
         */
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

    /**
     * @brief _wfs_undevmsg wrapper
     * 
     */
    typedef struct _wfs_undevmsg_w : public _wfs_undevmsg
    {
    private:
        /**
        * @brief initializes structure properties
        * 
        * @param obj 
        */
        void init(const _wfs_undevmsg& obj)
        {
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ obj.lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, obj.lpszAppID);
            this->dwSize        = obj.dwSize;
            SAFEALLOCCOPYSTRING(&this->lpbDescription, std::string{ (char*)obj.lpbDescription });
            this->dwMsg         = obj.dwMsg;
            this->lpWFSResult   = obj.lpWFSResult;
        }

        /**
         * @brief Initializes the object
         * 
         * @param lpBuffer 
         */
        void init(LPVOID lpBuffer)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSUNDEVMSG l_lpWFSUNDEVMSG = static_cast<LPWFSUNDEVMSG>(lpBuffer);
            this->init(*l_lpWFSUNDEVMSG);
        }

    public:
        /**
         * @brief normal constructor
         * 
         * @param obj 
         */
        _wfs_undevmsg_w(const _wfs_undevmsg& obj) { this->init(obj); }

        /**
         * @brief normal constructor
         * 
         * @param lpBuffer 
         */
        _wfs_undevmsg_w(const LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief default constructor
         * 
         */
        _wfs_undevmsg_w() = default;

        /**
         * @brief copy constructor
         * 
         * @param obj 
         */
        _wfs_undevmsg_w(const _wfs_undevmsg_w& obj) { this->init(obj); }

        /**
         * @brief move constructor
         * 
         * @param obj 
         */
        _wfs_undevmsg_w(_wfs_undevmsg_w&& obj) : _wfs_undevmsg_w{ obj } {}

        /**
         * @brief copy assignment
         * 
         * @param obj 
         */
        _wfs_undevmsg_w& operator = (const _wfs_undevmsg_w& obj)
        {
            this->init(obj);
            return *this;
        }

        /**
         * @brief move assignment
         * 
         * @param obj 
         */
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

    /**
     * @brief _wfs_appdisc wrapper
     * 
     */
    typedef struct _wfs_appdisc_w : public _wfs_appdisc
    {
    private:
        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
        void init(const _wfs_appdisc& obj) noexcept
        {
            SAFEALLOCCOPYSTRING(&this->lpszLogicalName, std::string{ obj.lpszLogicalName });
            SAFEALLOCCOPYSTRING(&this->lpszWorkstationName, std::string{ obj.lpszWorkstationName });
            SAFEALLOCCOPYSTRING(&this->lpszAppID, std::string{ obj.lpszAppID });
        }

        /**
         * @brief initializes structure properties
         * 
         * @param lpBuffer 
         */
        void init(const LPVOID lpBuffer)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSAPPDISC l_lpWFSAPPDisc = static_cast<LPWFSAPPDISC>(lpBuffer);
            this->init(*l_lpWFSAPPDisc);
        }

    public:
        /**
         * @brief normal constructor
         * 
         * @param lpBuffer 
         */
        _wfs_appdisc_w(LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief normal constructor
         * 
         * @param obj 
         */
        _wfs_appdisc_w(const _wfs_appdisc& obj) { this->init(obj); }

        /**
         * @brief default constructor
         * 
         */
        _wfs_appdisc_w() = default;

        /**
         * @brief copy constructor
         * 
         * @param obj 
         */
        _wfs_appdisc_w(const _wfs_appdisc_w& obj) { this->init(obj); }

        /**
         * @brief move constructor
         * 
         * @param obj 
         */
        _wfs_appdisc_w(_wfs_appdisc_w&& obj)  : _wfs_appdisc_w{ obj } {}

        /**
         * @brief copy assignment
         * 
         * @param obj 
         */
        _wfs_appdisc_w& operator = (const _wfs_appdisc_w& obj)
        {
            this->init(obj);
            return *this;
        }

        /**
         * @brief move assignment
         * 
         * @param obj 
         */
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

    /**
     * @brief _wfs_hwerror wrapper
     * 
     */
    typedef struct _wfs_hwerror_w : public _wfs_hwerror
    {
    private:
        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
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

        /**
         * @brief initializes structure properties
         * 
         * @param lpBuffer 
         */
        void init(const LPVOID lpBuffer)
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSHWERROR l_lpWFSHWError = static_cast<LPWFSHWERROR>(lpBuffer);
            this->init(*l_lpWFSHWError);
        }
        
    public:
        /**
         * @brief normal constructor
         * 
         * @param lpBuffer 
         */
        _wfs_hwerror_w(const LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief normal constructor
         * 
         * @param obj 
         */
        _wfs_hwerror_w(const _wfs_hwerror& obj) { this->init(obj); }

        /**
         * @brief default constructor
         * 
         */
        _wfs_hwerror_w() = default;

        /**
         * @brief copy constructor
         * 
         * @param obj 
         */
        _wfs_hwerror_w(const _wfs_hwerror_w& obj) { this->init(obj); }

        /**
         * @brief move constructor
         * 
         * @param obj 
         */
        _wfs_hwerror_w(_wfs_hwerror_w&& obj)  : _wfs_hwerror_w{ obj } {}

        /**
         * @brief copy assignment
         * 
         * @param obj 
         */
        _wfs_hwerror_w& operator = (const _wfs_hwerror_w& obj)
        {
            this->init(obj);
            return *this;
        }

        /**
         * @brief move assignment
         * 
         * @param obj 
         */
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
            out << " lpszLogicalName: "     << std::string{ obj.lpszLogicalName }
                << " lpszPhysicalName: "    << std::string{ obj.lpszPhysicalName }
                << " lpszWorkstationName: " << std::string{ obj.lpszWorkstationName }
                << " lpszAppID: "           << std::string{ obj.lpszAppID }
                << " dwAction: "            << obj.dwAction
                << " dwSize: "              << obj.dwSize
                << " lpbDescription: "      << std::string{ (char*)obj.lpbDescription };
            return out;
        }
    } WFSHWERROR_W, * LPWFSHWERROR_W;

    /**
     * @brief _wfs_vrsnerror wrapper
     * 
     */
    typedef struct _wfs_vrsnerror_w : public _wfs_vrsnerror
    {
    private:
        /**
         * @brief initializes structure properties
         * 
         * @param obj 
         */
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

        /**
         * @brief initializes structure properties
         * 
         * @param lpBuffer 
         */
        void init(LPVOID lpBuffer) 
        {
            UNSAFEPTR(lpBuffer) throw std::invalid_argument("lpBuffer is NULL");
            LPWFSVRSNERROR l_lpWFSVRSNError = static_cast<LPWFSVRSNERROR>(lpBuffer);
            this->init(*l_lpWFSVRSNError);
        }

    public:
        /**
         * @brief normal constructor
         * 
         */
        _wfs_vrsnerror_w(const _wfs_vrsnerror& obj) { this->init(obj); }

        /**
         * @brief normal constructor
         * 
         */
        _wfs_vrsnerror_w(const LPVOID lpBuffer) { this->init(lpBuffer); }

        /**
         * @brief default constructor
         * 
         */
        _wfs_vrsnerror_w() = default;

        /**
         * @brief copy constructor
         * 
         */
        _wfs_vrsnerror_w(const _wfs_vrsnerror_w& obj) { this->init(obj); }

        /**
         * @brief move constructor
         * 
         */
        _wfs_vrsnerror_w(_wfs_vrsnerror_w&& obj) : _wfs_vrsnerror_w{ obj } {}

        /**
         * @brief copy assignment
         * 
         */
        _wfs_vrsnerror_w& operator = (const _wfs_vrsnerror_w& obj)
        {
            this->init(obj);
            return *this;
        }

        /**
         * @brief move assignment
         * 
         */
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
    
    /**
     * @brief WFSStartUp parameters
     * 
     */
    typedef struct _wfs_startup_p
    {
        /**
         * @brief Specifies the range of versions of the XFS Manager that 
         * the application can support. The low-order word indicates the 
         * highest version of the XFS Manager the application can support; 
         * the high-order word indicates the lowest version of the XFS Manager 
         * the application can support. In each word, the low-order byte specifies 
         * the major version number and the high-order byte specifies the minor 
         * version number (i.e. the numbers before and after the decimal). 
         * Note: in order to allow intermediate minor revisions (e.g. between 1.10 and 1.20), 
         * the minor version number should always be expressed as two decimal digits, 
         * i.e. 1.10, 1.11, 1.20, etc. 
         */
        DWORD dwVersionRequired{ 0x0000 };

        /**
         * @brief // Data structure that is to receive version support 
         * information and other details about the current 
         * XFS implementation (returned parameter).
         */
        WFSVERSION WFSVersion{};

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_startup_p& obj) noexcept
        {
            out << " dwVersionRequired: "   << obj.dwVersionRequired
                << " WFSVersion: "          << WFSVERSION_W{ obj.WFSVersion };
            return out;
        }
    } WFSSTARTUP_P, * LPWFSSTARTUP_P;
    
    /**
     * @brief WFSSOpen parameters
     * 
     */
    typedef struct _xfs_open_p
    {
        /**
         * @brief String containing the pre-defined 
         * logical name of a service. It is a high level name such as 
         * "SYSJOURNAL1", "PASSBOOKPTR3" or "CASHDISP02," that is used by the XFS 
         * Manager and the Service Provider solely as a key to obtain the specific 
         * configuration information they need. 
         */
        std::string strLogicName{};

        /**
         * @brief The application handle to be associated with the session being opened. 
         * If this parameter is equal to WFS_DEFAULT_HAPP, the session is associated with 
         * the calling process as a whole (i.e. the calling process, not some subset of its 
         * threads, is the owner of the session and its hService).
         * See WFSCreateAppHandle for details.
         */
        HAPP hApp{ NULL };

        /**
         * @brief String containing the application ID; 
         * the pointer may be NULL if the ID is not used. This ID may be used by 
         * services in a variety of ways; e.g. it is included in the SYSTEM_EVENT 
         * message for undeliverable events, to aid in finding system problems
         */
        std::string strAppID{};

        /**
         * @brief NULL turns off all tracing. 
         */
        DWORD dwTraceLevel{ 0x0000 };

        /**
         * @brief Number of milliseconds to wait for completion 
         * (WFS_INDEFINITE_WAIT to specify a request that will wait until completion).
         */
        DWORD dwTimeOut{ 0x0000 };

        /**
         * @brief Specifies the range of versions of the service-specific interface 
         * that the application can support. (See Comments.) The low-order word indicates 
         * the highest version of the interface the application can support; the high-order 
         * word indicates the lowest version of the interface the application can support. 
         * In each word, the low-order byte specifies the major version number and the 
         * high-order byte specifies the minor version number (i.e. the numbers before and after the decimal). 
         * Note: in order to allow intermediate minor revisions (e.g. between 1.10 and 1.20), 
         * the minor version number should always be expressed as two decimal digits, i.e. 1.10, 1.11, 1.20, etc.
         */
        DWORD dwSrvcVersionsRequired{ 0x0000 };

        /**
         * @brief Data structure that is to receive version support information and other 
         * details about the service-specific interface implementation (returned parameter).
         */
        WFSVERSION SrvcVersion{};

        /**
         * @brief Data structure that is to receive version support information and (optionally)
         * other details about the SPI implementation of the Service Provider being 
         * opened (returned parameter).
         */
        WFSVERSION SPIVersion{};

        /**
         * @brief The service handle that the XFS Manager assigns to the service 
         * on a successful open; the application uses this handle for communication with the 
         * Service Provider for the remainder of the session (returned parameter). 
         * If a process opens the same service twice, the XFS Manager generates and returns 
         * different hService values.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _xfs_open_p& obj) noexcept
        {
            out << " strLogicName: "            << obj.strLogicName
                << " hApp: "                    << obj.hApp
                << " strAppID: "                << obj.strAppID
                << " dwTraceLevel: "            << obj.dwTraceLevel
                << " dwTimeOut: "               << obj.dwTimeOut
                << " dwSrvcVersionsRequired: "  << obj.dwSrvcVersionsRequired
                << " SrvcVersion: "             << WFSVERSION_W{ obj.SrvcVersion }
                << " SPIVersion: "              << WFSVERSION_W{ obj.SPIVersion }
                << " hService: "                << obj.hService;
            return out;
        }
    } WFSOPEN_P, * LPWFSOPEN_P;

    /**
     * @brief WFSClose parameters
     * 
     */
    typedef struct _wfs_close_p
    {
        /**
         * @brief The service handle returned by WFSOpen or WFSAsyncOpen. 
         * Matches the close request to the open request, allowing an application 
         * to maintain several "open sessions" simultaneously.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_close_p& obj) noexcept
        {
            out << " hService: " << obj.hService;
            return out;
        }
    } WFSCLOSE_P, * LPWFSCLOSE_P;
    
    /**
     * @brief WFSRegister parameters
     * 
     */
    typedef struct _wfs_register_p
    {
        /**
         * @brief Handle to the Service Provider as returned by WFSOpen or WFSAsyncOpen. 
         * If this value is NULL, and dwEventClass is SYSTEM_EVENTS, the XFS manager registers 
         * the application for those system events generated by the Manager itself.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief The class(es) of events for which the application is registering. 
         * Specified as a set of bit masks that are logically ORed together into this parameter.
         */
        DWORD dwEventClass{ 0x0000 };

        /**
         * @brief The window handle which is to be registered to receive the specified messages.
         */
        HWND hWndReg{ NULL };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_register_p& obj) noexcept
        {
            out << " hService: "        << obj.hService
                << " dwEventClass: "    << obj.dwEventClass
                << " hWndReg: "         << obj.hWndReg;
            return out;
        }
    } WFSREGISTER_P, * LPWFSREGISTER_P;

    /**
     * @brief WFSLock parameters
     * 
     */
    typedef struct _wfs_lock_p
    {
        /**
         * @brief Service Provider handle as returned by WFSOpen or WFSAsyncOpen.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief Number of milliseconds to wait for completion 
         * (WFS_INDEFINITE_WAIT to specify a request that will wait until completion).
         */
        DWORD dwTimeOut{ 0x0000 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_lock_p& obj) noexcept
        {
            out << " hService: "    << obj.hService
                << " dwTimeOut: "   << obj.dwTimeOut;
            return out;
        }
    } WFSLOCK_P, * LPWFSLOCK_P;

    /**
     * @brief WFSUnLock parameters
     * 
     */
    typedef struct _wfs_unlock_p
    {
        /**
         * @brief Service Provider handle as returned by WFSOpen or WFSAsyncOpen.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_unlock_p& obj) noexcept
        {
            out << " hService: " << obj.hService;
            return out;
        }
    } WFSUNLOCK_P, * LPWFSUNLOCK_P;

    /**
     * @brief WFSCancelAsyncRequest parameters
     * 
     */
    typedef struct _wfs_cancel_async_request_p
    {
        /**
         * @brief Handle to the service as returned by WFSOpen or WFSAsyncOpen.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief The request identifier for the request to be canceled, as returned by the original function call (NULL to cancel all).
         */
        REQUESTID RequestID{ NULL };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_cancel_async_request_p& obj) noexcept
        {
            out << " hService: "    << obj.hService
                << " RequestID: "   << obj.RequestID;
            return out;
        }
    } WFSCANCELASYNCREQUEST_P, * LPWFSCANCELASYNCREQUEST_P;

    /**
     * @brief WFSCancelBlockingCall parameters
     * 
     */
    typedef struct _wfs_cancel_blocking_call_p
    {
        /**
         * @brief Handle to the service as returned by WFSOpen or WFSAsyncOpen.
         */
        DWORD dwThreadID{ 0 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_cancel_blocking_call_p& obj) noexcept
        {
            out << " dwThreadID: " << obj.dwThreadID;
            return out;
        }
    } WFSCANCELBLOCKINGCALL_P, * LPWFSCANCELBLOCKINGCALL_P;

    /**
     * @brief WFSFreeResult parameters
     * 
     */
    typedef struct _wfs_free_result_p
    {
        /**
         * @brief WFSRESULT_W data structure.
         * 
         */
        LPWFSRESULT lpWFSResult{};

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_free_result_p& obj) noexcept
        {
            out << " WFSResult: " << WFSRESULT_W{ *obj.lpWFSResult };
            return out;
        }
    } WFSFREERESULT_P, * LPWFSFREERESULT_P;

    /**
     * @brief WFSSetBlockingHook parameters
     * 
     */
    typedef struct _wfs_set_blocking_hook_p
    {
        /**
         * @brief Pointer to the procedure instance address of the blocking routine to be installed.
         */
        XFSBLOCKINGHOOK lpBlockFunc{ nullptr };

        /**
         * @brief Returned pointer to the procedure instance of the previously installed blocking routine.
         * 
         */
        XFSBLOCKINGHOOK lpPrevFunc{ nullptr };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_set_blocking_hook_p& obj) noexcept
        {
            out << " lpBlockFunc: " << obj.lpBlockFunc
                << " lpPrevFunc: "  << obj.lpPrevFunc;
            return out;
        }
    } WFSSETBLOCKINGHOOK_P, * LPWFSSETBLOCKINGHOOK_P;

    /**
     * @brief WFSGetInfo parameters
     * 
     */
    typedef struct _wfs_get_info_p
    {
        /**
         * @brief Handle to the Service Provider as returned by WFSOpen or WFSAsyncOpen.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief Specifies the category of the query (e.g. for a printer, 
         * WFS_INF_PTR_STATUS to request status or WFS_INF_PTR_CAPABILITIES to request capabilities). 
         * The available categories depend on the service class, the Service Provider and the service. 
         * The information requested can be either static or dynamic, e.g. basic service capabilities 
         * (static) or current service status (dynamic).
         */
        DWORD dwCategory{ 0x0000 };

        /**
         * @brief Pointer to the data structure to be passed to the Service Provider, 
         * containing further details to make the query more precise, e.g. a form name. 
         * Many queries have no input parameters, in which case this pointer is NULL.
         */
        LPVOID lpQueryDetails{ nullptr };

        /**
         * @brief Number of milliseconds to wait for completion (WFS_INDEFINITE_WAIT to 
         * specify a request that will wait until completion).
         */
        DWORD dwTimeOut{ 0x0000 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_get_info_p& obj) noexcept
        {
            out << " hService: "                << obj.hService
                << " dwCategory: "              << obj.dwCategory
                << " lpQueryDetails: "          << obj.lpQueryDetails
                << " dwTimeOut: "               << obj.dwTimeOut;
            return out;
        }
    } WFSGETINFO_P, * LPWFSGETINFO_P;

    /**
     * @brief WFSExecute parameters
     * 
     */
    typedef struct _wfs_execute_p
    {
        /**
         * @brief Handle to the service as returned by WFSOpen or WFSAsyncOpen.
         */
        HSERVICE hService{ 0 };

        /**
         * @brief Command to be executed by the Service Provider.
         */
        DWORD dwCommand{ 0x0000 };

        /**
         * @brief Pointer to a command data structure to be passed to the Service Provider.
         */
        LPVOID lpCmdData{ nullptr };

        /**
         * @brief Number of milliseconds to wait for completion (WFS_INDEFINITE_WAIT 
         * to specify a request that will wait until completion).
         */
        DWORD dwTimeOut{ 0x0000 };

        /**
         * @brief << operator
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator << (std::ostream& out, const _wfs_execute_p& obj) noexcept
        {
            out << " hService: "    << obj.hService
                << " dwCommand: "   << obj.dwCommand
                << " lpCmdData: "   << obj.lpCmdData
                << " dwTimeOut: "   << obj.dwTimeOut;
            return out;
        }
    } WFSEXECUTE_P, * LPWFSEXECUTE_P;

#pragma pack(pop)

} // !__N_XFSAPI_W__

#endif // !__H_XFSAPI_W__