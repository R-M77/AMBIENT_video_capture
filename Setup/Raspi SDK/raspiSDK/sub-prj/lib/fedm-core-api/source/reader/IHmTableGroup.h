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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IHMTABLE_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IHMTABLE_GROUP_H_INCLUDED_

#include <vector>
#include <map>
#include <string>
#include "../source/FEDM.h"
#include "../source/i_scan/FEDM_ISC.h"

#define FEDM_API_PUB_MEM_BLOCK_COUNT	256 // 256 blocks
#define FEDM_API_PUB_MEM_BLOCK_SIZE		 32 // 32 bytes
#define FEDM_API_EPC_BANK_COUNT			128 // 128 blocks
#define FEDM_API_EPC_BANK_SIZE			  2 // 2 bytes

class FEDM_ISCReaderModule;
class FEDM_ISOTabItem;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing Host Mode table specific methods
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for Host Mode table for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [IHmTable](@ref FEDM::Core::ReaderModule::IHmTable) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IHmTableGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;

		public:

			/// Class represents one RSSI record of requested Host Mode data with command [0xB0][0x01] Inventory
			class _FEDM_ISC_CORE_EXT_CLASS RssiItem
			{
				friend class IHmTableGroup;
			protected:
				RssiItem(unsigned char ucAntennaNumber,	unsigned char ucStatus, unsigned char ucRSSI, unsigned short int usPhaseAngle);

			public:
				unsigned char m_ucAntNo;			///< Antenna Number
				unsigned char m_ucStatus;			///< Status value
				unsigned char m_ucRSSI;				///< RSSI value
				unsigned short int m_usPhaseAngle;	///< Phase Angle value
			};


			/// @brief type definition for a map, collecting RSSI values
			///
			/// @param Key Antenna Number
			/// @param Value Pointer to the RSSI object; see [RssiItem](@ref IHmTableGroup::RssiItem)
			typedef std::map<unsigned char, RssiItem*>					RSSI_MAP;

			/// type definition for a map iterator, collecting RSSI values
			typedef std::map<unsigned char, RssiItem*>::const_iterator	RSSI_MAP_ITOR;


			/// @brief Class represents one valid record of requested Host Mode data, initially created with the command [0xB0][0x01] Inventory
			///
			/// <b>Description</b><br>
			/// This class contains all record members, which are potentially part of the Reader&apos;s response of the command [0xB0][0x01] Inventory.<br>
			/// An item can be requested after the command was executed successfully with the method FEDM::Core::IHmTableGroup::GetItemByIndex().<br>
			/// <br>
			/// The [example](@ref FEDM::Core::IHmTableGroup::GetItemByIndex) demonstrate the direct table access method. 
			/// For more efficient and modern coding, the concept of TagHandlers should be preferred.
			/// See [Inventory](@ref FEDM::Core::ITagGroup::Inventory) for a simple example.<br>
			/// <br>
			/// The class can also buffer request or responded data for the following basic Transponder commands:<br>
			/// [0xB0][0x23] Read Multiple Blocks<br>
			/// [0xB0][0x24] Write Multiple Blocks<br>
			/// [0xB0][0x25] Select<br>
			/// [0xB0][0x27] Write AFI (for ISO 15693)<br>
			/// [0xB0][0x29] Write DSFID (for ISO 15693)<br>
			/// [0xB0][0x2B] Get System Information (for ISO 15693)<br>
			/// [0xB0][0x2C] Get Multiple Block Security Status (for ISO 15693)<br>
			/// [0xB2][0x2B] ISO 14443-4 Transponder Info<br>
			class _FEDM_ISC_CORE_EXT_CLASS HmTableItem
			{
			public:

				friend class IHmTableGroup;

				/// @brief Method to clear all data members and memories
				///
				/// <b>Description</b><br>
				/// This method clears all data members and memories without resizing of tag memories
				void Clear();

				/// @brief Method to query the IDD
				///
				/// @return IDD as string
				///
				/// <b>Description</b><br>
				std::string	GetIDD();

				/// @brief Method to query the manufacturer name for an Transponder of ISO 15693 standard
				///
				/// @return String with manufacturer name
				///
				/// <b>Description</b><br>
				std::string GetISO15693Manufacturer();

				/// @brief Method to query the manufacturer name for an Transponder of ISO 14443, Part A standard
				///
				/// @return String with manufacturer name
				///
				/// <b>Description</b><br>
				std::string GetISO14443AManufacturer();
	
				/// @brief Method to query the Chip-ID for an Transponder of EPC Class 1 Gen 2 or ISO 18000-3M3 standard
				///
				/// @return Chip-ID
				///
				/// <b>Description</b><br>
				unsigned int GetEpcC1G2TagModelNumber();

				/// @brief Method to query the Manufacturer-ID of EPC Class 1 Gen 2 or ISO 18000-3M3 standard
				///
				/// @return Manufacturer-ID
				///
				/// <b>Description</b><br>
				unsigned int GetEpcC1G2MaskDesignerID();

				/// @brief Method to query the manufacturer name for an Transponder of EPC Class 1 Gen 2 or ISO 18000-3M3 standard
				///
				/// @return String with manufacturer name
				///
				/// <b>Description</b><br>
				std::string GetEpcC1G2MaskDesignerName();

				/// @brief Method to query if the Protocol-Control (PC) is extended (only applicable with EPC Class 1 Gen 2 and ISO 18000-3M3)
				///
				/// @return true, if PC is extended, otherwise false
				///
				/// <b>Description</b><br>
				/// Method to query if the Protocol-Control (PC) of an EPC Class 1 Gen 2 Transponder or ISO 18000-3M3 is extended with 1 additional block of 2 bytes.
				bool IsExtendedPC_W1();

				/// @brief Method returns map with Received Signal Strength Indication (RSSI)
				///
				/// @return map with RSSI value and status for each antenna
				///
				/// <b>Description</b><br>
				/// Method to query a map with Received Signal Strength Indication (RSSI). The map contains a RSSI and status value for each antenna, where the Transponder is detected.
				/// The key of the map is the antenna number, the value is a pointer to a structure of type RssiItem with the RSSI and status value.
				const RSSI_MAP& GetRSSI();

				/// @brief Query method for block counts and block sizes
				///
				/// @param[out] uiPubDataBlockCount number of data blocks for public Rx and Tx memories
				/// @param[out] uiPubDataBlockSize number of bytes in each data block
				/// @param[out] uiEpcBankBlockCount number of data blocks for EPC, TID and RES Rx and Tx memories
				/// @param[out] uiEpcBankBlockSize number of bytes in each data block
				///
				/// <b>Description</b><br>
				/// Method to query the block count and block sizes of the internal memories for Rx and Tx public data.
				void GetTableSizes(	unsigned int& uiPubDataBlockCount,
									unsigned int& uiPubDataBlockSize,
									unsigned int& uiEpcBankBlockCount,
									unsigned int& uiEpcBankBlockSize);

				/// @brief Request of reference to data buffer for received public Transponder data
				///
				/// <b>Description</b><br>
				/// Initial size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>1024</center></td>
				/// <td><center>256</center></td>
				/// <td><center>4</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetRxPubData();

				/// @brief Request of reference to data buffer for public Transponder data to be sent to
				///
				/// <b>Description</b><br>
				/// Initial size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>1024</center></td>
				/// <td><center>256</center></td>
				/// <td><center>4</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetTxPubData();

				/// @brief Request of reference to an array for received block security status
				///
				/// <b>Description</b><br>
				/// Initial size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>256</center></td>
				/// <td><center>1</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>&	GetSecStatus();

				/// @brief Request of reference to data buffer for received EPC bank data from Transponder
				///
				/// <b>Description</b><br>
				/// Fixed size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>128</center></td>
				/// <td><center>2</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetRxEpcBank();

				/// @brief Request of reference to data buffer for EPC bank data to be sent to Transponder
				///
				/// <b>Description</b><br>
				/// Fixed size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>128</center></td>
				/// <td><center>2</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetTxEpcBank();

				/// @brief Request of reference to data buffer for received TID bank data from Transponder
				///
				/// <b>Description</b><br>
				/// Fixed size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>128</center></td>
				/// <td><center>2</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetRxTidBank();

				/// @brief Request of reference to data buffer for TID bank data to be sent to Transponder
				///
				/// <b>Description</b><br>
				/// Fixed size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>128</center></td>
				/// <td><center>2</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetTxTidBank();

				/// @brief Request of reference to data buffer for received Reserved bank data from Transponder
				///
				/// <b>Description</b><br>
				/// Fixed size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>128</center></td>
				/// <td><center>2</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetRxResBank();

				/// @brief Request of reference to data buffer for Reserved bank data to be sent to Transponder
				///
				/// <b>Description</b><br>
				/// Fixed size is:<br>
				/// <table border = "1">
				/// <tr>
				/// <td><center>Buffer Size in bytes</center></td>
				/// <td><center>No. of Data Blocks</center></td>
				/// <td><center>Block Size in bytes</center></td>
				/// </tr>
				/// <tr>
				/// <td><center>256</center></td>
				/// <td><center>128</center></td>
				/// <td><center>2</center></td>
				/// </tr>
				/// </table>
				std::vector<unsigned char>& GetTxResBank();

			protected:

				HmTableItem(FEDM_ISOTabItem* pTabItem, IHmTableGroup* pParent, unsigned int uiTabIndex, bool bSharedRxTxMemories, bool bGlobalTagMemories);	// constructor
				~HmTableItem();		// destructor

				void Init(FEDM_ISOTabItem* pTabItem);

				// data elements
			public:
					
				/// @brief Flag field indicating IDD and/or RSSI valid
				///
				/// <b>Description</b><br>
				/// Response data from [0xB0][0x01] Inventory command with request of RSSI.<br>
				/// Detailed information can be found in the system manual of the Reader.
				unsigned char	m_ucFlags;

				union
				{
					unsigned char	m_ucDsfID;			///< Data Storage Family Identifier (only applicable with ISO 15693 compliant Transponder)
					unsigned char	m_ucChipID;			///< Chip Identifier for SR176 and SRIxx Transponder og manufacturer STMicroelectronics SA (only applicable with ISO 14443 compliant Transponder)
					unsigned char	m_ucTrInfo;			///< Additional transponder info (only applicable with ISO 14443A compliant Transponder)
					unsigned char	m_ucProtoInfo;		///< Protocol info byte (only applicable with ISO 14443B compliant Transponder)
					unsigned char	m_ucIDDT;			///< Identifier Data Type (IDDT) (only applicable with EPC Class 1 Gen 2 and ISO 18000-3M3 compliant Transponder)
				};

				unsigned char	m_ucOptInfo;			///< Optional informations (only applicable with ISO 14443A compliant Transponder)

				unsigned char	m_ucTrType;				///< Transponder type
				//unsigned char	m_ucTrSubType;			///< Transponder sub-type of generic transponder type
				unsigned char	m_ucIDDLen;				///< Length of IDD (resp. UID,  resp. SNR, resp. EPC) in bytes
				unsigned char	m_ucIDD[FEDM_ISC_MAX_UID_LENGTH];			///< Buffer for IDD (resp. UID,  resp. SNR, resp. EPC)
				unsigned char	m_ucClass1Gen2_PC[2];	///< Protocol-Control (PC) of EPC Class 1 Gen 2 or ISO 18000-3M- compliant Transponder
				unsigned char	m_ucClass1Gen2_XPC_W1[2];	///< Extended Protocol-Control (XPC W1) of EPC Class 1 Gen 2 or ISO 18000-3M- compliant Transponder

				// ISO 15693 System Info with command [0xB0][0x2C] Get System Information
				unsigned char	m_ucAFI;				///< Application Family Identifier
				unsigned char	m_ucMemSize[3];			///< Array with complete Memory Size (only applicable with ISO 15693 compliant Transponder)
				unsigned char	m_ucICRef;				///< IC reference (only applicable with ISO 15693 compliant Transponder)
				unsigned char	m_ucMemSizeLen;			///< Length of [Memory-Size](@ref m_ucMemSize) from ISO Command [0xB0][0x2B] Get System Information (normally 2)

				// response data from command [0xB2][0x2B] ISO 14443-4 Transponder Info
				unsigned char	m_ucFSCI;				///< Max. Frame Size (part of ISO14443-4 Transponder Info)
				unsigned char	m_ucFWI;				///< Frame Waiting Time (part of ISO14443-4 Transponder Info)
				unsigned char	m_ucDSI;				///< Divisor Send Integer (part of ISO14443-4 Transponder Info)
				unsigned char	m_ucDRI;				///< Divisor Receive Integer (part of ISO14443-4 Transponder Info)
				unsigned char	m_ucNad;				///< Node Access (part of ISO14443-4 Transponder Info)
				unsigned char	m_ucCid;				///< Card Identifier (part of ISO14443-4 Transponder Info)
	
				/// @brief Block size for data blocks in m_ucRxDB and m_ucTxDB
				///
				/// The block size is normally set after a read of Transponder data.<br>
				unsigned char	m_ucBlockSize;

				bool	m_bIsBlockSizeSet;	///< read-only flag indicates if blocksize is set after read command

				/// @brief Read-only flag indicates if this transponder is selected for the next ISO-Host-Command
				///
				/// - a [0x25] Select sets this flag<br>
				/// - a [0x26] Reset to Ready or next [0x25] Select with other IDD clears this flag<br>
				bool	m_bIsSelected;

				bool	m_bIsIDD;				///< Flag indicates, if item contains valid data for IDD (includes TrType and IDDT)
				bool	m_bIsAFI;				///< Flag indicates, if item contains valid data for DSFID and AFI
				bool	m_bIsSysInfo;			///< Flag indicates, if item contains valid ISO 15693 Transponder Info
				bool	m_bIsISO14443_4Info;	///< Flag indicates, if item contains valid 14443-4 Transponder Info
				bool	m_bIsRSSI;				///< Flag indicates, if item contains valid data for RSSI values for each antenna


			protected:

				FEDM_ISOTabItem*	m_pTableItem;
				unsigned int		m_uiIndex;
				std::string			m_sIDD;
				RSSI_MAP			m_mapRSSI;

			private:
				IHmTableGroup* m_pParent;

				// local memory sizes for [0xB0][0x23] Read Multiple Blocks and [0xB0][0x24] Write Multiple Blocks
				unsigned int m_uiPubDataBlockCount; // number of data blocks for public Rx and Tx memories
				unsigned int m_uiPubDataBlockSize; // number of bytes in each data block
				unsigned int m_uiEpcBankBlockCount; // number of data blocks for EPC, TID and RES Rx and Tx memories
				unsigned int m_uiEpcBankBlockSize; // number of bytes in each data block

				bool m_bSharedRxTxMemories; // Tx in Rx memory
				bool m_bGlobalTagMemories; // use global memories in IHmTableGroup

				// local memories for [0xB0][0x23] Read Multiple Blocks and [0xB0][0x24] Write Multiple Blocks
				std::vector<unsigned char>	m_ucRxPubData;	// Data buffer for received public Transponder data
				std::vector<unsigned char>	m_ucTxPubData;	// Data buffer for public Transponder data to be sent to
				std::vector<unsigned char>	m_ucSecStatus;	// Array for received block security status (only applicable with ISO 15693 Transponder)

				std::vector<unsigned char>	m_ucTxEpcBank;	// transmit data block with block size 2 (only for EPC Class 1, Gen 2 and ISO 18000-3M3 compliant Transponder)
				std::vector<unsigned char>	m_ucRxEpcBank;	// receive data block with block size 2 (only for EPC Class 1, Gen 2 and ISO 18000-3M3 compliant Transponder)

				std::vector<unsigned char>	m_ucTxTidBank;	// transmit data block with block size 2 (only for EPC Class 1, Gen 2 and ISO 18000-3M3 compliant Transponder)
				std::vector<unsigned char>	m_ucRxTidBank;	// receive data block with block size 2 (only for EPC Class 1, Gen 2 and ISO 18000-3M3 compliant Transponder)

				std::vector<unsigned char>	m_ucTxResBank;	// transmit data block with block size 2 (only for EPC Class 1, Gen 2 and ISO 18000-3M3 compliant Transponder)
				std::vector<unsigned char>	m_ucRxResBank;	// receive data block with block size 2 (only for EPC Class 1, Gen 2 and ISO 18000-3M3 compliant Transponder)
			};



					
			/// @brief Set size of the table
			///
			/// @param[in] uiSize Maximal numbers of records in the Host Mode Table
			/// @param[in] bSharedRxTxMemories if true, Rx and Tx data from/to Transponder is shared in Rx global or local memory space
			/// @param[in] bGlobalTagMemories if true, Rx and Tx data from/to Transponder is shared in global memory space
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// The call of this method or overloaded SetSize(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int, bool, bool) is mandatory, 
			/// when the Host Mode Table should be used in the application.<br>
			/// The content of the table will be deleted.<br>
			/// The table size should be set to the maximal number of records, received by the command [0xB0][0x01] Inventory.<br>
			/// This method initializes the buffers for Transponder data as follows:<br>
			/// <table border = "1">
			/// <tr>
			/// <td><center>Table Member</center></td>
			/// <td><center>Description</center></td>
			/// <td><center>Buffer Size in bytes</center></td>
			/// <td><center>No. of Data Blocks</center></td>
			/// <td><center>Block Size in bytes</center></td>
			/// </tr>
			/// <tr>
			/// <td><center>Rx Data Memory</center></td>
			/// <td><center>Received Transponder data</center></td>
			/// <td><center>8192</center></td>
			/// <td><center>256</center></td>
			/// <td><center>32</center></td>
			/// </tr>
			/// <tr>
			/// <td><center>Tx Data Memory</center></td>
			/// <td><center>Transponder data to be sent to</center></td>
			/// <td><center>8192</center></td>
			/// <td><center>256</center></td>
			/// <td><center>32</center></td>
			/// </tr>
			/// </table>
			/// <br>
			/// Shared Rx and Tx Transponder (Tag) memories: use of local or global memories dependent on two flags<br>
			/// <br>
			/// local means : for each Transponder separated data memories<br>
			/// global means: common memories for all Transponders<br>
			/// <br>
			///                 | local memories               | global memories <br>
			///                 | bGlobalTagMemories = false   | bGlobalTagMemories = true <br>
			///                 |                              | <br>
			///                 |    bSharedRxTxMemories       |    bSharedRxTxMemories <br>
			///                 |------------------------------|------------------------------- <br>
			///                 |      false   |      true     |      false   |      true <br>             
			///                 |              |               |              | <br>
			/// Rx.. tag memory | data in Rx.. | data in Rx..  | data in Rx.. | data in Rx.. <br>
			/// Tx.. tag memory | data in Tx.. | data in Rx..  | data in Tx.. | data in Rx.. <br>
			int SetSize(unsigned int uiSize, bool bSharedRxTxMemories=false, bool bGlobalTagMemories=false);
					
			/// @brief Set size of the table
			///
			/// @param[in] uiSize Maximal numbers of records in the Host Mode Table
			/// @param[in] uiRxDB_BlockCount Number of data blocks for receive buffer
			/// @param[in] uiRxDB_BlockSize Size of each data block in byte for receive buffer
			/// @param[in] uiTxDB_BlockCount Number of data blocks for transmit buffer
			/// @param[in] uiTxDB_BlockSize Size of each data block in byte for transmit buffer
			/// @param[in] bSharedRxTxMemories if true, Rx and Tx data from/to Transponder is shared in Rx global or local memory space
			/// @param[in] bGlobalTagMemories if true, Rx and Tx data from/to Transponder is shared in global memory space
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// The call of this method or overloaded SetSize(unsigned int, bool, bool) is mandatory, 
			/// when the Host Mode Table should be used in the application.<br>
			/// The content of the table will be deleted.<br>
			/// The table size should be set to the maximal number of records, received by the command [0xB0][0x01] Inventory.<br>
			/// This method initializes the buffers for Transponder data as follows:<br>
			/// <table border = "1">
			/// <tr>
			/// <td><center>Table Member</center></td>
			/// <td><center>Description</center></td>
			/// <td><center>Buffer Size in bytes</center></td>
			/// <td><center>No. of Data Blocks</center></td>
			/// <td><center>Block Size in bytes</center></td>
			/// </tr>
			/// <tr>
			/// <td><center>Rx Data Memory</center></td>
			/// <td><center>Received Transponder data</center></td>
			/// <td><center>uiRxDB_BlockCount * uiRxDB_BlockSize</center></td>
			/// <td><center>uiRxDB_BlockCount</center></td>
			/// <td><center>uiRxDB_BlockSize</center></td>
			/// </tr>
			/// <tr>
			/// <td><center>Tx Data Memory</center></td>
			/// <td><center>Transponder data to be sent to</center></td>
			/// <td><center>uiTxDB_BlockCount * uiTxDB_BlockSize</center></td>
			/// <td><center>uiTxDB_BlockCount</center></td>
			/// <td><center>uiTxDB_BlockSize</center></td>
			/// </tr>
			/// </table>
			/// <br>
			/// Shared Rx and Tx Transponder (Tag) memories: use of local or global memories dependent on two flags<br>
			/// <br>
			/// local means : for each Transponder separated data memories<br>
			/// global means: common memories for all Transponders<br>
			/// <br>
			///                 | local memories               | global memories <br>
			///                 | bGlobalTagMemories = false   | bGlobalTagMemories = true <br>
			///                 |                              | <br>
			///                 |    bSharedRxTxMemories       |    bSharedRxTxMemories <br>
			///                 |------------------------------|------------------------------- <br>
			///                 |      false   |      true     |      false   |      true <br>             
			///                 |              |               |              | <br>
			/// Rx.. tag memory | data in Rx.. | data in Rx..  | data in Rx.. | data in Rx.. <br>
			/// Tx.. tag memory | data in Tx.. | data in Rx..  | data in Tx.. | data in Rx.. <br>
			int SetSize(unsigned int uiSize, 
						unsigned int uiRxDB_BlockCount, 
						unsigned int uiRxDB_BlockSize, 
						unsigned int uiTxDB_BlockCount, 
						unsigned int uiTxDB_BlockSize,
						bool bSharedRxTxMemories=false,
						bool bGlobalTagMemories=false);
	
			/// @brief Get size of the table
			///
			/// @return Size (>= 0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			int GetSize();
					
			/// @brief Get number of valid table items
			///
			/// @return Length (>0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Call this method to get the actual number of valid table items after the command [0xB0][0x01] Inventory.
			int GetLength();
					
			/// @brief Set number of valid data items in the table, if the application has built the table in front of transmit actions
			///
			/// @param[in] uiLength Number of valid table items in the Host Mode Table
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// This method is normally not used.<br>
			/// In rare cases, when the Host Mode Table is built for non-addressed data transfer to the Transponder,
			/// the table can be set to 1.<br>
			/// Non-addressed communication with Transponders need no Inventory and the table keeps empty.
			int SetLength(unsigned int uiLength);
					
			/// @brief Reset length of valid data items in the table
			///
			/// @param[in] uiDataFlags Flags to indicate the table members to be initialized to or 0 (preset) to initialize no members
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// After call of this method, GetLength() will return 0.
			/// In almost all cases, the transferred parameter uiDataFlags can be set to 0 (preset).
			///
			/// @note A call of an Inventory command does not clear the internal Host Mode Table. Thus, the call of %Reset() have to be done in front of each Inventory.
			int Reset(unsigned int uiDataFlags=0);

			/// @brief Get table item, which represents the selected Transponder
			///
			/// @return Table item. See [HmTableItem](@ref HmTableItem) for more information
			/// 
			/// <b>Description</b><br>
			/// The command [0xB0][0x25] Select switches an previously detected Transponder into the selectd state. As a Reader can manage only one Transponder in the selected state,
			/// this command can return the table item, which represents the selected Transponder.<br>
			HmTableItem*	GetSelectedItem();

			/// @brief Return the table index of the table item, which represents the selected Transponder
			///
			/// @return Table index (>=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			int GetSelectedIndex();

			/// @brief Get a valid table item, identified by IDD
			///
			/// @param[in] sIDD Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder
			/// @return table item. See [HmTableItem](@ref HmTableItem) for more information
			///
			/// <b>Description</b><br>
			HmTableItem*	GetItemByIDD(std::string sIDD);

			/// @brief Get the table index of the table item, identified by UID
			///
			/// @param[in] sIDD Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder
			/// @return Table index, beginning with 0 or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			int GetIndexByIDD(std::string sIDD);

			/// @brief Get a valid table item, identified by index
			///
			/// <b>Description</b><br>
			/// @param[in] uiIdx Table index, beginning with 0
			/// @return table item. See [HmTableItem](@ref HmTableItem) for more information
			///
			/// <b>Description</b><br>
			/// With this method, the table items (each contains one record from the Inventory response) can be gradually requested.<br>
			/// The following example demonstrate the direct table access method.<br>
			/// For more efficient and modern coding, the concept of TagHandlers should be preferred. See [Inventory](@ref FEDM::Core::ITagGroup::Inventory) for a simple example.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			///
			/// IHmTableGroup::HmTableItem* pItem = NULL; // pointer to table item
			///  
			/// reader.IHmTable.Reset();
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xB0::SUB_COMMAND, (unsigned char)0x01);
			/// reader.ICmd.SetCommandPara(ReaderCommand::_0xB0::SubCmd::_0x01::Req::MODE, (unsigned char)0x00);
			/// int back = reader.ICmd.SendProtocol(0xB0);
			/// if( back == 0 ||		// status: OK
			///		back == 0x84 ||		// status: RF warning
			///		back == 0x94 )		// status: more data
			/// {
			///		// internal Host Mode Table contains now the new records
			///
			///		for(int iIdx=0; iIdx<reader.IHmTable.GetLength(); iIdx++)
			///		{
			///			pItem = reader.IHmTable.GetItemByIndex(iIdx);
			///			if(pItem->m_bIsIDD)
			///			{
			///				// IDD is part of the received record
			///			}
			///		}
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			HmTableItem*	GetItemByIndex(unsigned int uiIdx);

		private:
			IHmTableGroup();
			virtual ~IHmTableGroup();

			void InitGlobalMemories(unsigned int uiPubDataBlockCount,	unsigned int uiPubDataBlockSize);

			FEDM_ISCReaderModule* m_pReader;

			std::vector<HmTableItem*> m_HmTable;

			// global memory sizes
			unsigned int m_uiPubDataBlockCount; // number of data blocks for public Rx and Tx memories
			unsigned int m_uiPubDataBlockSize; // number of bytes in each data block
			unsigned int m_uiEpcBankBlockCount; // number of data blocks for EPC, TID and RES Rx and Tx memories
			unsigned int m_uiEpcBankBlockSize; // number of bytes in each data block

			bool m_bSharedRxTxMemories;	// Rx and Tx shared memories, but for each Transponder separated
			bool m_bGlobalTagMemories;	// shared memories for all Transponders 

			// shared Rx and Tx tag memories: use of local or global memories dependent on two flags
			// local means : for each Transponder separated data memories
			// global means: common memories for all Transponders
			//
			//                 | local memories                                                | global memories
			//                 | bGlobalTagMemories = false                                    | bGlobalTagMemories = true
			//                 |                                                               |
			//                 |                     bSharedRxTxMemories                       |                             bSharedRxTxMemories
			//                 |---------------------------------------------------------------|-------------------------------------------------------------------------------
			//                 |            false              |            true               |             false                     |             true
			//                 |                               |                               |                                       |
			// Rx.. tag memory | data in HmTableItem::m_ucRx.. | data in HmTableItem::m_ucRx.. | data in IHmTableGroup::m_ucGlobalRx.. | data in IHmTableGroup::m_ucGlobalRx..
			// Tx.. tag memory | data in HmTableItem::m_ucTx.. | data in HmTableItem::m_ucRx.. | data in IHmTableGroup::m_ucGlobalTx.. | data in IHmTableGroup::m_ucGlobalRx..

			// global memories for [0xB0][0x23] Read Multiple Blocks and [0xB0][0x24] Write Multiple Blocks
			std::vector<unsigned char>	m_ucGlobalRxPubData;
			std::vector<unsigned char>	m_ucGlobalTxPubData;
			std::vector<unsigned char>	m_ucGlobalSecStatus;
			std::vector<unsigned char>	m_ucGlobalRxEpcBank;
			std::vector<unsigned char>	m_ucGlobalTxEpcBank;
			std::vector<unsigned char>	m_ucGlobalRxTidBank;
			std::vector<unsigned char>	m_ucGlobalTxTidBank;
			std::vector<unsigned char>	m_ucGlobalRxResBank;
			std::vector<unsigned char>	m_ucGlobalTxResBank;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IHMTABLE_GROUP_H_INCLUDED_)
