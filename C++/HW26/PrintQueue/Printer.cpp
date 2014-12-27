#include "Printer.h"
Printer::Printer()
{
    clientQueue = new Client*[0];
    queueSize = 0;
}

Printer::~Printer()
{
    //dtor
}

void Printer::addClient(Client* newClient){
    Client** temp = clientQueue;
    clientQueue = new Client*[queueSize+1];
    ++queueSize;
    for(int i=0; i<queueSize; ++i){
        clientQueue[i]=temp[i];
    }
    clientQueue[queueSize-1] = newClient;
}
