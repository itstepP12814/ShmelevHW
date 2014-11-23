#ifndef RESPONSIVEARRAY_H
#define RESPONSIVEARRAY_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class ResponsiveArray
{
    public:
        void setSizeUpTo(int);
        ResponsiveArray():size(1),array(NULL){setSizeUpTo(1); cout << "Ready\n";};
        virtual ~ResponsiveArray(){cout << "Array deleted\n";}
        int& operator[](int i);

        int getSize(){return size;}
    private:
        int* array;
        int size;
};

#endif // RESPONSIVEARRAY_H
