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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO18000_3M3_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO18000_3M3_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO18000_3M3)

#include "TH_EPC_Class1_Gen2.h"

class FedmIscTagHandler_EPC_Class1_Gen2;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO18000_3M3
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing basic commands for all ISO 18000-3M3 compliant Transponders
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the EPC Class 1 Gen 2 standard (<A HREF="http://www.gs1.org/epcglobal">http://www.gs1.org/epcglobal</A>)
			/// as ISO 18000-3M3 is based on this standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO18000_3M3 : public TH_EPC_Class1_Gen2
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

			protected:
				// constructor
				TH_ISO18000_3M3(ReaderModule* pReader, FedmIscTagHandler_EPC_Class1_Gen2* pThImpl);
				// destructor
				virtual ~TH_ISO18000_3M3();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO18000_3M3)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO18000_3M3_H_INCLUDED_)
