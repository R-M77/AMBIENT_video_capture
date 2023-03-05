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

#if !defined(_FEDM_CORE_READER_TYPES_H_INCLUDED_)
#define _FEDM_CORE_READER_TYPES_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "../source/i_scan/FEDM_ISC.h"


namespace FEDM
{
	namespace Core
	{
		namespace Const
		{
			/// @brief Namespace with all Reader Type Numbers
			class _FEDM_ISC_CORE_EXT_CLASS ReaderType
			{
			public:

				/// @brief Request of Reader Name from Reader Type
				///
				/// @return Reader Name
				/// <b>Description</b><br>
				/// The returned string can be used for displaying the product name.
				static std::string GetReaderName(unsigned int uiReaderType);

				/// Returns true, if Reader can handle ISO 14443 transponder
				static bool IsISO14443Reader(unsigned int uiReaderType);
				/// Returns true, if Reader can handle ISO 15693 transponder
				static bool IsISO15693Reader(unsigned int uiReaderType);
				/// Returns true, if Reader can handle ISO 18000-3M3 transponder
				static bool IsISO180003m3Reader(unsigned int uiReaderType);
				/// Returns true, if Reader can handle EPC Class1 Gen2 transponder
				static bool IsEPCC1G2Reader(unsigned int uiReaderType);

				/// Returns true, if Reader is part of IDENTIFICATION HF family (ISO 14443, ISO 15693 and ISO 18000-3M3)
				static bool IsHfReader(unsigned int uiReaderType);
				/// Returns true, if Reader is part of IDENTIFICATION UHF family (EPC Class1 Gen2)
				static bool IsUhfReader(unsigned int uiReaderType);

				/// i-scan HF ID ISC.M02 (31)
				static const unsigned int ID_ISC_M02 = FEDM_ISC_TYPE_ISCM02;
				/// i-scan HF ID ISC.M02.M8 (33)
				static const unsigned int ID_ISC_M02_M8 = FEDM_ISC_TYPE_ISCM02_M8;
				/// i-scan HF ID ISC.LR200 (41)
//				static const unsigned int ID_ISC_LR200 = FEDM_ISC_TYPE_ISCLR200;
				/// i-scan HF ID ISC.LR2000 or ID ISC.LRM2000 (42)
//				static const unsigned int ID_ISC_LR2000 = FEDM_ISC_TYPE_ISCLR2000;
				/// i-scan HF ID ISC.LR2500-B (43)
				static const unsigned int ID_ISC_LR2500_B = FEDM_ISC_TYPE_ISCLR2500_B;
				/// i-scan HF vID ISC.LR2500-A (44)
				static const unsigned int ID_ISC_LR2500_A = FEDM_ISC_TYPE_ISCLR2500_A;
				/// i-scan HF ID ISC.LR1002 (45)
				static const unsigned int ID_ISC_LR1002 = FEDM_ISC_TYPE_ISCLR1002;
				/// i-scan HF ID ISC.PRH101 (60)
				static const unsigned int ID_ISC_PRH101 = FEDM_ISC_TYPE_ISCPRH101;
				/// i-scan HF ID ISC.PRH101-U (61)
				static const unsigned int ID_ISC_PRH101_U = FEDM_ISC_TYPE_ISCPRH101_U;
				/// i-scan HF ID ISC.PRHD102 (62)
				static const unsigned int ID_ISC_PRHD102 = FEDM_ISC_TYPE_ISCPRHD102;
				/// i-scan HF ID ISC.PRH102 (63)
				static const unsigned int ID_ISC_PRH102 = FEDM_ISC_TYPE_ISCPRH102;
				/// i-scan HF ID ISC.PRH200 (64)
				static const unsigned int ID_ISC_PRH200 = FEDM_ISC_TYPE_ISCPRH200;
				/// i-scan HF ID ISC.PRH100-U (71)
//				static const unsigned int ID_ISC_PRH100_U = FEDM_ISC_TYPE_ISCPRH100_U;
				/// i-scan HF ID ISC.PRH100 (72)
//				static const unsigned int ID_ISC_PRH100 = FEDM_ISC_TYPE_ISCPRH100;
				/// i-scan HF ID ISC.MR100-U (73)
//				static const unsigned int ID_ISC_MR100_U = FEDM_ISC_TYPE_ISCMR100_U;
				/// i-scan HF ID ISC.MR100 (74)
//				static const unsigned int ID_ISC_MR100 = FEDM_ISC_TYPE_ISCMR100;
				/// i-scan HF ID ISC.PR100 (74) ???
//				static const unsigned int ID_ISC_PR100 = FEDM_ISC_TYPE_ISCPR100;
				/// i-scan HF ID ISC.MR200 (75)
//				static const unsigned int ID_ISC_MR200 = FEDM_ISC_TYPE_ISCMR200;
				/// i-scan HF ID ISC.MR101 (76)
				static const unsigned int ID_ISC_MR101 = FEDM_ISC_TYPE_ISCMR101;
				/// i-scan HF ID ISC.MR102 (77)
				static const unsigned int ID_ISC_MR102 = FEDM_ISC_TYPE_ISCMR102;
				/// i-scan HF ID ISC.MR101-U (78)
				static const unsigned int ID_ISC_MR101_U = FEDM_ISC_TYPE_ISCMR101_U;

				// experimental reader, identified by reader class, class generation and reader type
				//_FEDM_ISC_CORE_EXT_CLASS extern const unsigned int ISCMR10X;

				/// i-scan UHF ID ISC.MU02 (50)
				static const unsigned int ID_ISC_MU02 = FEDM_ISC_TYPE_ISCMU02;
				/// i-scan UHF ID ISC.MRU102 (54)
				static const unsigned int ID_ISC_MRU102 = FEDM_ISC_TYPE_ISCMRU102;
				/// i-scan UHF ID ISC.MRU200 (55)
//				static const unsigned int ID_ISC_MRU200 = FEDM_ISC_TYPE_ISCMRU200;
				/// i-scan UHF ID ISC.LRU1000 (92)
//				static const unsigned int ID_ISC_LRU1000 = FEDM_ISC_TYPE_ISCLRU1000;
				/// i-scan UHF ID ISC.LRU1002 (91)
				static const unsigned int ID_ISC_LRU1002 = FEDM_ISC_TYPE_ISCLRU1002;
				/// i-scan UHF ID ISC.LRU2000 (93)
//				static const unsigned int ID_ISC_LRU2000 = FEDM_ISC_TYPE_ISCLRU2000;
				/// i-scan UHF ID ISC.LRU3000 or ID ISC.LRU3500 (94)
				static const unsigned int ID_ISC_LRU3000 = FEDM_ISC_TYPE_ISCLRU3000;
				/// i-scan UHF ID ISC.LRU500_I_BD (0x01 95)
				static const unsigned int ID_LRU500_I_BD = FEDM_RDR_TYPE_LRU500_I_BD;
				/// i-scan UHF ID ISC.LRU500_I_POE (0x02 95)
				static const unsigned int ID_LRU500_I_POE = FEDM_RDR_TYPE_LRU500_I_POE;

				/// classic-pro ID CPR.M02 (80)
				static const unsigned int ID_CPRM02 = FEDM_ISC_TYPE_CPRM02;
				/// classic-pro ID CPR.02 (81)
				static const unsigned int ID_CPR02 = FEDM_ISC_TYPE_CPR02;
				/// classic-pro ID CPR40.xx-U (82)
				static const unsigned int ID_CPR40_XX_U = FEDM_ISC_TYPE_CPR40_XX_U;
				/// classic-pro ID CPR40.xx (83)
				static const unsigned int ID_CPR40_XX = FEDM_ISC_TYPE_CPR40_XX;
				/// classic-pro ID CPR50.xx (84)
				static const unsigned int ID_CPR50_XX = FEDM_ISC_TYPE_CPR50_XX;
				/// classic-pro ID CPR44.xx (85)
				static const unsigned int ID_CPR44_XX = FEDM_ISC_TYPE_CPR44_XX;
				/// classic-pro ID CPR30.xx (86)
				static const unsigned int ID_CPR30_XX = FEDM_ISC_TYPE_CPR30_XX;
				/// classic-pro ID CPR52.xx (87)
//				static const unsigned int ID_CPR52_XX = FEDM_ISC_TYPE_CPR52_XX;
				/// classic-pro ID CPR.04-USB (88)
//				static const unsigned int ID_CPR04_U = FEDM_ISC_TYPE_CPR04_U;
				/// classic-pro ID CPR46.xx (89)
				static const unsigned int ID_CPR46_XX = FEDM_ISC_TYPE_CPR46_XX;
				/// classic-pro ID CPR20.xx (110)
//				static const unsigned int ID_CPR20_XX = FEDM_ISC_TYPE_CPR20_XX;
				/// classic-pro ID CPR47.xx (111)
				static const unsigned int ID_CPR47_XX = FEDM_ISC_TYPE_CPR47_XX;
				/// classic-pro ID CPR60 (113)
				static const unsigned int ID_CPR60 = FEDM_ISC_TYPE_CPR60_XX;
				/// classic-pro ID CPR74 (114)
				static const unsigned int ID_CPR74 = FEDM_ISC_TYPE_CPR74;
				/// classic-pro ID CPR71 (115)
				static const unsigned int ID_CPR71 = FEDM_ISC_TYPE_CPR71;

				/// myAXXESS ID MAX50.xx (100)
				static const unsigned int ID_MAX50_XX = FEDM_ISC_TYPE_MAX50_XX;
				/// myAXXESS ID MAX.U1002xx (101)
				static const unsigned int ID_MAXU1002 = FEDM_ISC_TYPE_MAXU1002;
				/// myAXXESS ID MAX.U500_I (0x03 95)
				static const unsigned int ID_MAXU500_I = FEDM_RDR_TYPE_MAXU500_I;

				/// ID HyWEAR compact (140)
				static const unsigned int ID_HYWEAR_COMPACT = FEDM_TYPE_HYWEAR_COMPACT;
				/// ID HyWEAR compact xT (396)
				static const unsigned int ID_HYWEAR_COMPACT_XT = FEDM_TYPE_HYWEAR_COMPACT_XT;
				/// ID HyWEAR compact (652)
				static const unsigned int ID_HYWEAR_COMPACT_SR = FEDM_TYPE_HYWEAR_COMPACT_SR;
				/// ID ECCO+ (141)
				static const unsigned int ID_ECCO_PLUS = 141;
				/// ID ECCO Smart (142)
				//static const unsigned int ID_ECCO_SMART = 142;
				/// ID ECCO Smart HF-BLE (398)
				static const unsigned int ID_ECCO_SMART_HF_BLE = (FEDM_RDR_CLASS_ECCO_SMART | (0x01 << 8));
				/// ID ECCO Smart HF-BLE (398)
				static const unsigned int ID_ECCO_SMART_2D_HF_BLE = (FEDM_RDR_CLASS_ECCO_SMART | (0x02 << 8));
			};
		}
	}
}

#endif // !defined(_FEDM_CORE_READER_TYPES_H_INCLUDED_)
