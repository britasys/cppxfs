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
	

//	ֵΪ0,1,2,3,4,5,6,7�ֱ��Ӧ "All"�� "A4"��"A5"��"A6"��"A7"��"��Ƭ"��"����֤"��"�Զ���"
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
	/* values of LPWFSCAMWINDEXEC.wDisplay */  //����
#define WFS_CAM_CREATE							(0)      //��ʾ¼��
#define WFS_CAM_DESTROY							(1)      //����¼����ʾ
#define WFS_CAM_PAUSE							(2)		// Pause the display window
#define WFS_CAM_RESUME							(3)		// Resume the paused to display window
	
/* XFS CAM Errors */
#define WFS_ERR_CAM_SYNTAX						(-(CAM_SERVICE_OFFSET + 4))     //���������룬ʹ���˲���ȷ���������


/*=================================================================*/
/* CAM Execute Command Structures */
/*=================================================================*/

typedef struct _wfs_cam_take_picture_ex2
{	
	WORD wCamera;
	LPSTR lpszCamData;
	LPWSTR lpszUNICODECamData;
	LPSTR lpstrPath;      //������ͼƬ�洢·��
	WORD wScanSize;      //���� ͼ����Ʋ���

} WFSCAMTAKEPICTEX2, *LPWFSCAMTAKEPICTEX2;


typedef struct _wfs_cam_take_image_data  //�����ṹ��  ���ص�ͼ������
{
	WORD wDatalen;                  //���ݳ���
	LPBYTE lpData;                  //����
} WFSCAMIMAGDATA, *LPWFSCAMIMAGDATA;

typedef struct _wfs_cam_display       //�����ṹ�� ����ͷ��ʾ�ṹ��
{
	WORD wCamera;         //ָ��������ͷ
	WORD wAction;        //����������ָ������ͷ��¼����ʾ����
	WORD wWidth;         //ָ���ڿ���
	WORD wHeight;        //���ڸ߶�
	WORD wX;             //�������Ͻǵ�x����
	WORD wY;             //�����Ĵ������Ͻǵ�y����
	DWORD hWnd;			 //the handle of window
} WFSCAMDISP, *LPWFSCAMDISP;

	
	
/* restore alignment */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif	/* __INC_XFSCAM_EXT__H*/
