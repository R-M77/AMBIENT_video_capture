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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LRxxER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LRxxER_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_STM_M24LR64R.h"

class FedmIscTagHandler_ISO15693_STM_M24LRxxER;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_STM_M24LRxxER
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type M24LRxxE-R series from manufacturer STMicroelectronics SA
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to specific commands of M24LRxxE-R. Thus, you must refer to the Technical Datasheet of the M24LRxxE-R to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_STM_M24LRxxER : public TH_ISO15693_STM_M24LR64R
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				// methods for energy harvesting mode

				/// @brief [0xB1][0xA0] Read Configuration Byte
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int ReadCfg(unsigned char& ucData);

				/// @brief [0xB1][0xA1] Write Configuration Byte
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int WriteEHCfg(unsigned char ucData);

				/// @brief [0xB1][0xA2] Set/Reset Control Register
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int SetRstEHEn(unsigned char ucData);

				/// @brief [0xB1][0xA3] Read Control Register
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int CheckEHEn(unsigned char& ucData);

				/// @brief [0xB1][0xA4] Set/Reset RF WIP/BUSY bit in Control Register
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int WriteDOCfg(unsigned char ucData);


			protected:
				// constructor
				TH_ISO15693_STM_M24LRxxER(ReaderModule* pReader, FedmIscTagHandler_ISO15693_STM_M24LRxxER* pThImpl);
				// destructor
				virtual ~TH_ISO15693_STM_M24LRxxER();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LRxxER_H_INCLUDED_)
