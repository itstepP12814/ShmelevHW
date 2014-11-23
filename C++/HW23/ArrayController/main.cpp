#include "dynamicArray.h"

int main()
{
    dynamicArray x;
    dynamicArray y("Lol");
    dynamicArray n("Trololo");
    printf("Enter names: \n");
    x.printArray();
    x = n+y;
    for(int i=0; i<6; ++i){
    ++x;
    x.printArray();
    }

    for(int i=0; i<6; ++i){
    --x;
    x.printArray();
    }

    return 0;
}
