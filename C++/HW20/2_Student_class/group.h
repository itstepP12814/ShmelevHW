#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Group
{
  //constexpr int COMMON_GROUP_AMOUNT = 0; //Ошибка: constexpr не является типом, проблема поддержки компилятора?
    public:
        Group();
        ~Group();
       Student* members;
       void addStudent();
       int getAmountOfStudents();

    protected:
        int numberOfGroup;
        int maxAmountOfStudents;
};

#endif // GROUP_H
