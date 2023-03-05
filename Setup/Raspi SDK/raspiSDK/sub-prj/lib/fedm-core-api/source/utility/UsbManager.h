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

#if !defined(_FEDM_CORE_UTILITY_USB_MANAGER_H_INCLUDED_)
#define _FEDM_CORE_UTILITY_USB_MANAGER_H_INCLUDED_

#ifdef _FEDM_USB_SUPPORT

#include <string>
#include <vector>
#include "../source/FEDM.h"

// the following include is for USB support
// please define _FEDM_USB_SUPPORT with compiler option
// additionally, you must define _FEDM_WINDOWS or _FEDM_LINUX with compiler option
#include "feusb.h"


namespace FEDM
{
	namespace Core
	{
		/// Namespace for utility classes
		namespace Utility
		{
			/** @brief Class providing low-level access, based on the port library FEUSB
			*
			* <b>Description</b><br>
			* This class provides low-level access, based on the port library FEUSB.
			* The main method is [Scan](@ref FEDM::Core::Utility::UsbManager::Scan), with which all connected USB Readers are detected.
			* Some information of each Reader is read and collected in a [ScanListItem](@ref FEDM::Core::Utility::UsbManager::ScanListItem).
			* The main information of each Reader is its Device-ID, which must be known for opening the communication channels with the method
			* [ConnectUSB](@ref FEDM::Core::IPortGroup::ConnectUSB(unsigned long nDeviceID))
			*/
			class _FEDM_ISC_CORE_EXT_CLASS UsbManager
			{
			public:

				/// Structure represents one Scan List record
				struct ScanListItem
				{
					unsigned long nDeviceID;	///< Device ID of connected Reader
					std::string sDeviceName;	///< Reader Name

					ScanListItem() : nDeviceID(0) {};
				};

				/** @brief type definition for a vector, collecting scan list items*/
				typedef std::vector<ScanListItem*>					SCAN_LIST;

				/** @brief type definition for a vector iterator, collecting scan list items*/
				typedef std::vector<ScanListItem*>::const_iterator	SCAN_LIST_ITOR;

				/** Create an instance of the USB manager
				*
				* The USB manager is a singleton. Use this function to create an object
				* @return Pointer to an USB manager object
				*/
				static UsbManager *instance(void);

				/**Detecting a single or all USB readers.
				*
				* @param[in] uiScanOption for more details of this parameter look at the description field
				* @return ErrorCode::OK on success<br>
				*         negativ values on failure (constants from class ErrorCode or from the FEUSB-library)
				* <p align="justify">
				* <a name = "scan"></a>
				* <dt><b>Description:</b><br>
				* With this method the USB port is searched for Readers with the
				* FEIG identifier, and each found Reader is entered in the internal scan list.
				* The parameter uiScanOption allows searching for one or all Readers.<br>
				* The parameter uiScanOption controls the scan procedure and is comprised
				* of uiScanOption = [CommandID] | [OptionID] | [OptionID].<br>
				* CommandIDs:
				* <ul>
				* <li>SCAN_FIRST searches for the Reader that was the first one to
				* be registered by the operating system. The internal scan counter is thus
				* set to 0. The scan list is cleared before the scanning process.</li>
				* <li>SCAN_NEXT searches for the reader that was next registered by
				* the operating system. For this the internal scan counter is used, which
				* is incremented with each successful SCAN_NEXT (up to max. 127).
				* Note: each FEUSB_SCAN_FIRST resets the internal scan counter to 0!</li>
				* <li>SCAN_NEW searches for a new Readers which is not yet entered in
				* the scan list. The internal counter is correspondingly set anew.</li>
				* <li>SCAN_ALL allows searching for all Readers on the USB port.
				* The scan counter is correspondingly set anew.
				* The scan list is first cleared and then reconstructed.
				* You cannot therefore assume that a reader previously entered in the scan
				* list will be listed with the same index.</li>
				* </ul>
				* OptionIDs:
				* <ul>
				* <li>Actually no Option IDs defined.</li>
				* </ul>
				* <br>
				* </p>
				*/
				int Scan(unsigned int uiScanOption = SCAN_ALL);

				/** Get the scan list.
					*
					* @return scan list
					* <p align="justify">
					* <dt><b>Description:</b><br>
					* This method returns the scan list previously generated with [Scan](@ref FEDM::Core::Utility::UsbManager::Scan).<br>
					* </p>
					*/
				const SCAN_LIST& GetScanList() { return m_ScanList; }

				/** Scan Command for [Scan](@ref FEDM::Core::Utility::UsbManager::Scan) */
				static const unsigned int SCAN_FIRST = FEUSB_SCAN_FIRST;
				/** Scan Command for [Scan](@ref FEDM::Core::Utility::UsbManager::Scan) */
				static const unsigned int SCAN_NEXT = FEUSB_SCAN_NEXT;
				/** Scan Command for [Scan](@ref FEDM::Core::Utility::UsbManager::Scan) */
				static const unsigned int SCAN_NEW = FEUSB_SCAN_NEW;
				/** Scan Command for [Scan](@ref FEDM::Core::Utility::UsbManager::Scan) */
				static const unsigned int SCAN_ALL = FEUSB_SCAN_ALL;

			private:
				/** @brief type definition for a list iterator, collecting scan list items*/
				typedef std::vector<ScanListItem*>::iterator	SCAN_LIST_ITOR_P;

				static UsbManager* m_instance;
				SCAN_LIST          m_ScanList;

				UsbManager();
				UsbManager(const UsbManager &);
				~UsbManager();

				void ClearScanList();

				class Guard {
				public: 
					~Guard() {
						if( UsbManager::m_instance != NULL )
							delete UsbManager::m_instance;
						UsbManager::m_instance = NULL;
					}
				};
				friend class Guard;
			};
		}
	}
}

#endif // #ifdef _FEDM_USB_SUPPORT

#endif // !defined(_FEDM_CORE_UTILITY_USB_MANAGER_H_INCLUDED_)
