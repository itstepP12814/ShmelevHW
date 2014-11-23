#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int randomizer(int array1[], int SIZE)
{
    srand(time(NULL));

    for (int i = 0; i<SIZE; ++i)
    {
        array1[i] = rand()%SIZE+1;
    }
    return 0;
}

int printer(int *massive, int SIZE)
{
    for(int i = 0; i<SIZE; ++i, ++massive)
    {
        cout << *massive << " ";
    }
    cout << endl;
}

int reverser(int *massive, int SIZE)
    {
        for(int i = 0; i<SIZE; ++i, ++massive)
        {
            int x = *massive;
            *massive = *(massive+1);
            *(massive+1) = x;
            ++massive;
        }
    }

int main()
{
    int const SIZE = 20;
    int array1[SIZE];

    randomizer(array1,SIZE);
    printer(array1,SIZE);
    reverser(array1,SIZE);
    printer(array1,SIZE);

//    reverser(array1,SIZE);

    return 0;
}
