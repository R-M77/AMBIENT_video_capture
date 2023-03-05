/**
*
* Copyright (C) FEIG ELECTRONIC GmbH. All rights reserved. Do not disclose.
*
* This software is the confidential and proprietary information of
* FEIG ELECTRONIC GmbH ("Confidential Information"). You shall not
* disclose such Confidential Information and shall use it only in
* accordance with the terms of the license agreement you entered
* into with FEIG ELECTRONIC GmbH.
*/

#if !defined(_FEDM_CORE_UTILITY_HEX_CONVERT_H_INCLUDED_)
#define _FEDM_CORE_UTILITY_HEX_CONVERT_H_INCLUDED_

#include <string>
#include <stdint.h>
#include "../source/FEDM.h"

// STL - Standard Template Library
using namespace std;

namespace FEDM
{
	namespace Core
	{
		namespace Utility
		{
			/// @brief Class providing common conversion methods
			///
			/// <b>Description</b><br>
			/// All methods of this class are static.
			class _FEDM_ISC_CORE_EXT_CLASS HexConvert
			{

			public:

				/// @brief Converts hex-coded string (std::string) to int value
				///
				/// @param[in] sInStr input string
				/// @param[out] iOut pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 8 chars in sInStr<br>
				///
				/// <b>Example:</b><br>
				/// sInStr = "1122F05E"<br>
				/// iOut = 287502430<br>
				static int HexStrToInt(string sInStr, int* iOut);

				/// @brief Converts hex-coded string (std::string) to unsigned int value
				///
				/// @param[in] sInStr input string
				/// @param[out] uiOut pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 8 chars in sInStr<br>
				///
				/// <b>Example:</b><br>
				/// sInStr = "1122F05E"<br>
				/// uiOut = 287502430<br>
				static int HexStrToUInt(std::string sInStr, unsigned int* uiOut);

				/// @brief Converts hex-coded string (std::string) to int64_t value
				///
				/// @param[in] sInStr input string
				/// @param[out] i64Out pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 16 chars in sInStr<br>
				///
				/// <b>Example:</b><br>
				/// sInStr = "1122F05E1122F05E"<br>
				/// i64Out = 1234813534658031710<br>
				static int HexStrToInt64(std::string sInStr, int64_t* i64Out);

				/// @brief Converts hex-coded string (std::string) to uint64_t value
				///
				/// @param[in] sInStr input string
				/// @param[out] ui64Out pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 16 chars in sInStr<br>
				///
				/// <b>Example:</b><br>
				/// sInStr = "1122F05E1122F05E"<br>
				/// ui64Out = 1234813534658031710<br>
				static int HexStrToUInt64(std::string sInStr, uint64_t* ui64Out);

				/// @brief Converts hex-coded string (std::string) to unsigned char buffer value
				///
				/// @param[in] sInStr input string
				/// @param[out] ucOutBuf pointer to converted data
				/// @param[in] iOutBufLen size of data buffer
				/// @return
				/// - > 0 number of bytes in data buffer
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: no null-termination<br>
				///
				/// <b>Example:</b><br>
				/// sInStr = "1122F05E"<br>
				/// ucOutBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				static int HexStrToHexUChar(std::string sInStr, unsigned char* ucOutBuf, int iOutBufLen);

				/// @brief Converts byte array value to int value
				///
				/// @param[in] ucInBuf pointer to buffer with input data
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] iOut pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: max. 4 bytes<br>
				///
				/// <b>Example:</b><br>
				/// ucInBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iBufLen = 4<br>
				/// iOut = 287502430<br>
				static int HexUCharToInt(unsigned char* ucInBuf, int iBufLen, int* iOut);

				/// @brief Converts byte array value to unsigned int value
				///
				/// @param[in] ucInBuf pointer to buffer with input data
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] uiOut pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: max. 4 bytes<br>
				///
				/// <b>Example:</b><br>
				/// ucInBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iBufLen = 4<br>
				/// uiOut = 287502430<br>
				static int HexUCharToUInt(unsigned char* ucInBuf, int iBufLen, unsigned int* uiOut);

				/// @brief Converts byte array value to int64_t value
				///
				/// @param[in] ucInBuf pointer to buffer with input data
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] i64Out pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: max. 8 bytes<br>
				///
				/// <b>Example:</b><br>
				/// ucInBuf = {0x11, 0x22, 0xF0, 0x5E, 0x11, 0x22, 0xF0, 0x5E}<br>
				/// iBufLen = 8<br>
				/// i64Out = 1234813534658031710<br>
				static int HexUCharToInt64(unsigned char* ucInBuf, int iBufLen, int64_t* i64Out);

				/// @brief Converts byte array value to uint64_t value
				///
				/// @param[in] ucInBuf pointer to buffer with input data
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] ui64Out pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: max. 8 bytes<br>
				///
				/// <b>Example:</b><br>
				/// ucInBuf = {0x11, 0x22, 0xF0, 0x5E, 0x11, 0x22, 0xF0, 0x5E}<br>
				/// iBufLen = 8<br>
				/// ui64Out = 1234813534658031710<br>
				static int HexUCharToUInt64(unsigned char* ucInBuf, int iBufLen, uint64_t* ui64Out);

				/// @brief Converts byte array value to hex-coded char string
				///
				/// @param[in] ucInBuf pointer to buffer with input data
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] cOut pointer to converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: output buffer has to include additional '\0'<br>
				///
				/// <b>Example:</b><br>
				/// ucInBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iBufLen = 4<br>
				/// cOut = "1122F05E"<br>
				/// iOutBufLen = 9 (or higher)<br>
				static int HexUCharToHexChar(unsigned char* ucInBuf, int iBufLen, char* cOut, int iOutBufLen);

				/// @brief Converts byte array value to hex-coded string (std::string)
				///
				/// @param[in] ucInBuf pointer to buffer with input data
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] sOut buffer with converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///
				/// <b>Example:</b><br>
				/// ucInBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iBufLen = 4<br>
				/// sOut = "1122F05E"<br>
				static int HexUCharToHexStr(unsigned char* ucInBuf, int iBufLen, std::string& sOut);
			
				/// @brief Converts hex-coded char string to int value
				///
				/// @param[in] cInBuf pointer to buffer with input string
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] iOut pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 8 chars in cInBuf<br>
				///
				/// <b>Example:</b><br>
				/// cInBuf = "1122F05E"<br>
				/// iBufLen = 8<br>
				/// iOut = 287502430<br>
				static int HexCharToInt(char* cInBuf, int iBufLen, int* iOut);

				/// @brief Converts hex-coded char string to unsigned int value
				///
				/// @param[in] cInBuf pointer to buffer with input string
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] uiOut pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 8 chars in cInBuf<br>
				///
				/// <b>Example:</b><br>
				/// cInBuf = "1122F05E"<br>
				/// iBufLen = 8<br>
				/// uiOut = 287502430<br>
				static int HexCharToUInt(char* cInBuf, int iBufLen, unsigned int* uiOut);

				/// @brief Converts hex-coded char string to int64_t value
				///
				/// @param[in] cInBuf pointer to buffer with input string
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] i64Out pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 16 chars in cInBuf<br>
				///
				/// <b>Example:</b><br>
				/// cInBuf = "1122F05E1122F05E"<br>
				/// iBufLen = 8<br>
				/// i64Out = 1234813534658031710<br>
				static int HexCharToInt64(char* cInBuf, int iBufLen, int64_t* i64Out);

				/// @brief Converts hex-coded char string to uint64_t value
				///
				/// @param[in] cInBuf pointer to buffer with input string
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] ui64Out pointer to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				///	attention: max. 16 chars in cInBuf<br>
				///
				/// <b>Example:</b><br>
				/// cInBuf = "1122F05E1122F05E"<br>
				/// iBufLen = 8<br>
				/// ui64Out = 1234813534658031710<br>
				static int HexCharToUInt64(char* cInBuf, int iBufLen, uint64_t* ui64Out);

				/// @brief Converts hex-coded char string to unsigned char buffer
				///
				/// @param[in] cInBuf pointer to buffer with input string
				/// @param[in] iBufLen number of bytes in input buffer
				/// @param[out] ucOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// all chars except "0..9, a..f, A..F" will be removed<br>
				/// attention: no null-termination<br>
				///
				/// <b>Example:</b><br>
				/// cInBuf = "1122F05E"<br>
				/// iBufLen = 8<br>
				/// ucOutBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iOutBufLen = 4 (or higher)
				static int HexCharToHexUChar(char* cInBuf, int iBufLen, unsigned char* ucOutBuf, int iOutBufLen);

				/// @brief Converts int value to hex-coded string (std::string)
				///
				/// @param[in] iIn input data
				/// @param[out] sOut reference to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///
				/// <b>Example:</b><br>
				/// iIn = 287502430<br>
				/// sOut = "1122F05E"<br>
				static int IntToHexStr(int iIn, std::string& sOut);

				/// @brief Converts unsigned int value to hex-coded string (std::string)
				///
				/// @param[in] uiIn input data
				/// @param[out] sOut reference to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///
				/// <b>Example:</b><br>
				/// uiIn = 287502430<br>
				/// sOut = "1122F05E"<br>
				static int UIntToHexStr(unsigned int uiIn, std::string& sOut);

				/// @brief Converts int64_t value to hex-coded string (std::string)
				///
				/// @param[in] i64In input data
				/// @param[out] sOut reference to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///
				/// <b>Example:</b><br>
				/// i64In = 1234813534658031710<br>
				/// sOut = "1122F05E1122F05E"<br>
				static int Int64ToHexStr(int64_t i64In, std::string& sOut);

				/// @brief Converts uint64_t value to hex-coded string (std::string)
				///
				/// @param[in] ui64In input data
				/// @param[out] sOut reference to converted data
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///
				/// <b>Example:</b><br>
				/// ui64In = 1234813534658031710<br>
				/// sOut = "1122F05E1122F05E"<br>
				static int UInt64ToHexStr(uint64_t ui64In, std::string& sOut);

				/// @brief Converts int value to hex-coded char string
				///
				/// @param[in] iIn input data
				/// @param[out] cOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: output buffer has to include additional '\0'<br>
				///
				/// <b>Example:</b><br>
				/// iIn = 287502430<br>
				/// cOutBuf = "1122F05E"<br>
				/// iOutBufLen = 9 (or higher)<br>
				static int IntToHexChar(int iIn, char* cOutBuf, int iOutBufLen);

				/// @brief Converts unsigned int value to hex-coded char string
				///
				/// @param[in] uiIn input data
				/// @param[out] cOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: output buffer has to include additional '\0'<br>
				///
				/// <b>Example:</b><br>
				/// uiIn = 287502430<br>
				/// cOutBuf = "1122F05E"<br>
				/// iOutBufLen = 9 (or higher)<br>
				static int UIntToHexChar(unsigned int uiIn, char* cOutBuf, int iOutBufLen);

				/// @brief Converts int64_t value to hex-coded char string
				///
				/// @param[in] i64In input data
				/// @param[out] cOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: output buffer has to include additional '\0'<br>
				///
				/// <b>Example:</b><br>
				/// i64In = 1234813534658031710<br>
				/// cOutBuf = "1122F05E1122F05E"<br>
				/// iOutBufLen = 17 (or higher)<br>
				static int Int64ToHexChar(int64_t i64In, char* cOutBuf, int iOutBufLen);

				/// @brief Converts uint64_t value to hex-coded char string
				///
				/// @param[in] ui64In input data
				/// @param[out] cOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				///	attention: output buffer has to include additional '\0'<br>
				///
				/// <b>Example:</b><br>
				/// ui64In = 1234813534658031710<br>
				/// cOutBuf = "1122F05E1122F05E"<br>
				/// iOutBufLen = 17 (or higher)<br>
				static int UInt64ToHexChar(uint64_t ui64In, char* cOutBuf, int iOutBufLen);

				/// @brief Converts int value to unsigned char byte array
				///
				/// @param[in] iIn input data
				/// @param[out] ucOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// attention: no null-termination<br>
				///
				/// <b>Example:</b><br>
				/// iIn = 287502430<br>
				/// ucOutBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iOutBufLen = 4 (or higher)
				static int IntToHexUChar(int iIn, unsigned char* ucOutBuf, int iOutBufLen);

				/// @brief Converts unsigned int value to unsigned char byte array
				///
				/// @param[in] uiIn input data
				/// @param[out] ucOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// attention: no null-termination<br>
				///
				/// <b>Example:</b><br>
				/// uiIn = 287502430<br>
				/// ucOutBuf = {0x11, 0x22, 0xF0, 0x5E}<br>
				/// iOutBufLen = 4 (or higher)
				static int UIntToHexUChar(unsigned int uiIn, unsigned char* ucOutBuf, int iOutBufLen);

				/// @brief Converts int64_t value to unsigned char byte array
				///
				/// @param[in] i64In input data
				/// @param[out] ucOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// attention: no null-termination<br>
				///
				/// <b>Example:</b><br>
				/// i64In = 1234813534658031710<br>
				/// ucOutBuf = {0x11, 0x22, 0xF0, 0x5E, 0x11, 0x22, 0xF0, 0x5E}<br>
				/// iOutBufLen = 8 (or higher)
				static int Int64ToHexUChar(int64_t i64In, unsigned char* ucOutBuf, int iOutBufLen);

				/// @brief Converts uint64_t value to unsigned char byte array
				///
				/// @param[in] ui64In input data
				/// @param[out] ucOutBuf pointer to buffer with converted data
				/// @param[in] iOutBufLen size of output buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// attention: no null-termination<br>
				///
				/// <b>Example:</b><br>
				/// ui64In = 1234813534658031710<br>
				/// ucOutBuf = {0x11, 0x22, 0xF0, 0x5E, 0x11, 0x22, 0xF0, 0x5E}<br>
				/// iOutBufLen = 8 (or higher)
				static int UInt64ToHexUChar(uint64_t ui64In, unsigned char* ucOutBuf, int iOutBufLen);
			};
		}
	}
}

#endif // #if !defined(_FEDM_CORE_UTILITY_HEX_CONVERT_H_INCLUDED_)
