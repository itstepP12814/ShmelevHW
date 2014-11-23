#include "header.h"

int main()
{
    int const SIZE = 12; //Только четные
    int array1[SIZE];
    cout << "Сгенерирован массив случайных чисел от -20 до +20" << endl;

    cout << "До сортировки: " << endl;

    srand (time(NULL));

    for (int i = 0; i<SIZE; ++i) //Заполнение массива
    {
        int x = rand()%20;
        int sign = rand()%2;
        if (sign==1)
        {
            x = x*1;
        }
        else
        {
            x = x*(-1);
        }
        array1[i] = x;
        cout << array1[i] << endl;
    }

    cout << "После сортировки: " << endl;

    searcher(array1,SIZE);

    return 0;
}
