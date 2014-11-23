#include "header.h"

int* simpleNumberGenerator(int* simpleNumbers, int amountOfNumbers){
    int number = 2;
    int separator;
    int counterOfSimpleNumbers = 1;

    for(number; counterOfSimpleNumbers<amountOfNumbers;) {
        simpleNumbers[0]=2;
        ++number;
        separator = number;
        int checker = 0;

        for(separator-=1; separator>1; --separator) {
            if(number%separator) {
                continue;
            }
            else {
                checker = 1;
                break;
            }
        }

        if(checker != 1) {
            simpleNumbers[counterOfSimpleNumbers] = number;
            ++counterOfSimpleNumbers;
        }
    }

    return simpleNumbers;
}
