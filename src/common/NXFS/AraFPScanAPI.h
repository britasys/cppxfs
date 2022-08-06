#ifndef _AraScanAPI_H_
#define _AraScanAPI_H_

#include "Windef.h"

//return code
//General code
#define  GEN_SUCCEDED				   0    //成功 
#define  GEN_PAR_ERR				-900	//参数错误，给定函数的参数有错误。
#define  GEN_MEM_ERR				-901	//内存分配失败，没有分配到足够的内存。
#define  GEN_FUC_FAIL				-902	//功能未实现，或不支持该功能
#define  GEN_ILLEGAL_ERR			-903	//非法的错误号。
#define  GEN_OTHER_ERR				-910	//其他错误

//Device
#define  DEV_NOT_FIND				-100	//设备不存在。初始化的时候，检测到设备不存在。
#define  DEV_NOT_AUTHORIZE          -101    //设备没有授权
#define  DEV_NOT_INIT				-102	//设备未初始化。
#define  DEV_NOT_OPEN				-103	//设备未打开。
#define  DEV_BEGIN_FAIL				-110	//准备采集一帧图像失败，当前正在获取图像中
#define  DEV_NOT_CALL_BEGIN	        -111	//未调用准备一帧图像
#define  DEV_GET_IMA_FAIL			-112	//获取图像失败
#define  DEV_GET_IMA_TIMEOUT		-113	//获取图像超时

//Arithmetic
#define   ALG_BIONE_INIT_FAIL		-200 	//初始化指纹算法失败
#define   ALG_IMG_BUF_NO_DATA		-210	//图像缓冲区没有有效指纹数据
#define   ALG_IMG_QUALITY_LOW		-211	//图像质量太差
#define   ALG_INVALID_BMP_DATA		-212    //不是有效的BMP数据
#define   ALG_BIONE_NOT_INIT        -220	//算法库未初始化
#define   ALG_EXTRACT_FEATURE_FAIL  -221	//提取指纹特征失败
#define   ALG_GEN_TEMPLATE_FAIL     -222	//生成指纹模板失败
#define   ALG_VERIFY_FAIL           -230	//指纹比对失败




//Function
//1初始化采集设备
int __stdcall ARAFPSCAN_DeviceInit();
//2释放采集设备
int __stdcall ARAFPSCAN_DeviceFree();

//3获取采集设备数量
int __stdcall ARAFPSCAN_GetDeviceCount();
//4 打开采集设备
int __stdcall ARAFPSCAN_OpenDevice(HANDLE *nHandle,int nIndex);
//5 关闭采集设备
int __stdcall ARAFPSCAN_CloseDevice(HANDLE nHandle);

//6 获取设备信息
//************************************
// Method:    ARAFPSCAN_GetDeviceInfo
// FullName:  ARAFPSCAN_GetDeviceInfo
// Access:    public 
// Returns:   int __stdcall
//			0：获取版本信息成功
//			-100：设备不存在
//			-102：设备未初始化
//			-103：设备未打开
//			-900：参数错误
//			-910：其他错误
// Parameter: HANDLE nHandle 打开采集设备时返回的句柄。
// Parameter: char pszDevInfor[100] 输出设备相关的信息
// Instruction：获取设备相关信息。
//	包括设备编码、接口版本信息、设备序列号和设备描述信息。
//  设备编码长度为1个字节，接口版本信息最长10字节，设备序列号最长20个字节，设备描述按顺序为厂家、设备名称、型号，最长69个字节；各个数据项之间用“,”分割。如：“0xFF,1.0.0.1,,亚略特,半导体活体指纹采集仪,TL-FRT610”。返回值中的中文字符编码采用UTF，总的设备信息最长100个字节。
//************************************
int __stdcall ARAFPSCAN_GetDeviceInfo(HANDLE nHandle, char pszDevInfo[100]);

//7 获取图像信息
int __stdcall ARAFPSCAN_GetImageInfo(HANDLE nHandle, int *pnWidth, int *pnHeight, int *pnDpi);
//8 准备采集一帧指纹图像
int __stdcall ARAFPSCAN_BeginCapture(HANDLE nHandle);
//9 采集一帧RAW指纹图像
int __stdcall ARAFPSCAN_GetFPRawData (HANDLE nHandle,int nTimeout, unsigned char *pRawData);
//10 采集一帧BMP指纹图像
int __stdcall ARAFPSCAN_GetFPBmpData(HANDLE nHandle, int nTimeout ,unsigned char *pBmpData);

//11 设置LED状态
int __stdcall ARAFPSCAN_SetLedStatus(HANDLE nHandle , int nLed, int nStatus);
//12  获取LED状态
int __stdcall ARAFPSCAN_GetLedStatus(HANDLE nHandle , int nLed, int *pnStatus);

//13  初始化指纹算法
int __stdcall ARAFPSCAN_BioneInit(HANDLE *nHandle); 
//14  释放指纹算法 
int __stdcall ARAFPSCAN_BioneFree(HANDLE nHandle);

//15  提取指纹特征
int __stdcall  ARAFPSCAN_FeatureExtract(HANDLE nHandle, unsigned char cFingerPos, unsigned char * pFeatureData);

//16 生成指纹模板
int __stdcall ARAFPSCAN_TemplateGeneralize(HANDLE nHandle, unsigned char * pFeatureData1,	unsigned char * pFeatureData2, 
	unsigned char * pFeatureData3, unsigned char * pTemplateData);

//17 原始图像数据转BMP格式数据
int __stdcall ARAFPSCAN_RawToBmp(unsigned char* pRawData ,
							   unsigned char* pBmpData,
							   int nWidth, int nHeight);
//18 BMP格式数据转原始图像数
int __stdcall ARAFPSCAN_BmpToRaw(unsigned char* pBmpData,
							   unsigned  char* pRawData, 
							   int *pnWidth,int *pnHeight);



//19 获取错误信息
int __stdcall ARAFPSCAN_GetErrorInfo(int nErrorNo, char pszErrorInfo[256]);


//20 获取图像质量
int __stdcall ARAFPSCAN_ImgQuality(int width,int height,BYTE *ipImage,BYTE *Quality);

//21 指纹比对
int __stdcall ARAFPSCAN_Verify(HANDLE nHandle,int Security_Level,unsigned char * pFeatureData, unsigned char * pTemplateData, int *sc);
int __stdcall ARAFPSCAN_VerifyAll(HANDLE nHandle,int Security_Level,unsigned char * pFeatureData,int fealen, unsigned char * pTemplateData,int temlen, int *sc);

//22 比对二代证特征
int __stdcall ARAFPSCAN_IDCardVerify(HANDLE nHandle,int Security_Level,unsigned char * pIDCardFeatureData, unsigned char * pFingerFeature, int *sc);


//23 从RAW格式中获取特征
int __stdcall ARAFPSCAN_FeatureExtractFromRAW(HANDLE nHandle,int width,int height, unsigned char cFingerPos,unsigned char * RAWData, unsigned char * pFeatureData);

//24 从图像中获取特征
int __stdcall ARAFPSCAN_ImgToFeature (HANDLE nHandle,unsigned char* pImage,int nWidth,int nHeight, unsigned char * pFeatureData);
int __stdcall ARAFPSCAN_FeatureExtract_ISO(HANDLE nHandle, unsigned char cFingerPos, unsigned char * pFeatureData);
int __stdcall ARAFPSCAN_FeatureExtract_ANSI(HANDLE nHandle, unsigned char cFingerPos, unsigned char * pFeatureData);

#pragma comment(lib, "AraFPScanAPI")

#endif
