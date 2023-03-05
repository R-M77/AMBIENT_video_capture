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

#if !defined(_FEDM_CORE_ISCAN_INVENTORY_LISTENER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_INVENTORY_LISTENER_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "ITagGroup.h"


namespace FEDM
{
	namespace Core
	{
		/// Abstract class for providing a listener interface for application classes, handling asynchronous Inventory
		class _FEDM_ISC_CORE_EXT_CLASS IInventoryListener
		{
		public:
#ifdef _FEDM_TAG_HANDLER
			/// @brief Is called, when Reader is working in Host Mode and sends asynchronously the response data of an Inventory
			///
			/// @param[in] iError error code (< 0) or OK (=0)
			/// @param[in] TagList list with Tags from asynchonous called Inventory; see [ITagGroup::TH_LIST](@ref ITagGroup::TH_LIST)
			///
			/// If iError=0, the response data are collected in the TagHandler objects in the Tag-List
			virtual void OnNewTag(const int iError, const ITagGroup::TH_LIST& TagList)=0;
#endif
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_INVENTORY_LISTENER_H_INCLUDED_)
