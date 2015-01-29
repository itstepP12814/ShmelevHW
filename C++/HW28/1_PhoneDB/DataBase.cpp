#include "DataBase.h"

void DataBase::printData(Item* node){
    cout << node->name << endl;
    int check = 0;
    for(int i=0; i<3; ++i){
        if(!node->phoneNumber[i].empty()){
        cout << "\t" << node->phoneNumber[i] << endl;
        }
        else{
            if(check==0){
            cout << "No phone number.\n";
            ++check;
            }
        }
    }
    cout << endl;
}

