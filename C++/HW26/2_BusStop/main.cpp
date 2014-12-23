#include "ClassBus.h"
#include "BusStop.h"
void checkBus(ClassBus &MassOfBus);

int main(){
    ClassBus bus27(27,20);
    ClassBus bus33(33,40);
    ClassBus bus57(57,0);
    ClassBus bus78(78,10);
    ClassBus bus35(35,45);
    ClassBus MassOfBus[5] = {bus27,bus33,bus57,bus78,bus35};


    return 0;
}

void checkBus(ClassBus &MassOfBus){
    ClassBus temp;
    while(temp.busTime == ){
           temp = MassOfBus[0]
           for(int j=1; j<BusAmount; ++j){ ///Реализация циклической очереди
                MassOfBus[j-1] = MassOfBus[j];
           }
           MassOfBus[BusAmount-1] = temp;
        }
}
