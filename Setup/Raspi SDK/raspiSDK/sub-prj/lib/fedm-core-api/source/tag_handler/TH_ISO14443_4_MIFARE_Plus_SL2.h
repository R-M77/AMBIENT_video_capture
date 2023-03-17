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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_SL2_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_SL2_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include <string>
#include "TH_ISO14443_4_MIFARE_Plus.h"

class FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL2;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_4_MIFARE_Plus_SL2
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-4 compliant Transponders of type MIFARE Plus in Security Level 2 from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// This class implements the communication with [0xC2] Reader commands.<br>
			/// Detailed description about the command interface can be found in:
			/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
			/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_4_MIFARE_Plus_SL2 : public TH_ISO14443_4_MIFARE_Plus
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				// Security Level 3 commands

				// [0xC2][0xA1] SL3 Write Encrypted Maced


			protected:
				// constructor
				TH_ISO14443_4_MIFARE_Plus_SL2(ReaderModule* pReader, FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL2* pThImpl);
				// destructor
				virtual ~TH_ISO14443_4_MIFARE_Plus_SL2();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_SL2_H_INCLUDED_)