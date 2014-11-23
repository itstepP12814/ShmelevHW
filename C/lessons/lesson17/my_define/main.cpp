#include "header.h"

int main()
{
    char buffer[500];
    int amountOfDefines = sizeCalculateForDefineArray();
    defineStruct* defineUnit = (defineStruct*) malloc (amountOfDefines*sizeof(defineStruct));
    inFileSearch(defineUnit, amountOfDefines);


    for(int i=0; i<amountOfDefines; ++i){
        cout << "Имя: " << defineUnit[i].nameOfDirrective << endl << "Значение: " << defineUnit[i].valueOfDirrective << endl;
    }

    free(defineUnit);
    return 0;
}
