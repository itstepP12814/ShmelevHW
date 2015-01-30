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

bool DataBase::saveDB(Item* node){
    ofstream output("PhoneDataBase.txt", std::ios::out);
    if(output){
        saveFunction(node, output);
        output.close();
        return true;
    }
    else{
        return false;
    }
}

void DataBase::saveFunction(Item* node, ofstream& output){
    if(node){
    saveFunction(node->left, output);
    output << "Name: " << node->name << "\r\n";
    for(int i=0; i<3;i++){
        if(!(node->phoneNumber[i].empty())){
            output << "Phone: " << node->phoneNumber[i] << "\r\n";
        }
    }
    saveFunction(node->right, output);
    }
}

bool DataBase::readDB(Item* node){
    string str;
    string name;
    int i = 0;
    ifstream input("PhoneDataBase.txt", std::ios::in);
    if(input){
        while(!input.eof()){
        input >> str; //Получаем слово
        if(!(str.find("Name:"))){
            input >> str; //Получаем собственно имя
            //cout << str << endl;
            operator[](str);
            name = str;
            i=0;
        }
        else{
                if(!(str.find("Phone:"))&&i<3){
                    input >> str;
                    Item* object = operator[](name);
                    object->phoneNumber[i]={str};
                    ++i;
                    if(i==3){i=0;}
                }
            }
        }

        input.close();
        return true;
    }
    else{
        return false;
    }
}

