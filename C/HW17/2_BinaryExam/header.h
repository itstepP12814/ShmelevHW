#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string.h>
#include <stdlib.h>

#define NUMBER_OF_STUDENTS 12

using namespace std;


struct student {
    char name[20];
    int group;
    unsigned exam:1;
};

void printerShowUnit(student* base, int number);
void printerShowAll(student* base);
void printerShowName(student* base, int number);
void printerShowWinners(student* base);
void printerShowLoosers(student* base);

int compare(const void* unit_1, const void* unit_2);

#endif // PRINTER_H
