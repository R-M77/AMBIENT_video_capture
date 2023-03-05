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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_INFINEON_MY_D_MOVE_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_INFINEON_MY_D_MOVE_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#include "TH_ISO14443_3.h"

class FedmIscTagHandler_ISO14443_3_Infineon_my_d_move;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO14443_3_Infineon_my_d_move
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 14443-3 compliant Transponders of type my-d move from manufacturer Infineon Technologies AG
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// Detailed description about the command interface can be found in the Product Datasheet for my-d move from Infineon Technologies AG.<br>
			///
			/// @note Programmers should be familiar with the ISO 14443 standards
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO14443_3_Infineon_my_d_move : public TH_ISO14443_3
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief Read of 4 Blocks (RD4B) command
				///
				/// @param[in] ucAddress Address: 0x00...0x25
				/// @param[out] pucData Pointer to buffer with Transponder data (at least 16 bytes)
				/// @param[in] uiDataBufferLen Size of the Transponder data buffer
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				int Read4Blocks(unsigned char ucAddress, unsigned char* pucData, unsigned int uiDataBufferLen);

				/// @brief Write of 1 block (WR1B) command
				///
				/// @param[in] ucAddress Address: 0x02...0x24
				/// @param[out] pucData Pointer to buffer with Transponder data (4 bytes)
				/// @param[in] uiDataBufferLen Number of bytes in the Transponder data buffer 
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				int Write1Block(unsigned char ucAddress, unsigned char* pucData, unsigned int uiDataBufferLen);

				/// @brief Compatibility Write (CPTWR) command
				///
				/// @param[in] ucAddress
				/// @param[out] pucData Pointer to buffer with Transponder data (4 bytes)
				/// @param[in] uiDataBufferLen Number of bytes in the Transponder data buffer
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				int CompatibilityWriteCmd(unsigned char ucAddress, unsigned char* pucData, unsigned int uiDataBufferLen);

				/// @brief Read of 2 blocks (RD2B) command
				///
				/// @param[in] ucAddress
				/// @param[out] pucData Pointer to buffer with Transponder data
				/// @param[in] uiDataBufferLen Size of the Transponder data buffer (at least 8 bytes)
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				int Read2Blocks(unsigned char ucAddress, unsigned char* pucData, unsigned int uiDataBufferLen);

				/// @brief Write of 2 Blocks (WR2B) command
				///
				/// @param[in] ucAddress 
				/// @param[out] pucData Pointer to buffer with Transponder data (8 bytes)
				/// @param[in] uiDataBufferLen Number of bytes in the Transponder data buffer
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				int Write2Blocks(unsigned char ucAddress, unsigned char* pucData, unsigned int uiDataBufferLen);

				/// @brief Set Password (SPWD) command
				///
				/// @param[in] sPassword Hex-coded password with even number of chars
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int SetPassword(std::string& sPassword);

				/// @brief Access (ACS) command
				///
				/// @param[in] sPassword Hex-coded, 4 byte password
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int Access(std::string sPassword);

				/// @brief Decrement (DCR16) command
				///
				/// @param[in,out] uiCounterValue Value Counter value (LSByte = CNT0, MSByte = CNT1)
				/// @return 
				/// -   0 if OK. uiCounterValue contains the new Value Counter value.
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The Transponder must be selected first with [ITagGroup::Select](@ref FEDM::Core::ITagGroup::Select).<br>
				/// This command is realized with the Reader command [0xBD] ISO14443A Transparent Command.<br>
				/// Detailed description about the command and the parameters can be found in the Product Datasheet for my-d move from Infineon Technologies AG
				int Decrement(unsigned int& uiCounterValue);

			protected:
				// constructor
				TH_ISO14443_3_Infineon_my_d_move(ReaderModule* pReader, FedmIscTagHandler_ISO14443_3_Infineon_my_d_move* pThImpl);
				// destructor
				virtual ~TH_ISO14443_3_Infineon_my_d_move();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO14443_3_INFINEON_MY_D_MOVE_H_INCLUDED_)
