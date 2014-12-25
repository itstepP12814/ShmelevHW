#ifndef CLIENT_H
#define CLIENT_H
class Client
{
    public:
        Client(){
            priority = amountOfClients;
            ++amountOfClients;
            };
        int priority;
        virtual ~Client(){};
        friend class Printer;
        int getAmount(){return amountOfClients;}
    private:
        static int amountOfClients;

};
#endif // CLIENT_H
