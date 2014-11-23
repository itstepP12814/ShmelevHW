#include "header.h"

int wider(int position, int key, int mas[], int SIZE) {
    int counter = 1;
    int i,j;

    for(i=position; mas[i+1]==key; ++i){
        ++counter;
    }
    for(j=position; mas[j-1]==key; --j){
        ++counter;
    }
    return counter;
}
