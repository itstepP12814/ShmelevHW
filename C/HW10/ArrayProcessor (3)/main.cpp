#include "header.h"

int main()
{
    cout << "Программа для обработки массива" << endl;
    cout << "Сначала сгенерируем массив, достойный операций над ним." << endl;

    int const SIZE = 20;
    int array1[SIZE];
    int position;

    randomizer(array1,SIZE); //функция заполняющая массив случаныйми числами
    printer(array1,SIZE); //функция вывода массива

    cout << "А теперь переставим их местами ещё раз." << endl;

    ranger(array1,SIZE); //функция перемешивающая цифры
    printer(array1,SIZE);

    position = rand_searcher(array1,SIZE); //функция определяет позицию числа из диапазона


    cout << "Отсортируем массив слева и справа от " << position+1 << "-й позиции" << endl;

    sorter(array1,SIZE,position);
    printer(array1,SIZE);

    return 0;
}
