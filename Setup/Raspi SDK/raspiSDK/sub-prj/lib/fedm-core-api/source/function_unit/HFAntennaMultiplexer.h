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

#if !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_HF_ANTENNA_MULTIPLEXER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_EXT_DEVICE_HF_ANTENNA_MULTIPLEXER_H_INCLUDED_

#if !defined(_FEDM_NO_FU_SUPPORT)

#include "../source/FEDM.h"
#include "FunctionUnitBase.h"

class FEDM_ISCReaderModule;

namespace FEDM
{
	namespace Core
	{
		class IExtDeviceGroup;
		class ReaderModule;

		namespace ExternalDevice
		{
			/// Class for external connected Function-Unit of type HF Antenna Multiplexer (ID ISC.MUX)
			class _FEDM_ISC_CORE_EXT_CLASS HFAntennaMultiplexer : public FunctionUnitBase
			{
				friend class FEDM::Core::IExtDeviceGroup;

			// public functions
			public:

				/// Command [0xBF][0xDE] CPU Reset
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command.
				int CPUReset();
					
				/// Command  [0xBF][0xDF] Software Version
				///
				/// @param[out] ucSwMainRev
				/// @param[out] ucSwSubRev
				/// @param[out] ucSwType
				/// @param[out] ucHwRev
				/// @param[out] ucDIP
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int GetSoftwareVersion(	unsigned char& ucSwMainRev, 
										unsigned char& ucSwSubRev, 
										unsigned char& ucSwType, 
										unsigned char& ucHwRev, 
										unsigned char& ucDIP);

				/// Command  [0xBF][0xDD] Channel Select
				///
				/// @param[in] ucIn1
				/// @param[in] ucIn2
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int SelectChannel(unsigned char ucIn1, unsigned char ucIn2);
					
				/// Command [0xBF][0xDC] Detect
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command.
				int Detect();

			// protected functions
			protected:

				// constructor
				HFAntennaMultiplexer(ReaderModule* pReader, unsigned char ucCascadeLevel);

				// destructor
				virtual ~HFAntennaMultiplexer();

			};
		}
	}
}


#endif // #if !defined(_FEDM_NO_FU_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_HF_ANTENNA_MULTIPLEXER_H_INCLUDED_)
