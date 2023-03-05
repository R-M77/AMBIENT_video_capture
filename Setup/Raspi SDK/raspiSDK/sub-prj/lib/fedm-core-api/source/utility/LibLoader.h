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

#if !defined(_FEDM_CORE_UTILITY_LIB_LOADER_H_INCLUDED_)
#define _FEDM_CORE_UTILITY_LIB_LOADER_H_INCLUDED_

#include <stddef.h>

// the following include is for serial port support
// please define _FEDM_COM_SUPPORT with compiler option
// additionally, you must define _FEDM_WINDOWS or _FEDM_LINUX with compiler option
#ifdef _FEDM_COM_SUPPORT
#include "fecom.h"
#endif

// the following include is for USB support
// please define _FEDM_USB_SUPPORT with compiler option
// additionally, you must define _FEDM_WINDOWS or _FEDM_LINUX with compiler option
#ifdef _FEDM_USB_SUPPORT
#include "feusb.h"
#endif

// the following include is for TCP support
// please define _FEDM_TCP_SUPPORT with compiler option
// additionally, you must define _FEDM_WINDOWS or _FEDM_LINUX with compiler option
#ifdef _FEDM_TCP_SUPPORT
#include "fetcp.h"
#endif


namespace FEDM
{
	namespace Core
	{
		/// Namespace for utility classes
		namespace Utility
		{
			/// @brief Class providing functionality for loading libraries dynamically
			///
			class LibLoader
			{
			public:
				LibLoader();
				~LibLoader();

			protected:
#if !defined(_FEDM_SUPPORT_SLINK)
				void* GetFunctionPtr(void* pLib, const char* szFctName);
#endif

				// the following codelines are for serial port support
				// please define _FEDM_COM_SUPPORT with compiler option
#ifdef _FEDM_COM_SUPPORT
#if !defined(_FEDM_SUPPORT_SLINK)

			public:
				void* GetFeComFunction(unsigned int uiFct);

			protected:
				void* LoadFeCom();

			protected:
				struct _FEDM_FECOM_PTR
				{
					// function pointers for fecom library
					LPFN_FECOM_GET_DLL_VERSION		lpfnGetDLLVersion;
					LPFN_FECOM_GET_ERROR_TEXT		lpfnGetErrorText;
					LPFN_FECOM_GET_LAST_ERROR		lpfnGetLastError;
					LPFN_FECOM_DETECT_PORT			lpfnDetectPort;
					LPFN_FECOM_ADD_EVENT_HANDLER	lpfnAddEventHandler;
					LPFN_FECOM_DEL_EVENT_HANDLER	lpfnDelEventHandler;
					LPFN_FECOM_OPEN_PORT			lpfnOpenPort;
					LPFN_FECOM_CLOSE_PORT			lpfnClosePort;
					LPFN_FECOM_GET_PORT_LIST		lpfnGetPortList;
					LPFN_FECOM_GET_PORT_PARA		lpfnGetPortPara;
					LPFN_FECOM_SET_PORT_PARA		lpfnSetPortPara;
					LPFN_FECOM_DO_PORT_CMD			lpfnDoPortCmd;
					LPFN_FECOM_GET_PORT_HND			lpfnGetPortHnd;
					LPFN_FECOM_TRANSCEIVE			lpfnTransceive;
					LPFN_FECOM_TRANSMIT				lpfnTransmit;
					LPFN_FECOM_RECEIVE				lpfnReceive;

					// initialization
					_FEDM_FECOM_PTR() : lpfnGetDLLVersion(NULL),
						lpfnGetErrorText(NULL),
						lpfnGetLastError(NULL),
						lpfnDetectPort(NULL),
						lpfnAddEventHandler(NULL),
						lpfnDelEventHandler(NULL),
						lpfnOpenPort(NULL),
						lpfnClosePort(NULL),
						lpfnGetPortList(NULL),
						lpfnGetPortPara(NULL),
						lpfnSetPortPara(NULL),
						lpfnDoPortCmd(NULL),
						lpfnGetPortHnd(NULL),
						lpfnTransceive(NULL),
						lpfnTransmit(NULL),
						lpfnReceive(NULL)
					{}
				};
#endif // #if !defined(_FEDM_SUPPORT_SLINK)
#endif // #ifdef _FEDM_COM_SUPPORT


				// the following codelines are for USB support
				// please define _FEDM_USB_SUPPORT with compiler option
#ifdef _FEDM_USB_SUPPORT
#if !defined(_FEDM_SUPPORT_SLINK)

			public:
				void* GetFeUsbFunction(unsigned int uiFct);

			protected:
				void* LoadFeUsb();

			protected:
				struct _FEDM_FEUSB_PTR
				{
					// function pointers for feusb library
					LPFN_FEUSB_GET_DLL_VERSION		lpfnGetDLLVersion;
					LPFN_FEUSB_GET_DRV_VERSION		lpfnGetDrvVersion;
					LPFN_FEUSB_GET_ERROR_TEXT		lpfnGetErrorText;
					LPFN_FEUSB_GET_LAST_ERROR		lpfnGetLastError;
					LPFN_FEUSB_SCAN					lpfnScan;
					LPFN_FEUSB_SCAN_AND_OPEN		lpfnScanAndOpen;
					LPFN_FEUSB_GET_SCAN_LIST_PARA	lpfnGetScanListPara;
					LPFN_FEUSB_GET_SCAN_LIST_SIZE	lpfnGetScanListSize;
					LPFN_FEUSB_CLEAR_SCAN_LIST		lpfnClearScanList;
					LPFN_FEUSB_ADD_EVENT_HANDLER	lpfnAddEventHandler;
					LPFN_FEUSB_DEL_EVENT_HANDLER	lpfnDelEventHandler;
					LPFN_FEUSB_OPEN_DEVICE			lpfnOpenDevice;
					LPFN_FEUSB_CLOSE_DEVICE			lpfnCloseDevice;
					LPFN_FEUSB_IS_DEVICE_PRESENT	lpfnIsDevicePresent;
					LPFN_FEUSB_GET_DEVICE_LIST		lpfnGetDeviceList;
					LPFN_FEUSB_GET_DEVICE_PARA		lpfnGetDevicePara;
					LPFN_FEUSB_SET_DEVICE_PARA		lpfnSetDevicePara;
					LPFN_FEUSB_GET_DEVICE_HND		lpfnGetDeviceHnd;
					LPFN_FEUSB_TRANSCEIVE			lpfnTransceive;
					LPFN_FEUSB_TRANSMIT				lpfnTransmit;
					LPFN_FEUSB_RECEIVE				lpfnReceive;

					// initialization
					_FEDM_FEUSB_PTR() : lpfnGetDLLVersion(NULL),
						lpfnGetDrvVersion(NULL),
						lpfnGetErrorText(NULL),
						lpfnGetLastError(NULL),
						lpfnScan(NULL),
						lpfnScanAndOpen(NULL),
						lpfnGetScanListPara(NULL),
						lpfnGetScanListSize(NULL),
						lpfnClearScanList(NULL),
						lpfnAddEventHandler(NULL),
						lpfnDelEventHandler(NULL),
						lpfnOpenDevice(NULL),
						lpfnCloseDevice(NULL),
						lpfnIsDevicePresent(NULL),
						lpfnGetDeviceList(NULL),
						lpfnGetDevicePara(NULL),
						lpfnSetDevicePara(NULL),
						lpfnGetDeviceHnd(NULL),
						lpfnTransceive(NULL),
						lpfnTransmit(NULL),
						lpfnReceive(NULL)
					{}
				};
#endif // #if !defined(_FEDM_SUPPORT_SLINK)
#endif


				// the following codelines are for TCP support
				// please define _FEDM_TCP_SUPPORT with compiler option
#ifdef _FEDM_TCP_SUPPORT
#if !defined(_FEDM_SUPPORT_SLINK)

			public:
				void* GetFeTcpFunction(unsigned int uiFct);

			protected:
				void* LoadFeTcp();

			protected:
				struct _FEDM_FETCP_PTR
				{
					// function pointers for fetcp library
					LPFN_FETCP_GET_DLL_VERSION		lpfnGetDLLVersion;
					LPFN_FETCP_GET_ERROR_TEXT		lpfnGetErrorText;
					LPFN_FETCP_GET_LAST_ERROR		lpfnGetLastError;
					LPFN_FETCP_ADD_EVENT_HANDLER	lpfnAddEventHandler;
					LPFN_FETCP_DEL_EVENT_HANDLER	lpfnDelEventHandler;
					LPFN_FETCP_DETECT				lpfnDetect;
					LPFN_FETCP_CONNECT				lpfnConnect;
					LPFN_FETCP_DISCONNECT			lpfnDisConnect;
					LPFN_FETCP_GET_SOCKET_LIST		lpfnGetSocketList;
					LPFN_FETCP_GET_SOCKET_PARA		lpfnGetSocketPara;
					LPFN_FETCP_SET_SOCKET_PARA		lpfnSetSocketPara;
					LPFN_FETCP_GET_SOCKET_HND		lpfnGetSocketHnd;
					LPFN_FETCP_GET_SOCKET_STATE		lpfnGetSocketState;
					LPFN_FETCP_TRANSCEIVE			lpfnTransceive;
					LPFN_FETCP_TRANSMIT				lpfnTransmit;
					LPFN_FETCP_RECEIVE				lpfnReceive;

					// initialization
					_FEDM_FETCP_PTR() : lpfnGetDLLVersion(NULL),
						lpfnGetErrorText(NULL),
						lpfnGetLastError(NULL),
						lpfnAddEventHandler(NULL),
						lpfnDelEventHandler(NULL),
						lpfnDetect(NULL),
						lpfnConnect(NULL),
						lpfnDisConnect(NULL),
						lpfnGetSocketList(NULL),
						lpfnGetSocketPara(NULL),
						lpfnSetSocketPara(NULL),
						lpfnGetSocketHnd(NULL),
						lpfnGetSocketState(NULL),
						lpfnTransceive(NULL),
						lpfnTransmit(NULL),
						lpfnReceive(NULL)
					{}
				};
#endif // #if !defined(_FEDM_SUPPORT_SLINK)
#endif // #ifdef _FEDM_TCP_SUPPORT

			protected:
#ifdef _FEDM_COM_SUPPORT
				void* m_pFeComLib;		// pointer or handle to fecom
				void* m_pFeComPtrList;	// pointer to structure with function pointers of FECOM
#endif

#ifdef _FEDM_USB_SUPPORT
				void* m_pFeUsbLib;		// pointer or handle to feusb
				void* m_pFeUsbPtrList;	// pointer to structure with function pointers of FEUSB
#endif

#ifdef _FEDM_TCP_SUPPORT
				void* m_pFeTcpLib;		// pointer or handle to feusb
				void* m_pFeTcpPtrList;	// pointer to structure with function pointers of FETCP
#endif

			};
		}
	}
}


#endif // !defined(_FEDM_CORE_UTILITY_LIB_LOADER_H_INCLUDED_)
