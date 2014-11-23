#include "header.h"

int main()
{

    int amountOfNumbers;
    cout << "Введите желаемое количество простых чисел (число): ";
    cin >> amountOfNumbers;

    int* simpleNumbers = (int*) malloc (amountOfNumbers*sizeof(int));

    simpleNumberGenerator(simpleNumbers, amountOfNumbers);
    int successOfRecord = recordInFile(simpleNumbers, amountOfNumbers);
    if(successOfRecord == 0){
    printer(simpleNumbers,amountOfNumbers);
    }

    free(simpleNumbers);

    return 0;
}
