#include "header.h"

VideoShop* createArray(void) {
    int stringSize = 128;
    VideoShop *pm;
    int m1 = 100; //количество фильмов

    //Выделение памяти
    pm = new VideoShop[m1];

    return pm;
}
