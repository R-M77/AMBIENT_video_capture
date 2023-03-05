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


/**
This file includes all dependencies for the component FEDM
*/

#if !defined(_FEDM_ISC_CORE_API_H_INCLUDED_)
#define _FEDM_ISC_CORE_API_H_INCLUDED_


// header files of implementation (and old API)
#define _FEDM_NEW_API
#include "FedmIscCore.h"
#undef _FEDM_NEW_API

// header files of new API
#include "../source/Const.h"
#include "../source/ErrorCode.h"
#include "../source/ReaderType.h"
#include "../source/reader/ReaderModule.h"
#include "../source/reader/IPortGroup.h"
#include "../source/reader/ICommandGroup.h"
#include "../source/reader/IConfigGroup.h"
#include "../source/reader/IInfoGroup.h"
#include "../source/reader/IHmTableGroup.h"
#include "../source/reader/IBrmTableGroup.h"
#include "../source/reader/ILogGroup.h"
#if !defined(_FEDM_NO_FW_UPD_SUPPORT)
	#include "../source/reader/IFwUpdGroup.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER)
	#include "../source/reader/ITagGroup.h"
#endif
#include "../source/reader/IAsyncGroup.h"
#if !defined(_FEDM_NO_PD_SUPPORT) && !defined(_FEDM_NO_FU_SUPPORT)
	#include "../source/reader/IExtDeviceGroup.h"
#endif
#include "../source/reader/ReaderCommandPara.h"
#include "../source/reader/ReaderConfigPara.h"
#if !defined(_FEDM_NO_FU_SUPPORT)
	#include "../source/function_unit/FunctionUnitBase.h"
	#include "../source/function_unit/HFAntennaMultiplexer.h"
	#include "../source/function_unit/HFDynamicAntennaTuner.h"
	#include "../source/function_unit/UHFAntennaMultiplexer.h"
#endif
#if !defined(_FEDM_NO_PD_SUPPORT)
	#include "../source/peripheral_devices/GatePeopleCounter.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER)
	#include "../source/tag_handler/TagHandler_Includes.h"
#endif
#include "../source/utility/LibInfo.h"
#include "../source/utility/HexConvert.h"
#include "../source/utility/UsbManager.h"
#include "../source/utility/LibLoader.h"
#include "../source/utility/DateTime.h"
#include "../source/utility/OutputSetting.h"

#endif // _FEDM_ISC_CORE_API_H_INCLUDED_
