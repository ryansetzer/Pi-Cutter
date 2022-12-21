#include<iostream>
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
    message msg;
    msg.id = 1;
    msg.printAllFields();
    printf ("Hello\n");
    return 0;
}