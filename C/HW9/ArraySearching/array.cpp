#include "header.h"

/* int generator (int array1[], int  SIZE) { //Указываются имена, которые будут использоваться в самой функции

for (int i = 0; i<SIZE; ++i){
    array1[i] = rand()%40;
}
return array1[SIZE];
} */

double generator (double array1[], int  SIZE) { //Указываются имена, которые будут использоваться в самой функции

int const MAX = 100;
int const MIN = 1;
int const PRECISION = 100;

for (int i = 0; i<SIZE; ++i){
    array1[i] = MIN + (rand()%((MAX - MIN) * PRECISION + 1))/(float)PRECISION; //Способ генерирования случаных чисел с плавающей точкой.
}
return array1[SIZE];
}
