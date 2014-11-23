#include "header.h"

void printerShowUnit(student* base, int number) {
    cout << "Имя студента: " << base[number].name << endl;
    cout << "Группа №" << base[number].group << endl;
    if(base[number].exam == 1) {
        cout << "Экзамен сдан." << endl;
    }
    else {
        cout << "Экзамен НЕ сдан." << endl;
    }
}

void printerShowName(student* base, int number) {
    cout << base[number].name << endl;
}

void printerShowAll(student* base) {
    for(int i=0; i<NUMBER_OF_STUDENTS; ++i) {
        printerShowUnit(base, i);
        cout << endl;
    }
}

void printerShowWinners(student* base) {
    for(int i = 0; i<NUMBER_OF_STUDENTS; ++i) {
        if(base[i].exam == 1) {
            printerShowName(base, i);
        }
    }
}

void printerShowLoosers(student* base) {
    for(int i = 0; i<NUMBER_OF_STUDENTS; ++i) {
        if(base[i].exam == 0) {
            printerShowName(base, i);
        }
    }
}
