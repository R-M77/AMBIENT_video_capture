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

#if !defined(_FEDM_CORE_UTILITY_LIB_INFO_H_INCLUDED_)
#define _FEDM_CORE_UTILITY_LIB_INFO_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"

namespace FEDM
{
	namespace Core
	{
		/// Namespace for utility classes
		namespace Utility
		{
			/// @brief Class providing library information
			///
			/// <b>Description</b><br>
			/// All methods of this class are static.
			class _FEDM_ISC_CORE_EXT_CLASS LibInfo
			{
			public:

				/// @brief Check version numbers of dependent libraries
				///
				/// @param[out] sMessage %Error message 
				/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
				///
				/// <b>Description</b><br>
				/// This method checks all dependent libraries for correct version numbers. In case of an error, an error message is returned.
				static int EvalLibDependencies(std::string& sMessage);

				/// @brief Query of version numbers of dependent libraries FECOM, FETCP, FEUSB, FEISC, FEFU and FETCL
				///
				/// @return String with version numbers
				///
				/// <b>Description</b><br>
				/// This method builds a string with version information from dependent libraries.
				/// Useful for logging, debugging and support requests.
				static std::string GetDependentLibVersions();
			};
		}
	}
}


#endif // !defined(_FEDM_CORE_UTILITY_LIB_INFO_H_INCLUDED_)
