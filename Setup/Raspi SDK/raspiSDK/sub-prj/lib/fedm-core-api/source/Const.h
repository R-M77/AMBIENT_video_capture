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

#if !defined(_FEDM_CORE_CONST_H_INCLUDED_)
#define _FEDM_CORE_CONST_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"

namespace FEDM
{
	namespace Core
	{
		/// Namespace for general constants
		namespace Const
		{
			/// Version Number of the library FedmIscCore
			_FEDM_ISC_CORE_EXT_CLASS extern const std::string LIB_VERSION;

			/// Constants for UHF Regions
			class _FEDM_ISC_CORE_EXT_CLASS UhfRegion
			{
			public:
					
				/// @brief Return a text according the given status value
				///
				/// @param[in] uiRegion Region code of [EU](@ref FEDM::Core::Const::UhfRegion::EU) or [FCC](@ref FEDM::Core::Const::UhfRegion::FCC)
				/// @return string with region name
				///
				/// <b>Description</b><br>
				static std::string GetRegionName(unsigned int uiRegion);

				/// Constants for EU sub regions
				class _FEDM_ISC_CORE_EXT_CLASS EU
				{
				public:
					/// constant for EU Region Europe
					static const unsigned int EUROPE = 0x06;
					/// constant for EU Region Asia or Oceania
					static const unsigned int ASIA_OCEANIA = 0x16;
					/// constant for EU Region Russia
					static const unsigned int RUSSIA = 0x26;
					/// constant for EU Region Africa
					static const unsigned int AFRICA = 0x36;
					/// constant for EU Region India
					static const unsigned int INDIA = 0x46;
					/// constant for EU Region Morocco
					static const unsigned int MOROCCO = 0x56;
					/// constant for all other EU Regions with manual frequency settings (see System Manual of Reader)
					static const unsigned int MANUAL = 0xFE;
				};

				/// Constants for FCC sub regions
				class _FEDM_ISC_CORE_EXT_CLASS FCC
				{
				public:
					/// constant for FCC Region USA
					static const unsigned int USA = 0x04;
					/// constant for FCC Region China
					static const unsigned int CHINA = 0x14;
					/// constant for FCC Region Australia or New Zealand
					static const unsigned int AUSTRALIA_NEW_ZEALAND = 0x24;
					/// constant for FCC Region Brazil
					static const unsigned int BRAZIL = 0x34;
					/// constant for FCC Region Israel
					static const unsigned int ISRAEL = 0x44;
					/// constant for FCC Region Japan
					static const unsigned int JAPAN = 0x54;
					/// constant for FCC Region Malaysia
					static const unsigned int MALAYSIA = 0x64;
					/// constant for FCC Region Korea
					static const unsigned int KOREA = 0x74;
					/// constant for all other FCC Regions with manual frequency settings (see System Manual of Reader)
					static const unsigned int MANUAL = 0xFF;
				};
			};
		}
	}
}

#endif // _FEDM_CORE_CONST_H_INCLUDED_
