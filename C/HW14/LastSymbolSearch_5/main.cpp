#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char stroka[128];
    int counter = 0;
    printf("Введите строку: \n");
    gets(stroka);
    printf("Введите символ для поиска: \n");
    int key = getchar();
    char *pStroka;
    pStroka = stroka;

    //printf("Введите текст: ");
    printf("В строке %s последний из символов %c находится в позиции: ", stroka, key);
    int N = strlen(pStroka);
    for(int i = 0; i<N; ++i){
         if (pStroka[i] == key){
            counter = i;
         }
        }
    if (counter != 0){
    printf("%d \n", counter+1);
    }
    else {printf("\n Не найдено. \n");}
    return 0;
}
