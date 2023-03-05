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

#if !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_HF_DYNAMIC_ANTENNA_TUNER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_EXT_DEVICE_HF_DYNAMIC_ANTENNA_TUNER_H_INCLUDED_

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
			/// Class for external connected Function-Unit of type HF Dynamic Antenna Tuner (ID ISC.DAT)
			class _FEDM_ISC_CORE_EXT_CLASS HFDynamicAntennaTuner : public FunctionUnitBase
			{
				friend class FEDM::Core::IExtDeviceGroup;

			// public functions
			public:

				/// Command [0xBF][0xC0] Software Version
				///
				/// @param[out] ucSwMainRev
				/// @param[out] ucSwSubRev
				/// @param[out] ucSwType
				/// @param[out] ucHwRev
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int GetSoftwareVersion(	unsigned char& ucSwMainRev, 
										unsigned char& ucSwSubRev, 
										unsigned char& ucSwType, 
										unsigned char& ucHwRev);

				/// Command [0xBF][0xC1] CPU Reset
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command.
				int CPUReset();

				/// Command [0xBF][0xC2] Set Capacities
				///
				/// @param[in] ucCap1
				/// @param[in] ucCap2
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int SetCapacities(unsigned char ucCap1, unsigned char ucCap2);

				/// Command [0xBF][0xC3] Get Antenna Values
				///
				/// @param[out] ucCap1
				/// @param[out] ucCap2
				/// @param[out] uiR
				/// @param[out] ucPhi
				/// @param[out] ucTuningStatus
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int GetValues(	unsigned char& ucCap1, 
								unsigned char& ucCap2, 
								unsigned int& uiR, 
								unsigned char& ucPhi, 
								unsigned char& ucTuningStatus);

				/// Command [0xBF][0xC4] Set Outputs
				///
				/// @param[in] ucOut
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int SetOutput(unsigned char ucOut);

				/// Command [0xBF][0xC5] Re-Tuning
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command.
				int ReTuning();

				/// Command [0xBF][0xC6] Start Tuning
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command.
				int StartTuning();

				/// Command [0xBF][0xC9] Detect
				///
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command.
				int Detect();

				/// Command [0xBF][0xCA] Set Address
				///
				/// @param[in] ucNewAdr
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int SetAddress(unsigned char ucNewAdr);

				/// Command [0xBF][0xCB] Set Mode
				///
				/// @param[in] ucMode
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// NOTE: Refer to the System Manual for HF Function Unit (H30701-xe-ID-B) to get detailed information about the command and its parameters.
				int SetMode(unsigned char ucMode);

			// protected functions
			protected:

				// constructor
				HFDynamicAntennaTuner(ReaderModule* pReader, unsigned char ucCascadeLevel);

				// destructor
				virtual ~HFDynamicAntennaTuner();

			};
		}
	}
}


#endif // #if !defined(_FEDM_NO_FU_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_HF_DYNAMIC_ANTENNA_TUNER_H_INCLUDED_)
