#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class MenuItem
{
    public:
        MenuItem(){cout << "MenuItem Created";}
        virtual ~MenuItem(){};

        virtual void operator()(){};
};

class CocoItem:public MenuItem{
    public:
        CocoItem():MenuItem(){cout << "\nNew CocoItem\n";};
        virtual ~CocoItem(){};

        virtual void operator()(){
            printf("Cococo!\n");
        }
};

class GavItem:public MenuItem{
    public:
        GavItem():MenuItem(){cout << "\nNew GavItem\n";};
        virtual ~GavItem(){};

        virtual void operator()(){
            printf("Gav!\n");
        }
};

class ExitItem:public MenuItem{
    public:
        ExitItem():MenuItem(){cout << "\nNew ExitItem\n";};
        virtual ~ExitItem(){};

        virtual void operator()(){
            printf("Bye! Bye!\n");
            exit(0);
        }
};

#endif // MENUITEM_H
