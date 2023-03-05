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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_SL3_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_SL3_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include <string>
#include "TH_ISO14443_4_MIFARE_Plus.h"

class FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL3;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_4_MIFARE_Plus_SL3
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-4 compliant Transponders of type MIFARE Plus in Security Level 3 from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// This class implements the communication with [0xC2] Reader commands.<br>
			/// Detailed description about the command interface can be found in:
			/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
			/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_4_MIFARE_Plus_SL3 : public TH_ISO14443_4_MIFARE_Plus
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				// Security Level 3 commands

				/// @brief MIFARE Plus Command [0x78], realized with Reader command [0xC2][0x78] SL3 Reset Authent
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int ResetAuthentication();

				/// @brief MIFARE Plus Command [0x30], realized with Reader command [0xC2][0x30] SL3 Read Encrypted
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_Encrypted(			unsigned int uiBlockNo, 
											unsigned char ucExt, 
											unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x31], realized with Reader command [0xC2][0x31] SL3 Read Encrypted Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_EncryptedMaced(	unsigned int uiBlockNo, 
											unsigned char ucExt, 
											unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x32], realized with Reader command [0xC2][0x32] SL3 Read Plain
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_Plain(				unsigned int uiBlockNo, 
											unsigned char ucExt, 
											unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x33], realized with Reader command [0xC2][0x33] SL3 Read Plain Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_PlainMaced(		unsigned int uiBlockNo, 
											unsigned char ucExt, 
											unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x34], realized with Reader command [0xC2][0x34] SL3 Read Encrypted Unmaced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_EncryptedUnmaced(	unsigned int uiBlockNo, 
											unsigned char ucExt, 
											unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x35], realized with Reader command [0xC2][0x35] SL3 Read Encrypted Unmaced Respond Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_EncryptedUnmaced_RespondMaced(	unsigned int uiBlockNo, 
														unsigned char ucExt, 
														unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x36], realized with Reader command [0xC2][0x36] SL3 Read Plain Unmaced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_PlainUnmaced(		unsigned int uiBlockNo, 
											unsigned char ucExt, 
											unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0x37], realized with Reader command [0xC2][0x37] SL3 Read Plain Unmaced Respond Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Read_PlainUnmaced_RespondMaced(		unsigned int uiBlockNo, 
														unsigned char ucExt, 
														unsigned char* pucResponseData );

				/// @brief MIFARE Plus Command [0xA0], realized with Reader command [0xC2][0xA0] SL3 Write Encrypted
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Write_Encrypted(		unsigned int uiBlockNo, 
											unsigned char ucLength,
											unsigned char* pucRequestData );

				/// @brief MIFARE Plus Command [0xA1], realized with Reader command [0xC2][0xA1] SL3 Write Encrypted Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Write_EncryptedMaced(	unsigned int uiBlockNo, 
											unsigned char ucLength,
											unsigned char* pucRequestData );

				/// @brief MIFARE Plus Command [0xA2], realized with Reader command [0xC2][0xA2] SL3 Write Plain
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Write_Plain(			unsigned int uiBlockNo, 
											unsigned char ucLength,
											unsigned char* pucRequestData );

				/// @brief MIFARE Plus Command [0xA3], realized with Reader command [0xC2][0xA3] SL3 Write Plain Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Write_PlainMaced(		unsigned int uiBlockNo, 
											unsigned char ucLength,
											unsigned char* pucRequestData );

				/// @brief MIFARE Plus Command [0xB0], realized with Reader command [0xC2][0xB0] SL3 Increment Encrypted
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Increment_Encrypted(		unsigned int uiSourceBlockNo, 
												unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB1], realized with Reader command [0xC2][0xB1] SL3 Increment Encrypted Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Increment_EncryptedMaced(	unsigned int uiSourceBlockNo, 
												unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB2], realized with Reader command [0xC2][0xB2] SL3 Decrement Encrypted
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Decrement_Encrypted(		unsigned int uiSourceBlockNo, 
												unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB3], realized with Reader command [0xC2][0xB3] SL3 Decrement Encrypted Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Decrement_EncryptedMaced(	unsigned int uiSourceBlockNo, 
												unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB4], realized with Reader command [0xC2][0xB4] SL3 Transfer
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Transfer(					unsigned int uiDestinationBlockNo );

				/// @brief MIFARE Plus Command [0xB5], realized with Reader command [0xC2][0xB5] SL3 Transfer Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Transfer_Maced(				unsigned int uiDestinationBlockNo );

				/// @brief MIFARE Plus Command [0xB6], realized with Reader command [0xC2][0xB6] SL3 Increment Transfer Encrypted
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Increment_Transfer_Encrypted(		unsigned int uiSourceBlockNo,
														unsigned int uiDestinationBlockNo,
														unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB7], realized with Reader command [0xC2][0xB7] SL3 Increment Transfer Encrypted Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Increment_Transfer_EncryptedMaced(	unsigned int uiSourceBlockNo,
														unsigned int uiDestinationBlockNo,
														unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB8], realized with Reader command [0xC2][0xB8] SL3 Decrement Transfer Encrypted
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Decrement_Transfer_Encrypted(		unsigned int uiSourceBlockNo,
														unsigned int uiDestinationBlockNo,
														unsigned int uiData );

				/// @brief MIFARE Plus Command [0xB9], realized with Reader command [0xC2][0xB9] SL3 Decrement Transfer Encrypted Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Decrement_Transfer_EncryptedMaced(	unsigned int uiSourceBlockNo,
														unsigned int uiDestinationBlockNo,
														unsigned int uiData );

				/// @brief MIFARE Plus Command [0xC2], realized with Reader command [0xC2][0xC2] SL3 Restore
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Restore(					unsigned int uiSourceBlockNo );

				/// @brief MIFARE Plus Command [0xC3], realized with Reader command [0xC2][0xC3] SL3 Restore Maced
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 3 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Restore_Maced(				unsigned int uiSourceBlockNo );


			protected:
				// constructor
				TH_ISO14443_4_MIFARE_Plus_SL3(ReaderModule* pReader, FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL3* pThImpl);
				// destructor
				virtual ~TH_ISO14443_4_MIFARE_Plus_SL3();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_SL3_H_INCLUDED_)
