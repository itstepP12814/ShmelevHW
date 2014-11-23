#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//int generator (int a[], int b); //Указываются любые имена, важен порядок и тип передаваемых параметров
double generator (double a[], int b);

template <typename T> T searcher(T array1[], int SIZE) { //Тип массива устанавливается автоматически, тип размера массива задан жестко

T summ = 0;
T ave = 0;

for (int i = 0; i<SIZE; ++i){
summ += array1[i];
}
ave = summ/SIZE;

return ave;
}

#endif // HEADER_H
