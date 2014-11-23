#include "header.h"

int randomizer(int array1[], int SIZE)
{
    srand(time(NULL));

    for (int i = 0; i<SIZE; ++i)
    {
        array1[i] = rand()%SIZE+1;
    }
    return 0;
}


