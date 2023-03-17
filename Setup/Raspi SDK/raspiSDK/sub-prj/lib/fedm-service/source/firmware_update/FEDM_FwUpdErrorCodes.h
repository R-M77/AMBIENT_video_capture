/**
*
* \author FEIG ELECTRONIC GmbH
*
* Copyright (C) FEIG ELECTRONIC GmbH. All rights reserved. Do not disclose.
*
* This software is the confidential and proprietary information of
* FEIG ELECTRONIC GmbH ("Confidential Information"). You shall not
* disclose such Confidential Information and shall use it only in
* accordance with the terms of the license agreement you entered
* into with FEIG ELECTRONIC GmbH.
*/

#if !defined(_FEDM_FWUPD_ERROR_CODES_H_INCLUDED_)
#define _FEDM_FWUPD_ERROR_CODES_H_INCLUDED_

// error codes
#define FEDM_ERROR_FW_UPD_CHECKSUM						-400
#define FEDM_ERROR_FW_UPD_WRONG_CONTROLLER_TYPE			-401
#define FEDM_ERROR_FW_UPD_UNSUPPORTED_CONTROLLER_TYPE	-402
#define FEDM_ERROR_FW_UPD_FILE_DEFECT					-403
#define FEDM_ERROR_FW_UPD_BLOCKSIZE_RANGE				-404
#define FEDM_ERROR_FW_UPD_THREAD_START					-405
#define FEDM_ERROR_FW_UPD_READER_INFO_INCOMPLETE		-406
#define FEDM_ERROR_FW_UPD_FIRMWARE_REQUIREMENT			-407
#define FEDM_ERROR_FW_UPD_DEVICE_REQUIREMENT			-408
#define FEDM_ERROR_FW_UPD_SILICON_REQUIREMENT			-409
#define FEDM_ERROR_FW_UPD_ACTIVATION					-410
#define FEDM_ERROR_FW_UPD_UPLOAD						-411
#define FEDM_ERROR_FW_UPD_DELETE_FLASH					-412
#define FEDM_ERROR_FW_UPD_WRITE_FLASH					-413
#define FEDM_ERROR_FW_UPD_OBSERVE_DELETE_FLASH			-414
#define FEDM_ERROR_FW_UPD_OBSERVE_WRITE_FLASH			-415
#define FEDM_ERROR_FW_UPD_RESET_TARGET					-416
#define FEDM_ERROR_FW_UPD_CANCELED_BY_USER				-417
#define FEDM_ERROR_FW_UPD_UNSUPPORTED_PORT_TYPE			-418
#define FEDM_ERROR_FW_UPD_RECONNECT_TARGET				-419
#define FEDM_ERROR_FW_UPD_REENUMERATE_TARGET			-420
#define FEDM_ERROR_FW_UPD_FILE_NOT_FOUND				-421
#define FEDM_ERROR_FW_UPD_FILE_INCOMPLETE				-422
#define FEDM_ERROR_FW_UPD_PARTITION_NO_MISSING			-423
#define FEDM_ERROR_FW_UPD_DOUBLE_PARTITION				-424
#define FEDM_ERROR_FW_UPD_MULTIPLE_BANKS_UNSUPPORTED	-425
#define FEDM_ERROR_FW_UPD_LRU3000_CHANGE_VERSION		-426
#define FEDM_ERROR_FW_UPD_FILE_NOT_SUPPORTED			-427
#define FEDM_ERROR_FW_UPD_TOOL_VERSION_MISMATCH			-428

#endif // !defined(_FEDM_FWUPD_ERROR_CODES_H_INCLUDED_)