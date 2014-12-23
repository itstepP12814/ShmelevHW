#ifndef BUSSTOP_H
#define BUSSTOP_H
#include <time.h>
#include <stdlib.h>

class BusStop
{
    public:
        BusStop();
        virtual ~BusStop();
    protected:
        time_t actualSeconds;
        tm* actualTime;

};

#endif // BUSSTOP_H
