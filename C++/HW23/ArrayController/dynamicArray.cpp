#include "dynamicArray.h"

dynamicArray::dynamicArray() { ///Стандартный констурктор
    nameArray = new string[amountOfStrings];
    arraySize = amountOfStrings;
    if(!nameArray){
        cout << "Memory don't allocated\n";
    }
    length=0;
    nameArray[0]='\0';
    cout << "Created empty array\n";
    actualSize = 0;
}

dynamicArray::dynamicArray(const string str) { ///Констуктор с первой строкой

    nameArray = new string[amountOfStrings];
    arraySize = amountOfStrings;
    if(!nameArray) {
        cout << "Memory don't allocated\n";
        exit(1);
    }
    nameArray[0] = str;
    cout << "Created array with first element: " << nameArray[0] << " and use " << str.length() << " chars\n";
    actualSize = 1;
}

dynamicArray::dynamicArray(const int localSize) { ///Констуктор с преопределенным размером

    nameArray = new string[localSize];
    if(!nameArray) {
        cout << "Memory don't allocated\n";
        exit(1);
    }
    for(int i=0; i<localSize; ++i) {
        nameArray[i]='\0';
    }
    cout << "Created array with " << localSize << " empty cells\n";
    actualSize = localSize;
    arraySize = localSize;
}

/*
dynamicArray::dynamicArray(const dynamicArray& original){///Констуктор копирования
    nameArray = new string[original.actualSize];
    for(int i=0; i<actualSize; ++i){
        nameArray[i]=original.nameArray[i];
    }
}
*/

string& dynamicArray::operator[](const int j)const {
    return nameArray[j];
}

const string& dynamicArray::operator=(const string str)const {
    return str;
}

dynamicArray dynamicArray::operator+(const dynamicArray& secondArray)const {

    dynamicArray bigArray(actualSize+secondArray.actualSize);///Инициализируем объект размерами двух исходных

    for(int i=0; i<bigArray.actualSize; ++i) {
        int j=0;
        if(i<actualSize) {
            bigArray.nameArray[i]=nameArray[i];
        }
        if(i>=actualSize) {
            bigArray.nameArray[i]=secondArray.nameArray[j];
            ++j;
        }
    }
    return bigArray;
}

void dynamicArray::printArray() {
    cout << endl;
    for(int i=0; i<arraySize; ++i) {
        if(nameArray[i].size()) //Проверка на случай пустых строк
        cout << nameArray[i] << endl;
    }
    cout << endl;
}

dynamicArray& dynamicArray::operator--(){
    cout << "ActualSize = " << actualSize << endl;
    int newSize = actualSize-1;
    cout << "NewSize = " << newSize << endl;
        string* tempArray = new string[actualSize]; //Выделяем память под временное хранилище
        if(tempArray){
            for(int i=0; i<actualSize; ++i){
                tempArray[i]=nameArray[i]; //Переписываем исходный массив в хранилище
            }
            delete []nameArray; //Удаляем исходный массив

            nameArray = new string[newSize]; //Перевыделяем память под оригинал
            if(nameArray) {
            arraySize = newSize; //Задаем новый размер оригинального массива

                for(int i=0; i<newSize; ++i){
                    nameArray[i] = tempArray[i]; //Возвращаем массив на место
                }
                actualSize=newSize; //Обновляем информацию о размере содержимого
            }
            else {
                //Восстанавливаем исходный массив в случае неудачи
                string* nameArray = new string[actualSize];
                for(int i=0; i<actualSize; ++i) {
                nameArray[i] = tempArray[i];
                }
                cout << "Memory not allocated.\nOriginal array restored.\n";
            }
            delete []tempArray;
            return *this;
        }
        else {
            cout << "Memory not allocated\n";
        }
    }

dynamicArray& dynamicArray::operator++(){
    cout << "ActualSize = " << actualSize << endl;
    int newSize = actualSize+1;
    cout << "NewSize = " << newSize << endl;
    if(newSize<arraySize) { //Вариант, когда места достаточно
        for(int i=actualSize; i<newSize; ++i) {
            string tempString;
            cin >> tempString;
            nameArray[i]=tempString;
        }
        actualSize = newSize;
        return *this;
    }
    else { //Вариант, когда места не хватает
        string* tempArray = new string[actualSize]; //Выделяем память под временное хранилище
        if(tempArray){
            for(int i=0; i<actualSize; ++i){
                tempArray[i]=nameArray[i]; //Переписываем исходный массив в хранилище
            }
            delete []nameArray; //Удаляем исходный массив

            nameArray = new string[newSize]; //Перевыделяем память под оригинал
            if(nameArray) {
            arraySize = newSize;

                for(int i=0; i<actualSize; ++i) {
                    nameArray[i] = tempArray[i]; //Возвращаем массив на место
                }
                for(int i=actualSize; i<arraySize; ++i) {
                   cin >> nameArray[i];
                }
                actualSize=newSize;
            }
            else {
                //Восстанавливаем исходный массив в случае неудачи
                string* nameArray = new string[actualSize];
                for(int i=0; i<actualSize; ++i) {
                nameArray[i] = tempArray[i];
                }
                cout << "Memory not allocated.\nOriginal array restored.\n";
            }
            //
            return *this;
        }
        else {
            cout << "Memory not allocated\n";
        }
    }
}

dynamicArray::~dynamicArray() {
    delete []nameArray;
    cout << "Array canceled\n";
}
