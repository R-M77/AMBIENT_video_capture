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

#if !defined(_FEDM_CORE_ERROR_H_INCLUDED_)
#define _FEDM_CORE_ERROR_H_INCLUDED_

#include <string>
#include "../source/FEDM.h"
#include "feisc.h"
#if !defined(_FEDM_NO_COM_SUPPORT)
	#include "fecom.h"
#endif
#if !defined(_FEDM_NO_USB_SUPPORT)
	#include "feusb.h"
#endif
#if !defined(_FEDM_NO_TCP_SUPPORT)
	#include "fetcp.h"
#endif
#if !defined(_FEDM_NO_FU_SUPPORT)
	#include "fefu.h"
#endif
#if !defined(_FEDM_NO_TAG_HANDLER) && !defined(_FEDM_NO_TAG_HANDLER_ISO14443)
	#include "fetcl.h"
#endif
#if !defined(_FEDM_NO_FW_UPD_SUPPORT)
	#include "../../fedm-service/source/firmware_update/FEDM_FwUpdErrorCodes.h"
#endif

namespace FEDM
{
	namespace Core
	{
		/** %Error codes
		*/
		class _FEDM_ISC_CORE_EXT_CLASS ErrorCode
		{
		public:

			/** @brief Query method for error text
			*
			* @param[in] iErrorCode error code
			* @return string with error text
			*/
			static std::string GetErrorText(int iErrorCode);

			/** OK (0) - Value for successful operation
			*/
			static const int OK = FEDM_OK;
			/** Error (-101): Block size in the access constant is incorrect
			*/
			static const int BLOCK_SIZE = FEDM_ERROR_BLOCK_SIZE;
			/** Error (-102): Bit boundary in the access constant is incorrect
			*/
			static const int BIT_BOUNDARY = FEDM_ERROR_BIT_BOUNDARY;
			/** Error (-103): Byte boundary in the access constant is incorrect
			*/
			static const int BYTE_BOUNDARY = FEDM_ERROR_BYTE_BOUNDARY;
			/** Error (-104): Array boundary of a data container was exceeded
			*/
			static const int ARRAY_BOUNDARY = FEDM_ERROR_ARRAY_BOUNDARY;
			/** Error (-105): Length of the data buffer is insufficient
			*/
			static const int BUFFER_LENGTH = FEDM_ERROR_BUFFER_LENGTH;
			/** Error (-106): Unknown transfer parameter or parameter value is out of valid range
			*/
			static const int PARAMETER = FEDM_ERROR_PARAMETER;
			/** Error (-107): Transferred string is too long
			*/
			static const int STRING_LENGTH = FEDM_ERROR_STRING_LENGTH;
			/** Error (-108): Transferred string contains an odd number of characters. Even number of characters expected
			*/
			static const int ODD_STRING_LENGTH = FEDM_ERROR_ODD_STRING_LENGTH;
			/** Error (-109): No data in the protocol
			*/
			static const int NO_DATA_IN_PROTOCOL = FEDM_ERROR_NO_DATA;
			/** Error (-110): No reader handle set
			*/
			static const int NO_READER_HANDLE = FEDM_ERROR_NO_READER_HANDLE;
			/** Error (-111): No port handle set
			*/
			static const int NO_PORT_HANDLE = FEDM_ERROR_NO_PORT_HANDLE;
			/** Error (-112): Unknown control byte
			*/
			static const int UNKNOWN_CONTROL_BYTE = FEDM_ERROR_UNKNOWN_CONTROL_BYTE;
			/** Error (-113): Unknown memory ID
			*/
			static const int UNKNOWN_MEM_ID = FEDM_ERROR_UNKNOWN_MEM_ID;
			/** Error (-114): Unknown poll mode
			*/
			static const int UNKNOWN_POLL_MODE = FEDM_ERROR_UNKNOWN_POLL_MODE;
			/** Error (-115): No data in a table
			*/
			static const int NO_TABLE_DATA = FEDM_ERROR_NO_TABLE_DATA;
			/** Error (-116): Unknown error code
			*/
			static const int UNKNOWN_ERROR_CODE = FEDM_ERROR_UNKNOWN_ERROR_CODE;
			/** Error (-117): Unknown ISO-Host command
			*/
			static const int UNKNOWN_COMMAND = FEDM_ERROR_UNKNOWN_COMMAND;
			/** Error (-118): No support for this parameter or function
			*/
			static const int UNSUPPORTED = FEDM_ERROR_UNSUPPORTED;
			/** Error (-119): No more program memory available
			*/
			static const int NO_MEMORY = FEDM_ERROR_NO_MORE_MEM;
			/** Error (-120): No reader found
			*/
			static const int NO_READER_FOUND = FEDM_ERROR_NO_READER_FOUND;
			/** Error (-121): The transferred pointer is NULL
			*/
			static const int NULL_POINTER = FEDM_ERROR_NULL_POINTER;
			/** Error (-122): Unknown reader type
			*/
			static const int UNKNOWN_READER_TYPE = FEDM_ERROR_UNKNOWN_READER_TYPE;
			/** Error (-123): The Function doesn't support this reader type
			*/
			static const int UNSUPPORTED_READER_TYPE = FEDM_ERROR_UNSUPPORTED_READER_TYPE;
			/** Error (-124): Unknown table constant
			*/
			static const int UNKNOWN_TABLE_ID = FEDM_ERROR_UNKNOWN_TABLE_ID;
			/** Error (-125): Unknown language constant
			*/
			static const int UNKNOWN_LANGUAGE = FEDM_ERROR_UNKNOWN_LANGUAGE;
			/** Error (-126): The table has the size 0
			*/
			static const int NO_TABLE_SIZE = FEDM_ERROR_NO_TABLE_SIZE;
			/** Error (-127): The Sendbuffer is full
			*/
			static const int SENDBUFFER_OVERFLOW = FEDM_ERROR_SENDBUFFER_OVERFLOW;
			/** Error (-128): Data are not equal
			*/
			static const int VERIFY = FEDM_ERROR_VERIFY;
			/** Error (-129): File open error
			*/
			static const int OPEN_FILE = FEDM_ERROR_OPEN_FILE;
			/** Error (-130): File save error
			*/
			static const int SAVE_FILE = FEDM_ERROR_SAVE_FILE;
			/** Error (-131): Unknown transponder type
			*/
			static const int UNKNOWN_TRANSPONDER_TYPE = FEDM_ERROR_UNKNOWN_TRANSPONDER_TYPE;
			/** Error (-132): File read error
			*/
			static const int READ_FILE = FEDM_ERROR_READ_FILE;
			/** Error (-133): File write error
			*/
			static const int WRITE_FILE = FEDM_ERROR_WRITE_FILE;
			/** Error (-134): Unknown EPC type
			*/
			static const int UNKNOWN_EPC_TYPE = FEDM_ERROR_UNKNOWN_EPC_TYPE;
			/** Error (-135): Function does not support the active communication driver
			*/
			static const int UNSUPPORTED_PORT_DRIVER = FEDM_ERROR_UNSUPPORTED_PORT_DRIVER;
			/** Error (-136): Unknown address mode
			*/
			static const int UNKNOWN_ADDRESS_MODE = FEDM_ERROR_UNKNOWN_ADDRESS_MODE;
			/** Error (-137): Reader object is already connected with a communication port
			*/
			static const int ALREADY_CONNECTED = FEDM_ERROR_ALREADY_CONNECTED;
			/** Error (-138): Reader object is not connected with a communication port
			*/
			static const int NOT_CONNECTED = FEDM_ERROR_NOT_CONNECTED;
			/** Error (-139): No module handle found
			*/
			static const int NO_MODULE_HANDLE = FEDM_ERROR_NO_MODULE_HANDLE;
			/** Error (-140): The module list is empty
			*/
			static const int EMPTY_MODULE_LIST = FEDM_ERROR_EMPTY_MODULE_LIST;
			/** Error (-141): Module not found in module list
			*/
			static const int MODULE_NOT_FOUND = FEDM_ERROR_MODULE_NOT_FOUND;
			/** Error (-142): Runtime objects are different
			*/
			static const int DIFFERENT_OBJECTS = FEDM_ERROR_DIFFERENT_OBJECTS;
			/** Error (-143): IDD of transponder is not an EPC
			*/
			static const int NOT_AN_EPC = FEDM_ERROR_NOT_AN_EPC;
			/** Error (-144): Old library version. Function call not possible
			*/
			static const int OLD_LIB_VERSION = FEDM_ERROR_OLD_LIB_VERSION;
			/** Error (-145): Wrong reader type
			*/
			static const int WRONG_READER_TYPE = FEDM_ERROR_WRONG_READER_TYPE;
			/** Error (-146): Verification of file content terminates with checksum error
			*/
			static const int CRC = FEDM_ERROR_CRC;
			/** Error (-147): The configuration block must be first read before write
			*/
			static const int CONFIG_BLOCK_PREVIOUSLY_NOT_READ = FEDM_ERROR_CFG_BLOCK_PREVIOUSLY_NOT_READ;
			/** Error (-148): Function does not support this controller type
			*/
			static const int UNSUPPORTED_CONTROLLER_TYPE = FEDM_ERROR_UNSUPPORTED_CONTROLLER_TYPE;
			/** Error (-149): Version conflict with one or more dependent libraries
			*/
			static const int VERSION_CONFLICT = FEDM_ERROR_VERSION_CONFLICT;
			/** Error (-150): Connected reader does not support this parameter
			*/
			static const int UNSUPPORTED_NAMESPACE = FEDM_ERROR_UNSUPPORTED_NAMESPACE;
			/** Error (-151): Asynchronous task is still running
			*/
			static const int TASK_STILL_RUNNING = FEDM_ERROR_TASK_STILL_RUNNING;
			/** Error (-152): TagHandler type could not be identified
			*/
			static const int TAG_HANDLER_NOT_IDENTIFIED = FEDM_ERROR_TAG_HANDLER_NOT_IDENTIFIED;
			/** Error (-153): Value of IDD-Length is out of range
			*/
			static const int INVALID_IDD_LENGTH = FEDM_ERROR_UNVALID_IDD_LENGTH;
			/** Error (-154): Value of IDD-Format is out of range
			*/
			static const int INVALID_IDD_FORMAT = FEDM_ERROR_UNVALID_IDD_FORMAT;
			/** Error (-155): Unknown TagHandler type
			*/
			static const int UNKNOWN_TAG_HANDLER_TYPE = FEDM_ERROR_UNKNOWN_TAG_HANDLER_TYPE;
			/** Error (-156): Transponder type is not supported by the selected task
			*/
			static const int UNSUPPORTED_TRANSPONDER_TYPE = FEDM_ERROR_UNSUPPORTED_TRANSPONDER_TYPE;
			/** Error (-157): Another Reader object is already connected with this communication port
			*/
			static const int CONNECTED_WITH_OTHER_MODULE = FEDM_ERROR_CONNECTED_WITH_OTHER_MODULE;
			/** Error (-158): Inventory with return of IDD = EPC + TID, but TID is missing
			*/
			static const int INVENTORY_NO_TID_IN_IDD = FEDM_ERROR_INVENTORY_NO_TID_IN_UID;
			/** Error (-159): TagHandler type could not be found in the tag list
			*/
			static const int TAG_HANDLER_NOT_FOUND = FEDM_ERROR_TAG_HANDLER_NOT_FOUND;
			/** Error (-160): Wrong protcol response length
			*/
			static const int DATA_LENGTH = FEDM_ERROR_DATA_LENGTH;

			/** %Error codes related to XML files
			*/
			class _FEDM_ISC_CORE_EXT_CLASS XmlFile
			{
			public:
				/** Error (-200): File is not a XML document
				*/
				static const int NO_XML_FILE = FEDM_XML_ERROR_NO_XML_FILE;
				/** Error (-201): File contains no element 'OBID'
				*/
				static const int NO_OBID_TAG = FEDM_XML_ERROR_NO_OBID_TAG;
				/** Error (-202): No sub-element found
				*/
				static const int NO_CHILD_TAG = FEDM_XML_ERROR_NO_CHILD_TAG;
				/** Error (-203): Element not in the document
				*/
				static const int TAG_NOT_FOUND = FEDM_XML_ERROR_TAG_NOT_FOUND;
				/** Error (-204): XML document not well-formed
				*/
				static const int DOC_NOT_WELL_FORMED = FEDM_XML_ERROR_DOC_NOT_WELL_FORMED;
				/** Error (-205): No content of element found
				*/
				static const int NO_TAG_VALUE = FEDM_XML_ERROR_NO_TAG_VALUE;
				/** Error (-206): No attribute found
				*/
				static const int NO_TAG_ATTRIBUTE = FEDM_XML_ERROR_NO_TAG_ATTRIBUTE;
				/** Error (-207): Invalid document version
				*/
				static const int DOC_FILE_VERSION = FEDM_XML_ERROR_DOC_FILE_VERSION;
				/** Error (-208): The Document is for another reader family
				*/
				static const int DOC_FILE_FAMILY = FEDM_XML_ERROR_DOC_FILE_FAMILY;
				/** Error (-209): The document is not a valid file type
				*/
				static const int DOC_FILE_TYPE = FEDM_XML_ERROR_DOC_FILE_TYPE;
				/** Error (-210): Wrong controller type
				*/
				static const int WRONG_CONTROLLER_TYPE = FEDM_XML_ERROR_WRONG_CONTROLLER_TYPE;
				/** Error (-211): Wrong memory bank type
				*/
				static const int WRONG_MEM_BANK_TYPE = FEDM_XML_ERROR_WRONG_MEM_BANK_TYPE;
			};

		#if !defined(_FEDM_NO_FW_UPD_SUPPORT)
			/** %Error codes related to firmware update
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FwUpdate
			{
			public:
				/** Error (-400): Firmware Update Service: Checksum error
				*/
				static const int CHECKSUM = FEDM_ERROR_FW_UPD_CHECKSUM;
				/** Error (-401): Firmware Update Service: Wrong controller type
				*/
				static const int WRONG_CONTROLLER_TYPE = FEDM_ERROR_FW_UPD_WRONG_CONTROLLER_TYPE;
				/** Error (-402): Firmware Update Service: Unsupported controller type
				*/
				static const int UNSUPPORTED_CONTROLLER_TYPE = FEDM_ERROR_FW_UPD_UNSUPPORTED_CONTROLLER_TYPE;
				/** Error (-403): Firmware Update Service: File corruption
				*/
				static const int FILE_DEFECT = FEDM_ERROR_FW_UPD_FILE_DEFECT;
				/** Error (-404): Firmware Update Service: Received package length is too large
				*/
				static const int BLOCKSIZE_RANGE = FEDM_ERROR_FW_UPD_BLOCKSIZE_RANGE;
				/** Error (-405): Firmware Update Service: Start of background update thread failed
				*/
				static const int THREAD_START = FEDM_ERROR_FW_UPD_THREAD_START;
				/** Error (-406): Firmware Update Service: Missing parts of reader info
				*/
				static const int READER_INFO_INCOMPLETE = FEDM_ERROR_FW_UPD_READER_INFO_INCOMPLETE;
				/** Error (-407): Firmware Update Service: The reader firmware meets not the update requirements
				*/
				static const int FIRMWARE_REQUIREMENT = FEDM_ERROR_FW_UPD_FIRMWARE_REQUIREMENT;
				/** Error (-408): Firmware Update Service: The readers device info meets not the update requirements
				*/
				static const int DEVICE_REQUIREMENT = FEDM_ERROR_FW_UPD_DEVICE_REQUIREMENT;
				/** Error (-409): Firmware Update Service: The readers RFC Silicon revision meets not the update requirements
				*/
				static const int SILICON_REQUIREMENT = FEDM_ERROR_FW_UPD_SILICON_REQUIREMENT;
				/** Error (-410): Firmware Update Service: Error in activation of update process
				*/
				static const int ACTIVATION = FEDM_ERROR_FW_UPD_ACTIVATION;
				/** Error (-411): Firmware Update Service: Error while upload of firmware file
				*/
				static const int UPLOAD = FEDM_ERROR_FW_UPD_UPLOAD;
				/** Error (-412): Firmware Update Service: Error while delete of flash
				*/
				static const int DELETE_FLASH = FEDM_ERROR_FW_UPD_DELETE_FLASH;
				/** Error (-413): Firmware Update Service: Error while flash of target
				*/
				static const int WRITE_FLASH = FEDM_ERROR_FW_UPD_WRITE_FLASH;
				/** Error (-414): Firmware Update Service: Error while waiting for end of delete flash process
				*/
				static const int OBSERVE_DELETE_FLASH = FEDM_ERROR_FW_UPD_OBSERVE_DELETE_FLASH;
				/** Error (-415): Firmware Update Service: Error while waiting for end of flash process
				*/
				static const int OBSERVE_WRITE_FLASH = FEDM_ERROR_FW_UPD_OBSERVE_WRITE_FLASH;
				/** Error (-416): Firmware Update Service: Reset of target failed
				*/
				static const int RESET_TARGET = FEDM_ERROR_FW_UPD_RESET_TARGET;
				/** Error (-417): Firmware Update Service: User canceled update process
				*/
				static const int CANCELED_BY_USER = FEDM_ERROR_FW_UPD_CANCELED_BY_USER;
				/** Error (-418): Firmware Update Service: Selected port type is not supported
				*/
				static const int UNSUPPORTED_PORT_TYPE = FEDM_ERROR_FW_UPD_UNSUPPORTED_PORT_TYPE;
				/** Error (-419): Firmware Update Service: Reconnect of target failed
				*/
				static const int RECONNECT_TARGET = FEDM_ERROR_FW_UPD_RECONNECT_TARGET;
				/** Error (-420): Firmware Update Service: New enumeration of target failed
				*/
				static const int REENUMERATE_TARGET = FEDM_ERROR_FW_UPD_REENUMERATE_TARGET;
				/** Error (-421): Firmware Update Service: Firmware file not found
				*/
				static const int FILE_NOT_FOUND = FEDM_ERROR_FW_UPD_FILE_NOT_FOUND;
				/** Error (-422): Firmware Update Service: Missing parts in firmware file
				*/
				static const int FILE_INCOMPLETE = FEDM_ERROR_FW_UPD_FILE_INCOMPLETE;
				/** Error (-423): Firmware Update Service: Missing partition number
				*/
				static const int PARTITION_NO_MISSING = FEDM_ERROR_FW_UPD_PARTITION_NO_MISSING;
				/** Error (-424): Firmware Update Service: partition number is present twice
				*/
				static const int DOUBLE_PARTITION = FEDM_ERROR_FW_UPD_DOUBLE_PARTITION;
				/** Error (-425): Firmware Update Service: multiple firmware bank not supported
				*/
				static const int MULTIPLE_BANKS_UNSUPPORTED = FEDM_ERROR_FW_UPD_MULTIPLE_BANKS_UNSUPPORTED;
				/** Error (-426): Firmware Update Service: Illegal change of firmware version
				*/
				static const int LRU3000_CHANGE_VERSION = FEDM_ERROR_FW_UPD_LRU3000_CHANGE_VERSION;
				/** Error (-427): Firmware Update Service: firmware file is not supported. One or more required criteria checks failed
				*/
				static const int FILE_NOT_SUPPORTED = FEDM_ERROR_FW_UPD_FILE_NOT_SUPPORTED;
				/** Error (-428): Firmware Update Service: Selected update file requires a newer Update Tool version
				*/
				static const int TOOL_VERSION_MISMATCH = FEDM_ERROR_FW_UPD_TOOL_VERSION_MISMATCH;
			};
		#endif

		#if !defined(_FEDM_NO_COM_SUPPORT)
			/** %Error codes from communication library FECOM for serial port
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FECOM
			{
			public:
				// common errors
				/** Error (-1000): error while creating new port object
				*/
				static const int NEWPORT_FAILURE = FECOM_ERR_NEWPORT_FAILURE;
				/** Error (-1001): empty port list
				*/
				static const int EMPTY_LIST = FECOM_ERR_EMPTY_LIST;
				/** Error (-1002): pointer is NULL
				*/
				static const int POINTER_IS_NULL = FECOM_ERR_POINTER_IS_NULL;
				/** Error (-1003): no more memory
				*/
				static const int NO_MEMORY = FECOM_ERR_NO_MEMORY;
				/** Error (-1004): unsupported hardware
				*/
				static const int UNSUPPORTED_HARDWARE = FECOM_ERR_UNSUPPORTED_HARDWARE;
				/** Error (-1005): port not detected
				*/
				static const int PORT_NOT_FOUND = FECOM_ERR_PORT_NOT_FOUND;
				/** Error (-1006): Unsupported function or option
				*/
				static const int UNSUPPORTED = FECOM_ERR_UNSUPPORTED;

				// error while open the port
				/** Error (-1010): error while open port
				*/
				static const int NO_PORT = FECOM_ERR_NO_PORT;
				/** Error (-1011): port open timeout
				*/
				static const int NO_CONNECT = FECOM_ERR_NO_CONNECT;
				/** Error (-1012): port number is false
				*/
				static const int LINK_ID = FECOM_ERR_LINK_ID;
				/** Error (-1013): port is already open
				*/
				static const int PORT_IS_OPEN = FECOM_ERR_PORT_IS_OPEN;

				// handle errors
				/** Error (-1020): unknown port handle
				*/
				static const int UNKNOWN_HANDLE = FECOM_ERR_UNKNOWN_HND;
				/** Error (-1021): port handle is zero
				*/
				static const int HANDLE_IS_NULL = FECOM_ERR_HND_IS_NULL;
				/** Error (-1022): port handle is negativ
				*/
				static const int HANDLE_IS_NEGATIVE = FECOM_ERR_HND_IS_NEGATIVE;
				/** Error (-1023): no port handle found
				*/
				static const int NO_HANDLE_FOUND = FECOM_ERR_NO_HND_FOUND;

				// communication errors
				/** Error (-1030): receive timeout
				*/
				static const int TIMEOUT = FECOM_ERR_TIMEOUT;
				/** Error (-1031): no transmit protocol
				*/
				static const int NO_SEND_PROTOCOL = FECOM_ERR_NO_SENDPROTOCOL;
				/** Error (-1032): error in read process
				*/
				static const int RECEIVE_PROCESS = FECOM_ERR_RECEIVE_PROCESS;
				/** Error (-1033): communication process not started
				*/
				static const int INIT_COMM_PROCESS = FECOM_ERR_INIT_COMM_PROCESS;
				/** Error (-1034): delete input buffer
				*/
				static const int FLUSH_INPUT_BUFFER = FECOM_ERR_FLUSH_INPUT_BUFFER;
				/** Error (-1035): delete output buffer
				*/
				static const int FLUSH_OUTPUT_BUFFER = FECOM_ERR_FLUSH_OUTPUT_BUFFER;
				/** Error (-1036): change port parameter
				*/
				static const int CHANGE_PORT_PARAMETER = FECOM_ERR_CHANGE_PORT_PARA;
				/** Error (-1037): error in transmit process
				*/
				static const int TRANSMIT_PROCESS = FECOM_ERR_TRANSMIT_PROCESS;
				/** Error (-1038): noise data received (Frame and/or Parity is false)
				*/
				static const int RECEIVE_NOISE_DATA = FECOM_ERR_RECEIVE_NOISE_DATA;
				/** Error (-1039): port is busy
				*/
				static const int PORT_IS_BUSY = FECOM_ERR_PORT_IS_BUSY;
				/** Error (-1040): error while read of port parameter
				*/
				static const int READ_PORT_PARAMETER = FECOM_ERR_READ_PORT_PARA;

				// parameter errors
				/** Error (-1050): unknown parameter
				*/
				static const int UNKNOWN_PARAMETER = FECOM_ERR_UNKNOWN_PARAMETER;
				/** Error (-1051): parameter out of range
				*/
				static const int PARAMETER_OUT_OF_RANGE = FECOM_ERR_PARAMETER_OUT_OF_RANGE;
				/** Error (-1052): odd parameterstring
				*/
				static const int ODD_PARAMETER_STRING = FECOM_ERR_ODD_PARAMETERSTRING;
				/** Error (-1053): port number out of range
				*/
				static const int PORT_NUMBER_OUT_OF_RANGE = FECOM_ERR_PORTNR_OUT_OF_RANGE;
				/** Error (-1054): unknown error code
				*/
				static const int UNKNOWN_ERRORCODE = FECOM_ERR_UNKNOWN_ERRORCODE;

				// receive buffer overflow
				/** Error (-1070): receive buffer overflow
				*/
				static const int RECEIVE_BUFFER_OVERFLOW = FECOM_ERR_OVL_RECBUF;
			};
		#endif

		#if !defined(_FEDM_NO_USB_SUPPORT)
			/** %Error codes from communication library FEUSB for Universal Serial POrt
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FEUSB
			{
			public:
				/** Error (-1100): empty device list
				*/
				static const int EMPTY_DEVICE_LIST = FEUSB_ERR_EMPTY_DEVICELIST;
				/** Error (-1101): empty scan list
				*/
				static const int EMPTY_SCAN_LIST = FEUSB_ERR_EMPTY_SCANLIST;
				/** Error (-1102): pointer is NULL
				*/
				static const int POINTER_IS_NULL = FEUSB_ERR_POINTER_IS_NULL;
				/** Error (-1103): no more memory
				*/
				static const int NO_MEMORY = FEUSB_ERR_NO_MORE_MEM;
				/** Error (-1104): The USB configuration could not be set
				*/
				static const int SET_CONFIGURATION = FEUSB_ERR_SET_CONFIGURATION;
				/** Error (-1105): Error in Kernel-Function
				*/
				static const int KERNEL = FEUSB_ERR_KERNEL;
				/** Error (-1106): unsupported option
				*/
				static const int UNSUPPORTED_OPTION = FEUSB_ERR_UNSUPPORTED_OPTION;
				/** Error (-1107): unsupported method
				*/
				static const int UNSUPPORTED_FUNCTION = FEUSB_ERR_UNSUPPORTED_FUNCTION;
				/** Error (-1108): device has no configuration
				*/
				static const int NO_CONFIGURATIONS = FEUSB_ERR_NO_CONFIGURATIONS;
				/** Error (-1109): libUSB-API not available
				*/
				static const int NOT_HAS_CAPABILITY = FEUSB_ERR_NOT_HAS_CAPABILITY;

				// error while scanning
				/** Error (-1110): no feig device
				*/
				static const int NO_FEIG_DEVICE = FEUSB_ERR_NO_FEIG_DEVICE;
				/** Error (-1111): search mismatch
				*/
				static const int SEARCH_MISMATCH = FEUSB_ERR_SEARCH_MISMATCH;
				/** Error (-1112): no device found
				*/
				static const int NO_DEVICE_FOUND = FEUSB_ERR_NO_DEVICE_FOUND;
				/** Error (-1113): device is already scanned
				*/
				static const int DEVICE_IS_SCANNED = FEUSB_ERR_DEVICE_IS_SCANNED;
				/** Error (-1114): scan list overflow
				*/
				static const int SCAN_LIST_OVERFLOW = FEUSB_ERR_SCANLIST_OVERFLOW;
				/** Error (-1115):
				*/
				//static const int NO_SCAN_FIRST = FEUSB_ERR_NO_SCAN_FIRST;

				// handle errors
				/** Error (-1120): unknown device handle
				*/
				static const int UNKNOWN_HANDLE = FEUSB_ERR_UNKNOWN_HND;
				/** Error (-1121): device handle is null
				*/
				static const int HANDLE_IS_NULL = FEUSB_ERR_HND_IS_NULL;
				/** Error (-1122): device handle is negative
				*/
				static const int HANDLE_IS_NEGATIVE = FEUSB_ERR_HND_IS_NEGATIVE;
				/** Error (-1123): no device handle found
				*/
				static const int NO_HANDLE_FOUND = FEUSB_ERR_NO_HND_FOUND;

				// communication errors (part1))
				/** Error (-1130): receice timeout
				*/
				static const int TIMEOUT = FEUSB_ERR_TIMEOUT;
				/** Error (-1131): no send data
				*/
				static const int NO_SEND_DATA = FEUSB_ERR_NO_SENDDATA;
				/** Error (-1132): unknown interface
				*/
				static const int UNKNOWN_INTERFACE = FEUSB_ERR_UNKNOWN_INTERFACE;
				/** Error (-1133): unknown direction
				*/
				static const int UNKNOWN_DIRECTION = FEUSB_ERR_UNKNOWN_DIRECTION;
				/** Error (-1134): receive buffer is too small
				*/
				static const int RECEIVE_BUFFER_TOO_SMALL = FEUSB_ERR_RECBUF_TOO_SMALL;
				/** Error (-1135): send data length is fault
				*/
				static const int SEND_DATA_LENGTH = FEUSB_ERR_SENDDATA_LEN;
				/** Error (-1136): unknown descriptor type
				*/
				static const int UNKNOWN_DESCRIPTOR_TYPE = FEUSB_ERR_UNKNOWN_DESCRIPTOR_TYPE;
				/** Error (-1137): device is not present
				*/
				static const int DEVICE_NOT_PRESENT = FEUSB_ERR_DEVICE_NOT_PRESENT;
				/** Error (-1138): error in transmit process
				*/
				static const int TRANSMIT_PROCESS = FEUSB_ERR_TRANSMIT_PROCESS;
				/** Error (-1139): bulk transfer error
				*/
				static const int BULK_TRANSFER = FEUSB_ERR_BULK_TRANSFER;

				// open/close device errors
				/** Error (-1140): device not scanned
				*/
				static const int DEVICE_NOT_SCANNED = FEUSB_ERR_DEVICE_NOT_SCANNED;
				/** Error (-1141): device is not in scan list
				*/
				static const int DEVICE_HANDLE_NOT_IN_SCAN_LIST = FEUSB_ERR_DEVHND_NOT_IN_SCANLIST;
				/** Error (-1142): device list handle is null
				*/
				static const int DRIVER_LIST = FEUSB_ERR_DRIVERLIST;
				/** Error (-1143): device cannot be opened
				*/
				static const int OPEN_DEVICE = FEUSB_ERR_OPEN_DEVICE;
				/** Error (-1144): device is not opened
				*/
				static const int DEVICE_NOT_OPENED = FEUSB_ERR_DEVICE_NOT_OPENED;
				/** Error (-1145): interface cannot be claimed
				*/
				static const int CLAIM_INTERFACE = FEUSB_ERR_CLAIM_INTERFACE;
				/** Error (-1146): wrong device, another device was expected
				*/
				static const int WRONG_DEVICE = FEUSB_ERR_WRONG_DEVICE;

				// parameter errors
				/** Error (-1150): unknown parameter
				*/
				static const int UNKNOWN_PARAMETER = FEUSB_ERR_UNKNOWN_PARAMETER;
				/** Error (-1151): parameter out of range
				*/
				static const int PARAMETER_OUT_OF_RANGE = FEUSB_ERR_PARAMETER_OUT_OF_RANGE;
				/** Error (-1152): odd parameter string
				*/
				static const int ODD_PARAMETER_STRING = FEUSB_ERR_ODD_PARAMETERSTRING;
				/** Error (-1153): index out of range
				*/
				static const int INDEX_OUT_OF_RANGE = FEUSB_ERR_INDEX_OUT_OF_RANGE;
				/** Error (-1154): unknown scan option
				*/
				static const int UNKNOWN_SCAN_OPTION = FEUSB_ERR_UNKNOWN_SCANOPTION;
				/** Error (-1155): unknown error code
				*/
				static const int UNKNOWN_ERROR_CODE = FEUSB_ERR_UNKNOWN_ERRORCODE;
				/** Error (-1156): parameter not available
				*/
				static const int PARAMETER_NOT_AVAILABLE = FEUSB_ERR_PARAMETER_NOT_AVAILABLE;
				/** Error (-1157): device reset failed
				*/
				static const int RESET_DEVICE_FAILED = FEUSB_ERR_RESET_DEVICE_FAILED;
				/** Error (-1158): parameter syntax error
				*/
				static const int PARAMETER_SYNTAX = FEUSB_ERR_PARAMETER_SYNTAX;

				// identification errors
				/** Error (-1160): device descriptor length is fault
				*/
				static const int DEVICE_DESCRIPTOR_LENGTH = FEUSB_ERR_DEV_DESC_LENGTH;
				/** Error (-1161): configuration descriptor length is fault
				*/
				static const int CONFIGURATION_DESCRIPTOR_LENGTH = FEUSB_ERR_CFG_DESC_LENGTH;
				/** Error (-1162): interface descriptor length is fault
				*/
				static const int INTFACE_DESCRIPTOR_LENGTH = FEUSB_ERR_INTF_DESC_LENGTH;
				/** Error (-1163): endpoint descriptor length is fault
				*/
				static const int ENDPOINT_DESCRIPTOR_LENGTH = FEUSB_ERR_ENDP_DESC_LENGTH;
				/** Error (-1164): HID descriptor length is fault
				*/
				static const int HID_DESCRIPTOR_LENGTH = FEUSB_ERR_HID_DESC_LENGTH;
				/** Error (-1165): string descriptor length is fault
				*/
				static const int STRING_DESCRIPTOR_LENGTH = FEUSB_ERR_STRG_DESC_LENGTH;
				/** Error (-1166): device descriptor read error
				*/
				static const int READ_DEVICE_DESCRIPTOR = FEUSB_ERR_READ_DEV_DESCRIPTOR;
				/** Error (-1167): configuration descriptor read error
				*/
				static const int READ_CONFIGURATION_DESCRIPTOR = FEUSB_ERR_READ_CFG_DESCRIPTOR;
				/** Error (-1168): string descriptor read error
				*/
				static const int READ_STRINGG_DESCRIPTOR = FEUSB_ERR_READ_STRG_DESCRIPTOR;

				/** Error (-1170): device has to much interfaces
				*/
				static const int MAX_INTERFACES = FEUSB_ERR_MAX_INTERFACES;
				/** Error (-1171): device has to much endpoints
				*/
				static const int MAX_ENDPOINTS = FEUSB_ERR_MAX_ENDPOINTS;
				/** Error (-1172): device has to much strings
				*/
				static const int MAX_STRINGS = FEUSB_ERR_MAX_STRINGS;

				// communication errors (part2)
				/** Error (-1180): control transfer error
				*/
				static const int CONTROL_TRANSFER = FEUSB_ERR_CONTROL_TRANSFER;
			};
		#endif

		#if !defined(_FEDM_NO_TCP_SUPPORT)
			/** %Error codes from communication library FETCP for Transmission Control Protocol
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FETCP
			{
			public:
				// common errors
				/** Error (-1200): error while creating new socket object
				*/
				static const int NEW_SOCKET_FAILURE = FETCP_ERR_NEWSOCKET_FAILURE;
				/** Error (-1201): empty socket list
				*/
				static const int EMPTY_LIST = FETCP_ERR_EMPTY_LIST;
				/** Error (-1202): pointer is NULL
				*/
				static const int POINTER_IS_NULL = FETCP_ERR_POINTER_IS_NULL;
				/** Error (-1203): no more memory
				*/
				static const int NO_MEMORY = FETCP_ERR_NO_MEMORY;
				/** Error (-1205): server not found
				*/
				static const int SERVER_NOT_FOUND = FETCP_ERR_SERVER_NOT_FOUND;

				// error while connect/disconnect the server
				/** Error (-1211): socket open timeout
				*/
				static const int NO_CONNECTION = FETCP_ERR_NO_CONNECTION;
				/** Error (-1212): socket number is false
				*/
				static const int SERVER_ADDRESS = FETCP_ERR_SERVER_ADDR;
				/** Error (-1213): error while closing the socket
				*/
				static const int CLOSE_CONNECTION = FETCP_ERR_CLOSE_CONNECTION;

				// handle errors
				/** Error (-1220): unknown socket handle
				*/
				static const int UNKNOWN_HANDLE = FETCP_ERR_UNKNOWN_HND;
				/** Error (-1221): socket handle is zero
				*/
				static const int HANDLE_IS_NULL = FETCP_ERR_HND_IS_NULL;
				/** Error (-1222): socket handle is negativ
				*/
				static const int HANDLE_IS_NEGATIVE = FETCP_ERR_HND_IS_NEGATIVE;
				/** Error (-1223): no socket handle found
				*/
				static const int NO_HANDLE_FOUND = FETCP_ERR_NO_HND_FOUND;

				// communication errors
				/** Error (-1230): receive timeout
				*/
				static const int TIMEOUT = FETCP_ERR_TIMEOUT;
				/** Error (-1232): error in read process
				*/
				static const int RECEIVE_PROCESS = FETCP_ERR_RECEIVE_PROCESS;
				/** Error (-1236): error in change socket parameter
				*/
				static const int CHANGE_SOCKET_PARA = FETCP_ERR_CHANGE_SOCKET_PARA;
				/** Error (-1237): error in transmit process
				*/
				static const int TRANSMIT_PROCESS = FETCP_ERR_TRANSMIT_PROCESS;
				/** Error (-1238): error while reading the connection state
				*/
				static const int GET_CONNECTION_STATE = FETCP_ERR_GET_CONNECTION_STATE;

				// parameter errors
				/** Error (-1250): unknown parameter
				*/
				static const int UNKNOWN_PARAMETER = FETCP_ERR_UNKNOWN_PARAMETER;
				/** Error (-1251): parameter out of range
				*/
				static const int PARAMETER_OUT_OF_RANGE = FETCP_ERR_PARAMETER_OUT_OF_RANGE;
				/** Error (-1252): odd parameter string
				*/
				static const int ODD_PARAMETER_STRING = FETCP_ERR_ODD_PARAMETERSTRING;
				/** Error (-1254): unknown error code
				*/
				static const int UNKNOWN_ERRORCODE = FETCP_ERR_UNKNOWN_ERRORCODE;

				// communication data flow errors
				/** Error (-1270): Receive Buffer too small
				*/
				static const int BUFFER_OVERFLOW = FETCP_ERR_BUFFER_OVERFLOW;
			};
		#endif

			/** %Error codes from the protocol layer library FEISC
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FEISC
			{
			public:
				// common errors
				/** Error (-4000): error while creating new reader object
				*/
				static const int NEW_READER_FAILURE = FEISC_ERR_NEWREADER_FAILURE;
				/** Error (-4001): empty reader list
				*/
				static const int EMPTY_LIST = FEISC_ERR_EMPTY_LIST;
				/** Error (-4002): an internal pointer is NULL
				*/
				static const int POINTER_IS_NULL = FEISC_ERR_POINTER_IS_NULL;
				/** Error (-4003): no more memory
				*/
				static const int NO_MEMORY = FEISC_ERR_NO_MORE_MEM;
				/** Error (-4004): unknown communication mode
				*/
				static const int UNKNOWN_COMM_PORT = FEISC_ERR_UNKNOWN_COMM_PORT;
				/** Error (-4005): unsupported function
				*/
				static const int UNSUPPORTED_FUNCTION = FEISC_ERR_UNSUPPORTED_FUNCTION;
				/** Error (-4006): this operating system supports not USB
				*/
				static const int NO_USB_SUPPORT = FEISC_ERR_NO_USB_SUPPORT;
				/** Error (-4007): old version of FECOM library detectet
				*/
				static const int OLD_FECOM = FEISC_ERR_OLD_FECOM;

				// query errors
				/** Error (-4010): no value found
				*/
				static const int NO_VALUE = FEISC_ERR_NO_VALUE;

				// handle errors
				/** Error (-4020): unknown reader handle
				*/
				static const int UNKNOWN_HANDLE = FEISC_ERR_UNKNOWN_HND;
				/** Error (-4021): reader handle is zero
				*/
				static const int HANDLE_IS_NULL = FEISC_ERR_HND_IS_NULL;
				/** Error (-4022): reader handle is negative
				*/
				static const int HANDLE_IS_NEGATIVE = FEISC_ERR_HND_IS_NEGATIVE;
				/** Error (-4023): no reader handle found
				*/
				static const int NO_HANDLE_FOUND = FEISC_ERR_NO_HND_FOUND;
				/** Error (-4024): port handle is negative
				*/
				static const int PORT_HANDLE_IS_NEGATIVE = FEISC_ERR_PORTHND_IS_NEGATIVE;
				/** Error (-4025): invalid reader handle
				*/
				static const int HANDLE_INVALID = FEISC_ERR_HND_UNVALID;

				// communication errors
				/** Error (-4030): protocol length error
				*/
				static const int PROTOCOL_LENGTH = FEISC_ERR_PROTLEN;
				/** Error (-4031): checksum error
				*/
				static const int CHECKSUM = FEISC_ERR_CHECKSUM;
				/** Error (-4032): busy timeout
				*/
				static const int BUSY_TIMEOUT = FEISC_ERR_BUSY_TIMEOUT;
				/** Error (-4033): unknown status byte
				*/
				static const int UNKNOWN_STATUS = FEISC_ERR_UNKNOWN_STATUS;
				/** Error (-4034): no USB receive protocol
				*/
				static const int NO_RECEIVE_PROTOCOL = FEISC_ERR_NO_RECPROTOCOL;
				/** Error (-4035): false command byte in receive protocol
				*/
				static const int FALSE_COMMAND_BYTE = FEISC_ERR_CMD_BYTE;
				/** Error (-4036): error in USB protocol transaction
				*/
				static const int TRANSCEIVE = FEISC_ERR_TRANSCEIVE;
				/** Error (-4037): false bus address in receive protocol
				*/
				static const int FALSE_BUS_ADDRESS = FEISC_ERR_REC_BUS_ADR;
				/** Error (-4038): Reader is in power save mode
				*/
				static const int READER_POWER_DOWN = FEISC_ERR_READER_POWER_DOWN;

				// parameter errors
				/** Error (-4050): unknown parameter
				*/
				static const int UNKNOWN_PARAMETER = FEISC_ERR_UNKNOWN_PARAMETER;
				/** Error (-4051): parameter out of range
				*/
				static const int PARAMETER_OUT_OF_RANGE = FEISC_ERR_PARAMETER_OUT_OF_RANGE;
				/** Error (-4052): odd parameterstring
				*/
				static const int ODD_PARAMETER_STRING = FEISC_ERR_ODD_PARAMETERSTRING;
				/** Error (-4053): unknown error code
				*/
				static const int UNKNOWN_ERROR_CODE = FEISC_ERR_UNKNOWN_ERRORCODE;
				/** Error (-4054): unsupported option
				*/
				static const int UNSUPPORTED_OPTION = FEISC_ERR_UNSUPPORTED_OPTION;
				/** Error (-4055): Unknown EPC type
				*/
				static const int UNKNOWN_EPC_TYPE = FEISC_ERR_UNKNOWN_EPC_TYPE;
				/** Error (-4056): parameter is locked
				*/
				static const int PARAMETER_LOCKED = FEISC_ERR_PARAMETER_LOCKED;

				// plug-in errors
				/** Error (-4060): no plug-in module installed
				*/
				static const int NO_PLUGIN = FEISC_ERR_NO_PLUGIN;
				/** Error (-4061): plug-in module already installed
				*/
				static const int PLUGIN_PRESENT = FEISC_ERR_PLUGIN_PRESENT;
				/** Error (-4062): unknown plug-in identifier
				*/
				static const int UNKNOWN_PLUGIN_ID = FEISC_ERR_UNKNOWN_PLUGIN_ID;
				/** Error (-4063): error while building data stream
				*/
				static const int PLUGIN_BUILD_DATA = FEISC_ERR_PI_BUILD_DATA;
				/** Error (-4064): error while building protocol frame
				*/
				static const int PLUGIN_BUILD_FRAME = FEISC_ERR_PI_BUILD_FRAME;
				/** Error (-4065): error while split the protocol frame
				*/
				static const int PLUGIN_SPLIT_FRAME = FEISC_ERR_PI_SPLIT_FRAME;
				/** Error (-4066): error while extracting the protocol data
				*/
				static const int PLUGIN_SPLIT_DATA = FEISC_ERR_PI_SPLIT_DATA;
				/** Error (-4067): error while getting Plug-in
				*/
				static const int PLUGIN_GET = FEISC_ERR_PI_GET;
				/** Error (-4068): error while load Plug-in library
				*/
				static const int PLUGIN_LOAD = FEISC_ERR_PI_LOAD;
				/** Error (-4069): error while release Plug-in
				*/
				static const int PLUGIN_RELEASE = FEISC_ERR_PI_RELEASE;

				// communication data flow errors
				/** Error (-4070): receive buffer overflow
				*/
				static const int BUFFER_OVERFLOW = FEISC_ERR_BUFFER_OVERFLOW;

				// task errors
				/** Error (-4080): asynchronous task is still running
				*/
				static const int TASK_STILL_RUNNING = FEISC_ERR_TASK_STILL_RUNNING;
				/** Error (-4081): asynchronous task not started
				*/
				static const int TASK_NOT_STARTED = FEISC_ERR_TASK_NOT_STARTED;
				/** Error (-4082): asynchronous task finished with timeout. Reader has sent no reply
				*/
				static const int TASK_TIMEOUT = FEISC_ERR_TASK_TIMEOUT;
				/** Error (-4083): error while initializing a socket for asynchronous task
				*/
				static const int TASK_SOCKET_INIT = FEISC_ERR_TASK_SOCKET_INIT;
				/** Error (-4084): asynchronous task is busy
				*/
				static const int TASK_BUSY = FEISC_ERR_TASK_BUSY;
				/** Error (-4085): error in cancelling of asynchronous task
				*/
				static const int THREAD_CANCEL_ERROR = FEISC_ERR_THREAD_CANCEL_ERROR;
				/** Error (-4086): Port Number is already in use
				*/
				static const int TASK_PORT_ALREADY_IN_USE = FEISC_ERR_TASK_PORT_ALREADY_IN_USE;

				// errors from cryptography module
				/** Error (-4090): error while loading crypto-module
				*/
				static const int CRYPT_LOAD_LIBRARY = FEISC_ERR_CRYPT_LOAD_LIBRARY;
				/** Error (-4091): error while crypto initialization
				*/
				static const int CRYPT_INIT = FEISC_ERR_CRYPT_INIT;
				/** Error (-4092): error in authentication process
				*/
				static const int CRYPT_AUTHENT_PROCESS = FEISC_ERR_CRYPT_AUTHENT_PROCESS;
				/** Error (-4093): error in encipher process
				*/
				static const int CRYPT_ENCYPHER = FEISC_ERR_CRYPT_ENCYPHER;
				/** Error (-4094): error in decipher process
				*/
				static const int CRYPT_DECYPHER = FEISC_ERR_CRYPT_DECYPHER;
			};

		#if !defined(_FEDM_NO_FU_SUPPORT)
			/** %Error codes from Function UNit library
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FEFU
			{
			public:
				// common errors
				/** Error (-4102): an internal pointer is NULL
				*/
				static const int POINTER_IS_NULL = FEFU_ERR_POINTER_IS_NULL;
				/** Error (-4103): no more memory
				*/
				static const int NO_MEMORY = FEFU_ERR_NO_MORE_MEM;
				/** Error (-4105): unsupported function
				*/
				static const int UNSUPPORTED_FUNCTION = FEFU_ERR_UNSUPPORTED_FUNCTION;

				// communication errors
				/** Error (-4130): protocol length error
				*/
				static const int PROTOCOL_LENGTH = FEFU_ERR_PROTLEN;
				/** Error (-4131): checksum error
				*/
				static const int CHECKSUM = FEFU_ERR_CHECKSUM;
				/** Error (-4132): Timeout
				*/
				static const int TIMEOUT = FEFU_ERR_TIMEOUT;
				/** Error (-4133): unknown status
				*/
				static const int UNKNOWN_STATUS = FEFU_ERR_UNKNOWN_STATUS;
				/** Error (-4134): no receive protocol
				*/
				static const int NO_RECEIVE_DATA = FEFU_ERR_NO_RECDATA;

				// parameter errors
				/** Error (-4150): unknown parameter
				*/
				static const int UNKNOWN_PARAMETER = FEFU_ERR_UNKNOWN_PARAMETER;
				/** Error (-4151): parameter out of range
				*/
				static const int PARAMETER_OUT_OF_RANGE = FEFU_ERR_PARAMETER_OUT_OF_RANGE;
				/** Error (-4153): unknown error code
				*/
				static const int UNKNOWN_ERROR_CODE = FEFU_ERR_UNKNOWN_ERRORCODE;
			};
		#endif

		#if !defined(_FEDM_NO_TAG_HANDLER) && !defined(_FEDM_NO_TAG_HANDLER_ISO14443)
			/** %Error Codes from T=CL library for ISO 14443 APDU handling
			*/
			class _FEDM_ISC_CORE_EXT_CLASS FETCL
			{
			public:
				// common errors
				/** Error (-4200): error during transponder object creation
				*/
				static const int NEW_TRANSPONDER_FAILURE = FETCL_ERR_NEW_TRANSPONDER_FAILURE;
				/** Error (-4201): Empty transponder list
				*/
				static const int EMPTY_LIST = FETCL_ERR_EMPTY_LIST;
				/** Error (-4202): Internal NULL Pointer
				*/
				static const int POINTER_IS_NULL = FETCL_ERR_POINTER_IS_NULL;
				/** Error (-4203): Not enough memory
				*/
				static const int NO_MEMORY = FETCL_ERR_NO_MORE_MEM;
				/** Error (-4204): Unknown communication port
				*/
				static const int UNKNOWN_COMM_PORT = FETCL_ERR_UNKNOWN_COMM_PORT;
				/** Error (-4205): Function is not supported
				*/
				static const int UNSUPPORTED_FUNCTION = FETCL_ERR_UNSUPPORTED_FUNCTION;
				/** Error (-4206): USB is not supported
				*/
				static const int NO_USB_SUPPORT = FETCL_ERR_NO_USB_SUPPORT;
				/** Error (-4207): Outdated version of FECOM library detected
				*/
				static const int OLD_FECOM = FETCL_ERR_OLD_FECOM;
				/** Error (-4208): File open error
				*/
				static const int OPEN_FILE = FETCL_ERR_FILE_COULD_NOT_BE_OPENED;
				/** Error (-4209): Another APDU is currently being processed
				*/
				static const int APDU_CURRENTLY_RUNNING = FETCL_ERR_APDU_CURRENTLY_RUNNING;

				// query errors
				/** Error (-4210): No value found
				*/
				static const int NO_VALUE = FETCL_ERR_NO_VALUE;

				// handle errors
				/** Error (-4220): Unknown handle
				*/
				static const int UNKNOWN_HANDLE = FETCL_ERR_UNKNOWN_HND;
				/** Error (-4221): The handle is zero
				*/
				static const int HANDLE_IS_NULL = FETCL_ERR_HND_IS_NULL;
				/** Error (-4222): Negative handle
				*/
				static const int HANDLE_IS_NEGATIVE = FETCL_ERR_HND_IS_NEGATIVE;
				/** Error (-4223): Handle not found
				*/
				static const int NO_HANDLE_FOUND = FETCL_ERR_NO_HND_FOUND;
				/** Error (-4224): Negative transponder handle
				*/
				static const int TRANSPONDER_HANDLE_IS_NEGATIVE = FETCL_ERR_TRANSPONDER_HND_IS_NEGATIVE;
				/** Error (-4225): Handle is invalid
				*/
				static const int HANDLE_INVALID = FETCL_ERR_HND_UNVALID;
				/** Error (-4226): Negative reader handle
				*/
				static const int READER_HANDLE_IS_NEGATIVE = FETCL_ERR_READER_HND_IS_NEGATIVE;
				/** Error (-4227): Thread not created
				*/
				static const int THREAD_NOT_CREATED = FETCL_ERR_THREAD_NOT_CREATED;

				// parameter errors
				/** Error (-4250): Unknown parameter
				*/
				static const int UNKNOWN_PARAMETER = FETCL_ERR_UNKNOWN_PARAMETER;
				/** Error (-4251): Parameter out of range
				*/
				static const int PARAMETER_OUT_OF_RANGE = FETCL_ERR_PARAMETER_OUT_OF_RANGE;
				/** Error (-4252): Odd parameter string
				*/
				static const int ODD_PARAMETER_STRING = FETCL_ERR_ODD_PARAMETERSTRING;
				/** Error (-4253): Unknown error code. Error code is not defined
				*/
				static const int UNKNOWN_ERROR_CODE = FETCL_ERR_UNKNOWN_ERRORCODE;
				/** Error (-4257): Undersized Response Buffer
				*/
				static const int UNDERSIZED_RESPONSE_BUFFER = FETCL_ERR_UNDERSIZED_RESPONSE_BUFFER;

				// communication data flow errors
				/** Error (-4270): Receive buffer overflow
				*/
				static const int BUFFER_OVERFLOW = FETCL_ERR_BUFFER_OVERFLOW;
				/** Error (-4271): Response length to large
				*/
				static const int OVERSIZED_RESPONSE = FETCL_ERR_OVERSIZED_RESPONSE;
				/** Error (-4272): Invalid acknowledgement
				*/
				static const int INVALID_ACKNOWLEDGEMENT = FETCL_INVALID_ACKNOWLEDGEMENT;
				/** Error (-4273): Invalid acknowledgement length
				*/
				static const int INVALID_ACKNOWLEDGEMENT_LENGTH = FETCL_INVALID_ACKNOWLEDGEMENT_LENGTH;
				/** Error (-4274): Response list not complete
				*/
				static const int LIST_COMPLETE_FAILURE = FETCL_LIST_COMPLETE_FAILURE;
				/** Error (-4275): Response not complete
				*/
				static const int INCOMPLETE_RESPONSE = FETCL_INCOMPLETE_RESPONSE;
				/** Error (-4276): Invalid protocol
				*/
				static const int INVALID_PROTOCOL = FETCL_INVALID_PROTOCOL;
				/** Error (-4277): Invalid transmission
				*/
				static const int INVALID_TRANSMISSION = FETCL_INVALID_TRANSMISSION;
				/** Error (-4280): APDU canceled by user
				*/
				static const int USER_ABORT = FETCL_USER_ABORT;
			};
		#endif
		};
	}
}

#endif // _FEDM_CORE_ERROR_H_INCLUDED_
