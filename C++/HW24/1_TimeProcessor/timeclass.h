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
            secondsStore = time(NULL);//���������� ���������� ������ � ���������� ���� time_t
            actualTime = localtime(&secondsStore); //������������ ������ � ��������� tm
        };

        timeClass(const timeClass& another){
            secondsStore = another.secondsStore;
            actualTime = another.actualTime;
        };

        ~timeClass(){};

        void timeInput();
        void timeFormatter(const int geo);
        timeClass operator-(timeClass& secondTime);
        timeClass operator+(timeClass& interval);
        int operator==(const timeClass& anotherTime);
        char* getTime(){return showTime;}
        char showTime[12]; //���������� ��� ������ �������
    protected:
        time_t secondsStore; //��� ��������� ���������� ������ � 70�
        struct tm* actualTime; //��������� ��� �������������� ������ � �������

};

#endif // TIMECLASS_H
