/*-------------------------------------------------------
|                                                       |
|			FedmIscLedController.h						|
|                                                       |
---------------------------------------------------------

Copyright © 2010	FEIG ELECTRONIC GmbH, All Rights Reserved.
						Lange Strasse 4
						D-35781 Weilburg
						Federal Republic of Germany
						phone    : +49 6471 31090
						fax      : +49 6471 310999
						e-mail   : obid-support@feig.de
						Internet : http://www.feig.de
					
Author         		:	Axel Bierschenk
Begin        		:	21.10.2016

Version       		:	03.02.00 / 21.10.2016 / A. Bierschenk

Operation Systems	:	independent

Function			:	this class supports the peripheral device called LED controller


Trademarks:
-----------
OBID®, OBID i-scan® and OBID myAXXESS® are registered Trademarks of FEIG ELECTRONIC GmbH
Other Trademarks: see FEDM.h
*/


#if !defined(_FEDM_ISC_LED_CONTROLLER_H_INCLUDED_)
#define _FEDM_ISC_LED_CONTROLLER_H_INCLUDED_

#if !defined(_FEDM_NO_PD_SUPPORT)

#include "FedmIscPeripheralDevice.h"

//#####################################################################################
// type definitions
//#####################################################################################


//#####################################################################################
// constants
//#####################################################################################


//####################################################################
// class FedmIscPeopleCounter
//####################################################################

class _FEDM_ISC_CORE_EXT_CLASS FedmIscLedController : public FedmIscPeripheralDevice
{
public:
	// constructor
	FedmIscLedController(FEDM_ISCReader* pReader, unsigned char ucBusAdr);
	// destructor
	virtual ~FedmIscLedController();

	//main access functions
	FEDM_ISC_PERIPHERAL_DEVICE_INFO* ReadInfo();
	void BuildInfoReport(string& sReport);
	FEDM_ISC_PERIPHERAL_DEVICE_DIAGNOSTIC *ReadDiagnostic(void);
	void BuildDiagnosticReport(string& sReport);
	int SetOutput(FEISC_GPC_OUTPUT *pOutput);

protected:

};

#endif // #if !defined(_FEDM_NO_PD_SUPPORT)

#endif // !defined(_FEDM_ISC_LED_CONTROLLER_H_INCLUDED_)
