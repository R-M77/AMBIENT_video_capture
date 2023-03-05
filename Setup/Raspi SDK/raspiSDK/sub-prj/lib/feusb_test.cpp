#include "C:\Users\User\Desktop\UHN_RFID\Setup\Raspi SDK\ID_ISC.SDK.Raspi-V5.6.0\sub-prj\lib\feusb\include\feusb.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


int main()
{
    char cDeviceID[16];
    long nDeviceID;
    FEUSB_SCANSEARCH search;

    // Set search options
    
    search.iMask = FEUSB_SCAN_ALL;
    strcpy(search.cDeviceName, "ID ISC.LRU1002-FCC");

    if( FEUSB_Scan(FEUSB_SCAN_FIRST, &search) == 0)
    {
        if( FEUSB_GetScanListPara( 0, "Device-ID", cDeviceID ) == 0 )
            {
            sscanf((const char*)cDeviceID, "%lx", &nDeviceID);
            int iDevHnd = FEUSB_OpenDevice( nDeviceID );
            if( iDevHnd < 0 )
                {
                // Code here for error
                std::cout << "Error" << std::endl;
                }
            else
                {
                // Code here for communication or other
                std::cout << "Success" << std::endl;
                }
            }
    }

    return 0;
}