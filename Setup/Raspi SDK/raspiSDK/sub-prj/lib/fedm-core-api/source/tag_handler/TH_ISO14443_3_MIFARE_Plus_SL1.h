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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_PLUS_SL1_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_PLUS_SL1_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3_MIFARE_Plus.h"

class FedmIscTagHandler_ISO14443_3_MIFARE_Plus_SL1;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3_MIFARE_Plus_SL1
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-3 compliant Transponders of type MIFARE Plus in Security Level 1 from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// This class implements the communication with [0xC2] Reader commands.<br>
			/// Detailed description about the command interface can be found in:
			/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
			/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3_MIFARE_Plus_SL1 : public TH_ISO14443_3_MIFARE_Plus
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief MIFARE Plus Command [0x77], realized with Reader command [0xC2][0x77] MFP_SL1_AESAuthent
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is a Security Level 1 command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int AESAuthent(	unsigned char ucReaderKeyIndex );


			protected:
				// constructor
				TH_ISO14443_3_MIFARE_Plus_SL1(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3_MIFARE_Plus_SL1* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3_MIFARE_Plus_SL1();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_MIFARE_PLUS_SL1_H_INCLUDED_)
