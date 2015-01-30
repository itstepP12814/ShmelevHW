/**
������� ���������� ���������� ��� ������������� ��������� ��������:
1. ���������� ��������� � ����.
2. �������� ��������� �� ����.
3. ����������� ������ ��������.
4. ����� ��������� �� ����������� ������ ��� �������.
5. ���������� � ���������� ������� ��������� �� ��������� ��������� ������� ��� �������; ��������, ��� ������� �������� ����� ����: 222222 - 333333, � ��� �������: ���������� - ������ (�� ���� ������� � �������� �� ������).
6. ����������� ���������� ��������� ���������� � ����.
7. ���������� ���� � ����.
8. �������� ���� �� �����.
*/

#include "DataBase.h"
/**---------------------����������\������ ������� (����)-------�� �������� ��� ������������ ������-------------
bool saveDataBase(DataBase* object){
    ofstream output("PhoneDataBase.db", std::ios::binary);
    output.write(reinterpret_cast<char*>(&object), sizeof(object));
    if(output){
        output.close();
        return true;
    }
    else{
        return false;
    }
}

bool readDataBase(DataBase* object){
    ifstream input("PhoneDataBase.db", std::ios::binary);
    input.read(reinterpret_cast<char*>(&object), sizeof(object));
    if(!input){std::cerr<<"File not found"; return false;}
    if(input){
        input.close();
        return true;
    }
    else{
        return false;
    }
}
---------------------------------------------------------------*/

int main()
{
    DataBase yellowPages;
    DataBase test;

/*
    yellowPages["Gavrila"]->phoneNumber[0] = "+375447265842";
    yellowPages["Gavrila"]->phoneNumber[1] = "+375443743847";
    yellowPages["Gavrila"]->phoneNumber[2] = "+375255495897";
    yellowPages["Innokentii"];
    yellowPages["Larisa"];
    yellowPages["Diana"]->phoneNumber[0]= "+375255495895";
    yellowPages["Konstantin"];
    yellowPages["Evgeniy"];
    */

    //yellowPages.delNode("11");
    yellowPages.showAll(yellowPages.getRoot());
    int check;
    //check = (yellowPages.saveDB(yellowPages.getRoot()));
    //cout << check << endl;
    check = test.readDB(test.getRoot());
    cout << check << endl;
    test.showAll(test.getRoot());
    return 0;
}

