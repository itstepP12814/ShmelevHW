#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char stroka[128];
    printf("Введите строку: \n");
    gets(stroka);
    printf("Введите символ для поиска: \n");
    int key = getchar();
    char *pStroka;
    pStroka = stroka;

    //printf("Введите текст: ");
    printf("В строке %s символ %c находится в позициях: ", stroka, key);
    int N = strlen(pStroka);
    for(int i = 0; i<N; ++i){
         if (pStroka[i] == key){
            printf("%d ", i+1);
         }
        }
    printf("\n");
    return 0;
}
