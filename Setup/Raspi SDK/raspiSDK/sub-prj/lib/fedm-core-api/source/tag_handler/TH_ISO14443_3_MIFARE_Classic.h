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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_CLASSIC_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_CLASSIC_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3.h"

class FedmIscTagHandler_ISO14443_3_MIFARE_Classic;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3_MIFARE_Classic
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-3 compliant Transponders of type MIFARE Classic (Mini, 1K, 4K) from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3_MIFARE_Classic : public TH_ISO14443_3
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Value command
				///
				/// @param[in] ucCommand First data block address
				/// @param[in] ucSourceAddress Sourec address
				/// @param[in] uiValue Value
				/// @param[in] ucDestinationAddress Destination address
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Value command is realized with the Reader command [0xB2][0x30] ISO14443 Special Host Commands and is applicable only with a selected Transponder.<br>
				/// See Reader&apos;s System Manual for a detailed description of this command.<br>
				int ValueCommand(	unsigned char ucCommand,
									unsigned char ucSourceAddress,
									unsigned int uiValue,
									unsigned char ucDestinationAddress );

				/// @brief Authent Mifare with key from Reader&apos;s EEPROM
				///
				/// @param[in] ucFirstDataBlock First data block address
				/// @param[in] ucKeyType Key type
				/// @param[in] ucKeyAddress Key address
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Authent command is realized with the Reader command [0xB2][0xB0] ISO14443 Special Host Commands and is applicable only with a selected Transponder.<br>
				/// See Reader&apos;s System Manual for a detailed description of this command.<br>
				int Authent(		unsigned char ucFirstDataBlock,
									unsigned char ucKeyType,
									unsigned char ucKeyAddress );

				/// @brief Authent Mifare with key from protocol
				///
				/// @param[in] ucFirstDataBlock First data block address
				/// @param[in] ucKeyType Key type
				/// @param[in] sKey Authentication key
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Authent command is realized with the Reader command [0xB2][0xB0] ISO14443 Special Host Commands and is applicable only with a selected Transponder.<br>
				/// See Reader&apos;s System Manual for a detailed description of this command.<br>
				int Authent(		unsigned char ucFirstDataBlock,
									unsigned char ucKeyType,
									std::string sKey );

			protected:
				// constructor
				TH_ISO14443_3_MIFARE_Classic(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3_MIFARE_Classic* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3_MIFARE_Classic();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_CLASSIC_H_INCLUDED_)
