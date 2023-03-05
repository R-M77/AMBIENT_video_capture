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

#if !defined(_FEDM_CORE_ISCAN_NOTIFICATION_LISTENER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_NOTIFICATION_LISTENER_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "IInfoGroup.h"


namespace FEDM
{
	namespace Core
	{
		/// Abstract class for providing a listener interface for application classes, handling notification mode data
		class _FEDM_ISC_CORE_EXT_CLASS INotificationListener
		{
		public:
			/// @brief Is called, when Reader is working in Notification-Mode and sends a notification with Transponder data
			///
			/// @param[in] iError error code (< 0) or OK (=0) or Status Byte (>0) from notification protocol
			/// @param[in] sRemoteIP IP-Address of the Reader, which sent the notification
			/// @param[in] uiPortNumber TCP-Port, which receives the notification
			///
			/// If iError=0, the response data are collected in the internal Buffered Read Mode Table and must be requested gradually with IBrmTableGroup::GetItemByIndex()
			virtual void OnNewNotification(			int iError,
													std::string sRemoteIP,
													unsigned int uiPortNumber)=0;

			/// @brief Is called, when Reader is working in Notification-Mode and sends a notification with Diagnostic data (Keep-Alive option is activated)
			///
			/// @param[in] iError error code (< 0) or OK (=0)
			/// @param[in] pDiagnosticData Diagnostic data, if iError=0
			/// @param[in] sRemoteIP IP-Address of the Reader, which sent the notification
			/// @param[in] uiPortNumber TCP-Port, which receives the notification
			virtual void OnNewReaderDiagnostic(		int iError,
													IInfoGroup::ReaderDiagnostic* pDiagnosticData,
													std::string sRemoteIP,
													unsigned int uiPortNumber)=0;

			/// @brief Is called, when Reader is working in Notification-Mode and sends a notification with Input data
			///
			/// @param[in] iError error code (< 0) or OK (=0)
			/// @param[in] ucInput field with flags for each input
			/// @param[in] sRemoteIP IP-Address of the Reader, which sent the notification
			/// @param[in] uiPortNumber TCP-Port, which receives the notification
			///
			/// If iError=0, the response data are collected in the internal Buffered Read Mode Table and must be requested gradually with IBrmTableGroup::GetItemByIndex()
			virtual void OnNewInputEvent(			int iError,
													unsigned char ucInput,
													std::string sRemoteIP,
													unsigned int uiPortNumber)=0;

			/// @brief Is called, when Reader is working in Notification-Mode and sends a notification with People-Counter counter values
			///
			/// @param[in] iError error code (< 0) or OK (=0)
			/// @param[in] uiCounter1 Counter 1 value of People-Counter, if iError=0
			/// @param[in] uiCounter2 Counter 2 value of People-Counter, if iError=0
			/// @param[in] uiCounter3 Counter 3 value of People-Counter, if iError=0
			/// @param[in] uiCounter4 Counter 4 value of People-Counter, if iError=0
			/// @param[in] sRemoteIP IP-Address of the Reader, which sent the notification
			/// @param[in] uiPortNumber TCP-Port, which receives the notification
			/// @param[in] ucBusAddress Bus-Address of the People-Counter, which generates the counter event in the Reader
			virtual void OnNewPeopleCounterEvent(	int iError,
													unsigned int uiCounter1,
													unsigned int uiCounter2,
													unsigned int uiCounter3,
													unsigned int uiCounter4,
													std::string sRemoteIP,
													unsigned int uiPortNumber,
													unsigned char ucBusAddress)=0;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_NOTIFICATION_LISTENER_H_INCLUDED_)
