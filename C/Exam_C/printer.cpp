#include "header.h"

void printer(int* simpleNumbers, int amountOfNumbers) {
    for(int i=0; i<amountOfNumbers; ++i) {
        cout << simpleNumbers[i] << " ";
    }
    cout << endl << "Так же данные сохранены в файле numbers_for_you.txt" << endl;
}
