#include "header.h"


int** stringMover(int m1, int m2, int **pm, int changeTrigger){
--changeTrigger; //Корректировка для юзабилити

for(int i = m2; i!=changeTrigger; --i){ //Меняет местами строки
    int* ppm = pm[i]; //Использовал указатели, т.к. присвоение элементов массива другим элементам массива не сработало.
    pm[i] = pm[i-1]; //i указывает на номер строки
    pm[i-1] = ppm;
    }
    return pm;
}
