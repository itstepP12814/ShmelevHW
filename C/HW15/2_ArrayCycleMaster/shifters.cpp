#include "header.h"

int** shiftColumns(int m1,int m2,int** pm, int to, int kuda) {
    int buffer;
    int predel = 0; //Отвечает за инфу об накоплении элементов у края массива
    while(--to > 0) {
        if(kuda == 1) { //ВЛЕВО
            predel = 0;
            for(int i=0; i<m1; ++i)  //Здесь -1 к m1 не применяем так как отрабатывает оператор меньше
            {
                for(int j=m2-1; j>predel; --j)  //Здесь делаем m2-1, так как отсчет идет в обратную сторону, а предел равен нулю
                {
                    buffer = pm [i][j];
                    pm [i][j] = pm [i][j-1];
                    pm [i][j-1] = buffer;
                }
            }
            ++predel;
        }
        else
        {
            if(kuda == 2)//ВПРАВО
            {
                predel = m2-1;
                for(int i=0; i<m1; ++i)
                {
                    for(int j=0; j<predel; ++j)
                    {
                        buffer = pm [i][j];
                        pm [i][j] = pm [i][j+1];
                        pm [i][j+1] = buffer;
                    }
                }
                --predel;
            }
        }

    }

    return pm;
}

int** shiftRows(int m1,int m2,int** pm, int to, int kuda) {
    while(--to > 0) {
        int* buffer;
        int predel;

        if(kuda==1) { //Вверх
            predel = 0;

            for(int i=m1-1; i>predel; --i) {
                buffer=pm[i];
                pm[i]=pm[i-1];
                pm[i-1]=buffer;
            }
            ++predel;
        }
        else {
            if(kuda == 2) {
                predel = m1-1;
                for(int i=0; i<predel; ++i) {
                    buffer=pm[i];
                    pm[i]=pm[i+1];
                    pm[i+1]=buffer;
                }
                --predel;
            }
        }
    }

    return pm;
}
