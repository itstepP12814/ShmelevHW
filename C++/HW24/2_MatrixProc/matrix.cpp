#include "matrix.h"

Matrix::Matrix(int arraySize) {
    arraySizeInClass = arraySize;
    amountOfNumbersInClass = 0;

    ptr_array[0] = new int [arraySize];
    for(int i=0; i<arraySize; ++i) {
        ptr_array[0][i] = i;
    }
}
Matrix::Matrix(int arraySize, int amountOfNumbers) {
    arraySizeInClass = arraySize;
    amountOfNumbersInClass = amountOfNumbers;
    ptr_array = new int* [arraySize];
    for(int i=0; i<arraySize; ++i) {
        ptr_array[i] = new int [amountOfNumbers];
    }
    for(int i=0; i<arraySize; ++i) {
        for(int j=0; j<amountOfNumbers; ++j) {
            ptr_array[i][j] = j+i;
        }
    }
}

Matrix::~Matrix()
{
    if(amountOfNumbersInClass = 0) {
        delete []ptr_array[0];
    }
    else {
        for(int i=0; i<amountOfNumbersInClass; ++i) {
            delete []ptr_array[i];
        }
    }
}

void Matrix::showArray() {
    if(amountOfNumbersInClass==0) {
        for(int i=0; i<arraySizeInClass; ++i) {
            cout << getNumber(i) << " ";
        }
    }
    else {
        for(int i=0; i<arraySizeInClass; ++i) {
            for(int j=0; j<amountOfNumbersInClass; ++j) {
                cout << getNumber(i,j) << " ";
            }
            cout << endl;
        }
    }
}

Matrix Matrix::operator+(const Matrix& secondMatrix)const {
    Matrix result(arraySizeInClass, amountOfNumbersInClass);
    if(arraySizeInClass==secondMatrix.arraySizeInClass && amountOfNumbersInClass==secondMatrix.amountOfNumbersInClass) {
        for(int i=0; i<arraySizeInClass; ++i) {
            for(int j=0; j<amountOfNumbersInClass; ++j) {
                result.ptr_array[i][j] = ptr_array[i][j]+secondMatrix.ptr_array[i][j];
            }
        }
    }
    else {
        cerr << "Error: array's have different configuratio\n";
        exit(1);
    }
    return result;
}
