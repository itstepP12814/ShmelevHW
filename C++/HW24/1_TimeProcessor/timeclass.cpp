#include "timeclass.h"

void timeClass::timeFormatter(const int geo) {
    switch(geo) {
    case 'America':
        strftime(showTime,12, "%I:%M:%S %p", actualTime);//Записываем отформатированные данные
        break;
    case 'Europe':
        strftime(showTime,9, "%H:%M:%S", actualTime);//Записываем отформатированные данные
        break;
    default:
        cerr << "\nError: wrong geotag\n";
        exit(1);
        break;
    }
}

void timeClass::timeInput() {
    char dayFlag[2];
    int hour;
    printf("Enter time HH:MM:SS (AM/PM)\n");
    scanf("%d:%d:%d", &actualTime->tm_hour, &actualTime->tm_min, &actualTime->tm_sec);

    if(strcmp(dayFlag,"PM") == 0 || strcmp(dayFlag,"Pm")==0 || strcmp(dayFlag,"pM")==0 || strcmp(dayFlag,"pm")==0) {
            actualTime->tm_hour+=12;
    }
    secondsStore = mktime(actualTime);
}

timeClass timeClass::operator-(timeClass& secondTime){
    timeClass newTime;
    newTime.secondsStore = secondsStore-secondTime.secondsStore;
    newTime.actualTime = localtime(&newTime.secondsStore);
    newTime.actualTime->tm_hour-=3; ///ПОПРАВКА НА ТРИ ЧАСА, ОТКУДА ЭТИ ТРИ ЧАСА?
    strftime(showTime,9,"%H:%M:%S", newTime.actualTime);
    return newTime;
}

timeClass timeClass::operator+(timeClass& interval){
    timeClass temp;
    ///НЕ РАБОТАЕТ
    secondsStore = mktime(actualTime);
    temp.secondsStore = secondsStore + interval.secondsStore;
    temp.actualTime = localtime(&temp.secondsStore);
    strftime(showTime,9,"%H:%M:%S", temp.actualTime);
    return temp;
}

int timeClass::operator==(const timeClass& anotherTime){
    if(secondsStore < anotherTime.secondsStore || secondsStore > anotherTime.secondsStore){
        return 0;
    }
    else {
        if(secondsStore == anotherTime.secondsStore){
            return 1;
        }
    }
}




