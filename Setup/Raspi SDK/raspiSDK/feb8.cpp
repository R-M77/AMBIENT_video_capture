// import libs
#include <stdio.h>
#include <iostream>
#include <string>
#include <FedmIscCoreApi.h>

using namespace FEDM::Core;
// using namespace FEDM::TagHandler;


int main()
{
    

    // set FEDM::Core::ReaderModule::ReaderModule() as reader
    // ReaderModule reader;
    Const::ReaderType readerType;
    unsigned int name;
    readerType.GetReaderName(name);

    // print reader name
    std::cout << "Reader name: " << name << std::endl;

    

    return 0;

}