#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    double answer = 0;
    for(int i = 1; i<argc; ++i){
    answer += atof(*(argv+i));
    }
    answer /= (argc-1);
    printf("Среднее из чисел: %f \n", answer);
    return 0;
}
