#pragma once

#ifndef __H_GTEST_WFSAPI_STRUCTURES__
#define __H_GTEST_WFSAPI_STRUCTURES__

#include <gtest/gtest.h>

#include <xfsapi_w.hpp>

TEST(_wfs_result_w, constructors) 
{
    WFSRESULT l_WFSResult{};
    l_WFSResult.RequestID               = 100;
    l_WFSResult.hService                = 101;
    l_WFSResult.tsTimestamp             = SYSTEMTIME{};
    l_WFSResult.hResult                 = 0;
    l_WFSResult.u.dwCommandCode         = 311;
    l_WFSResult.lpBuffer                = nullptr;

    // normal constructor
    __N_XFSAPI_W__::_wfs_result_w l_WFSResult_w_1{ (LPVOID)&l_WFSResult };    
    EXPECT_EQ(l_WFSResult_w_1.RequestID, 100);
    EXPECT_EQ(l_WFSResult_w_1.hService, 101);
    EXPECT_EQ(l_WFSResult_w_1.hResult, 0);
    EXPECT_EQ(l_WFSResult_w_1.u.dwCommandCode, 311);
}

TEST(_wfsversion_w, constructors)
{
    auto compare = [](const __N_XFSAPI_W__::_wfsversion_w& obj_1, const WFSVERSION& obj_2) {
        EXPECT_EQ(obj_1.wVersion, obj_2.wVersion);
        EXPECT_EQ(obj_1.wLowVersion, obj_2.wLowVersion);
        EXPECT_EQ(obj_1.wHighVersion, obj_2.wHighVersion);
        EXPECT_EQ(std::string{ obj_1.szDescription }, std::string{ obj_2.szDescription });
        EXPECT_EQ(std::string{ obj_1.szSystemStatus }, std::string{ obj_2.szSystemStatus });
    };

    WFSVERSION l_WFSVersion{};
    l_WFSVersion.wVersion              = 310;
    l_WFSVersion.wLowVersion           = 300;
    l_WFSVersion.wHighVersion          = 330;
    SAFECOPYMEMORY(l_WFSVersion.szDescription, "szDescription", WFSDDESCRIPTION_LEN + 1);
    SAFECOPYMEMORY(l_WFSVersion.szSystemStatus, "szSystemStatus", WFSDSYSSTATUS_LEN + 1);

    // normal constructor
    __N_XFSAPI_W__::_wfsversion_w l_WFSVersion_w_1{ (LPVOID)&l_WFSVersion };
    compare(l_WFSVersion_w_1, l_WFSVersion);

    // copy constructor
    __N_XFSAPI_W__::_wfsversion_w l_WFSVersion_w_2{ l_WFSVersion_w_1 };
    compare(l_WFSVersion_w_2, l_WFSVersion);

    // move constructor
    __N_XFSAPI_W__::_wfsversion_w l_WFSVersion_w_3{ std::move(l_WFSVersion_w_1) };
    compare(l_WFSVersion_w_3, l_WFSVersion);

    // copy assignment
    __N_XFSAPI_W__::_wfsversion_w l_WFSVersion_w_4{};
    l_WFSVersion_w_4 = l_WFSVersion_w_1;
    compare(l_WFSVersion_w_4, l_WFSVersion);

    // move assignment
    __N_XFSAPI_W__::_wfsversion_w l_WFSVersion_w_5{};
    l_WFSVersion_w_5 = std::move(l_WFSVersion_w_1);
    compare(l_WFSVersion_w_5, l_WFSVersion);
}

TEST(_wfs_devstatus_w, constructors)
{
    auto compare = [](const __N_XFSAPI_W__::_wfs_devstatus_w& obj_1, const WFSDEVSTATUS& obj_2) {        
        EXPECT_EQ(std::string{ obj_1.lpszPhysicalName }, std::string{ obj_2.lpszPhysicalName });
        EXPECT_EQ(std::string{ obj_1.lpszWorkstationName }, std::string{ obj_2.lpszWorkstationName });
        EXPECT_EQ(obj_1.dwState, obj_2.dwState);
    };

    WFSDEVSTATUS l_WFSDevStatus{};
    SAFEALLOCCOPYSTRING(&l_WFSDevStatus.lpszPhysicalName, std::string{ "lpszPhysicalName" });
    SAFEALLOCCOPYSTRING(&l_WFSDevStatus.lpszWorkstationName, std::string{ "lpszWorkstationName" });
    l_WFSDevStatus.dwState = 101;

    // normal constructor
    __N_XFSAPI_W__::_wfs_devstatus_w l_WFSDevStatus_w_1{ (LPVOID)&l_WFSDevStatus };
    compare(l_WFSDevStatus_w_1, l_WFSDevStatus);

    // copy constructor
    __N_XFSAPI_W__::_wfs_devstatus_w l_WFSDevStatus_w_2{ l_WFSDevStatus_w_1 };
    compare(l_WFSDevStatus_w_2, l_WFSDevStatus);

    // move constructor
    __N_XFSAPI_W__::_wfs_devstatus_w l_WFSDevStatus_w_3{ std::move(l_WFSDevStatus_w_1) };
    compare(l_WFSDevStatus_w_3, l_WFSDevStatus);

    // copy assignment
    __N_XFSAPI_W__::_wfs_devstatus_w l_WFSDevStatus_w_4{};
    l_WFSDevStatus_w_4 = l_WFSDevStatus_w_1;
    compare(l_WFSDevStatus_w_4, l_WFSDevStatus);

    // move assignment
    __N_XFSAPI_W__::_wfs_devstatus_w l_WFSDevStatus_w_5{};
    l_WFSDevStatus_w_5 = std::move(l_WFSDevStatus_w_1);
    compare(l_WFSDevStatus_w_5, l_WFSDevStatus);
}

TEST(_wfs_undevmsg_w, constructors)
{
    auto compare = [] (const __N_XFSAPI_W__::_wfs_undevmsg_w& obj_1, const WFSUNDEVMSG& obj_2) {
        EXPECT_EQ(std::string{ obj_1.lpszLogicalName }, std::string{ obj_2.lpszLogicalName });
        EXPECT_EQ(std::string{ obj_1.lpszWorkstationName }, std::string{ obj_2.lpszWorkstationName });
        EXPECT_EQ(std::string{ obj_1.lpszAppID }, std::string{ obj_2.lpszAppID });
        EXPECT_EQ(obj_1.dwSize, obj_2.dwSize);
        EXPECT_EQ(std::string{ (char*)obj_1.lpbDescription }, std::string{ (char*)obj_2.lpbDescription });
        EXPECT_EQ(obj_1.dwMsg, obj_2.dwMsg);
    };

    WFSRESULT l_WFSResult{};
    l_WFSResult.RequestID               = 100;
    l_WFSResult.hService                = 101;
    l_WFSResult.tsTimestamp             = SYSTEMTIME{};
    l_WFSResult.hResult                 = 0;
    l_WFSResult.u.dwCommandCode         = 311;
    l_WFSResult.lpBuffer                = nullptr;

    WFSUNDEVMSG l_WFSUNDEVMSG{};
    SAFEALLOCCOPYSTRING(&l_WFSUNDEVMSG.lpszLogicalName, std::string{ "lpszLogicalName" });
    SAFEALLOCCOPYSTRING(&l_WFSUNDEVMSG.lpszWorkstationName, std::string{ "lpszWorkstationName" });
    SAFEALLOCCOPYSTRING(&l_WFSUNDEVMSG.lpszAppID, std::string{ "lpszAppID" });
    l_WFSUNDEVMSG.dwSize        = 100;
    SAFEALLOCCOPYSTRING(&l_WFSUNDEVMSG.lpbDescription, std::string{ "lpbDescription" });
    l_WFSUNDEVMSG.dwMsg         = 2024;
    l_WFSUNDEVMSG.lpWFSResult   = &l_WFSResult;

    // normal constructor
    __N_XFSAPI_W__::_wfs_undevmsg_w l_WFSUNDEVMSG_w_1{ &l_WFSUNDEVMSG };
    compare(l_WFSUNDEVMSG_w_1, l_WFSUNDEVMSG);

    // copy constructor
    __N_XFSAPI_W__::_wfs_undevmsg_w l_WFSUNDEVMSG_w_2{ l_WFSUNDEVMSG_w_1 };
    compare(l_WFSUNDEVMSG_w_2, l_WFSUNDEVMSG);

    // move constructor
    __N_XFSAPI_W__::_wfs_undevmsg_w l_WFSUNDEVMSG_w_3{ std::move(l_WFSUNDEVMSG_w_1) };
    compare(l_WFSUNDEVMSG_w_3, l_WFSUNDEVMSG);

    // copy assignment
    __N_XFSAPI_W__::_wfs_undevmsg_w l_WFSUNDEVMSG_w_4{};
    l_WFSUNDEVMSG_w_4 = l_WFSUNDEVMSG_w_1;
    compare(l_WFSUNDEVMSG_w_4, l_WFSUNDEVMSG);

    // move assignment
    __N_XFSAPI_W__::_wfs_undevmsg_w l_WFSUNDEVMSG_w_5{};
    l_WFSUNDEVMSG_w_5 = std::move(l_WFSUNDEVMSG_w_1);
    compare(l_WFSUNDEVMSG_w_5, l_WFSUNDEVMSG);
}

TEST(_wfs_appdisc_w, constructors)
{
    auto compare = [] (const __N_XFSAPI_W__::_wfs_appdisc_w& obj_1, const WFSAPPDISC& obj_2) {
        EXPECT_EQ(std::string{ obj_1.lpszLogicalName }, std::string{ obj_2.lpszLogicalName });
        EXPECT_EQ(std::string{ obj_1.lpszWorkstationName }, std::string{ obj_2.lpszWorkstationName });
        EXPECT_EQ(std::string{ obj_1.lpszAppID }, std::string{ obj_2.lpszAppID });
    };

    WFSAPPDISC l_WFSAPPDisc{};
    SAFEALLOCCOPYSTRING(&l_WFSAPPDisc.lpszLogicalName, std::string{ "lpszLogicalName" });
    SAFEALLOCCOPYSTRING(&l_WFSAPPDisc.lpszWorkstationName, std::string{ "lpszWorkstationName" });
    SAFEALLOCCOPYSTRING(&l_WFSAPPDisc.lpszAppID, std::string{ "lpszAppID" });

    // normal constructor
    __N_XFSAPI_W__::_wfs_appdisc_w l_WFSAPPDisc_w_1{ &l_WFSAPPDisc };
    compare(l_WFSAPPDisc_w_1, l_WFSAPPDisc);

    // copy constructor
    __N_XFSAPI_W__::_wfs_appdisc_w l_WFSAPPDisc_w_2{ l_WFSAPPDisc_w_1 };
    compare(l_WFSAPPDisc_w_2, l_WFSAPPDisc);

    // move constructor
    __N_XFSAPI_W__::_wfs_appdisc_w l_WFSAPPDisc_w_3{ std::move(l_WFSAPPDisc_w_1) };
    compare(l_WFSAPPDisc_w_3, l_WFSAPPDisc);

    // copy assignment
    __N_XFSAPI_W__::_wfs_appdisc_w l_WFSAPPDisc_w_4{};
    l_WFSAPPDisc_w_4 = l_WFSAPPDisc_w_1;
    compare(l_WFSAPPDisc_w_4, l_WFSAPPDisc);

    // move assignment
    __N_XFSAPI_W__::_wfs_appdisc_w l_WFSAPPDisc_w_5{};
    l_WFSAPPDisc_w_5 = std::move(l_WFSAPPDisc_w_1);
    compare(l_WFSAPPDisc_w_5, l_WFSAPPDisc);
}

TEST(_wfs_hwerror_w, constructors)
{
    auto compare = [] (const __N_XFSAPI_W__::_wfs_hwerror_w& obj_1, const WFSHWERROR& obj_2) {
        EXPECT_EQ(std::string{ obj_1.lpszLogicalName }, std::string{ obj_2.lpszLogicalName });
        EXPECT_EQ(std::string{ obj_1.lpszPhysicalName }, std::string{ obj_2.lpszPhysicalName });
        EXPECT_EQ(std::string{ obj_1.lpszWorkstationName }, std::string{ obj_2.lpszWorkstationName });
        EXPECT_EQ(std::string{ obj_1.lpszAppID }, std::string{ obj_2.lpszAppID });
        EXPECT_EQ(obj_1.dwAction, obj_2.dwAction);
        EXPECT_EQ(obj_1.dwSize, obj_2.dwSize);
        EXPECT_EQ(std::string{ (char*)obj_1.lpbDescription }, std::string{ (char*)obj_2.lpbDescription });
    };

    WFSHWERROR l_WFSHWError{};    
    SAFEALLOCCOPYSTRING(&l_WFSHWError.lpszLogicalName, std::string{ "lpszLogicalName" });
    SAFEALLOCCOPYSTRING(&l_WFSHWError.lpszPhysicalName, std::string{ "lpszPhysicalName" });
    SAFEALLOCCOPYSTRING(&l_WFSHWError.lpszWorkstationName, std::string{ "lpszWorkstationName" });
    SAFEALLOCCOPYSTRING(&l_WFSHWError.lpszAppID, std::string{ "lpszAppID" });
    l_WFSHWError.dwAction      = 101;
    l_WFSHWError.dwSize        = 102;
    SAFEALLOCCOPYSTRING(&l_WFSHWError.lpbDescription, std::string{ "lpbDescription" });

    // normal constructor
    __N_XFSAPI_W__::_wfs_hwerror_w l_WFSHWError_w_1{ &l_WFSHWError };
    compare(l_WFSHWError_w_1, l_WFSHWError);

    // copy constructor
    __N_XFSAPI_W__::_wfs_hwerror_w l_WFSHWError_w_2{ l_WFSHWError_w_1 };
    compare(l_WFSHWError_w_2, l_WFSHWError);

    // move constructor
    __N_XFSAPI_W__::_wfs_hwerror_w l_WFSHWError_w_3{ std::move(l_WFSHWError_w_1) };
    compare(l_WFSHWError_w_3, l_WFSHWError);

    // copy assignment
    __N_XFSAPI_W__::_wfs_hwerror_w l_WFSHWError_w_4{};
    l_WFSHWError_w_4 = l_WFSHWError_w_1;
    compare(l_WFSHWError_w_4, l_WFSHWError);

    // move assignment
    __N_XFSAPI_W__::_wfs_hwerror_w l_WFSHWError_w_5{};
    l_WFSHWError_w_5 = std::move(l_WFSHWError_w_1);
    compare(l_WFSHWError_w_5, l_WFSHWError);
}

TEST(_wfs_vrsnerror_w, constructors)
{
    auto compare_ex = [](const WFSVERSION& obj_1, const WFSVERSION& obj_2) {
        EXPECT_EQ(obj_1.wVersion, obj_2.wVersion);
        EXPECT_EQ(obj_1.wLowVersion, obj_2.wLowVersion);
        EXPECT_EQ(obj_1.wHighVersion, obj_2.wHighVersion);
        EXPECT_EQ(std::string{ obj_1.szDescription }, std::string{ obj_2.szDescription });
        EXPECT_EQ(std::string{ obj_1.szSystemStatus }, std::string{ obj_2.szSystemStatus });
    };

    auto compare = [compare_ex] (const __N_XFSAPI_W__::WFSVRSNERROR_W& obj_1, const WFSVRSNERROR& obj_2) {
        EXPECT_EQ(std::string{ obj_1.lpszLogicalName }, std::string{ obj_2.lpszLogicalName });
        EXPECT_EQ(std::string{ obj_1.lpszWorkstationName }, std::string{ obj_2.lpszWorkstationName });
        EXPECT_EQ(std::string{ obj_1.lpszAppID }, std::string{ obj_2.lpszAppID });
        EXPECT_EQ(obj_1.dwSize, obj_2.dwSize);
        EXPECT_EQ(std::string{ (char*)obj_1.lpbDescription }, std::string{ (char*)obj_2.lpbDescription });
        compare_ex(*obj_1.lpWFSVersion, *obj_2.lpWFSVersion);
    };

    WFSVERSION l_WFSVersion{};
    l_WFSVersion.wVersion              = 310;
    l_WFSVersion.wLowVersion           = 300;
    l_WFSVersion.wHighVersion          = 330;
    SAFECOPYMEMORY(l_WFSVersion.szDescription, "szDescription", WFSDDESCRIPTION_LEN + 1);
    SAFECOPYMEMORY(l_WFSVersion.szSystemStatus, "szSystemStatus", WFSDSYSSTATUS_LEN + 1);

    WFSVRSNERROR l_WFSVRSNError{};    
    SAFEALLOCCOPYSTRING(&l_WFSVRSNError.lpszLogicalName, std::string{ "lpszLogicalName" });
    SAFEALLOCCOPYSTRING(&l_WFSVRSNError.lpszWorkstationName, std::string{ "lpszWorkstationName" });
    SAFEALLOCCOPYSTRING(&l_WFSVRSNError.lpszAppID, std::string{ "lpszAppID" });
    l_WFSVRSNError.dwSize               = 100;
    SAFEALLOCCOPYSTRING(&l_WFSVRSNError.lpbDescription, std::string{ "lpbDescription" });
    l_WFSVRSNError.lpWFSVersion = new __N_XFSAPI_W__::WFSVERSION_W{ &l_WFSVersion };

    // normal constructor
    __N_XFSAPI_W__::_wfs_vrsnerror_w l_WFSVRSNError_w_1{ &l_WFSVRSNError };
    compare(l_WFSVRSNError_w_1, l_WFSVRSNError);

    // copy constructor
    __N_XFSAPI_W__::_wfs_vrsnerror_w l_WFSVRSNError_w_2{ l_WFSVRSNError_w_1 };
    compare(l_WFSVRSNError_w_2, l_WFSVRSNError);

    // move constructor
    __N_XFSAPI_W__::_wfs_vrsnerror_w l_WFSVRSNError_w_3{ std::move(l_WFSVRSNError_w_1) };
    compare(l_WFSVRSNError_w_3, l_WFSVRSNError);

    // copy assignment
    __N_XFSAPI_W__::_wfs_vrsnerror_w l_WFSVRSNError_w_4{};
    l_WFSVRSNError_w_4 = l_WFSVRSNError_w_1;
    compare(l_WFSVRSNError_w_4, l_WFSVRSNError);

    // move assignment
    __N_XFSAPI_W__::_wfs_vrsnerror_w l_WFSVRSNError_w_5{};
    l_WFSVRSNError_w_5 = std::move(l_WFSVRSNError_w_1);
    compare(l_WFSVRSNError_w_5, l_WFSVRSNError);
}

#endif // !__H_GTEST_WFSAPI_STRUCTURES__