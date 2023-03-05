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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_EM_4034_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_EM_4034_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_EM.h"

class FedmIscTagHandler_ISO15693_EM_4034;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_EM_4034
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type 4034 from manufacturer EM Microelectronic-Marin SA
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to the specific commands of the EM4034. Thus, you must refer to the Technical Datasheet of the EM4034 to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>EM Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_EM_4034 : public TH_ISO15693_EM
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:
	
				/// @brief [0xB1][0xA0] Toggle EAS
				///
				/// @param[in] sPassword Hex-coded password with even number of chars
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This command is realized with the Reader command [0xB1] ISO Custom and Proprietary Commands.<br>
				/// Refer to the Application Note <i>EM Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.<br>
				/// This command is only applicable in non-addressed mode. See [ITagGroup::CreateNonAddressedTagHandler](@ref FEDM::Core::ITagGroup::CreateNonAddressedTagHandler)
				/// on how to create a TagHandler instance for non-addressed communication.<br>
				/// 
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int ToggleEAS(std::string sPassword);

				/// @brief [0xB1][0xE4] Login
				///
				/// @param[in] sPassword Hex-coded password with even number of chars
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This command is realized with the Reader command [0xB1] ISO Custom and Proprietary Commands.<br>
				/// Refer to the Application Note <i>EM Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.<br>
				/// 
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int Login(std::string sPassword);


			protected:
				// constructor
				TH_ISO15693_EM_4034(ReaderModule* pReader, FedmIscTagHandler_ISO15693_EM_4034* pThImpl);
				// destructor
				virtual ~TH_ISO15693_EM_4034();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_EM_4034_H_INCLUDED_)
