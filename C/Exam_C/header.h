#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int* simpleNumberGenerator(int* simpleNumbers, int amountOfNumbers);
void printer(int* simpleNumbers, int amountOfNumbers);
int recordInFile(int* simpleNumbers, int amountOfNumbers);

#endif // HEADER_H_INCLUDED
