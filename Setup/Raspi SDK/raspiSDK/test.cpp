#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ID_ISC.SDK.Raspi-V5.6.0\sub-prj\lib\feusb\include\feusb.h"
#include "ID_ISC.SDK.Raspi-V5.6.0\sub-prj\lib\fedm-core\include\FedmIscCore.h"
#include "ID_ISC.SDK.Raspi-V5.6.0\sub-prj\lib\fedm-core-api\include\FedmIscCoreApi.h"




int main()
{
    // get reader name
    FEDM::Core::Const::ReaderType::GetReaderName(FEDM::Core::Const::ReaderType::ID_ISC_LRU1002);
    
    // create reader object
    FEDM::Core::ReaderModule reader;

    // store reader name
    reader.SetReaderHandle(FEDM::Core::Const::ReaderType::ID_ISC_LRU1002);
    // print reader name
    std::cout << reader.GetReaderHandle() << std::endl;


    // initialize tag handler
    FEDM::Core::TagHandler::TH_Base;


    
    
 
    // Create a structure to hold the RFID tag data
    struct RFIDTagData
    {
        unsigned char buffer[32];
        int length;
    };
        
    
    return 0;
}
