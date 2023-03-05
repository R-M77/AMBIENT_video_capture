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

#if !defined(_FEDM_CORE_ISCAN_TAG_HANDLER_INCLUDES_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_TAG_HANDLER_INCLUDES_H_INCLUDED_

#if !defined(_FEDM_NO_TAG_HANDLER)
	#include "TH_Base.h"
#if !defined(_FEDM_NO_TAG_HANDLER_EPC_C1_G2)
	#include "TH_EPC_Class1_Gen2.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER_ISO18000_3M3)
	#include "TH_ISO18000_3M3.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER_ISO14443)
	#include "TH_ISO14443.h"
	#include "TH_ISO14443_Innovatron.h"
	#include "TH_ISO14443_2.h"
	#include "TH_ISO14443_2_Innovision_Jewel.h"
	#include "TH_ISO14443_2_STM_SR176.h"
	#include "TH_ISO14443_2_STM_SRIxxx.h"
	#include "TH_ISO14443_3.h"
	#include "TH_ISO14443_3_ASK_CTx.h"
	#include "TH_ISO14443_3_Infineon_my_d.h"
	#include "TH_ISO14443_3_Infineon_my_d_move.h"
	#include "TH_ISO14443_3_MIFARE_Classic.h"
	#include "TH_ISO14443_3_MIFARE_Ultralight.h"
	#include "TH_ISO14443_3_MIFARE_Plus.h"
	#include "TH_ISO14443_3_MIFARE_Plus_SL1.h"
	#include "TH_ISO14443_3_MIFARE_Plus_SL2.h"
	#include "TH_ISO14443_4.h"
	#include "TH_ISO14443_4_MIFARE_Plus.h"
	#include "TH_ISO14443_4_MIFARE_Plus_SL1.h"
	#include "TH_ISO14443_4_MIFARE_Plus_SL2.h"
	#include "TH_ISO14443_4_MIFARE_Plus_SL3.h"
	#include "TH_ISO14443_4_MIFARE_DESFire.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER_ISO15693)
	#include "TH_ISO15693.h"
	#include "TH_ISO15693_STM.h"
	#include "TH_ISO15693_STM_LRI2K.h"
	#include "TH_ISO15693_STM_LRIS2K.h"
	#include "TH_ISO15693_STM_LRIS64K.h"
	#include "TH_ISO15693_STM_M24LR64R.h"
	#include "TH_ISO15693_STM_M24LRxxER.h"
	#include "TH_ISO15693_STM_ST25DVxxK.h"
	#include "TH_ISO15693_NXP.h"
	#include "TH_ISO15693_NXP_ICODE_SLI.h"
	#include "TH_ISO15693_NXP_ICODE_SLIX.h"
	#include "TH_ISO15693_NXP_ICODE_SLIX2.h"
	#include "TH_ISO15693_NXP_ICODE_SLI_L.h"
	#include "TH_ISO15693_NXP_ICODE_SLIX_L.h"
	#include "TH_ISO15693_NXP_ICODE_SLI_S.h"
	#include "TH_ISO15693_NXP_ICODE_SLIX_S.h"
	#include "TH_ISO15693_NXP_ICODE_DNA.h"
	#include "TH_ISO15693_Infineon.h"
	#include "TH_ISO15693_Infineon_my_d.h"
	#include "TH_ISO15693_TI.h"
	#include "TH_ISO15693_TI_Tag_it_HFI_Pro.h"
	#include "TH_ISO15693_TI_Tag_it_HFI_Plus.h"
	#include "TH_ISO15693_Fujitsu.h"
	#include "TH_ISO15693_Fujitsu_MB89R1xx.h"
	#include "TH_ISO15693_EM.h"
	#include "TH_ISO15693_EM_4034.h"
#endif
#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#endif // _FEDM_CORE_ISCAN_TAG_HANDLER_INCLUDES_H_INCLUDED_
