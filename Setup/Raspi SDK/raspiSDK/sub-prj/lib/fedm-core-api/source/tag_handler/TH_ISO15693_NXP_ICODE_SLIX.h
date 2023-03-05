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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_NXP_ICODE_SLIX_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_NXP_ICODE_SLIX_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_NXP_ICODE_SLI.h"

class FedmIscTagHandler_ISO15693_NXP_ICODE_SLIX;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_NXP_ICODE_SLIX
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type I-CODE SLI from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to specific commands of I-CODE SLIX. Thus, you must refer to the Technical Datasheet of the I-CODE SLIX to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_NXP_ICODE_SLIX : public TH_ISO15693_NXP_ICODE_SLI
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				//[0xB1][0xA0] - implemented in reader class

				//[0xB1][0xA1] - implemented in reader class

				/// @brief [0xB1][0xA6]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int PasswordProtectEAS();

				/// @brief [0xB1][0xA6]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int PasswordProtectAFI();

				/// @brief [0xB1][0xB2]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int GetRandomNumber(unsigned char* ucRandomNo, unsigned int uiRandomNoBufferLen);

				/// @brief [0xB1][0xB3]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int SetPassword(unsigned char ucPasswordIdentifier, std::string sPassoword);

				/// @brief [0xB1][0xB4]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int WritePassword(unsigned char ucPasswordIdentifier, std::string sPassword);

				/// @brief [0xB1][0xB5]
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int LockPassword(unsigned char ucPasswordIdentifier);

			protected:
				// constructor
				TH_ISO15693_NXP_ICODE_SLIX(ReaderModule* pReader, FedmIscTagHandler_ISO15693_NXP_ICODE_SLIX* pThImpl);
				// destructor
				virtual ~TH_ISO15693_NXP_ICODE_SLIX();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_NXP_ICODE_SLIX_H_INCLUDED_)
