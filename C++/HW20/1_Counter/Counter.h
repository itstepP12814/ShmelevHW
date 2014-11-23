#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <windows.h>
using namespace std;

class Counter
{
protected:
    int minAmount;
    int maxAmount;
    int bodyOfCounter;
public:
    void plusOne();
    void changeBorders();
    void counterOutput();
    void resetCounter();
    //static void *menu[4];
    Counter(); //Обьявляем конструктор
    ~Counter(){cout << "Counter is destructed";}
};

#endif // COUNTER_H
