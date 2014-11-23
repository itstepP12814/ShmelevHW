#include "header.h"

int **columnMover(int m1,int m2,int **pm, int changeTrigger)
{
/*
Из-за этой функции возникает следующая ошибка памяти:

*** Error in `/home/ukod/ShmelevHW/HW15/1_ArrayMaster/bin/Debug/1_ArrayMaster': free(): invalid next size (fast): 0x093f2108 ***
Aborted (core dumped)

Мне не удалось разобраться в том как её исправить.
*/
    --changeTrigger;

    for(int i=0; i<m1; ++i)
    {
        for(int j = m2-1; j>changeTrigger; --j)
        {
            int ppm = pm[i][j-1];
            pm[i][j-1] = pm[i][j];
            pm[i][j] = ppm;
        }
    }
    return pm;
}

