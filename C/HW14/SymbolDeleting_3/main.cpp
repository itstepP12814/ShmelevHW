#include <stdio.h>
#include <string.h>

int main()
{
    const int SIZE = 128;
    char stroka[SIZE], *pStroka;
    pStroka = stroka;

    gets(pStroka);
    int N = strlen(stroka);

    int a = 3; //Первый вырезаемый символ
    --a; //Корректировка для удобства пользования
    int b = 8;//Последний вырезаемый символ

    strncpy((pStroka+a), (pStroka+b), b-a); //Здесь выбранный интервал заменяется скопированными символами из другой части этой де строки

    printf(pStroka);


    return 0;
}
