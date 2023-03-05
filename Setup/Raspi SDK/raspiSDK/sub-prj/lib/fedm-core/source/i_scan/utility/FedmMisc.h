/*-------------------------------------------------------
|                                                       |
|				FedmMisc.h                              |
|                                                       |
---------------------------------------------------------

Copyright © 2009-2015	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	A. Bierschenk
Begin        		:	08.05.2018


Operation Systems	:	independent

Function			:	Misc's


Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/

#if !defined(_FEDM_MISC_H_INCLUDED_)
#define _FEDM_MISC_H_INCLUDED_


#include <string>
#include <vector>
#include "../../FEDM.h"



class _FEDM_ISC_CORE_EXT_CLASS FedmMisc
{
public:
	static bool        HexStringToBinArray(const std::string & str, std::vector<unsigned char> & ary);
	static std::string BinArrayToHexString(const std::vector<unsigned char> & ary);
};


#endif // _FEDM_MISC_H_INCLUDED_
