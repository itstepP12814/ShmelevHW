#include "slotmachine.h"

char slotLine::spin(){
    this->randomGen();
    if(symbols){
        for(int i=0; i<spinTimes; ++i){ ///Вращаем барабан столько раз сколько сгенерировалось число
           char temp = symbols[0];
           for(int j=1; j<amountOfSymbols; ++j){ ///Реализация циклической очереди
                symbols[j-1] = symbols[j];
           }
           symbols[amountOfSymbols-1] = temp;
        }
        return symbols[0];
    }
    else{
        return NULL;
    }
}

char slotLine::getSymbol(){
    return symbols[0];
}

void slotLine::randomGen(){
    srand(time(NULL));
    spinTimes = rand()%100;
}
