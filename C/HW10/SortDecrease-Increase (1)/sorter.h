#ifndef SORTER_H_INCLUDED
#define SORTER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename T> T sorter (T array1[], int SIZE, int trigger)
{
    for (int i = 0; i<SIZE; ++i){
        for (int j=SIZE-1; j>i; --j){
            switch(trigger){
            case 1:
            if (array1[j-1]<array1[j]){
                T x = array1[j-1];
                array1[j-1] = array1[j];
                array1[j] = x;
            }
            break;

            case 2:
            if (array1[j-1]>array1[j]){
                T x = array1[j-1];
                array1[j-1] = array1[j];
                array1[j] = x;
            }
            break;

            default:
                cout << endl << "Вы сделали неверный выбор." << endl;
                break;
            }
        }
   }
    for (int i = 0; i<SIZE; ++i)
    {
        cout << array1[i] << endl;
    }
    return 0;


}


#endif // SORTER_H_INCLUDED
