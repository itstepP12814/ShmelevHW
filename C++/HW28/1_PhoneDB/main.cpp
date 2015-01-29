#include "DataBase.h"
int main()
{
    DataBase yellowPages;
    yellowPages["10"]->phoneNumber[0] = "+375447265842";
    yellowPages["10"]->phoneNumber[1] = "+375443743847";
    yellowPages["10"]->phoneNumber[2] = "+375255495897";
    yellowPages["1"];
    yellowPages["15"];
    yellowPages["11"]->phoneNumber[0] = "+75657784747";
    yellowPages["12"];
    yellowPages["20"];

    yellowPages.showAll(yellowPages.getRoot());
    yellowPages.delNode("11");
    yellowPages.showAll(yellowPages.getRoot());
    return 0;
}
