#include <C:\Users\User\Desktop\UHN_RFID\Setup\Raspi SDK\SDK\sub-prj\lib\feusb\include\feusb.h>
#include <iostream>
#include <stdio.h>

class RFIDReader {
    int handle;

public:
// open the port
    RFIDReader(const char* ip, int port){
        handle = FEUSB_OpenDevice(port);
        if (handle < 0) {
            std::cout << "Error opening port:" << handle << std::endl;
        }
    }

    ~RFIDReader(){
        FEUSB_CloseDevice(handle);
    }

    std::string read(){
        char tag_data[256];
        // read the tag using FEUSB_Transceive
        int result = FEUSB_Transceive(handle, 0, 0, 0, tag_data, 256);
        if (result < 0) {
            std::cout << "Error reading tag:" << result << std::endl;
            return "";
        }
        else {
            return tag_data;
        }
    }
};

int main()
{
    const char* ip_number = "192.168.0.1";
    RFIDReader reader(ip_number, 3000);
    std::string tag = reader.read();
    std::cout << "Tag: " << tag << std::endl;
    return 0;
}