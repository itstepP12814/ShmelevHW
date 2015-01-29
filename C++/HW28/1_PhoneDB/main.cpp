#include "DataBase.h"
int main()
{
    DataBase yellowPages;
    yellowPages["1"]->phoneNumber[0] = "+375447265842";
    yellowPages["1"]->phoneNumber[1] = "+375443743847";
    yellowPages["1"]->phoneNumber[2] = "+375255495897";
    yellowPages["2"];
    yellowPages["3"];

    yellowPages.showAll(yellowPages.getRoot());
    yellowPages.delNode("3");
    yellowPages.showAll(yellowPages.getRoot());
    return 0;
}
