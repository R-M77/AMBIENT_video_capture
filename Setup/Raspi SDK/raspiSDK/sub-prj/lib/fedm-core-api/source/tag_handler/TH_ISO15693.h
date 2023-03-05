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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include <string>
#include "TH_Base.h"

class FedmIscTagHandler_ISO15693;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing basic commands for all ISO 15693 compliant Transponders
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693 : public TH_Base
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief class with system information
				///
				/// <b>Description</b><br>
				/// class for returned system information according ISO 15693.<br>
				class _FEDM_ISC_CORE_EXT_CLASS SystemInfo
				{
					friend class FEDM::Core::TagHandler::TH_ISO15693;

				public:
					/// @brief Returns true, if DSFID value is valid
					bool IsValidDSFID(void) const { return (uiInfoFlags & 0x01) ? true : false; }

					/// @brief Returns true, if AFI value is valid
					bool IsValidAFI(void) const { return (uiInfoFlags & 0x02) ? true : false; }

					/// @brief Returns true, if block size value is valid (part of VICC memory size)
					bool IsValidBlockSize(void) const { return (uiInfoFlags & 0x04) ? true : false; }

					/// @brief Returns true, if block count value is valid (part of VICC memory size)
					bool IsValidBlockCount(void) const { return (uiInfoFlags & 0x04) ? true : false; }

					/// @brief Returns true, if IC reference value is valid
					bool IsValidICReference(void) const { return (uiInfoFlags & 0x08) ? true : false; }

					/// @brief Returns true, if command list is valid
					bool IsValidCommandList(void) const { return (uiInfoFlags & 0x20) ? true : false; }

					/// @brief Returns true, if crypto suite IDsare valid
					bool IsValidCryptoSuiteIDs(void) const { return (uiInfoFlags & 0x40) ? true : false; }

					/// @brief Data Storage Format Identifier of the Transponder
					///
					unsigned char ucDSFID;

					/// @brief IDD of tag
					std::string sIDD;

					/// @brief Application Family Identifier
					unsigned char ucAFI;

					/// @brief block size (part of VICC memory size information)
					unsigned int uiBlockSize;

					/// @brief block count (part of VICC memory size information)
					unsigned int uiBlockCount;

					/// @brief IC reference defined by the IC manufacturer
					unsigned char ucICReference;

					/// @brief list with supported commands. Byte 1 is index 0, byte 2 is index 1 and so forth.
					std::vector<unsigned char> CommandList;

					/// @brief list with supported crypto suite IDs
					std::vector<unsigned char> CryptoSuiteIDs;


					/// @brief constructor
					SystemInfo();

					~SystemInfo() {}

					/// @brief copy constructor
					SystemInfo &operator=  (const SystemInfo & other);
				
					void Clear();
					unsigned int uiInfoFlags;
				};

				/// @brief Initialization method
				///
				/// <b>Description</b><br>
				/// Clears all data members
				virtual void Init();

				/// @brief Method to query the Manufacturer Name
				///
				/// @return String with Manufacturer Name
				///
				/// <b>Description</b><br>
				/// The Manufacturer Name is specified with Manufcturer Code, which is located in byte 1 of the Identifier Data (IDD), resp. UID, resp. SNR of Transponder
				std::string GetManufacturerName();

				/// @brief [0xB0][0x02] Stay Quiet command
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int StayQuiet();

				/// @brief Basic [0xB0][0x22] Lock Multiple Blocks command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..255]
				/// @param[in] uiNoOfDataBlocks Number of data blocks to be locked to [0..255]
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				virtual int LockMultipleBlocks(		unsigned int uiFirstDataBlock,
													unsigned int uiNoOfDataBlocks);

				/// @brief Extended [0xB0][0x22] Lock Multiple Blocks command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..65535]
				/// @param[in] uiNoOfDataBlocks Number of data blocks to be locked to [0..255]
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				virtual int LockMultipleBlocksEx(unsigned int uiFirstDataBlock,
					unsigned int uiNoOfDataBlocks);

				/// @brief Extended [0xB0][0x23] Read Multiple Blocks command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..65535]
				/// @param[in] uiNoOfDataBlocks Number of requested data blocks [0..255]
				/// @param[out] uiBlockSize Number of bytes in each data block
				/// @param[out] pucData Pointer to array for received data blocks. The array must have the dimension of uiNoOfDataBlocks x Expected Block Size
				/// @param[in] uiDataBufferLength length of data buffer
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Basic [0xB0][0x23] Read Multiple Blocks command<br>
				/// - Without support for extended address mode<br>
				/// - Without request of security status<br>
				/// <remarks>
				/// <b>Note:</b><br/>
				/// The internal data buffer is limited to 16384 bytes (e.g. 4K data blocks with each 4 byte).
				/// </remarks>
				int ReadMultipleBlocksEx(unsigned int uiFirstDataBlock,
					unsigned int uiNoOfDataBlocks,
					unsigned int& uiBlockSize,
					unsigned char* pucData,
					unsigned int uiDataBufferLength);

				/// @brief Extended [0xB0][0x23] Read Multiple Blocks command with additional security status
				///
				/// @param[in] uiFirstDataBlock First data block address [0..65535]
				/// @param[in] uiNoOfDataBlocks Number of requested data blocks [0..255]
				/// @param[out] uiBlockSize Number of bytes in each data block
				/// @param[out] pucSecurityStatus Array with received status information, one byte for each data block. The array must have the dimension of uiNoOfDataBlocks
				/// @param[in] uiSecurityBufferLength length of security status buffer (the dimension of uiNoOfDataBlocks)
				/// @param[out] pucData Pointer to array for received data blocks. The array must have the dimension of uiNoOfDataBlocks x expected block size
				/// @param[in] uiDataBufferLength length of data buffer (the dimension of uiNoOfDataBlocks x expected block size)
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Extended [0xB0][0x23] Read Multiple Blocks command with additional security status<br>
				/// - With support for extended address mode<br>
				/// <remarks>
				/// <b>Note:</b><br/>
				/// The internal data buffer is limited to 16384 bytes (e.g. 4K data blocks with each 4 byte).
				/// </remarks>
				int ReadMultipleBlocksEx(unsigned int uiFirstDataBlock,
					unsigned int uiNoOfDataBlocks,
					unsigned int& uiBlockSize,
					unsigned char* pucSecurityStatus,
					unsigned int uiSecurityBufferLength,
					unsigned char* pucData,
					unsigned int uiDataBufferLength);

				/// @brief Extended [0xB0][0x24] Write Multiple Blocks command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..65535]
				/// @param[in] uiNoOfDataBlocks Number of data blocks to transmit to [0..255]
				/// @param[in] uiBlockSize Number of bytes in each data block
				/// @param[in] pucData Pointer to array with data blocks to transmit to
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Extended [0xB0][0x24] Write Multiple Blocks command<br>
				/// - With support for extended address mode<br>
				/// <remarks>
				/// <b>Note:</b><br/>
				/// The internal data buffer is limited to 4K data blocks with each 4 byte.
				/// </remarks>
				int WriteMultipleBlocksEx(unsigned int uiFirstDataBlock,
					unsigned int uiNoOfDataBlocks,
					unsigned int uiBlockSize,
					unsigned char* pucData);

				/// @brief [0xB0][0x26] : Reset To Ready command
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int ResetToReady();

				/// @brief [0xB0][0x27] Write AFI command
				///
				/// @param[in] ucAFI AFI value
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				int WriteAFI(unsigned char ucAFI);

				/// @brief [0xB0][0x28] Lock AFI command
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int LockAFI();

				/// @brief [0xB0][0x29] Write DSFID command
				///
				/// @param[in] ucDSFID DSFID value
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				int WriteDSFID(unsigned char ucDSFID);

				/// @brief [0xB0][0x2A] Lock DSFID command
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command
				int LockDSFID();

				/// @brief Basic [0xB0][0x2B] Get System Information command
				///
				/// @param[in] systemInfo reference to a class with returned system information
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				virtual int GetSystemInformation(SystemInfo & systemInfo);

				/// @brief Extended [0xB0][0x2B] Get System Information command
				///
				/// @param[in] systemInfo reference to a class with returned system information
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				int GetSystemInformationEx(SystemInfo & systemInfo);

				/// @brief Basic [0xB0][0x2C] Get Multiple Block Security Status command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..255]
				/// @param[in] uiNoOfDataBlocks Number of data blocks to be locked to [0..255]
				/// @param[out] pucSecurityStatus Array with received status information, one byte for each data block. The array must have the dimension of uiNoOfDataBlocks.
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				/// <remarks>
				/// <b>Note:</b><br/>
				/// The internal data buffer is limited to 4096 bytes (4K data blocks).
				/// </remarks>
				virtual int GetMultipleBlockSecurityStatus(	unsigned int uiFirstDataBlock,
															unsigned int uiNoOfDataBlocks,
															unsigned char* pucSecurityStatus );

				/// @brief Extended [0xB0][0x2C] Get Multiple Block Security Status command
				///
				/// @param[in] uiFirstDataBlock First data block address [0..65535]
				/// @param[in] uiNoOfDataBlocks Number of data blocks to be locked to [0..255]
				/// @param[out] pucSecurityStatus Array with received status information, one byte for each data block. The array must have the dimension of uiNoOfDataBlocks.
				/// @param[in] uiSecurityBufferLength length if security status buffer (the dimension of uiNoOfDataBlocks)
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
				/// <remarks>
				/// <b>Note:</b><br/>
				/// The internal data buffer is limited to 4096 bytes (4K data blocks).
				/// </remarks>
				virtual int GetMultipleBlockSecurityStatusEx(	unsigned int uiFirstDataBlock,
																unsigned int uiNoOfDataBlocks,
																unsigned char* pucSecurityStatus,
																unsigned int uiSecurityBufferLength);

				/// @brief [0xB0][0x35] Authenticate
				///
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
				int Authenticate(	unsigned char ucAuthMode,
									unsigned char ucCSI,
									unsigned char ucCryptoTime,
									unsigned int  uiRspLen,
									const std::vector<unsigned char> & vMsg,
									std::vector<unsigned char> & vRsp);
	
				/// @brief [0xB0][0x39] Challenge
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

				/// @brief [0xB0][0x3A] Read Buffer
				///
				/// @param[out] vData The content of the tag response buffer
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// This command allows to read data stored in a tag response buffer.
				int ReadBuffer(std::vector<unsigned char> & vData);

				/// @brief [0xBF] Transparent Command
				///
				/// @param[in]  ucMode          Mode (Bit0..3 = Options, Bit7 = TxCRCEnab, all other bits are RFU and must be set to zero)
				/// @param[in]  uiRspBitLen     Length of the transponder response in bits without SOF and EOF
				/// @param[in]  uiCmdRspDelay   Command response delay
				/// @param[in]  uiEofPulseDelay EOF pulse delay        (only for options 3,4)
				/// @param[in]  uiMultiGrids    Multiple 302µs grids   (only for option 5)
				/// @param[in]  vReqData        Request data
				/// @param[out] vRspData        Response data
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// General implementation of the [0xBF] transparent command
				int TransparentCommand(	unsigned char ucMode,
										unsigned int  uiRspBitLen,
										unsigned int  uiCmdRspDelay,
										unsigned int  uiEofPulseDelay,
										unsigned int  uiMultiGrids,
										const std::vector<unsigned char> & vReqData,
										std::vector<unsigned char> & vRspData);


			protected:
				// constructor
				TH_ISO15693(ReaderModule* pReader, FedmIscTagHandler_ISO15693* pThImpl);
				// destructor
				virtual ~TH_ISO15693();

				unsigned char m_ucISO15693ErrorCode;

			private:
				int GetSystemInformationEx(bool ex, SystemInfo & systemInfo);
			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_H_INCLUDED_)
