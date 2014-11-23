#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int number = 3;
    int stepen = 2;

    int *pow_num = new int[1]; //Динамический массив размером 2 элемента
    *pow_num = number;
    *(pow_num+1) = stepen;

    cout << "Наше число: " << *pow_num << endl;
    cout << "Возводим в степень " << *(pow_num+1) << endl;
    *pow_num = pow(*pow_num, *(pow_num+1)); //Расчет
    cout << "Ответ: " << *pow_num << endl;
    delete []pow_num;
    return 0;
}
