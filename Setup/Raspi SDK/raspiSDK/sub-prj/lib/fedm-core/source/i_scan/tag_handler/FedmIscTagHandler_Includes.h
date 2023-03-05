/*-------------------------------------------------------
|                                                       |
|	   FedmIscTagHandler_Includes.h                     |
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
					
Author         		:	Markus Hultsch
Begin        		:	02.10.2009
Version       		:	04.05.02 / 02.07.2013 / M. Hultsch

Operation Systems	:	independent


This file includes all dependencies for the component FEDM with support for TagHandler

Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/


#if !defined(_FEDM_ISC_TAG_HANDLER_INCLUDES_H_INCLUDED_)
#define _FEDM_ISC_TAG_HANDLER_INCLUDES_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)
	#include "../source/i_scan/tag_handler/FedmIscTagHandler.h"
#if !defined(_FEDM_NO_TAG_HANDLER_EPC_C1_G2)
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_EPC_Class1_Gen2.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER_ISO18000_3M3)
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO18000_3M3.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_Innovatron.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_2.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_2_Innovision_Jewel.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_2_STM_SR176.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_2_STM_SRIxxx.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_ASK_CTx.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_Infineon_my_d.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_Infineon_my_d_move.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_MIFARE_Classic.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_MIFARE_Ultralight.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_MIFARE_Plus.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_MIFARE_Plus_SL1.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_3_MIFARE_Plus_SL2.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_4.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_4_MIFARE_Plus.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL1.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL2.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_4_MIFARE_Plus_SL3.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO14443_4_MIFARE_DESFire.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM_LRI2K.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM_LRIS2K.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM_LRIS64K.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM_M24LR64R.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM_M24LRxxER.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_STM_ST25DVxxK.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLI.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLIX.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLIX2.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLI_L.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLIX_L.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLI_S.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_SLIX_S.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_NXP_ICODE_DNA.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_Infineon.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_Infineon_my_d.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_TI.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_TI_Tag_it_HFI_Pro.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_TI_Tag_it_HFI_Plus.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_Fujitsu.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_Fujitsu_MB89R1xx.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_EM.h"
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_ISO15693_EM_4034.h"
#endif
#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // _FEDM_ISC_TAG_HANDLER_INCLUDES_H_INCLUDED_

