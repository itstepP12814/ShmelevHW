#include "header.h"

int recordInFile(int* simpleNumbers, int amountOfNumbers) {
    FILE* filePointer = fopen("numbers_for_you.txt", "w");
    if(filePointer != NULL){
    for(int i=0; i<amountOfNumbers;) {
        fprintf(filePointer, " %d", simpleNumbers[i]);
        ++i;
    }
    fclose(filePointer);
    return 0;
    }
    else {cout << "Ошибка записи в файл" << endl; return 1;}
}
