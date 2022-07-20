#pragma once

#ifndef TTFRAMEWORKUTILITY_H
#define TTFRAMEWORKUTILITY_H

#include <memory>
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <sstream>
#include <limits>

#include "TTFRM_macro.h"

#include "../TTLogger/CODE/ITTLogger.h"

#undef max

#define SAFERELEASE(lpp)							TTFRMU::SafeRelease(lpp);
#define SAFEFREEMEMORY(lpp)							TTFRMU::SafeFreeMemory(lpp);

#define SAFEALLOCCOPYMEMORY(lppDest, lpSrc, Size)	TTFRMU::SafeAllocCopyMemory(lppDest, lpSrc, Size);
#define SAFEALLOCCOPYMEMORY_N(lppDest, lpSrc, Size)	TTFRMU::SafeAllocCopyMemory_N(lppDest, lpSrc, Size);
#define SAFEALLOCCOPYSTRING(lppDest, lpSrc)			TTFRMU::SafeAllocCopyString(lppDest, lpSrc);
#define SAFECOPYMEMORY(lpDest, lpSrc, Size)			TTFRMU::SafeCopyMemory(lpDest, lpSrc, Size);
#define SAFECOPYMEMORY_N(lpDest, lpSrc, Size)		TTFRMU::SafeCopyMemory_N(lpDest, lpSrc, Size);
#define SAFECOPYSTRING(lpDest, lpSrc)				TTFRMU::SafeCopyString(lpDest, lpSrc);
#define SAFEPTR(lp)									if (TTFRMU::CheckPointer(lp))
#define UNSAFEPTR(lp)								if (!TTFRMU::CheckPointer(lp))

#define ELSE										else

#define ASSERTSAFEPTR(str, ptr)						UNSAFEPTR(ptr) { ERRORLOG("%s", str); return false; }
#define ASSERTSAFEPTR_VOID(str, ptr)				UNSAFEPTR(ptr) { ERRORLOG("%s", str); return; }

#define MAKESTRING(lpstr, len)						TTFRMU::MakeString(lpstr, len)
#define MAKESTRING(wstr)							TTFRMU::MakeString(wstr)

namespace TTFRMU
{
	/************************************************************************/
	/**********************ExceptionFilter Functions*************************/
	/************************************************************************/

	static int ExceptionFilter(unsigned int code, struct _EXCEPTION_POINTERS* ep)
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
		}
	}

	/************************************************************************/
	/**************************Safe Functions********************************/
	/************************************************************************/

	template <typename ARRAY>
	static inline SIZE_T Size_ARRAY_N(ARRAY Array[])
	{
		size_t _index = 0;
		while (Array[_index])
		{
			if (NULL == Array[_index])
				break;

			_index++;
		}

		return _index;
	}

	/************************************************************************/
	/**************************Safe Functions********************************/
	/************************************************************************/

	template <typename T, typename = std::enable_if_t<std::is_pointer<T>::value || std::is_null_pointer<T>::value>>
	inline bool CheckPointer(T p)
	{
		// Do not use SAFEPTR here
		if (nullptr == p)
			return false;
		return true;
	}

	template <typename T>
	inline bool CheckPointer(std::shared_ptr<T>& p)
	{
		// Do not use SAFEPTR here
		if (!p)
			return false;
		return true;
	}

	template <typename T>
	inline bool CheckPointer(std::weak_ptr<T>& p)
	{
		// Do not use SAFEPTR here
		std::shared_ptr<T> _sharedPtr = p.lock();
		if (!_sharedPtr)
			return false;
		return true;
	}

	template <typename T>
	inline bool CheckPointer(std::unique_ptr<T>& p)
	{
		// Do not use SAFEPTR here
		if (!p)
			return false;
		return true;
	}

	template <>
	inline bool CheckPointer(char* _lpstr)
	{
		// Do not use SAFEPTR here
		if (nullptr == _lpstr || NULL == _lpstr[0])
			return false;
		return true;
	}

	inline bool CheckPointer(int _int)
	{
		// Do not use SAFEPTR here
		if (NULL == _int)
			return false;
		return true;
	}

	template <typename T, typename = std::enable_if_t<std::is_pointer<T*>::value>>
	void SafeRelease(T** lpp)
	{
		UNSAFEPTR(lpp)
			return;
		UNSAFEPTR(*lpp)
			return;

		__try
		{
			delete *lpp;
		}
		__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("SafeRelease - Exception deleting _obj");
		}

		*lpp = NULL;
	}

	template <typename T>
	inline void SafeRelease(std::shared_ptr<T> obj)
	{
		if (obj)
			if (obj.get())
				obj.reset();
	}

	template <typename T1, typename T2, typename = std::enable_if_t<std::is_pointer<T1>::value && std::is_pointer<T2>::value>>
	inline void SafeCopyMemory(T1 lpDestination, T2 lpSource, SIZE_T Size)
	{
		// Do not use SAFECOPYMEMORY or SAFEALLOCCOPYMEMORY here

		if (0 == Size)
			return;

		SAFEPTR(lpSource)
		{
			__try
			{
				ZeroMemory(lpDestination, Size);
				CopyMemory((LPVOID)lpDestination, (LPVOID)lpSource, Size);
			}
			__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
			{
				ERRORLOG("SafeCopyMemory - EXCEPTION occurred while trying to Copy Memory");
			}
		}
	}

	inline void SafeCopyMemory(void* lpDestination, void* lpSource, SIZE_T Size)
	{
		// Do not use SAFECOPYMEMORY or SAFEALLOCCOPYMEMORY here

		if (nullptr == lpSource || nullptr == lpDestination || 0 >= Size)
			return;

		::ZeroMemory(lpDestination, Size);
		::CopyMemory(lpDestination, lpSource, Size);
	}

	template <typename T>
	inline void SafeCopyMemory(std::vector<T>& Destination, const void* Source, SIZE_T Size)
	{
		// Do not use SAFECOPYMEMORY or SAFEALLOCCOPYMEMORY here

		if (nullptr == Source || 0 >= Size)
			return;

		SIZE_T _index{ 0 };
		__try
		{
			for (_index = 0; _index < Size; ++_index)
			{
				T _elem = (T)*((char*)Source + _index);
				Destination.push_back(_elem);
			}
		}
		__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("SafeAllocCopyMemory - EXCEPTION occurred while trying to push_back");
		}
	}

	template <typename T1, typename T2, typename = std::enable_if_t<std::is_pointer<T1>::value&& std::is_pointer<T2>::value>>
	inline void SafeCopyMemory_N(T1 lpDestination, T2 lpSource, SIZE_T Size)
	{
		// Do not use SAFECOPYMEMORY or SAFEALLOCCOPYMEMORY here

		if (nullptr == Source || 0 >= _size)
			return;

		SafeCopyMemory(lpDestination, lpSource, Size);
		lpDestination[Size + 1] = NULL;
	}

	inline void SafeCopyString(char* lpszDestination, const std::string& strSource)
	{
		UNSAFEPTR(lpszDestination)
			return;

		__try
		{
			::ZeroMemory(lpszDestination, strSource.length() + 1);
			::CopyMemory(lpszDestination, strSource.c_str(), strSource.length());
		}
		__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("SafeCopyString - EXCEPTION occurred while trying to copy string");
		}
	}

	template <typename T>
	inline void SafeAllocCopyMemory(T** lppDestination, const void* pSource, const size_t Size)
	{
		// Do not use SAFEALLOCCOPYMEMORY here

		UNSAFEPTR(lppDestination)
			return;

		*lppDestination = nullptr;

		if (0 == Size)
			return;

		__try
		{
			*lppDestination = (T*)::calloc(1, Size);
		}
		__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("SafeAllocCopyMemory - EXCEPTION occurred while trying to calloc");
			return;
		}

		SAFECOPYMEMORY(*lppDestination, pSource, Size)
	}

	template <typename T>
	inline void SafeAllocCopyMemory_N(T** lppDestination, const void* pSource, const size_t Size)
	{
		// Do not use SAFEALLOCCOPYMEMORY here

		UNSAFEPTR(lppDestination)
			return;

		*lppDestination = nullptr;

		if (0 == Size)
			return;

		size_t _size = Size + sizeof(T);

		__try
		{
			*lppDestination = (T*)::calloc(1, _size);
		}
		__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("SafeAllocCopyMemory_N - EXCEPTION occurred while trying to calloc");
			return;
		}

		SAFECOPYMEMORY(*lppDestination, pSource, _size)
	}

	inline void SafeAllocCopyString(char** lppszDestination, const std::string& strSource)
	{
		UNSAFEPTR(lppszDestination)
			return;

		if (strSource.empty())
			*lppszDestination = nullptr;

		*lppszDestination = (char*)::calloc(1, strSource.length() + 1);
		::CopyMemory(*lppszDestination, strSource.c_str(), strSource.length());
	}

	inline void SafeAllocCopyString(BYTE** lppDestination, const std::string& strSource)
	{
		SafeAllocCopyString((char**)lppDestination, strSource);
	}

	inline void SafeAllocCopyString(wchar_t** lppwszDestination, const std::wstring& wstrSource)
	{
		UNSAFEPTR(lppwszDestination)
			return;

		if (wstrSource.empty())
			*lppwszDestination = nullptr;

		*lppwszDestination = (wchar_t*)::calloc(1, (wstrSource.length() + 1) * sizeof(wchar_t));
		::CopyMemory(*lppwszDestination, wstrSource.c_str(), (wstrSource.length() + 1) * sizeof(wchar_t));
	}

	inline void SafeAllocCopyString(BYTE** lppszDestination, const std::wstring& wstrSource)
	{
		SafeAllocCopyString((wchar_t**)lppszDestination, wstrSource);
	}

	template <typename T>
	inline void SafeFreeMemory(T** lppDestination)
	{
		UNSAFEPTR(lppDestination)
			return;
		UNSAFEPTR(*lppDestination)
			return;

		__try
		{
			::free(*lppDestination);
		}
		__except (ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("SafeFreeMemory - EXCEPTION occurred while trying to free Memory");
		}
		*lppDestination = NULL;
	}

	/************************************************************************/
	/*************************Convert Functions******************************/
	/************************************************************************/

	static inline std::string MakeString(const char* lpsz, const size_t len)
	{
		UNSAFEPTR(lpsz)
			return std::string{};

		if(len)
				return std::string{ lpsz, 0, len };
		else
			return std::string{};
	}

	static inline std::string MakeString(const wchar_t* lpwsz, const size_t len)
	{
		UNSAFEPTR(lpwsz)
			return std::string{};

		if (len)
		{
			std::wstring _wstr{ lpwsz, 0, len };
			return std::string{ _wstr.begin(), _wstr.end() };
		}
		else
			return std::string{};
	}

	static inline std::string MakeString(const std::wstring& wstr)
	{
		return std::string{ wstr.begin(), wstr.end() };
	}

	template <typename T>
	static inline void CopyArray2vector(std::vector<T>& vec, const T arr[], size_t arrSize)
	{
		__try
		{
			for (size_t i = 0; i < arrSize; ++i)
				vec.push_back(arr[i]);
		}
		__except(ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))
		{
			ERRORLOG("CopyArray2vector - EXCEPTION occurred while trying to copy");
		}
	}

	template <typename T>
	static inline void CopyNArray2vector(std::vector<T>& vec, const T arr[])
	{
		size_t _index = 0;
		while (arr[_index])
			_index++;

		CopyArray2vector(vec, arr, _index);
	}

	static std::string ByteArray2Str(const BYTE* b, size_t _size)
	{
		if (0 == _size)
			return std::string("");

		SAFEPTR(b)
		{
			std::ostringstream str;

			str << " - HEX: ";
			for (size_t i = 0; i < _size; ++i)
			{
				str << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(b[i]) << ' ';
			}
			str << " - DECIMAL: ";
			for (size_t i = 0; i < _size; ++i)
			{
				str << std::dec << std::setfill('0') << static_cast<char>(b[i]);
			}

			return str.str();
		}
		ELSE
			return std::string("");
	}

	template <typename ARR>
	inline std::string Array2Str(const ARR Array, const SIZE_T Count)
	{
		std::string String("");
		SAFEPTR(Array)
		{
			std::stringstream stream;
			for (SIZE_T i = 0; i < Count; ++i)
				stream << Array[i] << ' ';

			String.assign(stream.str());
		}
		return String;
	}

	template <typename T>
	inline std::string Vect2Str(std::vector<T>Vector)
	{
		std::stringstream _stream{};
		for (const auto& elem : Vector)
			_stream << elem << " ";

		return _stream.str();
	}

	template <typename RAWTYPE, typename SHAREDTYPE>
	inline auto Shared2Raw(std::shared_ptr<SHAREDTYPE> shared)
	{
		RAWTYPE * _raw = static_cast<RAWTYPE*>(shared.get());
		return _raw;
	}

	template <typename RAWTYPE, typename WEAKTYPE>
	inline auto Weak2Raw(std::weak_ptr<WEAKTYPE> weak)
	{
		RAWTYPE * _ptr = nullptr;

		auto _shared = weak.lock();
		UNSAFEPTR(_shared)	return _ptr;

		_ptr = Shared2Raw<RAWTYPE>(_shared);
		UNSAFEPTR(_ptr) return _ptr;

		return _ptr;
	}

	template <typename SHAREDTYPE, typename UNIQUETYPE>
	inline auto Unique2Shared(std::unique_ptr<UNIQUETYPE> unique)
	{
		SHAREDTYPE _shared = std::move(unique);
		return _shared;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Function to convert a character string to binary string
	inline std::string convertStringToBinary(const std::string strRawData)
	{
		std::string _strBinary;
		_strBinary.clear();

		for (const auto& c : strRawData)
			_strBinary.append(std::bitset<8>(c).to_string());

		return _strBinary;
	}

	// Function to convert a binary string to character string
	inline std::string convertBinaryToString(std::string binaryString)
	{
		if (binaryString.length() % 8 != 0)
			return "";

		std::vector<std::bitset<8>> _vecBinaryData;
		for (size_t i = 0; i < binaryString.length(); i += 8)
		{
			std::bitset<8> _b(binaryString.c_str() + i, 8);
			_vecBinaryData.push_back(_b);
		}

		std::string _strText;

		for (const auto& byte : _vecBinaryData)
			_strText.push_back((char)byte.to_ulong());

		return _strText;
	}

	// Function to convert a number in decimal to binary
	inline std::string convertDecimalToBinary(int decimal)
	{
		std::string binary;
		while (decimal != 0) {
			binary = (decimal % 2 == 0 ? "0" : "1") + binary;
			decimal = decimal / 2;
		}
		while (binary.length() < 4) {
			binary = "0" + binary;
		}
		return binary;
	}

	// Function to convert a number in binary to decimal
	inline int convertBinaryToDecimal(std::string binary)
	{
		int decimal = 0;
		int counter = 0;
		int size = binary.length();
		for (int i = size - 1; i >= 0; i--)
		{
			if (binary[i] == '1') {
				decimal += pow(2, counter);
			}
			counter++;
		}
		return decimal;
	}

	// Function to do a circular left shift by 1
	inline std::string shift_left_once(std::string key_chunk)
	{
		std::string shifted = "";
		for (int i = 1; i < 28; i++) {
			shifted += key_chunk[i];
		}
		shifted += key_chunk[0];
		return shifted;
	}

	// Function to do a circular left shift by 2
	inline std::string shift_left_twice(std::string key_chunk)
	{
		std::string shifted = "";
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j < 28; j++) {
				shifted += key_chunk[j];
			}
			shifted += key_chunk[0];
			key_chunk = shifted;
			shifted = "";
		}
		return key_chunk;
	}

	// Function to compute xor between two strings
	inline std::string Xor(std::string a, std::string b)
	{
		std::string result = "";
		int size = b.size();
		for (int i = 0; i < size; i++) {
			if (a[i] != b[i]) {
				result += "1";
			}
			else {
				result += "0";
			}
		}
		return result;
	}

	/************************************************************************/
	/*************************Generator Functions****************************/
	/************************************************************************/

	template<typename T>
	inline auto TTGenerateRandomNumber(unsigned short seed)
	{
		T T_RandomNumber = 1;

		unsigned short uiSeed = seed * ::GetCurrentProcessId();
		if (INT_MAX <= uiSeed)
			uiSeed = 1;

		std::srand(::GetCurrentProcessId() + uiSeed);

		do {
			T_RandomNumber = std::rand() * std::rand() + std::rand();
		} while (1 >= T_RandomNumber || std::numeric_limits<unsigned long long int>::max() <= T_RandomNumber);

		return T_RandomNumber;
	}
}

#endif // !TTFRAMEWORKUTILITY_H