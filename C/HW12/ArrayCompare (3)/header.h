#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int printer(int *massive, int SIZE);
int cleaner(int *arrayX, int SIZE);
int searcher(int *arrayX, int Ot, int Do, int key);
int comparer(int *arrayFirst, int *arraySecond, int *arrayResult, int SIZE, int trigger);
int sorter(int *arrayX, int SIZE);
int unity(int *m1, int *m2, int *m3, int SIZE);

#endif // FUNCTIONS_H
