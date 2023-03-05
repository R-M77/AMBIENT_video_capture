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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_ASK_CTX_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_ASK_CTX_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3.h"

class FedmIscTagHandler_ISO14443_3_ASK_CTx;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3_ASK_CTx
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-3 compliant CTx Transponder of type CTx series from manufacturer ASK
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// See Reader&apos;s System Manual for detailed information about the command and parameters.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3_ASK_CTx : public TH_ISO14443_3
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Method to query the Product Code
				///
				/// @return Product Code
				///
				/// <b>Description</b><br>
				/// The Product Code is part of the Inventory response.
				unsigned char GetProductCode();

				/// @brief Method to query the Fab Code
				///
				/// @return Fab Code
				///
				/// <b>Description</b><br>
				/// The Fab Code is part of the Inventory response.
				unsigned char GetFabCode();

				/// @brief Method to query the App Code
				///
				/// @return App Code
				///
				/// <b>Description</b><br>
				/// The App Code is part of the Inventory response.
				unsigned char GetAppCode();

				/// @brief Method to query the Embedder Code
				///
				/// @return Embedder Code
				///
				/// <b>Description</b><br>
				/// The Embedder Code is part of the Inventory response.
				unsigned char GetEmbedderCode();


			protected:
				// constructor
				TH_ISO14443_3_ASK_CTx(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3_ASK_CTx* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3_ASK_CTx();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_ASK_CTX_H_INCLUDED_)
