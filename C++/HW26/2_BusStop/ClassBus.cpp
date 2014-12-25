#include "ClassBus.h"

ClassBus::ClassBus(const ClassBus& another):busNumber(another.busNumber), busTime(another.busTime), seconds(another.seconds), maxPassengers(8){
    amountOfPassengers = another.amountOfPassengers;
}

ClassBus::~ClassBus()
{
    //dtor
}

///Решение проблемы:
///use of deleted function 'ClassBus& ClassBus::operator=(const ClassBus&)'
ClassBus& ClassBus::operator=(const ClassBus& another){
    this->~ClassBus();
    new(this)ClassBus(another);
    return *this;
}

