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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_INFINEON_MY_D_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_INFINEON_MY_D_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_Infineon.h"

class FedmIscTagHandler_ISO15693_Infineon_my_d;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_Infineon_my_d
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type my-d from manufacturer Infineon Technologies AG
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to specific commands of Infineon Technologies AG. Thus, you must refer to the Technical Datasheets to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>Infineon Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_Infineon_my_d : public TH_ISO15693_Infineon
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief [0xB1][0xAB] : This command enables or disables the Advanced Quiet Mode
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>Infineon Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
				int SetAdvancedQuietBit(unsigned char ucAQM);


			//	virtual void Init();					// set all data members to 0


			protected:
				// constructor
				TH_ISO15693_Infineon_my_d(ReaderModule* pReader, FedmIscTagHandler_ISO15693_Infineon_my_d* pThImpl);
				// destructor
				virtual ~TH_ISO15693_Infineon_my_d();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_INFINEON_MY_D_H_INCLUDED_)
