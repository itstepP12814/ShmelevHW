#include "header.h"
//Найти тройку в массиве, посчитать сколько всего троек

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main () {
    int const SIZE = 100000;
    int values[SIZE];
    int const key = 3; //Искомое

    for(int i=0; i<SIZE; ++i) {
        values[i] = rand()%(SIZE/10)+1;
    }

    srand(time(NULL));
    int n;

    qsort (values, SIZE, sizeof(int), compare); //Функция сортировки

    for (n=0; n<100; n++)
        printf ("%d ",values[n]);

    int answer = binarySearch(key,values,SIZE);

    if(answer == -1) {
        printf("\n\nНе найдено\n");
    }
    else {
        int counter = wider(answer,key,values,SIZE);//Функция поиска аналогичных элементов
        printf("\n\nИскомое (%d) найдено в позиции %d. Всего найдено: %d элементов.",key,answer,counter);
    }

    return 0;
}
