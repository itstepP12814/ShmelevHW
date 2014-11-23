#include "header.h"

int main() {
    int const SIZE = 10;
    int const dSIZE = 20;
    int newSize;

    int array1[SIZE] = {23,65,785,434,77,7,55,47,43,234};
    int array2[SIZE] = {54,25,12,66,11,75,867,43,77,43};
    int array3[SIZE*2];

    cout << "Первый массив: " << endl;
    sorter(array1,SIZE);
    printer(array1,SIZE);
    cout << "Второй массив: " << endl;
    sorter(array2,SIZE);
    printer(array2,SIZE);

    cout << "Объединение двух массивов: " << endl;
    unity(array1,array2,array3,SIZE);
    sorter(array3,dSIZE);
    printer(array3,dSIZE);

    cleaner(array3,dSIZE);

    cout << "Общие элементы двух массивов: " << endl;
    newSize = comparer(array1,array2,array3,SIZE,1); //Присваиваем новый размер массива (для вывода)
    printer(array3,newSize);

    cout << "То, что есть в Первом, но нет во Втором: " << endl;
    newSize = comparer(array1,array2,array3,SIZE,2);
    printer(array3,newSize);

    cout << "То, что есть во Втором, но нет в Первом: " << endl;
    newSize = comparer(array1,array2,array3,SIZE,3);
    printer(array3,newSize);

    cout << "Уникальные элементы обоих массивов: " << endl;
    newSize = comparer(array1,array2,array3,SIZE,4);
    printer(array3,newSize);
    cout << endl;

    return 0;
}
