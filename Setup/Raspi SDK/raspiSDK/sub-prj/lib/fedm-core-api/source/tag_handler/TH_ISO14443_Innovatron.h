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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_INNOVATRON_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_INNOVATRON_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include <string>
#include "TH_ISO14443.h"

class FedmIscTagHandler_ISO14443_Innovatron;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_Innovatron
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-4 compliant Transponders of type Innovatron (ISO 14443B')
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_Innovatron : public TH_ISO14443
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Return of Card Info read with last TagSelect call
				///
				/// @return card info byte or 0 in case of error
				///
				/// <b>Description</b><br>
				/// See command [0xB0][0x25] Select in Reader&apos;s System Manual.<br>
				unsigned char GetCardInfo();

				/// @brief Return of Verlog value read with last Inventory call
				///
				/// @return Verlog value
				///
				/// <b>Description</b><br>
				/// See command [0xB0][0x01] Inventory in Reader&apos;s System Manual.<br>
				unsigned char GetVerlog();

				/// @brief Return of Config value read with last Inventory call
				///
				/// @return Config value
				///
				/// <b>Description</b><br>
				/// See command [0xB0][0x01] Inventory in Reader&apos;s System Manual.<br>
				unsigned char GetConfig();

				/// @brief Return of ATR value read with last Inventory call
				///
				/// @param[out] pucAtr Pointer to buffer with ATR
				/// @param[in] uiAtrBufferLen Size of ATR buffer (Number of bytes)
				/// @param[out] uiAtrLen Number of bytes in ATR buffer
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// See command [0xB0][0x01] Inventory in Reader&apos;s System Manual.<br>
				int GetAtr(unsigned char* pucAtr, unsigned int uiAtrBufferLen, unsigned int& uiAtrLen);

				/// @brief APDU command
				///
				/// @param[in] pucRequestData Buffer with APDU request
				/// @param[in] iRequestLen Length of APDU (number of bytes)
				/// @param[out] pucResponseData Buffer for APDU response
				/// @param[in] uiResponseBufferLen Length of response bufer
				/// @param[out] uiResponseLen Length of APDU response (number of bytes)
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See command [0xB2][0xBB] ISO 14443-B’ (Innovatron) Data Exchange in Reader&apos;s System Manual.<br>
				int Apdu(	unsigned char*	pucRequestData,
							unsigned int	iRequestLen,
							unsigned char*	pucResponseData,
							unsigned int	uiResponseBufferLen,
							unsigned int&	uiResponseLen	);

				/// @brief Discard command
				///
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See command [0xB2][0xBB] ISO 14443-B’ (Innovatron) Data Exchange in Reader&apos;s System Manual.<br>
				int Discard();

			protected:
				// constructor
				TH_ISO14443_Innovatron(ReaderModule* pReader, FedmIscTagHandler_ISO14443_Innovatron* pThImpl);
				// destructor
				virtual ~TH_ISO14443_Innovatron();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_INNOVATRON_H_INCLUDED_)
