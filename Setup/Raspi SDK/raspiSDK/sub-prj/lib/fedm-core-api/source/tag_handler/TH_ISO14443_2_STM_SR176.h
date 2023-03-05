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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_2_STM_SR176_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_2_STM_SR176_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_2.h"

class FedmIscTagHandler_ISO14443_2_STM_SR176;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_2_STM_SR176
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-2 compliant Transponders of type SR176 from manufacturer STMicroelectronics SA
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_2_STM_SR176 : public TH_ISO14443_2
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

			protected:
				// constructor
				TH_ISO14443_2_STM_SR176(ReaderModule* pReader, FedmIscTagHandler_ISO14443_2_STM_SR176* pThImpl);
				// destructor
				virtual ~TH_ISO14443_2_STM_SR176();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_2_STM_SR176_H_INCLUDED_)
