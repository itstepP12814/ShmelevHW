#include <iostream>

using namespace std;

//Перевод числе в разные системы счисления

int const SIZE = 10000; //Размер массива

void calc(int main_number, int num_system);

int main()
{
    int main_number = 0;
    int num_system = 10;

    cout << "Эта программа поможет Вам перевести число в другую систему счисления." << endl << "Введите десятичное число: ";
    cin >> main_number;
    cout << endl << "Введите систему счисления, в которую следует перевести число: ";
    cin >> num_system;
    calc (main_number, num_system);
    return 0;
}

void calc (int main_number, int num_system) //Калькулятор
{
    int ostatok = main_number; //Для удобства присваевается то же значение
    int array1 [SIZE];
    int i = 1; //Переменная, которая будет считать позицию массива для будущего считывания числа.

    for (; main_number !=0; ++i)
    {
        ostatok = main_number%num_system; //Сначала рассчитывается остаток, на основании целого. Затем считаем новое целое для новой итерации.
        main_number/=num_system;
        array1 [i] = ostatok;//Складываем в массив цифры результирующего числа.
    }
    cout << endl << "Ваш ответ: ";
    for (i-=1; i!=0; --i) //Выводим массив наоборот.
    {
        if (array1[i]<10)
        {
            cout << array1[i];
        }
        else
        {
            char bukv_otvet = array1[i]+55;
            cout << bukv_otvet;
        }
    }
}
