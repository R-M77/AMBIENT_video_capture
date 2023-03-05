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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_4.h"

class FedmIscTagHandler_ISO14443_4_MIFARE_Plus;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_4_MIFARE_Plus
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-4 compliant Transponders of type MIFARE Plus from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// This class implements the communication with [0xC2] Reader commands.<br>
			/// Detailed description about the command interface can be found in:
			/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
			/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_4_MIFARE_Plus : public TH_ISO14443_4
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Initialization method
				///
				/// <b>Description</b><br>
				/// Clears all data members
				virtual void Init();

				/// @brief Method to query the last Error Source
				///
				/// @return Error Source
				///
				/// <b>Description</b><br>
				/// 
				unsigned char	GetErrorSource();

				/// @brief Method to query the last Error Code
				///
				/// @return Error Code
				///
				/// <b>Description</b><br>
				/// 
				unsigned int	GetErrorCode();


				// commands for all security levels

				/// @brief MIFARE Plus Command [0x70], realized with Reader command [0xC2][0x70] First Authentication
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an Authentication command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int FirstAuthent(		unsigned int uiAesKeyBlockNumber,
										unsigned char ucPcdCapLength,
										unsigned char* pucPcdCap2,
										unsigned char ucReaderKeyIndex );

				/// @brief MIFARE Plus Command [0x76], realized with Reader command [0xC2][0x76] Following Authentication
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This method is an Authentication command.<br>
				/// Detailed description about the command and the parameters can be found in:
				/// - Product Datasheet for MIFARE Plus from NXP Semiconductors
				/// - System Manual <i>SoftCrypto Functions</i> from FEIG ELECTRONIC
				int FollowingAuthent(	unsigned int uiAesKeyBlockNumber,
										unsigned char ucReaderKeyIndex );


			protected:
				// constructor not necessary, as this class represents not a real tag type
				TH_ISO14443_4_MIFARE_Plus(ReaderModule* pReader, FedmIscTagHandler_ISO14443_4_MIFARE_Plus* pThImpl);
				// destructor
				virtual ~TH_ISO14443_4_MIFARE_Plus();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_PLUS_H_INCLUDED_)
