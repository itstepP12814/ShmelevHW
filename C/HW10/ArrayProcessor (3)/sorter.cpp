#include "header.h"

int sorter (int array1[], int SIZE, int position)
{
    for (int i = 0; i<position; ++i)
    {
        for(int j = SIZE-1; j>i; --j)
        {
            if(array1[j]<array1[j-1])
            {
                int x = array1[j];
                array1[j] = array1[j-1];
                array1[j-1] = x;
            }
        }
    }
    for (int i = position; i<SIZE; ++i)
    {
        for(int j = SIZE-1; j>i; --j)
        {
            if(array1[j]>array1[j-1])
            {
                int x = array1[j];
                array1[j] = array1[j-1];
                array1[j-1] = x;
            }
        }
    }
}
