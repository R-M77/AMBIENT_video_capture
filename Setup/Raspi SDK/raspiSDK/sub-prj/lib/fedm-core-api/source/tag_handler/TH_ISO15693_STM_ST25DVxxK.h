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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_ST25DVxxK_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_ST25DVxxK_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#include "TH_ISO15693_STM.h"

class FedmIscTagHandler_ISO15693_STM_ST25DVxxK;

namespace FEDM
{
	namespace Core
	{
		/// Namespace for Transponder classes
		namespace TagHandler
		{
			//####################################################################
			// class TH_ISO15693_STM_ST25DVxxK
			// >> supports only ISO Host Commands <<
			//####################################################################

			/// @brief Transponder class providing manufacturer specific commands for ISO 15693 compliant Transponders of type ST25DVxxK series from manufacturer STMicroelectronics SA
			///
			/// <b>Description</b><br>
			/// High-level class for easy-to-use Transponder specific communication. See FEDM::Core::ITagGroup for additional information.<br>
			/// All methods are similiar to specific commands of M24LRxxE-R. Thus, you must refer to the Technical Datasheet of the ST25DVxxK to get detailed information about the methods and the parameters.<br>
			/// Secondly, all methods of this class are Custom specific commands, realized with the Reader command [0xB1], which are described in the Application Note <i>STMicroelectronics Custom and Proprietary Commands.pdf</i>
			///
			/// @note Programmers should be familiar with the ISO 15693 standard
			class _FEDM_ISC_CORE_EXT_CLASS TH_ISO15693_STM_ST25DVxxK : public TH_ISO15693_STM
			{
				// friend classes have access rights to protected and private members
				friend class FEDM::Core::ITagGroup;

			public:

				/// @brief [0xB1][0xA0] Read Configuration Byte
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
				int ReadCfg(unsigned char ucPointer, unsigned char & ucRegVal);

				/// @brief [0xB1][0xA1] Write Configuration Byte
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
				int WriteCfg(unsigned char ucPointer, unsigned char ucRegVal);

				/// @brief [0xB1][0xA9] Manage GPO
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
				int ManageGpo(unsigned char ucGpoVal);

				/// @brief [0xB1][0xAA] Write Mail Box Message
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
				int WriteMBMsg(const std::vector<unsigned char> & msg);

				/// @brief [0xB1][0xAB] Read Mail Box Message Length
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.
				int ReadMBMsgLength(unsigned int & uiLen);

				/// @brief [0xB1][0xAC] Read Mail Box Message
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
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
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
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
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
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
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
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
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Refer to the Application Note <i>DS10925_ST25DV64K_rev04d.pdf</i>, where all parameters are described in detail.<br>
				/// If ucMBPointer and ucReqLen both are set to 0x00, all bytes of the message are returned.
				int PresentPassword(unsigned char ucPwdNum, const unsigned char ucPwd[FEDM_ISO15693_ST25_PWD_LEN]);

				/** @brief Set of new command response delay value
				 *
				 * <b>Description</b><br>
				 * NOTE: Set of command response delay value is only for rare cases.<br>
				 * The command response delay value is preset to 0. This value let the Reader set the optimal value.<br>
				 * Any other value must be multiplicated with 590ns to calculate the command response delay.<br>
				 * Example: 543 * 590ns = 320.9 ?s (which is a typical value).
				 */
				void SetCommandResponseDelay(unsigned int uiCmdRspDelay);

			protected:
				// constructor
				TH_ISO15693_STM_ST25DVxxK(ReaderModule* pReader, FedmIscTagHandler_ISO15693_STM_ST25DVxxK* pThImpl);
				// destructor
				virtual ~TH_ISO15693_STM_ST25DVxxK();

			private:
				int ReadCfgTransp(unsigned char ucPointer, unsigned char & ucRegVal);
				int WriteCfgTransp(unsigned char ucPointer, unsigned char ucRegVal);
				int ManageGpoTransp(unsigned char ucGpoVal);
				int WriteMBMsgTransp(const std::vector<unsigned char> & msg);
				int ReadMBMsgLengthTransp(unsigned int & uiLen);
				int ReadMBMsgTransp(unsigned char ucMBPointer, unsigned int uiReqLen, std::vector<unsigned char> & msg);
				int ReadDynCfgTransp(unsigned char ucPointer, unsigned char & ucRegVal);
				int WriteDynCfgTransp(unsigned char ucPointer, unsigned char ucRegVal);
				int WritePasswordTransp(unsigned char ucPwdNum, const unsigned char ucPwd[FEDM_ISO15693_ST25_PWD_LEN]);
				int PresentPasswordTransp(unsigned char ucPwdNum, const unsigned char ucPwd[FEDM_ISO15693_ST25_PWD_LEN]);

				unsigned int m_uiCmdRspDelay;
			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)

#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_TH_ISO15693_STM_M24LRxxER_H_INCLUDED_)
