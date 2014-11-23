#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        Student();
        ~Student();
        string nameOfStudent;
        //void showStudents();
        void showOneStudent();
        int height;
        int weight;
        int iq;
};

#endif // STUDENT_H
