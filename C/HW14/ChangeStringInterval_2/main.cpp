#include <stdio.h>
#include <string.h>

int main()
{
    const int SIZE = 128;
    char stroka[SIZE], dest[SIZE*2];
    int a,b;

    printf("Введите строку: ");
    gets(stroka);
    int N = strlen(stroka); // Количество занятых элементов
    printf("Введите от какого символа вырезать строку (от 1 до %d): ", N);
    scanf("%d", &a);
    printf("Введите до какого символа (от %d до %d): ", a, N);
    scanf("%d", &b);
    --a; //Корректировка для удобства пользователя
    strncpy(dest, (stroka+a), b-a); //Выражение stroka+a - является указателем на область массива
    printf("Ваша новая строка: ");
    puts(dest);

    return 0;
}
