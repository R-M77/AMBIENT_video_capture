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

#if !defined(_FEDM_CORE_ISCAN_FWUPD_LISTENER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_FWUPD_LISTENER_H_INCLUDED_

#if !defined(_FEDM_NO_FW_UPD_SUPPORT)

#include <string>
#include "../source/FEDM.h"


namespace FEDM
{
	namespace Core
	{
		/// Abstract class for providing a listener interface for application classes, handling firmware update events
		class _FEDM_ISC_CORE_EXT_CLASS IFwUpdListener
		{
		public:
				
			/** @brief Is called, when a new update related message is available
			*
			* @param[in] iMsgMode message mode to control the content of the method parameters
			* @param[in] iErrorCode error code. See [ErrorCode](@ref FEDM::Core::ErrorCode)
			* @param[in] uiProgressCounter progress counter, started by zero
			* @param[in] uiCounterLimit limit of progress counter
			* @param[in] sMessage message text
			*
			* <b>Description</b><br>
			* This listener method sends status information of the currently running firmware update process.<br>
			* The message can contain different content and is controlled by the parameter iMsgMode:<br>
			* 0 - signals only message text - Example: <code>OnNewFwUpdMessage(0, 0, 0, 0, "message text")</code><br>
			* 1 - signals progress counter (3), progress range (510) and message text - Example: <code>OnNewFwUpdMessage(1, 0, 3, 510, "message text")</code><br>
			* 2 - signals new limit of progress range (set to new value); no message text - Example: <code>OnNewFwUpdMessage(2, 0, 0, 510, NULL)</code><br>
			* 3 - signals end of update; no message text - Example: <code>OnNewFwUpdMessage(3, 0, 0, 0, NULL)</code><br>
			* 4 - signals error code and message text. After this notification, the update process is canceled. - Example: <code>OnNewFwUpdMessage(4, error code, 0, 0, "error text")</code><br>
			*/ 
			virtual void OnNewFwUpdMessage(int iMsgMode, int iErrorCode, unsigned int uiProgressCounter, unsigned int uiCounterLimit, const std::string & sMessage)=0;
		};
	}
}

#endif // !defined(_FEDM_NO_FW_UPD_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_FWUPD_LISTENER_H_INCLUDED_)
