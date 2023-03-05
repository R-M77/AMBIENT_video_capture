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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IPORT_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IPORT_GROUP_H_INCLUDED_

#include <string>
#include <map>
#include "../source/FEDM.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		class ReaderModule;

		/// @brief Internal class providing communication port specific commands
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for port specific commands for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [IPort](@ref FEDM::Core::ReaderModule::IPort) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IPortGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;
			
		public:

			/**
			 * class for initializing the serial port with [ConnectCOMM](@ref IPortGroup::ConnectCOMM)
			 */
			class _FEDM_ISC_CORE_EXT_CLASS SerialPortSetting
			{
				friend class IPortGroup;

			public:
				/**
				 * Constructor for initialization the serial port
				 * 
				 * @param[in] ucBusAddress (preset to 0) bus address of connected Reader in the range of 0 .. 255.<br>Do not use 255, if you want to execute a firmware update.<br><br>
				 * @param[in] uiBaudrate baudrate of connected Reader. See list of applicable values for baudrate.<br>An unspecified value will be ignored and baudrate is set to zero (0).
				 * if it is not clear with which baudreate the Reader is configured, set baudrate to zero (0). This starts an internal baudrate detection process.<br>
				 * List of applicable baudrate values:<br>
				 * <table border = "1" summary = "">
				 * <tr>
				 *  <td>Value</td>
				 *  <td>Note</td>
				 * </tr>
				 * <tr>
				 *  <td>0</td>
				 *  <td>preset; baudrate is detected with {@link IPortGroup::FindBaudrate()}</td>
				 * </tr>
				 * <tr>
				 *  <td>4800</td>
				 *  <td></td>
				 * </tr>
				 * <tr>
				 *  <td>9600</td>
				 *  <td></td>
				 * </tr>
				 * <tr>
				 *  <td>19200</td>
				 *  <td></td>
				 * </tr>
				 * <tr>
				 *  <td>38400</td>
				 *  <td>factory setting</td>
				 * </tr>
				 * <tr>
				 *  <td>57600</td>
				 *  <td></td>
				 * </tr>
				 * <tr>
				 *  <td>115200</td>
				 *  <td></td>
				 * </tr>
				 * <tr>
				 *  <td>230400</td>
				 *  <td>please check, if your HW and OS does support this baudrate</td>
				 * </tr>
				 * </table>
				 * <br>
				 *
				 * @param[in] sFrame frame of connected Reader. See list of applicable value for frame.<br>An unspecified value will be ignored and frame is set to "8E1".<br>
				 * List of applicable frame values:<br>
				 * <table border = "1" summary = "">
				 * <tr>
				 *  <td>Value</td>
				 *  <td>Note</td>
				 * </tr>
				 * <tr>
				 *  <td>"8E1"</td>
				 *  <td>preset and factory setting</td>
				 * </tr>
				 * <tr>
				 *  <td>"8N1"</td>
				 *  <td></td>
				 * </tr>
				 * <tr>
				 *  <td>"8O1"</td>
				 *  <td></td>
				 * </tr>
				 * </table>
				 * <br>
				 *
				 * @param[in] uiCharTimeoutMpy (preset to 1) Multiplier for char timeout in the range of 1..99.<br>An unspecified value will be ignored and charTimeoutMpy is set to 1.<br><br>
				 * @param[in] bSetRtsAndDtrOn (preset to false) If true, control lines RTS and DTR are set on.<br>This parameter should be set only to true, if an external and signal powered TTL-to-RS232 converter is used.<br>
				 */
				SerialPortSetting(unsigned char ucBusAddress = 0, unsigned int uiBaudrate = 0, std::string sFrame = "8E1", unsigned int uiCharTimeoutMpy = 1, bool bSetRtsAndDtrOn = false);

			private:
				/**
				 * Bus Address in the range of 0..255
				 */
				unsigned char m_ucBusAddress;
		
				/**
				 * Baudrate
				 */
				unsigned int m_uiBaudrate; // detect of baudrate with findBaudrate
		
				/**
				 * Frame
				 */
				std::string m_sFrame;
		
				/**
				 * Char Timeout Multiplier
				 */
				unsigned int m_uiCharTimeoutMpy;
		
				/**
				 * Set RTS and DTR for signal powered TTL-to-RS232 converter
				 */
				bool m_bSetRtsAndDtrOn;

			};

			/// @brief Definition of callback function for [FindBaudrate](@ref IPortGroup::FindBaudrate)
			///
			/// @param[in] void* pointer to anything (e.g. 'this' pointer), which is transferred as last parameter in [FindBaudrate](@ref IPortGroup::FindBaudrate)
			/// @param[in] int Serial Port number
			/// @param[in] unsigned char Bus-Address
			/// @param[in] char* Actual selected baudrate ("230400", "115200", "57600", "38400", "19200", "9600", "4800")
			/// @param[in] char* Actual selected frame ("8E1", "8N1", "8O1")
			/// @param[in] int Actual selected protocol frame (#PROTOCOL_FRAME_STANDARD, #PROTOCOL_FRAME_ADVANCED)
			///
			/// <b>Description</b><br>
			/// Used for rare cases, when e.g. the detection process must be signaled with a Progress Bar or with Messages
			typedef void(*CB_FIND_BAUDRATE)(void*, int, unsigned char, char*, char*, int);
			
			/// @brief Setting communication timeout for Serial Port, USB, Bluetooth, LAN or WLAN
			///
			/// @param[in] uiTimeout new communication timeout in milliseconds
			///
			/// <b>Description</b><br>
			/// Used for setting the timeout parameter in the underlying libraries FECOM, FEUSB and FETCP<br>
			/// Use these library manuals to view which parameters and which parameter ranges are applicable
			void SetTimeout(unsigned int uiTimeout);		// for all port types
			
			/// @brief Setting port parameters for Serial Port, USB, Bluetooth, LAN or WLAN
			///
			/// @param[in] sPara Parameter Name
			/// @param[in] sValue Parameter Value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Used for setting port parameters in the underlying libraries FECOM, FEUSB and FETCP<br>
			/// Use these library manuals to view which parameters are applicable
			int SetPortPara(std::string sPara, std::string sValue);		// for all port types
					
			/// @brief Setting port parameters for Serial Port, USB, Bluetooth, LAN or WLAN
			///
			/// @param[in] sPara Parameter Name
			/// @param[in] iValue Parameter Value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Used for setting port parameters in the underlying libraries FECOM, FEUSB and FETCP<br>
			/// Use these library manuals to view which parameters are applicable
			int SetPortPara(std::string sPara, int iValue);		// for all port types

			/// @brief Get a port parameter of Serial Port, USB, Bluetooth, LAN or WLAN
			///
			/// @param[in] sPara Parameter Name
			/// @param[out] sValue Parameter Value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Used for getting port parameters from the underlying libraries FECOM, FEUSB and FETCP<br>
			/// Use these library manuals to view which parameters are applicable
			int GetPortPara(std::string sPara, std::string& sValue);		// for all port types

			/// @brief Get a port parameter of Serial Port, USB, Bluetooth, LAN or WLAN
			///
			/// @param[in] sPara Parameter Name
			/// @param[out] iValue Parameter Value
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Used for getting port parameters from the underlying libraries FECOM, FEUSB and FETCP<br>
			/// Use these library manuals to view which parameters are applicable
			int GetPortPara(std::string sPara, int* iValue);		// for all port types

			/// @brief Return the actual used port handle
			///
			/// @return Port Handle (>0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			int GetPortHandle();

			/// @brief Set a new port handle (do not use in normal conditions)
			///
			/// @param[in] uiPortHnd New port handle
			///
			/// <b>Description</b><br>
			/// This method is for special conditions. Do not use it. Use always the Connect methods for your applications.
			int SetPortHandle(unsigned int uiPortHnd);

			/// @brief Change the protocol frame
			///
			/// @param[in] uiType Protocol Frame Type
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Change the protocol frame type to [PROTOCOL_FRAME_STANDARD](@ref FEDM::Core::IPortGroup::PROTOCOL_FRAME_STANDARD) or [PROTOCOL_FRAME_ADVANCED](@ref FEDM::Core::IPortGroup::PROTOCOL_FRAME_ADVANCED)
			///
			/// @note STANDARD is preset in the library
			int SetProtocolFrameSupport(unsigned int uiType);
					
			/// @brief Return the actual used protocol frame
			///
			/// @return Actually used protocol frame
			///
			/// <b>Description</b><br>
			int GetProtocolFrameSupport();

			/// @brief Set the bus address for communication over Serial Port
			///
			/// @param[in] ucBusAdr New bus address to be used for the serial communication
			///
			/// <b>Description</b><br>
			void  SetBusAddress(unsigned char ucBusAdr);

			/// @brief Returns the actual used bus address, initialized in the Reader class
			///
			/// @return Actually used bus address
			///
			/// <b>Description</b><br>
			unsigned char GetBusAddress();

			/// @brief For Linux: Set the prefix for the Serial Port
			///
			/// @param[in] sPrefix String with port prefix name
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			///
			/// <b>Description</b><br>
			/// For Linux, the prefix for e.g. Bluetooth is /dev/rfcomm and not /dev/ttyS
			/// The prefix should be set in the eve of ConnectCOMM and should be set back to /dev/ttyS directly after this call.
			int  SetPortPrefix(std::string sPrefix);

			/// @brief Method to open a Serial Port for plain data transmission
			///
			/// @param[in] uiPortNr Number of serial port in the range of 1...256
			/// @param[in] bWithDetect if true (preset), a call of FindBaudRate() and IInfoGroup::ReadReaderInfo() is done to adjust the port parameters and to set the Reader Type Number internally
			/// @param[in] pPortPara optional initialization parameters.<br>If para is set to null, the following default values will be used: busAddress=0, baudRate=0, frame="8E1", charTimeoutMpy=1 and setRtsAndDtrOn=false.
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Opens a serial port with Baudrate and Frame adapted to the Reader&apos;s port settings.<br>
			/// If the second parameter is set to false, the port parameters will not be adapted to the Reader&apos;s port settings and the Reader cannot not be detetcted.
			/// In this case, the application must call FindBaudRate() and IInfoGroup::ReadReaderInfo() later.<br>
			/// It is recommended to set bDetect to true, if the Reader is still connected at the correct port and powered-on.
			/// 
			/// @note For Linux: use port number 1 for ttyS0 and so forth.
			int ConnectCOMM(unsigned int uiPortNr, bool bWithDetect=true, SerialPortSetting* pPortPara=NULL);

			/// @brief Method to open a Serial Port for secured data transmission
			///
			/// @param[in] uiPortNr Number of serial port in the range of 1...256
			/// @param[in] pPortPara optional initialization parameters.<br>If para is set to null, the following default values will be used: busAddress=0, baudRate=0, frame="8E1", charTimeoutMpy=1 and setRtsAndDtrOn=false.
			/// @param[in] uiAuthentType Type of authentification, when set to a type of FEDM::Core::Const::AES128 or higher
			/// @param[in] sAuthentKey Authentification password
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Opens a serial port with the following calls of FindBaudRate(), IInfoGroup::ReadReaderInfo() and ReaderAuthentication(). 
			/// Thus, it is expected, that the Reader is connected at the correct port and powered-on.<br>
			/// If an error occurs or the Reader cannot be detected, the method returns an error code.
			/// This method can only be used, if the Reader supports secured data transmission.
			/// 
			/// @note For Linux: use port number 1 for ttyS0 and so forth.
			/// @note: Secured data transmission is not supported with every Reader. Please refer to the Reader&apos;s System Manual for additional information.<br>
			int ConnectCOMM(unsigned int uiPortNr, SerialPortSetting* pPortPara, unsigned int uiAuthentType, std::string sAuthentKey);

			/** @brief Linux: Opens a Bluetooth port and detects (optional) a reader.  Windows: Not recommended. Use connectCOMM
			* 
			* @param uiPortNumber the number of the Bluetooth port in the range 1..256 (1 is asigned to /dev/rfcomm0, 2 to /dev/rfcomm1 and so on)
			* <p>
			* <dt><b>Description:</b><br>
			* This method is only for Linux!<br>
			* Method opens a Bluetooth port and detects a reader and reads information from reader.<br>
			* The Reader must be powered on.<br>
			* After successful opening of the Bluetooth port, the reader will be detected with FindBaudRate() method and if with success,
			* the complete reader information is read and can be queried with IInfoGroup::GetReaderInfo().<br>
			* In case of not detecting a reader the Bluetooth port is closed again.<br>
			* The connect method can be used once for every reader object. If the port must be changed, the opened port must first be closed with the method disConnect.<br>
			* </p>
			*/
			int ConnectBT(unsigned int uiPortNumber);

			/** @brief Method to open a connection to the unit-test reader-emulator
			*
			* <p>
			* <dt><b>Description:</b><br>
			* This method is only for FEIG internal Unit-Tests!<br>
			* This function sets LR1002 as default reader type.
			* Use SetReaderType() if your test case needs another one.
			* </p>
			*/
			int InitUnitTest(void);

			/// @brief Method to open a connection to a TCP-Reader for plain data transmission
			///
			/// @param[in] sHostAdr TCP/IP-Address
			/// @param[in] uiPortNr TCP/IP-Portnumber
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Establish a connection to a TCP-Reader with the following call of IInfoGroup::ReadReaderInfo().
			/// Thus, it is expected, that the Reader is connected at the Ethernet and powered-on.<br>
			/// If an error occurs or the Reader cannot be detected, the method returns an error code.
			int ConnectTCP(std::string sHostAdr, unsigned int uiPortNr);

			/// @brief Method to open a connection to a TCP-Reader for secured data transmission
			///
			/// @param[in] sHostAdr TCP/IP-Address
			/// @param[in] uiPortNr TCP/IP-Portnumber
			/// @param[in] uiAuthentType Type of authentification, when set to a type of FEDM::Core::Const::AES128 or higher
			/// @param[in] sAuthentKey Authentification password
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Establish a connection to a TCP-Reader with the following call of IInfoGroup::ReadReaderInfo() and ReaderAuthentication().
			/// Thus, it is expected, that the Reader is connected at the Ethernet and powered-on.<br>
			/// If an error occurs or the Reader cannot be detected, the method returns an error code.
			/// 
			/// @note: Secured data transmission is not supported with every Reader. Please refer to the Reader&apos;s System Manual for additional information.<br>
			int ConnectTCP(std::string sHostAdr, unsigned int uiPortNr, unsigned int uiAuthentType, std::string sAuthentKey);
	
			/// @brief Method to open a connection to an USB-Reader for plain data transmission
			///
			/// @param[in] ulDeviceID Device-ID of Reader or 0 to connect to the first USB-Reader, which is detected at USB
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Open a connection to an USB-Reader with the following call of IInfoGroup::ReadReaderInfo().
			/// Thus, it is expected, that the Reader is connected at the USB and powered-on.<br>
			/// If an error occurs or the Reader cannot be detected, the method returns an error code.<br>
			/// If only one USB-Reader is connected at the System, the Device-ID can be set to 0.<br>
			/// If multiple USB-Readers are connected, the Device-IDs must be requested with the USB-Library FEUSB. If a 0 ist unsed instead, 
			/// it is not guaranteed to connect always to the same USB-Reader.
			int ConnectUSB(unsigned long ulDeviceID);

			/// @brief Method to open a connection to an USB-Reader for secured data transmission
			///
			/// @param[in] ulDeviceID Device-ID of Reader or 0 to connect to the first USB-Reader, which is detected at USB
			/// @param[in] uiAuthentType Type of authentification, when set to a type of FEDM::Core::Const::AES128 or higher
			/// @param[in] sAuthentKey Authentification password
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Open a connection to an USB-Reader with the following call of IInfoGroup::ReadReaderInfo() and ReaderAuthentication().
			/// Thus, it is expected, that the Reader is connected at the USB and powered-on.<br>
			/// If an error occurs or the Reader cannot be detected, the method returns an error code.<br>
			/// If only one USB-Reader is connected at the System, the Device-ID can be set to 0.<br>
			/// If multiple USB-Readers are connected, the Device-IDs must be requested with the USB-Library FEUSB. If a 0 ist unsed instead, 
			/// it is not guaranteed to connect always to the same USB-Reader.
			/// 
			/// @note: Secured data transmission is not supported with every Reader. Please refer to the Reader&apos;s System Manual for additional information.<br>
			int ConnectUSB(unsigned long ulDeviceID, unsigned int uiAuthentType, std::string sAuthentKey);
	
			/// @brief Close a connection
			/// 
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Close the existing connection.
			/// When closing a TCP/IP connection, the last status of the connection is returned. But if the status TIME_WAIT is detected, 
			/// a 0 will be returned to signal a successful disconnection. Otherwise, GetTcpConnectionState() should be called again to observe the TCP/IP connection status.
			int DisConnect();

			/// @brief Returns the connection state
			///
			/// @return true, if a Connect method was previously successfully called
			///
			/// <b>Description</b><br>
			/// Signals that the application has called one of the Connect methods and no further connection can be established. 
			/// It is not active checked (e.g. with a Reader command), if the Reader is still connected and a communication is possible
			bool IsConnected();

			/// @brief Only for Serial Port: method to find the baudrate and frame of reader
			///
			/// @param[in] pStop Do not change the preset!
			/// @param[in] iTimeout Do not change the preset!
			/// @param[in] iFrameSupport Do not change the preset!
			/// @param[in] cbFct Do not change the preset!
			/// @param[in] pAny Do not change the preset!
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// The serial port settings will be adjusted to the port settings of the connected and powered-on Reader. All parameters are for special cases and should not be changed.
			int FindBaudrate(bool* pStop = NULL, int iTimeout = 300, int iFrameSupport = 3, CB_FIND_BAUDRATE cbFct=NULL, void* pAny=NULL);

			/// @brief Method to check the actual TCP/IP connection state according RFC 793 (Transmission Control Protocol)
			///
			/// @return Connection status (>0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// When closing a TCP/IP connection, the last status of the connection is returned. If the status is not TIME_WAIT, 
			/// %GetTcpConnectionState() should be called to observe the TCP/IP connection status, because a new connection to the same Reader is only possible after the 
			/// connection state TIME_WAIT is reached.<br>
			/// <br>
			/// The following connection states are defined:
			/// <pre>
			///		CLOSED     			 1
			///		LISTEN     			 2
			///		SYN_SENT   			 3
			///		SYN_RCVD   			 4
			///		ESTABLISHED			 5
			///		FIN_WAIT1  			 6
			///		FIN_WAIT2  			 7
			///		CLOSE_WAIT 			 8
			///		CLOSING    			 9
			///		LAST_ACK   			10
			///		TIME_WAIT  			11
			/// </pre>
			int GetTcpConnectionState();

			/// @brief Method to execute an authentication process for secured data transmission
			///
			/// @param[in] uiAuthentType Type of authentification, when set to a type of FEDM::Core::Const::AES128 or higher
			/// @param[in] sAuthentKey Authentification password
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// 
			/// @note This method can only be used, if the Reader supports secured data transmission.
			int ReaderAuthentication(unsigned int uiAuthentType, std::string sAuthentKey);


			/// @brief Constant for Standard Protocol Frame, used for Reader protocol (deprecated, use only for older Readers)
			///
			/// @note By default, the protocol frame is set to Standard
			static const unsigned int PROTOCOL_FRAME_STANDARD = FEDM_PRT_FRAME_STANDARD;

			/// @brief Constant for Advanced Protocol Frame, used for Reader protocol (ADVANCED frame should be used with actual Readers)
			///
			/// @note By default, the protocol frame is set to Standard. Use the method IPortGroup::SetProtocolFrameSupport() to switch to Advanced Protocol
			static const unsigned int PROTOCOL_FRAME_ADVANCED = FEDM_PRT_FRAME_ADVANCED;

			/// Constant for plain protocol transmission (standard)
			static const unsigned int TRANSMISSION_PLAIN = 255;
			/// Constant for secured protocol transmission to select the Advanced Encryption Standard (AES) with 128 bit key length
			static const unsigned int TRANSMISSION_AES128 = 0;
			/// Constant for secured protocol transmission to select the Advanced Encryption Standard (AES) with 192 bit key length
			static const unsigned int TRANSMISSION_AES192 = 1;
			/// Constant for secured protocol transmission to select the Advanced Encryption Standard (AES) with 256 bit key length
			static const unsigned int TRANSMISSION_AES256 = 2;

			/// Namespace with all TCP connection states according RFC 793 (Transmission Control Protocol)
			typedef enum TcpState
			{
				/// represents no connection state at all
				CLOSED = 1,
				/// represents waiting for a connection request from any remote TCP and port
				LISTEN = 2,
				/// represents waiting for a matching connection request after having sent a connection request
				SYN_SEND = 3,
				/// represents waiting for a confirming connection request acknowledgment after having both received and sent a connection request
				SYN_RCVD = 4,
				/// represents an open connection, data received can be delivered to the user.  The normal state for the data transfer phase of the connection
				ESTABLISHED = 5,
				/// represents waiting for a connection termination request from the remote TCP, or an acknowledgment of the connection termination request previously sent
				FIN_WAIT1 = 6,
				/// represents waiting for a connection termination request from the remote TCP
				FIN_WAIT2 = 7,
				/// represents waiting for a connection termination request from the local user
				CLOSE_WAIT = 8,
				/// represents waiting for a connection termination request acknowledgment from the remote TCP
				CLOSING = 9,
				/// represents waiting for an acknowledgment of the connection termination request previously sent to the remote TCP (which includes an acknowledgment of its connection termination request)
				LAST_ACK = 10,
				/// represents waiting for enough time to pass to be sure the remote TCP received the acknowledgment of its connection termination request
				TIME_WAIT = 11
			} TcpState;

		private:
				
			IPortGroup();
			virtual ~IPortGroup();
				
			ReaderModule*			m_pParent;
			FEDM_ISCReaderModule*	m_pReader;
			unsigned int			m_uiTimeout;
			unsigned int			m_uiCharTimeout;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IPORT_GROUP_H_INCLUDED_)
