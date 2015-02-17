#include "ClassBus.h"
#include "BusStop.h"
void spinBus(ClassBus* MassOfBus);

///јвтобусы приход€т по расписанию на остановке, сами автобусы наход€тс€ в циклической очереди "на дороге"

int main(){
    srand(time(NULL));
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
        if(actualTime->tm_sec == 0){check = true;} ///ѕроверка дл€ запуска автобусов только с 00 секунды.
        for(int i=0; i<5 && check == true; ++i){
            actualTime = station.getNowTime();
            ///јвтобус прибывает на остановку только если его врем€ совпадает с часами на остановке » если
            ///врем€ автобуса, который стоит на остановке не €вл€етс€ временем этого же автобуса
            if(MassOfBus[i].busTime == actualTime->tm_sec && timeOfActualBus != actualTime->tm_sec){
                timeOfActualBus = actualTime->tm_sec;
                cout << "Bus number " << MassOfBus[0].busNumber << " on station\n";
                cout << "Passengers on station: " << station.amountOfPassangers << endl << "Passengers in bus: " << MassOfBus[0].amountOfPassengers << endl << "Unboarding in progress\n";
                ///ѕроизводим высадку пассажиров
                if(MassOfBus[0].amountOfPassengers !=0){
                int pasGone = rand()%MassOfBus[0].amountOfPassengers;
                MassOfBus[0].amountOfPassengers -= pasGone;
                cout << pasGone << " passengers gone from bus\n";
                }
                ///ѕроизводим посадку пассажиров
                cout << "Boarding in progress\n";
                while(MassOfBus[0].amountOfPassengers<=MassOfBus[0].maxPassengers && station.amountOfPassangers != 0){
                    ++MassOfBus[0].amountOfPassengers;
                    --station.amountOfPassangers;
                }
                cout << "Passengers in bus: " << MassOfBus[0].amountOfPassengers << endl;
                cout << "Boarding completed. On station " << station.amountOfPassangers << " passengers\n\n";
                ///Ќа остановку приход€т новые люди
                station.amountOfPassangers += rand()%20;

                spinBus(MassOfBus);
            }
        }
    }
    return 0;
}

void spinBus(ClassBus* MassOfBus){
    ClassBus temp;
        temp = MassOfBus[0];
        for(int j=1; j<5; ++j){ ///–еализаци€ циклической очереди
            MassOfBus[j-1] = MassOfBus[j];
        }
        MassOfBus[5-1] = temp;
}
