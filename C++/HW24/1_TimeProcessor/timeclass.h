#ifndef TIMECLASS_H
#define TIMECLASS_H
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class timeClass
{
    public:
        timeClass(){
            secondsStore = time(NULL);//Записываем количество секунд в переменную типа time_t
            actualTime = localtime(&secondsStore); //Переписываем данные в структуру tm
        };
        ~timeClass(){};

        void timeInput();
        void timeFormatter(const int geo);
        timeClass operator+(const timeClass& secondTime);
        char* getTime(){return showTime;}
        char showTime[12]; //переменная для вывода времени
    protected:
        time_t secondsStore; //тут храниться количество секунд с 70х
        struct tm* actualTime; //структура для упорядочивания данных о времени

};

#endif // TIMECLASS_H
