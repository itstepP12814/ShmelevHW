#ifndef CLASSBUS_H
#define CLASSBUS_H
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

class ClassBus
{
    public:
        ClassBus():busNumber(0), seconds(0), busTime(0), amountOfPassengers(0), maxPassengers(8){};
        ClassBus(int number, int sheludeTime):busNumber(number), seconds(time(NULL)), busTime(sheludeTime), amountOfPassengers(0), maxPassengers(8){};
        ClassBus(const ClassBus& another);
        virtual ~ClassBus();
        int busTime;
        int busNumber;
        ClassBus& operator=(const ClassBus& another);
        int amountOfPassengers;
        const int maxPassengers;
    protected:
        time_t seconds;

};

#endif // CLASSBUS_H
