#include <FedmIscCoreApi.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
using namespace FEDM::Core;

ReaderModule reader;


int main()
{
    /*INITIALIZATION*/
    // table size - hm: host mode,  brm: buffer read mode
    reader.IHmTable.SetSize(100);
    // reader.IBrmTable.SetSize(100);

    // set reader type
    reader.SetReaderType(Const::ReaderType::ID_ISC_LRU1002);

    /* Connecttion */
    IPortGroup::SerialPortSetting portSettings(2, 38400, "8E1");

    // usb connection
    reader.IPort.ConnectUSB(0);


    // uncomment if using the old reader module
    // FEDM_ISCReaderModule* oldReader = reader.GetReaderImpl();

    




    return 0;
}