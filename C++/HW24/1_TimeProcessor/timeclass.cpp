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
    char* dayFlag;
    int hour;
    printf("Enter time HH:MM:SS (AM/PM)\n");
    scanf("%d", hour);
    scanf("%s", dayFlag);
    cout << dayFlag;

    /*
    if(dayFlag != pmEthalon) {
        if(dayFlag == "PM" || dayFlag == "Pm" || dayFlag == "pM" || dayFlag == "pm") {
            actualTime->tm_hour+=12;
        }
    }
    */
}



