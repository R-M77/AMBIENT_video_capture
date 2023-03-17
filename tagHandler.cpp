

#include <iostream>
#include "ReaderModule.h"

using namespace FEDM;
using namespace FEDM::TagHandler;
using namespace std;

class MyTagHandler : public ThBase
{
public:
    MyTagHandler(const TagItem* tagItem) : ThBase(tagItem) {}

    void handle() override
    {
        // handle the tag here
    }
};

class Inventory_TagHandler_Sample
{
public:
    static void tagHandler_EPC_Sample(ReaderModule &reader)
    {
        reader.hm().setUsageMode(FEDM::Hm::UsageMode::UseQueue);

        if (!reader.initialize()) { cout << "Failed to initialize reader" << endl; return 0; }

        int state = reader.hm().inventory();
        cout << "inventory: " << reader.lastErrorStatusText() << endl;
        if (state != ErrorCode::Ok) { /* Add error-handling... */ }

        // Number of read tags
        size_t count = reader.hm().queueItemCount();
        cout << "No. of tags: " << count << endl;

        // Create TagItem for each tag and output IDD
        while (reader.hm().queueItemCount() > 0)
        {
            unique_ptr<const TagItem> tagItem = reader.hm().popItem();
            if (tagItem == nullptr) { /* Add error handling */ cout << "Error: tag queue empty"; return; }
            // Create TagHandler
            unique_ptr<MyTagHandler> myTagHandler(const_cast<TagItem*>(tagItem.get()));
            if (myTagHandler == nullptr) { /* Add error handling */ cout << "Error: Failed to create tag handler"; return; }

            if (myTagHandler->tagHandlerType() == ThBase::TypeEpcClass1Gen2)
            {
                // ***************************
                // Add actions with tags here
                // ***************************
                // print the tag's idd
                cout << "Tag " << myTagHandler->iddToHexString() << " is declared: " << myTagHandler->transponderName() << endl;

            }
            else if (myTagHandler->tagHandlerType() == ThBase::TypeIso15693_NXP_IcodeSLI)
            {
                // ***************************
                // Add actions with tags here
                // ***************************
                // print the tag's idd
                cout << "Tag " << myTagHandler->iddToHexString() << " is declared: " << myTagHandler->transponderName() << endl;
            }
            else
            {
                cout << "Tag " << myTagHandler->iddToHexString() << " is not declared: " << myTagHandler->transponderName() << endl;
            }
        }
    }
};

int main()
{
    // Initialize reader
    ReaderModule reader;
    if (!reader.initialize()) { cout << "Failed to initialize reader" << endl; return 0; }

    // Set usage mode
    reader.hm().setUsageMode(FEDM::Hm::UsageMode::UseQueue);

    // Start inventory
    int state = reader.hm().inventory();
    if (state != ErrorCode::Ok) { cout << "Error: " << reader.lastErrorStatusText() << endl; return 0; }

    // Handle each tag in the queue
    while (reader.hm().queueItemCount() > 0)
    {
        // Get tag item from the queue
        unique_ptr<const TagItem> tagItem = reader.hm().popItem();
        if (tagItem == nullptr) { cout << "Error: tag queue empty" << endl; return 0; }

        // Create tag handler for the tag item
        unique_ptr<ThBase> th = reader.hm().createTagHandler(*tagItem);
        if (th == nullptr) { cout << "Error: Failed to create tag handler" << endl; return 0; }

        // Handle the tag
        MyTagHandler myTagHandler(*tagItem);
        myTagHandler.handleTag();
    }

    return 0;
}
