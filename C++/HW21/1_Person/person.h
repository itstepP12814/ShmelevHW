#ifndef PERSON_H
#define PERSON_H
#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h> //функция Exit()
using namespace std;
class Person
{
    public:
        Person();
        ~Person();
        void print();
        void editProfile(int);
    private:
        string nameOfPerson;
        int age;
        int sexOfPerson;
        int phoneNumber;
};

#endif // PERSON_H
