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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IEXTERNAL_DEVICE_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IEXTERNAL_DEVICE_GROUP_H_INCLUDED_

#if !defined(_FEDM_NO_PD_SUPPORT) && !defined(_FEDM_NO_FU_SUPPORT)

#include <map>
#include "../source/FEDM.h"
#if !defined(_FEDM_NO_PD_SUPPORT)
	#include "../peripheral_devices/GatePeopleCounter.h"
#endif
#if !defined(_FEDM_NO_FU_SUPPORT)
	#include "../function_unit/FunctionUnitBase.h"
	#include "../function_unit/HFDynamicAntennaTuner.h"
	#include "../function_unit/HFAntennaMultiplexer.h"
	#include "../function_unit/UHFAntennaMultiplexer.h"
#endif

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing specific methods for external connected Devices
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for external Devices (like Gate People Counter or Function Units) for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [IExtDev](@ref FEDM::Core::ReaderModule::IExtDev) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IExtDeviceGroup
		{

			// friend classes have access rights to protected and private members
			// funktioniert mit g++ nicht! GCC bug. [class.access.base]/p5
			friend class ReaderModule;
			friend class ExternalDevice::FunctionUnitBase;
			friend class ExternalDevice::GatePeopleCounter;
			friend class ExternalDevice::HFDynamicAntennaTuner;
			friend class ExternalDevice::HFAntennaMultiplexer;
			friend class ExternalDevice::UHFAntennaMultiplexer;

		public:
		#if !defined(_FEDM_NO_PD_SUPPORT)
			/// @brief type definition for a map, collecting Gate People Counter objects
			///
			/// @param Key Bus-Address of Gate People Counter
			/// @param Value Gate People Counter object
			typedef std::map<unsigned char, ExternalDevice::GatePeopleCounter*>					PC_LIST;
				
			/// type definition for a map iterator, collecting Gate People Counter objects
			typedef std::map<unsigned char, ExternalDevice::GatePeopleCounter*>::const_iterator	PC_LIST_ITOR;
		#endif

		public:
			
			/// @brief Request of connected People-Counter
			///
			/// @return 
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// The Reader starts an internal detection process.
		#if !defined(_FEDM_NO_PD_SUPPORT)
			int DetectPeopleCounter();
		#endif

			/// @brief Get map with previously detected People-Counters
			///
			/// @return Pointer to a list with detected People-Counters
			///
			/// <b>Description</b><br>
			/// After a call of DetectPeopleCounter the map of People-Counter objects is returned by this method.
		#if !defined(_FEDM_NO_PD_SUPPORT)
			const PC_LIST& GetPeopleCounterMap();
		#endif


		#if !defined(_FEDM_NO_FU_SUPPORT)
			/// @brief Method to get the root Function-Unit object
			///
			/// @param[in] uiAntennaNo Antenna number of Reader, where the Function-Unit is connected
			/// @return
			///		- Pointer to the Function-Unit, which must be casted to the specific type
			///		- NULL, if anything goes wrong
			///
			/// <b>Description</b><br>
			/// This method must be called to get the Function-Unit object in cascade level 1, which must be connected at the specified Antenna number of the Reader.<br>
			/// The returned object must be casted to the correct Function-Unit type.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// ExternalDevice::HFAntennaMultiplexer* pHfMux = NULL;
			/// ExternalDevice::UHFAntennaMultiplexer* pUhfMux = NULL;
			/// ExternalDevice::HFDynamicAntennaTuner* pHfDat = NULL;
			///
			/// ExternalDevice::FunctionUnitBase* pFU = reader.IExtDevice.GetRootFunctionUnit(1);
			///
			/// if(dynamic_cast<ExternalDevice::HFAntennaMultiplexer*>(pFU) != NULL)
			/// {
			///		pHfMux = (ExternalDevice::HFAntennaMultiplexer*)pFU;
			///		...
			/// }
			/// else if(dynamic_cast<ExternalDevice::HFDynamicAntennaTuner*>(pFU) != NULL)
			/// {
			///		pHfDat = (ExternalDevice::HFDynamicAntennaTuner*)pFU;
			///		...
			/// }
			/// else if(dynamic_cast<ExternalDevice::UHFAntennaMultiplexer*>(pFU) != NULL)
			/// {
			///		pUhfMux = (ExternalDevice::UHFAntennaMultiplexer*)pFU;
			///		...
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			ExternalDevice::FunctionUnitBase* GetRootFunctionUnit(unsigned int uiAntennaNo);

			/// @brief Fabric-Method to create an Function-Unit object of specified type
			///
			/// @param[in] uiAntennaNo Antenna number of Reader, where the Function-Unit is connected
			/// @param[in] uiFunctionUnitType Type of Function-Unit to be created to (see FEDM::Core::ExternalDevice::FunctionUnitBase::TYPE_HF_MULTIPLEXER and other constants)
			/// @return
			///		-  0, if root object is created
			///		- <0, if anything goes wrong
			///
			/// <b>Description</b><br>
			/// This method must be called to create the Function-Unit in cascade level 1 and which is connected at the specified Antenna number of the Reader.<br>
			/// The created Function-Unit is managed by the Reader class and destroyed automatically together with the Reader object.<br>
			/// For destroying manually, call DestroyRootFunctionUnit, which destroys all childs too.<br>
			int CreateRootFunctionUnit(unsigned int uiAntennaNo, unsigned int uiFunctionUnitType);

			/// @brief Method to destroy an Function-Unit object
			///
			/// @param[in] uiAntennaNo Antenna number of Reader, where the Function-Unit is connected
			/// @return
			///		-  0, if root object is destroyed
			///		- <0, if anything goes wrong
			///
			/// <b>Description</b><br>
			/// This method can optionally be called to destroy the Function-Unit in cascade level 1 and all associated childs.<br>
			/// The created Function-Unit is managed by the Reader class and destroyed normally automatically together with the Reader object.<br>
			int DestroyRootFunctionUnit(unsigned int uiAntennaNo);

		protected:

			// internal Fabric-Method to create an Function-Unit object of requested type
			ExternalDevice::FunctionUnitBase* CreateChildFunctionUnit(unsigned int uiAntennaNo, unsigned int uiFunctionUnitType, unsigned char ucCascadeLevel);
		#endif

		private:
			IExtDeviceGroup();
			virtual ~IExtDeviceGroup();

		#if !defined(_FEDM_NO_PD_SUPPORT)
			void ClearPeopleCounterMap();

			/// type definition for a map iterator, collecting Gate People Counter objects
			typedef std::map<unsigned char, ExternalDevice::GatePeopleCounter*>::iterator	PC_LIST_ITOR_P;
		#endif

		#if !defined(_FEDM_NO_FU_SUPPORT)
			void ClearFunctionUnitMap();
		#endif

			ReaderModule*			m_pParent;
			FEDM_ISCReaderModule*	m_pReader;
			
		#if !defined(_FEDM_NO_PD_SUPPORT)
			PC_LIST		m_mapPeopleCounter;
		#endif

		#if !defined(_FEDM_NO_FU_SUPPORT)
			ExternalDevice::FunctionUnitBase::FU_LIST	m_mapFunctionUnit;
		#endif
		};
	}
}

#endif // #if !defined(_FEDM_NO_PD_SUPPORT) && !defined(_FEDM_NO_FU_SUPPORT)

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IEXTERNAL_DEVICE_GROUP_H_INCLUDED_)
