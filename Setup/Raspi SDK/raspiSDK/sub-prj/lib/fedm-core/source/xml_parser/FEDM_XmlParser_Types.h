/*-------------------------------------------------------
|                                                       |
|	FEDM_XmlParser_Types.h								|
|                                                       |
---------------------------------------------------------

Copyright © 2008-2017	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : identification-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Markus Hultsch

Begin        		:	23.01.2008

Version       		:	08.00.00 / 23.10.2017 / M. Hultsch
						- extensions for XML document version 2.0

						07.00.02 / 25.04.2013 / M. Hultsch
						- support for new controller type: ext. Smartcard-Reader

Operation Systems	:	independent


This file contains special data types for XML Parser

OBID® and OBID i-scan® are registered Trademarks of FEIG ELECTRONIC GmbH.
Linux® is a registered trademark of Linus Torvalds.
Microsoft® and Windows® are registered trademarks of Microsoft Corporation.
*/


#ifndef _FEDM_TYPES_INCLUDE_H
#define _FEDM_TYPES_INCLUDE_H


#ifdef _MSC_VER
	// The (microsoft) debugger can't handle symbols more than 255 characters long.
	// STL often creates symbols longer than that.
	// When symbols are longer than 255 characters, the warning is disabled.
	#pragma warning(disable:4786)	// for MFC
#endif


#include <string>
#include <vector>
#include <map>
#include "FedmIscCore.h"


// STL - Standard Template Library
using namespace std;




// forward declarations
struct _FEDM_XML_HEADER;



//#######################################################################################
// structure for XML Header
//#######################################################################################
typedef struct _FEDM_XML_HEADER
{
	unsigned int	uiMinToolVersion;				// 01020304 : V1.02.03.04 - new with v8.0.0 / 23.10.2017 / mhu (v2.0 of XML document)
	unsigned int	uiDocVersion;					// 01020304 : V1.02.03.04
	unsigned int	uiFedmCoreVersion;				// 01020304 : V1.02.03.04
	unsigned int	uiFedmServiceVersion;			// 01020304 : V1.02.03.04 - new with v8.0.0 / 23.10.2017 / mhu (v2.0 of XML document)
	unsigned int	uiCrc;
	char			szDocType[FEDM_MAX_NAME_SIZE];
	char			szVendor[FEDM_MAX_NAME_SIZE];
	char			szDate[FEDM_MAX_NAME_SIZE];
	char			szTime[FEDM_MAX_NAME_SIZE];
	char			szComment[FEDM_MAX_TEXT_SIZE];
	
	void Init()
	{
		uiMinToolVersion		= 0;
		uiDocVersion			= 0;
		uiFedmCoreVersion		= 0;
		uiFedmServiceVersion	= 0;
		uiCrc			= 0;
		memset(szDocType,	0, FEDM_MAX_NAME_SIZE);
		memset(szVendor,	0, FEDM_MAX_NAME_SIZE);
		memset(szDate,		0, FEDM_MAX_NAME_SIZE);
		memset(szTime,		0, FEDM_MAX_NAME_SIZE);
		memset(szComment,	0, FEDM_MAX_TEXT_SIZE);
		return;
	}

} FEDM_XML_HEADER;

typedef struct _FEDM_XML_READER_REQUIREMENT
{
	// reader specification attributes
	bool bHasDevID;
	bool bHasCustID;
	bool bHasRdrFunc;
	bool bHasTrpDrv;
	bool bHasRegion;
	bool bHasPortType;
	bool bHasCustomizedFw;
	bool bHasFpgaFw;
	bool bHasRfcFw;
	bool bHasAccFw;
	bool bHasBlFw;
	bool bHasKbFw;
	bool bHasMlcEmpsFw;
	bool bHasScrFw;			// new since V07.00.02 / 25.04.2013 M. Hultsch
	bool bHasWlanFw;		// new since V07.01.02 / 28.04.2014 B. Tschunko
	bool bHasBcFw;			// new since V08.09.00 / 26.11.2020 M. Hultsch
	bool bHasOptional;
	bool bHasReaderRevisions;
	bool bHasReaderAssemblies;

	unsigned int	uiReaderType;
	unsigned int	uiDeviceID;
	unsigned int	uiCumstomerID;
	unsigned int	uiReaderFunction;
	unsigned int	uiTransponderDriver;
	unsigned int	uiRegion;	// 1: EU; 2: FCC
	unsigned int	uiPortType;	// up to doc-version 1.2: 0: Serial; 1: USB; 2: TCP; 3: Bluetooth
								// since doc-version 1.3: bit field according [0x66] Reader Info, Mode 0x10, byte PORT_TYPE
								// each bit has a define in FEDM_FwUpd.h
	
	string			sFirmwareIdentifier;

	string			sReaderName;

	map<unsigned int, unsigned int>	mapMinControllerFW;
	vector<string> aOptional;
	vector<unsigned char> aReaderRevisions;		// new with v8.0.0 / 23.10.2017 / mhu (v2.0 of XML document)
	vector<unsigned char> aReaderAssemblies;	// new with v8.0.0 / 23.10.2017 / mhu (v2.0 of XML document)

	// constructor
	_FEDM_XML_READER_REQUIREMENT() :	bHasDevID(false),
										bHasCustID(false),
										bHasRdrFunc(false),
										bHasTrpDrv(false),
										bHasRegion(false),
										bHasPortType(false),
										bHasCustomizedFw(false),
										bHasFpgaFw(false),
										bHasRfcFw(false),
										bHasAccFw(false),
										bHasBlFw(false),
										bHasKbFw(false),
										bHasMlcEmpsFw(false),
										bHasScrFw(false),
										bHasWlanFw(false),
										bHasBcFw(false),
										bHasOptional(false),
										bHasReaderRevisions(false),
										bHasReaderAssemblies(false),
										uiReaderType(0),
										uiDeviceID(0),
										uiCumstomerID(0),
										uiReaderFunction(0),
										uiTransponderDriver(0),
										uiRegion(0),
										uiPortType(0)
										{}

	void Init()
	{
		bHasDevID			= false;
		bHasCustID			= false;
		bHasRdrFunc			= false;
		bHasTrpDrv			= false;
		bHasRegion			= false;
		bHasPortType		= false;
		bHasCustomizedFw	= false;
		bHasFpgaFw			= false;
		bHasRfcFw			= false;
		bHasAccFw			= false;
		bHasBlFw			= false;
		bHasKbFw			= false;
		bHasMlcEmpsFw		= false;
		bHasScrFw			= false;
		bHasWlanFw			= false;
		bHasBcFw			= false;
		bHasOptional		= false;
		bHasReaderRevisions	= false;
		bHasReaderAssemblies= false;
		uiReaderType		= 0;
		uiDeviceID			= 0;
		uiCumstomerID		= 0;
		uiReaderFunction	= 0;
		uiTransponderDriver	= 0;
		uiRegion			= 0;
		uiPortType			= 0;

#if _MSC_VER > 1200
		sFirmwareIdentifier.clear();
		sReaderName.clear();
#else
		sFirmwareIdentifier.erase(sFirmwareIdentifier.begin(), sFirmwareIdentifier.end());
		sReaderName.erase(sReaderName.begin(), sReaderName.end());
#endif

		mapMinControllerFW.erase(mapMinControllerFW.begin(), mapMinControllerFW.end());
		aOptional.erase(aOptional.begin(), aOptional.end());
		aReaderRevisions.erase(aReaderRevisions.begin(), aReaderRevisions.end());
		aReaderAssemblies.erase(aReaderAssemblies.begin(), aReaderAssemblies.end());
		
		return;
	}

} FEDM_XML_READER_REQUIREMENT;

#endif // #ifndef _FEDM_TYPES_INCLUDE_H
