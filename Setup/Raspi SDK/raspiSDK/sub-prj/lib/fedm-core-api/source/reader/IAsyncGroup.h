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

#if !defined(_FEDM_CORE_READER_MODULE_IASYNC_GROUP_H_INCLUDED_)
#define _FEDM_CORE_READER_MODULE_IASYNC_GROUP_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "ITagGroup.h"
#include "IInfoGroup.h"
#include "IPortGroup.h"
#include "INotificationListener.h"
#include "IInventoryListener.h"
#include "IScanEventListener.h"
#include "../Const.h"

class FEDM_ISCReaderModule;
struct _FEDM_TASK_INIT;

namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing methods for asynchronous communication
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for asynchronous communication for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [IAsync](@ref FEDM::Core::ReaderModule::IAsync) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IAsyncGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;
			
		public:

			/// @brief Method to start an internal listener task for notifications sent by one Reader, which must work in Notification-Mode
			///
			/// @param[in] uiPortNumber TCP-Port, which listens for notifications
			/// @param[in] pListener pointer to listener class in application, which must be derived from INotificationListener
			/// @param[in] bWithAck (disabled by default); when true, an acknowledge protocol is sent to the Reader, when the listener method of INotificationListener is finished<br>
			/// The Reader must be configured to receive this acknowledge.
			/// @param[in] uiAuthentType (disabled by default); Type of authentification, when set to a type of FEDM::Core::IPortGroup::TRANSMISSION_AES128 or higher
			/// @param[in] sAuthentKey (disabled by default); Authentification password
			/// @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			///
			/// <b>Description</b><br>
			/// A recurring task of applications is inventorying transponders in the antenna field of the reader.
			/// Ideally this should run in the background and then tell the application when transponders are in the field or when the notification has arrived.
			/// This is precisely the functionality you can implement using the StartNotificationTask method.<br>
			/// Internally a thread is started which waits for the reply protocol of the reader and provides the reply data to the application using the 
			/// call of a listener method of abstract class INotificationListener.
			/// A task should only be started if the Notification-Mode is integrated and activated in the Reader&apos;s firmware. Only TCP/IP communication is supported.<br>
			/// The task waits for reception of the Buffered Read Mode data and then invokes one of the listener methods. After the method returns, 
			/// data can immediately be received again by the Reader.<br>
			/// If no error occurs, the response data are collected in the internal Buffered Read Mode Table and must be requested gradually with IBrmTableGroup::GetItemByIndex()
			/// In case of transmission errors the listener method is invoked with the error code and the receiving procedure then resumed.
			/// If the Keep-Alive option is activated (default setting: activated), then the listener socket is closed automatically after a break of the network cable or 
			/// after loss of power and is recovered again. This ensures the reliability of the network connection.<br>
			///
			/// <b>Notes</b><br>
			/// - Depending on the Reader setting, large quantities of data may be sent by the Reader in very short time intervals. 
			/// Without use of a handshake procedure (see system manual for the Reader), data may be lost if the host is not appropriate for the quantity of notifications.<br>
			/// - For Windows systems: check the settings of the Firewall, if notifications are not received.
			int StartNotificationTask(	unsigned int uiPortNumber, 
										INotificationListener* pListener,
										bool bWithAck=false, 
										unsigned int uiAuthentType=FEDM::Core::IPortGroup::TRANSMISSION_PLAIN, 
										std::string sAuthentKey="" );
					
			/// @brief Method to cancel an internal listener task at once
			///
			/// @return error code (<0) or OK (=0)
			///
			/// @note: a running Inventory task cannot be stopped.
			int Stop();

			/// Method to adjust the keep-alive parameters for notification listener tasks
			/// 
			/// @param[in] bEnableKeepAlive if true, keep alive option will be enabled
			/// @param[in] uiKeepAliveIdleTime wait time in ms for first probe after connection is dropped down<br>
			/// For Linux: time is rounded up to seconds
			/// @param[in] uiKeepAliveProbeCount only for Linux: number of probes<br>
			/// For Windows Server 2003, 2000 and XP it is fixed to 5 by Microsoft
			/// For Windows Vista and later it is fixed to 10 by Microsoft
			/// @param[in] uiKeepAliveIntervalTime wait time in ms between probes
			/// @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			///
			/// <b>Description</b><br>
			/// The keep-alive option is enabled by default and can be adjusted with this method. The parameters are used with the next call of StartNotificationTask().<br>
			/// Keep-alive parameters of a running task cannot be adjusted.<br>
			/// Keep-alive is enabled by default with the following settings:<br>
			/// Keep-alive Idle Time = 500ms<br>
			/// Keep-alive Probe Count = 5<br>
			/// Keep-alive Interval Time = 500ms<br>
			/// @note Parameters must be set in front of the call of StartNotificationTask()
			int SetKeepAlivePara(bool bEnableKeepAlive, unsigned int uiKeepAliveIdleTime, unsigned int uiKeepAliveProbeCount, unsigned int uiKeepAliveIntervalTime);
			
#ifdef _FEDM_TAG_HANDLER
			/// @brief Method to execute a single or repetitive asynchronous Inventory (only for some IDENTIFICATION Reader)
			///
			/// @param[in] uiTimeout Timeout (in multiple of 100ms) for waiting for the response
			/// @param[in] pListener pointer to listener class in application, which must be derived from IInventoryListener
			/// @param[in] bRepetitive (disabled by default); when true, a repetitive Inventory task is created and continued after each response with TriggerInventoryTask()
			/// @param[in] uiAuthentType (disabled by default); Type of authentification, when set to a type of FEDM::Core::IPortGroup::TRANSMISSION_AES128 or higher
			/// @param[in] sAuthentKey (disabled by default); Authentification password
			/// @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			///
			/// <b>Description</b><br>
			/// The Inventory command is sent to the Reader and the internal thread waits for the transponder response or a timeout.<br>
			/// @note The task in the Reader cannot be canceled nor any other command can be sent to the Reader until the task is finished.
			int StartInventoryTask(		unsigned int uiTimeout, 
										IInventoryListener* pListener, 
										bool bRepetitive=false, 
										unsigned int uiAuthentType=FEDM::Core::IPortGroup::TRANSMISSION_PLAIN, 
										std::string sAuthentKey="" );

			/// @brief Method to continue a repetitive asynchronous Inventory (only for some IDENTIFICATION Reader)
			///
			/// @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			int TriggerInventoryTask();
#endif

			/** @brief Method to start an internal listener task for scan events sent by a Scanner
			 *
			 * @param[in] uiPortNumber TCP-Port, which listens for scan events
			 * @param[in] pListener Listener object, which must be derived from IScanEventListener
			 * @return [error code](@ref FEDM::Core::ErrorCode) (<0) or OK (=0)
			 * <br>
			 * <br><b>Description:</b><br>
			 * A recurring task of applications is waiting for transponder or barcode data.
			 * Ideally, this should run in the background and then tell the application when a transponder or barcode is scanned.
			 * This is precisely the functionality you can implement using the startScanEventTask method.<br>
			 * Internally a thread is started which waits for the data of the Scanner to forward this data to the application using the
			 * call of a listener method of interface IScanEventListener
			 * <br>
			 * NOTE: the listener port can handle only one event at the same time.<br>
			 */
			int StartScanEventTask(unsigned int uiPortNumber, IScanEventListener* pListener);

		private:
				
			IAsyncGroup();
			virtual ~IAsyncGroup();

			void ClearNotifier();

			// for internal use: callback for inventory from embedded reader object
			static void	cbsFctInventory(void* pAny, int iError, unsigned char ucCmd);
			// for internal use: callback for notification task
			static void	cbsFctNotify(void* pAny, int iError, unsigned char ucCmd, char* cIPAdr, int iPortNr);
			// for internal use: callback for scan event from Scanner
			static void cbsFctScanEvent(void* pAny,					// [in] pointer to anything (from struct _FEISC_TASK_INIT)
										int iReaderHnd,				// [in] reader handle of FEISC
										int iTaskID,				// [in] task identifier from FEISC_StartAsyncTask(..)
										int iError,					// [in] OK (=0), error code (<0) or status byte from reader (>0)
										unsigned char ucCmd,		// [in]	reader command
										unsigned char* ucRspData,	// [in] response data
										int iRspLen,				// [in] length of response data
										char* cRemoteIP,			// [in] ip address of the reader
										int iLocalPort,				// [in] local port number which received the notification
										unsigned char* ucMode,		// [out] mode byte in return command [0x72] Set Output
										unsigned char* ucNoOfRecords,		// [out] number of records in return command [0x72] Set Output
										unsigned char* ucSignalization);	// [out] signalization records in return command [0x72] Set Output


			ReaderModule*				m_pParent;
			FEDM_ISCReaderModule*		m_pReader;
					
			_FEDM_TASK_INIT				m_TaskInit;

			IInventoryListener*			m_pInvListener;
			INotificationListener*		m_pNtfListener;
			IScanEventListener*			m_pSEListener;

			// only for notification tasks
			bool			m_bKeepAlive;				// if true, keep alive option will be enabled (recommended)
			unsigned int	m_uiKeepAliveIdleTime;		// wait time in ms for first probe after connection is dropped down
														// for Linux: time is rounded up to seconds
			unsigned int	m_uiKeepAliveProbeCount;	// only for Linux: number of probes
														// for Windows Server 2003, 2000 and XP it is fixed to 5 by Microsoft
														// for Windows Vista and later it is fixed to 10 by Microsoft
			unsigned int	m_uiKeepAliveIntervalTime;	// wait time in ms between probes
		};
	}
}

#endif // !defined(_FEDM_CORE_READER_MODULE_IASYNC_GROUP_H_INCLUDED_)
