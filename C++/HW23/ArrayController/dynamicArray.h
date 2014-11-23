#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class dynamicArray
{
    public:
        dynamicArray();
        dynamicArray(const string str);
        dynamicArray(const int arraySize);
        dynamicArray(const dynamicArray& original);

        virtual ~dynamicArray();
        void printArray();

        ///Перегруженные операторы
        string& operator[](const int j)const;
        const string& operator=(const string str)const;
        dynamicArray operator+(const dynamicArray& secondArray)const;
        dynamicArray& operator++();
        dynamicArray& operator--();

    private:
        string* nameArray;
        int length;
        int index;
        static const int amountOfStrings = 128;
        int arraySize;
        int actualSize;
};

#endif // DYNAMICARRAY_H
