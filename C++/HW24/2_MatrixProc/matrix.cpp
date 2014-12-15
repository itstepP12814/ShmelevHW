#include "matrix.h"

Matrix::Matrix(int arraySize) {
    arraySizeInClass = arraySize;
    amountOfNumbersInClass = 0;

    ptr_array[0] = new int [arraySizeInClass];
    for(int i=0; i<arraySizeInClass; ++i) {
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
            ptr_array[i][j] = j;
        }
    }
}

///Конструктор копирования
Matrix::Matrix(const Matrix& copyOfMatrix){
    *ptr_array = *copyOfMatrix.ptr_array;
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
        cerr << "Error: array's have different configuration\n";
        exit(1);
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& secondMatrix)const {
    Matrix result(arraySizeInClass, amountOfNumbersInClass);
    if(arraySizeInClass==secondMatrix.arraySizeInClass && amountOfNumbersInClass==secondMatrix.amountOfNumbersInClass) {
        for(int i=0; i<arraySizeInClass; ++i) {
            for(int j=0; j<amountOfNumbersInClass; ++j) {
                result.ptr_array[i][j] = ptr_array[i][j]*secondMatrix.ptr_array[i][j];
            }
        }
    }
    else {
        cerr << "Error: array's have different configuration\n";
        exit(1);
    }
    return result;
}

const Matrix& Matrix::transpose(){
    ///Устанавливаем новые размеры матрицы
    int newSize = amountOfNumbersInClass;
    int newAmountOfNumbers = arraySizeInClass;
    ///Создаем новую временную матрицу
    Matrix temp(newSize,newAmountOfNumbers);
    if(temp.ptr_array){
        ///Переписываем значения
        for(int i=0; i<arraySizeInClass; ++i){
            for(int j=0; j<amountOfNumbersInClass; ++j){
                temp.ptr_array[i][j]=ptr_array[j][i];
            }
        }
        ///Удаляем исходный массив
        for(int i=0; i<amountOfNumbersInClass; ++i){
            delete []ptr_array[i];
        }
        ///Пересоздаем исходный массив в другом формате
        ptr_array = new int* [newSize];
        for(int i=0; i<newSize; ++i) {
            ptr_array[i] = new int [newAmountOfNumbers];
        }
        ///Перепимываем указатель на память содержащую новый массив
        ptr_array = temp.ptr_array;
    }

    return *this;
}

int* Matrix::operator[](const int index)const{
    return ptr_array[index];
}
