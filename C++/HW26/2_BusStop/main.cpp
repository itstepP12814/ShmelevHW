#include "ClassBus.h"
#include "BusStop.h"
ClassBus spinBus(ClassBus* MassOfBus);

///Автобусы приходят по расписанию на остановке, сами автобусы находятся в циклической очереди "на дороге"

int main(){
    BusStop station;
    ClassBus bus27(27,10);
    ClassBus bus33(33,20);
    ClassBus bus57(57,30);
    ClassBus bus78(78,40);
    ClassBus bus35(35,55);
    ClassBus MassOfBus[5] = {bus27,bus33,bus57,bus78,bus35};

    ClassBus actualBus;
    int timeOfActualBus;
    bool check = false;
    while(1){
        const tm* actualTime = station.getNowTime();
        if(actualTime->tm_sec == 0){check = true;}
        for(int i=0; i<5 && check == true; ++i){
            actualTime = station.getNowTime();
            ///Автобус прибывает на остановку только если его время совпадает с часами на остановке И если
            ///время автобуса, который стоит на остановке не является временем этого же автобуса
            if(MassOfBus[i].busTime == actualTime->tm_sec && timeOfActualBus != actualTime->tm_sec){
                timeOfActualBus = actualTime->tm_sec;
                cout << "Bus number " << (spinBus(MassOfBus)).busNumber << " on station\n";
            }
        }
    }
    return 0;
}

ClassBus spinBus(ClassBus* MassOfBus){
    ClassBus temp;
        temp = MassOfBus[0];
        for(int j=1; j<5; ++j){ ///Реализация циклической очереди
            MassOfBus[j-1] = MassOfBus[j];
        }
        MassOfBus[5-1] = temp;
        return temp;
}
