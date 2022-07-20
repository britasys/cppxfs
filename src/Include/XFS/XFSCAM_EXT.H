#ifndef __INC_XFSCAM_EXT__H
#define __INC_XFSCAM_EXT__H

#ifdef __cplusplus
extern "C" {
#endif

#include "xfsapi.h"

/*   be aware of alignment   */
#pragma pack(push,1)


/* CAM Execute Commands */
#define WFS_CMD_CAM_DISPLAY						(CAM_SERVICE_OFFSET + 3)

/* indices of WFSCAMSTATUS.fwMedia[...]
WFSCAMSTATUS.fwCameras [...]
WFSCAMSTATUS.fwPictures[...]
WFSCAMCAPS.fwCameras [...]
	WFSCAMTAKEPICT.wCamera */
#define WFS_CAM_EXTRA							(3)
#define WFS_CAM_HIGHCAMERA						(4)
	

//	值为0,1,2,3,4,5,6,7分别对应 "All"， "A4"，"A5"，"A6"，"A7"，"名片"，"身份证"，"自定义"
/* values of WFSCAMTAKEPICT.wScanSize */
#define WFS_CAM_SIZEALL							(0)
#define WFS_CAM_SIZEA4 							(1)
#define WFS_CAM_SIZEA5 							(2)
#define WFS_CAM_SIZEA6 							(3)
#define WFS_CAM_SIZEA7                                                  (4)
#define WFS_CAM_SIZECALLINGCARD 				(5)
#define WFS_CAM_SIZEID 							(6)
#define WFS_CAM_SIZECUSTOM 						(7)
#define WFS_CAM_SIZEAJUSTEDTOWINDOW				(8)
#define WFS_CAM_SIZEAJUSTEDTOFRAME				(9)
	/* values of LPWFSCAMWINDEXEC.wDisplay */  //新增
#define WFS_CAM_CREATE							(0)      //显示录像
#define WFS_CAM_DESTROY							(1)      //隐藏录像显示
#define WFS_CAM_PAUSE							(2)		// Pause the display window
#define WFS_CAM_RESUME							(3)		// Resume the paused to display window
	
/* XFS CAM Errors */
#define WFS_ERR_CAM_SYNTAX						(-(CAM_SERVICE_OFFSET + 4))     //新增错误码，使用了不正确的输入参数


/*=================================================================*/
/* CAM Execute Command Structures */
/*=================================================================*/

typedef struct _wfs_cam_take_picture_ex2
{	
	WORD wCamera;
	LPSTR lpszCamData;
	LPWSTR lpszUNICODECamData;
	LPSTR lpstrPath;      //新增，图片存储路径
	WORD wScanSize;      //新增 图像控制参数

} WFSCAMTAKEPICTEX2, *LPWFSCAMTAKEPICTEX2;


typedef struct _wfs_cam_take_image_data  //新增结构体  返回的图像数据
{
	WORD wDatalen;                  //数据长度
	LPBYTE lpData;                  //数据
} WFSCAMIMAGDATA, *LPWFSCAMIMAGDATA;

typedef struct _wfs_cam_display       //新增结构体 摄像头显示结构体
{
	WORD wCamera;         //指定的摄像头
	WORD wAction;        //创建或销毁指定摄像头的录像显示窗口
	WORD wWidth;         //指窗口宽度
	WORD wHeight;        //窗口高度
	WORD wX;             //窗口左上角的x坐标
	WORD wY;             //创建的窗口左上角的y坐标
	DWORD hWnd;			 //the handle of window
} WFSCAMDISP, *LPWFSCAMDISP;

	
	
/* restore alignment */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif	/* __INC_XFSCAM_EXT__H*/

