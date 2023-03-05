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

#if !defined(_FEDM_CORE_ISCAN_LOG_LISTENER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_LOG_LISTENER_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"


namespace FEDM
{
	namespace Core
	{
		/// Abstract class for providing a listener interface for application classes, handling Log Events
		class _FEDM_ISC_CORE_EXT_CLASS ILogListener
		{
		public:
			/// @brief Is called, when a new Reader protocol is sent or received
			///
			/// @param[in] uiDirection 1: outgoing protocol; 2: incomming protocol
			/// @param[in] sLogText String with date and time and protocol
			///
			/// <b>Description</b><br>
			/// 
			virtual void OnNewReaderProtocol(unsigned int uiDirection, std::string sLogText)=0;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_LOG_LISTENER_H_INCLUDED_)
