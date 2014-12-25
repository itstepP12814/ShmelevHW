#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>
#include "Client.h"
using namespace std;

class Printer
{
    public:
        Printer();
        virtual ~Printer();
        void addClient(Client* newClient);
        size_t queueSize;
        Client** clientQueue;
        friend class Client;
    private:


};

#endif // PRINTER_H
