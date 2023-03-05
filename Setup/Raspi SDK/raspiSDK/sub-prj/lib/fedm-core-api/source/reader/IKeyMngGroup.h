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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IKEY_MNG_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IKEY_MNG_GROUP_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		class ReaderModule;

		/// @brief Internal class providing communication port specific commands
		///
		/// <b>Description</b><br>
        /// This class realizes the nested interface with special methods for key management for the Reader class ReaderModule.<br/>
		/// Methods of this class can be called with the [IPort](@ref FEDM::Core::ReaderModule::IKeyMng) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IKeyMngGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;
			
		public:

            /// <summary>
            /// Transfer and persistent store of an Authentication Key for ISO 14443 MIFARE Transponder (MIFARE classic, MIFARE mini and MIFARE 1K or 4K) with [0xA2] Write MIFARE Reader Keys command.
            /// 
            /// <b>Description:</b><br/>
            /// A key which is used by the Reader for authentication to an NXP MIFARE Transponder will be stored persistent in the Reader.<br/>
            /// Only if the key of the Reader and of the Transponder correspond, the data exchange between Reader and Transponder can be successful executed.<br/>
            /// The factory adjustment of the keys on KEY-ADR 0x00 is:<br/>
            /// - KEY-A: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF<br/>
            /// - KEY-B: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
            /// </summary>
            /// <param name="uiKeyType">
            /// - 0: Key A<br/>
            /// - 1: Key B</param>
            /// <param name="uiKeyAddress">Address where the key is stored in the reader. Applicable values are 0..7.</param>
            /// <param name="sKey">6 byte key for authentication.<br/>
            /// Use <see cref="FEDM::Core::Utility::HexConvert::byteArrayToHexString(byte[])"/> for conversion of the key into a hexadecimal string with 12 chars</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int WriteTagAuthentKey_Mifare(unsigned int uiKeyType, unsigned int uiKeyAddress, const std::string & sKey);

            /// <summary>
            /// Transfer and store a DES or AES Authentication Key for ISO 14443 Transponder (MIFARE DESFire, MIFARE Plus and MIFARE Ultralight C) with [0xA3] Write DES/AES Reader Keys command.
            /// 
            /// <b>Description:</b><br/>
            /// An AES or DES key which is used by the Reader for authentication to an NXP MIFARE Transponder will be stored in the Reader.<br/>
            /// Only if the key of the Reader and of the Transponder correspond, the data exchange between Reader and Transponder can be successful executed.
            /// </summary>
            /// <param name="toEEPROM">
            /// - if false, the key is stored temporarely in the RAM. After the supply power was interrupted, the keys has to be loaded once again into the RAM.<br/>
            ///   This option is recommended, if the Reader is used on a public place and anybody can take the Reader away easily.<br/>
            /// - if true, the key ist stored persistent in the Reader's internal non-volatile memory (EEPROM).<br/>
            ///   This option can be used, if the Reader is installed at a secured place.</param>
            /// <param name="uiIndex">Address where the key is stored in the reader. Applicable values are 0..3.</param>
            /// <param name="uiAuthentMode">Type of key<br/>
            /// - 0: DESFire Native - TDES (16 byte) applicable for MIFARE DESFire<br/>
            /// - 1: Standard TDES (16 byte) applicable for MIFARE DESFire and MIFARE Ultralight C<br/>
            /// - 2: DESFire Native - DES (8 byte) applicable for MIFARE DESFire<br/>
            /// - 3: Standard DES (8 byte) applicable for MIFARE DESFire<br/>
            /// - 4: 3KTDES (24 byte) applicable for MIFARE DESFire<br/>
            /// - 5: AES (16 byte) applicable for MIFARE DESFire and MIFARE Plus<br/>
            /// </param>
            /// <param name="sKey">key for authentication.<br/>
            /// Use <see cref="FEDM::Core::Utility::HexConvert::byteArrayToHexString(byte[])"/> for conversion of the key into a hexadecimal string</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int WriteTagAuthentKey_ISO14443(bool toEEPROM, unsigned int uiIndex, unsigned int uiAuthentMode, const std::string & sKey);

            /// <summary>
            /// Transfer and store an AES Authentication Key for NXP UCODE/ICODE DNA Transponder with [0xA3] Write AES Reader Keys command.
            /// 
            /// <b>Description:</b><br/>
            /// An AES key which is used by the Reader for authentication to an NXP UCODE/ICODE DNA Transponder will be stored in the Reader.<br/>
            /// Only if the key of the Reader and of the Transponder correspond, the data exchange between Reader and Transponder can be successful executed.
            /// </summary>
            /// <param name="toEEPROM">
            /// - if false, the key is stored temporarely in the RAM<br/>
            /// - if true, the key ist stored persistent in the Reader's internal non-volatile memory (EEPROM)</param>
            /// <param name="uiIndex">Address where the key is stored in the reader. Applicable values are 0 and 1.</param>
            /// <param name="sKey">16 byte (128 bit) AES key for authentication.<br/>
            /// Use <see cref="FEDM.Core.Utility.HexConvert.byteArrayToHexString(byte[])"/> for conversion of the key into a hexadecimal string with 32 chars</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int WriteTagAuthentKey_UcodeDNA(bool toEEPROM, unsigned int uiIndex, const std::string & sKey);

            /// <summary>
            /// Transfer and store an Authentication Key for EPC Transponder with [0xAD] Write Reader Authentication Key command.
            /// 
            /// <b>Description:</b><br/>
            /// A key which is used by the Reader for authentication to a EPC Transponder will be stored in the Reader.<br/>
            /// Only if the key of the Reader and of the Transponder correspond, the data exchange between Reader and Transponder can be successful executed.
            /// </summary>
            /// <param name="toEEPROM">
            /// - if false, the key is stored temporarely in the RAM<br/>
            /// - if true, the key ist stored persistent in the Reader's internal non-volatile memory (EEPROM)</param>
            /// <param name="uiKeyType">only the value 3 is applicable for EPC Transponders</param>
            /// <param name="sKey">4 byte key. Use <see cref="FEDM.Core.Utility.HexConvert.byteArrayToHexString(byte[])"/> for conversion of the key into a hexadecimal string with eight chars</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int WriteTagAuthentKey_EPC(bool toEEPROM, unsigned int uiKeyType, const std::string & sKey);

		private:
				
			IKeyMngGroup();
			virtual ~IKeyMngGroup();
				
			ReaderModule*			m_pParent;
			FEDM_ISCReaderModule*	m_pReader;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IKEY_MNG_GROUP_H_INCLUDED_)
