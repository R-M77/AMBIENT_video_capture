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


#if !defined(_FEDM_ISC_CORE_H_INCLUDED_)
#define _FEDM_ISC_CORE_H_INCLUDED_


#if defined(__APPLE__)
	// limitations for Mac OSX
	#define _FEDM_NO_COM_SUPPORT
	#define _FEDM_NO_FU_SUPPORT
	#define _FEDM_NO_PD_SUPPORT
#endif

#if defined(__ANDROID__)
	// limitations for Android
	#define _FEDM_NO_FU_SUPPORT
	#define _FEDM_NO_PD_SUPPORT
#endif

#if !defined(_FEDM_NO_XML_SUPPORT)
  #if !defined(_FEDM_XML_SUPPORT)
	#define _FEDM_XML_SUPPORT
  #endif
#endif

#if !defined(_FEDM_NO_DLL)
	#define _FEDM_DLL
#endif

#if !defined(_FEDM_NO_COM_SUPPORT)
  #if !defined(_FEDM_COM_SUPPORT)
	#define _FEDM_COM_SUPPORT
  #endif
#endif

#if !defined(_FEDM_NO_USB_SUPPORT)
  #if !defined(_FEDM_USB_SUPPORT)
	#define _FEDM_USB_SUPPORT
  #endif
#endif

#if !defined(_FEDM_NO_TCP_SUPPORT)
  #if !defined(_FEDM_TCP_SUPPORT)
	#define _FEDM_TCP_SUPPORT
  #endif
#endif

#if !defined(_FEDM_NO_TAG_HANDLER)
  #if !defined(_FEDM_TAG_HANDLER)
	#define _FEDM_TAG_HANDLER
  #endif
#endif

#if !defined(_FEDM_NO_FU_SUPPORT)
  #if !defined(_FEDM_FU_SUPPORT)
	#define _FEDM_FU_SUPPORT
  #endif
#endif

#if defined(_MSC_VER)
  #if !defined(_FEDM_WINDOWS)
	#define _FEDM_WINDOWS
  #endif
#elif  defined(__BORLANDC__)
  #if !defined(_FEDM_WINDOWS)
	#define _FEDM_WINDOWS
  #endif
#else
  #if !defined(_FEDM_LINUX)
	#define _FEDM_LINUX
  #endif
#endif


// header files of implementation (and old API)
#include "../source/FEDM.h"
#include "../source/FEDM_Base.h"
#include "../source/FEDM_DataBase.h"
#include "../source/FEDM_Functions.h"
#include "../source/FEDM_Xml.h"
#include "../source/FEDM_XmlBase.h"
#include "../source/FEDM_XmlReaderCfgDataModul.h"
#include "../source/FEDM_XmlReaderCfgProfileModul.h"
#include "../source/i_scan/FEDM_ISC.h"
#include "../source/i_scan/FEDM_ISCReaderInfo.h"
#include "../source/i_scan/FEDM_ISCReaderDiagnostic.h"
#include "../source/i_scan/FEDM_ISCReaderID.h"
#include "../source/i_scan/FEDM_ISOTabItem.h"
#include "../source/i_scan/FEDM_BRMTabItem.h"
#include "../source/i_scan/FEDM_ISCReader.h"
#include "../source/i_scan/FEDM_ISCReaderModule.h"
#include "../source/i_scan/FEDM_ISCReaderConfig.h"
#include "../source/i_scan/FEDM_ISO_IEC_7816_6_ICManufacturerRegistration.h"
#include "../source/i_scan/utility/FedmIscReport_ReaderInfo.h"
#include "../source/i_scan/utility/FedmIscReport_ReaderDiagnostic.h"
#include "../source/i_scan/utility/FedmMisc.h"
#if !defined(_FEDM_NO_PD_SUPPORT)
	#include "../source/i_scan/peripheral_devices/FedmIscPeripheralDevice.h"
	#include "../source/i_scan/peripheral_devices/FedmIscPeopleCounter.h"
	#include "../source/i_scan/peripheral_devices/FedmIscExternalIO.h"
	#include "../source/i_scan/peripheral_devices/FedmIscLedController.h"
#endif
#if !defined(_FEDM_NO_FU_SUPPORT)
	#include "../source/i_scan/function_unit/FEDM_ISCFunctionUnit.h"
	#include "../source/i_scan/function_unit/FEDM_ISCFunctionUnitID.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER)
	#include "../source/i_scan/tag_handler/FedmIscTagHandler_Includes.h"
#endif // #if !defined(_FEDM_NO_TAG_HANDLER)

#if !defined(_FEDM_NEW_API)
	using namespace CoreImpl;
#endif

#endif // _FEDM_ISC_CORE_H_INCLUDED_
