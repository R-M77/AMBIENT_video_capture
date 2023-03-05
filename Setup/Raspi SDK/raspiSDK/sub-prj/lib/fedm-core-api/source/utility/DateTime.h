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

#if !defined(_FEDM_CORE_UTILITY_DATE_TIME_H_INCLUDED_)
#define _FEDM_CORE_UTILITY_DATE_TIME_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"

namespace FEDM
{
	namespace Core
	{
		/// Namespace for utility classes
		namespace Utility
		{
			/// @brief Class providing date and time information
			///
			/// <b>Description</b><br>
			/// 
			class _FEDM_ISC_CORE_EXT_CLASS DateTime
			{

			public:
				/// @brief Constucts a DateTime object with invalid date and time values
				DateTime();

				/// @brief Constucts a DateTime object with invalid date values
				DateTime(int hour, int minute, int second, int milliSecond);

				/// @brief Constucts a DateTime object with complete valid values
				DateTime(int year, int month, int day, int hour, int minute, int second, int milliSecond);

				~DateTime() { }

				/// @brief Set date and time invalid
				void clear(void);

				/// @brief Returns true, if all date and time values are valid
				bool isValid() const;

				/// @brief Returns true, if all time values are valid
				bool isValidTime() const;

				/// @brief Returns true, if all date values are valid
				bool isValidDate() const;

				/// @brief Returns a date and/or time string according to ISO 8601
				std::string toString(bool withDate, bool withTime) const;

				DateTime &operator=  (const DateTime & other);
				bool      operator== (const DateTime & other) const;

				/// @brief Returns a DateTime object with current local date and time
				///
				/// <b>Description</b><br>
				/// This function can be used, to copy the PC date and time to a reader:
				/// ReaderModule.SetSystemClock( FEDM::Core::Utility::DateTime::currentDateTime() );
				static DateTime currentDateTime(void);

				int m_year;
				int m_month;
				int m_day;
				int m_hour;
				int m_minute;
				int m_second;
				int m_milliSecond;
			};
		}
	}
}


#endif // !defined(_FEDM_CORE_UTILITY_DATE_TIME_H_INCLUDED_)
