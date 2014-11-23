#include "group.h"
#include "student.h"
Group::Group()
{
    static int COMMON_GROUP_AMOUNT = 0;

    cout << "Enter size of group: ";
    cin >> maxAmountOfStudents;//Вводим количество студентов в группе

    members = new Student[maxAmountOfStudents]; //Выделяем динамическую память (констуктор должен быть без параметров!)
    addStudent(); //Добавляем данные

    ++COMMON_GROUP_AMOUNT; //Считаем номер группы
    numberOfGroup = COMMON_GROUP_AMOUNT;
    cout << "Group #" << numberOfGroup << " was created.\n";
}

void Group::addStudent(){
    for(int i=0; i<maxAmountOfStudents; ++i) {
        cout << "Enter name:\n";
        cin >> members[i].nameOfStudent;
        cout << "Enter height:\n";
        cin >> members[i].height;
        cout << "Enter weight:\n";
        cin >> members[i].weight;
        cout << "Enter iq:\n";
        cin >> members[i].iq;
    }
}

int Group::getAmountOfStudents(){
    return maxAmountOfStudents;
}

Group::~Group()
{
    delete []members; //Удаляем динамическую память
    cout << "Group # " << numberOfGroup << " was dissolved\n";
}
