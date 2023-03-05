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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IREADER_CONFIGURATION_MNG_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IREADER_CONFIGURATION_MNG_GROUP_H_INCLUDED_

#include <string>
#include <stdint.h>
#include "../source/FEDM.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing Reader configuration specific methods
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with configuration methods for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [ICfg](@ref FEDM::Core::ReaderModule::ICfg) member of ReaderModule.<br>
		class _FEDM_ISC_CORE_EXT_CLASS IConfigGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;

		public:

			/// @brief Method returns FEDM::Core::ErrorCode::OK, if configuration parameter meets the selected Reader configuration
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Call this method, if a configuration parameter must be checked if it is part of the selected Reader configuration.<br>
			/// The Reader configuration is selected after a call of IInfoGroup::ReadReaderInfo() or after a call of ReaderModule::SetReaderType().<br>
			/// A new object of ReaderModule is not initialized with a Reader Type and TestConfigPara() will fail.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			///  
			/// int back = reader.ICfg.TestConfigPara(ReaderConfig::Transponder::Driver::HF::Drivers);
			/// if( back == 0 )
			/// {
			///		// parameter is part of the selected Reader configuration
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			int TestConfigPara( std::string sParaName );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// As the parameter value is of type bool, only single bit parameters can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.<br>
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, bool* Data, bool bEEPROM=true );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// As the parameter value is of type unsigned char, only single byte parameters can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, unsigned char* Data, bool bEEPROM=true );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// The parameter value is an array of type unsigned char and can return a multi-byte parameter.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, unsigned char* Data, unsigned int uiDataLen, bool bEEPROM=true );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// As the parameter value is of type unsigned int, only parameters with up to 4 bytes can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, unsigned int* Data, bool bEEPROM=true );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// As the parameter value is of type int64_t, only parameters with up to 8 bytes can be returned.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, int64_t* Data, bool bEEPROM=true );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// The parameter value is a hex-coded string and can return a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 will be returned as "AB39F1".
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, std::string& Data, bool bEEPROM=true );

			/// @brief Method for getting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[out] Data Buffer for parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @param[in] bEEPROM If true, parameter value is from Reader&apos;s EEPROM, otherwise from RAM
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Overload method returns a parameter value, identified by parameter name. The parameter value must be previously read from the Reader, e.g. with ReadCompleteConfiguration().<br>
			/// The parameter value is a hex-coded string and can return a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 will be returned as "AB39F1".
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int GetConfigPara( std::string sParaName, char* Data, unsigned int uiDataLen, bool bEEPROM=true );
	

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data Parameter value
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// As the parameter value is of type bool, only single bit parameters can be set.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, bool Data, bool bEEPROM=true );

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data Parameter value
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// As the parameter value is of type unsigned char, only single byte parameters can be set.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, unsigned char Data, bool bEEPROM=true );

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data buffer with parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// The parameter value is an arry of type unsigned char and can set a multi-byte parameter.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, unsigned char* Data, unsigned int uiDataLen, bool bEEPROM=true );

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data Parameter value
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// As the parameter value is of type unsigned int, only 4 byte wide parameters can be set.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, unsigned int Data, bool bEEPROM=true );

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data Parameter value
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// As the parameter value is of type int64_t, only 8 byte wide parameters can be set.
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, int64_t Data, bool bEEPROM=true );

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data Parameter value
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// The parameter value is a hex-coded string and can set a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 must be set as "AB39F1".
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, std::string Data, bool bEEPROM=true );

			/// @brief Method for setting a configuration parameter value
			///
			/// @param[in] sParaName A string with parameter name. The parameter name is one of the namespace FEDM::Core::ReaderConfig 
			/// and must be applicable with the connected Reader
			/// @param[in] Data Buffer with parameter value
			/// @param[in] uiDataLen Length specification for data buffer
			/// @param[in] bEEPROM If true, parameter value is set for Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK and value not modified
			/// -   1 if OK and value modified
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// Overload method sets a parameter value, identified by parameter name. The parameter value must finally written into the Reader, e.g. with ApplyConfiguration().<br>
			/// The parameter value is a hex-coded string and can set a multi-byte parameter. Hex-coded string means, that a hex value of 0xAB39F1 must be set as "AB39F1".
			/// <br><br>
			/// @note It is recommended to evaluate always the return value in the application.
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int SetConfigPara( std::string sParaName, char* Data, unsigned int uiDataLen, bool bEEPROM=true );

					
			/// @brief Reads complete configuration from Reader
			///
			/// @param[in] bEEPROM If true, read from Reader&apos;s EEPROM, otherwise for RAM
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// This method reads all configuration parameter values from the Reader&apos;s EEPROM or RAM.
			/// This needs some time, dependent on the Reader type and the communication interface<br>
			/// It is recommended to use this method before any configuration value has to be modified. It is sufficient to read the complete configuration from the Reader once
			/// after the connection call and only, if configuration parameters have to be modified. Otherwise, an application needs not to read the configuration.<br>
			/// If an error occurs, then the function returns immediately.<br>
			/// If the Reader signals with one or more configuration pages a problem with a status (e.g. 0x15 for Read Protect), the function continuous the reading for all other configuration pages.<br>
			/// The return value is then the first status received from the Reader.<br>
			/// <br>
			/// See [Example](@ref FEDM::Core::IConfigGroup::ApplyConfiguration())
			int ReadCompleteConfiguration(bool bEEPROM);

			/// @brief Writes complete configuration into the Reader
			/// 
			/// @param[in] bEEPROM If true, write to Reader&apos;s EEPROM, otherwise to RAM
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// This method writes all configuration parameter values into the Reader&apos;s EEPROM or RAM.<br>
			/// It is recommended to use this method only, if all configuration blocks are prepared properly in the Reader object. 
			/// Normally, ApplyConfiguration() meets the most application needs.<br><br>
			/// If an error occurs, then the function returns immediately.<br>
			/// If all configuration pages could be written successful, then the function returns ErrorCode::OK.<br>
			/// If the Reader signals with one or more configuration pages a problem with a status (e.g. 0x16 for Write Protect), the function continuous the writing for all other configuration pages.<br>
			/// The return value is then the first status received from the Reader.<br>
			/// <br>
			/// <b>Take care with this method, as it changes all configuration parameters.</b>
			int WriteCompleteConfiguration(bool bEEPROM);

			/// @brief Resets complete configuration to factory default
			/// 
			/// @param[in] bEEPROM If true, Reader&apos;s EEPROM will be reset to factory default, otherwise the RAM
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// This method sets all configuration parameter values in the Reader&apos;s EEPROM and/or RAM to factory default.<br>
			/// <br><br>
			/// <b>Take care with this method, as it changes probably all configuration parameters.</b>
			int ResetCompleteConfiguration(bool bEEPROM);

			/// @brief Writes modified configuration pages to reader
			/// 
			/// @param[in] bEEPROM If true, write to Reader&apos;s EEPROM, otherwise to RAM
			/// @return
			///   0	if nothing to be applied to
			///	  1	if at least one page is successfully written
			/// < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// > 1	status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// This method writes all modified configuration parameter values into the Reader&apos;s EEPROM or RAM.<br>
			/// It is recommended to use this method after all configuration parameters are modified.<br>
			/// If multiple configuration blocks must be written and the Reader signals with one or more, but not all configuration pages a problem with a status (e.g. 0x16 for Write Protect), 
			/// the function continuous the writing for all other configuration pages.<br>
			/// If at least one modified configuration page could be written successful, then the function returns 1 and not the return value with a Reader status.<br>
			/// In this case, call [GetLastStatus](@ref ReaderModule::GetLastStatus()) to retrieve the status byte.<br>
			/// If only one configuration block must be written and the Reader returns with a status, then this status value is returned.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			///
			///	// method disables ISO 15693 tag driver and enables ISO 18000-3M3 tag driver
			/// void ModifyConfiguration()
			/// {
			///		bool bDrv = false;
			///
			///		// if not previously done, read complete configuration from Reader (needs some time, dependent on the Reader type and the communication interface)
			///		int back = reader.ICfg.ReadCompleteConfiguration(true);	// read from Reader's EEPROM
			///		if( back < 0 )
			///		{
			///			cout << reader.GetErrorText(back) << std::endl;
			///			return;
			///		}
			///		else if( back > 0 )
			///		{
			///			cout << reader.GetStatusText(back) << std::endl;
			///			return;
			///		}
			///	
			///		back = reader.ICfg.GetConfigPara(ReaderConfig::Transponder::Driver::HF::ISO_15693, &bDrv, true);
			///		if( back < 0 )
			///		{
			///			cout << << reader.GetErrorText(back) << std::endl;
			///			return;
			///		}
			///
			///		if(bDrv)
			///		{
			///			back = reader.ICfg.SetConfigPara(ReaderConfig::Transponder::Driver::HF::ISO_15693, false, true); // disable driver for ISO 15693
			///			if( back < 0 )
			///			{
			///				cout << << reader.GetErrorText(back) << std::endl;
			///				return;
			///			}
			///		}
			///
			///		back = reader.ICfg.GetConfigPara(ReaderConfig::Transponder::Driver::HF::ISO_18000_3M3, &bDrv, true);
			///		if( back < 0 )
			///		{
			///			cout << << reader.GetErrorText(back) << std::endl;
			///			return;
			///		}
			///
			///		if(!bDrv)
			///		{
			///			back = reader.ICfg.SetConfigPara(ReaderConfig::Transponder::Driver::HF::ISO_18000_3M3, true, true); // enable driver for ISO 18000-3M3
			///			if( back < 0 )
			///			{
			///				cout << << reader.GetErrorText(back) << std::endl;
			///				return;
			///			}
			///		}
			///
			///		int back = reader.ICfg.ApplyConfiguration(true);	// write to Reader's EEPROM
			///		if( back < 0 )
			///		{
			///			cout << << reader.GetErrorText(back) << std::endl;
			///			return;
			///		}
			///		else if( back == 1 )
			///		{
			///			cout << "all or some configuration pages are written successful" << std::endl;
			///			int status = reader.GetLastStatus();
			///			if( status > 0 )
			///			{
			///				cout << "one or more pages could not be written. " << reader.GetStatusText(back) << std::endl;
			///				return;
			///			}
			///		}
			///		else if( back > 1 )
			///		{
			///			cout << reader.GetStatusText(back) << std::endl;
			///			return;
			///		}
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			int ApplyConfiguration(bool bEEPROM);
	

			/// @brief Method for XML based reader profiling
			/// 
			/// @param[in] bRead If true, a subset of the Reader&apos;s configuration parameter set is read from a profile file, otherwise into a file
			/// @param[in] sFileName Name of the profile file
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// This method supports a way to modify only a subset of the Reader&apos;s configuration. This ensures to define special configuration settings for different projects.
			/// Actually, the definition of configuration profiles is not supported.
			int SerializeProfile(bool bRead, char* sFileName);

			/// @brief Method for XML serialization
			/// 
			/// @param[in] bRead If true, the complete Reader configuration is read from a file, otherwise into a file
			/// @param[in] sFileName Name of the configuration file
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// This method supports an easy way to read a Reader configuration from a file or save a Reader configuration into a file.<br>
			/// The configuration in the reader keeps unchanged.
			int Serialize(bool bRead, char* sFileName);


			/// @brief Method to transfer configuration from XML file to reader
			///
			/// @param[in] sFileName Name of the configuration file
			/// @return
			/// -   0 ifOK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Opens an XML file, transfers the configuration data into the respective data container and writes afterwards the complete configuration into the Reader.
			int TransferXmlFileToReaderCfg(char* sFileName);

			/// @brief Method to transfer configuration from reader to XML file
			///
			/// @param[in] sFileName Name of the configuration file
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Reads the complete configuration from the Reader, saves it in the respective data container and writes afterwards the configuration data into an XML file.
			int TransferReaderCfgToXmlFile(char* sFileName);

		private:

			IConfigGroup();
			virtual ~IConfigGroup();

			FEDM_ISCReaderModule* m_pReader;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IREADER_CONFIGURATION_MNG_GROUP_H_INCLUDED_)
