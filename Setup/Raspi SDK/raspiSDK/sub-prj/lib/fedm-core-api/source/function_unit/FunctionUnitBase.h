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

#if !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_FUNCTION_UNIT_BASE_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_EXT_DEVICE_FUNCTION_UNIT_BASE_H_INCLUDED_

#if !defined(_FEDM_NO_FU_SUPPORT)

#include <map>
#include <string>
#include "../source/FEDM.h"

class FEDM_ISCFunctionUnit;


namespace FEDM
{
	namespace Core
	{
		class IExtDeviceGroup;
		class ReaderModule;

		/// Namespace for external connected Devices, like Gate People Counter, Antenna Multiplexer or Antenna Tuner
		namespace ExternalDevice
		{
			/// Base class for external connected Function-Units (like Antenna Multiplexer or Antenna Tuner)
			class _FEDM_ISC_CORE_EXT_CLASS FunctionUnitBase
			{
				friend class FEDM::Core::IExtDeviceGroup;

			public:
					
				/// type definition for a map iterator, collecting Function-Unit objects
				//typedef std::map<unsigned int, FunctionUnitBase*>::const_iterator	FU_LIST_ITOR;

			// public functions
			public:

				/// @brief Get the last error code
				///
				int GetLastError();
					
				/// @brief Get the status byte of the last communication
				///
				unsigned char GetLastStatus();
					
				/// @brief Get status text
				///
				std::string GetStatusText(unsigned char ucStatus);
					
				/// @brief Request the type of Function-Unit
				///
				int GetType();

				/// @brief Method to add a new Function-Unit as a child
				///
				/// @param[in] uiOutputNo Number of the output, where the Function-Unit is connected
				/// @param[in] uiFunctionUnitType Type of Function-Unit ([TYPE_HF_MULTIPLEXER](@ref FunctionUnitBase::TYPE_HF_MULTIPLEXER), [TYPE_HF_DYNAMIC_ANTENNA_TUNER](@ref FunctionUnitBase::TYPE_HF_DYNAMIC_ANTENNA_TUNER), [TYPE_UHF_MULTIPLEXER](@ref FunctionUnitBase::TYPE_UHF_MULTIPLEXER))
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// This method creates a new Function-Unit of type uiFunctionUnitType and adds this object to the internal child list.<br>
				/// The cascade level is automatically set.<br>
				/// Use [GetChild](@ref FunctionUnitBase::GetChild) to request the new created Function-Unit object.
				int AddChild(unsigned int uiOutputNo, unsigned int uiFunctionUnitType);

				/// @brief Method to remove a Function-Unit object from the internal child list
				///
				/// @param[in] uiOutputNo Number of the output, where the Function-Unit is connected
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// This method removes a Function-Unit object from the internal child list and deletes this object (and all Function-Unit objects in its child list).<br>
				int DeleteChild(unsigned int uiOutputNo);

				/// @brief Method to remove all Function-Unit objects from the internal child list
				///
				/// @return
				/// -   0 if OK
				/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
				///
				/// <b>Description</b><br>
				/// This method removes all Function-Unit object from the internal child list, deletes these objects (and all Function-Unit objects in each child list).<br>
				int DeleteChildList();

				/// @brief Method to return the number of Function-Units in the internal child list
				///
				int GetChildCount();

				/// @brief Method to return a Function-Unit object from the internal child list
				///
				/// @param[in] uiOutputNo Number of the output, where the Function-Unit is connected
				/// @return
				/// - Pointer to the Function-Unit object
				/// - NULL in error case
				FunctionUnitBase* GetChild(unsigned int uiOutputNo);

				// function unit HF types
				static const unsigned int TYPE_NONE						= 0x00;		///< Constant for not assigned Function-Unit type
				static const unsigned int TYPE_ANTENNA					= 0x01;		///< Constant for Antenna type (actually unused)
				static const unsigned int TYPE_HF_MULTIPLEXER			= 0x0A;		///< Constant for HF Antenna Multiplexer (ID ISC.MUX)
				static const unsigned int TYPE_HF_DYNAMIC_ANTENNA_TUNER	= 0x0B;		///< Constant for HF Dynamic Antenna Tuner (ID ISC.DAT)

				// function unit UHF types
				static const unsigned int TYPE_UHF_MULTIPLEXER			= 0x0C;		///< Constant for UHF Antenna Multiplexer (ID ISC.UMUX)

			// protected functions
			protected:

				// constructor
				FunctionUnitBase(ReaderModule* pReader, unsigned int uiFUType, unsigned char ucCascadeLevel);

				// destructor
				virtual ~FunctionUnitBase();
					
				// Function Unit implementation
				FEDM_ISCFunctionUnit* m_pFUImpl;

				unsigned char m_ucCascadeLevel;

				/// @brief type definition for a map, collecting Function-Unit objects
				///
				/// @param Key Antenna-Number
				/// @param Value Function-Unit object
				typedef std::map<unsigned int, FunctionUnitBase*>				FU_LIST;

				/// type definition for a map iterator, collecting Function-Unit objects
				typedef std::map<unsigned int, FunctionUnitBase*>::iterator		FU_LIST_ITOR_P;

			// protected data
			private:

				// Reader object for communication
				ReaderModule* m_pReader;

				FU_LIST		m_ChildList;
			};
		}
	}
}


#endif // #if !defined(_FEDM_NO_FU_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_EXT_DEVICE_FUNCTION_UNIT_BASE_H_INCLUDED_)
