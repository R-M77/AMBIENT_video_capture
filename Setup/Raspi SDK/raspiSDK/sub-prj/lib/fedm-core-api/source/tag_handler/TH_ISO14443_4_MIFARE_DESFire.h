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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_DESFIRE_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_DESFIRE_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_4.h"
#include "TH_ISO14443_4_MIFARE_DESFire_SoftCrypto.h"
#include "TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto.h"
#include "TH_ISO14443_4_MIFARE_DESFire_SamCrypto.h"

class FedmIscTagHandler_ISO14443_4_MIFARE_DESFire;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_4_MIFARE_DESFire
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-4 compliant Transponders of type MIFARE DESFire from manufacturer NXP Semiconductors
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// The support for MIFARE DESFire is limited to some IDENTIFICATION Readers and realized with three different implementations:<br>
			/// - Soft-Crypto, using [0xC1] High integrated commands for DESFire Communication
			/// - Flexible Soft-Crypto, using [0xC3] Flexible commands for DESFire Communication
			/// - SAM-Crypto, using [0xC3] Flexible commands for DESFire Communication with SAM
			/// 
			/// For more information about the pros and cons of the different commands get in contact with FEIG ELECTRONIC.<br>
			/// Additionally, you have to order the Product Datasheet from NXP Semiconductors to become familiar with the features of the DESFire.<br>
			/// <br>
			/// The method interface of this class is very wide and complex. Due to the three different DESFire APIs in the Reader, this class maps this APIs with three different nested classes, 
			/// each implementing the specialized method interface:
			/// - [ISoftCrypto](@ref ISoftCrypto) for Soft-Crypto commands
			/// - [IFlexSoftCrypto](@ref IFlexSoftCrypto) for Flexible Soft-Crypto commands
			/// - [ISamCrypto](@ref ISamCrypto) for SAM-Crypto commands
			///
			/// @note Programmers should also be familiar with the ISO 14443 and ISO/IEC 7816 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_4_MIFARE_DESFire : public TH_ISO14443_4
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Initialization method
				///
				/// <b>Description</b><br>
				/// Clears all data members
				virtual void Init();

			public:
				/// @brief Constant for Authentication
				///
				///
				static const unsigned int PLAIN_COMMUNICATION;
				/// @brief Constant for Authentication
				///
				///
				static const unsigned int PLAIN_SECURED_BY_MAC;
				/// @brief Constant for Authentication
				///
				///
				static const unsigned int FULLY_ENCIPHERED;

				/// @brief Nested interface implementing the Soft-Crypto commands
				///
				/// <b>Description</b><br>
				/// See TH_ISO14443_4_MIFARE_DESFire_SoftCrypto for detailed information about the method interface.
				TH_ISO14443_4_MIFARE_DESFire_SoftCrypto		ISoftCrypto;
	
				/// @brief Nested interface implementing the Flexible Soft-Crypto commands
				///
				/// <b>Description</b><br>
				/// See TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto for detailed information about the method interface.
				TH_ISO14443_4_MIFARE_DESFire_FlexSoftCrypto	IFlexSoftCrypto;
	
				/// @brief Nested interface implementing the SAM-Crypto commands
				///
				/// <b>Description</b><br>
				/// See TH_ISO14443_4_MIFARE_DESFire_SamCrypto for detailed information about the method interface.
				TH_ISO14443_4_MIFARE_DESFire_SamCrypto		ISamCrypto;

			protected:
				// constructor
				TH_ISO14443_4_MIFARE_DESFire(ReaderModule* pReader, FedmIscTagHandler_ISO14443_4_MIFARE_DESFire* pThImpl);
				// destructor
				virtual ~TH_ISO14443_4_MIFARE_DESFire();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_MIFARE_DESFIRE_H_INCLUDED_)
