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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_INFINEON_MY_D_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_INFINEON_MY_D_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3.h"

class FedmIscTagHandler_ISO14443_3_Infineon_my_d;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3_Infineon_my_d
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-3 compliant Transponders of type my-d from manufacturer Infineon Technologies AG
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3_Infineon_my_d : public TH_ISO14443_3
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Authentication command
				///
				/// @param[in] ucKeyTagAddress Address where the key is stored in the Transponder. The address can have any value between 4 and 31.
				/// @param[in] ucAuthentCounterAddress Address of the Authentication Counter of the Transponder (Default: 0x03).
				/// @param[in] ucAuthentSequence Defines the authentication sequence.<br>
				/// - 0x00: Accelerated card authentication<br>
				/// - 0x01: Entire card authentication<br>
				/// @param[in] ucKeyAddressSAM Address of the key in the security access module (SAM). The address can have any value between 1 and 28.
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Authent my-d command is realized with the Reader command [0xB2][0xB1] ISO14443 Special Host Commands.<br>
				int Authent(	unsigned char ucKeyTagAddress,
								unsigned char ucAuthentCounterAddress,
								unsigned char ucAuthentSequence,
								unsigned char ucKeyAddressSAM );


			protected:
				// constructor
				TH_ISO14443_3_Infineon_my_d(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3_Infineon_my_d* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3_Infineon_my_d();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_INFINEON_MY_D_H_INCLUDED_)
