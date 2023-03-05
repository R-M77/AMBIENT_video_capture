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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_DESFIRE_FLEX_SOFT_CRYPTO_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_DESFIRE_FLEX_SOFT_CRYPTO_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include <string>
#include "FedmIscCore.h"

class FedmIscTagHandler_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto;


namespace FEDM
{
	namespace Core
	{
		class ITagGroup;

		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class, nested in class TH_ISO14443_4_MIFARE_DESFire, providing manufacturer specific commands for ISO 14443-4 compliant Transponders of type MIFARE DESFire from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// This class implements the communication with [0xC3] Reader commands and flexible software cryptographic.<br>
			/// Detailed description about the command interface can be found in:
			/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
			/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:
				friend class TH_ISO14443_4_MIFARE_DESFire;

				/** @brief Method to query the last Error Source
					* 
					* @return Error Source
					*/
				unsigned char	GetErrorSource();

				/** @brief Method to query the last Error Code
					* 
					* @return Error Code
					*/
				unsigned int	GetErrorCode();

				//####################################################################
				// 5 security related commands
	
				/// @brief DESFire command [0x0A] Authenticate or [0x1A] AuthenticateISO or [0xAA] AuthenticateAES, realized with Reader command [0xC3][0xFA] Authent
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a security related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				/// <br>
				/// The explicite Authenticate method is defined by the Key, previously stored in the Reader with the Reader command [0xA3] Write DES/AES Reader Keys
				int Authenticate(		unsigned char ucReaderKeyIndex,
										unsigned char ucDESFireKeyNo );
	
				/// @brief DESFire command [0x54] Change Key Settings, realized with Reader command [0xC3][0x54]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a security related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ChangeKeySettings(	unsigned char ucNewKeySettings );
	
				/// @brief DESFire command [0x45] Get Key Settings, realized with Reader command [0xC3][0x45]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a security related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetKeySettings(		unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );

				/// @brief DESFire command [0xC4] Change Key, realized with Reader command [0xC3][0xC4]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a security related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ChangeKey(			unsigned char ucKeyNoToBeChanged,
										unsigned char ucAESNewKeyVersion,
										std::string sOldKey,
										std::string sNewKey );
	
				/// @brief DESFire command [0x64] Get Key Version, realized with Reader command [0xC3][0x64]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a security related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetKeyVersion(		unsigned char ucDESFireKeyNo,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );


				//####################################################################
				// 10 PICC level commands

				/// @brief DESFire command [0xCA] Create Application, realized with Reader command [0xC3][0xCA]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CreateApplication(	unsigned char ucPiccLevelFlags,
										unsigned int uiApplicationID,
										unsigned char ucKeySetting1,
										unsigned char ucKeySetting2,
										unsigned int uiISOFileID,
										std::string sDFName );
	
				/// @brief DESFire command [0xDA] Delete Application, realized with Reader command [0xC3][0xDA]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int DeleteApplication(	unsigned char ucPiccLevelFlags,
										unsigned int uiApplicationID );
	
				/// @brief DESFire command [0x6A] Get Application IDs, realized with Reader command [0xC3][0x6A]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetApplicationIDs(	unsigned char ucPiccLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );

				/// @brief DESFire command [0x6E] Free Memory, realized with Reader command [0xC3][0x6E]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int FreeMemory(			unsigned char ucPiccLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );

				/// @brief DESFire command [0x6D] Get DF-Names, realized with Reader command [0xC3][0x6D]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetDFNames(			unsigned char ucPiccLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );
	
				/// @brief DESFire command [0x5A] Select Application, realized with Reader command [0xC3][0x5A]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int SelectApplication(	unsigned char ucPiccLevelFlags,
										unsigned int uiApplicationID );

				/// @brief DESFire command [0xFC] Format PICC, realized with Reader command [0xC3][0xFC]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int FormatPICC(			unsigned char ucPiccLevelFlags );

				/// @brief DESFire command [0x60] Get Version, realized with Reader command [0xC3][0x60]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetVersion(			unsigned char ucPiccLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );

				/// @brief DESFire command [0x51] Get Card-UID, realized with Reader command [0xC3][0x51]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetCardUID(			unsigned char ucPiccLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );
	
				/// @brief DESFire command [0x5C] Set Configuration, realized with Reader command [0xC3][0x5C]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a PICC level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int SetConfiguration(	unsigned char ucPiccLevelFlags,
										unsigned char* pucRequestData,
										unsigned int uiRequestLength );


				//####################################################################
				// 10 application level commands

				/// @brief DESFire command [0x5F] Change File Settings, realized with Reader command [0xC3][0x5F]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ChangeFileSettings(	unsigned char ucApplicationLevelFlags,
										unsigned char ucFileNo,
										unsigned char ucNewFileCommSettings,
										unsigned char ucNewFileReadWriteAccessRights,
										unsigned char ucNewFileChangeAccessRights,
										unsigned char ucNewFileReadAccessRights,
										unsigned char ucNewFileWriteAccessRights );

				/// @brief DESFire command [0x6F] Get File IDs, realized with Reader command [0xC3][0x6F]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetFileIDs(			unsigned char ucApplicationLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );

				/// @brief DESFire command [0xF5] Get File Settings, realized with Reader command [0xC3][0x5F]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetFileSettings(	unsigned char ucApplicationLevelFlags,
										unsigned char ucFileNo,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );

				/// @brief DESFire command [0xCD] Create StdDataFile, realized with Reader command [0xC3][0xCD]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CreateStdDataFile(	unsigned char ucApplicationLevelFlags,
										unsigned char ucFileNo,
										unsigned int uiISOFileID,
										unsigned char ucFileCommSettings,
										unsigned char ucFileReadWriteAccessRights,
										unsigned char ucFileChangeAccessRights,
										unsigned char ucFileReadAccessRights,
										unsigned char ucFileWriteAccessRights,
										unsigned int uiFileSize );

				/// @brief DESFire command [0xCB] Create BackupDataFile, realized with Reader command [0xC3][0xCB]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CreateBackupDataFile(	unsigned char ucApplicationLevelFlags,
											unsigned char ucFileNo,
											unsigned int uiISOFileID,
											unsigned char ucFileCommSettings,
											unsigned char ucFileReadWriteAccessRights,
											unsigned char ucFileChangeAccessRights,
											unsigned char ucFileReadAccessRights,
											unsigned char ucFileWriteAccessRights,
											unsigned int uiFileSize );

				/// @brief DESFire command [0xCC] Create ValueFile, realized with Reader command [0xC3][0xCC]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CreateValueFile(	unsigned char ucApplicationLevelFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned char ucFileReadWriteAccessRights,
										unsigned char ucFileChangeAccessRights,
										unsigned char ucFileReadAccessRights,
										unsigned char ucFileWriteAccessRights,
										unsigned int uiLowerLimit,
										unsigned int uiUpperLimit,
										unsigned int uiValue,
										unsigned char ucLimitedCreditEnabled );

				/// @brief DESFire command [0xC1] Create LinearRecordFile, realized with Reader command [0xC3][0xC1]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CreateLinearRecordFile(	unsigned char ucApplicationLevelFlags,
											unsigned char ucFileNo,
											unsigned int uiISOFileID,
											unsigned char ucFileCommSettings,
											unsigned char ucFileReadWriteAccessRights,
											unsigned char ucFileChangeAccessRights,
											unsigned char ucFileReadAccessRights,
											unsigned char ucFileWriteAccessRights,
											unsigned int uiRecordSize,
											unsigned int uiMaxNoOfRecords );

				/// @brief DESFire command [0xC0] Create CyclicRecordFile, realized with Reader command [0xC3][0xC0]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CreateCyclicRecordFile(	unsigned char ucApplicationLevelFlags,
											unsigned char ucFileNo,
											unsigned int uiISOFileID,
											unsigned char ucFileCommSettings,
											unsigned char ucFileReadWriteAccessRights,
											unsigned char ucFileChangeAccessRights,
											unsigned char ucFileReadAccessRights,
											unsigned char ucFileWriteAccessRights,
											unsigned int uiRecordSize,
											unsigned int uiMaxNoOfRecords );

				/// @brief DESFire command [0xDF] DeleteFile, realized with Reader command [0xC3][0xDF]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int DeleteFile(			unsigned char ucApplicationLevelFlags,
										unsigned char ucFileNo );

				/// @brief DESFire command [0x61] Get ISOFile IDs, realized with Reader command [0xC3][0x61]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an application level related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetISOFileIDs(		unsigned char ucApplicationLevelFlags,
										unsigned char* pucResponseData,
										unsigned int uiResponseBufferLength,
										unsigned int& uiResponseLength );


				//####################################################################
				// 11 data manipulation commands
	
				/// @brief DESFire command [0xBD] Read Standard Data, realized with Reader command [0xC1][0xBD]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ReadStandardData(	unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiFileOffset,
										unsigned int uiFileLen,
										unsigned char* pucFileData );
	
				/// @brief DESFire command [0x3D] Write Standard Data, realized with Reader command [0xC3][0x3D]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int WriteStandardData(	unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiFileOffset,
										unsigned int uiFileLen,
										unsigned char* pucFileData );

				/// @brief DESFire command [0x6C] Get Value, realized with Reader command [0xC3][0x6C]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int GetValue(			unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int& uiValue );

				/// @brief DESFire command [0x0C] Credit, realized with Reader command [0xC3][0x0C]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Credit(				unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiCreditValue );

				/// @brief DESFire command [0xDC] Debit, realized with Reader command [0xC3][0xDC]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Debit(				unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiDebitValue );


				/// @brief DESFire command [0x1C] Limited Credit, realized with Reader command [0xC3][0x1C]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int LimitedCredit(		unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiCreditValue );

				/// @brief DESFire command [0x3B] Write Record, realized with Reader command [0xC3][0x3B]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int WriteRecord(		unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiFileOffset,
										unsigned int uiRecordLen,
										unsigned char* pucRecordData );

				/// @brief DESFire command [0xBB] Read Records, realized with Reader command [0xC3][0xBB]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ReadRecords(		unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings,
										unsigned int uiRecordOffset,
										unsigned int uiNoOfRecords,
										unsigned int uiRecordSize,
										unsigned char* pucRecordData );

				/// @brief DESFire command [0xEB] Clear Record File, realized with Reader command [0xC3][0xEB]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ClearRecordFile(	unsigned char ucDataManipulationFlags,
										unsigned char ucFileNo,
										unsigned char ucFileCommSettings );

				/// @brief DESFire command [0xC7] Commit Transaction, realized with Reader command [0xC3][0xC7]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int CommitTransaction(	unsigned char ucDataManipulationFlags );

				/// @brief DESFire command [0xA7] Abort Transaction, realized with Reader command [0xC3][0xA7]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a data manipulation related command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE DESFire from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int AbortTransaction(	unsigned char ucDataManipulationFlags );

			protected:
				// constructor
				TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto();
				// destructor
				virtual ~TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto();

				FedmIscTagHandler_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto* m_pImpl;

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_DESFIRE_FLEX_SOFT_CRYPTO_H_INCLUDED_)
