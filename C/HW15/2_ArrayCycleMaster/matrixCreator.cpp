#include "header.h"

int **createMatrix(int m1, int m2) {
    //Выделение памяти под массивы
    int **pm = new int*[m1];
    for(int i=0; i<m1; ++i)
    {
        pm[i] = new int[m2];
    }

    //Присвоение значений
    for(int i=0; i<m1; ++i)
    {
        for(int j=0; j<m2; ++j)
        {
            pm[i][j] = i+j+1;
        }
    }
    return pm;
}
