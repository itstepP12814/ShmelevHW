#include "Counter.h"

Counter::Counter()  //Описываем констуктор
{
    minAmount = 0;
    maxAmount = 100;
    bodyOfCounter = minAmount;
}

void Counter::plusOne()
{
    if(bodyOfCounter >= minAmount && bodyOfCounter < maxAmount)
    {
        ++bodyOfCounter;
    }
    else
    {
        resetCounter();
        ++bodyOfCounter;
    }
    counterOutput();
}

void Counter::counterOutput()
{
    cout << "Common amount: " << bodyOfCounter << endl;
}

void Counter::changeBorders()
{
    int minor;
    int major;
    cout << "Enter start number: ";
    cin >> minor;
    cout << "Enter max number: ";
    cin >> major;
    minAmount = minor;
    maxAmount = major;
    cout << "New borders were installed" << endl;
    if(bodyOfCounter < minAmount)
    {
        bodyOfCounter = minAmount;
    }
}

void Counter::resetCounter()
{
    bodyOfCounter = minAmount;
}
