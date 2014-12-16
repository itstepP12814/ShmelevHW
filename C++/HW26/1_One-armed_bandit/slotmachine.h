#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
class slotLine;
class slotMachine
{
    public:
        slotMachine();
        virtual ~slotMachine();
        void spin();
        void showResult();
    protected:
        slotLine* Lines;
        int randomNumber;

};

class slotLine:public slotMachine
{
    public:
        slotLine(int Multiplier): slotMachine(), symbols{'1','2','3','4'}{
            spinMultiplier = Multiplier;
        }
        virtual ~slotLine(){}
        bool spin(const int spinTimes);
        char getSymbol();
    private:
        char symbols[4];
        const int amountOfSymbols = 4;
        int spinMultiplier; ///ћножитель вращений, дл€ каждого барабана - свой
};



#endif // SLOTMACHINE_H
