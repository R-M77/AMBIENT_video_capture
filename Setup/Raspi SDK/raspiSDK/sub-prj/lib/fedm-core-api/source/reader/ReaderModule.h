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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "IPortGroup.h"
#include "IInfoGroup.h"
#include "ICommandGroup.h"
#include "IConfigGroup.h"
#include "IHmTableGroup.h"
#include "IBrmTableGroup.h"
#include "IAsyncGroup.h"
#include "ILogGroup.h"
#include "IKeyMngGroup.h"
#include "ReaderCommandPara.h"
#include "../source/utility/DateTime.h"
#include "../source/utility/OutputSetting.h"
#ifdef _FEDM_TAG_HANDLER
	#include "ITagGroup.h"
#endif
#if !defined(_FEDM_NO_FW_UPD_SUPPORT)
	#include "IFwUpdGroup.h"
#endif
#if !defined(_FEDM_NO_PD_SUPPORT) && !defined(_FEDM_NO_FU_SUPPORT)
	#include "IExtDeviceGroup.h"
#endif

using namespace FEDM::Core;

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{

		/// @brief Class %ReaderModule is the Reader class
		///
		/// <b>Description</b><br>
		/// This class realizes the uniform Reader class for all IDENTIFICATION Readers 
		/// and supports all working modes.<br>
		/// Each physical Reader needs one instance of this class. Multiple connections from one instance to many Readers are not possible.
		/// Also an alternating use of one instance for multiple Readers is not recommended.<br>
		/// This Reader class has a wide method interface, devided in groups for better orientation. The method interfaces of these groups are realized with nested classes.<br>
		/// <br>
		/// @note 1. It is highly recommended to read the Reader's System Manual when coding the Reader communication.
		/// @note 2. The functionality of this class is implemented with the private embedded class FEDM_ISCReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS ReaderModule
		{

		public:
				
			/// @brief Main constructor
			///
			/// <b>Description</b><br>
			ReaderModule();
					
			/// @brief Special constructor
			///
			/// <b>Description</b><br>
			ReaderModule(FEDM_ISCReaderModule* pReaderImpl);
					
			/// @brief Destructor
			///
			/// <b>Description</b><br>
			virtual ~ReaderModule();

			/// @brief Initialization method to set the Reader Type (for rare cases)
			///
			/// @param[in] uiReaderType Reader Type Number from namespace FEDM::Core::Const::ReaderType
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// The Reader Type Number is essential for the Reader class and is set normally within one of the Connect methods of the nested interface IPortGroup.<br>
			/// In rare cases, when the Reader Type Number must be set in front of a connection, this method can be used.
			int SetReaderType(unsigned int uiReaderType);

			/** @brief Returns the handle of the libray FEISC
			*
			* @return handle of FEISC object
			*
			* <b>Description</b><br>
			* This method is useful in rare cases.<br>
			* The underlaying library FEISC prepares or evaluates the communication frames and controls the communication with one active port layer library, 
			* which is selected with one of the Connect methods in IPortGroup.<br>
			* With knowledge of this handle one can communicate with the same Reader but with FEISC functions.
			*/
			int  GetReaderHandle(void) const;

			/** @brief Set the FEISC handle in the library
			*
			* <b>Description</b><br>
			* This method is useful in rare cases.<br>
			* The underlaying library FEISC prepares or evaluates the communication frames and controls the communication with one active port layer library.<br>
			* The Connect methods in IPortGroup cannot be used. Instead of, the communication must be established with the specific port layer library and the connection between 
			* the port layer library and FEISC must be handled in the application.<br>
			* More information can be found in the manual of FEISC.
			*/
			void SetReaderHandle(int handle);

			/// @brief Return the underlaying reader module (for rare cases)
			///
			/// @return Pointer of implementation object of type FEDM_ISCReaderModule
			///
			/// <b>Description</b><br>
			/// The %ReaderModule class aggregates the class FEDM_ISCReaderModule, which implements the complete functionality (together with base classes, helper classes and function libraries).
			/// %FEDM_ISCReaderModule is extended over a lot of years, the complexity is increased extremely and to get a quick overview is difficult. Therefore, this new thin C++ API was born.<br>
			/// In rare cases, when a special detail needs to be addressed, the pointer of the implementation object can be returned and the old API can be used in parallel with the class %ReaderModule.
			FEDM_ISCReaderModule* GetReaderImpl();

			/// @brief Get the last error code
			///
			/// @return last [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// In cases, when the result of a method is not as expected and it does not return an error code, the application should call this method first to
			/// evaluate an internal error. If this method returns OK (=0), then the application should call GetLastStatus() to evaluate the returned status byte 
			/// from the last Reader response.
			int GetLastError();
					
			/// @brief Get the last status byte
			///
			/// @return status byte from last Reader response. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// The method ICmdGroup::SendProtocol returns always the status byte of the responded Reader protocol. Thus, the evaluation of the Reader response can be done 
			/// - and this is strongly recommended - after the method call.
			/// But in cases, when the result of a method is not as expected and it does not return an error code,
			/// the application should call GetLastError() first to evaluate an internal error. 
			/// If this method returns OK (=0), then the application should call %GetLastStatus() to evaluate the returned status byte from the last Reader response.
			int GetLastStatus();
									
			/// @brief Return a text according the given status value
			///
			/// @param[in] ucStatus
			/// @return Message text for Reader status byte
			///
			/// <b>Description</b><br>
			std::string GetStatusText(unsigned char ucStatus);

            /// <summary>
            /// Executes a hardware reset of the Reader.
            /// 
            /// <b>Description:</b><br/>
            /// Dependent on the connected Reader type, the reboot is executed as a [0x63] CPU Reset or as a [0x64] System Reset.<br/>
            /// The Reader sends the response protocol at once and executes then the reboot.<br/>
            /// This means, that a Host system must wait until the Reader is rebooted before any further communication is proceeded.
            /// </summary>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            /// <remarks>
            /// <b>Important Notes for USB connection:</b><br/>
            /// In case of a USB connection the Reader executes a new enumeration after receiving this command.<br/>
            /// The current USB connection is refreshed internally and the Host must not reopen the connection again.<br/>
            /// <br/>
            /// <b>Important Notes for TCP connection:</b><br/>
            /// In case of a TCP connection the current connection is closed inside the Reader and the host system must reopen the connection again.<br/>
            /// </remarks>
            int Reboot();

            /// <summary>
            /// The RF-field of the Reader antenna is switched off for a short time with the [0x69] RF Reset command.
            /// 
            /// <b>Description:</b><br/>
            /// The RF-field of the Reader antenna is switched off for a few milliseconds. This time differs from Reader to Reader.<br/>
            /// The response of this command will be send after the RF-Reset was completed.<br/>
            /// All Transponders which are within the antenna field of the Reader will be reset to their reset state.<br/>
            /// </summary>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int RfReset();

            /// <summary>
            /// The RF-field of the Reader antenna is switched off with the [0x6A] RF On/Off command.
            /// 
            /// <b>Description:</b><br/>
            /// The RF-field of the Reader antenna is switched off.<br/>
            /// If the reader works in an Auto Read Mode (Buffered Read Mode, Scan Mode, Notification Mode or Access Mode), the RF communication is interrupted.<br/>
            /// After the Rf-field is switched off, the Reader accepts every Host command and the RF communication is handled on the last selected antenna.<br/>
            /// For selecting a specific antenna without continuing the Auto Read Mode, use <see cref="RfOn"/> and set the parameter maintainHostMode to true.<br/>
            /// </summary>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            /// <remarks>
            /// <b>Note for UHF Reader:</b><br/>
            /// A command to reset the persistance flags of Transponders is sent before the Rf-field is switched off.
            /// </remarks>
            int RfOff();

            /// <summary>
            /// The RF-field of the Reader is switsched on with the [0x6A] RF On/Off command.
            /// 
            /// <b>Description:</b><br/>
            /// The RF-field of the Reader antenna is switched on.<br/>
            /// If the reader works in an Auto Read Mode (Buffered Read Mode, Scan Mode, Notification Mode or Access Mode), the RF communication is continued with the selected antennaNo (>0) and when maintainHostMode is set to false.<br/>
            /// </summary>
            /// <param name="uiAntennaNo">Number of antenna to be selected to after Rf is switched on (> 0 and limited by the capabilities of the Reader)</param>
            /// <param name="bMaintainHostMode">Applicable only for Auto Read Mode: if true, Host Mode is maintained and the antenna, selected by antennaNo, is switched on</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int RfOn(unsigned int uiAntennaNo, bool bMaintainHostMode);

            /// <summary>
            /// The command serves temporary limited or unlimited activation of the outputs of the Reader with the [0x72] Set Output command
            /// 
            /// <b>Description:</b><br/>
            /// Each output takes the state defined by <see cref="OutputSetting"/> for the period of time.<br/>
            /// Each new call of SetOutput overwrites the current output states.
            /// </summary>
            /// <param name="vOutputSets">Dictionary with <see cref="OutputSetting"/>. The number and type of outputs differs from Reader to Reader.<br/>
            /// The output number is the key and the setting is the value of the dictionary.</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            /// <remarks>
            /// <b>Notes:</b><br/>
            /// To reset a continuously activation time, send settings for the respectively output with the activation time of 1.<br/>
            /// A reboot of the Reader resets all activated outputs to its idle state.
            /// </remarks>
            int SetOutput(const std::vector<Utility::OutputSetting> & vOutputSets);

            /// <summary>
            /// The actual status of the digital inputs can be determined with the [0x74] Get Input command.
            /// 
            /// </summary>
            /// <param name="input">Flags with the status of each input. Bit 0 for input 1, bit 1 for input 2 and so forth.</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int GetInput(unsigned int & input);

            /// <summary>
            /// The Reader's system clock is set
            /// 
            /// <b>Description:</b><br/>
            /// Dependent on the connected Reader type, the system clock is set with a [0x85] Set System Timer command or with [0x87] Set System Time and Date command.<br/>
            /// The first command sets only the internal timer while the second command sets the date and time.<br/>
            /// </summary>
            /// <param name="dateAndTime">Clock structure with date and time information to be set to in the Reader.<br/>
            /// For the [0x85] Set System Timer, only the time information is applicable.</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            /// <remarks>
            /// <b>Note for Auto Read Mode:</b><br/>
            /// After setting the system clock, a [0x33] Initialize Buffer command (<see cref="IBrmTableGroup.InitializeBuffer"/>) is necessary to restart the Auto Read Mode with correct time information.
            /// </remarks>
            int SetSystemClock(const Utility::DateTime & dateAndTime);

            /// <summary>
            /// Query of the Reader's system clock
            /// 
            /// <b>Description:</b><br/>
            /// Dependent on the connected Reader type, the system clock is queried with a [0x86] Get System Timer command or with [0x88] Get System Time and Date command.<br/>
            /// The first command gets only the internal timer while the second command gets the date and time.<br/>
            /// </summary>
            /// <param name="dateAndTime">Clock structure with date and time information from the Reader.<br/>
            /// For the [0x86] Get System Timer, only the time information is set.</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int GetSystemClock(Utility::DateTime & dateAndTime);

            /// <summary>
            /// A login for access to the Reader's configuration is executed with the [0xA0] Reader Login command.
            /// 
            /// <b>Description:</b><br/>
            /// A password can protect the configuration parameters from any read and write access, when it is configured in the Reader's configuration with (<see cref="ReaderConfig.AccessProtection.password"/>).<br/>
            /// A logout can be performed with any false password or with a <see cref="Reboot"/>.
            /// </summary>
            /// <param name="password">Password with 4 byte length. Use <see cref="Utility.HexConvert.byteArrayToHexString(byte[])"/> to convert the given password into a string</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int ReaderLogin(const std::string & password);

		public:

			/// @brief Nested interface providing port specific methods like ConnectUSB, etc.
			///
			/// <b>Description</b><br>
			IPortGroup		IPort;
					
			/// @brief Nested interface providing Reader command specific methods
			///
			/// <b>Description</b><br>
			ICommandGroup	ICmd;
					
			/// @brief Nested interface providing Reader configuration specific methods
			///
			/// <b>Description</b><br>
			IConfigGroup	ICfg;
					
			/// @brief Nested interface providing Reader info specific methods
			///
			/// <b>Description</b><br>
			IInfoGroup		IInfo;
					
			/// @brief Nested interface providing Host Mode table specific methods. Normally, method interface of ITagGroup should be preferred for Transponder communication
			///
			/// <b>Description</b><br>
			IHmTableGroup	IHmTable;
					
			/// @brief Nested interface providing Buffered Read Mode table specific methods
			///
			/// <b>Description</b><br>
			IBrmTableGroup	IBrmTable;
					
			/// @brief Nested interface providing special methods for asynchronous communication
			///
			/// <b>Description</b><br>
			IAsyncGroup		IAsync;
					
			/// @brief Nested interface providing special methods for logging
			///
			/// <b>Description</b><br>
			ILogGroup		ILog;

			/// @brief Nested interface providing special methods for key management
			IKeyMngGroup	IKeyMng;
			
		#if !defined(_FEDM_NO_FW_UPD_SUPPORT)
			/// @brief Nested interface providing methods for firmware update
			///
			/// <b>Description</b><br>
			IFwUpdGroup		IFwUpd;
		#endif

		#ifdef _FEDM_TAG_HANDLER
			/// @brief Nested interface providing transponder specific methods like Inventory and Select
			///
			/// <b>Description</b><br>
			ITagGroup		ITag;
		#endif

		#if !defined(_FEDM_NO_PD_SUPPORT) && !defined(_FEDM_NO_FU_SUPPORT)
			/// @brief Nested interface providing specific methods for external Devices (like Gate People Counter or Function Units)
			///
			/// <b>Description</b><br>
			IExtDeviceGroup		IExtDev;
		#endif

		private:

			FEDM_ISCReaderModule*	m_pReader;

			void Init();
			int SetSystemTime(const Utility::DateTime & dt);
			int GetSystemTime(Utility::DateTime & dt);
			int SetSystemDateTime(const Utility::DateTime & dt);
			int GetSystemDateTime(Utility::DateTime & dt);
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_H_INCLUDED_)
