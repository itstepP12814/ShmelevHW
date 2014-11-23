#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace std;

int** createFirstMatrix(int, int);
int** createNewMatrix(int m1, int m2, int trigger, int **pm);
int printer(int m1, int m2, int **pm);
int** stringMover(int,int,int**,int);
int** columnMover(int,int,int**,int);
int ** writer(int m1,int m2,int **pm, int trigger);

#endif // HEADER_H
