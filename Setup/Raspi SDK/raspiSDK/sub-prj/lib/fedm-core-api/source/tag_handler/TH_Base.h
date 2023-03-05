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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_BASE_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_BASE_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

//#if defined(_MSC_VER)
//#include "stdafx.h"
//#endif

#include <string>
#include "FedmIscCore.h"

class FedmIscTagHandler;

namespace FEDM
{
	namespace Core
	{
		class ITagGroup;
		class ReaderModule;

		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_Base
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing basic commands for all Transponders
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// This class supports non-addressed, selected and addressed mode in Host Mode.
			class _FEDM_ISC_CORE_EXT_CLASS TH_Base
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// Class represents one RSSI record of requested Host Mode data with command [0xB0][0x01] Inventory
				class _FEDM_ISC_CORE_EXT_CLASS RssiItem
				{
					friend class FEDM::Core::TagHandler::TH_Base;

				protected:
					RssiItem(unsigned char ucAntennaNumber, unsigned char ucStatus, unsigned char ucRSSI, unsigned short int usPhaseAngle);

				public:
					unsigned char m_ucAntNo;			///< Antenna Number
					unsigned char m_ucStatus;			///< Status value
					unsigned char m_ucRSSI;				///< RSSI value
					unsigned short int m_usPhaseAngle;	///< Phase Angle value
				};

				/// @brief type definition for a map, collecting RSSI values
				///
				/// @param Key Antenna Number
				/// @param Value Pointer to the RSSI object; see [RssiItem](@ref TH_Base::RssiItem)
				typedef std::map<unsigned char, RssiItem*>					RSSI_MAP;

				/// type definition for a map iterator, collecting RSSI values
				typedef std::map<unsigned char, RssiItem*>::const_iterator	RSSI_MAP_ITOR;

				/// @brief Initialization method
				///
				/// <b>Description</b><br>
				/// Clears all data members
				virtual void Init();

				/// @brief Return of TagHandler Type Number
				///
				/// @return Type Number
				///
				/// <b>Description</b><br>
				/// Return of TagHandler Type Number
				unsigned int	GetTagHandlerType();

				/// @brief Return of Transponder Driver Type Number
				///
				/// @return Driver Type Number
				///
				/// <b>Description</b><br>
				/// Return of Transponder Driver Type Number. See Reader&apos;s System Manual for the full list of all Transponder Driver Type Numbers.
				unsigned int	GetTagDriverType();

				/// @brief Return of TagHandler Type Number
				///
				/// @return Transponder Name
				///
				/// <b>Description</b><br>
				/// Return of TagHandler Type Number
				std::string	GetTagName();

				/// @brief Return of IDD
				///
				/// @return string with IDD
				///
				/// <b>Description</b><br>
				/// Return of Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder. For EPC Class 1 Gen 2 or ISO 18000-3M3 standards, the Electronic Product Code (EPC) is returned.
				/// If the Reader is configured to return the EPC with additional TID, then both is returned.
				std::string	GetIDD();

				/// @brief Return of Received Signal Strength Indication (RSSI) value
				///
				/// @return map with RSSI value and status for each antenna
				///
				/// <b>Description</b><br>
				/// Method to query a map with Received Signal Strength Indication (RSSI). The map contains a RSSI and status value for each antenna, where the Transponder is detected.
				/// The key of the map is the antenna number, the value is a pointer to a structure of type RssiItem with the RSSI and status value.
				///
				/// @note This additional antenna values are not available with all Readers. See Reader&apos;s System Manual for additional information.
				const RSSI_MAP& GetRSSI();

				/// @brief Return of Transponder address after an error
				///
				/// @return Address number, where an error occured
				///
				/// <b>Description</b><br>
				unsigned int GetErrorDBAddress();

				/// @brief Return of additional, Transponder specific error code
				///
				/// @return Error code
				///
				/// <b>Description</b><br>
				unsigned char GetLastISOErrorCode();

				/// @brief Request of non-addressed status
				///
				/// @return non-addressed status
				///
				/// <b>Description</b><br>
				bool IsNonAddressedModeEnabled();

				/// @brief Request of selected status
				///
				/// @return selected status
				///
				/// <b>Description</b><br>
				bool IsSelected();


				/// @brief Basic [0xB0][0x23] Read Multiple Blocks command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..255]
				/// @param[in] uiNoOfDataBlocks Number of requested data blocks [0..255]
				/// @param[out] uiBlockSize Number of bytes in each data block
				/// @param[out] pucData Pointer to array for received data blocks. The array must have the dimension of uiNoOfDataBlocks x Expected Block Size
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Basic [0xB0][0x23] Read Multiple Blocks command<br>
				/// - Without support for extended address mode<br>
				/// - Without request of security status<br>
				int ReadMultipleBlocks(	unsigned int uiFirstDataBlock,
										unsigned int uiNoOfDataBlocks,
										unsigned int& uiBlockSize,
										unsigned char* pucData );

				/// @brief Basic [0xB0][0x23] Read Multiple Blocks command with additional security status
				///
				/// @param[in] uiFirstDataBlock First data block address [0..255]
				/// @param[in] uiNoOfDataBlocks Number of requested data blocks [0..255]
				/// @param[out] uiBlockSize Number of bytes in each data block
				/// @param[out] pucSecurityStatus Array with received status information, one byte for each data block. The array must have the dimension of uiNoOfDataBlocks
				/// @param[out] pucData Pointer to array for received data blocks. The array must have the dimension of uiNoOfDataBlocks x Expected Block Size
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Basic [0xB0][0x23] Read Multiple Blocks command with additional security status<br>
				/// - Without support for extended address mode<br>
				int ReadMultipleBlocks(	unsigned int uiFirstDataBlock,
										unsigned int uiNoOfDataBlocks,
										unsigned int& uiBlockSize,
										unsigned char* pucSecurityStatus,
										unsigned char* pucData );

				/// @brief Basic [0xB0][0x24] Write Multiple Blocks command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..255]
				/// @param[in] uiNoOfDataBlocks Number of data blocks to transmit to [0..255]
				/// @param[in] uiBlockSize Number of bytes in each data block
				/// @param[in] pucData Pointer to array with data blocks to transmit to
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Basic [0xB0][0x24] Write Multiple Blocks command<br>
				/// - Without support for extended address mode<br>
				int WriteMultipleBlocks(	unsigned int uiFirstDataBlock,
											unsigned int uiNoOfDataBlocks,
											unsigned int uiBlockSize,
											unsigned char* pucData );

			public:

				// declaration of tag handler types for run-time identification

				/// @brief Identifier for Base TagHandler class
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_BASIC = 1;
				/// @brief Identifier for Transponder class for EPC Class1 Generation2
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_EPC_CLASS1_GEN2 = 10;
				/// @brief Identifier for Transponder class for EPC Class1 Generation2, with extension for SL900A of Manufacturer IDS Microchip AG
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_EPC_CLASS1_GEN2_IDS_SL900A = 11;
				/// @brief Identifier for ISO 14443 Transponder class
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443 = 20;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extension for Innovatron (ISO 14443B')
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_INNOVATRON = 21;
				/// @brief Identifier for ISO 14443-2 Transponder class
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_2 = 30;
				/// @brief Identifier for ISO 14443-2 Transponder class, with extension for Innovision Jewel
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_2_INNOVISION_JEWEL = 31;
				/// @brief Identifier for ISO 14443-2 Transponder class, with extension for SR176 of manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_2_STM_SR176 = 32;
				/// @brief Identifier for ISO 14443-2 Transponder class, with extension for SRIxxx series of manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_2_STM_SRIxxx = 33;
				/// @brief Identifier for ISO 14443-3 Transponder class
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3 = 40;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for my-d move of Manufacturer Infineon Technologies AG
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_INFINEON_MY_D = 41;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for my-d move of Manufacturer Infineon Technologies AG
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_INFINEON_MY_D_MOVE = 42;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for MIFARE Classic (Mini, 1K, 4K) of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_MIFARE_CLASSIC = 43;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for MIFARE Ultralight of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_MIFARE_ULTRALIGHT = 44;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for MIFARE Plus in Security Level 1 of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_MIFARE_PLUS_SL1 = 45;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for MIFARE Plus in Security Level 2 of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_MIFARE_PLUS_SL2 = 46;
				/// @brief Identifier for ISO 14443-3 Transponder class, with extensions for CTx series of Manufacturer ASK
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_3_ASK_CTX = 47;
				/// @brief Identifier for ISO 14443-4 Transponder class
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_4 = 50;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MIFARE DESFire of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_4_MIFARE_DESFIRE = 51;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MIFARE Plus in Security Level 1 of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_4_MIFARE_PLUS_SL1 = 52;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MIFARE Plus in Security Level 2 of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_4_MIFARE_PLUS_SL2 = 53;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MIFARE Plus in Security Level 3 of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO14443_4_MIFARE_PLUS_SL3 = 54;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO14443_4_MAXIM = 60;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MAX66000 of Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO14443_4_MAXIM_MAX66000 = 61;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MAX66020 of Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO14443_4_MAXIM_MAX66020 = 62;
				/// @brief Identifier for ISO 14443-4 Transponder class, with extensions for MAX66040 of Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO14443_4_MAXIM_MAX66040 = 63;
				/// @brief Identifier for Transponder class for ISO 18000-3M3
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO18000_3M3 = 100;
				/// @brief ISO 15693 Transponder class
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693 = 0xE0000000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM = 0xE0020000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for LRI2K of Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM_LRI2K = 0xE0022000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for LRIS2K of Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM_LRIS2K = 0xE0020280;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for LRIS64K of Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM_LRIS64K = 0xE0020440;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for M24LR64-R of Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM_M24LR64R = 0xE00202C0;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for M24LRxxE-R series of Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM_M24LRxxER = 0xE00205C0;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for ST25DVxxK series of Manufacturer STMicroelectronics SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_STM_ST25DVxxK = 0xE0022400;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP = 0xE0040000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLI of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLI = 0xE0040100;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLIX of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLIX = 0xE0040110;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLIX2 of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLIX2 = 0xE0040108;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLI-L of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLI_L = 0xE0040300;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLIX-L of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLIX_L = 0xE0040310;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLI-S of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLI_S = 0xE0040200;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE SLIX-S of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_SLIX_S = 0xE0040210;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for I-CODE DNA of Manufacturer NXP Semiconductors
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_NXP_ICODE_DNA = 0xE0040118;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer Infineon Technologies AG
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_INFINEON = 0xE0050000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for my-d of Manufacturer Infineon Technologies AG
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_INFINEON_MY_D = 0xE005FFFF;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer Texas Instruments
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_TI = 0xE0070000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Tag-it HFI Pro of Manufacturer Texas Instruments
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_TI_TAG_IT_HFI_PRO = 0xE007E000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Tag-it HFI Plus of Manufacturer Texas Instruments
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_TI_TAG_IT_HFI_PLUS = 0xE0078000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer Fujitsu Limited
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_FUJITSU = 0xE0080000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for MB89R1xx series of Manufacturer Fujitsu Limited
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_FUJITSU_MB89R1xx = 0xE0080001;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer EM Microelectronic-Marin SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_EM = 0xE0160000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for EM4034 of Manufacturer EM Microelectronic-Marin SA
				///
				/// <b>Description</b><br>
				static const unsigned int TYPE_ISO15693_EM_4034 = 0xE0160004;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer KSW Microtec GmbH
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO15693_KSW = 0xE0170000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO15693_MAXIM = 0xE02B0000;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for MAX66100 of Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO15693_MAXIM_MAX66100 = 0xE02B0010;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for MAX66120 of Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO15693_MAXIM_MAX66120 = 0xE02B0020;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for MAX66140 of Manufacturer Maxim
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO15693_MAXIM_MAX66140 = 0xE02B0030;
				/// @brief Identifier for ISO 15693 Transponder class, with extensions for SL13A of Manufacturer IDS Microchip AG
				///
				/// <b>Description</b><br>
//				static const unsigned int TYPE_ISO15693_IDS_SL13A = 0xE036FFFF;
				// protected methods
				
			protected:
				// constructor
				TH_Base(ReaderModule* pReader, FedmIscTagHandler* pThImpl);
				// destructor
				virtual ~TH_Base();

				void SetTagErrorCode(unsigned char ucTagError, unsigned int uiErrorDBAddress);
				void ClearTagError();

				ReaderModule* m_pReader;
				FedmIscTagHandler* m_pThImpl;

				// private attributes
			private:
				void ClearRssiMap();

				RSSI_MAP m_mapRSSI;

				bool m_bThisTagError; // indicates, that tag error code is stored in this class and not in FedmIscTagHandler of fedm-core
				unsigned int	m_uiErrorDBAddress;
				unsigned char	m_ucTagErrorCode;
			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_BASE_H_INCLUDED_)
