#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class Matrix
{
    public:
        Matrix(int);
        Matrix(int,int);
        Matrix(const Matrix&);
        virtual ~Matrix();
        int& getNumber(const int i){return ptr_array[0][i];}
        int& getNumber(const int i,const int j){return ptr_array[i][j];}
        Matrix operator+(const Matrix& secondMatrix)const;
        Matrix operator*(const Matrix& secondMatrix)const;
        void showArray();
    private:
        int** ptr_array;
        int arraySizeInClass;
        int amountOfNumbersInClass;

};

#endif // MATRIX_H
