#include "FEDM_ISCReader.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    // Create a reader object
    FEDM_ISCReader 

    // get reader info for rfid_reader connected via usb
    FEDM_ISCReaderInfo reader_info;
    int result = reader.GetReaderInfo(&reader_info);
    if (result != FEDM_OK) {
        cout << "Error getting reader info:" << result << endl;
        return 0;
    }
    // print reader info
    cout << "Reader info:" << endl;
    cout << "  Reader type: " << reader_info.reader_type << endl;
    cout << "  Reader serial number: " << reader_info.serial_number << endl;
    cout << "  Reader firmware version: " << reader_info.firmware_version << endl;
    cout << "  Reader hardware version: " << reader_info.hardware_version << endl;
    cout << "  Reader model: " << reader_info.model << endl;
    cout << "  Reader name: " << reader_info.name << endl;
    cout << "  Reader description: " << reader_info.description << endl;
    cout << "  Reader IP address: " << reader_info.ip_address << endl;
    cout << "  Reader MAC address: " << reader_info.mac_address << endl;
    cout << "  Reader subnet mask: " << reader_info.subnet_mask << endl;
    cout << "  Reader gateway: " << reader_info.gateway << endl;
    cout << "  Reader port: " << reader_info.port << endl;
    cout << "  Reader status: " << reader_info.status << endl;
    cout << "  Reader antenna count: " << reader_info.antenna_count << endl;
    cout << "  Reader antenna ports: " << reader_info.antenna_ports << endl;
    cout << "  Reader antenna power: " << reader_info.antenna_power << endl;
    cout << "  Reader antenna power levels: " << reader_info.antenna_power_levels << endl;
    cout << "  Reader antenna power levels count: " << reader_info.antenna_power_levels_count << endl;

    return 0;
}    