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

#if !defined(_FEDM_CORE_ISCAN_READER_COMMAND_PARA_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_COMMAND_PARA_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"

using namespace std;

namespace FEDM
{
	namespace Core
	{
		/// @brief Namespace %ReaderCommand collects all command parameters
		///
		/// <b>Description</b><br>
		/// This namespace collects command parameters to be used with ICommandGroup::SetCommandPara or ICommandGroup::GetCommandPara.<br>
		/// These methods can be called with the [ICmd](@ref FEDM::Core::ReaderModule::ICmd) member of the Reader class ReaderModule.
		/// <br>
		/// @note It is highly recommended to read the Reader's System Manual when coding the Reader communication with these command parameters.
		namespace ReaderCommand
		{
			/// Namespace, containing all command parameters for command [0x22] Read Buffer
					
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
			namespace _0x22
			{
				/// Request parameters
				namespace Req
				{
					/// <b>2 byte parameter defining the requested data sets.</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x22)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATA_SETS;
				}

				/// Responded values
				namespace Rsp
				{
					/// <b>1 byte parameter defining the 1<SUP>st</SUP> byte with the structure of the responded data record</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x22)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TR_DATA1;

					/// Parameters, nested in TR_DATA1
					namespace TrData1
					{
						/// <b>1 bit parameter defining the flag for Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;

						/// <b>1 bit parameter defining the DATA flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string DATA;

						/// <b>1 bit parameter defining the EAS flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string EAS;

						/// <b>1 bit parameter defining the ANT flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string ANT;

						/// <b>1 bit parameter defining the TIMER flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER;

						/// <b>1 bit parameter defining the DATE flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string DATE;

						/// <b>1 bit parameter defining the EXTENSION flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string EXT;
					}

					/// <b>1 byte parameter defining the 2<SUP>nd</SUP> byte with the structure of the responded data record</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x22)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TR_DATA2;

					/// Parameters, nested in TR_DATA2
					namespace TrData2
					{
						/// <b>1 bit parameter defining the INPUT flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string INPUT;
							
						/// <b>1 bit parameter defining the AFI/DSFID flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string AFI;

						/// <b>1 bit parameter defining the RSSI resp. ANT_EXT flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSI;

						/// <b>1 bit parameter defining the DIRECTION flag</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x22)
						_FEDM_ISC_CORE_EXT_CLASS extern const string DIRECTION;
					}

					/// <b>2 byte parameter defining the number of data records in the response</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x22)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATA_SETS;
				}
			}

			/// Namespace, containing all command parameters for command [0x31] Read Data Buffer Info

			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned int uiTabSize = 0;
			/// unsigned int uiTabStart = 0;
			/// unsigned int uiTabLen = 0;
			/// 
			/// int back = reader.ICmd.SendProtocol(0x31);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x31::Rsp::TAB_SIZE, &uiTabSize);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x31::Rsp::TAB_START, &uiTabStart);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x31::Rsp::TAB_LEN, &uiTabLen);
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x31
			{
				/// Responded values
				namespace Rsp
				{
					/// <b>2 byte parameter defining the size of the Buffered Read Mode table in the Reader</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x31)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TAB_SIZE;

					/// <b>2 byte parameter defining the start index in the Buffered Read Mode table in the Reader</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x31)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TAB_START;

					/// <b>2 byte parameter defining the number of valid data sets to be requested from the Buffered Read Mode table in the Reader</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x31)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TAB_LEN;
				}
			}

			/// Namespace, containing all command parameters for command [0x34] Force Notify Trigger
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x34::Req::MODE, (unsigned int)0);
			/// reader.ICmd.SendProtocol(0x34);
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x34
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the mode byte</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x34)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;
				}
			}

			/// Namespace, containing all command parameters for command [0x64] System Reset
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x64::Req::MODE, (unsigned int)0); // 0: RFC; 1: ACC
			/// reader.ICmd.SendProtocol(0x64);
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x64
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the mode byte</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x64)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;
				}
			}

			/// Namespace, containing all command parameters for command [0x66] Reader Info
					
			/// <b>It is recommended to call the method IInfoGroup::ReadReaderInfo to read complete
			/// information about the Reader, which returns the [ReaderInfo](@ref FEDM::Core::IInfoGroup::ReaderInfo) structure</b><br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucInfo[31]; // buffer for reader information
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x66::Req::MODE, (unsigned int)0); // see Reader's System Manual for list with applicable mode bytes
			/// int back = reader.ICmd.SendProtocol(0x66);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x66::Rsp::READER_INFO, ucInfo, 31);
			/// }
			/// 
			/// Or as recommended:
			/// 
			/// READER_INFO* pInfo = reader.IInfo.ReadReaderInfo();
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x66
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the mode byte</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x66)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;
				}
					
				/// Responded values
				namespace Rsp
				{
					/// <b>Up to 31 bytes with Reader information depending on MODE</b>.
					///	Detailed info about the applicable values can be found in Reader's System Manual
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::GetCommandPara(string, char*, unsigned int)<br>
					/// <br>[Example](@ref _0x66)
					_FEDM_ISC_CORE_EXT_CLASS extern const string READER_INFO;
				}
			}

			/// Namespace, containing all command parameters for command [0x6A] RF On/Off
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x6A::Req::RF_OUTPUT, (unsigned int)0);
			/// reader.ICmd.SendProtocol(0x6A);
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x6A
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the RF state</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x6A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string RF_OUTPUT;
				}
			}

			/// Namespace, containing all command parameters for command [0x6D] Get Noise Level

			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned int uiNLMin = 0;
			/// unsigned int uiNLAvg = 0;
			/// unsigned int uiNLMax = 0;
			/// 
			/// int back = reader.ICmd.SendProtocol(0x6D);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x6D::Rsp::NL_MIN, &uiNLMin;
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x6D::Rsp::NL_AVG, &uiNLAvg;
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x6D::Rsp::NL_MAX, &uiNLMax;
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x6D
			{
				/// Responded values
				namespace Rsp
				{
					/// <b>2 byte parameter defining the measured minimal noise level in the Reader</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x6D)
					_FEDM_ISC_CORE_EXT_CLASS extern const string NL_MIN;
							
					/// <b>2 byte parameter defining the measured average noise level in the Reader</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x6D)
					_FEDM_ISC_CORE_EXT_CLASS extern const string NL_AVG;

					/// <b>2 byte parameter defining the measured maximal noise level in the Reader</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x6D)
					_FEDM_ISC_CORE_EXT_CLASS extern const string NL_MAX;
				}
			}

			/// Namespace, containing all command parameters for command [0x6E] Reader Diagnostic
					
			/// <b>It is recommended to call the method IInfoGroup::ReadReaderDiagnostic to read complete
			/// diagnostic information from the Reader, which returns the [ReaderDiagnostic](@ref FEDM::Core::IInfoGroup::ReaderDiagnostic) structure</b><br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucInfo[31]; // buffer for diagnostic data
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x6E::Req::MODE, (unsigned int)0); // see Reader's System Manual for list with applicable mode bytes
			/// int back = reader.ICmd.SendProtocol(0x6E);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x6E::Rsp::DIAGNOSTIC_DATA, ucInfo, 31);
			/// }
			/// 
			/// Or as recommended:
			/// 
			/// READER_DIAGNOSTIC* pInfo = reader.IInfo.ReadReaderDiagnostic();
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x6E
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the mode byte</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x6E)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// <b>1 byte parameter defining the data byte (only applicable with mode 0x21)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x6E)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATA;
				}
					
				/// Responded values
				namespace Rsp
				{
					/// <b>Up to 31 bytes with Reader diagnostic information depending on MODE</b>.
					///	Detailed info about the applicable values can be found in Reader's System Manual
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::GetCommandPara(string, char*, unsigned int)<br>
					/// <br>[Example](@ref _0x6E)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DIAGNOSTIC_DATA;
				}
			}

			/// Namespace, containing all command parameters for command [0x71] Set Output

			/// <remarks>
			/// <example>
			/// <br><b>Example:</b> (for ID ISC.MR101)
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x71::Req::OS, (unsigned int)0x0001); // LED green on
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x71::Req::OSF, (unsigned int)0x0000); // no flashing
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x71::Req::OS_TIME, (unsigned int)10); // 10x100ms = 1s on
			/// reader.ICmd.SendProtocol(0x71);
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x71
			{
				/// Request parameters
				namespace Req
				{
					/// <b>2 byte parameter defining the Output State</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x71)
					_FEDM_ISC_CORE_EXT_CLASS extern const string OUTPUT_STATE;

					/// Parameters, nested in OUTPUT_STATE
					namespace OutputState
					{
						/// <b>2 bit parameter defining the output state of digital output 1</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT1;

						/// <b>2 bit parameter defining the output state of digital output 2</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT2;

						/// <b>2 bit parameter defining the output state of LED Green</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LED_GREEN;

						/// <b>2 bit parameter defining the output state of LED Red</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LED_RED;

						/// <b>2 bit parameter defining the output state of Beeper</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string BEEPER;
					}

					/// <b>2 byte parameter defining the Output State Flash</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x71)
					_FEDM_ISC_CORE_EXT_CLASS extern const string OUTPUT_STATE_FLASH;

					/// Parameters, nested in OSF
					namespace OutputStateFlash
					{
						/// <b>2 bit parameter defining the output state flash of digital output 1</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT1;

						/// <b>2 bit parameter defining the output state flash of digital output 2</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT2;

						/// <b>2 bit parameter defining the output state flash of LED Green</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LED_GREEN;

						/// <b>2 bit parameter defining the output state flash of LED Red</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LED_RED;

						/// <b>2 bit parameter defining the output state flash of Beeper</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x71)
						_FEDM_ISC_CORE_EXT_CLASS extern const string BEEPER;
					}

					/// <b>2 byte parameter defining the LED and Beeper Activation Time</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x71)
					_FEDM_ISC_CORE_EXT_CLASS extern const string OS_TIME;

					/// <b>2 byte parameter defining the Output Activation Time</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x71)
					_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
				}
			}

			/// Namespace, containing all command parameters for command [0x72] Set Output

			/// <remarks>
			/// <example>
			/// <br><b>Example:</b> (for ID ISC.LR2500-A)
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::MODE, (unsigned char)0x01);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::OUT_N, (unsigned int)3);					// 3 outputs should be activated
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No1::OUT_NUMBER, (unsigned char)1);		// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No1::OUT_TYPE, (unsigned char)0);			// Digital Output 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No1::State::MODE, (unsigned char)3);		// flashing
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No1::State::FREQUENCY, (unsigned char)1); // 4Hz
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No1::OUT_TIME, (unsigned int)5);			// 5x100ms = 500ms on
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No2::OUT_NUMBER, (unsigned char)1);		// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No2::OUT_TYPE, (unsigned char)1);			// Relay
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No2::State::MODE, (unsigned char)0);		// not activated
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No2::State::FREQUENCY, (unsigned char)0); // unused
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No2::OUT_TIME, (unsigned int)2);			// 2x100ms = 200ms on
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No3::OUT_NUMBER, (unsigned char)2);		// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No3::OUT_TYPE, (unsigned char)1);			// Relay
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No3::State::MODE, (unsigned char)1);		// activated
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No3::State::FREQUENCY, (unsigned char)0); // unused
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x72::Req::No3::OUT_TIME, (unsigned int)10);			// 10x100ms = 1s on
			/// reader.ICmd.SendProtocol(0x72);
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x72
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the mode byte</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x72)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// <b>1 byte parameter defining the number of outputs</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x72)
					_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_N;
						
					/// Parameters for 1st output
					namespace No1
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 2nd output
					namespace No2
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 3rd output
					namespace No3
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 4th output
					namespace No4
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 5th output
					namespace No5
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 6th output
					namespace No6
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 7th output
					namespace No7
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
						
					/// Parameters for 8th output
					namespace No8
					{
						/// <b>5 bit parameter defining the output number</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_NUMBER;

						/// <b>3 bit parameter defining the output type</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TYPE;

						/// <b>1 byte parameter defining the output state, containing mode, frequency and/or repetition</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_STATE;

						/// Parameters, nested in OUT_STATE
						namespace State
						{
							/// <b>2 bit parameter defining the mode in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// <b>2 bit parameter defining the frequency in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FREQUENCY;

							/// <b>4 bit parameter defining the repetitions of activations in the output state</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// <br>[Example](@ref _0x72)
							_FEDM_ISC_CORE_EXT_CLASS extern const string REPETITIONS;
						}

						/// <b>2 byte parameter defining the activation time</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// <br>[Example](@ref _0x72)
						_FEDM_ISC_CORE_EXT_CLASS extern const string OUT_TIME;
					}
				}
			}

			/// Namespace, containing all command parameters for command [0x74] Get Input
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucInputs = 0;
			/// 
			/// int back = reader.ICmd.SendProtocol(0x74);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x74::Rsp::INPUTS, &ucInputs);
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x74
			{
				/// Responded values
				namespace Rsp
				{
					/// <b>1 byte parameter defining the actual input state</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// <br>[Example](@ref _0x74)
					_FEDM_ISC_CORE_EXT_CLASS extern const string INPUTS;
					/// Parameters, nested in INPUTS
					namespace Inputs
					{
						/// <b>1 bit parameter defining the actual state of input 1</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x74)
						_FEDM_ISC_CORE_EXT_CLASS extern const string IN1;

						/// <b>1 bit parameter defining the actual state of input 2</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x74)
						_FEDM_ISC_CORE_EXT_CLASS extern const string IN2;

						/// <b>1 bit parameter defining the actual state of input 3</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x74)
						_FEDM_ISC_CORE_EXT_CLASS extern const string IN3;

						/// <b>1 bit parameter defining the actual state of input 4</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x74)
						_FEDM_ISC_CORE_EXT_CLASS extern const string IN4;

						/// <b>1 bit parameter defining the actual state of input 5</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::GetCommandPara(string, bool*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
						/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
						/// ICommandGroup::GetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x74)
						_FEDM_ISC_CORE_EXT_CLASS extern const string IN5;
					}
				}
			}

			/// Namespace, containing all command parameters for command [0x76] Check Antennas
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucOutInt = 0;
			/// unsigned char ucOutExt1 = 0;
			/// unsigned char ucOutExt2 = 0;
			/// unsigned char ucOutExt3 = 0;
			/// unsigned char ucOutExt4 = 0;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x76::Req::MODE, (unsigned char)0);
			/// int back = reader.ICmd.SendProtocol(0x76);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x76::Rsp::ANT_OUT_INT, &ucOutInt);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x76::Rsp::ANT_OUT_EXT_1, &ucOutExt1);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x76::Rsp::ANT_OUT_EXT_2, &ucOutExt2);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x76::Rsp::ANT_OUT_EXT_3, &ucOutExt3);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x76::Rsp::ANT_OUT_EXT_4, &ucOutExt4);
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x76
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the mode byte</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x76)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;
				}

				/// Responded values
				namespace Rsp
				{
					/// <b>1 byte parameter defining the connected and detected antennas at internal Multiplexer</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x76)
					_FEDM_ISC_CORE_EXT_CLASS extern const string ANT_OUT_INT;

					/// <b>1 byte parameter defining the connected and detected antennas at external Multiplexer, connected at Antenna Output 1</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x76)
					_FEDM_ISC_CORE_EXT_CLASS extern const string ANT_OUT_EXT_1;

					/// <b>1 byte parameter defining the connected and detected antennas at external Multiplexer, connected at Antenna Output 2</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x76)
					_FEDM_ISC_CORE_EXT_CLASS extern const string ANT_OUT_EXT_2;

					/// <b>1 byte parameter defining the connected and detected antennas at external Multiplexer, connected at Antenna Output 3</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x76)
					_FEDM_ISC_CORE_EXT_CLASS extern const string ANT_OUT_EXT_3;

					/// <b>1 byte parameter defining the connected and detected antennas at external Multiplexer, connected at Antenna Output 4</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x76)
					_FEDM_ISC_CORE_EXT_CLASS extern const string ANT_OUT_EXT_4;
				}
			}

			/// Namespace, containing all command parameters for command [0x80] Read Configuration
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b> This example demonstrates the read-modify-write cycle for the parameter OperatingMode
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucWorkMode = 0;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x80::Req::CfgAddr::ADDRESS, (unsigned char)1); // configuration address 1
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x80::Req::CfgAddr::LOCATION, false); // reading from RAM
			/// int back = reader.ICmd.SendProtocol(0x80);
			/// if(back == 0)
			/// {
			///		// an example for modifying a configuration parameter in the Reader
			///		reader.ICfg.GetConfigPara(ReaderConfig::OperatingMode::Mode, &ucWorkMode, false);
			///		ucWorkMode = 0x80; // set to Buffered Read Mode
			///		reader.ICfg.SetConfigPara(ReaderConfig::OperatingMode::Mode, ucWorkMode, false);
			/// 
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x81::Req::CfgAddr::ADDRESS, (unsigned char)1); // configuration address 1
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x81::Req::CfgAddr::LOCATION, false); // writing into RAM
			///		reader.ICmd.SendProtocol(0x81);
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x80
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the address of the configuration block. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x80)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_ADDRESS;

					/// Parameters, nested in CFG_ADDRESS
					namespace CfgAddr
					{
						/// <b>6 bit parameter defining the address of the configuration block</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x80)
						_FEDM_ISC_CORE_EXT_CLASS extern const string ADDRESS;

						/// <b>1 bit parameter defining the location of the configuration block (0=RAM; 1=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x80)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;
					}
				}
			}

			/// Namespace, containing all command parameters for command [0x81] Write Configuration
	
			/// <b>[Example: see 0x80](@ref _0x80)</b>
			namespace _0x81
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the address of the configuration block. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x80)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_ADDRESS;

					/// Parameters, nested in CFG_ADDRESS
					namespace CfgAddr
					{
						/// <b>6 bit parameter defining the address of the configuration block</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x81)
						_FEDM_ISC_CORE_EXT_CLASS extern const string ADDRESS;

						/// <b>1 bit parameter defining the location of the configuration block (0=RAM; 1=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x81)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;
					}
				}
			}

			/// Namespace, containing all command parameters for command [0x83] Reset Configuration
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x83::Req::CfgAddr::ADDRESS, (unsigned char)1);	// configuration address 1
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x83::Req::CfgAddr::MODE, true);					// reset of complete configuration
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x83::Req::CfgAddr::LOCATION, true);				// reset in EEPROM
			/// reader.ICmd.SendProtocol(0x83);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x83
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the address of the configuration block. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x83)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_ADDRESS;

					/// Parameters, nested in CFG_ADDRESS
					namespace CfgAddr
					{
						/// <b>6 bit parameter defining the address of the configuration block</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x83)
						_FEDM_ISC_CORE_EXT_CLASS extern const string ADDRESS;

						/// <b>1 bit parameter defining the operation mode (0=reset of specified configuration address; 1=reset of complete configuration)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x83)
						_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

						/// <b>1 bit parameter defining the location of the configuration block (0=RAM; 1=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x83)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;
					}
				}
			}

			/// Namespace, containing all command parameters for command [0x85] Set Timer
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// // set timer to 12:45:10 and 300ms
			///
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x85::Req::TIMER_HOUR, (unsigned char)12);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x85::Req::TIMER_MINUTE, (unsigned char)45);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x85::Req::TIMER_MILLISECONDS, (unsigned int)(10*1000 + 300));
			/// reader.ICmd.SendProtocol(0x85);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x85
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the hour</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x85)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER_HOUR;

					/// <b>1 byte parameter defining the minutes</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x85)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER_MINUTE;

					/// <b>2 byte parameter defining the milliseconds</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x85)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER_MILLISECONDS;
				}
			}

			/// Namespace, containing all command parameters for command [0x86] Get Timer
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucHour = 0;
			/// unsigned char ucMinute = 0;
			/// unsigned int uiMilliseconds = 0;
			/// 
			/// int back = reader.ICmd.SendProtocol(0x86);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x86::Rsp::TIMER_HOUR, &ucHour);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x86::Rsp::TIMER_MINUTE, &ucMinute);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x86::Rsp::TIMER_MILLISECONDS, &uiMilliseconds);
			/// }
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x86
			{
				/// Responded values
				namespace Rsp
				{
					/// <b>1 byte parameter defining the hour</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x86)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER_HOUR;

					/// <b>1 byte parameter defining the minutes</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x86)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER_MINUTE;

					/// <b>2 byte parameter defining the milliseconds</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
					/// ICommandGroup::GetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x86)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIMER_MILLISECONDS;
				}
			}

			/// Namespace, containing all command parameters for command [0x87] Set System Date and Time
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// // set date to 2012-10-16 and time to 12:45:10 and 300ms
			///
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::DATE_CENTURY, (unsigned char)20);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::DATE_YEAR, (unsigned char)12);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::DATE_MONTH, (unsigned char)10);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::DATE_DAY, (unsigned char)16);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::DATE_TIMEZONE, (unsigned char)0); // note: timezone is set to 0, because unused
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::TIME_HOUR, (unsigned char)12);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::TIME_MINUTE, (unsigned char)45);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x87::Req::TIME_MILLISECONDS, (unsigned int)(10*1000 + 300));
			/// reader.ICmd.SendProtocol(0x87);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x87
			{
				/// Request parameters
				namespace Req
				{					
					/// <b>1 byte parameter defining the century</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_CENTURY;
							
					/// <b>1 byte parameter defining the year</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_YEAR;
							
					/// <b>1 byte parameter defining the month</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_MONTH;
							
					/// <b>1 byte parameter defining the day</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_DAY;
							
					/// <b>1 byte parameter defining the timezone. Note: This parameter is actually not in use.</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_TIMEZONE;
							
					/// <b>1 byte parameter defining the hour</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIME_HOUR;

					/// <b>1 byte parameter defining the minutes</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIME_MINUTE;

					/// <b>2 byte parameter defining the milliseconds</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x87)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIME_MILLISECONDS;
				}
			}

			/// Namespace, containing all command parameters for command [0x88] Get System Date and Time
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucCentury = 0;
			/// unsigned char ucYear = 0;
			/// unsigned char ucMonth = 0;
			/// unsigned char ucDay = 0;
			/// unsigned char ucHour = 0;
			/// unsigned char ucMinute = 0;
			/// unsigned int uiMilliseconds = 0;
			/// 
			/// int back = reader.ICmd.SendProtocol(0x88);
			/// if(back == 0)
			/// {
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::DATE_CENTURY, &ucCentury);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::DATE_YEAR, &ucYear);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::DATE_MONTH, &ucMonth);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::DATE_DAY, &ucDay);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::TIME_HOUR, &ucHour);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::TIME_MINUTE, &ucMinute);
			///		reader.ICmd.GetCommandPara(ReaderCommand::_0x88::Rsp::TIME_MILLISECONDS, &uiMilliseconds);
			/// }
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x88
			{
				/// Responded values
				namespace Rsp
				{
					/// <b>1 byte parameter defining the century</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_CENTURY;
							
					/// <b>1 byte parameter defining the year</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_YEAR;
							
					/// <b>1 byte parameter defining the month</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_MONTH;
							
					/// <b>1 byte parameter defining the day</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_DAY;
							
					/// <b>1 byte parameter defining the timezone. Note: This parameter is actually not in use.</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DATE_TIMEZONE;
							
					/// <b>1 byte parameter defining the hour</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIME_HOUR;

					/// <b>1 byte parameter defining the minutes</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIME_MINUTE;

					/// <b>2 byte parameter defining the milliseconds</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x88)
					_FEDM_ISC_CORE_EXT_CLASS extern const string TIME_MILLISECONDS;
				}
			}

			/// Namespace, containing all command parameters for command [0x8A] Read Configuration
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b> This example demonstrates the read-modify-write cycle for the parameter OperatingMode
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// unsigned char ucWorkMode = 0;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::DEVICE, (unsigned char)2);			// RF-Controller
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::BANK, (unsigned char)1);				// main bank
			///	reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::MODE, (unsigned char)0);				// clear mode byte
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::Mode::LOCATION, (unsigned char)1);	// EEPROM
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::Mode::ALL, false);					// read only specified config blocks
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::CFG_ADDRESS, (unsigned char)1);		// first configuration address
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8A::Req::CFG_N, (unsigned int)1);				// number of config blocks to be read to
			/// int back = reader.ICmd.SendProtocol(0x8A);
			/// if(back == 0)
			/// {
			///		reader.ICfg.GetConfigPara(ReaderConfig::OperatingMode::Mode, &ucWorkMode, false); // an example of getting a configuration setting after reading from Reader
			/// 
			///		ucWorkMode = 0x80; // set to Buffered Read Mode
			/// 
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::DEVICE, (unsigned char)2);			// RF-Controller (see Reader's System Manual for applicable values)
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::BANK, (unsigned char)1);				// main bank (see Reader's System Manual for applicable values)
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::MODE, (unsigned char)0);				// clear mode byte
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::Mode::LOCATION, (unsigned char)1);	// EEPROM
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::CFG_N, (unsigned char)1);				// number of config blocks to be read to
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::BLOCK_SIZE, (unsigned char)30);		// block size (see Reader's System Manual for applicable values)
			///		reader.ICmd.SetCommandPara(ReaderCommand::_0x8B::Req::CFG_ADDRESS, (unsigned int)1);		// first configuration address
			///		reader.ICmd.SendProtocol(0x8B);
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x8A
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the device type in the Reader (2=RF-Controller; 3=AC-Controller. See Reader's System Manual for applicable values)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DEVICE;

					/// <b>1 byte parameter defining the configuration bank in the Reader (1=main bank; all other not specified. See Reader's System Manual for applicable values)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string BANK;

					/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// Parameters, nested in MODE
					namespace Mode
					{
						/// <b>3 bit parameter defining the location of the configuration block (b000=RAM; b001=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x8A)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;

						/// <b>1 bit parameter defining the operation mode (0=read of specified configuration addresses; 1=read of complete configuration)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x8A)
						_FEDM_ISC_CORE_EXT_CLASS extern const string ALL;
					}

					/// <b>2 byte parameter defining the first configuration block address</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_ADDRESS;

					/// <b>1 byte parameter defining the number of sequent configuration blocks to be read to, beginning with ReaderCommand::_0x8A::Req::CFG_ADDRESS</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_N;
				}
			}

			/// Namespace, containing all command parameters for command [0x8B] Write Configuration

			/// <b>[Example: see 0x8A](@ref _0x8A)</b>
			namespace _0x8B
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the device type in the Reader (2=RF-Controller; 3=AC-Controller. See Reader's System Manual for applicable values)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DEVICE;

					/// <b>1 byte parameter defining the configuration bank in the Reader (1=main bank; all other not specified. See Reader's System Manual for applicable values)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string BANK;

					/// <b>1 byte parameter defining operation mode. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// Parameters, nested in MODE
					namespace Mode
					{
						/// <b>3 bit parameter defining the location of the configuration block (b000=RAM; b001=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x8A)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;
					}

					/// <b>1 byte parameter defining the number of sequent configuration blocks to be written to, beginning with ReaderCommand::_0x8B::Req::CFG_ADDRESS</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_N;

					/// <b>1 byte parameter defining the size of each configuration blocks. See Reader's System Manual for applicable values</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string BLOCK_SIZE;

					/// <b>2 byte parameter defining the first configuration block address</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8A)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_ADDRESS; // 1st address
				}
			}

			/// Namespace, containing all command parameters for command [0x8C] Reset Configuration
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::DEVICE, (unsigned char)2);			// RF-Controller
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::BANK, (unsigned char)1);				// main bank
			///	reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::MODE, (unsigned char)0);				// clear mode byte
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::Mode::LOCATION, (unsigned char)1);	// EEPROM
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::Mode::ALL, true);						// reset complete configuration
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::CFG_ADDRESS, (unsigned char)0);		// not used
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0x8C::Req::CFG_N, (unsigned int)0);				// not used
			/// reader.ICmd.SendProtocol(0x8C);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0x8C
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the device type in the Reader (2=RF-Controller; 3=AC-Controller. See Reader's System Manual for applicable values)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8C)
					_FEDM_ISC_CORE_EXT_CLASS extern const string DEVICE;

					/// <b>1 byte parameter defining the configuration bank in the Reader (1=main bank; all other not specified. See Reader's System Manual for applicable values)</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8C)
					_FEDM_ISC_CORE_EXT_CLASS extern const string BANK;

					/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8C)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// Parameters, nested in MODE
					namespace Mode
					{
						/// <b>3 bit parameter defining the location of the configuration block (b000=RAM; b001=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x8C)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;

						/// <b>1 bit parameter defining the operation mode (0=reset of specified configuration addresses; 1=reset of complete configuration)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0x8C)
						_FEDM_ISC_CORE_EXT_CLASS extern const string ALL;
					}

					/// <b>2 byte parameter defining the first configuration block address</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8C)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_ADDRESS;

					/// <b>1 byte parameter defining the number of sequent configuration blocks to be reset to, beginning with ReaderCommand::_0x8C::Req::CFG_ADDRESS</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0x8C)
					_FEDM_ISC_CORE_EXT_CLASS extern const string CFG_N;
				}
			}

			/// Namespace, containing all command parameters for command [0xA0] Reader Login
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA0::Req::PASSWORD, (string)"1A2B3C4F");
			/// reader.ICmd.SendProtocol(0xA0);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0xA0
			{
				/// Request parameters
				namespace Req
				{
					/// <b>4 byte parameter defining the login password</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA0)
					_FEDM_ISC_CORE_EXT_CLASS extern const string PASSWORD;
				}
			}

			/// Namespace, containing all command parameters for command [0xA2] Write Mifare Key
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA2::Req::KEY_TYPE, (unsigned char)0);		// key A
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA2::Req::KEY_ADDRESS, (unsigned char)3);	// key address
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA2::Req::KEY, (string)"1A2B3C4F7920");		// authentication key
			/// reader.ICmd.SendProtocol(0xA2);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0xA2
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the key type</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA2)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_TYPE;

					/// <b>1 byte parameter defining the key address</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA2)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_ADDRESS;

					/// <b>6 byte parameter defining the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA2)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY;
				}
			}

			/// Namespace, containing all command parameters for command [0xA3] Write DES/AES Key
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA3::Req::MODE, (unsigned char)0);					// reset MODE
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA3::Req::Mode::LOCATION, (unsigned char)1);		// key B
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA3::Req::KEY_INDEX, (unsigned char)0);				// address in the Reader
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA3::Req::AUTHENTICATION_MODE, (unsigned char)5);	// AES
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA3::Req::KEY_LEN, (unsigned char)16);				// 16 byte key length
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xA3::Req::KEY, (string)"11223344556677889900AABBCCDDEEFF");		// authentication key
			/// reader.ICmd.SendProtocol(0xA3);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0xA3
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA3)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// Parameters, nested in MODE
					namespace Mode
					{
						/// <b>1 bit parameter defining the location of the key in the Reader (b0=RAM; b1=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0xA3)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;
					}

					/// <b>1 byte parameter defining the key index. See Reader's System Manual for applicable values</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// <br>[Example](@ref _0xA3)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_INDEX;

					/// <b>1 byte parameter defining the authentication mode. See Reader's System Manual for applicable values</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA3)
					_FEDM_ISC_CORE_EXT_CLASS extern const string AUTHENTICATION_MODE;

					/// <b>1 byte parameter defining the length of the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA3)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_LEN;

					/// <b>8, 16 or 24 byte parameter defining the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xA3)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY;
				}
			}

			/// Namespace, containing all command parameters for command [0xAD] Write Reader Authentication Key
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAD::Req::MODE, (unsigned char)0);					// set always to 0
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAD::Req::KEY_TYPE, (unsigned char)0);				// AES 128
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAD::Req::KEY_LEN, (unsigned char)16);				// 16 byte key length
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAD::Req::KEY, (string)"11223344556677889900AABBCCDDEEFF");		// authentication key
			/// reader.ICmd.SendProtocol(0xAD);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0xAD
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the operation mode. Actually not in use</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAD)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// Parameters, nested in MODE
					namespace Mode
					{
						/// <b>1 bit parameter defining the location of the key in the Reader (b0=RAM; b1=EEPROM)</b><br>
						/// <br>
						/// The following methods matches this parameter:<br>
						/// ICommandGroup::SetCommandPara(string, bool)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
						/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
						/// ICommandGroup::SetCommandPara(string, string)<br>
						/// <br>[Example](@ref _0xA3)
						_FEDM_ISC_CORE_EXT_CLASS extern const string LOCATION;
					}

					/// <b>1 byte parameter defining the type of the key. See Reader's System Manual for applicable values</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAD)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_TYPE;

					/// <b>1 byte parameter defining the length of the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAD)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_LEN;

					/// <b>16, 24 or 32 byte parameter defining the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAD)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY;
				}
			}

			/// Namespace, containing all command parameters for command [0xAE] Reader Authentication
					
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAE::Req::MODE, (unsigned char)0);					// set always to 0
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAE::Req::KEY_TYPE, (unsigned char)0);				// AES 128
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAE::Req::KEY_LEN, (unsigned char)16);				// 16 byte key length
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xAE::Req::KEY, (string)"11223344556677889900AABBCCDDEEFF");		// authentication key
			/// reader.ICmd.SendProtocol(0xAE);
			/// </code>
			/// </example>
			/// </remarks>
			namespace _0xAE
			{
				/// Request parameters
				namespace Req
				{
					/// <b>1 byte parameter defining the operation mode. Actually not in use</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAE)
					_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

					/// <b>1 byte parameter defining the type of the key. See Reader's System Manual for applicable values</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAE)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_TYPE;

					/// <b>1 byte parameter defining the length of the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
					/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAE)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY_LEN;

					/// <b>16, 24 or 32 byte parameter defining the key</b><br>
					/// <br>
					/// The following methods matches this parameter:<br>
					/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
					/// ICommandGroup::SetCommandPara(string, string)<br>
					/// <br>[Example](@ref _0xAE)
					_FEDM_ISC_CORE_EXT_CLASS extern const string KEY;
				}
			}

			/// Namespace, containing all command parameters for command [0xB0] ISO Host Command

			/// <br>see [IHmTableGroup::GetItemByIndex](@ref FEDM::Core::IHmTableGroup::GetItemByIndex) for a simple example.<br>
			namespace _0xB0
			{
				/// <b>1 byte parameter defining the ISO Host command</b><br>
				/// <br>
				/// The following methods matches this parameter:<br>
				/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
				/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
				/// ICommandGroup::SetCommandPara(string, string)<br>
				/// <br>[Example](@ref _0xB0)
				_FEDM_ISC_CORE_EXT_CLASS extern const string SUB_COMMAND;
						
				/// Host command specific namespaces
				namespace SubCmd
				{
					/// Inventory
					namespace _0x01
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;
									
							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>1 bit parameter defining the request with antenna numbers. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x01::Req::ANTENNA_SELECTION. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ANT;

								/// <b>1 bit parameter defining the request with presence check. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string PRESC;

								/// <b>1 bit parameter defining the request with asynchronous Inventory. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x01::Req::NOTIFY_TIME. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string NOTIFY;

								/// <b>1 bit parameter defining the request of additional data</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string MORE;
							}

							/// <b>1 byte parameter defining the timeout for the asynchronous Inventory. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x01::Req::Mode::NOTIFY</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string NOTIFY_TIME;

							/// <b>1 byte parameter defining the requested Antennas. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x01::Req::Mode::ANT</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string ANTENNA_SELECTION;
						}
					}

					/// Stay Quiet
					namespace _0x02
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}
					}

					/// Lock Multiple Blocks
					namespace _0x22
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;

								/// <b>1 bit parameter defining the extended addressed mode. This parameter must be combined with parameters from ReaderCommand::_0xB0::SubCmd::_0x22::Req::ExtAddrMode. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string EXT_ADR;
							}
						
							/// <b>Up to 96 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;

							/// Parameters for normal address mode
							namespace NormAddrMode
							{
								/// <b>1 byte parameter defining the Transponder block address</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

								/// <b>1 byte parameter defining the number of data blocks to be locked to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x22::Req::NormAddrMode::DB_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;
							}
								
							/// Parameters for extended address mode
							namespace ExtAddrMode
							{
								/// <b>1 byte parameter defining the bank and has nested parameters. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x22::Req::Mode::EXT_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string BANK;
										
								/// Parameters, nested in BANK
								namespace Bank
								{
									/// <b>2 bit parameter defining the bank number. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x22::Req::Mode::EXT_ADR</b><br>
									/// <br>
									/// The following methods matches this parameter:<br>
									/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
									/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
									/// ICommandGroup::SetCommandPara(string, string)<br>
									/// <br>[Example](@ref _0xB0)
									_FEDM_ISC_CORE_EXT_CLASS extern const string NUMBER;
								}

								/// <b>2 byte parameter defining the first Transponder block address to be locked to</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

								/// <b>1 byte parameter defining the number of data blocks to be locked to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x22::Req::ExtAddrMode::DB_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;
							}
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;

							/// Parameters for normal address mode
							namespace NormAddrMode
							{
								/// <b>1 byte parameter defining the data block address after ISO error</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
								/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
								/// ICommandGroup::GetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADDRESS_ERROR;
							}

							/// Parameters for extended address mode
							namespace ExtAddrMode
							{
								/// <b>2 byte parameter defining the data block address after ISO error</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
								/// ICommandGroup::GetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADDRESS_ERROR;
							}
						}
					}
						
					/// Read Multiple Blocks
					namespace _0x23
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;

								/// <b>1 bit parameter defining the request with security data. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string SEC;

								/// <b>1 bit parameter defining the additional IDD length. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::ExtAddrMode::IDD_LEN. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string IDD_LF;

								/// <b>1 bit parameter defining the extended addressed mode. This parameter must be combined with parameters from ReaderCommand::_0xB0::SubCmd::_0x23::Req::ExtAddrMode. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string EXT_ADR;

								/// <b>1 bit parameter defining the Read-Complete-Bank option for the extended addressed mode. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR and with parameters from ReaderCommand::_0xB0::SubCmd::_0x23::Req::ExtAddrMode. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string READ_COMPLETE_BANK;

								/// <b>1 bit parameter defining the request of additional data</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string MORE;
							}
											
							/// <b>Up to 96 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;

							/// Parameters for normal address mode
							namespace NormAddrMode
							{
								/// <b>1 byte parameter defining the Transponder block address</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

								/// <b>1 byte parameter defining the number of data blocks to be locked to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x23::Req::NormAddrMode::DB_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;
							}
								
							/// Parameters for extended address mode
							namespace ExtAddrMode
							{
								/// <b>1 byte parameter defining the number of bytes in the IDD. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR and with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::IDD_LF</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string IDD_LEN;

								/// <b>1 byte parameter defining the bank and has nested parameters. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string BANK;

								/// Parameters, nested in BANK
								namespace Bank
								{
									/// <b>2 bit parameter defining the bank number. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR</b><br>
									/// <br>
									/// The following methods matches this parameter:<br>
									/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
									/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
									/// ICommandGroup::SetCommandPara(string, string)<br>
									/// <br>[Example](@ref _0xB0)
									_FEDM_ISC_CORE_EXT_CLASS extern const string NUMBER;

									/// <b>1 bit parameter defining the enabling of access password in the request. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR</b><br>
									/// <br>
									/// The following methods matches this parameter:<br>
									/// ICommandGroup::SetCommandPara(string, bool)<br>
									/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
									/// <br>[Example](@ref _0xB0)
									_FEDM_ISC_CORE_EXT_CLASS extern const string ACCESS_FLAG;
								}

								/// <b>1 byte parameter defining the number of bytes in the access pasword. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR and with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Bank::ACCESS_FLAG</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ACCESS_PASSWORD_LEN;

								/// <b>Up to 31 byte parameter defining the access pasword. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Mode::EXT_ADR and with ReaderCommand::_0xB0::SubCmd::_0x23::Req::Bank::ACCESS_FLAG</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ACCESS_PASSWORD;

								/// <b>2 byte parameter defining the first Transponder block address</b><br>
								/// <br>
								/// This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR.<br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

								/// <b>1 byte parameter defining the number of data blocks to be read to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x23::Req::NormAddrMode::DB_ADR</b><br>
								/// <br>
								/// This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR.<br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;
							}
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}
						
					/// Write Multiple Blocks
					namespace _0x24
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;

								/// <b>1 bit parameter defining the Write-No-Erase option. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string WR_NE;

								/// <b>1 bit parameter defining the additional IDD length. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::ExtAddrMode::IDD_LEN. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string IDD_LF;

								/// <b>1 bit parameter defining the extended addressed mode. This parameter must be combined with parameters from ReaderCommand::_0xB0::SubCmd::_0x24::Req::ExtAddrMode. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string EXT_ADR;
							}
						
							/// <b>Up to 96 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;

							/// Parameters for normal address mode
							namespace NormAddrMode
							{
								/// <b>1 byte parameter defining the Transponder block address</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

								/// <b>1 byte parameter defining the number of data blocks to be locked to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x24::Req::NormAddrMode::DB_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;
							}
								
							/// Parameters for extended address mode
							namespace ExtAddrMode
							{
								/// <b>1 byte parameter defining the number of bytes in the IDD. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR and with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::IDD_LF</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string IDD_LEN;

								/// <b>1 byte parameter defining the bank and has nested parameters. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string BANK;
										
								/// Parameters, nested in BANK
								namespace Bank
								{
									/// <b>2 bit parameter defining the bank number. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR</b><br>
									/// <br>
									/// The following methods matches this parameter:<br>
									/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
									/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
									/// ICommandGroup::SetCommandPara(string, string)<br>
									/// <br>[Example](@ref _0xB0)
									_FEDM_ISC_CORE_EXT_CLASS extern const string NUMBER;

									/// <b>1 bit parameter defining the enabling of access password in the request. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR</b><br>
									/// <br>
									/// The following methods matches this parameter:<br>
									/// ICommandGroup::SetCommandPara(string, bool)<br>
									/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
									/// <br>[Example](@ref _0xB0)
									_FEDM_ISC_CORE_EXT_CLASS extern const string ACCESS_FLAG;
								}

								/// <b>1 byte parameter defining the number of bytes in the access pasword. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR and with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Bank::ACCESS_FLAG</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ACCESS_PASSWORD_LEN;

								/// <b>Up to 31 byte parameter defining the access pasword. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR and with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Bank::ACCESS_FLAG</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ACCESS_PASSWORD;

								/// <b>2 byte parameter defining the Transponder block address</b><br>
								/// <br>
								/// This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR.<br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

								/// <b>1 byte parameter defining the number of data blocks to be written to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x24::Req::NormAddrMode::DB_ADR</b><br>
								/// <br>
								/// This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR.<br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;

								/// <b>1 byte parameter defining the number of bytes in each data block. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x24::Req::Mode::EXT_ADR</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_SIZE;
							}
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;

							/// Parameters for normal address mode
							namespace NormAddrMode
							{
								/// <b>1 byte parameter defining the data block address after ISO error</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
								/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
								/// ICommandGroup::GetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADDRESS_ERROR;
							}

							/// Parameters for extended address mode
							namespace ExtAddrMode
							{
								/// <b>2 byte parameter defining the data block address after ISO error</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
								/// ICommandGroup::GetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADDRESS_ERROR;
							}
						}
					}
										
					/// Select
					namespace _0x25
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;

								/// <b>1 bit parameter defining the additional IDD length. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x25::Req::IDD_LEN. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string IDD_LF;

								/// <b>1 bit parameter defining the request of additional card information. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string CINF;

								/// <b>1 bit parameter defining the manual selection of the transponder driver. See Reader's System manual, if applicable</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, bool)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string DRV_SEL;
							}
						
							/// <b>1 byte parameter defining the transponder driver to be used for the next selection operation. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x25::Req::Mode::DRV_SEL</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string TR_DRIVER;

							/// <b>1 byte parameter defining the number of bytes in the IDD. This parameter must be combined with ReaderCommand::_0xB0::SubCmd::_0x25::Req::Mode::IDD_LF</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD_LEN;

							/// <b>Up to 96 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the Format value. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string FORMAT;

							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Reset to Ready
					namespace _0x26
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Write AFI
					namespace _0x27
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Lock AFI
					namespace _0x28
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Write DSFID
					namespace _0x29
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Lock DSFID
					namespace _0x2A
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Get System Information
					namespace _0x2B
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}

					/// Get Multiple Block Security Status
					namespace _0x2C
					{
						/// Request parameters
						namespace Req
						{
							/// <b>1 byte parameter defining the operation mode. This parameter has nested parameters</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string MODE;			

							/// Parameters, nested in MODE
							namespace Mode
							{
								/// <b>3 bit parameter defining the address mode (0=non-addressed; 1=addressed;2=selected</b><br>
								/// <br>
								/// The following methods matches this parameter:<br>
								/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
								/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
								/// ICommandGroup::SetCommandPara(string, string)<br>
								/// <br>[Example](@ref _0xB0)
								_FEDM_ISC_CORE_EXT_CLASS extern const string ADR;
							}
						
							/// <b>8 byte parameter defining the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, char*, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						
							/// <b>1 byte parameter defining the first Transponder block address</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string DB_ADR;

							/// <b>1 byte parameter defining the number of data blocks to be locked to, beginning at the Transponder address specified with ReaderCommand::_0xB0::SubCmd::_0x2C::Req::DB_ADR</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::SetCommandPara(string, unsigned char)<br>
							/// ICommandGroup::SetCommandPara(string, unsigned int)<br>
							/// ICommandGroup::SetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string DBN;
						}

						/// Responded values
						namespace Rsp
						{
							/// <b>1 byte parameter defining the ISO error code, returned by the Transponder. See the Transponder Reference Manual for more information</b><br>
							/// <br>
							/// The following methods matches this parameter:<br>
							/// ICommandGroup::GetCommandPara(string, unsigned char*)<br>
							/// ICommandGroup::GetCommandPara(string, unsigned int*)<br>
							/// ICommandGroup::GetCommandPara(string, string)<br>
							/// <br>[Example](@ref _0xB0)
							_FEDM_ISC_CORE_EXT_CLASS extern const string STATUS_0x95_ERROR;
						}
					}
				}
			}
		}
	}
}

#endif // _FEDM_CORE_ISCAN_READER_COMMAND_PARA_H_INCLUDED_
