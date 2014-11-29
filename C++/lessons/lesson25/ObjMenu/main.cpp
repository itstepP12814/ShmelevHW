#include "menuitem.h"

int main()
{
    unsigned char z;
    MenuItem* x[256];
    for(int i=0; i<=256; ++i){
        x[i]=NULL;
    }
    x['1']=new CocoItem();
    x['2']=new GavItem();
    x['B']=new ExitItem();
    //x['b']=ExitItem();
    while(1) {
        cin >> z;

        if(x[z]!=NULL) {
            ///x[z]->operator()();  ИЛИ

            ///MenuItem& item = *x[z];
            ///item(); ИЛИ
            (*x[z])();
        }
    }

    for(int i=0; i<=256; ++i){
        if(x[i]!=NULL){
            delete x[i];
        }
    }
    return 0;
}

