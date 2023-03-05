/*-------------------------------------------------------
|                                                       |
|	   FedmIscTagHandler_ISO15693_NXP_ICODE_DNA.h     |
|                                                       |
---------------------------------------------------------

Copyright © 2009-2013	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Axel Bierschenk
Begin        		:	28.08.2017

Version       		:	04.08.03 / 28.08.2017 / A. Bierschenk

Operation Systems	:	independent

Function			:	class for OBID i-scan® HF transponder ISO15693 of manufacturer NXP Semiconductors
						specialized tag handler on top with custom specific commands

NOTE				:	this class supports only selected or addressed mode in Host-Mode


Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/

#if !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_NXP_ICODE_DNA_H_INCLUDED_)
#define _FEDM_ISC_TAG_HANDLER_ISO15693_NXP_ICODE_DNA_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "../../FEDM.h"
#include "FedmIscTagHandler_ISO15693_NXP_ICODE_SLI.h"

class FEDM_ISOTabItem;



//#####################################################################################
// constants
//#####################################################################################





//####################################################################
// class FedmIscTagHandler_ISO15693_NXP_ICODE_DNA
// >> supports only ISO Host Commands <<
//####################################################################

/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type I-CODE DNA from manufacturer NXP Semiconductors
///
/// <b>Description</b><br>
/// High-level class for easy-to-use Transponder specific communication. See OBID::FEDM::Core::ITagGroup for additional information.<br>
/// All methods are similiar to specific commands of I-CODE DNA. Thus, you must refer to the Technical Datasheet of the I-CODE DNA to get detailed information about the methods and the parameters.<br>
/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>
///
/// @note Programmers should be familiar with the ISO 15693 standard
class _FEDM_ISC_CORE_EXT_CLASS FedmIscTagHandler_ISO15693_NXP_ICODE_DNA : public FedmIscTagHandler_ISO15693_NXP_ICODE_SLI
{
public:

	// friend classes have access rights to protected members
	friend class FEDM_ISCReaderModule;
	friend class FEDM_ISCReader;
	friend class FEDM_ISOTabItem;

	/// @brief [0xB1][0xA6]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int PasswordProtectEAS();

	/// @brief [0xB1][0xA6]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int PasswordProtectAFI();

	/// @brief [0xB1][0xA7]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int WriteEASID(string sEASID);

	/// @brief [0xB1][0xB2]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int GetRandomNumber(unsigned char* ucRandomNo, unsigned int uiRandomNoBufferLen);

	/// @brief [0xB1][0xAB]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int GetNxpSystemInformation(unsigned char* ucPpPointer, unsigned char* ucPpCond, unsigned char* ucLockBits, unsigned int *uiFeatureFlags);

	/// @brief [0xB1][0xB6]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int ProtectPage(unsigned char ucPpa, unsigned char ucExtProtectionStatus);

	/// @brief [0xB1][0xB7]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int LockPageProtectionCondition(unsigned char ucPageNumber);

	/// @brief [0xB1][0xBD]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int ReadSignature(unsigned char ucSignature[32]);

	/// @brief [0xBF][0xC0]
	/// Length of pucData-array must be 4 x ucNumOfBlocks
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int ReadConfig(	unsigned char ucBlockAddr,
					unsigned char ucNumOfBlocks,
					unsigned char *pucData);

	/// @brief [0xBF][0xC1]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int WriteConfig(	unsigned char ucBlockAddr,
						const unsigned char ucData[4]);

	/// @brief [0xBF][0xC3]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int PickRandomID();


protected:
	// constructor
	FedmIscTagHandler_ISO15693_NXP_ICODE_DNA(FEDM_ISCReader* pReader, FEDM_ISOTabItem* pTabItem);
	// 2. constructor
	FedmIscTagHandler_ISO15693_NXP_ICODE_DNA(FEDM_ISCReader* pReader, unsigned int uiTagHandlerType, FEDM_ISOTabItem* pTabItem);
	// destructor
	virtual ~FedmIscTagHandler_ISO15693_NXP_ICODE_DNA();

};

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_NXP_ICODE_DNA_H_INCLUDED_)
