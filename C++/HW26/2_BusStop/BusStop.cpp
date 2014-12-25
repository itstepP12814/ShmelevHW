#include "BusStop.h"

BusStop::BusStop():actualSeconds(time(NULL)), actualTime(localtime(&actualSeconds))
{
    amountOfPassangers = rand()%12;
}

BusStop::~BusStop()
{
}

const tm* BusStop::getNowTime(){
    actualSeconds = time(NULL);
    actualTime = localtime(&actualSeconds);
    return actualTime;
}
