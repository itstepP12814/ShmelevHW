#ifndef MAN_H
#define MAN_H
#include <iostream>
using namespace std;

///Создать Еву, Адама и отнаследовать несколько детей
class Human;
class Woman;
class Man;

class Human
{
    protected:
    Human() {cout << "protohuman was created\n";};
    Human(Man papa, Woman mama);
};

class Woman:public Human{
    private:
        Woman(){cout << "EVE created\n";};
        static Woman* eve;
    public:
        Woman(Woman mama, Man papa):Human(mama, papa){cout << "Created Woman";};
        static Woman& getEve(){
            if(!eve){
                eve = new Woman();
            }
            return *eve;
        }
};

class Man:public Human{
    protected:
        Man(){cout << "ADAM created\n";};
        static Man* adam;
    public:
        Man(Woman mama, Man papa):Human(mama, papa){cout << "Created Man";};
        static Man& getAdam(){
            if(!adam){
                adam = new Man();
            }
                return *adam;

        }
};

Woman* Woman::eve = NULL;
Man* Man::adam = NULL;

#endif // MAN_H
