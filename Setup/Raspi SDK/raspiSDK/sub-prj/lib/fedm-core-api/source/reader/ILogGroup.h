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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_ILOG_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_ILOG_GROUP_H_INCLUDED_

#include <vector>
#include "../source/FEDM.h"
#include "ILogListener.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing specific methods for logging
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for logging for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [ILog](@ref FEDM::Core::ReaderModule::ILog) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS ILogGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;

		public:

			/// @brief Activation or deactivation of log events
			/// 
			/// Log events are disabled by default.
			/// @param[in] enable true, to enable log events
			void EnableLogging(bool enable);

			/** Installs an event handling method.
			* 
			* @param[in] pListener is an object inherited of ILogListener
			* @param[in] iEventID constant with event id
			* <dt><b>Description:</b><br>
			* This method is used to install an event handler method for protocol notifications.<br>
			* With the methods of ILogListener, it is easy to realize a protocol window, to transfer the raw send or receive protocols to the application.<br>
			*/
			int AddProtocolEventListener(ILogListener* pListener, int iEventID);

			/** Removes the installed event handler.
			* 
			* @param[in] pListener is an object inherited of ILogListener
			* @param[in] iEventID constant with event id
			* <dt><b>Description:</b><br>
			* This method is used to remove an event handler method for protocol notifications.
			*/
			int RemoveProtocolEventListener(ILogListener* pListener, int iEventID);

			// for internal use: callback from FEISC
			static void	cbsFct5(void* pAny,			// [in] pointer to anything (from struct _FEISC_EVENT_INIT)
								const char* cMsg,	// [in] pointer to message
								int iStatus,		// [in] status byte (>=0) or error code (<0)
								int iEvent );		// [in] Event-ID

			/** Event-IDs for signaling protocol events to the application.
			* 
			* The protocol is notified with the listener interface of ILogListener.
			*/
			static const int EVENT_ID_TRANSCEIVE_AS_STRING = 1;

		private:
			ILogGroup();
			virtual ~ILogGroup();

			FEDM_ISCReaderModule* m_pReader;

			std::vector<ILogListener*> m_ListenerList;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_ILOG_GROUP_H_INCLUDED_)
