#include "header.h"

int rand_searcher(int array1[],int SIZE)
{

    srand(time(NULL));

    int g = 0;
    int position;
    int number = rand()%SIZE+1;
    cout << endl << "Случайное число из диапазона: " << number << endl;

    cout << "Позиции случайного числа:" << endl;
    for (int i = 0; i<SIZE; ++i)
    {
        if (array1[i] == number)
        {
            if(g == 0)
            {
                position = i;    //Записывает значение только первой позиции
                ++g;
            }
            cout << i+1 << "-я" << endl;
        }
    }
    return position;
}
