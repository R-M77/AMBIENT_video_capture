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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_ULTRALIGHT_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_ULTRALIGHT_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3.h"

class FedmIscTagHandler_ISO14443_3_MIFARE_Ultralight;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3_MIFARE_Ultralight
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-3 compliant Transponders of type MIFARE Ultralight from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3_MIFARE_Ultralight : public TH_ISO14443_3
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Authent Mifare Ultralight C with key from Reader, realized with Reader command [0xB2] ISO14443 Special Host Commands
				///
				/// @param ucReaderKeyIndex Reader key index
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is only applicable, if the Transponder is in selected mode.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Ultralight C from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int Authent(unsigned char ucReaderKeyIndex);

				/// @brief Get Product Info from Mifare Ultralight EV1, realized with Reader command [0xB5] ISO14443 Custom and Proprietary Commands 
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is only applicable, if the Transponder is in selected mode.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Ultralight EV1 from NXP Semiconductors
				int GetVersion(unsigned char* pucResponseData);

			protected:
				// constructor
				TH_ISO14443_3_MIFARE_Ultralight(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3_MIFARE_Ultralight* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3_MIFARE_Ultralight();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_ULTRALIGHT_H_INCLUDED_)
