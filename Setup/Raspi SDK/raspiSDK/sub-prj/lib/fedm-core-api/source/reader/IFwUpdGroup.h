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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IFWUPD_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IFWUPD_GROUP_H_INCLUDED_

#if !defined(_FEDM_NO_FW_UPD_SUPPORT)

#include <string>
#include <map>
#include "../source/FEDM.h"
#include "IFwUpdListener.h"

class FEDM_ISCReaderModule;
class FedmFwUpdModule;


namespace FEDM
{
	namespace Core
	{
		/** @brief Internal class providing methods for firmware update
		*
		* <b>Description</b><br>
		* This class realizes the nested interface with methods for firmware update for the Reader class ReaderModule.<br>
		* Methods of this class can be called with the [IFwUpd](@ref FEDM::Core::ReaderModule::IFwUpd) member of ReaderModule.<br>
		* 
		* @note It is strongly recommended to read and follow the instructions in the Application Note <i>N60810-e-ID-B.pdf</i>
		*/
		class _FEDM_ISC_CORE_EXT_CLASS IFwUpdGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;

		public:
			/** @brief Definition of a map type with version numbers of each controller firmware, embedded in the XML firmware file
			*
			* @param std::string controller type ("RF-Decoder", "RF-Controller", "AC-Controller", "Bootloader", "Keyboard", "Ext. SCR", "WLAN Module")
			* @param std::string version number in the format xx.yy.zz
			*/
			typedef std::map<std::string, std::string>					FW_INFO_LIST;

			/// Definition of an iterator for map type with version numbers
			typedef std::map<std::string, std::string>::const_iterator	FW_INFO_LIST_ITOR;

			/** @brief Request version number of firmware update library
			*
			* @return String with version number in the format xx.yy.zz
			*/
			std::string GetModuleVersion();
			
			/** @brief Method to execute a firmware update
			*
			* @param[in] sXmlFwPathname Firmware pathname (path and filename). Firmware files are XML files and available from FEIG ELECTRONIC
			* @param[in] uiLogOption Logging option
			* @param[in] sLogDir Optional destination path for log files
			* @param[in] pListener (optional) Pointer to listener class in application, which must be derived from [IFwUpdListener](@ref FEDM::Core::IFwUpdListener)
			* @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			*
			* <b>Description</b><br>
			* The update is executed in silent mode with optional update messages reflected with a listener.<br>
			* Different logging options can be enabled:<br>
			* a) no logging: set uiLogOption = IFwUpdGroup::LOGGING_OFF<br>
			* b) standard logging: set uiLogOption = IFwUpdGroup::LOGGING_STANDARD (this option is recommended)<br>
			* c) standard logging and additional protocol logging: set uiLogOption = IFwUpdGroup::LOGGING_WITH_PROTOCOLS<br>
			*
			* @note The connection to the Reader must be established before the use of this update method.
			*/
			int StartUpdateSilent(std::string sXmlFwPathname, unsigned int uiLogOption, std::string sLogDir, IFwUpdListener* pListener=NULL);

			/** @brief Method to check the compatibility of firmeware file with the connected Reader
			*
			* @param[in] sXmlFwPathname Firmware pathname (path and filename). Firmware files are XML files and available from FEIG ELECTRONIC
			* @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			*
			* <b>Description</b><br>
			* This method checks the compatibility of an XML firmware file with the connected Reader.<br>
			* It is preconditioned that the Reader is connected and the Reader Information is previously read
			* with [ReadReaderInfo](@ref FEDM::Core::IInfoGroup::ReadReaderInfo)
			*/
			int VerifyFile(std::string sXmlFwPathname);

			/** @brief Method to query version numbers of each controller firmware, embedded in the XML firmware file
			*
			* @return Info [FW_INFO_LIST](@ref FEDM::Core::IFwUpdGroup::FW_INFO_LIST) with version numbers of each controller firmware, embedded in the XML firmware file
			*
			* <b>Description</b><br>
			* This method returns a map with version numbers of each controller firmware, embedded in the XML firmware file.<br>
			* It is preconditioned that the Reader is connected and the compatibility of the XML firmware file is checked 
			* with [VerifyFile](@ref FEDM::Core::IFwUpdGroup::VerifyFile)
			*/
			const FW_INFO_LIST& GetFileInfo();
			
			/** @brief Option-ID for selecting additional options
			*
			* <b>Description</b><br>
			* The update is executed and no logfiles are generated.<br>
			*/
			static const unsigned int LOGGING_OFF = 0x00000100;
				
			/** @brief Option-ID for selecting additional options
			*
			* <b>Description</b><br>
			* The update is executed and a standard logfile is generated.<br>
			*/
			static const unsigned int LOGGING_STANDARD = 0x00010000;
				
			/** @brief Option-ID for selecting additional options
			*
			* <b>Description</b><br>
			* The update is executed and an additional logfile with exchanged protocols is generated.<br>
			*/
			static const unsigned int LOGGING_WITH_PROTOCOLS = 0x00020000;

		private:
			IFwUpdGroup();
			virtual ~IFwUpdGroup();

			void Init();

			FEDM_ISCReaderModule* m_pReader;
			FedmFwUpdModule* m_pUpdModule;
			
			FW_INFO_LIST m_Info;

			/* static callback function invoked by firmware update function (fedm-service library) with process information
				parameters:	void* pAny			- pointer to anything (passed with StartUpdate)
							int iStatus			- OK (=0) or error code (<0)
							int iNtfLevel		- notification level
							int iCounter		- process counter
							int iMaxCount		- limit of process counter
							char* pszMessage	- additional message
			*/
			static int cbsUpdMessage(void* pAny, int iStatus, int iNtfLevel, int iCounter, int iMaxCount, char* pszMessage);

			IFwUpdListener* m_pListener;
		};
	}
}

#endif // !defined(_FEDM_NO_FW_UPD_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IFWUPD_GROUP_H_INCLUDED_)
