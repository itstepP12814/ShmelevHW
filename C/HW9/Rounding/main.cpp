#include "header.h"

using namespace std;

int main()
{
    double number = 123.857865465456456456;
    int precision = 0;

    cout << "Программа для округления числа" << endl << "Число для округления - " << setprecision(1000)<< number << endl << "Выберите точность округления (знаков после запятой): ";
    cin >> precision;

    rounder(number, precision);
    return 0;
}
