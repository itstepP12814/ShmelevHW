#ifndef CLASSBUS_H
#define CLASSBUS_H
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

class ClassBus
{
    public:
        ClassBus(int number, int sheludeTime):busNumber(number), seconds(time(NULL)), busTime(sheludeTime){};
        virtual ~ClassBus();

    protected:
        const int busNumber;
        const time_t seconds;
        const int busTime;
};

#endif // CLASSBUS_H
