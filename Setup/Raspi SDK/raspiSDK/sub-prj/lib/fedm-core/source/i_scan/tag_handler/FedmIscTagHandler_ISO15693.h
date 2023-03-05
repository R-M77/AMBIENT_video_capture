/*-------------------------------------------------------
|                                                       |
|	   FedmIscTagHandler_ISO15693.h                     |
|                                                       |
---------------------------------------------------------

Copyright © 2009-2014	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Markus Hultsch
Begin        		:	30.03.2009

Version       		:	04.06.01 / 07.03.2014 / M. Hultsch
						- methods LockMultipleBlocks and GetMultipleBlockSecurityStatus now virtual

						03.01.00 / 10.02.2010 / M. Hultsch

Operation Systems	:	independent

Function			:	class for OBID i-scan® HF transponder ISO15693

NOTE				:	this class supports only selected or addressed mode in Host-Mode


Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/

#if !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_H_INCLUDED_)
#define _FEDM_ISC_TAG_HANDLER_ISO15693_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "../../FEDM.h"
#include "FedmIscTagHandler.h"
#include <vector>

class FEDM_ISOTabItem;

#define FEDM_ISO15693_UID_LEN 8



//#####################################################################################
// constants
//#####################################################################################





//####################################################################
// class FedmIscTagHandler_ISO15693
// >> supports only ISO Host Commands <<
//####################################################################

/// @brief Transponder class providing basic commands for all ISO 15693 compliant Transponders
///
/// <b>Description</b><br>
/// High-level class for easy-to-use Transponder specific communication. See OBID::FEDM::Core::ITagGroup for additional information.<br>
///
/// @note Programmers should be familiar with the ISO 15693 standard
class _FEDM_ISC_CORE_EXT_CLASS FedmIscTagHandler_ISO15693 : public FedmIscTagHandler
{
public:

	// friend classes have access rights to protected members
	friend class FEDM_ISCReaderModule;
	friend class FEDM_ISCReader;
	friend class FEDM_ISOTabItem;

	/// @brief Initialization method
	///
	/// <b>Description</b><br>
	/// Clears all data members
	virtual void Init();

	/// @brief Method to query the ISO15693 error code
	///
	/// <b>Description</b><br>
	/// Call this function if you obtain the reader status code 0x95.
	unsigned char GetISO15693ErrorCode() { return m_ucISO15693ErrorCode; }

	/// @brief Method to query the Manufacturer Name
	///
	/// @return String with Manufacturer Name
	///
	/// <b>Description</b><br>
	/// The Manufacturer Name is specified with Manufcturer Code, which is located in byte 1 of the UID
	const char* GetManufacturerName();

	/// @brief [0xB0][0x02] : Stay Quiet command
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command
	int StayQuiet();

	/// @brief [0xB0][0x22] : Lock Multiple Blocks command
	///
	/// @param[in] uiFirstDataBlock First data block address
	/// @param[in] uiNoOfDataBlocks Number of data blocks to be locked to
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
	virtual int LockMultipleBlocks(	unsigned int uiFirstDataBlock,
									unsigned int uiNoOfDataBlocks);

	/// @brief [0xB0][0x26] : Reset To Ready command
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command
	int ResetToReady();

	/// @brief [0xB0][0x27] : Write AFI command
	///
	/// @param[in] ucAFI AFI value
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
	int WriteAFI(unsigned char ucAFI);

	/// @brief [0xB0][0x28] : Lock AFI command
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command
	int LockAFI();

	/// @brief [0xB0][0x29] : Write DSFID command
	///
	/// @param[in] ucDSFID DSFID value
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
	int WriteDSFID(unsigned char ucDSFID);

	/// @brief [0xB0][0x2A] : Lock DSFID command
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command
	int LockDSFID();

	/// @brief [0xB0][0x2B] : Get System Information command
	///
	/// @param[out] sUid String with hex-coded UID or Serial Number
	/// @param[out] ucAFI AFI value
	/// @param[out] uiMemSize VICC Memory size
	/// @param[out] ucICRef IC-Reference
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
	///
	/// @note Hex-coded string means, that a string like "AB39F1D9" represent a hex value of 0xAB39F1D9.
	virtual int GetSystemInformation(	string& sUid,
										unsigned char& ucAFI,
										unsigned int& uiMemSize,
										unsigned char& ucICRef );

	/*int GetSystemInformation2(	bool bExtended,
								unsigned char *ucDSFID,
								unsigned char ucUID[8],
								unsigned char *ucAFI,
								unsigned int  *uiMemBlkSize,
								unsigned int  *uiMemNumBlk,
								unsigned char *ucIcRef,
								unsigned char ucCL[4]);*/

	/// @brief [0xB0][0x2C] : Get Multiple Block Security Status command
	///
	/// @param[in] uiFirstDataBlock First data block address
	/// @param[in] uiNoOfDataBlocks Number of data blocks to be locked to
	/// @param[out] pucSecurityStatus Array with received status information, one byte for each data block. The array must have the dimension of uiNoOfDataBlocks.
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// See Reader&apos;s System Manual for detailed information about the command and the method parameters
	virtual int GetMultipleBlockSecurityStatus(	unsigned int uiFirstDataBlock,
												unsigned int uiNoOfDataBlocks,
												unsigned char* pucSecurityStatus );

	/// @brief Authenticate
	///
	/// @param[in] ucAuthMode Defines the format of the request and the response (see manual).
	/// @param[in] ucCSI      Crypto Suite Identifier
	/// @param[in] vMsg       Message defined by the specified crypto suite (see manual).
	/// @param[out] vRsp      Vector of the response data.
	///
	/// <b>Description</b><br>
	/// [0xB0][0x35] Authenticate: This command performs tag, reader, or mutual authentication.
	int Authenticate(	unsigned char ucAuthMode,
						unsigned char ucCSI,
						unsigned char ucCryptoTime,
						unsigned int  uiRspLen,
						const std::vector<unsigned char> & vMsg,
						std::vector<unsigned char> & vRsp);
	
	/// @brief Challenge
	///
	/// @param[in] ucAuthMode Defines the format of the request and the response (see manual).
	/// @param[in] ucCSI      Crypto Suite Identifier
	/// @param[in] vMsg       Message defined by the specified crypto suite (see manual).
	///
	/// <b>Description</b><br>
	/// [0xB0][0x39]Challenge: This command allows an interrogator to instruct multiple tags to simultaneously yet independently precompute and store a cryptographic value.
	/// No response is send from tag on a challenge command.
	int Challenge(	unsigned char ucAuthMode,
					unsigned char ucCSI,
					unsigned char ucCryptoTime,
					unsigned int  uiRspLen,
					const std::vector<unsigned char> & vMsg);

	/// @brief Read Buffer
	///
	/// @param[out] vData       (vector containing the cryptographic response)
	///
	/// <b>Description</b><br>
	/// [0xB0][0x3A]ReadBuffer: This command allows to read data stored in a tag response buffer.
	int ReadBuffer(std::vector<unsigned char> & vData);

	/// @brief Transparent Command
	///
	/// @param[in]  ucMode          Mode (Bit0..3 = Options, Bit6 = Fast(only for UHF), Bit7 = TxCRCEnab)
	/// @param[in]  uiRspBitLen     Length of the transponder response in bits without SOF and EOF
	/// @param[in]  uiCmdRspDelay   Command response delay
	/// @param[in]  uiEofPulseDelay EOF pulse delay        (only for options 3,4)
	/// @param[in]  uiMultiGrids    Multiple 302µs grids   (only for option 5)
	/// @param[in]  vReqData        Request data (depends on the sub command, see manual)
	/// @param[out] vRspData        Response data
	///
	/// <b>Description</b><br>
	/// [0xBF][SubCmd]: General implementation of the transparent command
	int TransparentCommand(	unsigned char ucMode,
							unsigned int  uiRspBitLen,
							unsigned int  uiCmdRspDelay,
							unsigned int  uiEofPulseDelay,
							unsigned int  uiMultiGrids,
							const std::vector<unsigned char> & vReqData,
							std::vector<unsigned char> & vRspData);

protected:
	// constructor
	FedmIscTagHandler_ISO15693(FEDM_ISCReader* pReader, FEDM_ISOTabItem* pTabItem);
	// 2. constructor
	FedmIscTagHandler_ISO15693(FEDM_ISCReader* pReader, unsigned int uiTagHandlerType, FEDM_ISOTabItem* pTabItem);
	// destructor
	virtual ~FedmIscTagHandler_ISO15693();

	unsigned int m_uiChipID;
	unsigned char m_ucISO15693ErrorCode;

};

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_H_INCLUDED_)
