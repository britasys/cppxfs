/******************************************************************************
* *
* xfsbcr.h XFS - definitions *
* for the Bar Code Reader Unit - services *
* *
* Version 3.00 (10/01/05) *
* *
******************************************************************************/

#ifndef __INC_XFSBCR__H
#define __INC_XFSBCR__H

#ifdef __cplusplus
extern "C" {
#endif

#include "xfsapi.h"

/* be aware of alignment */
#pragma     pack(push, 1)

/* values of WFSBCRCAPS.wClass */
#define     WFS_SERVICE_CLASS_BCR                   (15)
#define     WFS_SERVICE_CLASS_NAME_BCR              "BCR"
#define     WFS_SERVICE_CLASS_VERSION_BCR           (0x0003)

#define     BCR_SERVICE_OFFSET                      (WFS_SERVICE_CLASS_BCR * 100)

/* BCR Info Commands */
#define     WFS_INF_BCR_STATUS                      (BCR_SERVICE_OFFSET + 1)
#define     WFS_INF_BCR_CAPABILITIES                (BCR_SERVICE_OFFSET + 2)

/* BCR Execute Commands */
#define     WFS_CMD_BCR_READ                        (BCR_SERVICE_OFFSET + 1)
#define     WFS_CMD_BCR_RESET                       (BCR_SERVICE_OFFSET + 2)
#define     WFS_CMD_BCR_SET_GUIDANCE_LIGHT          (BCR_SERVICE_OFFSET + 3)

/* BCR Messages */
/* Values of WFSBCRSTATUS.fwDevice */
#define     WFS_BCR_DEVONLINE                       WFS_STAT_DEVONLINE
#define     WFS_BCR_DEVOFFLINE                      WFS_STAT_DEVOFFLINE
#define     WFS_BCR_DEVPOWEROFF                     WFS_STAT_DEVPOWEROFF
#define     WFS_BCR_DEVNODEVICE                     WFS_STAT_DEVNODEVICE
#define     WFS_BCR_DEVHWERROR                      WFS_STAT_DEVHWERROR
#define     WFS_BCR_DEVUSERERROR                    WFS_STAT_DEVUSERERROR
#define     WFS_BCR_DEVBUSY                         WFS_STAT_DEVBUSY
#define     WFS_BCR_DEVFRAUDATTEMPT                 WFS_STAT_DEVFRAUDATTEMPT

/* Values of WFSBCRSTATUS.fwBCRScanner */
#define     WFS_BCR_SCANNERON                       (0)
#define     WFS_BCR_SCANNEROFF                      (1)
#define     WFS_BCR_SCANNERINOP                     (2)
#define     WFS_BCR_SCANNERUNKNOWN                  (3)

/* values of WFSBCRCAPS.lpwBarCodeList
WFSBCRCODELIST.lpwCodeList
WFSBCRREAD.lpwCodeFormat */
#define     WFS_BCR_BARCODE_EAN128                  (1)
#define     WFS_BCR_BARCODE_EAN8_13                 (2)
#define     WFS_BCR_BARCODE_JAN8_13                 (3)
#define     WFS_BCR_BARCODE_EAN8_132                (4)
#define     WFS_BCR_BARCODE_EAN8_135                (5)
#define     WFS_BCR_BARCODE_UPCA_E                  (6)
#define     WFS_BCR_BARCODE_UPCA_E2                 (7)
#define     WFS_BCR_BARCODE_UPCA_E5                 (8)
#define     WFS_BCR_BARCODE_NW_7                    (9)
#define     WFS_BCR_BARCODE_ITF                     (10)
#define     WFS_BCR_BARCODE_11                      (11)
#define     WFS_BCR_BARCODE_39                      (12)
#define     WFS_BCR_BARCODE_49                      (13)
#define     WFS_BCR_BARCODE_93                      (14)
#define     WFS_BCR_BARCODE_MSIPLESSEY              (15)
#define     WFS_BCR_BARCODE_STD2OF5                 (16)
#define     WFS_BCR_BARCODE_IND2OF5                 (17)
#define     WFS_BCR_BARCODE_POSNET                  (18)
#define     WFS_BCR_BARCODE_PDF_417                 (19)
#define     WFS_BCR_BARCODE_DATAMATRIX              (20)
#define     WFS_BCR_BARCODE_MAXICODE                (21)
#define     WFS_BCR_BARCODE_CODEONE                 (22)
#define     WFS_BCR_BARCODE_CHANNELCODE             (23)

/* Size and max index of fwGuidLights array */
#define     WFS_BCR_GUIDLIGHTS_SIZE                 (32)
#define     WFS_BCR_GUIDLIGHTS_MAX                  (WFS_BCR_GUIDLIGHTS_SIZE - 1)

/* Indices of WFSBCRSTATUS.fwGuidLights [...]
WFSBCRCAPS.fwGuidLights [...] */
#define     WFS_BCR_GUIDANCE_BCR                    (0)

/* Values of WFSBCRSTATUS.fwGuidLights [...]
WFSBCRCAPS.fwGuidLights [...] */
#define     WFS_BCR_GUIDANCE_OFF                    (0x00000001)
#define     WFS_BCR_GUIDANCE_ON                     (0x00000002)
#define     WFS_BCR_GUIDANCE_SLOW_FLASH             (0x00000004)
#define     WFS_BCR_GUIDANCE_MEDIUM_FLASH           (0x00000008)
#define     WFS_BCR_GUIDANCE_QUICK_FLASH            (0x00000010)
#define     WFS_BCR_GUIDANCE_CONTINUOUS             (0x00000080)
#define     WFS_BCR_GUIDANCE_RED                    (0x00000100)
#define     WFS_BCR_GUIDANCE_GREEN                  (0x00000200)
#define     WFS_BCR_GUIDANCE_YELLOW                 (0x00000400)
#define     WFS_BCR_GUIDANCE_BLUE                   (0x00000800)
#define     WFS_BCR_GUIDANCE_CYAN                   (0x00001000)
#define     WFS_BCR_GUIDANCE_MAGENTA                (0x00002000)
#define     WFS_BCR_GUIDANCE_WHITE                  (0x00004000)

/* Values of WFSBCRSTATUS.fwGuidLights [...]
WFSBCRCAPS.fwGuidLights [...] */
#define     WFS_BCR_GUIDANCE_NOT_AVAILABLE          (0x00000000)

/* XFS BCR Errors */
#define     WFS_ERR_BCR_BARCODEINVALID              (-(BCR_SERVICE_OFFSET + 0))
#define     WFS_ERR_BCR_INVALID_PORT                (-(BCR_SERVICE_OFFSET + 1))

/*=================================================================*/
/* BCR Info Command Structures */
/*=================================================================*/

typedef struct _wfs_bcr_status
{
    WORD        fwDevice;
    WORD        fwBCRScanner;
    DWORD       dwGuidLights[WFS_BCR_GUIDLIGHTS_SIZE];
    LPSTR       lpszExtra;
} WFSBCRSTATUS, * LPWFSBCRSTATUS;
typedef struct _wfs_bcr_caps
{
    WORD        wClass;
    BOOL        bCompound;
    BOOL        bFormatDiscrimine;
    LPWORD      lpwBarCodeList;
    DWORD       dwGuidLights[WFS_BCR_GUIDLIGHTS_SIZE];
    LPSTR       lpszExtra;
} WFSBCRCAPS, * LPWFSBCRCAPS;

/*=================================================================*/
/* BCR Execute Command Structures */
/*=================================================================*/

typedef struct _wfs_bcr_read_input
{
    LPWORD      lpwCodeList;
} WFSBCRREADINPUT, * LPWFSBCRREADINPUT;
typedef struct _wfs_bcr_read_OUTPUT
{
    WORD        wCodeFormat;
    LPWSTR      lpszCodeData;
} WFSBCRREADOUTPUT, * LPWFSBCRREADOUTPUT;
typedef struct _wfs_bcr_set_guidlight
{
    WORD        wGuidLight;
    DWORD       dwCommand;
} WFSBCRSETGUIDLIGHT, * LPWFSBCRSETGUIDLIGHT;

/* restore alignment */
#pragma pack(pop)

#ifdef __cplusplus
} /*extern "C"*/

#endif

#endif /* __INC_XFSBCR__H */
