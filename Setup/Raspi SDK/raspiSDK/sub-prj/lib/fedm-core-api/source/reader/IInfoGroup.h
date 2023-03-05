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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IREADER_INFO_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IREADER_INFO_GROUP_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "../source/i_scan/FEDM_ISCReaderInfo.h"
#include "../source/i_scan/FEDM_ISCReaderDiagnostic.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing Reader info specific methods
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for requesting general information for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [IInfo](@ref FEDM::Core::ReaderModule::IInfo) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IInfoGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;

		public:

			/// @brief Class for collecting all reader information
			///
			/// <b>Description</b><br>
			/// This class contains all data values, which are potentially part of the Reader&apos;s response of the command [0x66] Reader Info.<br>
			class _FEDM_ISC_CORE_EXT_CLASS ReaderInfo
			{

				friend class IInfoGroup;

			// public methods
			public:
				/// constructor
				ReaderInfo();

				/// returns the status of the Reader information data
				bool IsValid() const;

				/// Request of Reader Type Number. All Reader Type Numbers are listed in [Const::ReaderType](@ref FEDM::Core::Const::ReaderType)
				unsigned int GetReaderType() const;

				/// Returns true, if Reader can handle ISO 14443 transponder
				bool IsISO14443Reader() const;
				/// Returns true, if Reader can handle ISO 15693 transponder
				bool IsISO15693Reader() const;
				/// Returns true, if Reader can handle ISO 18000-3M3 transponder
				bool IsISO180003m3Reader() const;
				/// Returns true, if Reader can handle EPC Class1 Gen2 transponder
				bool IsEPCC1G2Reader() const;

				/// Returns true, if Reader is part of IDENTIFICATION HF family (ISO 14443, ISO 15693 and ISO 18000-3M3)
				bool IsHfReader() const;
				/// Returns true, if Reader is part of IDENTIFICATION UHF family (EPC Class1 Gen2)
				bool IsUhfReader() const;

				/// Returns size of RF-Controller receive buffer
				unsigned int GetRxBufferSize() const;

				/// Returns size of RF-Controller transmit buffer
				unsigned int GetTxBufferSize() const;

				/// Return of Device-ID (decimal)
				unsigned int GetDeviceID() const;

				/// Return the number of Reader's configuration pages
				unsigned int GetNoOfCfgPages() const;

				/// Returns a report with complete Reader information
				std::string GetReport() const;

				/** @brief Returns a partial report with Reader information
				*
				* @param[in] ucMode mode byte in command [0x66] Reader Info
				* @return string with partial report
				*
				* <b>Description</b><br>
				* This method returns a partial report, based on information which must be previously read from the Reader with the command
				* [0x66] Reader Info.<br>
				* Use [SendProtocol](@ref FEDM::Core::ICommandGroup::SendProtocol) or [ReadReaderInfo](@ref ReadReaderInfo) to read the information.<br>
				* See Reader&apos;s System Manual for the list with all supported mode bytes.
				*/
				std::string GetPartialReport(unsigned char ucMode) const;

			// protected methods
			protected:
				void Init(FEDM_ISCReaderModule* pReader, FEDM_ISC_READER_INFO* pInfo);
				void Clear();

			private:
				FEDM_ISCReaderModule* m_pReader;

			// public data members
			public:

				/// Information from RF-Controller requested with command [0x66] and Mode=0x00
				struct RfcFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSwVer[2];						///< major and minor version number of RFC
					unsigned char	ucDevVer;						///< developer version number of RFC
					unsigned char	ucHwType;						///< flag field with hardware options of RFC
					unsigned char	ucSwType;						///< Reader Type = SW-TYPE of protcol
					unsigned char	ucTrType[2];					///< flag field with supported Transponder types
					unsigned char	ucRxBufferSize[2];				///< size of Reader's receive buffer
					unsigned char	ucTxBufferSize[2];				///< size of Reader's transmit buffer
					unsigned char	ucUhfTrType[2];					///< additional flag field with supported UHF Transponder types
					unsigned char	ucReaderRevision;				///< [0x66] and Mode=0x00: additional reader information
					unsigned char	ucReaderAssembly;				///< [0x66] and Mode=0x00: additional reader information
					unsigned char	ucPrtFrameSupport;				///< [0x66] and Mode=0x00: protocol frame support
					unsigned char	ucCfgConfigID[4];				///< [0x66] and Mode=0x00: configuration ID (layout ID, custom ID, version high, version low)
				} RfcFw;

				/// Information from AC-Controller requested with command [0x66] and Mode=0x01
				struct AccFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSwVer[2];						///< major and minor version number of ACC
					unsigned char	ucDevVer;						///< developer version number of ACC
					unsigned char	ucHwType;						///< flag field with hardware options of ACC
					unsigned char	ucEmbAppSwVer[2];				///< major and minor version number of 2nd embedded application inside ACC
					unsigned char	ucEmbAppDevVer;					///< developer version number of 2nd embedded application inside ACC
				} AccFw;

				/// Information from USB-Controller requested with command [0x66] and Mode=0x02
				struct UsbFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSwVer[2];						///< major and minor version number of USB controller
					unsigned char	ucDevVer;						///< developer version number of USB controller
					unsigned char	ucHwType;						///< flag field with hardware options of USB controller
				} UsbFw;

				/// Information from FPGA requested with command [0x66] and Mode=0x03
				struct FpgaFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSwVer[2];						///< major and minor version number of FPGA/RF-Decoder
					unsigned char	ucDevVer;						///< developer version number of FPGA/RF-Decoder
					unsigned char	ucHwType;						///< flag field with hardware options of FPGA/RF-Decoder
				} FpgaFw;

				/// HF-Decoder Information requested with command [0x66] and Mode=0x03
				struct CprDecoderInfo
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucDecoderType[5];				///< decoder information
					unsigned char	ucSelfTest;						///< selt test result
				} CprDecoderInfo;

				/// Additional firmware functionality requested with command [0x66] and Mode=0x04
				struct CprFwFunction
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucFctTemplate;					///< template for classic-pro Reader
					unsigned char	ucFctList0;						///< flag field with function list
					unsigned char	ucFctList1;						///< flag field with function list
					unsigned char	ucFctList2;						///< flag field with function list
					//unsigned char	ucCprRfu0;						///< reserved
					//unsigned char	ucCprRfu1;						///< reserved
					//unsigned char	ucCprRfu2;						///< reserved
					//unsigned char	ucCprRfu3;						///< reserved
					//unsigned char	ucCprRfu4;						///< reserved
					unsigned char	ucFwIdentifier[2];				///< firmware identifier
				} CprFwFunction;
	
				/// Information from bootloader requested with command [0x66] and Mode=0x05
				struct BootFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSwVer[2];						///< major and minor version number of Bootloader
					unsigned char	ucDevVer;						///< developer version number of Bootloader
				} BootFw;

				/// Information from keyboard unit requested with command [0x66] and Mode=0x06
				struct KeyboardFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucStatus[2];					///< 2 byte with status flags of Keyboard
					unsigned char	ucSwVer[2];						///< major and minor version number of Keyboard
					unsigned char	ucHwVer[4];						///< hardware version of Keyboard
				} KeyboardFw;

				/// Information from CPRIO unit requested with command [0x66] and Mode=0x07
				struct CprioFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSwVer[2];						///< major and minor version number of CPRIO
					unsigned char	ucHwVer;						///< hardware revison number of CPRIO
					unsigned char	ucNoOfInputs;					///< number of inputs of CPRIO
					unsigned char	ucNoOfOutputs;					///< number of outputs of CPRIO
					unsigned char	ucNoOfRelays;					///< number of relays of CPRIO
					unsigned char	ucNoOfSignalers;				///< number of signalers of CPRIO
				} CprioFw;

				/// Information with supported tag drivers requested with command [0x66] and Mode=0x08
				struct CprTrDriver
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucSupportedTagDriver[14];		///< with firmware supported tag drivers
				} CprTrDriver;

				/// Command=[0x66] Mode=[0x0A]: Bluetooth Info
				struct BluetoothFw
				{
					bool			isValid;
					unsigned char	ucSwVer[2];						///< major and minor version number of WLAN and Bluetooth controller
					unsigned char	ucDevVer;						///< developer version number of WLAN and Bluetooth controller
				} BluetoothFw;

				/// Command=[0x66] Mode=[0x0B]: Barcode Info
				struct BarcodeFw
				{
					bool			isValid;
					unsigned char	ucVersion[30];					///< barcode information according system manual
					//unsigned char	ucSwVer[2];						///< major and minor version number of Barcode controller
					//unsigned char	ucDevVer[2];					///< developer version of Barcode controller
				} BarcodeFw;

				/// Hardware information of RF-Controller requested with command [0x66] and Mode=0x10
				struct HwInfo
				{
					bool			isValid;						///< indicates valid data members
					bool			isFrequencyValid;				///< indicates, if RFC Frequency is read
					unsigned char	ucHwInfo[2];					///< flag field with hardware info
					unsigned char	ucDHw[2];						///< for internal use
					unsigned char	ucAHw[2];						///< for internal use
					unsigned char	ucFrequency;					///< frequency information (HF, UHF, .., EU, FCC)
					unsigned char	ucPortTypes;					///< flag field with supported port types
					//unsigned char	ucReserved2;					///< reserved byte
					unsigned char	ucRfcInfo;						///< RFC info
				} HwInfo;

				/// SAM information of RC-Controller requested with command [0x66] and Mode=0x11
				struct SamInfo
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucNoOfSlots;					///< number of installed SAM slots
					unsigned char	ucSlotInfo[4];					///< slot info for each SAM
				} SamInfo;

				/// General CPU information of RF-Controller requested with command [0x66] and Mode=0x12
				struct CpuInfo
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucManufacturer;					///< manufacturer id
					unsigned char	ucType[2];						///< cpu type id
					unsigned char	ucRevision;						///< cpu revision code
					unsigned char	ucFlashSize[4];					///< size in KB of flash
				} CpuInfo;
	
				/// RF-Stack Firmware Version requested with command [0x66] and Mode=0x15
				struct RfStackFw
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucRfStackSwVer[2];				///< major and minor version number of RF-Stack
					unsigned char	ucISO7816StackSwVer[2];			///< major and minor version number of ISO7816-Stack
				} RfStackFw;

				/// IDT Firmware Version requested with command [0x66] and Mode=0x16
				struct IDTFw
				{
					bool			isValid;
					unsigned char	ucSwVer[2];						///< major and minor version number of IDT Firmware
				} IDTFw;

				/// CFG information with read and write permission requested with command [0x66] and Mode=0x40 and Mode=0x41
				struct CfgInfo
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucNoOfCfgPages[2];				///< number of configuration pages
					unsigned char	ucReadPermissions[18];			///< flag field with readable CFG pages
					unsigned char	ucWritePermissions[18];			///< flag field with writeable CFG pages
				} CfgInfo;

				/// Information with LAN capabilities requested with command [0x66] and Modes=0x50 ... 0x53
				struct LanInfo
				{
					/// Information with MAC for LAN requested with command [0x66] and Mode=0x50
					struct Mac
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucFlags;					///< flags
						unsigned char	ucMac[6];					///< media access control
					} Mac;

					/// Information with IP Address for LAN requested with command [0x66] and Mode=0x51
					struct IpAddress
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucV4[4];					///< IP Address V4
						//unsigned char	ucV6[16];					///< IP Address V6
					} IpAddress;

					/// Information with netmask for LAN requested with command [0x66] and Mode=0x52
					struct NetMask
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucV4[4];					///< netmask V4
						//unsigned char	ucV6[16];					///< netmask V6
					} NetMask;

					/// Information with Gateway Address for LAN requested with command [0x66] and Mode=0x53
					struct Gateway
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucV4[4];					///< Gateway Address V4
						//unsigned char	ucV6[16];					///< Gateway Address V6
					} Gateway;
				} LanInfo;

				/// Information with WLAN capabilities requested with command [0x66] and Modes=0x54 ... 0x57
				struct WlanInfo
				{
					/// Information with MAC for WLAN requested with command [0x66] and Mode=0x54
					struct Mac
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucFlags;					///< flags
						unsigned char	ucMac[6];					///< media access control
					} Mac;

					/// Information with IP Address for WLAN requested with command [0x66] and Mode=0x55
					struct IpAddress
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucV4[4];					///< IP Address V4
						//unsigned char	ucV6[16];					///< IP Address V6
					} IpAddress;

					/// Information with netmask for WLAN requested with command [0x66] and Mode=0x56
					struct NetMask
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucV4[4];					///< netmask V4
						//unsigned char	ucV6[16];					///< netmask V6
					} NetMask;

					/// Information with Gateway Address for LAN requested with command [0x66] and Mode=0x57
					struct Gateway
					{
						bool			isValid;					///< indicates valid data members
						unsigned char	ucV4[4];					///< Gateway Address V4
						//unsigned char	ucV6[16];					///< Gateway Address V6
					} Gateway;
				} WlanInfo;

				/// Information with MAC for Bluetooth requested with command [0x66] and Mode=0x58
				struct BluetoothInfo
				{
					bool			isValid;					///< indicates valid data members
					unsigned char	ucFlags;					///< flags
					unsigned char	ucMac[6];					///< media access control
				} BluetoothInfo;

				/// Input/output capabilities information requested with command [0x66] and Mode=0x60
				struct IOCap
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucNoOfInputs;					///< number of inputs
					unsigned char	ucNoOfOutputs;					///< number of outputs
					unsigned char	ucNoOfRelays;					///< number of relays
				} IOCap;

				/// External peripheral devices information requested with command [0x66] and Mode=0x61
				struct PeriphDev
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucNoOfPeripheralDevices;		///< number of detected devices
				} PeriphDev;

				/// Device information of RF-Controller requested with command [0x66] and Mode=0x80 and Mode=0x81
				struct DeviceInfo
				{
					bool			isValid;						///< indicates valid data members
					unsigned char	ucDevID[4];						///< Device-IF (serial number)
					unsigned char	ucLicenseCustom[4];				///< licensed customer version
					unsigned char	ucLicenseFw[2];					///< licensed firmware version
					unsigned char	ucLicenseTrType[2];				///< licensed transponder driver
					unsigned char	ucLicenseFct[2];				///< licensed functions
					unsigned char	ucLicenseUhfTrType[2];			///< licensed uhf transponder driver (for dual frequency reader)
					unsigned char	ucLicenseUhfFct[2];				///< licensed uhf functions (for dual frequency reader)
					std::string		sScannerID;						///< User-configurable Scanner-ID. The Scanner-ID can be set in the Scanner configuration.
				} DeviceInfo;
				
			}; // class _FEDM_ISC_CORE_EXT_CLASS IInfoGroup


			/// @brief Class for collecting all reader diagnostic information
			///
			/// <b>Description</b><br>
			/// This class contains all data values, which are potentially part of the Reader&apos;s response of the command [0x6E] Reader Diagnostic.<br>
			class _FEDM_ISC_CORE_EXT_CLASS ReaderDiagnostic
			{

				friend class IInfoGroup;
				friend class IAsyncGroup;

			// public methods
			public:
				/// constructor
				ReaderDiagnostic();

				/// returns the status of the Reader diagnostic data
				bool IsValid() const;

				/// Returns a report with complete Reader diagnostic information
				std::string GetReport() const;

				/** @brief Returns a partial report with Reader diagnostic information
				*
				* @param[in] ucMode mode byte in command [0x6E] Reader Diagnostic
				* @return string with partial report
				*
				* <b>Description</b><br>
				* This method returns a partial report, based on information which must be previously read from the Reader with the command
				* [0x6E] Reader Diagnostic.<br>
				* Use [SendProtocol](@ref FEDM::Core::ICommandGroup::SendProtocol) or [ReadReaderDiagnostic](@ref ReadReaderDiagnostic) to read the information.<br>
				* See Reader&apos;s System Manual for the list with all supported mode bytes.
				*/
				std::string GetPartialReport(unsigned char ucMode) const;

			// protected methods
			protected:
				void Init(FEDM_ISCReaderModule* pReader, FEDM_ISC_READER_DIAGNOSTIC* pDiag);
				void Clear();

			private:
				FEDM_ISCReaderModule*		m_pReader;

			// public data members
			public:
				/// Reader and Antenna Status requested with command [0x6E] and Mode=0x01
				struct ReaderStatus
				{
					bool isValid;									///< indicates, if data with Mode 0x01 is read

					/// Flags byte A
					union FlagsA
					{
						unsigned char	ucFlagsA;						///< Flags byte A
						/// Flags byte A
						struct Flags
						{
							unsigned char	bRfHardware:		1;		///< Flags byte A, bit 0: RF-Hardware error
							unsigned char	bRfNoise:			1;		///< Flags byte A, bit 1: RF-Noise problem
							unsigned char	bRfPhaseError_Less:	1;		///< Flags byte A, bit 2: only HF Reader
							unsigned char	bRfPhaseError_More:	1;		///< Flags byte A, bit 3: only HF Reader
							unsigned char	bRfPowerAmp:		1;		///< Flags byte A, bit 4:
							unsigned char	bTempWarning:		1;		///< Flags byte A, bit 5: Temperature Warning (only HF Reader)
							unsigned char	bSyncTimeout:		1;		///< Flags byte A, bit 6:
							unsigned char	bTempAlarm:			1;		///< Flags byte A, bit 7: Temperature Alarm
						} Flags;
					} FlagsA;

					/// Flags byte B
					union FlagsB
					{
						unsigned char	ucFlagsB;						///< Flags byte B
						/// Flags byte B (UHF Reader only)
						struct FlagsUhf
						{
							unsigned char	bRfPhaseError_Ant1:	1;		///< Flags byte B, bit 0: Phase Error at internal Antenna Output 1 (only UHF Reader)
							unsigned char	bRfPhaseError_Ant2: 1;		///< Flags byte B, bit 1: Phase Error at internal Antenna Output 2 (only UHF Reader)
							unsigned char	bRfPhaseError_Ant3: 1;		///< Flags byte B, bit 2: Phase Error at internal Antenna Output 3 (only UHF Reader)
							unsigned char	bRfPhaseError_Ant4: 1;		///< Flags byte B, bit 3: Phase Error at internal Antenna Output 4 (only UHF Reader)
							unsigned char	bDummy3:			4;		///< Flags byte B, bits 4-7: unused bits
						} FlagsUhf;
						/// Flags byte B (HF Reader only)
						struct FlagsHf
						{
							unsigned char	bMuxStatus:			1;		///< Flags byte B, bit 0: Multiplexer status (only HF Reader)
							unsigned char	bDatStatus:			1;		///< Flags byte B, bit 1: Dynamic Antenna Tuner status (only HF Reader)
							unsigned char	bDCAntError:		1;		///< Flags byte B, bit 2: DC-Power error at Antenna Output (only HF Reader)
							unsigned char	bDummy4:			5;		///< Flags byte B, bits 3-7: unused bits
						} FlagsHf;

					} FlagsB;
				} ReaderStatus;

				/// Multiplexer Status requested with command [0x6E] and Mode=0x03
				struct ExtMuxStatus
				{
					bool isValid;								///< indicates, if data with Mode 0x03 is read
					unsigned char ucMuxStatusCh1;				///< Impedance-Status of Output Channel 1 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh2;				///< Impedance-Status of Output Channel 2 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh3;				///< Impedance-Status of Output Channel 3 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh4;				///< Impedance-Status of Output Channel 4 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh5;				///< Impedance-Status of Output Channel 5 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh6;				///< Impedance-Status of Output Channel 6 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh7;				///< Impedance-Status of Output Channel 7 of external Multiplexer (only for HF Reader)
					unsigned char ucMuxStatusCh8;				///< Impedance-Status of Output Channel 8 of external Multiplexer (only for HF Reader)
				} ExtMuxStatus;

				/// EEPROM and FPGA Status requested with command [0x6E] and Mode=0x04
				struct ErrorAndDecoderStatus
				{
					bool isValid;										///< indicates, if data with Mode 0x04 is read
						
					/// Internal Error flag field A
					union ErrorA
					{
						unsigned char	ucIntErrorA;						///< Internal Error flag field A

						/// Internal Error flag field A
						struct ErrorFlags
						{
							unsigned char	bIOExpander:		1;		///< Internal Error flag field A, bit 0: IO Expander error
							unsigned char	bDCOut:				1;		///< Internal Error flag field A, bit 1: DC Out error
							unsigned char	bUsbImax:			1;		///< Internal Error flag field A, bit 2: USB error
							unsigned char	bReserved:			5;		///< Internal Error flag field A, bits 3-7: reserved
						} ErrorFlags;

						/// Internal Error flag field A
						struct ErrorFlags_HyWEAR_compact
						{
							unsigned char	bReserved1:			1;		///< Internal Error flag field A, bit 0: reserved
							unsigned char	bTriggerLockStatus: 1;		///< Internal Error flag field A, bit 1: Trigger lock status
							unsigned char	bBarcode:			1;		///< Internal Error flag field A, bit 2: Barcode
							unsigned char	bWiFiBluetooth:		1;		///< Internal Error flag field A, bit 3: WiFi / Bluetooth
							unsigned char	bAccelerationSensor: 1;		///< Internal Error flag field A, bit 4: Acceleration Sensor
							unsigned char	bBattery:			1;		///< Internal Error flag field A, bit 5: Battery
							unsigned char	bReserved2:			2;		///< Internal Error flag field A, bits 6-7: reserved
						} ErrorFlags_HyWEAR_compact;

					} ErrorA;

					/// Internal Error flag field B
					union ErrorB
					{
						unsigned char	ucIntErrorB;					///< Internal Error flag field B

						/// Internal Error flag field B
						struct ErrorFlags
						{
							unsigned char	bEepromDevice1:		1;		///< Internal Error flag field B, bit 0: EEPROM error in Device 1
							unsigned char	bEepromDevice2:		1;		///< Internal Error flag field B, bit 1: EEPROM error in Device 2
							unsigned char	bHwFilter:			1;		///< Internal Error flag field B, bit 2: Hardware Filter problem
							unsigned char	bRfDecoder:			1;		///< Internal Error flag field B, bit 3: RF-Decoder problem
							unsigned char	bParaMismatch:		1;		///< Internal Error flag field B, bit 4: Parameter mismatch
							unsigned char	bPeopleCounter:		1;		///< Internal Error flag field B, bit 5: People Counter error
							unsigned char	bRealTimeClock:		1;		///< Internal Error flag field B, bit 6: Real-Time Clock error
							unsigned char	bADC:				1;		///< Internal Error flag field B, bit 7: ADC error
						} ErrorFlags;

						/// Internal Error flag field B
						struct ErrorFlags_HyWEAR_compact
						{
							unsigned char	bEeprom:			1;		///< Internal Error flag field B, bit 0: EEPROM
							unsigned char	bReserved1:			2;		///< Internal Error flag field B, bits 1-2: reserved
							unsigned char	bRfDecoder:			1;		///< Internal Error flag field B, bit 3: RF-Decoder
							unsigned char	bReserved2:			4;		///< Internal Error flag field B, bits 4-7: reserved
						} ErrorFlags_HyWEAR_compact;

					} ErrorB;
				} ErrorAndDecoderStatus;

				/// Multiplexer Impedance Status requested with command [0x6E] and Mode=0x05 (only HF/UHF LR-Reader): Status of external Multiplexer, connected at internal Antenna Outputs
				struct ExtMuxOutStatus
				{
					bool isValid;											///< indicates, if data with Mode 0x05 is read

					/// (only HF/UHF LR-Reader): Status of external Multiplexer, connected at internal Antenna Output 1
					struct Mux1
					{
						/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
						union Cntrl
						{
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
							unsigned char	ucPowerAmp;
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
							struct PowerAmpFlags
							{
								/// HF LR-Reader: Power-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh1:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh2:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh3:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh4:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh5:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh6:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh7:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 1:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 1:<br>
								unsigned char 	bMuxCh8:			1;
							} PowerAmpFlags;
						} Cntrl;

						/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
						union Phase_LT50
						{
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_LT50;

						/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
						union Phase_GT50
						{
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 1
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 1
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_GT50;
					} Mux1;

					/// (only HF/UHF LR-Reader): Status of external Multiplexer, connected at internal Antenna Output 2
					struct Mux2
					{
						/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
						union Cntrl
						{
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
							unsigned char	ucPowerAmp;
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
							struct PowerAmpFlags
							{
								/// HF LR-Reader: Power-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh1:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh2:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh3:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh4:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh5:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh6:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh7:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 2:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 2:<br>
								unsigned char 	bMuxCh8:			1;
							} PowerAmpFlags;
						} Cntrl;

						/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
						union Phase_LT50
						{
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_LT50;

						/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
						union Phase_GT50
						{
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 2
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 2
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_GT50;
					} Mux2;

					/// (only HF/UHF LR-Reader): Status of external Multiplexer, connected at internal Antenna Output 3
					struct Mux3
					{
						/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
						union Cntrl
						{
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
							unsigned char	ucPowerAmp;
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
							struct PowerAmpFlags
							{
								/// HF LR-Reader: Power-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh1:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh2:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh3:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh4:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh5:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh6:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh7:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 3:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 3:<br>
								unsigned char 	bMuxCh8:			1;
							} PowerAmpFlags;
						} Cntrl;

						/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
						union Phase_LT50
						{
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_LT50;

						/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
						union Phase_GT50
						{
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 3
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 3
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_GT50;
					} Mux3;

					/// (only HF/UHF LR-Reader): Status of external Multiplexer, connected at internal Antenna Output 4
					struct Mux4
					{
						/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
						union Cntrl
						{
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
							unsigned char	ucPowerAmp;
							/// (only HF/UHF LR-Reader): Power- or Impedance-Status of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
							struct PowerAmpFlags
							{
								/// HF LR-Reader: Power-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh1:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh2:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh3:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh4:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh5:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh6:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh7:			1;
								/// HF LR-Reader: Power-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 4:<br>
								/// UHF LR-Reader: Impedance-Status of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 4:<br>
								unsigned char 	bMuxCh8:			1;
							} PowerAmpFlags;
						} Cntrl;

						/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
						union Phase_LT50
						{
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (<50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_LT50;

						/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
						union Phase_GT50
						{
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
							unsigned char	ucPhaseError;
							/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Outputs of external Multiplexer, connected at internal Antenna Output 4
							struct PhaseErrorFlags
							{
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 1 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh1:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 2 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh2:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 3 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh3:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 4 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh4:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 5 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh5:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 6 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh6:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 7 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh7:	1;
								/// (only HF LR-Reader): Impedance-Status (>50R) of Antenna Output 8 of external Multiplexer, connected at internal Antenna Output 4
								unsigned char 	bMuxCh8:	1;
							} PhaseErrorFlags;
						} Phase_GT50;
					} Mux4;
				} ExtMuxOutStatus;

				/// MAX Status requested with command [0x6E] and Mode=0x06
				struct MaxStatus
				{
					bool isValid;												///< indicates, if data with Mode 0x06 is read
					/// Error Status
					union ErrorStatus
					{
						unsigned short int	usError;							///< 2 byte Error flag field
						/// Error flag field
						struct Flags
						{
							unsigned short int 	bRTC:					1;		///< Error flag field, bit 0: real-time clock error
							unsigned short int 	bMetadata:				1;		///< Error flag field, bit 1: metadata error
							unsigned short int 	bTimezoneTable:			1;		///< Error flag field, bit 2: timezone table error
							unsigned short int 	bHolidayTable:			1;		///< Error flag field, bit 3: holiday table error
							unsigned short int 	bAccessTable:			1;		///< Error flag field, bit 4: access table error
							unsigned short int 	bRes1:					1;		///< Error flag field, bit 5: reserved
							unsigned short int 	bReaderConfig:			1;		///< Error flag field, bit 6: Reader configuration problem
							unsigned short int 	bTableUpdate:			1;		///< Error flag field, bit 7: table update problem
							unsigned short int 	bRes2:					8;		///< Error flag field, bit 8-15: reserved
						} Flags;
					} ErrorStatus;

					unsigned short int	usEventTableSize;						///< Event table size
					unsigned short int	usEventTableLength;						///< Event table length
				} MaxStatus;

				/// ID ISC.PRH200: LED Status requested with command [0x6E] and Mode=0x07
				struct PRH200_Status
				{
					bool isValid;											///< indicates, if data with Mode 0x07 is read
					unsigned char ucNoOfLEDs;								///< Number of following LED status bytes
					unsigned char ucLEDStatus[29];							///< LED status bytes for ID ISC.PRH200 according Reader's System Manual
				} PRH200_Status;

				/// ID ISC.LR2500-B: Antenna Tuning Status requested with command [0x6E] and Mode=0x08
				struct LR2500_B_AntTuningStatus
				{
					bool isValid;											///< indicates, if data with Mode 0x08 is read
					unsigned short int	usVoltage;							///< Antenna Voltage in mV
					unsigned short int	usCurrent;							///< Amplifier Current in mA
					unsigned short int	usPhase_mV;							///< Phase in mV
					short int			iPhase;								///< Phase in degree
				} LR2500_B_AntTuningStatus;

				/// Battery Status requested with command [0x6E] and Mode=0x10
				struct BatteryStatus
				{
					unsigned char	ucVoltage[2];							///< Battery Voltage in mV
				} BatteryStatus;

				/// Firmware Status requested with command [0x6E] and Mode=0x20
				struct FwStatus
				{
					bool isValid;											///< indicates, if data with Mode 0x20 is read
					unsigned char	ucStatusText[32];						///< Firmware status text
				} FwStatus;

				/// Config-Para Change requested with command [0x6E] and Mode=0x21
				struct CfgChange
				{
					bool isValid;											///< indicates, if data with Mode 0x21 is read
					unsigned char	ucStatus;								///< Status of Reader's configuration after last Firmware Update
				} CfgChange;
				
			}; // class _FEDM_ISC_CORE_EXT_CLASS ReaderDiagnostic


			/// @brief Request of Reader Type Number, actually set in the Reader class
			///
			/// @return Reader Type or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// All Reader Types are collected in the namespace FEDM::Core::Const::ReaderType
			unsigned int GetReaderType();

			/// @brief Request of Reader Name, actually set in the Reader class
			///
			/// @return Reader Name
			/// <b>Description</b><br>
			/// The returned string can be used for displaying the product name.
			std::string GetReaderName();

			/// @brief Read complete reader info and set the Reader Type
			///
			/// @param[in] uiProtocolFrame type of protocol frame (preset to STANDARD) to be used for the communication.
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// %ReadReaderInfo() is one of the important methods, that have to be called first after connecting to the Reader.<br>
			/// This method sets the Reader Type internally and can set the protocol frame properly to the connected Reader.<br>
			/// This method is normally called in the connect methods internally (see IPortGroup), but in some cases, 
			/// e.g. when one of the Connect methods is called without the detect option, the %ReadReaderInfo() must be called separately.
			int ReadReaderInfo(unsigned int uiProtocolFrame = FEDM_PRT_FRAME_STANDARD);

			/// @brief Return structure with previously read Reader information
			///
			/// @return [ReaderInfo](@ref FEDM::Core::IInfoGroup::ReaderInfo)
			///
			/// <b>Description</b><br>
			const ReaderInfo& GetReaderInfo() const { return m_Info; }

			/// @brief Read the complete reader diagnostic data
			///
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// The returned information have to be analyzed with the descriptions in the Reader&apos;s System Manual.
			int ReadReaderDiagnostic();

			/// @brief Return structure with previously read Reader diagnostic data
			///
			/// @return [ReaderDiagnostic](@ref FEDM::Core::IInfoGroup::ReaderDiagnostic)
			///
			/// <b>Description</b><br>
			const ReaderDiagnostic& GetReaderDiagnostic() const { return m_Diag; }

		private:
				
			IInfoGroup();
			virtual ~IInfoGroup();

			ReaderModule*			m_pParent;
			FEDM_ISCReaderModule*	m_pReader;
			ReaderInfo				m_Info;
			ReaderDiagnostic		m_Diag;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IREADER_INFO_GROUP_H_INCLUDED_)
