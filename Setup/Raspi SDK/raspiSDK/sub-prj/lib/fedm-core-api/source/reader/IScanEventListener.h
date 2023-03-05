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

#if !defined(_FEDM_CORE_SCAN_EVENT_LISTENER_H_INCLUDED_)
#define _FEDM_CORE_SCAN_EVENT_LISTENER_H_INCLUDED_

#include <vector>
#include "../source/FEDM.h"
#include "IBrmTableGroup.h"
#include "../source/utility/OutputSetting.h"

using namespace FEDM::Core;


namespace FEDM
{
	namespace Core
	{
		/// @brief Abstract class for providing a listener interface for application classes, handling asynchronous Scanner events
		class _FEDM_ISC_CORE_EXT_CLASS IScanEventListener
		{
		public:

			/** @brief Listener method for data comming with Scanner event.
			 *
			 * @param[in] scanData table item with received data
			 * @param[out] vOutputSets settings for output signalization to be returned to Scanner
			 */
			virtual void OnNewScanEvent(const IBrmTableGroup::BrmTableItem & scanData, std::vector<Utility::OutputSetting> & vOutputSets)=0;
		};
	}
}

#endif // !defined(_FEDM_CORE_SCAN_EVENT_LISTENER_H_INCLUDED_)
