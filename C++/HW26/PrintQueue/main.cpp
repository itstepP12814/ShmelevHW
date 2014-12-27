#include "Printer.h"
#include "Client.h"
int main()
{

    Client user1;
    Client user2;
    Client user3;
    Printer commonPrinter;

    commonPrinter.addClient(&user1);
    commonPrinter.addClient(&user2);
    commonPrinter.addClient(&user3);

    for(int i=0; i<commonPrinter.queueSize; ++i){
        cout << commonPrinter.clientQueue[i]->priority+1;
    }



    return 0;
}
