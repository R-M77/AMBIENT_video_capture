/*-------------------------------------------------------
|                                                       |
|	FEDM_XmlParser_Base.h				                |
|                                                       |
---------------------------------------------------------

Copyright © 2008		FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : identification-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Markus Hultsch
Begin        		:	23.01.2008
Version       		:	03.00.00 / 06.02.2008 / M. Hultsch
Operation Systems	:	independent
Function			:	abstract class for basic parser API

OBID® and OBID i-scan® are registered Trademarks of FEIG ELECTRONIC GmbH.
Linux® is a registered trademark of Linus Torvalds.
Microsoft® and Windows® are registered trademarks of Microsoft Corporation.
*/


//###########################
//      D E F I N E S
//###########################
#ifndef FEDM_XMLPARSER_BASE_H
#define FEDM_XMLPARSER_BASE_H


//#############################
//      I N C L U D E S
//#############################
#include "FedmIscCore.h"
#include "FEDM_XmlParser_Types.h"	// public include file of library

class FEDM_XmlParser_Reader;
class FEDM_XmlParser_Writer;

#define FEDM_CRC16_PRESET		0xFEDB
#define FEDM_CRC16_POLYNOM		0x8408	// x^16 + x^12 + x^5 + 1

#define FEDM_XML_PARSER_TYPE_FEDM	1
#define FEDM_XML_PARSER_TYPE_TINY	2


//#######################################################################################
//	class FEDM_XmlParser_Base
//#######################################################################################
class FEDM_XmlParser_Base
{
public:
	FEDM_XmlParser_Base(unsigned int uiReaderType=FEDM_XML_PARSER_TYPE_TINY,
						unsigned int uiWriterType=FEDM_XML_PARSER_TYPE_FEDM);


	FEDM_XmlParser_Base(unsigned int uiDocVersion,
						unsigned int uiReaderType=FEDM_XML_PARSER_TYPE_TINY,
						unsigned int uiWriterType=FEDM_XML_PARSER_TYPE_FEDM);

	virtual ~FEDM_XmlParser_Base(void);

	void SetLastError(int iError)	{ m_iLastError = iError; }
	int  GetLastError()				{ return m_iLastError; }

	bool IsParsed()					{ return m_bIsParsed; }

	void SetWriteMode(bool bMode)	{ m_bWriteMode = bMode; }
	
	void EnableSerializeWithChecksum(bool bWithChecksum);
	void EnableSerializeWithData(bool bWithData);
	void SetRequiredToolVersion(const unsigned int uiRequiredToolVersion)	{ m_uiRequiredToolVersion = uiRequiredToolVersion; }

	// function to detect the document version
	static int IsXmlDocType(const char* szXmlFileName, const char* szRootTag, const char* szDocType, const unsigned int uiReqDocVersion);
	unsigned int GetXmlDocType()	{ return m_uiDocVersion; }

	// main serialization functions
	virtual int SerializeIn(const char* szXmlFileName, const char* szVendor, const char* szOemRootTag, const char* szAccessCode, unsigned int uiAccessCodeLen)=0;
	virtual int SerializeIn(const char* szXmlFileName, const char* szVendor, const char* szOemRootTag, const char* szAccessCode, unsigned int uiAccessCodeLen, bool bWithData)=0;
	virtual int SerializeOut(const char* szXmlFileName, const char* szVendor, const char* szOemRootTag, const char* szAccessCode, unsigned int uiAccessCodeLen)=0;

	// serialization helper functions for file-header
	int SerializeHeaderIn(FEDM_XML_TREEITEM* parent, const char* szVendor="");
	int SerializeHeaderOut(FEDM_XML_TREEITEM* parent, const char* szVendor="");


	// document management
	int OpenDoc(char* sFileName, char* sMode);	// open a xml document
	int CloseDoc();								// close xml document
	int LoadDoc();								// reads the xml text
	int LoadDoc(const char* szOemRootTag);		// reads the xml text
	int WriteDoc();								// write the xml text into file
	wstring WriteStream();						// build and return xml string
	int LoadStream(wstring sXmlStream);			// load xml string

	// ##################################################################################
	// interface for reader class
	// ##################################################################################
	FEDM_XML_TREEITEM* FindTag(	wstring sTag,
								unsigned int uiTagLevel,
								bool bNext=false);

	FEDM_XML_TREEITEM* FindTag(	wstring sTag,
								wstring sAttribute,
								unsigned int uiTagLevel,
								bool bNext=false);

	int	GetTagAttrib(	FEDM_XML_TREEITEM* item,
						int iIndex, 
						string& sAttrib, 
						string& sValue );


	// ##################################################################################
	// interface for writer class
	// ##################################################################################
	void DeleteXmlTree();						// clears temporary tree
	void SetComment(wstring sComment);
	
	// functions to build tree before writing into file
	FEDM_XML_TREEITEM* BuildTag(wstring sTag, bool bNewLine=true, bool bEmpty=false);
	int AddTagValue(FEDM_XML_TREEITEM* item, wstring sValue);
	int AddTagAttrib(FEDM_XML_TREEITEM* item, wstring sAttrib, wstring sValue);
	int AddTagItem(FEDM_XML_TREEITEM* pParent, FEDM_XML_TREEITEM* pChild);

protected:
	virtual unsigned int CalcChecksum()=0;

	unsigned int CalcCRC16CheckSum(	unsigned int uiCrcPreset,
									unsigned int uiData );

	unsigned int CalcCRC16CheckSum(	unsigned int uiCrcPreset,
									unsigned char* ucBuffer, 
									unsigned int uiBufLen );

	int Base64Encode(unsigned char* ucSourcePtr,
					 unsigned char* ucDestPtr,
					 unsigned int	src_len,
					 unsigned int	dst_len_max);

	int Base64Decode(unsigned char* ucSourcePtr,
					 unsigned char* ucDestPtr,
					 unsigned int	src_len,
					 unsigned int	dst_len_max);

	unsigned char Translate64(unsigned char ucInput);

	void Init(unsigned int uiDocVersion, unsigned int uiReaderType, unsigned int uiWriterType);

public:
	FEDM_XML_HEADER	m_XmlHeader;

protected:
	bool m_bIsParsed;
	int	 m_iLastError;			// last error code
	bool m_bWriteMode;
	bool m_bSerializeWithChecksum;
	bool m_bSerializeWithData;

	// access code for calculating a CRC16-checksum
	char			m_szAccessCode[FEDM_MAX_NAME_SIZE];
	unsigned int	m_uiAccessCodeLen;

	unsigned int m_uiDocVersion;
	unsigned int m_uiRequiredToolVersion;

	// helper classes, which implements the parser
	FEDM_XmlParser_Reader* m_pXmlReader;
	FEDM_XmlParser_Writer* m_pXmlWriter;
};

#endif // #ifndef FEDM_XMLPARSER_BASE_H

