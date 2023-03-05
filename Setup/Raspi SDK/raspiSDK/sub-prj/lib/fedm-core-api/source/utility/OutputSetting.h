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

#if !defined(_FEDM_CORE_UTILITY_OUTPUT_SETTING_H_INCLUDED_)
#define _FEDM_CORE_UTILITY_OUTPUT_SETTING_H_INCLUDED_

#include "../source/FEDM.h"

namespace FEDM
{
	namespace Core
	{
		/// Namespace for utility classes
		namespace Utility
		{
			/** @brief Class providing setting information of a digital hardware output
			*
			* <b>Description</b><br>
			*/ 
			class _FEDM_ISC_CORE_EXT_CLASS OutputSetting
			{

			public:
				/// @brief Constucts an invalid OutputSetting object
				OutputSetting();

				/** @brief Constructor to be preferred to
				 *
				 * @param index Number of Output
				 * @param type Type of the output (Digital Output, Relay, LED)
				 * @param mode Mode of output (On, Off, Flash)
				 * @param frequency Frequency of activation
				 * @param holdTime Activation time for the selected output in steps of 100ms.<br>
				 * Set 1 for 100ms, 2 for 200ms and so forth<br>
				 *
				 * <b>Note:</b><br>
				 * <b>For more information about applicable settings, see Reader's System Manual</b>
				 */
				OutputSetting(int index, int type, int mode, int frequency, int holdTime);

				~OutputSetting() { }

				/** @brief Returns true, if the object is valid
				*
				* <b>Description</b><br>
				* An output object is valid, when the outIndex is greater than zero.<br>
				* All other output parameters are not validated and must be conform to the Reader's System Manual.<br>
				* If one of these parameters is not conform, then the [0x72] Set Output command will be responded with the status byte 0x11 (Parameter range error).
				*/
				bool isValid() const { return m_index >= 0; }

				/** @brief Number of Output*/
				int m_index;
				/** @brief Type of the output (Digital Output, Relay, LED)*/
				int m_type;
				/** @brief Mode of output (On, Off, Flash)*/
				int m_mode;
				/** @brief Frequency of activation*/
				int m_frequency;
				/** @brief Activation time for the selected output in steps of 100ms*/
				int m_holdTime;
			};
		}
	}
}


#endif // !defined(_FEDM_CORE_UTILITY_OUTPUT_SETTING_H_INCLUDED_)
