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

#if !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_GATE_PEOPLE_COUNTER_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_EXT_DEVICE_GATE_PEOPLE_COUNTER_H_INCLUDED_

#if !defined(_FEDM_NO_PD_SUPPORT)

#include "../source/FEDM.h"

class FedmIscPeopleCounter;

namespace FEDM
{
	namespace Core
	{
		class IExtDeviceGroup;

		namespace ExternalDevice
		{
			/// Class for the IDENTIFICATION Gate People Counter.<br>
			class _FEDM_ISC_CORE_EXT_CLASS GatePeopleCounter
			{
				friend class FEDM::Core::IExtDeviceGroup;

			public:
				/// @brief Structure definition of output settings.
				///
				/// The hold time is in steps of 100ms, e.g. 10: 10x100ms = 1s.<br>
				/// The range for each time is 0...65535.<br>
				/// If the hold time is zero, the output is not set.<br>
				/// If the hold time is 65535, the output is set permanently.
				typedef struct Outputs
				{
					/// Index of the output (starting with 1)
					unsigned char	ucNumber;

					/// Type of the output (digital output, LED, buzzer)
					unsigned char	ucType;

					/// Mode of the output (unchanged, on, off, flash)
					unsigned char	ucMode;

					/// Flash frequency of output (1, 2, 4, 8 [Hz])
					unsigned char	ucFrequency;

					/// The hold time of the output state
					unsigned int	uiHoldTime;		

					Outputs() :	ucNumber(0),
									ucType(0),
									ucMode(0),
									ucFrequency(0),
									uiHoldTime(0)
									{}
				} Outputs;

				/// @brief Method to set multiple outputs
				///
				/// @param[in] pOutArray array of output settings
				/// @param[in] iOutSize  size of that array
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				int SetOutputs(Outputs *pOutArray, int iOutSize);

				/// @brief Method to request the counter values
				///
				/// @param[out] uiRadar1_Counter1 Counter value of Counter 1 at Radar Detector 1
				/// @param[out] uiRadar1_Counter2 Counter value of Counter 2 at Radar Detector 1
				/// @param[out] uiRadar2_Counter1 Counter value of Counter 1 at Radar Detector 2
				/// @param[out] uiRadar2_Counter2 Counter value of Counter 2 at Radar Detector 2
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Protocol traffic is executed with this method.
				/// This communication method can be used with all port drivers.
				int GetCounterValues(unsigned int& uiRadar1_Counter1, unsigned int& uiRadar1_Counter2, unsigned int& uiRadar2_Counter1, unsigned int& uiRadar2_Counter2);
				
				/// @brief Method to set the counter values
				///
				/// @param[in] uiRadar1_Counter1 Counter value for Counter 1 at Radar Detector 1
				/// @param[in] uiRadar1_Counter2 Counter value for Counter 2 at Radar Detector 1
				/// @param[in] uiRadar2_Counter1 Counter value for Counter 1 at Radar Detector 2
				/// @param[in] uiRadar2_Counter2 Counter value for Counter 2 at Radar Detector 2
				/// @return 
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
				///
				/// <b>Description</b><br>
				/// Protocol traffic is executed with this method.
				/// This communication method can be used with all port drivers.
				int SetCounterValues(unsigned int uiRadar1_Counter1, unsigned int uiRadar1_Counter2, unsigned int uiRadar2_Counter1, unsigned int uiRadar2_Counter2);


				/// @brief Constant for type \"digital output\"
				///
				static const unsigned char TYPE_OUTPUT = 0;

				/// @brief Constant for type \"LED\"
				///
				static const unsigned char TYPE_LED = 1;

				/// @brief Constant for type \"buzzer\"
				///
				static const unsigned char TYPE_BUZZER = 2;


				/// @brief Constant for mode \"unchanged\"
				///
				static const unsigned char MODE_UNCHANGED = 0;

				/// @brief Constant for mode \"on\"
				///
				static const unsigned char MODE_ON = 0;

				/// @brief Constant for mode \"off\"
				///
				static const unsigned char MODE_OFF = 0;

				/// @brief Constant for mode \"flash\"
				///
				static const unsigned char MODE_FLASH = 0;


				/// @brief Constant for flash frequency 1Hz
				///
				static const unsigned char FLASH_1HZ = 3;

				/// @brief Constant for flash frequency 2Hz
				///
				static const unsigned char FLASH_2HZ = 2;

				/// @brief Constant for flash frequency 4Hz
				///
				static const unsigned char FLASH_4HZ = 1;

				/// @brief Constant for flash frequency 8Hz
				///
				static const unsigned char FLASH_8HZ = 0;

			protected:

				// constructor
				GatePeopleCounter(FedmIscPeopleCounter* pImpl);
				// destructor
				virtual ~GatePeopleCounter();

			private:

				FedmIscPeopleCounter* m_pImpl;
			};
		}
	}
}

#endif // #if !defined(_FEDM_NO_PD_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_GATE_PEOPLE_COUNTER_H_INCLUDED_)
