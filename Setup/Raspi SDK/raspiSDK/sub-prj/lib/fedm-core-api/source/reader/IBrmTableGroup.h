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

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_IBRMTABLE_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_IBRMTABLE_GROUP_H_INCLUDED_

#include <map>
#include <vector>
#include "../source/FEDM.h"
#include "../source/i_scan/FEDM_ISC.h"
#include "../source/utility/DateTime.h"

class FEDM_ISCReaderModule;
class FEDM_BRMTabItem;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing Buffered Read Mode table specific methods
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with special methods for Buffered Read Mode table for the Reader class ReaderModule.<br>
		/// Methods of this class can be called with the [IBrmTable](@ref FEDM::Core::ReaderModule::IBrmTable) member of ReaderModule.
		class _FEDM_ISC_CORE_EXT_CLASS IBrmTableGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;

		public:
				
			/// @brief Class Class represents one RSSI record
			class _FEDM_ISC_CORE_EXT_CLASS RssiItem
			{
			public:
				RssiItem();
				RssiItem(int iAntennaNumber, int iRssi, int iPhaseAngle);

				void clear();
				bool isValid() const { return m_iAntennaNumber >= 0; }
				RssiItem &operator=(const RssiItem & other);

				int m_iAntennaNumber;	///< Antenna Number
				int m_iRssi;			///< RSSI value
				int m_iPhaseAngle;		///< Phase Angle value
			};



			/// @brief Class represents one record of requested Buffered Read Mode data with command [0x22] Read Buffer or with received Notification data
			///
			/// <b>Description</b><br>
			/// This class contains all record members, which are potentially part of the Reader&apos;s response of the command [0x22] Read Buffer.<br>
			/// An item can be requested after the command was executed successfully with the method FEDM::Core::IBrmTableGroup::GetItemByIndex().<br>
			/// <br>
			/// [Example](@ref FEDM::Core::IBrmTableGroup::GetItemByIndex)
			class _FEDM_ISC_CORE_EXT_CLASS BrmTableItem
			{
			public:

				friend class IBrmTableGroup;

				/// @brief Class stores the IDD and transponder information
				///
				/// <b>Description</b><br>
				/// m_trType is the transponder type (see annex in system manual of the reader)
				/// m_afi is the Application Family Identifier
				/// m_dsfid is the Data Storage Family Identifier. Only applicable with ISO 15693 standard
				/// m_iddt is the Identifier Data Type (IDDT). The IDDT is only applicable with EPC Class 1 Gen 2 and ISO 18000-3M3
				/// m_ucClass1Gen2_PC is the Protocol-Control (PC) of EPC Class 1 Gen 2 or ISO 18000-3M- compliant Transponder
				/// m_ucClass1Gen2_XPC_W1 is the Extended Protocol-Control (XPC W1) of EPC Class 1 Gen 2 or ISO 18000-3M- compliant Transponder
				/// m_sIso15693Manufacturer is the manufacturer name for a transponder of ISO 15693 standard
				/// m_sEpcC1G2MaskDesignerName is the manufacturer name for a transponder of EPC Class 1 Gen 2 or ISO 18000-3M3 standard (only available if isEpcAndTid() returns true)
				/// m_uiEpcC1G2TagModelNumber is the chip ID for a transponder of EPC Class 1 Gen 2 or ISO 18000-3M3 standard (only available if isEpcAndTid() returns true)
				/// m_uiEpcC1G2MaskDesignerID is the manufacturer ID of EPC Class 1 Gen 2 or ISO 18000-3M3 standard (only available if isEpcAndTid() returns true)
				class _FEDM_ISC_CORE_EXT_CLASS SectorIdd
				{
				public:
					SectorIdd();
					~SectorIdd();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid()         const { return m_trType >= 0; }
					bool isValidAfi()      const { return m_afi >= 0; }
					bool isIso15693()      const { return m_trType == FEDM_ISC_TR_TYPE_ISO15693; }
					bool isEpcClass1Gen2() const { return m_trType == FEDM_ISC_TR_TYPE_EPC_CLASS1_GEN2; }
					bool isIso18000_3M3()  const { return m_trType == FEDM_ISC_TR_TYPE_ISO18000_3M3; }
					bool isExtendedPC_W1() const { return (m_ucClass1Gen2_PC[0] & 0x02) != 0; }
					bool isEpcAndTid()     const { return m_iddt == 0x02; }

					std::string iddToHexString() const;
					SectorIdd &operator=(const SectorIdd & other);

					std::vector<unsigned char> m_idd;
					int m_trType;
					int m_afi;
					int m_dsfid;
					int m_iddt;
					int m_tagStatus;
					int m_newAfi;
					unsigned char m_ucClass1Gen2_PC[2];
					unsigned char m_ucClass1Gen2_XPC_W1[2];
					std::string   m_sIso15693Manufacturer;
					std::string   m_sEpcC1G2MaskDesignerName;
					unsigned int  m_uiEpcC1G2TagModelNumber;
					unsigned int  m_uiEpcC1G2MaskDesignerID;
				};

				/// @brief Class stores the data blocks
				///
				/// <b>Description</b><br>
				/// Each block has a size of m_blkSize bytes.
				/// m_blkCount is the number of data blocks. The std::vector has a total size of m_blkSize * m_blkCount bytes.
				class _FEDM_ISC_CORE_EXT_CLASS SectorDataBlocks
				{
				public:
					SectorDataBlocks();
					~SectorDataBlocks();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid() const { return !m_blocks.empty(); }

					SectorDataBlocks &operator=(const SectorDataBlocks & other);

					std::vector<unsigned char> m_blocks;
					int m_blkSize;
					int m_blkCount;
				};

				/// @brief Class is derived from Utility::DateTime, storing the date and time information
				class _FEDM_ISC_CORE_EXT_CLASS SectorDateTime : public Utility::DateTime
				{
				public:
					SectorDateTime();
					~SectorDateTime();
				};

				/// @param Key Antenna Number
				/// @param Value RSSI value
				typedef std::map<unsigned char, RssiItem> MapRssi;
				typedef MapRssi::const_iterator MapRssiConstItor;

				/// @brief Class stores the RSSI values
				/// @param Key Antenna Number
				/// @param Value RSSI value
				class _FEDM_ISC_CORE_EXT_CLASS SectorRssi
				{
				public:
					SectorRssi();
					~SectorRssi();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid() const { return !m_mapRssi.empty(); }

					SectorRssi &operator=(const SectorRssi & other);

					MapRssi m_mapRssi;
				};

				/// @brief Class stores the antenna numbers
				///
				/// <b>Description</b><br>
				/// m_antennaNo is a bit field (see manual of the reader)
				class _FEDM_ISC_CORE_EXT_CLASS SectorAntenna
				{
				public:
					SectorAntenna();
					~SectorAntenna();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid()        const { return m_antennaNo >= 0; }
					bool isTagStatistic() const { return isValid() && (m_tagCount >= 0); }

					std::string toString() const;
					SectorAntenna &operator=(const SectorAntenna & other);

					int m_antennaNo;
					int m_tagCount;
					int m_rssiMax;
					int m_rssiAvg;
				};

				/// @brief Class stores the input states and state flags
				class _FEDM_ISC_CORE_EXT_CLASS SectorInput
				{
				public:
					SectorInput();
					~SectorInput();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid() const;

					SectorInput &operator=(const SectorInput & other);

					int m_input;
					int m_state;
				};

				/// @brief Class stores the MAC address
				class _FEDM_ISC_CORE_EXT_CLASS SectorMac
				{
				public:
					SectorMac();
					~SectorMac();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid() const;

					SectorMac &operator=(const SectorMac & other);

					unsigned char m_ucMacAddr[6];
				};

				/// @brief Class stores the Scanner-ID
				class _FEDM_ISC_CORE_EXT_CLASS SectorScannerID
				{
				public:
					SectorScannerID();
					~SectorScannerID();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					/// @brief Indicates, if sector contains valid data for Scanner-ID
					bool isValid() const;

					SectorScannerID &operator=(const SectorScannerID & other);

					unsigned char m_idType; ///< 0x00: ScannerID; 0x01: DeviceID
					std::string m_sScannerID; ///< Scanner-ID (only for Notification-Mode)
				};

				/// @brief Class stores the gate people counter direction information
				class _FEDM_ISC_CORE_EXT_CLASS SectorDirection
				{
				public:
					static const int DetectionDisabled = 0;
					static const int Direction1 = 1;
					static const int Direction2 = 2;

					SectorDirection();
					~SectorDirection();

					/// @brief Method clears all member variables and sets the object's state to invalid
					void clear();

					bool isValid()             const { return m_direction >= 0; }
					bool isDetectionDisabled() const { return m_direction == DetectionDisabled; }
					bool isDirection1()        const { return m_direction == Direction1; }
					bool isDirection2()        const { return m_direction == Direction2; }

					SectorDirection &operator=(const SectorDirection & other);

					int m_direction;
				};


			protected:
				BrmTableItem(FEDM_BRMTabItem* pTableItem, unsigned int uiIndex);	// constructor

				void Init(FEDM_BRMTabItem* pTableItem);

				// data elements
			public:
				BrmTableItem();
				~BrmTableItem();	// destructor

				SectorIdd        m_SectorIdd;
				SectorDataBlocks m_SectorDataBlocks;
				SectorDateTime   m_SectorDateTime;
				SectorRssi       m_SectorRssi;
				SectorAntenna    m_SectorAntenna;
				SectorInput      m_SectorInput;
				SectorMac        m_SectorMac;
				SectorScannerID  m_SectorScannerID;
				SectorDirection  m_SectorDirection;

				BrmTableItem &operator=(const BrmTableItem & other);

			protected:

				unsigned int		m_uiIndex;

			};



			/// @brief Set size of the table
			///
			/// @param[in] uiNewSize Maximal numbers of records in the Buffered Read Mode Table
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// The call of this method or overloaded SetSize(unsigned int,unsigned int,unsigned int) is mandatory, when the Buffered Read Mode Table should be used in the application.<br>
			/// The table size should be set to the maximal number of records, received by the command [0x22] Read Buffer.<br>
			/// This method initializes the buffer for Transponder data to 1024 bytes, which means 256 data blocks of each 4 bytes.
			/// The content of the table will be deleted.
			int SetSize(unsigned int uiNewSize);

			/// @brief Set size of the table with additional option to set the Transponder data buffer size
			///
			/// @param[in] uiNewSize Maximal numbers of records in the Buffered Read Mode Table
			/// @param[in] uiRxDB_BlockCount Number of data blocks
			/// @param[in] uiRxDB_BlockSize Size of each data block in byte
			/// @return OK (=0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// The call of this method or overloaded SetSize(unsigned int) is mandatory, when the Buffered Read Mode Table should be used in the application.<br>
			/// The table size should be set to the maximal number of records, received by the command [0x22] Read Buffer.<br>
			/// This method initializes the buffer for Transponder data to user defined size, calculated by uiRxDB_BlockCount data blocks with each uiRxDB_BlockSize bytes.<br>
			/// The content of the table will be deleted.
			int SetSize(unsigned int uiNewSize, unsigned int uiRxDB_BlockCount, unsigned int uiRxDB_BlockSize);
	
			/// @brief Return actual table size
			///
			/// @return Size (>0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			int GetSize();

			/// @brief Get number of valid table items
			///
			/// @return Length (>0) or [error code](@ref FEDM::Core::ErrorCode) (<0)
			///
			/// <b>Description</b><br>
			/// Call this method to get the actual number of valid table items after the command [0x22] Read Buffer.
			int GetLength();

			/// @brief Get a valid table item, identified by index
			///
			/// @param[in] uiIdx Table index, beginning with 0
			/// @return table item. See [BrmTableItem](@ref BrmTableItem) for more information
			///
			/// <b>Description</b><br>
			/// With this method, the table items (each contains one record from the Reader response) can be gradually requested.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			///
			/// IBrmTableGroup::BrmTableItem* pItem = NULL; // pointer to table item
			///  
			/// int back = reader.IBrm.ReadBuffer(255);
			/// if( back == 0 ||		// status: OK
			///		back == 0x84 ||		// status: RF warning
			///		back == 0x93 ||		// status: buffer overflow
			///		back == 0x94 )		// status: more data
			/// {
			///		// internal Buffered Read Mode Table contains now the new records
			///
			///		for(int iIdx=0; iIdx<reader.IBrmTable.GetLength(); iIdx++)
			///		{
			///			pItem = reader.IBrmTable.GetItemByIndex(iIdx);
			///			if(pItem->m_sectorIDD.isValid())
			///			{
			///				// IDD is part of the received record
			///			}
			///
			///			if(pItem->m_sectorDataBlocks.isValid())
			///			{
			///				// received record contains Transponder data
			///			}
			///		}
			/// }
			/// 
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			BrmTableItem* GetItemByIndex(unsigned int uiIdx);

            /// <summary>
            /// Read data sets from Reader's internal data buffer with [0x22] Read Buffer command.
            /// 
            /// <b>Description:</b><br/>
            /// This command is only applicable when the Buffered Read Mode is enabled in the Reader.<br/>
            /// The responded data records are stored in the internal BrmTable. Each record can be successively requested as a <see cref="BrmTableItem"/> with the method <see cref="GetItemByIndex"/>.<br/>
            /// The Buffered Read Mode is widely configurable and the settings determine the responded data. For more information about the configuration, see Reader's System Manual.<br/>
            /// The configuration parameters for the Buffered Read Mode are collected in the parameter namespace ReaderConfig.OperatingMode.BufferedReadMode.
            /// </summary>
            /// <param name="uiDataSets">Number of requested data sets. Must be less than 256.<br/>
            /// If the data buffer does not contain the requested number of data sets, the Reader responds with all available data sets.</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
			/// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int ReadBuffer(unsigned int uiDataSets);

            /// <summary>
            /// Clear of transferred data sets from Reader's internal data buffer with [0x32] Clear Data Buffer command.
            /// 
            /// <b>Description:</b><br/>
            /// The clear command deletes all already transferred data sets in the Reader's internal data buffer.<br/>
            /// All not queried data sets remain in the buffer until they are queried with <see cref="ReadBuffer"/>.
            /// </summary>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			/// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int ClearBuffer();

            /// <summary>
            /// Initialize of the Reader's internal data buffer with [0x33] Initialize Buffer command.
            /// 
            /// <b>Description:</b><br/>
            /// The internal buffer is cleared and all data gets lost.
            /// </summary>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int InitializeBuffer();

            /// <summary>
            /// Query of current fill level and size of the Reader's internal data buffer with [0x31] Read Data Buffer Info command. 
            /// 
            /// <b>Description:</b><br/>
            /// The Reader's internal data buffer is organized as a First-in First-out memory (FIFO) with the size of tableSize.<br/>
            /// If the buffer is full (tableLength == tableSize), every new generated data set overwrites the oldest data set.<br/>
            /// An overflow is indicated with the return status 0x93 (Data Buffer Overflow) of method <see cref="ReadBuffer"/>.
            /// </summary>
            /// <param name="uiTableSize">Maximum count of data sets in the data buffer</param>
            /// <param name="uiTableStart">Address of first data Set in the data buffer</param>
            /// <param name="uiTableLength">Number of data sets stored currently in the data buffer</param>
            /// <returns>
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
            /// 
            /// <b>It is strongly recommended to evaluate always the return value in the application.</b>
            /// </returns>
            int GetBufferInfo(unsigned int & uiTableSize, unsigned int & uiTableStart, unsigned int & uiTableLength);

		private:
			IBrmTableGroup();
			virtual ~IBrmTableGroup();

			ReaderModule *m_pParent;
			FEDM_ISCReaderModule* m_pReader;

			std::vector<BrmTableItem*> m_BrmTable;
		};
	}
}

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_IBRMTABLE_GROUP_H_INCLUDED_)
