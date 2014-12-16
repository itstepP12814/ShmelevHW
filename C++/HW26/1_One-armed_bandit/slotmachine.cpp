#include "slotmachine.h"

bool slotLine::spin(const int spinTimes){
    if(symbols){
        for(int i=0; i<spinTimes*spinMultiplier; ++i){ ///������� ������� ������� ��� ������� ��������������� �����
           char temp = symbols[0];
           for(int j=1; j<amountOfSymbols; ++j){ ///���������� ����������� �������
                symbols[j-1] = symbols[j];
           }
           symbols[amountOfSymbols-1] = temp;
        }
        return 1;
    }
    else{
        return 0;
    }
}

char slotLine::getSymbol(){
    return symbols[0];
}


slotMachine::slotMachine(){}

slotMachine::~slotMachine(){}

void slotMachine::spin(){
    srand (time(NULL));
    randomNumber = rand()%100;
    ///����� ����� ������� ������ ������� �������
    ///����� �������?
    slotLine::firstBar.spin(randomNumber);
}

void slotMachine::showResult(){
    for(int i=0; i<3; ++i){
        cout << Lines[i].getSymbol();
    }
    cout << endl;
}
