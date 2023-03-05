/*-------------------------------------------------------
|                                                       |
|	   FedmIscTagHandler_ISO15693_STM_ST25DVxxK.h       |
|                                                       |
---------------------------------------------------------

Copyright © 2009-2012	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Axel Bierschenk
Begin        		:	21.06.2017

Version       		:	04.08.02 / 21.06.2017 / A.Bierschenk

Operation Systems	:	independent

Function			:	class for OBID i-scan® HF transponder ISO15693 of manufacturer STMicroelectronics SA
						specialized tag handler on top with custom specific commands

NOTE				:	this class supports only selected or addressed mode in Host-Mode


Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/

#if !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_STM_ST25DVxxK_H_INCLUDED_)
#define _FEDM_ISC_TAG_HANDLER_ISO15693_STM_ST25DVxxK_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "../../FEDM.h"
#include "FedmIscTagHandler_ISO15693_STM.h"
#include <vector>

class FEDM_ISOTabItem;

#define FEDM_ISO15693_ST25_UID_LEN 8
#define FEDM_ISO15693_ST25_PWD_LEN 8
#define FEDM_ISO15693_ST25_MAILBOX_SIZE 256



//#####################################################################################
// constants
//#####################################################################################





//####################################################################
// class FedmIscTagHandler_ISO15693_STM_ST25DVxxK
// >> supports only ISO Host Commands <<
//####################################################################

/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type ST25DVxxK-IE/JF series from manufacturer STMicroelectronics SA
///
/// <b>Description</b><br>
/// High-level class for easy-to-use Transponder specific communication. See OBID::FEDM::Core::ITagGroup for additional information.<br>
/// All methods are similiar to specific commands of ST25DVxxK-IE/JF. Thus, you must refer to the Technical Datasheet of the ST25DVxxK-IE/JF to get detailed information about the methods and the parameters.<br>
/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>
///
/// @note Programmers should be familiar with the ISO 15693 standard
class _FEDM_ISC_CORE_EXT_CLASS FedmIscTagHandler_ISO15693_STM_ST25DVxxK : public FedmIscTagHandler_ISO15693_STM
{
public:

	// friend classes have access rights to protected members
	friend class FEDM_ISCReaderModule;
	friend class FEDM_ISCReader;
	friend class FEDM_ISOTabItem;

	typedef struct temp_t {
		unsigned char ucPointer;
		unsigned char ucValue;
		unsigned char ucMbMsgLen;
		unsigned char ucMbMsg[FEDM_ISO15693_ST25_MAILBOX_SIZE];
		unsigned char ucPassword[FEDM_ISO15693_ST25_PWD_LEN];
	} temp_t;

	/// @brief [0xB1][0xA0] Read Configuration Byte
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
	int ReadCfg(unsigned char ucPointer, unsigned char & ucRegVal);

	/// @brief [0xB1][0xA1] Write Configuration Byte
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
	int WriteCfg(unsigned char ucPointer, unsigned char ucRegVal);

	/// @brief [0xB1][0xA9] Manage GPO
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
	int ManageGpo(unsigned char ucGpoVal);

	/// @brief [0xB1][0xAA] Write Mail Box Message
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
	int WriteMBMsg(const std::vector<unsigned char> & msg);

	/// @brief [0xB1][0xAB] Read Mail Box Message Length
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
	int ReadMBMsgLength(unsigned int & uiLen);

	/// @brief [0xB1][0xAC] Read Mail Box Message
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.<br>
	/// If ucMBPointer and ucReqLen both are set to 0x00, all bytes of the message are returned.
	int ReadMBMsg(unsigned char ucMBPointer, unsigned int uiReqLen, std::vector<unsigned char> & msg);

	/// @brief [0xB1][0xAD] Read Dynamic Register
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.<br>
	/// If ucMBPointer and ucReqLen both are set to 0x00, all bytes of the message are returned.
	int ReadDynCfg(unsigned char ucPointer, unsigned char & ucRegVal);

	/// @brief [0xB1][0xAE] Write Dynamic Register
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.<br>
	/// If ucMBPointer and ucReqLen both are set to 0x00, all bytes of the message are returned.
	int WriteDynCfg(unsigned char ucPointer, unsigned char ucRegVal);

	/// @brief [0xB1][0xB1] Write Password
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.<br>
	/// If ucMBPointer and ucReqLen both are set to 0x00, all bytes of the message are returned.
	int WritePassword(unsigned char ucPwdNum, const unsigned char ucPwd[FEDM_ISO15693_ST25_PWD_LEN]);

	/// @brief [0xB1][0xB3] Present Password
	///
	/// @return 
	/// -   0 if OK
	/// - < 0 [error code](@ref FEDM::Core::Error)
	/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
	///
	/// <b>Description</b><br>
	/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.<br>
	/// If ucMBPointer and ucReqLen both are set to 0x00, all bytes of the message are returned.
	int PresentPassword(unsigned char ucPwdNum, const unsigned char ucPwd[FEDM_ISO15693_ST25_PWD_LEN]);

	temp_t *GetTempData(void) { return &tempData; }


protected:
	// constructor
	FedmIscTagHandler_ISO15693_STM_ST25DVxxK(FEDM_ISCReader* pReader, FEDM_ISOTabItem* pTabItem);
	// 2. constructor
	FedmIscTagHandler_ISO15693_STM_ST25DVxxK(FEDM_ISCReader* pReader, unsigned int uiTagHandlerType, FEDM_ISOTabItem* pTabItem);
	// destructor
	virtual ~FedmIscTagHandler_ISO15693_STM_ST25DVxxK();

	void SetTagName(const unsigned char *ucSnr);

	temp_t tempData;
};

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // !defined(_FEDM_ISC_TAG_HANDLER_ISO15693_STM_ST25DVxxK_H_INCLUDED_)
