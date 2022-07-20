#ifndef _AraScanAPI_H_
#define _AraScanAPI_H_

#include "Windef.h"

//return code
//General code
#define  GEN_SUCCEDED				   0    //�ɹ� 
#define  GEN_PAR_ERR				-900	//�������󣬸��������Ĳ����д���
#define  GEN_MEM_ERR				-901	//�ڴ����ʧ�ܣ�û�з��䵽�㹻���ڴ档
#define  GEN_FUC_FAIL				-902	//����δʵ�֣���֧�ָù���
#define  GEN_ILLEGAL_ERR			-903	//�Ƿ��Ĵ���š�
#define  GEN_OTHER_ERR				-910	//��������

//Device
#define  DEV_NOT_FIND				-100	//�豸�����ڡ���ʼ����ʱ�򣬼�⵽�豸�����ڡ�
#define  DEV_NOT_AUTHORIZE          -101    //�豸û����Ȩ
#define  DEV_NOT_INIT				-102	//�豸δ��ʼ����
#define  DEV_NOT_OPEN				-103	//�豸δ�򿪡�
#define  DEV_BEGIN_FAIL				-110	//׼���ɼ�һ֡ͼ��ʧ�ܣ���ǰ���ڻ�ȡͼ����
#define  DEV_NOT_CALL_BEGIN	        -111	//δ����׼��һ֡ͼ��
#define  DEV_GET_IMA_FAIL			-112	//��ȡͼ��ʧ��
#define  DEV_GET_IMA_TIMEOUT		-113	//��ȡͼ��ʱ

//Arithmetic
#define   ALG_BIONE_INIT_FAIL		-200 	//��ʼ��ָ���㷨ʧ��
#define   ALG_IMG_BUF_NO_DATA		-210	//ͼ�񻺳���û����Чָ������
#define   ALG_IMG_QUALITY_LOW		-211	//ͼ������̫��
#define   ALG_INVALID_BMP_DATA		-212    //������Ч��BMP����
#define   ALG_BIONE_NOT_INIT        -220	//�㷨��δ��ʼ��
#define   ALG_EXTRACT_FEATURE_FAIL  -221	//��ȡָ������ʧ��
#define   ALG_GEN_TEMPLATE_FAIL     -222	//����ָ��ģ��ʧ��
#define   ALG_VERIFY_FAIL           -230	//ָ�Ʊȶ�ʧ��




//Function
//1��ʼ���ɼ��豸
int __stdcall ARAFPSCAN_DeviceInit();
//2�ͷŲɼ��豸
int __stdcall ARAFPSCAN_DeviceFree();

//3��ȡ�ɼ��豸����
int __stdcall ARAFPSCAN_GetDeviceCount();
//4 �򿪲ɼ��豸
int __stdcall ARAFPSCAN_OpenDevice(HANDLE *nHandle,int nIndex);
//5 �رղɼ��豸
int __stdcall ARAFPSCAN_CloseDevice(HANDLE nHandle);

//6 ��ȡ�豸��Ϣ
//************************************
// Method:    ARAFPSCAN_GetDeviceInfo
// FullName:  ARAFPSCAN_GetDeviceInfo
// Access:    public 
// Returns:   int __stdcall
//			0����ȡ�汾��Ϣ�ɹ�
//			-100���豸������
//			-102���豸δ��ʼ��
//			-103���豸δ��
//			-900����������
//			-910����������
// Parameter: HANDLE nHandle �򿪲ɼ��豸ʱ���صľ����
// Parameter: char pszDevInfor[100] ����豸��ص���Ϣ
// Instruction����ȡ�豸�����Ϣ��
//	�����豸���롢�ӿڰ汾��Ϣ���豸���кź��豸������Ϣ��
//  �豸���볤��Ϊ1���ֽڣ��ӿڰ汾��Ϣ�10�ֽڣ��豸���к��20���ֽڣ��豸������˳��Ϊ���ҡ��豸���ơ��ͺţ��69���ֽڣ�����������֮���á�,���ָ�磺��0xFF,1.0.0.1,,������,�뵼�����ָ�Ʋɼ���,TL-FRT610��������ֵ�е������ַ��������UTF���ܵ��豸��Ϣ�100���ֽڡ�
//************************************
int __stdcall ARAFPSCAN_GetDeviceInfo(HANDLE nHandle, char pszDevInfo[100]);

//7 ��ȡͼ����Ϣ
int __stdcall ARAFPSCAN_GetImageInfo(HANDLE nHandle, int *pnWidth, int *pnHeight, int *pnDpi);
//8 ׼���ɼ�һָ֡��ͼ��
int __stdcall ARAFPSCAN_BeginCapture(HANDLE nHandle);
//9 �ɼ�һ֡RAWָ��ͼ��
int __stdcall ARAFPSCAN_GetFPRawData (HANDLE nHandle,int nTimeout, unsigned char *pRawData);
//10 �ɼ�һ֡BMPָ��ͼ��
int __stdcall ARAFPSCAN_GetFPBmpData(HANDLE nHandle, int nTimeout ,unsigned char *pBmpData);

//11 ����LED״̬
int __stdcall ARAFPSCAN_SetLedStatus(HANDLE nHandle , int nLed, int nStatus);
//12  ��ȡLED״̬
int __stdcall ARAFPSCAN_GetLedStatus(HANDLE nHandle , int nLed, int *pnStatus);

//13  ��ʼ��ָ���㷨
int __stdcall ARAFPSCAN_BioneInit(HANDLE *nHandle); 
//14  �ͷ�ָ���㷨 
int __stdcall ARAFPSCAN_BioneFree(HANDLE nHandle);

//15  ��ȡָ������
int __stdcall  ARAFPSCAN_FeatureExtract(HANDLE nHandle, unsigned char cFingerPos, unsigned char * pFeatureData);

//16 ����ָ��ģ��
int __stdcall ARAFPSCAN_TemplateGeneralize(HANDLE nHandle, unsigned char * pFeatureData1,	unsigned char * pFeatureData2, 
	unsigned char * pFeatureData3, unsigned char * pTemplateData);

//17 ԭʼͼ������תBMP��ʽ����
int __stdcall ARAFPSCAN_RawToBmp(unsigned char* pRawData ,
							   unsigned char* pBmpData,
							   int nWidth, int nHeight);
//18 BMP��ʽ����תԭʼͼ����
int __stdcall ARAFPSCAN_BmpToRaw(unsigned char* pBmpData,
							   unsigned  char* pRawData, 
							   int *pnWidth,int *pnHeight);



//19 ��ȡ������Ϣ
int __stdcall ARAFPSCAN_GetErrorInfo(int nErrorNo, char pszErrorInfo[256]);


//20 ��ȡͼ������
int __stdcall ARAFPSCAN_ImgQuality(int width,int height,BYTE *ipImage,BYTE *Quality);

//21 ָ�Ʊȶ�
int __stdcall ARAFPSCAN_Verify(HANDLE nHandle,int Security_Level,unsigned char * pFeatureData, unsigned char * pTemplateData, int *sc);
int __stdcall ARAFPSCAN_VerifyAll(HANDLE nHandle,int Security_Level,unsigned char * pFeatureData,int fealen, unsigned char * pTemplateData,int temlen, int *sc);

//22 �ȶԶ���֤����
int __stdcall ARAFPSCAN_IDCardVerify(HANDLE nHandle,int Security_Level,unsigned char * pIDCardFeatureData, unsigned char * pFingerFeature, int *sc);


//23 ��RAW��ʽ�л�ȡ����
int __stdcall ARAFPSCAN_FeatureExtractFromRAW(HANDLE nHandle,int width,int height, unsigned char cFingerPos,unsigned char * RAWData, unsigned char * pFeatureData);

//24 ��ͼ���л�ȡ����
int __stdcall ARAFPSCAN_ImgToFeature (HANDLE nHandle,unsigned char* pImage,int nWidth,int nHeight, unsigned char * pFeatureData);
int __stdcall ARAFPSCAN_FeatureExtract_ISO(HANDLE nHandle, unsigned char cFingerPos, unsigned char * pFeatureData);
int __stdcall ARAFPSCAN_FeatureExtract_ANSI(HANDLE nHandle, unsigned char cFingerPos, unsigned char * pFeatureData);

#pragma comment(lib, "AraFPScanAPI")

#endif
