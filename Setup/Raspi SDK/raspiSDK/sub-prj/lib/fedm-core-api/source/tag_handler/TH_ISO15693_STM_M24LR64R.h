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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LR64R_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LR64R_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_STM.h"

class FedmIscTagHandler_ISO15693_STM_M24LR64R;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_STM_M24LR64R
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type M24LR64-R from manufacturer STMicroelectronics SA
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to specific commands of M24LR64-R. Thus, you must refer to the Technical Datasheet of the M24LR64-R to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_STM_M24LR64R : public TH_ISO15693_STM
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief [0xB1][0xB1] Write Sector Password
				///
				/// @param[in] ucPasswordNumber
				/// @param[in] sPassword
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int WriteSectorPassword(unsigned char ucPasswordNumber, std::string sPassword);

				/// @brief [0xB1][0xB2] Lock Sector Password
				///
				/// @param[in] ucSectorNumber
				/// @param[in] ucSectorSecurityStatus
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int LockSectorPassword(unsigned char ucSectorNumber, unsigned char ucSectorSecurityStatus);	

				/// @brief [0xB1][0xB3] Present Sector Password
				///
				/// @param[in] ucPasswordNumber
				/// @param[in] sPassword
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int PresentSectorPassword(unsigned char ucPasswordNumber, std::string sPassword);

			protected:
				// constructor
				TH_ISO15693_STM_M24LR64R(ReaderModule* pReader, FedmIscTagHandler_ISO15693_STM_M24LR64R* pThImpl);
				// destructor
				virtual ~TH_ISO15693_STM_M24LR64R();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LR64R_H_INCLUDED_)
