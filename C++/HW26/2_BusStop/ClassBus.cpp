#include "ClassBus.h"

ClassBus::ClassBus(const ClassBus& another):busNumber(another.busNumber), busTime(another.busTime), seconds(another.seconds){
}

ClassBus::~ClassBus()
{
    //dtor
}

ClassBus& ClassBus::operator[](int index){
    return this[index];
}

