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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3.h"

class FedmIscTagHandler_ISO14443_4;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_4
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing commands for all ISO 14443-4 compliant Transponders
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 and ISO/IEC 7816 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_4 : public TH_ISO14443_3
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Initialization method
				///
				/// <b>Description</b><br>
				/// Clears all data members
				virtual void Init();

				/// @brief Set CID for next use, if enabled
				///
				/// <b>Description</b><br>
				///
				void SetCID(unsigned char ucCID);

				/// @brief Enable CID usage
				///
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				int EnableCID(bool bEnable);

				/// @brief Get CID, actually in use
				///
				/// @return CID
				///
				/// <b>Description</b><br>
				unsigned char GetCID();

				/// @brief Query, if CID usage is enabled
				///
				/// @return true, if CID is enabled
				///
				/// <b>Description</b><br>
				bool IsCIDEnabled();

				/// @brief Set NAD for next use, if enabled
				///
				/// <b>Description</b><br>
				///
				void SetNAD(unsigned char ucNAD);

				/// @brief Enable NAD usage
				///
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				int EnableNAD(bool bEnable);

				/// @brief Get NAD, actually in use
				///
				/// @return NAD
				///
				/// <b>Description</b><br>
				unsigned char GetNAD();

				/// @brief Query, if NAD usage is enabled
				///
				/// @return true, if NAD is enabled
				///
				/// <b>Description</b><br>
				bool IsNADEnabled();

	
				/// @brief [0xB2][0xBE] : T=CL %APDU for synchronous call
				///
				/// @param[in] pucRequestData Pointer to array with request %APDU
				/// @param[in] iRequestLen Length (number of bytes) of request %APDU
				/// @param[out] pucResponseData Pointer to array for responded %APDU
				/// @param[in] uiResponseBufferLen Buffer size for responded %APDU
				/// @param[out] uiResponseLen Length (number of bytes) of responded %APDU
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters<br>
				/// The structure of an APDU is defined by ISO/IEC 7816-4.<br>
				///
				/// @note An %APDU exchange can be a long term function call. The necessary timeout for the communication port is adapted internally and set to the previous value 
				/// when the method returns. If an application cannot wait such a long time, use the overloaded APDU(unsigned char*,unsigned int,void*,void (*)(void*,int,int,int)) 
				/// method for asynchronous execution.
				int Apdu(				unsigned char*	pucRequestData,
										unsigned int	iRequestLen,
										unsigned char*	pucResponseData,
										unsigned int	uiResponseBufferLen,
										unsigned int&	uiResponseLen	);

				/// @brief [0xB2][0xBE] : T=CL Ping command
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int Ping();

				/// @brief [0xB2][0xBE] : T=CL Deselect command
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int Deselect();

				/// @brief [0xB2][0x2B] : Get Transponder Info command
				///
				/// @param[out] ucFSCI
				/// @param[out] ucFWI
				/// @param[out] ucDSI
				/// @param[out] ucDRI
				/// @param[out] ucNADSupport
				/// @param[out] ucCIDSupport
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters.<br>
				int GetTransponderInfo(	unsigned char& ucFSCI,
										unsigned char& ucFWI,
										unsigned char& ucDSI,
										unsigned char& ucDRI,
										unsigned char& ucNADSupport,
										unsigned char& ucCIDSupport );

				/// @brief Return of additional, Transponder specific error code
				///
				/// @return Error code
				///
				/// <b>Description</b><br>
				unsigned char GetLastISOErrorCode();

				/// @brief Returns the responded %APDU
				///
				/// @param[out] pucResponseData Pointer to array for responded %APDU
				/// @param[in] uiResponseBufferLen Buffer size for responded %APDU
				/// @param[out] uiResponseLen Length (number of bytes) of responded %APDU
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// The structure of an APDU is defined by ISO/IEC 7816-4.<br>
				int GetResponseData(	unsigned char*	pucResponseData,
										unsigned int	uiResponseBufferLen,
										unsigned int&	uiResponseLen );


			protected:
				// constructor
				TH_ISO14443_4(ReaderModule* pReader, FedmIscTagHandler_ISO14443_4* pThImpl);
				// destructor
				virtual ~TH_ISO14443_4();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_4_H_INCLUDED_)
