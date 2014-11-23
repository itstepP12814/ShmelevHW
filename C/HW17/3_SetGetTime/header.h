#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;

struct prettyTime{
    unsigned seconds:6;
    unsigned minutes:6;
    unsigned hours:5;
} binaryTimer;

int triggerIfAuto = 0; //Если последний раз вызывалось автоматическая установка времени, то это здесь запоминается для того, чтобы показывать каждый раз актуальное время.
//Да, это глобальная переменная...

void timePrint(void);
void autoSetTime(void);

#endif // HEADER_H_INCLUDED
