#include "student.h"
#include "group.h"

void showStudents(Group& group){ //Функция отвечает за вывод всех студентов группы на экран, призвана решить проблему наследование+массив
    int amountOfStudents = group.getAmountOfStudents();
    for(int i=0; i<amountOfStudents; ++i){
    group.members[i].showOneStudent();
    }
}

int main()
{
    Group first;
    showStudents(first);
    return 0;
}
