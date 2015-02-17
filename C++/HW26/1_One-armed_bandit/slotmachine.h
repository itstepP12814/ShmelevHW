#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include <iostream>
using namespace std;
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

class slotLine
{
    public:
        slotLine(): symbols{'\1','\2','\3','\4'}{}
        virtual ~slotLine(){}
        char spin();
        char getSymbol();
        void randomGen();
    private:
        char symbols[4];
        const int amountOfSymbols = 4;
        int spinTimes;
};
#endif // SLOTMACHINE_H
