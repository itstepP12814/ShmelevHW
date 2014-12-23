#ifndef CLASSBUS_H
#define CLASSBUS_H
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

class ClassBus
{
    public:
        ClassBus():busNumber(0), seconds(0), busTime(0){};
        ClassBus(int number, int sheludeTime):busNumber(number), seconds(time(NULL)), busTime(sheludeTime){};
        ClassBus(const ClassBus& another);
        virtual ~ClassBus();
        int busTime;
        int busNumber;
        ClassBus& operator[](int index);
    protected:
        time_t seconds;
};

#endif // CLASSBUS_H
