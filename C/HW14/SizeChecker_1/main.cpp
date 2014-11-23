#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    const int SIZE = 128;
    char stroka[SIZE], *pStroka;
    pStroka = stroka;

    gets(stroka);
    int N = strlen(stroka);
    int antiN = SIZE - strlen(stroka);
    puts(pStroka);
    cout << "Длинна строки: " << N << endl << "Осталось символов в массиве: " << antiN << endl;
    return 0;
}
