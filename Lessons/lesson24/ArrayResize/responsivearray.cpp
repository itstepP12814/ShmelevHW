#include "responsivearray.h"

void ResponsiveArray::setSizeUpTo(int i){
    while(i>=size){
        size *=2;
    }
    array = (int*)realloc(array,size*sizeof(int));
}


int& ResponsiveArray::operator[](int i){
    setSizeUpTo(i);
    return array[i];
}
