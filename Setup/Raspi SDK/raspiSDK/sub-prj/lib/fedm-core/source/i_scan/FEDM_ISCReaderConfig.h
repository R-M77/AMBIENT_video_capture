/*-------------------------------------------------------
|
|		FEDM_ISCReaderConfig.h
|
---------------------------------------------------------

Copyright © 2000-2021	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : info@feig.de
						Internet : http://www.feig.de
					
Version       		:	05.06.00 / 21.05.2021

Operation Systems	:	independent
						This file is auto-generated

Function			:	This file contains all configuration namespaces


Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/


#if !defined(_FEDM_READER_CONFIG_PARA_H_INCLUDED_)
#define _FEDM_READER_CONFIG_PARA_H_INCLUDED_

#include <string>
#include "../FEDM.h"

using namespace std;

namespace CoreImpl
{
	namespace ReaderConfig
	{
		/// General device parameters
		namespace Device
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string ConfigLayoutID;
			_FEDM_ISC_CORE_EXT_CLASS extern const string ConfigVersion;

			/// Parameters for device identification
			namespace Identifier
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string ScannerID;
				_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderID;
			}
		}

		/// Configuration parameters for security and access protection
		namespace AccessProtection
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string Password;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG0;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG1;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG2;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG3;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG4;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG5;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG6;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG7;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG8;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG9;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG10;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG11;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG12;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG13;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG14;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG15;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG16;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG17;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG18;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG19;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG20;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG21;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG36;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG37;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG38;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG39;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG48;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG63;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG22_29;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG30_35;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG30_39;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG40_49;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG50_59;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG60_62;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Lock_CFG64_86;
			_FEDM_ISC_CORE_EXT_CLASS extern const string CryptoMode;
		}

		/// Configuration parameters for communication interfaces
		namespace HostInterface
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string Interfaces;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_RS232;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_RS4xx;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_LAN;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_WLAN;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_USB;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Discovery;

			/// %Serial Port specific parameters
			namespace Serial
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string BusAddress;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Baudrate;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Frame;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Parity;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Databits;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Stopbits;
				_FEDM_ISC_CORE_EXT_CLASS extern const string ProtocolStartSynchronizationTime;
				_FEDM_ISC_CORE_EXT_CLASS extern const string FlashloaderBaudrate;

				/// RS485 or RS422 specific parameters
				namespace RS4xx
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_TerminationResistors;
				}
			}

			/// %USB specific parameters
			namespace USB
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UniformDeviceID;

				/// USB %HID specific parameters
				namespace HID
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string KeyStroke_Delay;
				}
			}

			/// %LAN specific parameters
			namespace LAN
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;

				/// Parameter group for LAN hostname
				namespace Hostname
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Name;
				}

				/// Keep-Alive specific parameters (important when network gets broken)
				namespace Keepalive
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RetransmissionCount;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IntervalTime;
				}

				/// Connection parameters for Localhost (embedded Application)
				namespace LocalHost
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
				}

				/// %IPv4 specific connection parameters
				namespace IPv4
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_IPv4;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SubnetMask;
					_FEDM_ISC_CORE_EXT_CLASS extern const string GatewayAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_DHCP;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Speed;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TCP_UserTimeout;
				}

				/// %IPv6 specific connection parameters
				namespace IPv6
				{
				}

				/// LAN specific connection parameters
				namespace Autonegotiation
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Disable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Duplex;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Speed;
				}
			}

			/// %WLAN specific parameters
			namespace WLAN
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
				_FEDM_ISC_CORE_EXT_CLASS extern const string NetworkType;
				_FEDM_ISC_CORE_EXT_CLASS extern const string AdHocChannel;
				_FEDM_ISC_CORE_EXT_CLASS extern const string FrequencyBand;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Region;

				/// Parameter group for WLAN hostname
				namespace Hostname
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Name;
				}

				/// Keep-Alive specific parameters (important when network gets broken)
				namespace Keepalive
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RetransmissionCount;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IntervalTime;
				}

				/// 
				namespace AccessPoint
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Channel;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SecurityMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_HTTPServer;
				}

				/// Connection parameters for secured transmission
				namespace Security
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string AuthenticationType;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EncryptionType;

					/// SSID parameters
					namespace ServiceSetIdentifier
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Length;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SSID;
					}

					/// %WEP Key
					namespace WEP
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string KeyLength;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Key;
					}

					/// %WPA Key
					namespace WPA
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string KeyLength;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Key;
					}

					/// %WPA2 Key
					namespace WPA2
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string KeyLength;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Key;
					}

					/// 
					namespace EAP
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Method;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InnerMethod;
						_FEDM_ISC_CORE_EXT_CLASS extern const string UserID;
						_FEDM_ISC_CORE_EXT_CLASS extern const string UserPassword;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_OKC;
					}
				}

				/// %IPv4 specific connection parameters
				namespace IPv4
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_IPv4;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SubnetMask;
					_FEDM_ISC_CORE_EXT_CLASS extern const string GatewayAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DNS1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DNS2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_DHCP;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TCP_UserTimeout;

					/// Parameters for IPv4 remote connection
					namespace Remote
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
						_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ConnectionHoldTime;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Hostname;
					}
				}

				/// %IPv6 specific connection parameters
				namespace IPv6
				{
				}
			}

			/// %Bluetooth specific parameters
			namespace Bluetooth
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string DestinationAddress;
				_FEDM_ISC_CORE_EXT_CLASS extern const string DeviceName;
				_FEDM_ISC_CORE_EXT_CLASS extern const string NameSuffix;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Key;
				_FEDM_ISC_CORE_EXT_CLASS extern const string PIN;
				_FEDM_ISC_CORE_EXT_CLASS extern const string PowerOnTime;

				/// Bluetooth %HID specific parameters
				namespace HID
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string KeyStrokeDelay;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AutoReconnect;
				}

				/// Bluetooth classic specific parameters
				namespace Classic
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string DeviceName;

					/// 
					namespace HID
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string KeyStrokeDelay;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AutoReconnect;
					}
				}

				/// BLE specific parameters
				namespace LowEnergy
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Security;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TxPower;
					_FEDM_ISC_CORE_EXT_CLASS extern const string LocalShortName;
				}
			}

			/// Data-Clock Port specific parameters
			namespace DataClock
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Format;

				/// %Wiegand specific parameters
				namespace Wiegand
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Delay;
					_FEDM_ISC_CORE_EXT_CLASS extern const string PulseWidth;
					_FEDM_ISC_CORE_EXT_CLASS extern const string PulseInterval;
				}
			}

			/// 
			namespace MultiDropBus
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string DeviceAddress;
				_FEDM_ISC_CORE_EXT_CLASS extern const string TerminalID;
			}

			/// 
			namespace IrDA
			{

				/// 
				namespace AccessPassword
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Password;
				}
			}

			/// %Miscellaneous communication interface parameters
			namespace Miscellaneous
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string ProtocolSelection;
			}
		}

		/// Configuration parameters for configuring the different working modes
		namespace OperatingMode
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
			_FEDM_ISC_CORE_EXT_CLASS extern const string EMVco;
			_FEDM_ISC_CORE_EXT_CLASS extern const string EMV;
			_FEDM_ISC_CORE_EXT_CLASS extern const string PowerOnMode;

			/// Configuration parameters for adjusting the Host-Mode (polling mode)
			namespace HostMode
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string InventoryAbortCondition;

				/// %Filter parameters
				namespace Filter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string ResponseMode;
				}
			}

			/// Common configuration parameters for adjusting any Auto Read Mode
			namespace AutoReadModes
			{

				/// %Trigger Parameters
				namespace Trigger
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				}

				/// Parameters for defining event layout
				namespace DataSelector
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Selector;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DataTidMem;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DataEpcMem;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DataUserMem;
					_FEDM_ISC_CORE_EXT_CLASS extern const string InputEvents;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderID;

					/// Parameters for defining event data
					namespace Mode
					{
					}
				}

				/// Parameters for defining event data
				namespace DataSource
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Engine;

					/// Parameters for defining event data from TID bank
					namespace TidBank
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					}

					/// Parameters for defining event data from EPC bank
					namespace EpcBank
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					}

					/// Parameters for defining event data from User bank
					namespace UserBank
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					}
				}

				/// Parameters for defining event buffer behaviour
				namespace DataBuffer
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string BatchMode;
				}

				/// Parameters for filtering event data
				namespace Filter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransponderValidTime;
				}
			}

			/// Configuration parameters for adjusting the Buffered-Read-Mode (auto-read mode)
			namespace BufferedReadMode
			{

				/// Parameters for selecting data items
				namespace DataSelector
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Selector;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Data;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EAS;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Time;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Date;
					_FEDM_ISC_CORE_EXT_CLASS extern const string InputEvents;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AFI;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Direction;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagStatistic;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RSSI;

					/// Parameters for adjusting the selected data items
					namespace Mode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_AntennaPool;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ReadCompleteBank;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SeekFunction;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ChangeAFI;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActionOnEPC;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ChangeEAS;
					}
				}

				/// Parameters for defining the sources of Transponder data
				namespace DataSource
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData;
				}

				/// Parameters for filtering event data
				namespace Filter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransponderValidTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input1Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input2Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input3Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input4Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input5Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_TriggerEvent;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_TimeoutEvent;
				}

				/// Parameters for defining trigger conditions
				namespace Trigger
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Condition;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UnlimitTransponderValidTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RFOffAfterRead;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoReadSignalization;

					/// Parameters for defining the trigger source
					namespace Source
					{

						/// Parameters for trigger source of type %Input
						namespace Input
						{

							/// 1st Input
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 2nd Input
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 3rd Input
							namespace No3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 4th Input
							namespace No4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 5th Input
							namespace No5
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}
						}
					}
				}

				/// Parameters for %EAS (Electronic Article Surveillance)
				namespace EAS
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagType;
				}

				/// 
				namespace SeekFunction
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaskStartAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NewAFI;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NewEAS;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Password;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Password;

					/// 
					namespace Mask
					{
					}
				}

				/// %Miscellaneous configuration parameters
				namespace Miscellaneous
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoRfReset;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Blacklist;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DetectionSensitivity;
				}

				/// 
				namespace Alarm
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Method;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagBank;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagValue;

					/// 
					namespace LED
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					}

					/// 
					namespace Buzzer
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					}
				}
			}

			/// Configuration parameters for adjusting the Notification-Mode (auto-read mode)
			namespace NotificationMode
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string InputMessage;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Interface;

				/// Parameters for selecting data items
				namespace DataSelector
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Selector;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Data;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EAS;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Time;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Date;
					_FEDM_ISC_CORE_EXT_CLASS extern const string InputEvents;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MacAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AFI;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Direction;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RSSI;

					/// Parameters for adjusting the selected data items
					namespace Mode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_AntennaPool;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ReadCompleteBank;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SeekFunction;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ChangeAFI;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActionOnEPC;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ChangeEAS;
					}
				}

				/// Parameters for defining the sources of Transponder data
				namespace DataSource
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{

						/// 
						namespace ISO_14443
						{

							/// 
							namespace Part4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData;
							}
						}
					}

					/// Access parameters for %Mifare Transponders
					namespace Mifare
					{

						/// Access parameters for Mifare %Classic Transponders
						namespace Classic
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyAddress;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyType;
						}

						/// Access parameters for Mifare %Ultralight Transponders
						namespace Ultralight
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyAddress;
						}

						/// Access parameters for Mifare %DESFire Transponders
						namespace DESFire
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyNumber;
							_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileType;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileNumber;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileCommSettings;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileOffset;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileLength;
						}

						/// 
						namespace Plus
						{

							/// 
							namespace SecurityLevel1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
							}

							/// 
							namespace SecurityLevel3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
								_FEDM_ISC_CORE_EXT_CLASS extern const string KeyType;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReadCommand;
								_FEDM_ISC_CORE_EXT_CLASS extern const string BlockNumber;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Ext;
								_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
								_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
								_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;
							}
						}
					}
				}

				/// 
				namespace AutoWrite
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string AFI1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AFI2;
				}

				/// Parameters for filtering event data
				namespace Filter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransponderValidTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input1Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input2Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input3Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input4Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Input5Event;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_TriggerEvent;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_TimeoutEvent;
				}

				/// Parameters for defining trigger conditions
				namespace Trigger
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Condition;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UnlimitTransponderValidTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RFOffAfterRead;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoReadSignalization;

					/// Parameters for defining the trigger source
					namespace Source
					{

						/// Parameters for trigger source of type %Input
						namespace Input
						{

							/// 1st Input
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 2nd Input
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 3rd Input
							namespace No3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 4th Input
							namespace No4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 5th Input
							namespace No5
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}
						}
					}
				}

				/// Parameters for %EAS (Electronic Article Surveillance)
				namespace EAS
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagType;
				}

				/// Parameters for defining transmission parameters
				namespace Transmission
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string ResponseTimeout;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NotifyTrigger;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TimeTriggeredTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DataSetsLimit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Acknowledge;

					/// Parameters for defining the transmission destination
					namespace Destination
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ConnectionHoldTime;

						/// %IPv4 specific connection parameters
						namespace IPv4
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
							_FEDM_ISC_CORE_EXT_CLASS extern const string TCP_UserTimeout;
						}

						/// %IPv6 specific connection parameters
						namespace IPv6
						{
						}
					}

					/// Keep-Alive specific parameters (important when network gets broken)
					namespace KeepAlive
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
						_FEDM_ISC_CORE_EXT_CLASS extern const string IntervalTime;
					}
				}

				/// 
				namespace SeekFunction
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaskStartAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NewAFI;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NewEAS;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Password;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Password;

					/// 
					namespace Mask
					{
					}
				}

				/// Parameters for defining event parameters of Gate-People-Counter
				namespace GatePeopleCounter
				{

					/// Parameters for defining transmission parameters
					namespace Transmission
					{

						/// Parameters for defining the transmission destination
						namespace Destination
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;

							/// %IPv4 specific connection parameters
							namespace IPv4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
							}
						}
					}
				}

				/// %Miscellaneous configuration parameters
				namespace Miscellaneous
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Blacklist;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DetectionSensitivity;
				}

				/// 
				namespace Alarm
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Method;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagBank;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagAddress;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagValue;

					/// 
					namespace LED
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					}

					/// 
					namespace Buzzer
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					}
				}
			}

			/// Configuration parameters for adjusting the Scan-Mode (auto-read mode)
			namespace ScanMode
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Interface;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Framing;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;

				/// Parameters for selecting data items
				namespace DataSelector
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Selector;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Data;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EAS;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Time;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Date;
					_FEDM_ISC_CORE_EXT_CLASS extern const string InputEvents;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ScannerID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MifareAppID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Direction;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RSSI;

					/// Parameters for adjusting the selected data items
					namespace Mode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_AntennaPool;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_IndependentTransmission;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ReadCompleteBank;
					}
				}

				/// Parameters for defining the sources of Transponder data
				namespace DataSource
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Engine;
					_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData_ProcessorCards;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;

					/// 
					namespace IDD
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Format;
					}

					/// Parameters for defining event data from TID bank
					namespace TidBank
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;
					}

					/// Parameters for defining event data from EPC bank
					namespace EpcBank
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Format;
					}

					/// Parameters for defining event data from User bank
					namespace UserBank
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Format;
					}

					/// Access parameters for %Mifare Transponders
					namespace Mifare
					{

						/// Access parameters for Mifare %Classic Transponders
						namespace Classic
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyAddress;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyType;
						}

						/// Access parameters for Mifare %DESFire Transponders
						namespace DESFire
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyNumber;
							_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileType;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileNumber;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileCommSettings;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileOffset;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileLength;
							_FEDM_ISC_CORE_EXT_CLASS extern const string EnableAuthentication;
						}

						/// 
						namespace PLUS
						{

							/// 
							namespace SecurityLevel1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
								_FEDM_ISC_CORE_EXT_CLASS extern const string EnableAuthentication;
							}

							/// 
							namespace SecurityLevel3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string KeyType;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReadCommand;
								_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
								_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
								_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
								_FEDM_ISC_CORE_EXT_CLASS extern const string EnableAuthentication;
							}
						}

						/// 
						namespace UltralightC
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyAddress;
							_FEDM_ISC_CORE_EXT_CLASS extern const string EnableAuthentication;
						}
					}

					/// Parameters for defining the data sources of ISO 15693 Transponder
					namespace ISO_15693
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;
					}
				}

				/// Parameters for formatting the data output
				namespace DataFormat
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string BusAddressPrefix;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Format;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DoNoTransmitPCofEPC;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfUserHeaderChars;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserHeaderChar1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserHeaderChar2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserHeaderChar3;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserHeaderChar4;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SeparationChar;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserSeparationChar;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EndChar;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfUserEndChars;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserEndChar;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserEndChar1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserEndChar2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UserEndChar3;
					_FEDM_ISC_CORE_EXT_CLASS extern const string UidInBcd;
					_FEDM_ISC_CORE_EXT_CLASS extern const string PrefixLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Prefix;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SuffixLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Suffix;
				}

				/// Parameters for filtering event data
				namespace Filter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string ResponseMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransponderValidTime;
				}

				/// Parameters for defining trigger conditions
				namespace Trigger
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Condition;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UnlimitTransponderValidTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RFOffAfterRead;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoReadSignalization;

					/// Parameters for defining the trigger source
					namespace Source
					{

						/// Parameters for trigger source of type %Input
						namespace Input
						{

							/// 1st Input
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 2nd Input
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 3rd Input
							namespace No3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 4th Input
							namespace No4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 5th Input
							namespace No5
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}
						}
					}
				}

				/// Parameters for %EAS (Electronic Article Surveillance)
				namespace EAS
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagType;
				}

				/// 
				namespace Transmission
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Timeout;

					/// 
					namespace Destination
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;

						/// 
						namespace IPv4
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Hostname;
						}
					}
				}
			}

			/// Configuration parameters for adjusting the Access-Mode (auto-read mode)
			namespace AccessMode
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Disable_TeachIn;

				/// 
				namespace Antipassback
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TimeOfDayForLockClearing;
				}

				/// 
				namespace AccessControl
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineRequest;
					_FEDM_ISC_CORE_EXT_CLASS extern const string RequestTimeout;
				}

				/// Parameters for selecting data items
				namespace DataSelector
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string UID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Data;
				}

				/// Parameters for defining the sources of Transponder data
				namespace DataSource
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstDataBlock;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;

					/// 
					namespace Miscellaneous
					{

						/// 
						namespace ISO_14443
						{

							/// 
							namespace Part4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ByteOrderOfData;
							}
						}
					}

					/// 
					namespace Mifare
					{

						/// 
						namespace Classic
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyAddress;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyType;
						}

						/// 
						namespace Ultralight
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyAddress;
						}

						/// Access parameters for Mifare %DESFire Transponders
						namespace DESFire
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
							_FEDM_ISC_CORE_EXT_CLASS extern const string KeyNumber;
							_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileType;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileNumber;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileCommSettings;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileOffset;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FileLength;
						}

						/// 
						namespace Plus
						{

							/// 
							namespace SecurityLevel1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
							}

							/// 
							namespace SecurityLevel3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Authentication;
								_FEDM_ISC_CORE_EXT_CLASS extern const string KeyType;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReaderKeyIndex;
								_FEDM_ISC_CORE_EXT_CLASS extern const string ReadCommand;
								_FEDM_ISC_CORE_EXT_CLASS extern const string BlockNumber;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Ext;
								_FEDM_ISC_CORE_EXT_CLASS extern const string AppID;
								_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
								_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfBytes;
							}
						}
					}
				}

				/// Parameters for filtering event data
				namespace Filter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransponderValidTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_EventNotification;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_AccessEvent;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_InputEvent;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_AlarmEvent;
				}

				/// Parameters for defining trigger conditions
				namespace Trigger
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Condition;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UnlimitTransponderValidTime;

					/// Parameters for defining the trigger source
					namespace Source
					{

						/// 
						namespace Input
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaAssignment;

							/// 
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}

							/// 
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerUse;
								_FEDM_ISC_CORE_EXT_CLASS extern const string HoldTime;
							}
						}
					}
				}

				/// Parameters for defining transmission parameters
				namespace Transmission
				{

					/// Parameters for defining the transmission destination
					namespace Destination
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string PortNumber;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ConnectionHoldTime;

						/// %IPv4 specific connection parameters
						namespace IPv4
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
						}
					}

					/// Keep-Alive specific parameters (important when network gets broken)
					namespace KeepAlive
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
						_FEDM_ISC_CORE_EXT_CLASS extern const string IntervalTime;
					}

					/// Parameters for formatting the data output
					namespace DataLayout
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string IDD;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TimeStamp;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Status;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Input;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}
				}
			}

			/// %Miscellaneous configuration parameters
			namespace Miscellaneous
			{

				/// %HF specific parameters
				namespace HF
				{

					/// 
					namespace ReaderSynchronization
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_Synchronization;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Is_Master;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SwitchCondition;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RfOffCondition;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SynchronizationTimeout;
					}
				}

				/// 
				namespace TransponderIdentification
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Source;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DataBlockNo;
					_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfDataBlocks;
				}

				/// 
				namespace Logging
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				}
			}

			/// 
			namespace Payment
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Interface;

				/// 
				namespace girogo
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Functions;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CreditDisplay;
					_FEDM_ISC_CORE_EXT_CLASS extern const string PaymentAck;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ConfirmPayment;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MerchantReferenceNo;

					/// 
					namespace AutomaticAccountReconciliation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string TransactionLimit;
					}

					/// 
					namespace SmartCard
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					}
				}
			}
		}

		/// Configuration parameters for adjusting the RF-Interface
		namespace AirInterface
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string TimeLimit;
			_FEDM_ISC_CORE_EXT_CLASS extern const string RFPower;
			_FEDM_ISC_CORE_EXT_CLASS extern const string RFProfile;
			_FEDM_ISC_CORE_EXT_CLASS extern const string ScanTime;

			/// Configuration parameters for adjusting the %Antennas
			namespace Antenna
			{

				/// %HF specific parameters
				namespace HF
				{

					/// Antenna output 1
					namespace No1
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string PowerOnTime;

						/// 
						namespace Filter
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string SensitivityLevel;
						}
					}

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_PowerUpTuning;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_DCPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string MinimumLevelMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string MinimumLevel;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_TagDetect;
					}
				}

				/// %UHF specific parameters
				namespace UHF
				{

					/// Antenna output 1
					namespace No1
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSIFilter;
					}

					/// Antenna output 2
					namespace No2
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSIFilter;
					}

					/// Antenna output 3
					namespace No3
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSIFilter;
					}

					/// Antenna output 4
					namespace No4
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSIFilter;
					}

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Gain;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Type;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_DCPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSIStartLevel;
					}

					/// 
					namespace Int
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputPower;
						_FEDM_ISC_CORE_EXT_CLASS extern const string RSSIFilter;
					}
				}
			}

			/// %Regional settings
			namespace Region
			{

				/// %UHF specific parameters
				namespace UHF
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Regulation;

					/// Settings for European Union regulation
					namespace EU
					{

						/// %Channel parameters
						namespace Channel
						{

							/// Settings for EN302208 with LBT
							namespace EN302208_with_LBT
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_865MHz1;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_865MHz3;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_865MHz5;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_865MHz7;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_865MHz9;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_866MHz1;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_866MHz3;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_866MHz5;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_866MHz7;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_866MHz9;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_867MHz1;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_867MHz3;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_867MHz5;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_867MHz7;
								_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_867MHz9;
							}

							/// Settings for EN302208 4-Channel-Plan
							namespace EN302208_4_ChannelPlan
							{

								/// Preferred channels for EN302208 4-Channel-Plan
								namespace PreferredChannels
								{
									_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfChannels;
									_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelNo1;
									_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelNo2;
									_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelNo3;
									_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelNo4;
								}
							}

							/// Settings for %EN300220
							namespace EN300220
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string Disable_869MHz_FallbackChannel;
							}

							/// 
							namespace Morocco
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelNo1;
							}
						}
					}

					/// Settings for %FCC regulation
					namespace FCC
					{

						/// %Channel parameters
						namespace Channel
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelAllocationMode;
							_FEDM_ISC_CORE_EXT_CLASS extern const string UpperChannel;
							_FEDM_ISC_CORE_EXT_CLASS extern const string LowerChannel;

							/// 
							namespace Japan
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string LowerChannel;
								_FEDM_ISC_CORE_EXT_CLASS extern const string UpperChannel;
							}
						}
					}

					/// Settings for %Korea regulation
					namespace Korea
					{

						/// %Channel parameters
						namespace Channel
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string LowerChannel;
							_FEDM_ISC_CORE_EXT_CLASS extern const string UpperChannel;
							_FEDM_ISC_CORE_EXT_CLASS extern const string ChannelAllocationMode;
						}
					}
				}
			}

			/// Configuration parameters for internal or external %Multiplexer
			namespace Multiplexer
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				_FEDM_ISC_CORE_EXT_CLASS extern const string EnableAntennas;
				_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedDefaultAntenna;

				/// %HF specific settings
				namespace HF
				{

					/// %External Multiplexer
					namespace External
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string SwitchCondition;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InputChannelMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfOutputChannels;

						/// Settings for %Antenna Outputs
						namespace Antenna
						{

							/// Output 1
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 2
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 3
							namespace No3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 4
							namespace No4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 5
							namespace No5
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 6
							namespace No6
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 7
							namespace No7
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 8
							namespace No8
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}
						}

						/// 
						namespace Output
						{

							/// 
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedAntennas;
							}
						}
					}
				}

				/// %UHF specific settings
				namespace UHF
				{

					/// %Internal Multiplexer
					namespace Internal
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string SwitchCondition;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaSelectionMode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfAntennas;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedAntennas;

						/// Settings for %Antenna Outputs
						namespace Antenna
						{

							/// Output 1
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 2
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 3
							namespace No3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}

							/// Output 4
							namespace No4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveTime;
							}
						}
					}

					/// %External Multiplexer
					namespace External
					{

						/// Settings for Antenna %Outputs
						namespace Output
						{

							/// Output 1
							namespace No1
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedAntennas;
							}

							/// Output 2
							namespace No2
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedAntennas;
							}

							/// Output 3
							namespace No3
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedAntennas;
							}

							/// Output 4
							namespace No4
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string SelectedAntennas;
							}
						}
					}
				}
			}

			/// %Miscellaneous configuration parameters
			namespace Miscellaneous
			{

				/// %HF specific parameters
				namespace HF
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Modulation;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReceiverChannel;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReceiverSensitivity;

					/// Settings for ISO 15693 and/or ICode1
					namespace ISO_15693_ICode1
					{

						/// Settings for error handling
						namespace ErrorHandling
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string WeakCollision;
						}
					}

					/// Settings for ICode UID and ICode EPC
					namespace ICodeUID_ICodeEPC
					{

						/// Settings for error handling
						namespace ErrorHandling
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string WeakCollision;
						}
					}

					/// Settings for ISO 15693
					namespace ISO_15693
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Modulation;
						_FEDM_ISC_CORE_EXT_CLASS extern const string SubCarrier;
					}

					/// Settings for error handling
					namespace ISO_18000_3M3
					{

						/// Settings for ISO 18000-3M3
						namespace ErrorHandling
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string WeakCollision;
						}
					}

					/// 
					namespace ASK_Modulation
					{

						/// Settings for error handling
						namespace ErrorHandling
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string WeakCollision;
						}
					}

					/// 
					namespace NoiseLevel
					{
					}
				}
			}
		}

		/// Configuration parameters for %Transponder drivers
		namespace Transponder
		{

			/// Transponder %Driver
			namespace Driver
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_HF;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UHF;

				/// %HF Drivers (in fixed execution order)
				namespace HF
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Selector;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Drivers;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ICode1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Tagit_HF;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ISO_15693;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ISO_14443_TypeA;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ISO_14443_TypeB;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ICodeEPC;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ICodeUID;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EPC_Class1Gen2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Jewel;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SR176;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SRIxx;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Microchip_MCRF45x;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Keyboard;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ISO_18000_3M3;
					_FEDM_ISC_CORE_EXT_CLASS extern const string FeliCa;

					/// Drivers, in execution order defined by user
					namespace UserSequenced
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string No1;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No2;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No3;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No4;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No5;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No6;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No7;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No8;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No9;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No10;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No11;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No12;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No13;
						_FEDM_ISC_CORE_EXT_CLASS extern const string No14;
					}

					/// Sub-Drivers for ISO 14443
					namespace ISO_14443
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Drivers;

						/// Sub-Drivers for ISO 14443, Part A
						namespace TypeA
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string MifareStandard;
							_FEDM_ISC_CORE_EXT_CLASS extern const string my_d_Proximity_SLE55Rxx;
							_FEDM_ISC_CORE_EXT_CLASS extern const string MifareUltraLight;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Part4;
						}
					}
				}

				/// %UHF Driver
				namespace UHF
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Drivers;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ISO_18000_6_B;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EM4222_EM4444;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EPC_Class1Gen1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EPC_Class1Gen2;
				}
			}

			/// Anticollission settings
			namespace Anticollision
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
			}

			/// Persistence Reset settings
			namespace PersistenceReset
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;

				/// Settings for %Antenna outputs
				namespace Antenna
				{

					/// Output 1
					namespace No1
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string PersistenceResetTime;
					}

					/// Output 2
					namespace No2
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string PersistenceResetTime;
					}

					/// Output 3
					namespace No3
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string PersistenceResetTime;
					}

					/// Output 4
					namespace No4
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string PersistenceResetTime;
					}
				}
			}

			/// Configuration parameters for %HF Transponders
			namespace HF
			{

				/// I-Code1 specific settings
				namespace ICode1
				{

					/// %Anticollision settings
					namespace Anticollision
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string MaximalTimeslots;
						_FEDM_ISC_CORE_EXT_CLASS extern const string MinimalTimeslots;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Timeslots;
					}

					/// Link settings
					namespace LinkRate
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FastMode;
					}

					/// Mask settings
					namespace SelectionMask
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FamilyCode;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ApplicationIdentifier;
					}

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string MemoryMapping;
						_FEDM_ISC_CORE_EXT_CLASS extern const string EASLevel;
					}
				}

				/// ISO 15693 specific settings
				namespace ISO_15693
				{

					/// %Anticollision settings
					namespace Anticollision
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string NoOfTimeslots;
					}

					/// Link settings
					namespace LinkRate
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string DataCoding;
						_FEDM_ISC_CORE_EXT_CLASS extern const string DataRate;
					}

					/// Mask settings
					namespace SelectionMask
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_AFI;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AFI1;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AFI2;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AFI3;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AFI4;
					}

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string WriteOption;
						_FEDM_ISC_CORE_EXT_CLASS extern const string CommandBreak;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Modulation;

						/// Settings for reading Transponder data
						namespace ReadOption
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string ReadMode;
							_FEDM_ISC_CORE_EXT_CLASS extern const string BlockSizeSelection;
							_FEDM_ISC_CORE_EXT_CLASS extern const string BlockSize;
						}
					}
				}

				/// ICode UID and ICode EPC specific settings
				namespace ICodeUID_ICodeEPC
				{

					/// %Anticollision settings
					namespace Anticollision
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string MinimalTimeslots;
						_FEDM_ISC_CORE_EXT_CLASS extern const string MaximalTimeslots;
					}

					/// Mask settings
					namespace SelectionMask
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
					}
				}

				/// EPC Class1 Gen2 specific settings
				namespace EPC_Class1Gen2
				{

					/// %Anticollision settings
					namespace Anticollision
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Session;
					}
				}

				/// ISO 14443 specific settings
				namespace ISO_14443
				{

					/// Link settings
					namespace Bitrate
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Transmit;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Receive;
					}

					/// ISO 14443, Part 4 specific settings
					namespace Part4
					{

						/// %Miscellaneous configuration parameters
						namespace Miscellaneous
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string PowerLevelCheck;
							_FEDM_ISC_CORE_EXT_CLASS extern const string ErrorRetry;
						}
					}

					/// ISO 14443, Type A specific settings
					namespace TypeA
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OptionalInventoryInfo;
						_FEDM_ISC_CORE_EXT_CLASS extern const string UID_Order;
					}

					/// ISO 14443, Type B specific settings
					namespace TypeB
					{

						/// Mask settings
						namespace SelectionMask
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AFI;
						}

						/// %Miscellaneous configuration parameters
						namespace Miscellaneous
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string BitrateSelect;
						}
					}

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string StartupTime;
					}
				}

				/// ISO 18000-3M3 specific settings
				namespace ISO_18000_3M3
				{

					/// Mask settings
					namespace SelectionMask
					{

						/// 1st Mask
						namespace No1
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string Bank;
							_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FirstBit;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
						}
					}

					/// 
					namespace Anticollision
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Session;
					}
				}

				/// Configuration parameters for Transponder-specific Custom-Commands
				namespace CustomerCommandOptions
				{

					/// EM Microelectronic-Marin SA
					namespace EM_Microelectronic
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string StorageQuiet;
					}

					/// %Fujitsu Limited
					namespace Fujitsu
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string FastInventory;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FastCommands;
					}

					/// %Infineon Technologies AG
					namespace Infineon
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string ReadWrite_Commands;
					}

					/// %NXP Semiconductors
					namespace NXP
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string Disable;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FastReturnLink;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InventoryReadPage;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InventoryReadBlock;
						_FEDM_ISC_CORE_EXT_CLASS extern const string LongRangeCommand;
					}

					/// %STMicroelectronics SA
					namespace STMicroelectronics
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string InitiateInventory;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FastCommands;
					}

					/// Texas Instruments
					namespace Texas_Instruments
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string InventoryReadBlock;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FastSID;
					}
				}
			}

			/// Configuration parameters for %UHF Transponders
			namespace UHF
			{

				/// ISO 18000-6B specific settings
				namespace ISO_18000_6_B
				{

					/// Link settings
					namespace LinkRate
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string ReturnLinkBitrate;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ForwardLinkModulation;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ForwardLinkBitrate;
					}

					/// Mask settings
					namespace SelectionMask
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstByte;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Operation;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
					}
				}

				/// EPC Class1 Gen1 specific settings
				namespace EPC_Class1Gen1
				{

					/// Link settings
					namespace LinkRate
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string ReturnLinkBitrate;
						_FEDM_ISC_CORE_EXT_CLASS extern const string UidLength;
					}

					/// Mask settings
					namespace SelectionMask
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
						_FEDM_ISC_CORE_EXT_CLASS extern const string FirstBit;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
					}
				}

				/// EPC Class1 Gen2 specific settings
				namespace EPC_Class1Gen2
				{

					/// %Anticollision settings
					namespace Anticollision
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AnticollisionStartValue;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Session;
					}

					/// Link settings
					namespace LinkRate
					{
					}

					/// Mask settings
					namespace SelectionMask
					{

						/// 1st Mask
						namespace No1
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
							_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FirstBit;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Negation;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_EPCTruncation;
						}

						/// 2nd Mask
						namespace No2
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
							_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FirstBit;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Negation;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Logic;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_EPCTruncation;
						}

						/// 3rd Mask
						namespace No3
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string BankNo;
							_FEDM_ISC_CORE_EXT_CLASS extern const string MaskLength;
							_FEDM_ISC_CORE_EXT_CLASS extern const string FirstBit;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Mask;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Negation;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Logic;
							_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_EPCTruncation;
						}
					}

					/// %Miscellaneous configuration parameters
					namespace Miscellaneous
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string WriteOption;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagAuthent;
					}
				}
			}

			/// %Miscellaneous configuration parameters
			namespace Miscellaneous
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string IdentifierInterpretationMode;
				_FEDM_ISC_CORE_EXT_CLASS extern const string TIDLength;
			}
		}

		/// Configuration parameters for %Barcodes
		namespace Barcode
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string Aiming;
			_FEDM_ISC_CORE_EXT_CLASS extern const string Light;
			_FEDM_ISC_CORE_EXT_CLASS extern const string VideoReverse;
			_FEDM_ISC_CORE_EXT_CLASS extern const string ScanTime;
			_FEDM_ISC_CORE_EXT_CLASS extern const string DisplayMode;
			_FEDM_ISC_CORE_EXT_CLASS extern const string MirroredImage;
			_FEDM_ISC_CORE_EXT_CLASS extern const string PicklistMode;
			_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCodeIDCharacter;

			/// Configuration parameters for read sensitivity
			namespace Sensitivity
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Threshold;
			}

			/// Configuration parameters for 1D-Barcodes
			namespace Type1D
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Inverse;

				/// AIM 128 parameters
				namespace AIM_128
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
				}

				/// %Codabar parameters
				namespace Codabar
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Letter;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitStartStopCharacters;
					_FEDM_ISC_CORE_EXT_CLASS extern const string StartStopCharacters;
				}

				/// Code 11 parameters
				namespace Code_11
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CheckDigitVerification;
				}

				/// Code 39 parameters
				namespace Code_39
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ASCIIDecode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CheckDigitVerification;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ConvertCode39ToCode32;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReducedQuietZone;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCode32Prefix;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitStartStopCharacters;
				}

				/// Code 93 parameters
				namespace Code_93
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// Code 128 parameters
				namespace Code_128
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReducedQuietZone;
				}

				/// EAN-8 parameters
				namespace EAN_8
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ExpandToEAN_13;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AddOnCodeRequired;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable2BitsExpandCharacters;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable5BitsExpandCharacters;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// EAN-13 parameters
				namespace EAN_13
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AddOnCodeRequired;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable2BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable5BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// GS1-128 parameters
				namespace GS1_128
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				}

				/// GS1-Databar parameters
				namespace GS1_DataBar
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitApplicationID;
				}

				/// Industrial-25 parameters
				namespace Industrial_25
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// ITF 2-of-5 parameters
				namespace Interleaved_2of5
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Length2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CheckDigitVerification;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReducedQuietZone;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit_ITF_6;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit_ITF_14;
				}

				/// %ISBN parameters
				namespace ISBN
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AddOnCodeRequired;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable2BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable5BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Format;
				}

				/// ISBT-128 parameters
				namespace ISBT_128
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				}

				/// %ISSN parameters
				namespace ISSN
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				}

				/// ITF-6 parameters
				namespace ITF_6
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				}

				/// ITF-14 parameters
				namespace ITF_14
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
				}

				/// Matrix-25 parameters
				namespace Matrix_25
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// MSI-Plessey parameters
				namespace MSI_Plessey
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CheckDigitVerification;
				}

				/// %Plessey parameters
				namespace Plessey
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// Standard-25 parameters
				namespace Standard_25
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// %UPC parameters
				namespace UPC
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string ReducedQuietZone;
				}

				/// UPC-A parameters
				namespace UPC_A
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AddOnCodeRequired;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable2BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable5BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitPrecursor;
				}

				/// UPC-E parameters
				namespace UPC_E
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ExpandToUPC_A;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AddOnCodeRequired;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable2BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable5BitsAddendaCode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitPrecursor;
				}

				/// UPC-E1 parameters
				namespace UPC_E1
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransmitCheckDigit;
				}

				/// UCC EAN-128 parameters
				namespace UCC_EAN_128
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
				}
			}

			/// Configuration parameters for 2D-Barcodes
			namespace Type2D
			{

				/// %Aztec parameters
				namespace Aztec
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Inverse;
				}

				/// Datamatrix parameters
				namespace DataMatrix
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Inverse;
					_FEDM_ISC_CORE_EXT_CLASS extern const string DisableRectangularSymbols;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MirrorImages;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SingleTwin;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ForwardBackward;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EnableECIOutput;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CharacterEncoding;
				}

				/// PDF 417 parameters
				namespace PDF417
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SingleTwin;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ForwardBackward;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EnableECIOutput;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CharacterEncoding;
				}

				/// QR-Code parameters
				namespace QR_Code
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SingleTwin;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ForwardBackward;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EnableECIOutput;
					_FEDM_ISC_CORE_EXT_CLASS extern const string CharacterEncoding;
				}

				/// %DotCode parameters
				namespace DotCode
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Inverse;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mirrored;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Prioritize;
				}

				/// Chinese Sensible Code parameters
				namespace Chinese_Sensible_Code
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MinMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string MaxMessageLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SingleTwin;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ForwardBackward;
				}
			}
		}

		/// Configuration parameters for digital inputs and outputs, Relays and LEDs
		namespace DigitalIO
		{

			/// Settings for digital buttons
			namespace Button
			{

				/// Settings for trigger button
				namespace Trigger
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_UnlockTrigger;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Function;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransferStringLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransferString;
				}

				/// Settings for left button
				namespace Left
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_PowerOff;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Function;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransferStringLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransferString;
				}

				/// Settings for right button
				namespace Right
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_PowerOff;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Function;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransferStringLength;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TransferString;
				}
			}

			/// Settings for digital inputs
			namespace Input
			{

				/// No 1
				namespace No1
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				}

				/// No 2
				namespace No2
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				}

				/// No 3
				namespace No3
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				}

				/// No 4
				namespace No4
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				}

				/// No 5
				namespace No5
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				}
			}

			/// Settings for digital outputs
			namespace Output
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineDelay;
				_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectActiveTime;

				/// No 1
				namespace No1
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;

					/// Event link
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}

					/// Settings for Access-Mode
					namespace AccessMode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
					}
				}

				/// No 2
				namespace No2
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;

					/// Event link
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}

					/// 
					namespace AccessMode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
					}
				}

				/// No 3
				namespace No3
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
				}
			}

			/// Settings for %Relays
			namespace Relay
			{

				/// No 1
				namespace No1
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;

					/// Event link
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}

					/// Settings for Access-Mode
					namespace AccessMode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
					}
				}

				/// No 2
				namespace No2
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;

					/// Event link
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}
				}

				/// No 3
				namespace No3
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;

					/// Event link
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}
				}

				/// No 4
				namespace No4
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashMode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;

					/// Event link
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}
				}
			}

			/// Settings for %Signalers/Buzzers
			namespace Signaler
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineDelay;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_StartupSignal;
				_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectActiveTime;
				_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmTimeout;

				/// Automatic activation by sources
				namespace EventSource
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineDetect;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetect;
					_FEDM_ISC_CORE_EXT_CLASS extern const string StartupSignal;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Input1;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Input2;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Input3;
				}

				/// Settings for %Buzzers
				namespace Buzzer
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashFrequency;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveFlashFrequency;
					_FEDM_ISC_CORE_EXT_CLASS extern const string InputFlashFrequency;
					_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineFlashFrequency;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationSources;
					_FEDM_ISC_CORE_EXT_CLASS extern const string Volume;

					/// Settings for Access-Mode
					namespace AccessMode
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedActiveTime;
						_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmState;
					}
				}

				/// Settings for %Vibrators
				namespace Vibrator
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveFlashFrequency;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationTime;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationSources;
				}

				/// Settings for %LEDs
				namespace LED
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;

					/// %Blue LED
					namespace Blue
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string IdleState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationTime;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveFlashFrequency;

						/// Settings for Access-Mode
						namespace AccessMode
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessState;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedState;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedActiveTime;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmState;
						}
					}

					/// %Green LED
					namespace Green
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string IdleState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InputFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationTime;

						/// Settings for Access-Mode
						namespace AccessMode
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessState;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedState;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedActiveTime;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmState;
						}
					}

					/// %Yellow LED
					namespace Yellow
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InputEventActivation;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OutputEventActivation;
						_FEDM_ISC_CORE_EXT_CLASS extern const string Time;
					}

					/// %Red LED
					namespace Red
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string IdleState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string IdleFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string InputFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineFlashFrequency;
						_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationTime;

						/// Settings for Access-Mode
						namespace AccessMode
						{
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessState;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedState;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessActiveTime;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedActiveTime;
							_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmState;
						}
					}

					/// LED No 1
					namespace No1
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}

					/// LED No 2
					namespace No2
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}

					/// LED No 3
					namespace No3
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}

					/// LED No 4
					namespace No4
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}

					/// LED No 5
					namespace No5
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}

					/// LED No 6
					namespace No6
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}

					/// LED No 7
					namespace No7
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string OnlineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string OfflineState;
						_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					}
				}

				/// Settings for traffic lights
				namespace TrafficLight
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
					_FEDM_ISC_CORE_EXT_CLASS extern const string IdleState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TagDetectState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActiveFlash;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AccessState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedState;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AccessFlash;
					_FEDM_ISC_CORE_EXT_CLASS extern const string AccessDeniedFlash;
					_FEDM_ISC_CORE_EXT_CLASS extern const string ActivationTime;

					/// 
					namespace ReadEventActivation
					{
						_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
					}
				}
			}

			/// %Miscellaneous configuration parameters
			namespace Miscellaneous
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string AFIAssignment;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_CPRIO;
				_FEDM_ISC_CORE_EXT_CLASS extern const string Enable_CPRMUX;
			}
		}

		/// Configuration parameters for adjusting the power consumption
		namespace PowerManagement
		{
			_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
			_FEDM_ISC_CORE_EXT_CLASS extern const string WakeUpPulse;
			_FEDM_ISC_CORE_EXT_CLASS extern const string PowerOnTime;
			_FEDM_ISC_CORE_EXT_CLASS extern const string AutoPowerOff;
			_FEDM_ISC_CORE_EXT_CLASS extern const string RFOnMode;
			_FEDM_ISC_CORE_EXT_CLASS extern const string RFOnTime_Min;
			_FEDM_ISC_CORE_EXT_CLASS extern const string RFOnTime_Max;
			_FEDM_ISC_CORE_EXT_CLASS extern const string RfOffTime;
		}

		/// Configuration parameters for internal clock or timer
		namespace Clock
		{

			/// Settings for Network Time Protocol
			namespace NetworkTimeProtocol
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Mode;
				_FEDM_ISC_CORE_EXT_CLASS extern const string TriggerTime;

				/// %IPv4 specific settings
				namespace IPv4
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string IPAddress;
				}

				/// %IPv6 specific settings
				namespace IPv6
				{
				}
			}
		}

		/// Configuration parameters for Peripheral Devices, like People-Counter
		namespace PeripheralDevice
		{

			/// 
			namespace GatePeopleCounter
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string DirectionMode;
				_FEDM_ISC_CORE_EXT_CLASS extern const string DetectionMode;
				_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaType;

				/// 
				namespace TriggerFilter
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string TimeLimit_BeforeTagDetection;
					_FEDM_ISC_CORE_EXT_CLASS extern const string TimeLimit_AfterTagDetection;
				}

				/// 
				namespace Mode
				{
					_FEDM_ISC_CORE_EXT_CLASS extern const string EnableGPC;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EnableIO;
					_FEDM_ISC_CORE_EXT_CLASS extern const string EnableNotifyCounter;
				}

				/// 
				namespace BusAddr1
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}

						/// 
						namespace No2
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}

						/// 
						namespace No3
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr2
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}

						/// 
						namespace No2
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}

						/// 
						namespace No3
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr3
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}

						/// 
						namespace No2
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}

						/// 
						namespace No3
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}
			}

			/// 
			namespace LedController
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string AlarmColor;

				/// 
				namespace BusAddr11
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr12
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr13
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr14
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr15
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr16
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}

				/// 
				namespace BusAddr17
				{

					/// 
					namespace Output
					{

						/// 
						namespace No1
						{

							/// 
							namespace ReadEventActivation
							{
								_FEDM_ISC_CORE_EXT_CLASS extern const string AntennaNo;
							}
						}
					}
				}
			}

			/// 
			namespace Output
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingMode;
				_FEDM_ISC_CORE_EXT_CLASS extern const string SettlingTime;
			}
		}

		/// Additional tools
		namespace SystemTools
		{

			/// %Linux specific tools
			namespace Linux
			{
				_FEDM_ISC_CORE_EXT_CLASS extern const string Telnet;
				_FEDM_ISC_CORE_EXT_CLASS extern const string ssh;
				_FEDM_ISC_CORE_EXT_CLASS extern const string WebServer;
				_FEDM_ISC_CORE_EXT_CLASS extern const string FTPServer;
			}
		}

	}
}

#endif // _FEDM_READER_CONFIG_PARA_H_INCLUDED_
