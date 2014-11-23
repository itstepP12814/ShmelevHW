#include "header.h"

int ** writer(int m1,int m2,int **newMatrix, int trigger) //Записывает данные в новую строку/колонку
{
    if(trigger == 1)
    {
            for(int i=0; i<m2; ++i)
            {
                newMatrix[m2][i] = 0;
            }
    }
    else {
        for(int i=0; i<m1; ++i)
            {
            for(int j=0; j<m2; ++j){
                newMatrix[i][m2] = 0;
            }
            }
    }
    return newMatrix;
}
