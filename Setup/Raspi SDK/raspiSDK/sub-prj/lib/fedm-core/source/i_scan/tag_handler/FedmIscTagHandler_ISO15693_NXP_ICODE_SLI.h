/*-------------------------------------------------------
|                                                       |
|	   FedmIscTagHandler_ISO15693_NXP_ICODE_SLI.h       |
|                                                       |
---------------------------------------------------------

Copyright � 2009-2010	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Markus Hultsch
Begin        		:	02.10.2009

Version       		:	03.01.00 / 10.02.2010 / M. Hultsch

Operation Systems	:	independent

Function			:	class for OBID i-scan� HF transponder ISO15693 of manufacturer NXP Semiconductors
						specialized tag handler on top with custom specific commands

NOTE				:	this class supports only selected or addressed mode in Host-Mode


Trademarks:
-----------
OBID�, OBID i-scan� and OBID myAXXESS� are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/

#if !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_NXP_ICODE_SLI_H_INCLUDED_)
#define _FEDM_ISC_TAG_HANDLER_ISO15693_NXP_ICODE_SLI_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "../../FEDM.h"
#include "FedmIscTagHandler_ISO15693_NXP.h"

class FEDM_ISOTabItem;



//#####################################################################################
// constants
//#####################################################################################





//####################################################################
// class FedmIscTagHandler_ISO15693_NXP_ICODE_SLI
// >> supports only ISO Host Commands <<
//####################################################################

/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type I-CODE SLI from manufacturer NXP Semiconductors
///
/// <b>Description</b><br>
/// High-level class for easy-to-use Transponder specific communication. See OBID::FEDM::Core::ITagGroup for additional information.<br>
/// All methods are similiar to specific commands of I-CODE SLI. Thus, you must refer to the Technical Datasheet of the I-CODE SLI to get detailed information about the methods and the parameters.<br>
/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>
///
/// @note Programmers should be familiar with the ISO 15693 standard
class _FEDM_ISC_CORE_EXT_CLASS FedmIscTagHandler_ISO15693_NXP_ICODE_SLI : public FedmIscTagHandler_ISO15693_NXP
{
public:

	// friend classes have access rights to protected members
	friend class FEDM_ISCReaderModule;
	friend class FEDM_ISCReader;
	friend class FEDM_ISOTabItem;

//	virtual void Init();
	// set all data members to 0

	//[0xB1][0xA0] - implemented in reader class

	//[0xB1][0xA1] - implemented in reader class

	/// @brief [0xB1][0xA2]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int SetEAS();

	/// @brief [0xB1][0xA3]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int ResetEAS();

	/// @brief [0xB1][0xA4]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int LockEAS();

	/// @brief [0xB1][0xA5]
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref OBID::FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>NXP Custom and Proprietary Commands.pdf</i>, where all parameters are described in detail.
	int EASAlarm();

protected:
	// constructor
	FedmIscTagHandler_ISO15693_NXP_ICODE_SLI(FEDM_ISCReader* pReader, FEDM_ISOTabItem* pTabItem);
	// 2. constructor
	FedmIscTagHandler_ISO15693_NXP_ICODE_SLI(FEDM_ISCReader* pReader, unsigned int uiTagHandlerType, FEDM_ISOTabItem* pTabItem);
	// destructor
	virtual ~FedmIscTagHandler_ISO15693_NXP_ICODE_SLI();

	int PasswordProtectEAS();
	int PasswordProtectAFI();
	int WriteEASID(string sEASID);
	int ReadEPC(unsigned char* ucEpc, unsigned int uiEpcBufferLen);
	int GetRandomNumber(unsigned char* ucRandomNo, unsigned int uiRandomNoBufferLen);
	int SetPassword(unsigned char ucPasswordIdentifier, string sPassoword);
	int WritePassword(unsigned char ucPasswordIdentifier, string sPassword);
	int LockPassword(unsigned char ucPasswordIdentifier);
	int ProtectPage(unsigned char ucPageNumber, unsigned char ucProtectionStatus);
	int ProtectPageExt(unsigned char ucPpa, unsigned char ucExtProtectionStatus);
	int LockPageProtectionCondition(unsigned char ucPageNumber);
	int GetMultipleBlockProtectionStatus(unsigned int uiFirstDataBlock, unsigned int uiNoOfDataBlocks, unsigned char* pucSecurityStatus);
	int Destroy();
	int EnablePrivacy();
	int PasswordProtection(unsigned char ucPasswordParameter);
	int GetNxpSystemInformation(unsigned char* ucPpPointer, unsigned char* ucPpCond, unsigned char* ucLockBits, unsigned int *uiFeatureFlags);
	int ReadSignature(unsigned char ucSignature[32]);

};

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_NXP_ICODE_SLI_H_INCLUDED_)
