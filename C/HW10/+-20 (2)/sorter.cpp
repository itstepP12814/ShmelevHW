#include "header.h"

int searcher(int array1[], int SIZE)
{
    int left_number, right_number = 21;
    int left_border, right_border = 0;
    //Поиск крайних отрицательных значений
    for(int i=0; i<(SIZE/2); ++i)  //Поиск с левой стороны массива
    {
        if (array1[i]<left_number)
        {
            left_number = array1[i];
            left_border = i;
        }
    }

    for(int i=(SIZE/2); i<SIZE; ++i)  //Поиск с правой стороны массива
    {
        if (array1[i]<right_number)
        {
            right_number = array1[i];
            right_border = i;
        }

    }

    int sort_interval = (right_border-left_border)-1; //Поправка индексов и соотнесение их с реальным положением цифр

    int real_left_border = left_border + 1;
    int real_right_border = right_border - 1;

    cout << endl << "Левая граница: " << left_border << endl << "Правая граница: " << right_border << endl << "Новый интервал сортировки: " << sort_interval << endl;
    cout << "Первое число для сортировки (место): " << real_left_border << endl << "Последнее число для сортировки (место): " << real_right_border << endl;

    sorter(array1,SIZE,sort_interval,real_left_border,real_right_border);

    // Вывод отсортированного массива

    for (int i = 0; i<SIZE; ++i)
    {
        cout << array1[i] << endl;
    }

    cout << endl << "Числа между " << array1[left_border] << " и " << array1[right_border] << " отсортированы в порядке убывания.";

}

int sorter (int array1[], int SIZE, int sort_interval, int real_left_border, int real_right_border)
{
    if (sort_interval >=2) //Проверка размера интервала
    {
        // Собственно сортировка
        for (int i = real_left_border; i < real_right_border; ++i)
        {
            for (int j = real_right_border; j>i; --j)
            {
                if (array1[j]>array1[j-1])
                {
                    int x = array1[j];
                    array1[j] = array1[j-1];
                    array1[j-1] = x;
                }
            }
        }

    }



    else
    {
        cout << "Интервал для сортировки слишком мал, перезапустите программу.";
        return 0;
    }
}
