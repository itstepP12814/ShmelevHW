#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) //Аргументы для мейна
{
    for(int i = 0; i<argc; ++i){
        cout << argv[i] << endl;
    }
    return 0;
}


/*
    int cmpint(const void *a, const void *b){ //Пример использования библиотечной функции сортировки
     return *((int*)a)-*((int *)b);
    }

int main(int argc, char *argv[])
{
    int const SIZE = 20;
    int ar[SIZE];

  //  qsort((void*)ar, 20, sizeof(int), cmpint);
    //void qsort(void *arr, int SIZE, int sizeOfElement, int (*cmp)(const void *, const void*));

//    cmp(a,b) < 0;


    return 0;
}

*/
