#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class message {
    public:
        uint8_t id;
        uint8_t type;
        uint8_t flags;
        uint8_t sendType;
        message() {
            id = -1;
            type = -1;
            flags = -1;
            sendType = -1;
        }
        void printAllFields() {
            printf ("id:\t%d\n", id);
            printf ("type:\t%d\n", type);
            printf ("flags:\t%d\n", flags);
            printf ("sendType:\t%d\n", sendType);
        }
};

int main()
{   
    uint8_t messageBytes[10];
    string filename = "testMessageBits";
    ifstream ifs (filename.c_str());
    if (ifs.is_open())
    {
        for (int i = 0; i < 5; i++)
        {
            ifs >> messageBytes[i];
        }

        ifs.close(); // CLose input file
    }
    else { //Error message
        printf ("could not find %s\n", filename.c_str());
        EXIT_FAILURE;
    }
    message msg;
    msg.id = 1;
    msg.printAllFields();
    printf ("Hello\n");
    for (int i = 0; i < sizeof (messageBytes) / sizeof (messageBytes[0]); i++) {
        printf ("%d ", messageBytes[i]);
    }
    printf ("\n");
    return 0;
}