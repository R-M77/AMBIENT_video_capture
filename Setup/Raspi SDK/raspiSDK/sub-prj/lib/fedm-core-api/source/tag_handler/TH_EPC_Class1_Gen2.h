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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_EPC_CLASS1_GEN2_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_EPC_CLASS1_GEN2_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_EPC_C1_G2)

#include <string>
#include "TH_Base.h"

class FedmIscTagHandler_EPC_Class1_Gen2;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_EPC_Class1_Gen2
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing basic commands for all EPC Class 1 Generation 2 compliant Transponders
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the EPC Class 1 Gen 2 standard (<A HREF="http://www.gs1.org/epcglobal">http://www.gs1.org/epcglobal</A>)
			class _FEDM_ISC_CORE_EXT_CLASS TH_EPC_Class1_Gen2 : public TH_Base
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

			//	virtual void Init();					// set all data members to 0

				/// @brief Method to query if the IDD is a combination of EPC and TID
				///
				/// @return true, if Identifier Data (IDD) is EPC + TID
				///
				/// <b>Description</b><br>
				/// 
				bool IsIDDWithTid();

				/// @brief Method to query if the Protocol-Control (PC) is extended
				///
				/// @return true, if PC is extended, otherwise false
				///
				/// <b>Description</b><br>
				/// Method to query if the Protocol-Control (PC) is extended with 1 additional block of 2 bytes.
				bool IsExtendedPC_W1();

				/// @brief Method to query the Protocol-Control (PC)
				///
				/// @return Protocol Control
				///
				/// <b>Description</b><br>
				/// 
				unsigned int GetProtocolControl();

				/// @brief Method to query the Extended Protocol-Control (XPC_W1)
				///
				/// @return Extended Protocol Control XPC_W1
				///
				/// <b>Description</b><br>
				/// 
				unsigned int GetExtendedProtocolControlW1();

				/// @brief Returns the EPC from the IDD
				///
				/// @return String with EPC
				///
				/// <b>Description</b><br>
				/// The EPC is extracted from the IDD and returned.
				const char* GetEpcOfIDD();

				/// @brief Returns the TID from the IDD
				///
				/// @return String with TID
				///
				/// <b>Description</b><br>
				/// The TID is extracted from the IDD and returned.
				const char* GetTidOfIDD();
					
				/// @brief Method to query the Tag Model Number
				///
				/// @return Tag Model Number
				///
				/// <b>Description</b><br>
				/// The Tag Model Number is part of the TID and can only be returned, if the TID is part of the IDD or if the first 2 blocks of the TID memory is read separately.<br>
				/// The EPC Class 1 Gen 2 standard reserves the bits 14h .. 1Fh of the TID memory as a vendor-defined 12-bit Tag Model Number.
				unsigned int GetTagModelNumber();

				/// @brief Method to query the Mask Designer Identifier
				///
				/// @return Mask Designer Identifier
				///
				/// <b>Description</b><br>
				/// The Mask Designer Identifier is part of the TID and can only be returned, if the TID is part of the IDD or if the first 2 blocks of the TID memory is read separately.<br>
				/// The EPC Class 1 Gen 2 standard reserves the bits 08h .. 13h of the TID memory as a 12-bit Mask Designer Identifier (obtainable from the registration authority).
				unsigned int GetMaskDesignerID();

				/// @brief Method to query the Manufacturer Name
				///
				/// @return String with Manufacturer Name
				///
				/// <b>Description</b><br>
				/// The Manufacturer Name is specified by the Mask Designer Identifier, which is part of the TID.<br>
				/// The Manufacturer name can only be returned, if the TID is part of the IDD or if the first 2 blocks of the TID memory is read separately.<br>
				/// The EPC Class 1 Gen 2 standard reserves the bits 08h .. 13h of the TID memory as a 12-bit Mask Designer Identifier (obtainable from the registration authority).
				const char* GetMaskDesignerName();

				/// @brief Read the complete content of a bank
				///
				/// @param[in] uiBank Bank number. Use [BANK_RESERVED](@ref BANK_RESERVED), [BANK_EPC](@ref BANK_EPC), [BANK_TID](@ref BANK_TID) or [BANK_USER](@ref BANK_USER)
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[out] pucData Pointer to array for received data blocks
				/// @param[in] uiDataBufferSize Size of the array for received data blocks
				/// @param[out] uiNoOfDataBlocksRead Return of the number of data blocks read
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// [0xB0][0x23] Read Multiple Blocks command with READ_COMPLETE_BANK option<br>
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int ReadCompleteBank(		unsigned int uiBank,
											std::string sPassword,
											unsigned char* pucData,
											unsigned int uiDataBufferSize,
											unsigned int& uiNoOfDataBlocksRead );

				/// @brief [0xB0][0x23] Read Multiple Blocks command
				///
				/// @param[in] uiBank Bank number. Use [BANK_RESERVED](@ref BANK_RESERVED), [BANK_EPC](@ref BANK_EPC), [BANK_TID](@ref BANK_TID) or [BANK_USER](@ref BANK_USER)
				/// @param[in] uiFirstDataBlock First data block address
				/// @param[in] uiNoOfDataBlocks Number of requested data blocks
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[out] pucData Pointer to array for received data blocks
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// [0xB0][0x23] Read Multiple Blocks command<br>
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int ReadMultipleBlocks(		unsigned int uiBank,
											unsigned int uiFirstDataBlock,
											unsigned int uiNoOfDataBlocks,
											std::string sPassword,
											unsigned char* pucData );

				/// @brief [0xB0][0x24] Write Multiple Blocks command
				///
				/// @param[in] uiBank Bank number. Use [BANK_RESERVED](@ref BANK_RESERVED), [BANK_EPC](@ref BANK_EPC), [BANK_TID](@ref BANK_TID) or [BANK_USER](@ref BANK_USER)
				/// @param[in] uiFirstDataBlock First data block address
				/// @param[in] uiNoOfDataBlocks Number of data blocks to transmit to
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] pucData Pointer to array with data blocks to transmit to
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Basic [0xB0][0x24] Write Multiple Blocks command<br>
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int WriteMultipleBlocks(	unsigned int uiBank,
											unsigned int uiFirstDataBlock,
											unsigned int uiNoOfDataBlocks,
											std::string sPassword,
											unsigned char* pucData );

				/// @brief Write of an EPC into the EPC Memory
				///
				/// @param[in] sNewEPC Hex-coded string with the new EPC with even number of chars
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password (preset: disabled).
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Special [0xB0][0x24] Write Multiple Blocks command to write a new EPC number to the EPC bank of a transponder<br>
				/// The EPC-lenght must be multiple of 2 bytes. Thus, the EPC string must contain multiple of 4 characters.
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int WriteEPC(	std::string sNewEPC, std::string sPassword="");
	
				/// @brief Select command
				///
				/// @param[in] uiTarget Indicates the modified flag: values 0..3 = Inventoried (S0..3), value 4 = SL
				/// @param[in] uiAction Defines the behavior of matching and not matching tags. See documentation for details.
				/// @param[in] uiBank Memory bank specifies how a tag applies mask
				/// @param[in] uiMaskBitPointer Specifies the starting bit address of the mask
				/// @param[in] uiMaskBitLen Specifies the bit lenght of the mask. The bit lenght must not exceed 255!
				/// @param[in] vucMask The mask. The length of the vector must be (uiMaskBitLen+7)/8!
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Basic [0xB3][0x0A] Select a tag subpopulation. See EPC Class 1 Gen 2 standard for detailed information.<br>
				int Select(	unsigned int uiTarget,
							unsigned int uiAction,
							unsigned int uiBank,
							unsigned int uiMaskBitPointer,
							unsigned int uiMaskBitLen,
							const std::vector<unsigned char> & vucMask );
					
				/// @brief Kill command
				///
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] bRecom_AssertedLSB Recommissioning Bit Asserted LSB (preset: disabled)
				/// @param[in] bRecom_Asserted2SB Recommissioning Bit Asserted 2LSB (preset: disabled)
				/// @param[in] bRecom_Asserted3SB Recommissioning Bit Asserted 3LSB (preset: disabled)
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// The kill command can destroy the Transponder. See EPC Class 1 Gen 2 standard for detailed information, especially how to handle the Kill command with Recommissioning Bits.
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int Kill(		std::string sPassword,
								bool bRecom_AssertedLSB=false,
								bool bRecom_Asserted2SB=false,
								bool bRecom_Asserted3SB=false );

				/// @brief Lock command (simplified version)
				///
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] ucLockKill lock settings for kill
				/// @param[in] ucLockAccess lock settings for access pasword
				/// @param[in] ucLockEPC lock settings for  EPC memory
				/// @param[in] ucLockTID lock settings for TID memory
				/// @param[in] ucLockUser lock settings for User memory
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// [0xB3][0x22] Lock command to secure the access to a transponder.<br>
				/// The Lock command can lock permanently one bank or multiple banks of the Transponder. See EPC Class 1 Gen 2 standard for detailed information.<br>
				/// <br>
				/// Use one of the constants for each lock setting:<br>
				/// - [UNCHANGED](@ref UNCHANGED)<br>
				/// - [UNLOCK](@ref UNLOCK)<br>
				/// - [UNLOCK_PERMANENTLY](@ref UNLOCK_PERMANENTLY)<br>
				/// - [LOCK](@ref LOCK)<br>
				/// - [LOCK_PERMANENTLY](@ref LOCK_PERMANENTLY)<br>
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int Lock(		std::string sPassword,
								unsigned char ucLockKill,
								unsigned char ucLockAccess,
								unsigned char ucLockEPC,
								unsigned char ucLockTID,
								unsigned char ucLockUser );

				/// @brief Lock command (parameters according EPC Class 1 Gen 2 specification)
				///
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] ucKillMask		2 Bit mask settings for kill
				/// @param[in] ucKillAction		2 Bit action settings for kill
				/// @param[in] ucAccessMask		2 Bit mask settings for access pasword
				/// @param[in] ucAccessAction	2 Bit action settings for access pasword
				/// @param[in] ucEPCMask		2 Bit mask settings for  EPC memory
				/// @param[in] ucEPCAction		2 Bit action settings for  EPC memory
				/// @param[in] ucTIDMask		2 Bit mask settings for TID memory
				/// @param[in] ucTIDAction		2 Bit action settings for TID memory
				/// @param[in] ucUserMask		2 Bit mask settings for User memory
				/// @param[in] ucUserAction		2 Bit action settings for User memory
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// [0xB3][0x22] Lock command to secure the access to a transponder.<br>
				/// The Lock command can lock permanently one bank or multiple banks of the Transponder. See EPC Class 1 Gen 2 standard for detailed information.<br>
				/// <br>
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int Lock(		std::string sPassword,
								unsigned char ucKillMask,
								unsigned char ucKillAction,
								unsigned char ucAccessMask,
								unsigned char ucAccessAction,
								unsigned char ucEPCMask,
								unsigned char ucEPCAction,
								unsigned char ucTIDMask,
								unsigned char ucTIDAction,
								unsigned char ucUserMask,
								unsigned char ucUserAction );

				/// @brief [0xB3][0x25] Block Permalock command
				///
				/// @param[in] uiBank Bank number. Use [BANK_RESERVED](@ref BANK_RESERVED), [BANK_EPC](@ref BANK_EPC), [BANK_TID](@ref BANK_TID) or [BANK_USER](@ref BANK_USER)
				/// @param[in] uiBlockPointer first block (consider: vendor specific block size)
				/// @param[in] uiBlockRange number of blocks (limited to 4)
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] pucMask Pointer to array with mask data to transmit to
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This is an optional command and must not be supported by the Transponder.<br>
				/// See EPC Class 1 Gen 2 standard for detailed information.
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int BlockPermalock(			unsigned int uiBank,
											unsigned int uiBlockPointer,
											unsigned int uiBlockRange,
											std::string sPassword,
											unsigned char* pucMask );

				/// @brief [0xB3][0x25] Block Permalock command
				///
				/// @param[in] uiBank Bank number. Use [BANK_RESERVED](@ref BANK_RESERVED), [BANK_EPC](@ref BANK_EPC), [BANK_TID](@ref BANK_TID) or [BANK_USER](@ref BANK_USER)
				/// @param[in] uiBlockPointer first block (consider: vendor specific block size)
				/// @param[in] uiBlockRange number of blocks (limited to 4)
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[out] pucMask Pointer to array for received mask data
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This is an optional command and must not be supported by the Transponder.<br>
				/// See EPC Class 1 Gen 2 standard for detailed information.
				///
				/// @note Hex-coded string means, that a hex value of 0xAB39F1D9 must be set as "AB39F1D9".
				int ReadPermalockStatus(	unsigned int uiBank,
											unsigned int uiBlockPointer,
											unsigned int uiBlockRange,
											std::string sPassword,
											unsigned char* pucMask );

				/// @brief [0xB3][0x30] Untraceable
				///
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password (preset: disabled).
				/// @param[in] ucUFlag : reserved, should be 0x00
				/// @param[in] usHide  : specifies, what to hide (see manual)
				/// @param[in] ucRange : specifies an operating range
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This command hides parts of the tag’s TID, EPC and/or user memory.
				int Untraceable(	const std::string & sPassword,
									unsigned char ucUFlag,
									unsigned short usHide,
									unsigned char ucRange);

				/// @brief [0xB3][0x31] Authenticate
				///
				/// @param[in] sPassword  Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] ucAuthMode Defines the format of the request and the response (see manual).
				/// @param[in] ucCSI      Crypto Suite Identifier
				/// @param[in] ucCryptoTime
				/// @param[in] uiRspLen
				/// @param[in] vMsg       Message defined by the specified crypto suite (see manual).
				/// @param[out] vRsp      Vector of the response data.
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This command performs tag, reader, or mutual authentication.
				int Authenticate(	const std::string & sPassword,
									unsigned char ucAuthMode,
									unsigned char ucCSI,
									unsigned char ucCryptoTime,
									unsigned int  uiRspLen,
									const std::vector<unsigned char> & vMsg,
									std::vector<unsigned char> & vRsp);
	
				/// @brief [0xB3][0x32] Challenge
				///
				/// @param[in] ucAuthMode Defines the format of the request and the response (see manual).
				/// @param[in] ucCSI      Crypto Suite Identifier
				/// @param[in] ucCryptoTime
				/// @param[in] uiRspLen
				/// @param[in] vMsg       Message defined by the specified crypto suite (see manual).
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This command allows an interrogator to instruct multiple tags to simultaneously yet independently precompute and store a cryptographic value.
				/// No response is send from tag on a challenge command.
				int Challenge(	unsigned char ucAuthMode,
								unsigned char ucCSI,
								unsigned char ucCryptoTime,
								unsigned int  uiRspLen,
								const std::vector<unsigned char> & vMsg);

				/// @brief Read Buffer
				///
				/// @param[in] sPassword Optional hex-coded password with even number of chars. Set to "" (empty string) disables password.
				/// @param[in] uiStartAddr
				/// @param[in] uiNumOfBits If 0, the entire buffer will be read
				/// @param[out] vData The content of the tag response buffer
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// [0xB3][0x33]ReadBuffer: This command allows to read data stored in a tag response buffer.
				int ReadBuffer(	const std::string & sPassword,
								unsigned int uiStartAddr,
								unsigned int uiNumOfBits,
								std::vector<unsigned char> & vData);




				// Tag Data Standard http://www.epcglobalinc.org/standards/tds/tds_1_4-standard-20080611.pdf
				// GTIN:  GS1 Global Trade Item Number, (here, a serialized version)
				// SSCC:  GS1 Serial Shipping Container Code
				// GLN:  GS1 Global Location Number
				// GRAI:  GS1 Global Returnable Asset Identifier
				// GIAI:  GS1 Global Individual Asset Identifier
				// GID:  GS1 General Identifier
				// GDTI:  GS1 Global Document Type Identifier
				// GSRN:  GS1 Global Service Relation Number

				// constants for Bank

				/// @brief Constant for bank type Reserved Memory
				///
				/// 
				static const unsigned int BANK_RESERVED	= 0;
				/// @brief Constant for bank type EPC Memory
				///
				/// 
				static const unsigned int BANK_EPC		= 1;
				/// @brief Constant for bank type TID Memory
				///
				/// 
				static const unsigned int BANK_TID		= 2;
				/// @brief Constant for bank type User Memory
				///
				/// 
				static const unsigned int BANK_USER		= 3;

				/// @brief Constant for Lock command to keep lock status unchanged
				///
				/// 
				static const unsigned int UNCHANGED				= 0x00;
				/// @brief Constant for Lock command to unlock a bank
				///
				/// 
				static const unsigned int UNLOCK				= 0x20;
				/// @brief Constant for Lock command to unlock a bank permanently
				///
				/// 
				static const unsigned int UNLOCK_PERMANENTLY	= 0x31;
				/// @brief Constant for Lock command to lock a bank
				///
				/// 
				static const unsigned int LOCK					= 0x22;
				/// @brief Constant for Lock command to lock a bank permanently
				///
				/// 
				static const unsigned int LOCK_PERMANENTLY		= 0x33;

			protected:
				// constructor
				TH_EPC_Class1_Gen2(ReaderModule* pReader, FedmIscTagHandler_EPC_Class1_Gen2* pThImpl);
				// destructor
				virtual ~TH_EPC_Class1_Gen2();

			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_EPC_C1_G2)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_ISC_TAG_HANDLER_EPC_CLASS1_GEN2_H_INCLUDED_)
