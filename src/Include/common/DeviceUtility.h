#pragma once

#ifndef DEVICEUTILITY_H
#define DEVICEUTILITY_H

#include <memory>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

#include "NOVACONSTRUCTOR.h"
#include <TTFRM_Include\TTFrameworkUtility.h>
#include <TTLogger\CODE\ITTLogger.h>

#include <Include\XFS\XFSAPI.H>

#define SAFERELEASECONT(cont)					DeviceUtility::SafeReleaseCont(cont);
#define SAFERELEASELPP(lpp, count)				DeviceUtility::SafeReleaseLPP(lpp, count);
#define SAFEFREEMEMORYLPP(lpp, count)			DeviceUtility::SafeFreeMemoryLPP(lpp, count);

namespace DeviceUtility
{
	template <typename T, typename = std::enable_if_t<std::is_pointer<T>::value>>
	using TTCONT = std::deque<T>;

	typedef struct _wfs_lpstr
	{
		LPSTR _lpstr;
	} WFSLPSTR, * LPWFSLPSTR;

	typedef struct _wfs_lpushort
	{
		int _lpushort;
	} WFSUSHORT, * LPWFSUSHORT;

	using USHORTVECT		= std::vector<USHORT>;
	using STRVECT			= std::vector<std::string>;
	
	/************************************************************************/
	/**********************ExceptionFilter Functions*************************/
	/************************************************************************/
	
	static int ExceptionFilter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
	{
		if (code == EXCEPTION_ACCESS_VIOLATION)
		{
			ERRORLOG("caught AV as expected.");
			return EXCEPTION_EXECUTE_HANDLER;
		}
		else
		{
			ERRORLOG("didn't catch AV, unexpected.");
			return EXCEPTION_CONTINUE_SEARCH;
		};
	}

	/************************************************************************/
	/**************************Safe Functions********************************/
	/************************************************************************/

	template <typename CONT>
	static void SafeReleaseCont(CONT& cont)
	{
		for (auto& elem : cont)
			if(elem) delete elem;
	}

	template <typename T>
	static void SafeReleaseLPP(T** &lpp, const size_t count)
	{
		TRACELOG("DeviceUtility::SafeReleaseLPP - Started");

		UNSAFEPTR(lpp)
			return;

		for (size_t i = 0; i < count; ++i)
		{
			SAFEPTR(lpp[i])
			{
				DEBUGLOG("DeviceUtility::SafeReleaseLPP - 0x%08x", lpp[i]);
				if(lpp[i])
					delete lpp[i];
			}
		}

		::free(lpp);
		lpp = nullptr;

		TRACELOG("DeviceUtility::SafeReleaseLPP - Ended");
	}

	static void SafeFreeMemoryLPP(void** &lpp, const size_t count)
	{
		UNSAFEPTR(lpp)
			return;

		for (size_t i = 0; i < count; ++i)
			::free(lpp[i]);

		::free(lpp);
		lpp = nullptr;
	}

	/************************************************************************/
	/*************************Copy Functions*********************************/
	/************************************************************************/

	template <typename T>
	SIZE_T Size_P2NA(const T lpSrc)
	{
		SIZE_T i = 0;
		UNSAFEPTR(lpSrc)
			i = 0;
		ELSE
		{
			T lpTemp = lpSrc;
			__try
			{
				while (lpSrc)
					++i;
			}
			__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
			{
				ERRORLOG("Size_P2NA - EXCEPTION occurred while trying to calculate the size");
			}
			return i + 1;
		}
		return i;
	}

	template <typename TT, typename T>
	static inline void  CopyP2NAPs(TTCONT<TT*>& DestCont, T** lppSrc)
	{
		DestCont.clear();
		SAFEPTR(lppSrc)
		{
			while (*lppSrc)
			{
				TT* _obj = new TT();
				_obj->WFS2TT(*lppSrc);
				DestCont.push_back(_obj);
				lppSrc++;
			}
		}
		return;
	}

	template <typename TT, typename T>
	static inline void  CopyP2APs(TTCONT<TT*>& DestCont, T** lppSrc, unsigned int Count)
	{
		UNSAFEPTR(lppSrc)
			return;
			
		UNSAFEPTR(*lppSrc)
			return;

		DestCont.clear();

		for (unsigned int i = 0; i < Count; i++)
		{
			SAFEPTR(*lppSrc)
			{
				TT* _obj = new TT();
				_obj->WFS2TT(*lppSrc);
				DestCont.push_back(_obj);
				lppSrc++;
			}
		}
		return;
	}

	template <typename TT, typename T>
	static inline void CopyP(TT** lpDest, const T* lpSrc)
	{
		SAFEPTR(lpSrc)
		{
			*lpDest = new TT();
			(*lpDest)->WFS2TT(lpSrc);
		}
		ELSE
			*lpDest = NULL;
	}

	template <typename TT, typename T>
	static inline void  CopyP2NAPs_r(T** &lppDest, const TTCONT<TT*>& SrcCont)
	{
		UNSAFEPTR(lppDest)
			return;

		LPINT _lpTemp = (LPINT)::calloc(1, sizeof(int) * SrcCont.size() + 1);
		lppDest = (T**)_lpTemp;

		for (const auto& elem : SrcCont)
		{
			elem->WFS((T**)_lpTemp);
			_lpTemp++;
		}

		lppDest[SrcCont.size()] = '\0';

		return;
	}

	template <typename TT, typename T>
	static inline void  CopyP2APs_r(T** &lppDest, const TTCONT<TT*>& SrcCont)
	{
		TRACELOG("DeviceUtility::CopyP2APs_r - Started");

		/*UNSAFEPTR(lppDest)
			return;*/

		LPINT _lpTemp = (LPINT)::calloc(1, sizeof(int) * SrcCont.size());
		lppDest = (T**)_lpTemp;

		for (const auto& elem : SrcCont)
		{
			DEBUGLOG("DeviceUtility::CopyP2APs_r - _lpTemp: 0x%08x", _lpTemp);
			elem->WFS((T**)_lpTemp);
			_lpTemp++;
		}


		TRACELOG("DeviceUtility::CopyP2APs_r - Ended");
		return;
	}

	template <typename TT, typename T>
	static inline void CopyP_r(TT** lppDest, T* lpSrc)
	{
		SAFEPTR(lpSrc)
			lpSrc->WFS(lppDest);
		ELSE
			*lppDest = NULL;
	}

	static inline SIZE_T Size_LPWSTR(LPCWSTR lpwStr)
	{
		SIZE_T i = 0;
		UNSAFEPTR(lpwStr)
			i = 0;
		ELSE
		{
			LPCWSTR lpTemp = lpwStr;
			__try
			{
				i = wcslen(lpwStr);
			}
			__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
			{
				ERRORLOG("Size_LPWSTR - EXCEPTION occurred while trying to calculate the size");
			}
		}
		return i;
	}

	static inline SIZE_T Size_LPSTR(LPCSTR lpszStr)
	{
		SIZE_T i = 0;
		UNSAFEPTR(lpszStr)
			i = 0;
		ELSE
		{
			LPCSTR lpTemp = lpszStr;
			__try
			{
				i = strlen(lpszStr);
			}
			__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
			{
				ERRORLOG("Size_LPSTR - EXCEPTION occurred while trying to calculate the size");
			}
		}
		return i;
	}

	static inline SIZE_T Size_LPSTR_NN(LPCSTR lpStr)
	{
		SIZE_T i = 0;
		UNSAFEPTR(lpStr)
			i = 0;
		ELSE
		{
			LPCSTR lpTemp = lpStr;
			__try
			{
				while ((lpTemp[i]) || (lpTemp[i + 1]))
					i++;
			}
			__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
			{
				ERRORLOG("Size_LPSTR_NN - EXCEPTION occurred while trying to calculate the size");
			}
			i += 2;
		}
		return i;
	}

	static void inline Srlz_LPSTR_NN(LPSTR lpDes, LPCSTR lpSrc)
	{
		if (lpSrc == NULL)
			return;
		int _Size = 0;
		_Size = Size_LPSTR_NN(lpSrc);
		CopyMemory(lpDes, lpSrc, _Size);
	}
	
	/************************************************************************/
	/*************************Convert Functions******************************/
	/************************************************************************/
	
	static std::string LPSTRNN2Str(LPCSTR lpSrc)
	{
		SIZE_T i = 0;
		LPSTR lpTemp{ NULL };
		lpTemp = (LPSTR)malloc(Size_LPSTR_NN(lpSrc));
		UNSAFEPTR(lpTemp)
			return "";

		ZeroMemory(lpTemp, Size_LPSTR_NN(lpSrc));
		CopyMemory(lpTemp, lpSrc, Size_LPSTR_NN(lpSrc));
		if (NULL == lpSrc)
		{
			free(lpTemp);
			return "";
		}
		else
		{
			for (i = 0; i < Size_LPSTR_NN(lpSrc) - 1; ++i)
			{
				if (!lpTemp[i])
					lpTemp[i] = '\n';
			}
		}
	
		std::string str(lpTemp);

		free(lpTemp);
	
		return str;
	}
	
	static inline void LPSTRNN2Vector(STRVECT & vecDes, LPSTR lpSrc)
	{
		std::string  strTemp;
		SIZE_T  i = 0;
		SIZE_T  _Index = 0;
	
		SAFEPTR(lpSrc)
		{
			for (i = 0; i < Size_LPSTR_NN(lpSrc) - 1; ++i)
			{
				if (!lpSrc[i])
				{
					strTemp.assign(lpSrc + _Index);
					vecDes.push_back(strTemp);
					strTemp.clear();
					_Index = i + 1;
				}
			}
		}
	}
	
	inline std::string STRVECT2Str(const STRVECT & vecSrc)
	{
		std::stringstream _stream;
		for (const auto & elem : vecSrc)
			_stream << elem << ' ';
		return _stream.str();
	}
	
	inline void STRVECT2LPSTRNN(char** lppsz, const STRVECT& vecSrc)
	{
		ULONG _size = 0;
	
		for (const auto & elem : vecSrc)
		{
			_size += elem.size();
			_size++;
		}
		_size++;
	
		*lppsz = (char*)::malloc(_size);
		::FillMemory(*lppsz, _size, '\0');
	
		for (const auto & elem : vecSrc)
		{
			SAFECOPYMEMORY(*lppsz, elem.c_str(), elem.size());
			*lppsz += elem.size() + 1;
		}
	}
	
	template <typename T>
	inline std::string TTCONT2Str(const TTCONT<T*> & _tt_cont)
	{
		std::ostringstream str;
		for (const auto & elem : _tt_cont)
			str << std::endl << *elem << ' ';
		return str.str();
	}
	
	template <typename LPWFSBUFFER, typename LPOUT, typename std::enable_if_t<std::is_pointer<LPOUT>::value, bool> = true>
	inline void Parse_WFSResult(LPOUT pOut, LPWFSRESULT lpWFSResult)
	{
		TRACELOG("Parse_WFSResult - Started");
	
		LPWFSBUFFER _pWFSBuffer = NULL;
		SAFEPTR(lpWFSResult)
			_pWFSBuffer = (LPWFSBUFFER)lpWFSResult->lpBuffer;
		ELSE
		{
			ERRORLOG("Parse_WFSResult - FAILED because lpWFSResult is NULL");
			return;
		}

		SAFEPTR(pOut)
		{
			SAFEPTR(_pWFSBuffer)
			{
				pOut->WFS2TT((LPWFSBUFFER)_pWFSBuffer);
			}
		}
		ELSE
		{
			ERRORLOG("Parse_WFSResult - FAILED because pOut is NULL");
			return;
		}
	
		std::stringstream stream;
		stream << " OUTPUT DATA -> " << *pOut;
		INFOLOG(stream.str().c_str());
		TRACELOG("Parse_WFSResult - Ended");
	}
	
	template <typename LPWFSBUFFER, typename LPOUT, typename std::enable_if_t<std::is_integral<LPOUT>::value, bool> = true>
	inline void Parse_WFSResult(LPOUT, LPWFSRESULT)
	{
		// Template Specialization for NULL
	}

	template <typename LPTTWFSDATA, typename LPPWFSDATA, typename std::enable_if_t<std::is_pointer<LPTTWFSDATA>::value, bool> = true>
	inline void Parse_WFSInputData(LPPWFSDATA lppWFSOutputData, LPTTWFSDATA lpTTWFSInputData)
	{
		TRACELOG("Parse_WFSInputData - Started");

		UNSAFEPTR(lppWFSOutputData)
			return;
		UNSAFEPTR(lpTTWFSInputData)
			return;

		lpTTWFSInputData->WFS(lppWFSOutputData);

		std::stringstream stream;
		stream << " INPUT DATA -> " << *lpTTWFSInputData;
		INFOLOG(stream.str().c_str());
		TRACELOG("Parse_WFSInputData - Ended");
	}

	template <typename LPTTWFSDATA, typename LPPWFSDATA>
	inline void Parse_WFSInputData(LPPWFSDATA lppOut, LPDWORD lpTTWFSInputData)
	{
		*lppOut = lpTTWFSInputData;
	}

	template <typename LPTTWFSDATA, typename LPPWFSDATA>
	inline void Parse_WFSInputData(LPPWFSDATA lppOut, LPWORD lpTTWFSInputData)
	{
		*lppOut = lpTTWFSInputData;
	}

	/*template <typename LPTTWFSDATA, typename LPPWFSDATA>
	inline void Parse_WFSInputData(LPPOUT lppOut, LPUSHORT lpTTWFSInputData)
	{
		*lppOut = lpTTWFSInputData;
	}*/

	/*template <typename LPTTWFSDATA, typename LPPWFSDATA>
	inline void Parse_WFSInputData(LPPOUT lppOut, LPULONG lpTTWFSInputData)
	{
		*lppOut = lpTTWFSInputData;
	}*/

	template <typename LPTTWFSDATA, typename LPPWFSDATA>
	inline void Parse_WFSInputData(LPPWFSDATA lppOut, LPSTR lpTTWFSInputData)
	{
		*lppOut = lpTTWFSInputData;
	}

	template <typename LPTTWFSDATA, typename LPPWFSDATA, typename std::enable_if_t<std::is_integral<LPTTWFSDATA>::value, bool> = true>
	inline void Parse_WFSInputData(LPPWFSDATA, int)
	{
		// Template Specialization for NULL
	}
	
	template <typename T1, typename T2, typename T3>
	void Parse_Pointer2Pointer(T3 &lOut, LPARAM lParam)
	{
		WFSRESULT   l_WFSResult = *((LPWFSRESULT)lParam);
	
		if (WFS_SUCCESS != l_WFSResult.hResult || !l_WFSResult.lpBuffer)
			return;
	
		T1* l_pWFSBuffer = (T1*)l_WFSResult.lpBuffer;
		CopyP2NAPs(lOut, (T2*)l_pWFSBuffer);
		WFMSafeFreeMemory(l_pWFSBuffer);
		for (auto elem : lOut)
			;//TTINFO(elem.MakeString());
	}
		
	/************************************************************************/
	/*************************XFS Parse Functions****************************/
	/************************************************************************/
	//
	//static std::string XFSErrorParser(DWORD macro)
	//{
	//	std::string _str;
	//
	//	switch (macro)
	//	{
	//	case	WFS_SUCCESS							: _str.assign("WFS_SUCCESS");											break;
	//	case	WFS_ERR_ALREADY_STARTED				: _str.assign("WFS_ERR_ALREADY_STARTED");								break;
	//	case	WFS_ERR_API_VER_TOO_HIGH			: _str.assign("WFS_ERR_API_VER_TOO_HIGH");								break;
	//	case	WFS_ERR_API_VER_TOO_LOW				: _str.assign("WFS_ERR_API_VER_TOO_LOW");								break;
	//	case	WFS_ERR_CANCELED					: _str.assign("WFS_ERR_CANCELED");										break;
	//	case	WFS_ERR_CFG_INVALID_HKEY			: _str.assign("WFS_ERR_CFG_INVALID_HKEY");								break;
	//	case	WFS_ERR_CFG_INVALID_NAME			: _str.assign("WFS_ERR_CFG_INVALID_NAME");								break;
	//	case	WFS_ERR_CFG_INVALID_SUBKEY			: _str.assign("WFS_ERR_CFG_INVALID_SUBKEY");							break;
	//	case	WFS_ERR_CFG_INVALID_VALUE			: _str.assign("WFS_ERR_CFG_INVALID_VALUE");								break;
	//	case	WFS_ERR_CFG_KEY_NOT_EMPTY			: _str.assign("WFS_ERR_CFG_KEY_NOT_EMPTY");								break;
	//	case	WFS_ERR_CFG_NAME_TOO_LONG			: _str.assign("WFS_ERR_CFG_NAME_TOO_LONG");								break;
	//	case	WFS_ERR_CFG_NO_MORE_ITEMS			: _str.assign("WFS_ERR_CFG_NO_MORE_ITEMS");								break;
	//	case	WFS_ERR_CFG_VALUE_TOO_LONG			: _str.assign("WFS_ERR_CFG_VALUE_TOO_LONG");							break;
	//	case	WFS_ERR_DEV_NOT_READY				: _str.assign("WFS_ERR_DEV_NOT_READY");									break;
	//	case	WFS_ERR_HARDWARE_ERROR 				: _str.assign("WFS_ERR_HARDWARE_ERROR");								break;
	//	case	WFS_ERR_INTERNAL_ERROR 				: _str.assign("WFS_ERR_INTERNAL_ERROR");								break;
	//	case	WFS_ERR_INVALID_ADDRESS 			: _str.assign("WFS_ERR_INVALID_ADDRESS");								break;
	//	case	WFS_ERR_INVALID_APP_HANDLE 			: _str.assign("WFS_ERR_INVALID_APP_HANDLE");							break;
	//	case	WFS_ERR_INVALID_BUFFER 				: _str.assign("WFS_ERR_INVALID_BUFFER");								break;
	//	case	WFS_ERR_INVALID_CATEGORY 			: _str.assign("WFS_ERR_INVALID_CATEGORY");								break;
	//	case	WFS_ERR_INVALID_COMMAND 			: _str.assign("WFS_ERR_INVALID_COMMAND");								break;
	//	case	WFS_ERR_INVALID_EVENT_CLASS 		: _str.assign("WFS_ERR_INVALID_EVENT_CLASS");							break;
	//	case	WFS_ERR_INVALID_HSERVICE 			: _str.assign("WFS_ERR_INVALID_HSERVICE");								break;
	//	case	WFS_ERR_INVALID_HPROVIDER 			: _str.assign("WFS_ERR_INVALID_HPROVIDER");								break;
	//	case	WFS_ERR_INVALID_HWND 				: _str.assign("WFS_ERR_INVALID_HWND");									break;
	//	case	WFS_ERR_INVALID_HWNDREG 			: _str.assign("WFS_ERR_INVALID_HWNDREG");								break;
	//	case	WFS_ERR_INVALID_POINTER 			: _str.assign("WFS_ERR_INVALID_POINTER");								break;
	//	case	WFS_ERR_INVALID_REQ_ID 				: _str.assign("WFS_ERR_INVALID_REQ_ID");								break;
	//	case	WFS_ERR_INVALID_RESULT 				: _str.assign("WFS_ERR_INVALID_RESULT");								break;
	//	case	WFS_ERR_INVALID_SERVPROV 			: _str.assign("WFS_ERR_INVALID_SERVPROV");								break;
	//	case	WFS_ERR_INVALID_TIMER 				: _str.assign("WFS_ERR_INVALID_TIMER");									break;
	//	case	WFS_ERR_INVALID_TRACELEVEL 			: _str.assign("WFS_ERR_INVALID_TRACELEVEL");							break;
	//	case	WFS_ERR_LOCKED 						: _str.assign("WFS_ERR_LOCKED");										break;
	//	case	WFS_ERR_NO_BLOCKING_CALL 			: _str.assign("WFS_ERR_NO_BLOCKING_CALL");								break;
	//	case	WFS_ERR_NO_SERVPROV 				: _str.assign("WFS_ERR_NO_SERVPROV");									break;
	//	case	WFS_ERR_NO_SUCH_THREAD 				: _str.assign("WFS_ERR_NO_SUCH_THREAD");								break;
	//	case	WFS_ERR_NO_TIMER 					: _str.assign("WFS_ERR_NO_TIMER");										break;
	//	case	WFS_ERR_NOT_LOCKED 					: _str.assign("WFS_ERR_NOT_LOCKED");									break;
	//	case	WFS_ERR_NOT_OK_TO_UNLOAD 			: _str.assign("WFS_ERR_NOT_OK_TO_UNLOAD");								break;
	//	case	WFS_ERR_NOT_STARTED 				: _str.assign("WFS_ERR_NOT_STARTED");									break;
	//	case	WFS_ERR_NOT_REGISTERED 				: _str.assign("WFS_ERR_NOT_REGISTERED");								break;
	//	case	WFS_ERR_OP_IN_PROGRESS 				: _str.assign("WFS_ERR_OP_IN_PROGRESS");								break;
	//	case	WFS_ERR_OUT_OF_MEMORY 				: _str.assign("WFS_ERR_OUT_OF_MEMORY");									break;
	//	case	WFS_ERR_SERVICE_NOT_FOUND 			: _str.assign("WFS_ERR_SERVICE_NOT_FOUND");								break;
	//	case	WFS_ERR_SPI_VER_TOO_HIGH 			: _str.assign("WFS_ERR_SPI_VER_TOO_HIGH");								break;
	//	case	WFS_ERR_SPI_VER_TOO_LOW 			: _str.assign("WFS_ERR_SPI_VER_TOO_LOW");								break;
	//	case	WFS_ERR_SRVC_VER_TOO_HIGH			: _str.assign("WFS_ERR_SRVC_VER_TOO_HIGH");								break;
	//	case	WFS_ERR_SRVC_VER_TOO_LOW 			: _str.assign("WFS_ERR_SRVC_VER_TOO_LOW");								break;
	//	case	WFS_ERR_TIMEOUT 					: _str.assign("WFS_ERR_TIMEOUT");										break;
	//	case	WFS_ERR_UNSUPP_CATEGORY 			: _str.assign("WFS_ERR_UNSUPP_CATEGORY");								break;
	//	case	WFS_ERR_UNSUPP_COMMAND 				: _str.assign("WFS_ERR_UNSUPP_COMMAND");								break;
	//	case	WFS_ERR_VERSION_ERROR_IN_SRVC 		: _str.assign("WFS_ERR_VERSION_ERROR_IN_SRVC");							break;
	//	case	WFS_ERR_INVALID_DATA 				: _str.assign("WFS_ERR_INVALID_DATA");									break;
	//	case	WFS_ERR_SOFTWARE_ERROR 				: _str.assign("WFS_ERR_SOFTWARE_ERROR");								break;
	//	case	WFS_ERR_CONNECTION_LOST 			: _str.assign("WFS_ERR_CONNECTION_LOST");								break;
	//	case	WFS_ERR_USER_ERROR 					: _str.assign("WFS_ERR_USER_ERROR");									break;
	//	case	WFS_ERR_UNSUPP_DATA 				: _str.assign("WFS_ERR_UNSUPP_DATA");									break;
	//		/* XFS PTR Errors */
	//	case	WFS_ERR_PTR_FORMNOTFOUND			: _str.assign("WFS_ERR_PTR_FORMNOTFOUND");								break;
	//	case	WFS_ERR_PTR_FIELDNOTFOUND			: _str.assign("WFS_ERR_PTR_FIELDNOTFOUND");								break;
	//	case	WFS_ERR_PTR_NOMEDIAPRESENT			: _str.assign("WFS_ERR_PTR_NOMEDIAPRESENT");							break;
	//	case	WFS_ERR_PTR_READNOTSUPPORTED		: _str.assign("WFS_ERR_PTR_READNOTSUPPORTED");							break;
	//	case	WFS_ERR_PTR_FLUSHFAIL				: _str.assign("WFS_ERR_PTR_FLUSHFAIL");									break;
	//	case	WFS_ERR_PTR_MEDIAOVERFLOW			: _str.assign("WFS_ERR_PTR_MEDIAOVERFLOW");								break;
	//	case	WFS_ERR_PTR_FIELDSPECFAILURE		: _str.assign("WFS_ERR_PTR_FIELDSPECFAILURE");							break;
	//	case	WFS_ERR_PTR_FIELDERROR				: _str.assign("WFS_ERR_PTR_FIELDERROR");								break;
	//	case	WFS_ERR_PTR_MEDIANOTFOUND			: _str.assign("WFS_ERR_PTR_MEDIANOTFOUND");								break;
	//	case	WFS_ERR_PTR_EXTENTNOTSUPPORTED		: _str.assign("WFS_ERR_PTR_EXTENTNOTSUPPORTED");						break;
	//	case	WFS_ERR_PTR_MEDIAINVALID			: _str.assign("WFS_ERR_PTR_MEDIAINVALID");								break;
	//	case	WFS_ERR_PTR_FORMINVALID				: _str.assign("WFS_ERR_PTR_FORMINVALID");								break;
	//	case	WFS_ERR_PTR_FIELDINVALID			: _str.assign("WFS_ERR_PTR_FIELDINVALID");								break;
	//	case	WFS_ERR_PTR_MEDIASKEWED				: _str.assign("WFS_ERR_PTR_MEDIASKEWED");								break;
	//	case	WFS_ERR_PTR_RETRACTBINFULL			: _str.assign("WFS_ERR_PTR_RETRACTBINFULL");							break;
	//	case	WFS_ERR_PTR_STACKERFULL				: _str.assign("WFS_ERR_PTR_STACKERFULL");								break;
	//	case	WFS_ERR_PTR_PAGETURNFAIL			: _str.assign("WFS_ERR_PTR_PAGETURNFAIL");								break;
	//	case	WFS_ERR_PTR_MEDIATURNFAIL			: _str.assign("WFS_ERR_PTR_MEDIATURNFAIL");								break;
	//	case	WFS_ERR_PTR_SHUTTERFAIL				: _str.assign("WFS_ERR_PTR_SHUTTERFAIL");								break;
	//	case	WFS_ERR_PTR_MEDIAJAMMED				: _str.assign("WFS_ERR_PTR_MEDIAJAMMED");								break;
	//	case	WFS_ERR_PTR_FILE_IO_ERROR			: _str.assign("WFS_ERR_PTR_FILE_IO_ERROR");								break;
	//	case	WFS_ERR_PTR_CHARSETDATA				: _str.assign("WFS_ERR_PTR_CHARSETDATA");								break;
	//	case	WFS_ERR_PTR_PAPERJAMMED				: _str.assign("WFS_ERR_PTR_PAPERJAMMED");								break;
	//	case	WFS_ERR_PTR_PAPEROUT				: _str.assign("WFS_ERR_PTR_PAPEROUT");									break;
	//	case	WFS_ERR_PTR_INKOUT					: _str.assign("WFS_ERR_PTR_INKOUT");									break;
	//	case	WFS_ERR_PTR_TONEROUT				: _str.assign("WFS_ERR_PTR_TONEROUT");									break;
	//	case	WFS_ERR_PTR_LAMPINOP				: _str.assign("WFS_ERR_PTR_LAMPINOP");									break;
	//	case	WFS_ERR_PTR_SOURCEINVALID			: _str.assign("WFS_ERR_PTR_SOURCEINVALID");								break;
	//	case	WFS_ERR_PTR_SEQUENCEINVALID			: _str.assign("WFS_ERR_PTR_SEQUENCEINVALID");							break;
	//	case	WFS_ERR_PTR_MEDIASIZE				: _str.assign("WFS_ERR_PTR_MEDIASIZE");									break;
	//		/* XFS IDC Errors */
	//	case	WFS_ERR_IDC_MEDIAJAM				: _str.assign("WFS_ERR_IDC_MEDIAJAM");									break;
	//	case	WFS_ERR_IDC_NOMEDIA					: _str.assign("WFS_ERR_IDC_NOMEDIA");									break;
	//	case	WFS_ERR_IDC_MEDIARETAINED			: _str.assign("WFS_ERR_IDC_MEDIARETAINED");								break;
	//	case	WFS_ERR_IDC_RETAINBINFULL			: _str.assign("WFS_ERR_IDC_RETAINBINFULL");								break;
	//	case	WFS_ERR_IDC_INVALIDDATA				: _str.assign("WFS_ERR_IDC_INVALIDDATA");								break;
	//	case	WFS_ERR_IDC_INVALIDMEDIA			: _str.assign("WFS_ERR_IDC_INVALIDMEDIA");								break;
	//	case	WFS_ERR_IDC_FORMNOTFOUND			: _str.assign("WFS_ERR_IDC_FORMNOTFOUND");								break;
	//	case	WFS_ERR_IDC_FORMINVALID				: _str.assign("WFS_ERR_IDC_FORMINVALID");								break;
	//	case	WFS_ERR_IDC_DATASYNTAX				: _str.assign("WFS_ERR_IDC_DATASYNTAX");								break;
	//	case	WFS_ERR_IDC_SHUTTERFAIL				: _str.assign("WFS_ERR_IDC_SHUTTERFAIL");								break;
	//	case	WFS_ERR_IDC_SECURITYFAIL			: _str.assign("WFS_ERR_IDC_SECURITYFAIL");								break;
	//	case	WFS_ERR_IDC_PROTOCOLNOTSUPP			: _str.assign("WFS_ERR_IDC_PROTOCOLNOTSUPP");							break;
	//	case	WFS_ERR_IDC_ATRNOTOBTAINED			: _str.assign("WFS_ERR_IDC_ATRNOTOBTAINED");							break;
	//	case	WFS_ERR_IDC_INVALIDKEY				: _str.assign("WFS_ERR_IDC_INVALIDKEY");								break;
	//	case	WFS_ERR_IDC_WRITE_METHOD			: _str.assign("WFS_ERR_IDC_WRITE_METHOD");								break;
	//	case	WFS_ERR_IDC_CHIPPOWERNOTSUPP		: _str.assign("WFS_ERR_IDC_CHIPPOWERNOTSUPP");							break;
	//	case	WFS_ERR_IDC_CARDTOOSHORT			: _str.assign("WFS_ERR_IDC_CARDTOOSHORT");								break;
	//	case	WFS_ERR_IDC_CARDTOOLONG				: _str.assign("WFS_ERR_IDC_CARDTOOLONG");								break;
	//		/* XFS CDM Errors */
	//	case	WFS_ERR_CDM_INVALIDCURRENCY			: _str.assign("WFS_ERR_CDM_INVALIDCURRENCY");							break;
	//	case	WFS_ERR_CDM_INVALIDTELLERID			: _str.assign("WFS_ERR_CDM_INVALIDTELLERID");							break;
	//	case	WFS_ERR_CDM_CASHUNITERROR			: _str.assign("WFS_ERR_CDM_CASHUNITERROR");								break;
	//	case	WFS_ERR_CDM_INVALIDDENOMINATION		: _str.assign("WFS_ERR_CDM_INVALIDDENOMINATION");						break;
	//	case	WFS_ERR_CDM_INVALIDMIXNUMBER		: _str.assign("WFS_ERR_CDM_INVALIDMIXNUMBER");							break;
	//	case	WFS_ERR_CDM_NOCURRENCYMIX			: _str.assign("WFS_ERR_CDM_NOCURRENCYMIX");								break;
	//	case	WFS_ERR_CDM_NOTDISPENSABLE			: _str.assign("WFS_ERR_CDM_NOTDISPENSABLE");							break;
	//	case	WFS_ERR_CDM_TOOMANYITEMS			: _str.assign("WFS_ERR_CDM_TOOMANYITEMS");								break;
	//	case	WFS_ERR_CDM_UNSUPPOSITION			: _str.assign("WFS_ERR_CDM_UNSUPPOSITION");								break;
	//	case	WFS_ERR_CDM_SAFEDOOROPEN			: _str.assign("WFS_ERR_CDM_SAFEDOOROPEN");								break;
	//	case	WFS_ERR_CDM_SHUTTERNOTOPEN			: _str.assign("WFS_ERR_CDM_SHUTTERNOTOPEN");							break;
	//	case	WFS_ERR_CDM_SHUTTEROPEN				: _str.assign("WFS_ERR_CDM_SHUTTEROPEN");								break;
	//	case	WFS_ERR_CDM_SHUTTERCLOSED			: _str.assign("WFS_ERR_CDM_SHUTTERCLOSED");								break;
	//	case	WFS_ERR_CDM_INVALIDCASHUNIT			: _str.assign("WFS_ERR_CDM_INVALIDCASHUNIT");							break;
	//	case	WFS_ERR_CDM_NOITEMS					: _str.assign("WFS_ERR_CDM_NOITEMS");									break;
	//	case	WFS_ERR_CDM_EXCHANGEACTIVE			: _str.assign("WFS_ERR_CDM_EXCHANGEACTIVE");							break;
	//	case	WFS_ERR_CDM_NOEXCHANGEACTIVE		: _str.assign("WFS_ERR_CDM_NOEXCHANGEACTIVE");							break;
	//	case	WFS_ERR_CDM_SHUTTERNOTCLOSED		: _str.assign("WFS_ERR_CDM_SHUTTERNOTCLOSED");							break;
	//	case	WFS_ERR_CDM_PRERRORNOITEMS			: _str.assign("WFS_ERR_CDM_PRERRORNOITEMS");							break;
	//	case	WFS_ERR_CDM_PRERRORITEMS			: _str.assign("WFS_ERR_CDM_PRERRORITEMS");								break;
	//	case	WFS_ERR_CDM_PRERRORUNKNOWN			: _str.assign("WFS_ERR_CDM_PRERRORUNKNOWN");							break;
	//	case	WFS_ERR_CDM_ITEMSTAKEN				: _str.assign("WFS_ERR_CDM_ITEMSTAKEN");								break;
	//	case	WFS_ERR_CDM_INVALIDMIXTABLE			: _str.assign("WFS_ERR_CDM_INVALIDMIXTABLE");							break;
	//	case	WFS_ERR_CDM_OUTPUTPOS_NOT_EMPTY		: _str.assign("WFS_ERR_CDM_OUTPUTPOS_NOT_EMPTY");						break;
	//	case	WFS_ERR_CDM_INVALIDRETRACTPOSITION	: _str.assign("WFS_ERR_CDM_INVALIDRETRACTPOSITION");					break;
	//	case	WFS_ERR_CDM_NOTRETRACTAREA			: _str.assign("WFS_ERR_CDM_NOTRETRACTAREA");							break;
	//	case	WFS_ERR_CDM_NOCASHBOXPRESENT		: _str.assign("WFS_ERR_CDM_NOCASHBOXPRESENT");							break;
	//	case	WFS_ERR_CDM_AMOUNTNOTINMIXTABLE		: _str.assign("WFS_ERR_CDM_AMOUNTNOTINMIXTABLE");						break;
	//	case	WFS_ERR_CDM_ITEMSNOTTAKEN			: _str.assign("WFS_ERR_CDM_ITEMSNOTTAKEN");								break;
	//	case	WFS_ERR_CDM_ITEMSLEFT				: _str.assign("WFS_ERR_CDM_ITEMSLEFT");									break;
	//		/* XFS PIN Errors */
	//	case	WFS_ERR_PIN_KEYNOTFOUND				: _str.assign("WFS_ERR_PIN_KEYNOTFOUND");								break;
	//	case	WFS_ERR_PIN_MODENOTSUPPORTED		: _str.assign("WFS_ERR_PIN_MODENOTSUPPORTED");							break;
	//	case	WFS_ERR_PIN_ACCESSDENIED			: _str.assign("WFS_ERR_PIN_ACCESSDENIED");								break;
	//	case	WFS_ERR_PIN_INVALIDID				: _str.assign("WFS_ERR_PIN_INVALIDID");									break;
	//	case	WFS_ERR_PIN_DUPLICATEKEY			: _str.assign("WFS_ERR_PIN_DUPLICATEKEY");								break;
	//	case	WFS_ERR_PIN_KEYNOVALUE				: _str.assign("WFS_ERR_PIN_KEYNOVALUE");								break;
	//	case	WFS_ERR_PIN_USEVIOLATION			: _str.assign("WFS_ERR_PIN_USEVIOLATION");								break;
	//	case	WFS_ERR_PIN_NOPIN					: _str.assign("WFS_ERR_PIN_NOPIN");										break;
	//	case	WFS_ERR_PIN_INVALIDKEYLENGTH		: _str.assign("WFS_ERR_PIN_INVALIDKEYLENGTH");							break;
	//	case	WFS_ERR_PIN_KEYINVALID				: _str.assign("WFS_ERR_PIN_KEYINVALID");								break;
	//	case	WFS_ERR_PIN_KEYNOTSUPPORTED			: _str.assign("WFS_ERR_PIN_KEYNOTSUPPORTED");							break;
	//	case	WFS_ERR_PIN_NOACTIVEKEYS			: _str.assign("WFS_ERR_PIN_NOACTIVEKEYS");								break;
	//	case	WFS_ERR_PIN_NOTERMINATEKEYS			: _str.assign("WFS_ERR_PIN_NOTERMINATEKEYS");							break;
	//	case	WFS_ERR_PIN_MINIMUMLENGTH			: _str.assign("WFS_ERR_PIN_MINIMUMLENGTH");								break;
	//	case	WFS_ERR_PIN_PROTOCOLNOTSUPP			: _str.assign("WFS_ERR_PIN_PROTOCOLNOTSUPP");							break;
	//	case	WFS_ERR_PIN_INVALIDDATA				: _str.assign("WFS_ERR_PIN_INVALIDDATA");								break;
	//	case	WFS_ERR_PIN_NOTALLOWED				: _str.assign("WFS_ERR_PIN_NOTALLOWED");								break;
	//	case	WFS_ERR_PIN_NOKEYRAM				: _str.assign("WFS_ERR_PIN_NOKEYRAM");									break;
	//	case	WFS_ERR_PIN_NOCHIPTRANSACTIVE		: _str.assign("WFS_ERR_PIN_NOCHIPTRANSACTIVE");							break;
	//	case	WFS_ERR_PIN_ALGORITHMNOTSUPP		: _str.assign("WFS_ERR_PIN_ALGORITHMNOTSUPP");							break;
	//	case	WFS_ERR_PIN_FORMATNOTSUPP			: _str.assign("WFS_ERR_PIN_FORMATNOTSUPP");								break;
	//	case	WFS_ERR_PIN_HSMSTATEINVALID			: _str.assign("WFS_ERR_PIN_HSMSTATEINVALID");							break;
	//	case	WFS_ERR_PIN_MACINVALID				: _str.assign("WFS_ERR_PIN_MACINVALID");								break;
	//	case	WFS_ERR_PIN_PROTINVALID				: _str.assign("WFS_ERR_PIN_PROTINVALID");								break;
	//	case	WFS_ERR_PIN_FORMATINVALID			: _str.assign("WFS_ERR_PIN_FORMATINVALID");								break;
	//	case	WFS_ERR_PIN_CONTENTINVALID			: _str.assign("WFS_ERR_PIN_CONTENTINVALID");							break;
	//	case	WFS_ERR_PIN_SIG_NOT_SUPP			: _str.assign("WFS_ERR_PIN_SIG_NOT_SUPP	");								break;
	//	case	WFS_ERR_PIN_INVALID_MOD_LEN			: _str.assign("WFS_ERR_PIN_INVALID_MOD_LEN");							break;
	//	case	WFS_ERR_PIN_INVALIDCERTSTATE		: _str.assign("WFS_ERR_PIN_INVALIDCERTSTATE");							break;
	//	case	WFS_ERR_PIN_KEY_GENERATION_ERROR	: _str.assign("WFS_ERR_PIN_KEY_GENERATION_ERROR");						break;
	//	case	WFS_ERR_PIN_EMV_VERIFY_FAILED		: _str.assign("WFS_ERR_PIN_EMV_VERIFY_FAILED");							break;
	//	case	WFS_ERR_PIN_RANDOMINVALID			: _str.assign("WFS_ERR_PIN_RANDOMINVALID");								break;
	//	case	WFS_ERR_PIN_SIGNATUREINVALID		: _str.assign("WFS_ERR_PIN_SIGNATUREINVALID");							break;
	//	case	WFS_ERR_PIN_SNSCDINVALID			: _str.assign("WFS_ERR_PIN_SNSCDINVALID");								break;
	//	case	WFS_ERR_PIN_NORSAKEYPAIR			: _str.assign("WFS_ERR_PIN_NORSAKEYPAIR");								break;
	//		/* CHK Errors */
	//	case	WFS_ERR_CHK_FORMNOTFOUND			: _str.assign("WFS_ERR_CHK_FORMNOTFOUND");								break;
	//	case	WFS_ERR_CHK_FORMINVALID				: _str.assign("WFS_ERR_CHK_FORMINVALID");								break;
	//	case	WFS_ERR_CHK_MEDIANOTFOUND			: _str.assign("WFS_ERR_CHK_MEDIANOTFOUND");								break;
	//	case	WFS_ERR_CHK_MEDIAINVALID			: _str.assign("WFS_ERR_CHK_MEDIAINVALID");								break;
	//	case	WFS_ERR_CHK_MEDIAOVERFLOW			: _str.assign("WFS_ERR_CHK_MEDIAOVERFLOW");								break;
	//	case	WFS_ERR_CHK_FIELDNOTFOUND			: _str.assign("WFS_ERR_CHK_FIELDNOTFOUND");								break;
	//	case	WFS_ERR_CHK_FIELDINVALID			: _str.assign("WFS_ERR_CHK_FIELDINVALID");								break;
	//	case	WFS_ERR_CHK_FIELDERROR				: _str.assign("WFS_ERR_CHK_FIELDERROR");								break;
	//	case	WFS_ERR_CHK_REQDFIELDMISSING		: _str.assign("WFS_ERR_CHK_REQDFIELDMISSING");							break;
	//	case	WFS_ERR_CHK_FIELDSPECFAILURE		: _str.assign("WFS_ERR_CHK_FIELDSPECFAILURE");							break;
	//	case	WFS_ERR_CHK_CHARSETDATA				: _str.assign("WFS_ERR_CHK_CHARSETDATA");								break;
	//	case	WFS_ERR_CHK_MEDIAJAM				: _str.assign("WFS_ERR_CHK_MEDIAJAM");									break;
	//	case	WFS_ERR_CHK_SHUTTERFAIL				: _str.assign("WFS_ERR_CHK_SHUTTERFAIL");								break;
	//		/* DEP Errors*/
	//	case	WFS_ERR_DEP_DEPFULL					: _str.assign("WFS_ERR_DEP_DEPFULL");									break;
	//	case	WFS_ERR_DEP_DEPJAMMED				: _str.assign("WFS_ERR_DEP_DEPJAMMED");									break;
	//	case	WFS_ERR_DEP_ENVEMPTY				: _str.assign("WFS_ERR_DEP_ENVEMPTY");									break;
	//	case	WFS_ERR_DEP_ENVJAMMED				: _str.assign("WFS_ERR_DEP_ENVJAMMED");									break;
	//	case	WFS_ERR_DEP_ENVSIZE					: _str.assign("WFS_ERR_DEP_ENVSIZE");									break;
	//	case	WFS_ERR_DEP_NOENV					: _str.assign("WFS_ERR_DEP_NOENV");										break;
	//	case	WFS_ERR_DEP_PTRFAIL					: _str.assign("WFS_ERR_DEP_PTRFAIL");									break;
	//	case	WFS_ERR_DEP_SHTNOTCLOSED			: _str.assign("WFS_ERR_DEP_SHTNOTCLOSED");								break;
	//	case	WFS_ERR_DEP_SHTNOTOPENED			: _str.assign("WFS_ERR_DEP_SHTNOTOPENED");								break;
	//	case	WFS_ERR_DEP_CONTMISSING				: _str.assign("WFS_ERR_DEP_CONTMISSING");								break;
	//	case	WFS_ERR_DEP_DEPUNKNOWN				: _str.assign("WFS_ERR_DEP_DEPUNKNOWN");								break;
	//	case	WFS_ERR_DEP_CHARSETNOTSUPP			: _str.assign("WFS_ERR_DEP_CHARSETNOTSUPP");							break;
	//	case	WFS_ERR_DEP_TONEROUT				: _str.assign("WFS_ERR_DEP_TONEROUT");									break;
	//		/* XFS TTU Errors */
	//	case	WFS_ERR_TTU_FIELDERROR				: _str.assign("WFS_ERR_TTU_FIELDERROR");								break;
	//	case	WFS_ERR_TTU_FIELDINVALID			: _str.assign("WFS_ERR_TTU_FIELDINVALID");								break;
	//	case	WFS_ERR_TTU_FIELDNOTFOUND			: _str.assign("WFS_ERR_TTU_FIELDNOTFOUND");								break;
	//	case	WFS_ERR_TTU_FIELDSPECFAILURE		: _str.assign("WFS_ERR_TTU_FIELDSPECFAILURE");							break;
	//	case	WFS_ERR_TTU_FORMINVALID				: _str.assign("WFS_ERR_TTU_FORMINVALID");								break;
	//	case	WFS_ERR_TTU_FORMNOTFOUND			: _str.assign("WFS_ERR_TTU_FORMNOTFOUND");								break;
	//	case	WFS_ERR_TTU_INVALIDLED				: _str.assign("WFS_ERR_TTU_INVALIDLED");								break;
	//	case	WFS_ERR_TTU_KEYCANCELED				: _str.assign("WFS_ERR_TTU_KEYCANCELED");								break;
	//	case	WFS_ERR_TTU_MEDIAOVERFLOW			: _str.assign("WFS_ERR_TTU_MEDIAOVERFLOW");								break;
	//	case	WFS_ERR_TTU_RESNOTSUPP				: _str.assign("WFS_ERR_TTU_RESNOTSUPP");								break;
	//	case	WFS_ERR_TTU_CHARSETDATA				: _str.assign("WFS_ERR_TTU_CHARSETDATA");								break;
	//	case	WFS_ERR_TTU_KEYINVALID				: _str.assign("WFS_ERR_TTU_KEYINVALID");								break;
	//	case	WFS_ERR_TTU_KEYNOTSUPPORTED			: _str.assign("WFS_ERR_TTU_KEYNOTSUPPORTED");							break;
	//	case	WFS_ERR_TTU_NOACTIVEKEYS			: _str.assign("WFS_ERR_TTU_NOACTIVEKEYS");								break;
	//		/* XFS SIU Errors */
	//	case	WFS_ERR_SIU_INVALID_PORT			: _str.assign("WFS_ERR_SIU_INVALID_PORT");								break;
	//	case	WFS_ERR_SIU_SYNTAX					: _str.assign("WFS_ERR_SIU_SYNTAX");									break;
	//	case	WFS_ERR_SIU_PORT_ERROR				: _str.assign("WFS_ERR_SIU_PORT_ERROR");								break;
	//		/* XFS CAM Errors */
	//	case	WFS_ERR_CAM_CAMNOTSUPP				: _str.assign("WFS_ERR_CAM_CAMNOTSUPP");								break;
	//	case	WFS_ERR_CAM_MEDIAFULL				: _str.assign("WFS_ERR_CAM_MEDIAFULL");									break;
	//	case	WFS_ERR_CAM_CAMINOP					: _str.assign("WFS_ERR_CAM_CAMINOP");									break;
	//	case	WFS_ERR_CAM_CHARSETNOTSUPP			: _str.assign("WFS_ERR_CAM_CHARSETNOTSUPP");							break;
	//		/* XFS CIM Errors */
	//	case	WFS_ERR_CIM_INVALIDCURRENCY         : _str.assign("WFS_ERR_CIM_INVALIDCURRENCY");							break;
	//	case	WFS_ERR_CIM_INVALIDTELLERID         : _str.assign("WFS_ERR_CIM_INVALIDTELLERID");							break;
	//	case	WFS_ERR_CIM_CASHUNITERROR           : _str.assign("WFS_ERR_CIM_CASHUNITERROR");								break;
	//	case	WFS_ERR_CIM_TOOMANYITEMS            : _str.assign("WFS_ERR_CIM_TOOMANYITEMS");								break;
	//	case	WFS_ERR_CIM_UNSUPPOSITION           : _str.assign("WFS_ERR_CIM_UNSUPPOSITION");								break;
	//	case	WFS_ERR_CIM_SAFEDOOROPEN            : _str.assign("WFS_ERR_CIM_SAFEDOOROPEN");								break;
	//	case	WFS_ERR_CIM_SHUTTERNOTOPEN          : _str.assign("WFS_ERR_CIM_SHUTTERNOTOPEN");							break;
	//	case	WFS_ERR_CIM_SHUTTEROPEN             : _str.assign("WFS_ERR_CIM_SHUTTEROPEN");								break;
	//	case	WFS_ERR_CIM_SHUTTERCLOSED           : _str.assign("WFS_ERR_CIM_SHUTTERCLOSED");								break;
	//	case	WFS_ERR_CIM_INVALIDCASHUNIT         : _str.assign("WFS_ERR_CIM_INVALIDCASHUNIT");							break;
	//	case	WFS_ERR_CIM_NOITEMS                 : _str.assign("WFS_ERR_CIM_NOITEMS");									break;
	//	case	WFS_ERR_CIM_EXCHANGEACTIVE          : _str.assign("WFS_ERR_CIM_EXCHANGEACTIVE");							break;
	//	case	WFS_ERR_CIM_NOEXCHANGEACTIVE        : _str.assign("WFS_ERR_CIM_NOEXCHANGEACTIVE");							break;
	//	case	WFS_ERR_CIM_SHUTTERNOTCLOSED        : _str.assign("WFS_ERR_CIM_SHUTTERNOTCLOSED");							break;
	//	case	WFS_ERR_CIM_ITEMSTAKEN              : _str.assign("WFS_ERR_CIM_ITEMSTAKEN");								break;
	//	case	WFS_ERR_CIM_CASHINACTIVE            : _str.assign("WFS_ERR_CIM_CASHINACTIVE");								break;
	//	case	WFS_ERR_CIM_NOCASHINACTIVE          : _str.assign("WFS_ERR_CIM_NOCASHINACTIVE");							break;
	//	case	WFS_ERR_CIM_POSITION_NOT_EMPTY      : _str.assign("WFS_ERR_CIM_POSITION_NOT_EMPTY");						break;
	//	case	WFS_ERR_CIM_INVALIDRETRACTPOSITION  : _str.assign("WFS_ERR_CIM_INVALIDRETRACTPOSITION");					break;
	//	case	WFS_ERR_CIM_NOTRETRACTAREA          : _str.assign("WFS_ERR_CIM_NOTRETRACTAREA");							break;
	//
	//	default										: _str.assign("Unknown Error");
	//	}
	//	return _str;
	//}
	//
	//static std::string XFSMessageParser(DWORD macro)
	//{
	//	std::string _str;
	//
	//	switch(macro)
	//	{
	//		/****** Messages ********************************************************/				  								
	//		/* Message-No = (WM_USER + No) */																									
	//	case	WFS_OPEN_COMPLETE 							: _str.assign("WFS_OPEN_COMPLETE");								break;
	//	case	WFS_CLOSE_COMPLETE 							: _str.assign("WFS_CLOSE_COMPLETE");							break;
	//	case	WFS_LOCK_COMPLETE 							: _str.assign("WFS_LOCK_COMPLETE");								break;
	//	case	WFS_UNLOCK_COMPLETE 						: _str.assign("WFS_UNLOCK_COMPLETE");							break;
	//	case	WFS_REGISTER_COMPLETE 						: _str.assign("WFS_REGISTER_COMPLETE");							break;
	//	case	WFS_DEREGISTER_COMPLETE 					: _str.assign("WFS_DEREGISTER_COMPLETE");						break;
	//	case	WFS_GETINFO_COMPLETE 						: _str.assign("WFS_GETINFO_COMPLETE");							break;
	//	case	WFS_EXECUTE_COMPLETE 						: _str.assign("WFS_EXECUTE_COMPLETE");							break;
	//	case	WFS_EXECUTE_EVENT 							: _str.assign("WFS_EXECUTE_EVENT");								break;
	//	case	WFS_SERVICE_EVENT 							: _str.assign("WFS_SERVICE_EVENT");								break;
	//	case	WFS_USER_EVENT 								: _str.assign("WFS_USER_EVENT");								break;
	//	case	WFS_SYSTEM_EVENT 							: _str.assign("WFS_SYSTEM_EVENT");								break;
	//	case	WFS_TIMER_EVENT 							: _str.assign("WFS_TIMER_EVENT");								break;
	//		/****** System Event IDs ************************************************/					  											
	//	case	WFS_SYSE_UNDELIVERABLE_MSG 					: _str.assign("WFS_SYSE_UNDELIVERABLE_MSG");					break;
	//	case	WFS_SYSE_HARDWARE_ERROR 					: _str.assign("WFS_SYSE_HARDWARE_ERROR");						break;
	//	case	WFS_SYSE_VERSION_ERROR 						: _str.assign("WFS_SYSE_VERSION_ERROR");						break;
	//	case	WFS_SYSE_DEVICE_STATUS 						: _str.assign("WFS_SYSE_DEVICE_STATUS");						break;
	//	case	WFS_SYSE_APP_DISCONNECT 					: _str.assign("WFS_SYSE_APP_DISCONNECT");						break;
	//	case	WFS_SYSE_SOFTWARE_ERROR 					: _str.assign("WFS_SYSE_SOFTWARE_ERROR");						break;
	//	case	WFS_SYSE_USER_ERROR 						: _str.assign("WFS_SYSE_USER_ERROR");							break;
	//	case	WFS_SYSE_LOCK_REQUESTED 					: _str.assign("WFS_SYSE_LOCK_REQUESTED");						break;
	//		/* PTR Messages */
	//	case	WFS_EXEE_PTR_NOMEDIA						: _str.assign("WFS_EXEE_PTR_NOMEDIA");							break;
	//	case	WFS_EXEE_PTR_MEDIAINSERTED					: _str.assign("WFS_EXEE_PTR_MEDIAINSERTED");					break;
	//	case	WFS_EXEE_PTR_FIELDERROR						: _str.assign("WFS_EXEE_PTR_FIELDERROR");						break;
	//	case	WFS_EXEE_PTR_FIELDWARNING					: _str.assign("WFS_EXEE_PTR_FIELDWARNING");						break;
	//	case	WFS_USRE_PTR_RETRACTBINTHRESHOLD			: _str.assign("WFS_USRE_PTR_RETRACTBINTHRESHOLD");				break;
	//	case	WFS_SRVE_PTR_MEDIATAKEN						: _str.assign("WFS_SRVE_PTR_MEDIATAKEN");						break;
	//	case	WFS_USRE_PTR_PAPERTHRESHOLD					: _str.assign("WFS_USRE_PTR_PAPERTHRESHOLD");					break;
	//	case	WFS_USRE_PTR_TONERTHRESHOLD					: _str.assign("WFS_USRE_PTR_TONERTHRESHOLD");					break;
	//	case	WFS_SRVE_PTR_MEDIAINSERTED					: _str.assign("WFS_SRVE_PTR_MEDIAINSERTED");					break;
	//	case	WFS_USRE_PTR_LAMPTHRESHOLD					: _str.assign("WFS_USRE_PTR_LAMPTHRESHOLD");					break;
	//	case	WFS_USRE_PTR_INKTHRESHOLD					: _str.assign("WFS_USRE_PTR_INKTHRESHOLD");						break;
	//	case	WFS_SRVE_PTR_MEDIADETECTED					: _str.assign("WFS_SRVE_PTR_MEDIADETECTED");					break;
	//		/* IDC Messages */
	//	case	WFS_EXEE_IDC_INVALIDTRACKDATA				: _str.assign("WFS_EXEE_IDC_INVALIDTRACKDATA");					break;
	//	case	WFS_EXEE_IDC_MEDIAINSERTED					: _str.assign("WFS_EXEE_IDC_MEDIAINSERTED");					break;
	//	case	WFS_SRVE_IDC_MEDIAREMOVED					: _str.assign("WFS_SRVE_IDC_MEDIAREMOVED");						break;
	//	case	WFS_SRVE_IDC_CARDACTION						: _str.assign("WFS_SRVE_IDC_CARDACTION");						break;
	//	case	WFS_USRE_IDC_RETAINBINTHRESHOLD				: _str.assign("WFS_USRE_IDC_RETAINBINTHRESHOLD");				break;
	//	case	WFS_EXEE_IDC_INVALIDMEDIA					: _str.assign("WFS_EXEE_IDC_INVALIDMEDIA");						break;
	//	case	WFS_EXEE_IDC_MEDIARETAINED					: _str.assign("WFS_EXEE_IDC_MEDIARETAINED");					break;
	//	case	WFS_SRVE_IDC_MEDIADETECTED					: _str.assign("WFS_SRVE_IDC_MEDIADETECTED");					break;
	//		/* CDM Messages */
	//	case	WFS_SRVE_CDM_SAFEDOOROPEN					: _str.assign("WFS_SRVE_CDM_SAFEDOOROPEN");						break;
	//	case	WFS_SRVE_CDM_SAFEDOORCLOSED					: _str.assign("WFS_SRVE_CDM_SAFEDOORCLOSED");					break;
	//	case	WFS_USRE_CDM_CASHUNITTHRESHOLD				: _str.assign("WFS_USRE_CDM_CASHUNITTHRESHOLD");				break;
	//	case	WFS_SRVE_CDM_CASHUNITINFOCHANGED			: _str.assign("WFS_SRVE_CDM_CASHUNITINFOCHANGED");				break;
	//	case	WFS_SRVE_CDM_TELLERINFOCHANGED				: _str.assign("WFS_SRVE_CDM_TELLERINFOCHANGED");				break;
	//	case	WFS_EXEE_CDM_DELAYEDDISPENSE				: _str.assign("WFS_EXEE_CDM_DELAYEDDISPENSE");					break;
	//	case	WFS_EXEE_CDM_STARTDISPENSE					: _str.assign("WFS_EXEE_CDM_STARTDISPENSE");					break;
	//	case	WFS_EXEE_CDM_CASHUNITERROR					: _str.assign("WFS_EXEE_CDM_CASHUNITERROR");					break;
	//	case	WFS_SRVE_CDM_ITEMSTAKEN						: _str.assign("WFS_SRVE_CDM_ITEMSTAKEN");						break;
	//	case	WFS_EXEE_CDM_PARTIALDISPENSE				: _str.assign("WFS_EXEE_CDM_PARTIALDISPENSE");					break;
	//	case	WFS_EXEE_CDM_SUBDISPENSEOK					: _str.assign("WFS_EXEE_CDM_SUBDISPENSEOK");					break;
	//	case	WFS_SRVE_CDM_ITEMSPRESENTED					: _str.assign("WFS_SRVE_CDM_ITEMSPRESENTED");					break;
	//	case	WFS_SRVE_CDM_COUNTS_CHANGED					: _str.assign("WFS_SRVE_CDM_COUNTS_CHANGED");					break;
	//	case	WFS_EXEE_CDM_INCOMPLETEDISPENSE				: _str.assign("WFS_EXEE_CDM_INCOMPLETEDISPENSE");				break;
	//	case	WFS_EXEE_CDM_NOTEERROR						: _str.assign("WFS_EXEE_CDM_NOTEERROR");						break;
	//	case	WFS_SRVE_CDM_MEDIADETECTED					: _str.assign("WFS_SRVE_CDM_MEDIADETECTED");					break;
	//		/* PIN Messages */
	//	case	WFS_EXEE_PIN_KEY							: _str.assign("WFS_EXEE_PIN_KEY");								break;
	//	case	WFS_SRVE_PIN_INITIALIZED					: _str.assign("WFS_SRVE_PIN_INITIALIZED");						break;
	//	case	WFS_SRVE_PIN_ILLEGAL_KEY_ACCESS				: _str.assign("WFS_SRVE_PIN_ILLEGAL_KEY_ACCESS");				break;
	//	case	WFS_SRVE_PIN_OPT_REQUIRED					: _str.assign("WFS_SRVE_PIN_OPT_REQUIRED");						break;
	//	case	WFS_SRVE_PIN_HSM_TDATA_CHANGED				: _str.assign("WFS_SRVE_PIN_HSM_TDATA_CHANGED");				break;
	//	case	WFS_SRVE_PIN_CERTIFICATE_CHANGE				: _str.assign("WFS_SRVE_PIN_CERTIFICATE_CHANGE");				break;
	//
	//	case	WFS_SRVE_PIN_HSM_CHANGED					: _str.assign("WFS_SRVE_PIN_HSM_CHANGED");						break;
	//	case	WFS_EXEE_PIN_ENTERDATA						: _str.assign("WFS_EXEE_PIN_ENTERDATA");						break;
	//	case	WFS_SRVE_PIN_DEVICEPOSITION					: _str.assign("WFS_SRVE_PIN_DEVICEPOSITION");					break;
	//	case	WFS_SRVE_PIN_POWER_SAVE_CHANGE				: _str.assign("WFS_SRVE_PIN_POWER_SAVE_CHANGE");				break;
	//	case	WFS_EXEE_PIN_LAYOUT							: _str.assign("WFS_EXEE_PIN_LAYOUT");							break;
	//		/* CHK Messages */
	//	case	WFS_EXEE_CHK_NOMEDIA						: _str.assign("WFS_EXEE_CHK_NOMEDIA");							break;
	//	case	WFS_EXEE_CHK_MEDIAINSERTED					: _str.assign("WFS_EXEE_CHK_MEDIAINSERTED");					break;
	//	case	WFS_SRVE_CHK_MEDIAINSERTED					: _str.assign("WFS_SRVE_CHK_MEDIAINSERTED");					break;
	//	case	WFS_EXEE_CHK_FIELDERROR						: _str.assign("WFS_EXEE_CHK_FIELDERROR");						break;
	//	case	WFS_EXEE_CHK_FIELDWARNING					: _str.assign("WFS_EXEE_CHK_FIELDWARNING");						break;
	//	case	WFS_USRE_CHK_INKTHRESHOLD					: _str.assign("WFS_USRE_CHK_INKTHRESHOLD");						break;
	//	case	WFS_SRVE_CHK_MEDIADETECTED					: _str.assign("WFS_SRVE_CHK_MEDIADETECTED");					break;
	//		/* DEP Messages */
	//	case	WFS_SRVE_DEP_ENVTAKEN						: _str.assign("WFS_SRVE_DEP_ENVTAKEN");							break;
	//	case	WFS_EXEE_DEP_ENVDEPOSITED					: _str.assign("WFS_EXEE_DEP_ENVDEPOSITED");						break;
	//	case	WFS_EXEE_DEP_DEPOSITERROR					: _str.assign("WFS_EXEE_DEP_DEPOSITERROR");						break;
	//	case	WFS_USRE_DEP_DEPTHRESHOLD					: _str.assign("WFS_USRE_DEP_DEPTHRESHOLD");						break;
	//	case	WFS_USRE_DEP_TONERTHRESHOLD					: _str.assign("WFS_USRE_DEP_TONERTHRESHOLD");					break;
	//	case	WFS_USRE_DEP_ENVTHRESHOLD					: _str.assign("WFS_USRE_DEP_ENVTHRESHOLD");						break;
	//	case	WFS_SRVE_DEP_CONTINSERTED					: _str.assign("WFS_SRVE_DEP_CONTINSERTED");						break;
	//	case	WFS_SRVE_DEP_CONTREMOVED					: _str.assign("WFS_SRVE_DEP_CONTREMOVED");						break;
	//	case	WFS_SRVE_DEP_ENVINSERTED					: _str.assign("WFS_SRVE_DEP_ENVINSERTED");						break;
	//	case	WFS_SRVE_DEP_MEDIADETECTED					: _str.assign("WFS_SRVE_DEP_MEDIADETECTED");					break;
	//		/* TTU Messages */
	//	case	WFS_EXEE_TTU_FIELDERROR						: _str.assign("WFS_EXEE_TTU_FIELDERROR");						break;
	//	case	WFS_EXEE_TTU_FIELDWARNING					: _str.assign("WFS_EXEE_TTU_FIELDWARNING");						break;
	//	case	WFS_EXEE_TTU_KEY							: _str.assign("WFS_EXEE_TTU_KEY");								break;
	//		/* SIU Messages */
	//	case	WFS_SRVE_SIU_PORT_STATUS					: _str.assign("WFS_SRVE_SIU_PORT_STATUS");						break;
	//	case	WFS_EXEE_SIU_PORT_ERROR						: _str.assign("WFS_EXEE_SIU_PORT_ERROR");						break;
	//		/* VDM Messages */
	//	case	WFS_SRVE_VDM_ENTER_MODE_REQ					: _str.assign("WFS_SRVE_VDM_ENTER_MODE_REQ");					break;
	//	case	WFS_SRVE_VDM_EXIT_MODE_REQ					: _str.assign("WFS_SRVE_VDM_EXIT_MODE_REQ");					break;
	//	case	WFS_SYSE_VDM_MODEENTERED					: _str.assign("WFS_SYSE_VDM_MODEENTERED");						break;
	//	case	WFS_SYSE_VDM_MODEEXITED						: _str.assign("WFS_SYSE_VDM_MODEEXITED");						break;
	//		/* CAM Messages */
	//	case	WFS_USRE_CAM_MEDIATHRESHOLD					: _str.assign("WFS_USRE_CAM_MEDIATHRESHOLD");					break;
	//	case	WFS_EXEE_CAM_INVALIDDATA					: _str.assign("WFS_EXEE_CAM_INVALIDDATA");						break;
	//		/* CIM Messages */
	//	case     WFS_SRVE_CIM_SAFEDOOROPEN					: _str.assign(" WFS_SRVE_CIM_SAFEDOOROPEN");					break;
	//	case     WFS_SRVE_CIM_SAFEDOORCLOSED				: _str.assign(" WFS_SRVE_CIM_SAFEDOORCLOSED");					break;
	//	case     WFS_USRE_CIM_CASHUNITTHRESHOLD				: _str.assign(" WFS_USRE_CIM_CASHUNITTHRESHOLD");				break;
	//	case     WFS_SRVE_CIM_CASHUNITINFOCHANGED			: _str.assign(" WFS_SRVE_CIM_CASHUNITINFOCHANGED");				break;
	//	case     WFS_SRVE_CIM_TELLERINFOCHANGED				: _str.assign(" WFS_SRVE_CIM_TELLERINFOCHANGED");				break;
	//	case     WFS_EXEE_CIM_CASHUNITERROR					: _str.assign(" WFS_EXEE_CIM_CASHUNITERROR");					break;
	//	case     WFS_SRVE_CIM_ITEMSTAKEN					: _str.assign(" WFS_SRVE_CIM_ITEMSTAKEN");						break;
	//	case     WFS_SRVE_CIM_COUNTS_CHANGED				: _str.assign(" WFS_SRVE_CIM_COUNTS_CHANGED");					break;
	//	case     WFS_EXEE_CIM_INPUTREFUSE					: _str.assign(" WFS_EXEE_CIM_INPUTREFUSE");						break;
	//	case     WFS_SRVE_CIM_ITEMSPRESENTED				: _str.assign(" WFS_SRVE_CIM_ITEMSPRESENTED");					break;
	//	case     WFS_SRVE_CIM_ITEMSINSERTED					: _str.assign(" WFS_SRVE_CIM_ITEMSINSERTED");					break;
	//	case     WFS_EXEE_CIM_NOTEERROR						: _str.assign(" WFS_EXEE_CIM_NOTEERROR");						break;
	//	case     WFS_EXEE_CIM_SUBCASHIN						: _str.assign(" WFS_EXEE_CIM_SUBCASHIN");						break;
	//	case     WFS_SRVE_CIM_MEDIADETECTED					: _str.assign(" WFS_SRVE_CIM_MEDIADETECTED");					break;
	//	case     WFS_EXEE_CIM_INPUT_P6						: _str.assign(" WFS_EXEE_CIM_INPUT_P6");						break;
	//
	//	default												: _str.assign("Unknown Message");
	//	}
	//	return _str;
	//}
	//
	//static std::string XFSInfoCommandParser(DWORD macro)
	//{
	//	std::string _str;
	//
	//	switch (macro)
	//	{
	//		/* PTR Info Commands */
	//	case	WFS_INF_PTR_STATUS							: _str.assign("WFS_INF_PTR_STATUS");							break;
	//	case	WFS_INF_PTR_CAPABILITIES					: _str.assign("WFS_INF_PTR_CAPABILITIES");						break;
	//	case	WFS_INF_PTR_FORM_LIST						: _str.assign("WFS_INF_PTR_FORM_LIST");							break;
	//	case	WFS_INF_PTR_MEDIA_LIST						: _str.assign("WFS_INF_PTR_MEDIA_LIST");						break;
	//	case	WFS_INF_PTR_QUERY_FORM						: _str.assign("WFS_INF_PTR_QUERY_FORM");						break;
	//	case	WFS_INF_PTR_QUERY_MEDIA						: _str.assign("WFS_INF_PTR_QUERY_MEDIA");						break;
	//	case	WFS_INF_PTR_QUERY_FIELD						: _str.assign("WFS_INF_PTR_QUERY_FIELD");						break;
	//		/* IDC Info Commands */
	//	case	WFS_INF_IDC_STATUS							: _str.assign("WFS_INF_IDC_STATUS");							break;
	//	case	WFS_INF_IDC_CAPABILITIES					: _str.assign("WFS_INF_IDC_CAPABILITIES");						break;
	//	case	WFS_INF_IDC_FORM_LIST						: _str.assign("WFS_INF_IDC_FORM_LIST");							break;
	//	case	WFS_INF_IDC_QUERY_FORM						: _str.assign("WFS_INF_IDC_QUERY_FORM");						break;
	//		/* CDM Info Commands */
	//	case	WFS_INF_CDM_STATUS							: _str.assign("WFS_INF_CDM_STATUS");							break;
	//	case	WFS_INF_CDM_CAPABILITIES					: _str.assign("WFS_INF_CDM_CAPABILITIES");						break;
	//	case	WFS_INF_CDM_CASH_UNIT_INFO					: _str.assign("WFS_INF_CDM_CASH_UNIT_INFO");					break;
	//	case	WFS_INF_CDM_TELLER_INFO						: _str.assign("WFS_INF_CDM_TELLER_INFO");						break;
	//	case	WFS_INF_CDM_CURRENCY_EXP					: _str.assign("WFS_INF_CDM_CURRENCY_EXP");						break;
	//	case	WFS_INF_CDM_MIX_TYPES						: _str.assign("WFS_INF_CDM_MIX_TYPES");							break;
	//	case	WFS_INF_CDM_MIX_TABLE						: _str.assign("WFS_INF_CDM_MIX_TABLE");							break;
	//	case	WFS_INF_CDM_PRESENT_STATUS					: _str.assign("WFS_INF_CDM_PRESENT_STATUS");					break;
	//		/* PIN Info Commands */
	//	case	WFS_INF_PIN_STATUS							: _str.assign("WFS_INF_PIN_STATUS");							break;
	//	case	WFS_INF_PIN_CAPABILITIES					: _str.assign("WFS_INF_PIN_CAPABILITIES");						break;
	//	case	WFS_INF_PIN_KEY_DETAIL						: _str.assign("WFS_INF_PIN_KEY_DETAIL");						break;
	//	case	WFS_INF_PIN_FUNCKEY_DETAIL					: _str.assign("WFS_INF_PIN_FUNCKEY_DETAIL");					break;
	//	case	WFS_INF_PIN_HSM_TDATA						: _str.assign("WFS_INF_PIN_HSM_TDATA");							break;
	//	case	WFS_INF_PIN_KEY_DETAIL_EX					: _str.assign("WFS_INF_PIN_KEY_DETAIL_EX");						break;
	//		/* CHK Info Commands */
	//	case	WFS_INF_CHK_STATUS							: _str.assign("WFS_INF_CHK_STATUS");							break;
	//	case	WFS_INF_CHK_CAPABILITIES					: _str.assign("WFS_INF_CHK_CAPABILITIES");						break;
	//	case	WFS_INF_CHK_FORM_LIST						: _str.assign("WFS_INF_CHK_FORM_LIST");							break;
	//	case	WFS_INF_CHK_MEDIA_LIST						: _str.assign("WFS_INF_CHK_MEDIA_LIST");						break;
	//	case	WFS_INF_CHK_QUERY_FORM						: _str.assign("WFS_INF_CHK_QUERY_FORM");						break;
	//	case	WFS_INF_CHK_QUERY_MEDIA						: _str.assign("WFS_INF_CHK_QUERY_MEDIA");						break;
	//	case	WFS_INF_CHK_QUERY_FIELD						: _str.assign("WFS_INF_CHK_QUERY_FIELD");						break;
	//		/* DEP Info Commands */
	//	case	WFS_INF_DEP_STATUS							: _str.assign("WFS_INF_DEP_STATUS");							break;
	//	case	WFS_INF_DEP_CAPABILITIES					: _str.assign("WFS_INF_DEP_CAPABILITIES");						break;
	//		/* TTU Info Commands */
	//	case	WFS_INF_TTU_STATUS							: _str.assign("WFS_INF_TTU_STATUS");							break;
	//	case	WFS_INF_TTU_CAPABILITIES					: _str.assign("WFS_INF_TTU_CAPABILITIES");						break;
	//	case	WFS_INF_TTU_FORM_LIST						: _str.assign("WFS_INF_TTU_FORM_LIST");							break;
	//	case	WFS_INF_TTU_QUERY_FORM						: _str.assign("WFS_INF_TTU_QUERY_FORM");						break;
	//	case	WFS_INF_TTU_QUERY_FIELD						: _str.assign("WFS_INF_TTU_QUERY_FIELD");						break;
	//	case	WFS_INF_TTU_KEY_DETAIL						: _str.assign("WFS_INF_TTU_KEY_DETAIL");						break;
	//		/* SIU Info Commands */
	//	case	WFS_INF_SIU_STATUS							: _str.assign("WFS_INF_SIU_STATUS");							break;
	//	case	WFS_INF_SIU_CAPABILITIES					: _str.assign("WFS_INF_SIU_CAPABILITIES");						break;
	//		/* VDM Info Commands */
	//	case	WFS_INF_VDM_STATUS							: _str.assign("WFS_INF_VDM_STATUS");							break;
	//	case	WFS_INF_VDM_CAPABILITIES					: _str.assign("WFS_INF_VDM_CAPABILITIES");						break;
	//		/* CAM Info Commands */
	//	case	WFS_INF_CAM_STATUS							: _str.assign("WFS_INF_CAM_STATUS");							break;
	//	case	WFS_INF_CAM_CAPABILITIES					: _str.assign("WFS_INF_CAM_CAPABILITIES");						break;
	//		/* CIM Info Commands */
	//	case     WFS_INF_CIM_STATUS							: _str.assign("WFS_INF_CIM_STATUS");							break;
	//	case     WFS_INF_CIM_CAPABILITIES					: _str.assign("WFS_INF_CIM_CAPABILITIES");						break;
	//	case     WFS_INF_CIM_CASH_UNIT_INFO					: _str.assign("WFS_INF_CIM_CASH_UNIT_INFO");					break;
	//	case     WFS_INF_CIM_TELLER_INFO					: _str.assign("WFS_INF_CIM_TELLER_INFO");						break;
	//	case     WFS_INF_CIM_CURRENCY_EXP					: _str.assign("WFS_INF_CIM_CURRENCY_EXP");						break;
	//	case     WFS_INF_CIM_BANKNOTE_TYPES					: _str.assign("WFS_INF_CIM_BANKNOTE_TYPES");					break;
	//	case     WFS_INF_CIM_CASH_IN_STATUS					: _str.assign("WFS_INF_CIM_CASH_IN_STATUS");					break;
	//	case     WFS_INF_CIM_GET_P6_INFO					: _str.assign("WFS_INF_CIM_GET_P6_INFO");						break;
	//	case     WFS_INF_CIM_GET_P6_SIGNATURE				: _str.assign("WFS_INF_CIM_GET_P6_SIGNATURE");					break;
	//
	//	default												: _str.assign("Unknown Info Command");
	//	}
	//	return _str;
	//}
	//
	//static std::string XFSExecuteCommandParser(DWORD macro)
	//{
	//	std::string _str;
	//	
	//	switch (macro)
	//	{
	//		/* PTR Execute Commands */
	//	case	WFS_CMD_PTR_CONTROL_MEDIA					: _str.assign("WFS_CMD_PTR_CONTROL_MEDIA");						break;
	//	case	WFS_CMD_PTR_PRINT_FORM						: _str.assign("WFS_CMD_PTR_PRINT_FORM");						break;
	//	case	WFS_CMD_PTR_READ_FORM						: _str.assign("WFS_CMD_PTR_READ_FORM");							break;
	//	case	WFS_CMD_PTR_RAW_DATA						: _str.assign("WFS_CMD_PTR_RAW_DATA");							break;
	//	case	WFS_CMD_PTR_MEDIA_EXTENTS					: _str.assign("WFS_CMD_PTR_MEDIA_EXTENTS");						break;
	//	case	WFS_CMD_PTR_RESET_COUNT						: _str.assign("WFS_CMD_PTR_RESET_COUNT");						break;
	//	case	WFS_CMD_PTR_READ_IMAGE						: _str.assign("WFS_CMD_PTR_READ_IMAGE");						break;
	//	case	WFS_CMD_PTR_RESET							: _str.assign("WFS_CMD_PTR_RESET");								break;
	//	case	WFS_CMD_PTR_RETRACT_MEDIA					: _str.assign("WFS_CMD_PTR_RETRACT_MEDIA");						break;
	//	case	WFS_CMD_PTR_DISPENSE_PAPER					: _str.assign("WFS_CMD_PTR_DISPENSE_PAPER");					break;
	//		/* IDC Execute Commands */
	//	case	WFS_CMD_IDC_READ_TRACK						: _str.assign("WFS_CMD_IDC_READ_TRACK");						break;
	//	case	WFS_CMD_IDC_WRITE_TRACK						: _str.assign("WFS_CMD_IDC_WRITE_TRACK");						break;
	//	case	WFS_CMD_IDC_EJECT_CARD						: _str.assign("WFS_CMD_IDC_EJECT_CARD");						break;
	//	case	WFS_CMD_IDC_RETAIN_CARD						: _str.assign("WFS_CMD_IDC_RETAIN_CARD");						break;
	//	case	WFS_CMD_IDC_RESET_COUNT						: _str.assign("WFS_CMD_IDC_RESET_COUNT");						break;
	//	case	WFS_CMD_IDC_SETKEY							: _str.assign("WFS_CMD_IDC_SETKEY");							break;
	//	case	WFS_CMD_IDC_READ_RAW_DATA					: _str.assign("WFS_CMD_IDC_READ_RAW_DATA");						break;
	//	case	WFS_CMD_IDC_WRITE_RAW_DATA					: _str.assign("WFS_CMD_IDC_WRITE_RAW_DATA");					break;
	//	case	WFS_CMD_IDC_CHIP_IO							: _str.assign("WFS_CMD_IDC_CHIP_IO");							break;
	//	case	WFS_CMD_IDC_RESET							: _str.assign("WFS_CMD_IDC_RESET");								break;
	//	case	WFS_CMD_IDC_CHIP_POWER						: _str.assign("WFS_CMD_IDC_CHIP_POWER");						break;
	//	case	WFS_CMD_IDC_PARSE_DATA						: _str.assign("WFS_CMD_IDC_PARSE_DATA");						break;
	//		/* CDM Execute Commands */
	//	case	WFS_CMD_CDM_DENOMINATE						: _str.assign("WFS_CMD_CDM_DENOMINATE");						break;
	//	case	WFS_CMD_CDM_DISPENSE						: _str.assign("WFS_CMD_CDM_DISPENSE");							break;
	//	case	WFS_CMD_CDM_PRESENT							: _str.assign("WFS_CMD_CDM_PRESENT");							break;
	//	case	WFS_CMD_CDM_REJECT							: _str.assign("WFS_CMD_CDM_REJECT");							break;
	//	case	WFS_CMD_CDM_RETRACT							: _str.assign("WFS_CMD_CDM_RETRACT");							break;
	//	case	WFS_CMD_CDM_OPEN_SHUTTER					: _str.assign("WFS_CMD_CDM_OPEN_SHUTTER");						break;
	//	case	WFS_CMD_CDM_CLOSE_SHUTTER					: _str.assign("WFS_CMD_CDM_CLOSE_SHUTTER");						break;
	//	case	WFS_CMD_CDM_SET_TELLER_INFO					: _str.assign("WFS_CMD_CDM_SET_TELLER_INFO");					break;
	//	case	WFS_CMD_CDM_SET_CASH_UNIT_INFO				: _str.assign("WFS_CMD_CDM_SET_CASH_UNIT_INFO");				break;
	//	case	WFS_CMD_CDM_START_EXCHANGE					: _str.assign("WFS_CMD_CDM_START_EXCHANGE");					break;
	//	case	WFS_CMD_CDM_END_EXCHANGE					: _str.assign("WFS_CMD_CDM_END_EXCHANGE");						break;
	//	case	WFS_CMD_CDM_OPEN_SAFE_DOOR					: _str.assign("WFS_CMD_CDM_OPEN_SAFE_DOOR");					break;
	//	case	WFS_CMD_CDM_CALIBRATE_CASH_UNIT				: _str.assign("WFS_CMD_CDM_CALIBRATE_CASH_UNIT");				break;
	//	case	WFS_CMD_CDM_SET_MIX_TABLE					: _str.assign("WFS_CMD_CDM_SET_MIX_TABLE");						break;
	//	case	WFS_CMD_CDM_RESET							: _str.assign("WFS_CMD_CDM_RESET");								break;
	//	case	WFS_CMD_CDM_TEST_CASH_UNITS					: _str.assign("WFS_CMD_CDM_TEST_CASH_UNITS");					break;
	//	case	WFS_CMD_CDM_COUNT							: _str.assign("WFS_CMD_CDM_COUNT");								break;
	//		/* PIN Execute Commands */
	//	case	WFS_CMD_PIN_CRYPT							: _str.assign("WFS_CMD_PIN_CRYPT");								break;
	//	case	WFS_CMD_PIN_IMPORT_KEY						: _str.assign("WFS_CMD_PIN_IMPORT_KEY");						break;
	//	case	WFS_CMD_PIN_GET_PIN							: _str.assign("WFS_CMD_PIN_GET_PIN");							break;
	//	case	WFS_CMD_PIN_GET_PINBLOCK					: _str.assign("WFS_CMD_PIN_GET_PINBLOCK");						break;
	//	case	WFS_CMD_PIN_GET_DATA						: _str.assign("WFS_CMD_PIN_GET_DATA");							break;
	//	case	WFS_CMD_PIN_INITIALIZATION					: _str.assign("WFS_CMD_PIN_INITIALIZATION");					break;
	//	case	WFS_CMD_PIN_LOCAL_DES						: _str.assign("WFS_CMD_PIN_LOCAL_DES");							break;
	//	case	WFS_CMD_PIN_LOCAL_EUROCHEQUE				: _str.assign("WFS_CMD_PIN_LOCAL_EUROCHEQUE");					break;
	//	case	WFS_CMD_PIN_LOCAL_VISA						: _str.assign("WFS_CMD_PIN_LOCAL_VISA");						break;
	//	case	WFS_CMD_PIN_CREATE_OFFSET					: _str.assign("WFS_CMD_PIN_CREATE_OFFSET");						break;
	//	case	WFS_CMD_PIN_DERIVE_KEY						: _str.assign("WFS_CMD_PIN_DERIVE_KEY");						break;
	//	case	WFS_CMD_PIN_PRESENT_IDC						: _str.assign("WFS_CMD_PIN_PRESENT_IDC");						break;
	//	case	WFS_CMD_PIN_LOCAL_BANKSYS					: _str.assign("WFS_CMD_PIN_LOCAL_BANKSYS");						break;
	//	case	WFS_CMD_PIN_BANKSYS_IO						: _str.assign("WFS_CMD_PIN_BANKSYS_IO");						break;
	//	case	WFS_CMD_PIN_RESET							: _str.assign("WFS_CMD_PIN_RESET");								break;
	//	case	WFS_CMD_PIN_HSM_SET_TDATA					: _str.assign("WFS_CMD_PIN_HSM_SET_TDATA");						break;
	//	case	WFS_CMD_PIN_SECURE_MSG_SEND					: _str.assign("WFS_CMD_PIN_SECURE_MSG_SEND");					break;
	//	case	WFS_CMD_PIN_SECURE_MSG_RECEIVE				: _str.assign("WFS_CMD_PIN_SECURE_MSG_RECEIVE");				break;
	//	case	WFS_CMD_PIN_GET_JOURNAL						: _str.assign("WFS_CMD_PIN_GET_JOURNAL");						break;
	//	case	WFS_CMD_PIN_IMPORT_KEY_EX					: _str.assign("WFS_CMD_PIN_IMPORT_KEY_EX");						break;
	//	case	WFS_CMD_PIN_ENC_IO							: _str.assign("WFS_CMD_PIN_ENC_IO");							break;
	//	case	WFS_CMD_PIN_HSM_INIT						: _str.assign("WFS_CMD_PIN_HSM_INIT");							break;
	//	case	WFS_CMD_PIN_IMPORT_RSA_PUBLIC_KEY			: _str.assign("WFS_CMD_PIN_IMPORT_RSA_PUBLIC_KEY");				break;
	//	case	WFS_CMD_PIN_EXPORT_RSA_ISSUER_SIGNED_ITEM	: _str.assign("WFS_CMD_PIN_EXPORT_RSA_ISSUER_SIGNED_ITEM");		break;
	//	case	WFS_CMD_PIN_IMPORT_RSA_SIGNED_DES_KEY		: _str.assign("WFS_CMD_PIN_IMPORT_RSA_SIGNED_DES_KEY");			break;
	//	case	WFS_CMD_PIN_GENERATE_RSA_KEY_PAIR			: _str.assign("WFS_CMD_PIN_GENERATE_RSA_KEY_PAIR");				break;
	//	case	WFS_CMD_PIN_EXPORT_RSA_EPP_SIGNED_ITEM		: _str.assign("WFS_CMD_PIN_EXPORT_RSA_EPP_SIGNED_ITEM");		break;
	//	case	WFS_CMD_PIN_LOAD_CERTIFICATE				: _str.assign("WFS_CMD_PIN_LOAD_CERTIFICATE");					break;
	//	case	WFS_CMD_PIN_GET_CERTIFICATE					: _str.assign("WFS_CMD_PIN_GET_CERTIFICATE");					break;
	//	case	WFS_CMD_PIN_REPLACE_CERTIFICATE				: _str.assign("WFS_CMD_PIN_REPLACE_CERTIFICATE");				break;
	//	case	WFS_CMD_PIN_START_KEY_EXCHANGE				: _str.assign("WFS_CMD_PIN_START_KEY_EXCHANGE");				break;
	//	case	WFS_CMD_PIN_IMPORT_RSA_ENCIPHERED_PKCS7_KEY : _str.assign("WFS_CMD_PIN_IMPORT_RSA_ENCIPHERED_PKCS7_KEY");	break;
	//	case	WFS_CMD_PIN_EMV_IMPORT_PUBLIC_KEY			: _str.assign("WFS_CMD_PIN_EMV_IMPORT_PUBLIC_KEY");				break;
	//	case	WFS_CMD_PIN_DIGEST							: _str.assign("WFS_CMD_PIN_DIGEST");							break;
	//		/* CHK Execute Commands */
	//	case	WFS_CMD_CHK_PROCESS_FORM					: _str.assign("WFS_CMD_CHK_PROCESS_FORM");						break;
	//	case	WFS_CMD_CHK_RESET							: _str.assign("WFS_CMD_CHK_RESET");								break;
	//		/* DEP Execute Commands */
	//	case	WFS_CMD_DEP_ENTRY							: _str.assign("WFS_CMD_DEP_ENTRY");								break;
	//	case	WFS_CMD_DEP_DISPENSE						: _str.assign("WFS_CMD_DEP_DISPENSE");							break;
	//	case	WFS_CMD_DEP_RETRACT							: _str.assign("WFS_CMD_DEP_RETRACT");							break;
	//	case	WFS_CMD_DEP_CLEAR_TRANSPORT					: _str.assign("WFS_CMD_DEP_CLEAR_TRANSPORT");					break;
	//	case	WFS_CMD_DEP_RESET_COUNT						: _str.assign("WFS_CMD_DEP_RESET_COUNT");						break;
	//	case	WFS_CMD_DEP_RESET							: _str.assign("WFS_CMD_DEP_RESET");								break;
	//		/* TTU Execute Commands */
	//	case	WFS_CMD_TTU_BEEP							: _str.assign("WFS_CMD_TTU_BEEP");								break;
	//	case	WFS_CMD_TTU_CLEARSCREEN						: _str.assign("WFS_CMD_TTU_CLEARSCREEN");						break;
	//	case	WFS_CMD_TTU_DISPLIGHT						: _str.assign("WFS_CMD_TTU_DISPLIGHT");							break;
	//	case	WFS_CMD_TTU_SET_LED							: _str.assign("WFS_CMD_TTU_SET_LED");							break;
	//	case	WFS_CMD_TTU_SET_RESOLUTION					: _str.assign("WFS_CMD_TTU_SET_RESOLUTION");					break;
	//	case	WFS_CMD_TTU_WRITE_FORM						: _str.assign("WFS_CMD_TTU_WRITE_FORM");						break;
	//	case	WFS_CMD_TTU_READ_FORM						: _str.assign("WFS_CMD_TTU_READ_FORM");							break;
	//	case	WFS_CMD_TTU_WRITE							: _str.assign("WFS_CMD_TTU_WRITE");								break;
	//	case	WFS_CMD_TTU_READ							: _str.assign("WFS_CMD_TTU_READ");								break;
	//	case	WFS_CMD_TTU_RESET							: _str.assign("WFS_CMD_TTU_RESET");								break;
	//		/* SIU Execute Commands */
	//	case	WFS_CMD_SIU_ENABLE_EVENTS					: _str.assign("WFS_CMD_SIU_ENABLE_EVENTS");						break;
	//	case	WFS_CMD_SIU_SET_PORTS						: _str.assign("WFS_CMD_SIU_SET_PORTS");							break;
	//	case	WFS_CMD_SIU_SET_DOOR						: _str.assign("WFS_CMD_SIU_SET_DOOR");							break;
	//	case	WFS_CMD_SIU_SET_INDICATOR					: _str.assign("WFS_CMD_SIU_SET_INDICATOR");						break;
	//	case	WFS_CMD_SIU_SET_AUXILIARY					: _str.assign("WFS_CMD_SIU_SET_AUXILIARY");						break;
	//	case	WFS_CMD_SIU_SET_GUIDLIGHT					: _str.assign("WFS_CMD_SIU_SET_GUIDLIGHT");						break;
	//	case	WFS_CMD_SIU_RESET							: _str.assign("WFS_CMD_SIU_RESET");								break;
	//		/* VDM Execute Commands */
	//	case	WFS_CMD_VDM_ENTER_MODE_REQ					: _str.assign("WFS_CMD_VDM_ENTER_MODE_REQ");					break;
	//	case	WFS_CMD_VDM_ENTER_MODE_ACK					: _str.assign("WFS_CMD_VDM_ENTER_MODE_ACK");					break;
	//	case	WFS_CMD_VDM_EXIT_MODE_REQ					: _str.assign("WFS_CMD_VDM_EXIT_MODE_REQ");						break;
	//	case	WFS_CMD_VDM_EXIT_MODE_ACK					: _str.assign("WFS_CMD_VDM_EXIT_MODE_ACK");						break;
	//		/* CAM Execute Commands */
	//	case	WFS_CMD_CAM_TAKE_PICTURE					: _str.assign("WFS_CMD_CAM_TAKE_PICTURE");						break;
	//	case	WFS_CMD_CAM_RESET							: _str.assign("WFS_CMD_CAM_RESET");								break;
	//		/* CIM Execute Commands */
	//	case	WFS_CMD_CIM_CASH_IN_START					: _str.assign("WFS_CMD_CIM_CASH_IN_START");						break;
	//	case	WFS_CMD_CIM_CASH_IN							: _str.assign("WFS_CMD_CIM_CASH_IN");							break;
	//	case	WFS_CMD_CIM_CASH_IN_END						: _str.assign("WFS_CMD_CIM_CASH_IN_END");						break;
	//	case	WFS_CMD_CIM_CASH_IN_ROLLBACK				: _str.assign("WFS_CMD_CIM_CASH_IN_ROLLBACK");					break;
	//	case	WFS_CMD_CIM_RETRACT							: _str.assign("WFS_CMD_CIM_RETRACT");							break;
	//	case	WFS_CMD_CIM_OPEN_SHUTTER					: _str.assign("WFS_CMD_CIM_OPEN_SHUTTER");						break;
	//	case	WFS_CMD_CIM_CLOSE_SHUTTER					: _str.assign("WFS_CMD_CIM_CLOSE_SHUTTER");						break;
	//	case	WFS_CMD_CIM_SET_TELLER_INFO					: _str.assign("WFS_CMD_CIM_SET_TELLER_INFO");					break;
	//	case	WFS_CMD_CIM_SET_CASH_UNIT_INFO				: _str.assign("WFS_CMD_CIM_SET_CASH_UNIT_INFO");				break;
	//	case	WFS_CMD_CIM_START_EXCHANGE					: _str.assign("WFS_CMD_CIM_START_EXCHANGE");					break;
	//	case	WFS_CMD_CIM_END_EXCHANGE					: _str.assign("WFS_CMD_CIM_END_EXCHANGE");						break;
	//	case	WFS_CMD_CIM_OPEN_SAFE_DOOR					: _str.assign("WFS_CMD_CIM_OPEN_SAFE_DOOR");					break;
	//	case	WFS_CMD_CIM_RESET							: _str.assign("WFS_CMD_CIM_RESET");								break;
	//	case	WFS_CMD_CIM_CONFIGURE_CASH_IN_UNITS			: _str.assign("WFS_CMD_CIM_CONFIGURE_CASH_IN_UNITS");			break;
	//	case	WFS_CMD_CIM_CONFIGURE_NOTETYPES				: _str.assign("WFS_CMD_CIM_CONFIGURE_NOTETYPES");				break;
	//	case	WFS_CMD_CIM_CREATE_P6_SIGNATURE				: _str.assign("WFS_CMD_CIM_CREATE_P6_SIGNATURE");				break;
	//	case	WFS_CMD_CIM_AUDIT							: _str.assign("WFS_CMD_CIM_AUDIT");								break;
	//
	//	default												: _str.assign("Unknown Execute Command");						break;
	//	}
	//	return _str;
	//}
	//
	//static std::string TTErrorParser(DWORD macro)
	//{
	//	std::string _str;
	//	
	//	switch (macro)
	//	{
	//		/* PTR Execute Commands */
	//	case	TT_SUCCESS									: _str.assign("TT_SUCCESS");									break;
	//	case	TT_ERR_NOTINITIALIZED						: _str.assign("TT_ERR_NOTINITIALIZED");							break;
	//	case	TT_ERR_NOT_REGISTERED						: _str.assign("TT_ERR_NOT_REGISTERED");							break;
	//	case	TT_ERR_INVALID_POINTER						: _str.assign("TT_ERR_INVALID_POINTER");						break;
	//	case	TT_ERR_INVALID_DATA							: _str.assign("TT_ERR_INVALID_DATA");							break;
	//	case	TT_ERR_XFSASYNC								: _str.assign("TT_ERR_XFSASYNC");								break;
	//	default												: _str.assign("Unknown TTError");								break;
	//	}
	//	return _str;
	//	}
	//}
}

#endif // !DEVICEUTILITY_H