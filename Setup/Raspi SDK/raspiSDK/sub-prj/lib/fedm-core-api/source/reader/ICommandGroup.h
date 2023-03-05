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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IREADER_COMMUNICATION_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IREADER_COMMUNICATION_GROUP_H_INCLUDED_

#include <string>
#include <stdint.h>
#include "../source/FEDM.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing Reader command specific methods
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with general command methods for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [ICmd](@ref FEDM::Core::ReaderModule::ICmd) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS ICommandGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;
			
		public:

			/// @brief Main communication method
			///
			/// @param[in] ucCmdByte The command byte. The command must be applicable with the connected Reader. See Reader&apos;'s System Manual for applicable commands.
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Protocol traffic is generated with this method and can be used with all port drivers. This method gets only the control byte of the desired protocol.<br>
			/// All the data necessary for the protocol transfer are taken from the internal data containers resp. tables. 
			/// You must therefore ensure that all the protocol data have first been updated with the overloaded methods SetCommandPara().<br>
			/// For Transponder specific communication, see ITagGroup with easy to use high-level methods.<br>
			/// <br>
			/// @note <B>It is strongly recommended to evaluate always the return value in the application.</B><br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucTrData1 = 0;
			/// unsigned char ucTrData2 = 0;
			/// unsigned char ucDataSets = 0;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x22::Req::DATA_SETS, (unsigned int)255);
			/// int back = reader.ICmd.SendProtocol(0x22);
			/// if( back == 0 ||		// status: OK
			///		back == 0x84 ||		// status: RF warning
			///		back == 0x93 ||		// status: buffer overflow
			///		back == 0x94 )		// status: more data
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x22::Rsp::TR_DATA1, &ucTrData1);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x22::Rsp::TR_DATA2, &ucTrData2);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x22::Rsp::DATA_SETS, &ucDataSets);
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			int SendProtocol(unsigned char ucCmdByte);


			/// @brief Optional communication method for special cases
			///
			/// @param[in] ucCmdByte The command byte. The command must be applicable with the connected Reader. See Reader&apos;'s System Manual for applicable commands.
			/// @param[in] ucReqData Pointer to the buffer with the protocol data to be sent to the Reader
			/// @param[in] uiReqDataLength Length in number of bytes in the buffer with the protocol data for the request protocol
			/// @param[in] ucRspData Pointer to the buffer with the protocol data received from the Reader
			/// @param[out] uiRspDataBufferLength In:Maximal Size of ucRspData Out:Length in number of bytes in the buffer with the protocol data extracted from the responded protocol
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Protocol traffic is generated with this method and can be used with all port drivers.<br>
			/// This method enables a low-level access to the Reader for protocols, which are not supported by this library or
			/// which must be built under the control of the application.<br>
			/// The request protocol data must contain all bytes, except the bytes for the protocol frame, which is added internally.<br>
			/// The buffer with the protocol data bytes extracted from the responded protocol contains not the bytes of the protocol frame and not the status byte.
			/// The latter is the return value of this method.
			/// <br>
			/// @note <B>It is strongly recommended to evaluate always the return value in the application.</B><br>
			int SendProtocol(	unsigned char ucCmdByte,
								unsigned char* ucReqData,
								unsigned int uiReqDataLength,
								unsigned char* ucRspData,
								unsigned int& uiRspDataBufferLength);
			

/*				/// @brief Optional communication method for special cases
			///
			/// @param[in] ucReqProtocol Pointer to the buffer with the protocol to be sent to the Reader
			/// @param[in] uiReqProtocolLength Length in number of bytes in the buffer with the request protocol
			/// @param[in] ucRspProtocol Pointer to the buffer with the protocol received from the Reader
			/// @param[in] uiRspProtocolBufferLength Length in number of bytes in the buffer with the responded protocol
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Protocol traffic is generated with this method and can be used with all port drivers.<br>
			/// This method enables a low-level access to the Reader for protocols, which are not supported by this library or
			/// which must be built under the control of the application.
			/// The request protocol must contain the complete protocol frame with data, except the CRC, which is added internally. The length field in the protocol must include the 2 bytes for the CRC.<br>
			/// <br>
			/// @note <B>It is strongly recommended to evaluate always the return value in the application.</B><br>
// NOTE: wird aktuell nicht gebraucht. Vielleicht später einmal
			int SendTransparent(unsigned char* ucReqProtocol,
								unsigned int uiReqProtocolLength, 
								unsigned char* ucRspProtocol,
								unsigned int uiRspProtocolBufferLength);
*/

			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// As the parameter value is of type bool, only single bit parameters can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, bool* Data );

			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// As the parameter value is of type unsigned char, only single byte parameters can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, unsigned char* Data );
					
			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// The parameter value is an array of type unsigned char and can return a multi-byte parameter.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, unsigned char* Data, unsigned int uiDataLen );
					
			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// As the parameter value is of type unsigned int, only parameters with up to 4 bytes can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, unsigned int* Data );
					
			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// As the parameter value is of type int64_t, only parameters with up to 8 bytes can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, int64_t* Data );

			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// The parameter value is a hex-coded string and can return a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 will be returned as "AB39F1".
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, std::string& Data );
					
			/// @brief Method for getting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for command parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a command parameter value, identified by parameter name.<br>
			/// The parameter value is a hex-coded string and can return a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 will be returned as "AB39F1".
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int GetCommandPara( std::string sParaName, char* Data, unsigned int uiDataLen );
	
					
			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// As the parameter value is of type bool, only single bit parameters can be set.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, bool Data );

			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// As the parameter value is of type unsigned char, only single byte parameters can be set.<br>
			/// If a constant is set for the value, a cast operator has to placed in front of the constant (e.g. (unsigned char)0x05 )<br>
			/// <br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, unsigned char Data );

			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data Buffer with command parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// The parameter value is an arry of type unsigned char and can set a multi-byte parameter.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, unsigned char* Data, unsigned int uiDataLen );

			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// As the parameter value is of type unsigned int, only 4 byte wide parameters can be set.<br>
			/// If a constant is set for the value, a cast operator has to placed in front of the constant (e.g. (unsigned int)0x01020304 )<br>
			/// <br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, unsigned int Data );

			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// As the parameter value is of type unsigned int, only 8 byte wide parameters can be set.<br>
			/// If a constant is set for the value, a cast operator has to placed in front of the constant (e.g. (int64_t)123456789 )<br>
			/// <br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, int64_t Data );

			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data command parameter value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// The parameter value is a hex-coded string and can set a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 must be set as "AB39F1".<br>
			/// If a constant is set for the value, a cast operator has to placed in front of the constant (e.g. (string)"AB39F1" )<br>
			/// <br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, std::string Data );

			/// @brief Method for setting a command parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderCommand
			/// and must be applicable with the connected Reader
			/// @param[in] Data Buffer with command parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method sets a command parameter value, identified by parameter name.
			/// This prepares the next command to be executed to with SendProtocol().<br>
			/// The parameter value is a hex-coded string and can set a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 must be set as "AB39F1".<br>
			/// <br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref SendProtocol)
			int SetCommandPara( std::string sParaName, char* Data, unsigned int uiDataLen );

		private:
			ICommandGroup();
			virtual ~ICommandGroup();

			FEDM_ISCReaderModule* m_pReader;

			// buffer for protocols
			unsigned char m_ucSndPrt[65537];
			unsigned char m_ucRecPrt[65537];
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IREADER_COMMUNICATION_GROUP_H_INCLUDED_)
