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
    scanf("%d:%d:%d %s", &actualTime->tm_hour, &actualTime->tm_min, &actualTime->tm_sec, &dayFlag);

    if(strcmp(dayFlag,"PM") == 0 || strcmp(dayFlag,"Pm")==0 || strcmp(dayFlag,"pM")==0 || strcmp(dayFlag,"pm")==0) {
            actualTime->tm_hour+=12;
    }
}

timeClass timeClass::operator+(const timeClass& secondTime){
    timeClass newTime;
    time_t temp = secondTime.secondsStore;
    time_t seconds = temp+this->secondsStore;
    newTime.actualTime = localtime(&seconds);
    strftime(showTime,9,"%H:%M:%S", newTime.actualTime);
    cout << showTime << endl;
    return newTime;
}





