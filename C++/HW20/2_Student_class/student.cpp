#include "student.h"
#include "group.h"

Student::Student()
{
   cout << "Student with empty profile was added.\n";
}

Student::~Student()
{
    cout << "Student's profile deleted\n";
}

void Student::showOneStudent(){
        cout << endl;
        cout << "Name: " << nameOfStudent << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "IQ: " << iq << endl;
        cout << endl;
}
