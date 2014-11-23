#include "header.h"

int main()
{
    int const SIZE = 50;
    //int array1 [SIZE];
    double array1 [SIZE];

    srand(time(NULL));

    generator(array1, SIZE);//В передаваемые параметры вносятся имена переменных, значения которых нужно передать в функцию. При этом не имеет значения, какие имена использовались для объявления и какие имена будут использоваться в самой функции.

    for (int i = 0; i<SIZE; ++i){//Вывод значений массива
    cout << array1[i] << endl;
    }

    cout << endl << "Среднее арифметическое из массива: " << searcher(array1, SIZE) << endl;
    return 0;
}
