#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

int printer(int m1, int m2, int **pm);
int **createMatrix(int m1, int m2);
int **shiftColumns(int m1,int m2,int** pm, int to, int kuda);
int** shiftRows(int m1,int m2,int** pm, int to, int kuda);
#endif // HEADER_H_INCLUDED
