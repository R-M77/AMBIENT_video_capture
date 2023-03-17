#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include "include/fedm/ReaderModule.h"
#include "include/fedm/UsbManager.h"

using namespace FEDM;
using namespace FEDM::TagHandler;
using namespace FEDM::Utility;
using namespace std;

// vector<string> tagList;

class Inventory_TagHandler_Sample
{
public:
    static void tagHandler_EPC_Sample(ReaderModule &reader)
    {
        reader.hm().setUsageMode(FEDM::Hm::UsageMode::UseQueue);

        int state = reader.hm().inventory();
        cout << "inventory: " << reader.lastErrorStatusText() << endl;
        if (state != ErrorCode::Ok) { /* Add error-handling... */ }

        // Number of read tags
        size_t count = reader.hm().queueItemCount();
        cout << "No. of tags: " << count << endl;

        // Create TagItem for each tag and output IDD
        while (reader.hm().queueItemCount() > 0)
        {
            unique_ptr <const TagItem> tagItem = reader.hm().popItem();
            if (tagItem == nullptr) { /* Add error handling */ cout << "Error: tag queue empty"; return; }
            // Create TagHandler
            unique_ptr<ThBase> th = reader.hm().createTagHandler(*tagItem);
            if (th == nullptr) { /* Add error handling */ cout << "Error: Failed to create tag handler"; return; }
            // ********************************************************************************
            if (th->tagHandlerType() == ThBase::TypeEpcClass1Gen2)
            {
                // ***************************
                // Add actions with tags here
                // ***************************
                // print the tag's idd
                cout << "Tag " << th->iddToHexString() << " is declared: " << th->transponderName() << endl;
            }
            else if (th->tagHandlerType() == ThBase::TypeIso15693_NXP_IcodeSLI)
            {
                // ***************************
                // Add actions with tags here
                // ***************************
                // print the tag's idd
                cout << "Tag " << th->iddToHexString() << " is declared: " << th->transponderName() << endl;
            }

            // ***************************
            // Add tagHandlerTypes here
            // else if(th.tagHandlerType() == ...
            // ***************************
            else
            {
                cout << "Tag " << th->iddToHexString() << " is not declared: " << th->transponderName() << endl;
            }
        }
    }
};

class UsbManagerConnect : IUsbListener
{
public:
    static UsbManager usbManager;

    static void SampleMain()
    {
        UsbManagerConnect usbManager;
        usbManager.Run();
    }

    void Run()
{
    // Start USB Discover
    usbManager.startDiscover(this);
    cout << "Waiting for Connection with first USB Reader...." << endl;;

    // Wait for first BLE device
    while (usbManager.readerCount() == 0)
    {
    }

    // Get the Connector by BLE Manager
    UsbScanInfo usbScanInfo = usbManager.popDiscover();
    usbManager.stopDiscover();

    if (!usbScanInfo.isValid())
    {
        cout << "Error: Invalid usb scan info" << endl;
        return;
    }

    Connector connector = usbScanInfo.connector();
    if (connector.isValid())
    {
        // Create Reader Module with Request Mode UniDirectional = Advanced Protocol
        ReaderModule* reader = new ReaderModule(RequestMode::UniDirectional);
        cout << "Start connection with Reader: " << usbScanInfo.readerTypeToString() << " (" << connector.usbDeviceIdToHexString() << ")..." << endl;
        // Connect
        int state = reader->connect(connector);

        cout << "Connect: " << reader->lastErrorStatusText() << endl;
        // Error handling
        if (state != ErrorCode::Ok)
        {
            return;
        }

        set<string> uniqueTags;

        // Perform 3 scans and inventory all unique tags
        // for (int i = 0; i < 3; i++)
        // {
        //     // Inventory tags
        //     state = reader->hm().inventory();
        //     cout << "inventory: " << reader->lastErrorStatusText() << endl;
        //     if (state != ErrorCode::Ok) { /* Add error-handling... */ }

        //     // Get tag count
        //     size_t count = reader->hm().itemCount();

        //     // Output number of tags found
        //     std::cout << "No. of tags found in scan " << i + 1 << ": " << count << std::endl;

        //     // Save data to uniqueTags set
        //     for (size_t itemIndex = 0; itemIndex < count; itemIndex++)
        //     {
        //         // Create TagItem
        //         TagItem tagItem = reader->hm().tagItem(itemIndex);
        //         if (!tagItem.isValid()) { /* Add error handling */ cout << "Error: tag table empty"; return; }

        //         // Get IDD of TagItem
        //         string iddString = tagItem.iddToHexString();

        //         // Insert IDD to uniqueTags set
        //         uniqueTags.insert(iddString);
        //     }
        // }
        
        // perform scans until at least 1 tag is found. print the scan number and the number of tags found
        int scanNum = 0;
        while (uniqueTags.size() == 0) {
            scanNum++;
            // Inventory tags
            state = reader->hm().inventory();
            cout << "inventory: " << reader->lastErrorStatusText() << endl;
            if (state != ErrorCode::Ok) { /* Add error-handling... */ }

            // Get tag count
            size_t count = reader->hm().itemCount();

            // Output number of tags found
            std::cout << "No. of tags found in scan " << scanNum << ": " << count << std::endl;

            // Save data to uniqueTags set
            for (size_t itemIndex = 0; itemIndex < count; itemIndex++)
            {
                // Create TagItem
                TagItem tagItem = reader->hm().tagItem(itemIndex);
                if (!tagItem.isValid()) { /* Add error handling */ cout << "Error: tag table empty"; return; }

                // Get IDD of TagItem
                string iddString = tagItem.iddToHexString();

                // Insert IDD to uniqueTags set
                uniqueTags.insert(iddString);
            }
        }

        // Output unique tags found
        std::cout << "No. of unique tags found: " << uniqueTags.size() << std::endl;

        // Save data to CSV file
        if (!uniqueTags.empty()) {
            // Open file for appending
            ofstream file;
            file.open("tag_data.csv", std::ios::app);

            // Create TagItem for each unique tag and output IDD
            for (auto it = uniqueTags.begin(); it != uniqueTags.end(); ++it)
            {
                // Display IDD on screen
                std::cout << "IDD: " << *it << std::endl;

                // // Save data to CSV file
                // file << *it << "," << time(0) << endl;

                // save data to CSV file, with time in EST
                time_t now = time(0);
                tm *gmtm = gmtime(&now);
                gmtm = localtime(&now);
                file << *it << "," << asctime(gmtm) << endl;
                
            }

            // Close file
            file.close();
        }

        // identify tag type using tagHandler_EPC_Sample
        Inventory_TagHandler_Sample::tagHandler_EPC_Sample(*reader);
        


        // Disconnect Reader
        reader->disconnect();

        if (reader->lastError() == ErrorCode::Ok)
        {
            cout << "\n" << reader->info().readerTypeToString() << " disconnected." << endl;
        }
        delete reader;
        }
    }


    void onUsbEvent()
    {
        // Not used
    }
};

UsbManager UsbManagerConnect::usbManager;

int main()
{
    UsbManagerConnect::SampleMain();

    return 0;
}