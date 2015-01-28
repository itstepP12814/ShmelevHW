#include "DataBase.h"


int main()
{
    DataBase yellowPages;
    yellowPages["Shmelev"]->phoneNumber[0] = "+375447235842";
    yellowPages["Shmelev"]->phoneNumber[1] = "+375443743847";
    yellowPages["Shmelev"]->phoneNumber[2] = "+375255495897";
    yellowPages["Chistaya"];
    yellowPages["Chehov"];

    for(int i=0; i<3; ++i){
    cout << yellowPages["Shmelev"]->phoneNumber[i] << endl;
    cout << yellowPages["Shmelev"]->name << endl;
    }
    return 0;
}
