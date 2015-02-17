#ifndef BUSSTOP_H
#define BUSSTOP_H
#include <time.h>
#include <stdlib.h>

class BusStop
{
    public:
        BusStop();
        virtual ~BusStop();
        const tm* getNowTime();
        tm* actualTime;
        int amountOfPassangers;
    protected:
        time_t actualSeconds;

};

#endif // BUSSTOP_H
