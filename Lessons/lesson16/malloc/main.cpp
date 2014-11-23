#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int *array = (int*) malloc(n*sizeof(int));

    if(array==NULL){
        printf("Не дала!\n");
        return 1;
    }

    array[0]=17;

    free(array);
    return 0;
}
