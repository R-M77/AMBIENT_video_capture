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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_TI_TAG_IT_HFI_PLUS_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_TI_TAG_IT_HFI_PLUS_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_TI.h"

class FedmIscTagHandler_ISO15693_TI_Tag_it_HFI_Plus;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_TI_Tag_it_HFI_Plus
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type Tag-it HFI Plus from manufacturer Texas Instruments
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to specific commands of Tag-it HF-I Plus. Thus, you must refer to the Technical Datasheet of the Tag-it HF-I Plus to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>TI Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_TI_Tag_it_HFI_Plus : public TH_ISO15693_TI
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief [0xB1][0xA2] Write 2 Blocks
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>TI Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int Write2Blocks(unsigned char ucDBAdr, unsigned char ucDBSize, unsigned char* pucEvenDB, unsigned char* pucOddDB);

				/// @brief [0xB1][0xA3] Lock 2 Blocks
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>TI Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int Lock2Blocks(unsigned char ucDBAdr);


			//	virtual void Init();					// set all data members to 0

			protected:
				// constructor
				TH_ISO15693_TI_Tag_it_HFI_Plus(ReaderModule* pReader, FedmIscTagHandler_ISO15693_TI_Tag_it_HFI_Plus* pThImpl);
				// destructor
				virtual ~TH_ISO15693_TI_Tag_it_HFI_Plus();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_TI_TAG_IT_HFI_PLUS_H_INCLUDED_)
