#pragma once

#ifndef __INC_XFSCUSTOM__H
#define __INC_XFSCUSTOM__H

#ifdef __cplusplus
extern "C" {
#endif

/* be aware of alignment */
#pragma pack(push, 1)

#define WFS_INF_CRM_CASHINFO_TRANSINFO		(CIM_SERVICE_OFFSET + 51)

#define WFS_CRM_JOURNALNO_LEN				32
#define WFS_CRM_ACCOUNTNO_LEN				48
#define WFS_CRM_IMAGEFILENAME_LEN			260
#define WFS_CRM_SERIALNO_LEN				32

/*=================================================================*/
/* CIM Command Structures */
/*=================================================================*/

	typedef struct _wfs_crm_query_transinfo
	{
		char								acJournalNo[WFS_CRM_JOURNALNO_LEN];
		char								acAccountNo[WFS_CRM_ACCOUNTNO_LEN];
		SYSTEMTIME							sDateBegin;
		SYSTEMTIME							sDateEnd;
	} WFSCRMQUERYTRANSINFO, * LPWFSCRMQUERYTRANSINFO;

	typedef struct _wfs_crm_cash_info_details
	{
		SYSTEMTIME							sSysTime;
		char								acJournalNo[WFS_CRM_JOURNALNO_LEN];
		char								acAccountNo[WFS_CRM_ACCOUNTNO_LEN];
		BYTE								byValidation;
		WORD								wDenomination;
		char								acImageFileName[WFS_CRM_IMAGEFILENAME_LEN];
		char								acSerialNo[WFS_CRM_SERIALNO_LEN];
	} WFSCRMCASHINFODETAILS, * LPWFSCRMCASHINFODETAILS;

	typedef struct _wfs_crm_cash_info
	{
		USHORT								usCount;
		LPWFSCRMCASHINFODETAILS*			lppCashInfoDetails;
	} WFSCRMCASHINFO, * LPWFSCRMCASHINFO;

/* restore alignment */
#pragma pack (pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif  /* __INC_XFSCUSTOM__H */

