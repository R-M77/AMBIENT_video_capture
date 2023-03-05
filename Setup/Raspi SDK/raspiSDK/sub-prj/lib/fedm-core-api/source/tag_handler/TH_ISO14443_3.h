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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_2.h"

class FedmIscTagHandler_ISO14443_3;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing commands for all ISO 14443-3 compliant Transponders
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3 : public TH_ISO14443_2
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Return of Protocol Info, read with last Inventory call
				///
				/// @param[out] ucMaxFrameSize Maximal Frame Size according ISO 14443-3-2001
				/// @param[out] ucProtocolType Protocol Type according ISO 14443-3-2001
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the method parameters
				int GetProtocolInfo(unsigned char& ucMaxFrameSize,
									unsigned char& ucProtocolType );

				/// @brief Return of Card Info, read with last TagSelect call
				///
				/// @param[out] ucCardInfoFormat Reference to Format
				/// @param[out] pucCardInfo Pointer to array for Card Info
				/// @param[in]  uiCardInfoBufferSize size of pucCardInfo
				/// @return 
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 number of bytes in Card Info
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				int GetCardInfo(	unsigned char& ucCardInfoFormat,
									unsigned char* pucCardInfo,
									unsigned int   uiCardInfoBufferSize );

				/// @brief [0xB2][0xC0] : Halt command (only for selected Transponder)
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int Halt();

			protected:
				// constructor
				TH_ISO14443_3(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_H_INCLUDED_)
