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

#if !defined(_FEDM_FWUPD_MODULE_PUBLIC_H_INCLUDED_)
#define _FEDM_FWUPD_MODULE_PUBLIC_H_INCLUDED_

#include <map>
#include "FedmIscCore.h"

class FEDM_FwUpdModule;


/* callback function informs the application with process information
// parameters:	void* pAny			- pointer to anything (passed with StartUpdate)
int iStatus			- OK (=0) or error code (<0)
int iNtfLevel		- notification level
int iCounter		- process counter
int iMaxCount		- limit of process counter
char* pszMessage	- additional message
*/
typedef int(*LPFN_FEDM_FW_UPD_CB)(void*, int, int, int, int, char*);



class _FEDM_SERVICE_EXT_CLASS FedmFwUpdModule
{
public:

	FedmFwUpdModule(FEDM_ISCReaderModule* pReader);
	~FedmFwUpdModule();

	char* GetLibVersion();

	bool UpdateIsRunning();
	bool IsUpdateFailed();

	int StartUpdateSilent(void* pAny, std::string sXmlFwPathname, unsigned int uiLogOption, std::string sLogDir, LPFN_FEDM_FW_UPD_CB cb = NULL);

	static std::string GetErrorTextS(int iErrorCode);

	int VerifyFile(char* pszFileName, FEDM_ISC_READER_INFO* pReaderInfo);
	int GetFileInfo(std::map<std::string, std::string> &Info);


	/** @brief Option-ID for selecting additional options
	*
	* <b>Description</b><br>
	* The update is executed and no logfiles are generated.<br>
	*/
	static const unsigned int LOGGING_OFF = 0x00000100;

	/** @brief Option-ID for selecting additional options
	*
	* <b>Description</b><br>
	* The update is executed and a standard logfile is generated.<br>
	*/
	static const unsigned int LOGGING_STANDARD = 0x00010000;

	/** @brief Option-ID for selecting additional options
	*
	* <b>Description</b><br>
	* The update is executed and an additional logfile with exchanged protocols is generated.<br>
	*/
	static const unsigned int LOGGING_WITH_PROTOCOLS = 0x00020000;

private:

	// pointer to firmware update object
	FEDM_FwUpdModule* m_pFwUpdModule;
};

#endif // !defined(_FEDM_FWUPD_MODULE_PUBLIC_H_INCLUDED_)
