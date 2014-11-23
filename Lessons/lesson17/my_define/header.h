#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const char FILENAME[255] = "codefile.cpp";

struct defineStruct{
    char nameOfDirrective[100];
    char valueOfDirrective[500];
};

defineStruct* inFileSearch(defineStruct* defineUnit, const int SIZE_OF_ARRAY);
int sizeCalculateForDefineArray(void);
#endif // HEADER_H_INCLUDED
