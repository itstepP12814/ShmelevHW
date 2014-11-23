#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3
#define NAMESIZE 50

using namespace std;

struct quiz {
    char name[NAMESIZE];
    int age;
};

int compareByAge(const void* a, const void* b) {
    const struct quiz quizA = *(const struct quiz*)a;
//Здесь мы объясняем нашей функции какого типа указатель мы передали, поскольку qsort ничерта об этом не знает и не передает
    const struct quiz quizB = *(const struct quiz*)b;
    return (quizA.age-quizB.age);
}

int compareByName(const void* a, const void* b){
    const struct quiz quizA = *(const struct quiz*)a;
    const struct quiz quizB = *(const struct quiz*)b;
    return strcmp(quizA.name,quizB.name);
    /*Приводим полученные указатели к реальному используемому типу,
    затем используем функцию для сравнения строк, возвращаем её значение в
    qsort*/
}

void printer(quiz ankety[]) {
    for(int i=0; i<3; ++i) {
        cout << "Анкета: " << ankety[i].name << endl;
        cout << "Возраст: " << ankety[i].age << endl;
        cout << endl;
    }
}

//Отсортировать по имени и по возрасту
int main()
{
    quiz ankety[SIZE];

    cout << "Введите данные в анкеты: " << endl;

    for(int i=0; i<SIZE; ++i) {
        cout << "Введите имя: ";
        cin >> ankety[i].name;
        cout << "Введите возраст: ";
        cin >> ankety[i].age;
        cout << endl;
    }

    printer(ankety);

    cout << "Сортируем по возрасту: " << endl;
    qsort(ankety, SIZE, sizeof(quiz), compareByAge);
    printer(ankety);

    cout << "Сортируем по имени: " << endl;
    qsort(ankety, SIZE, sizeof(quiz), compareByName);
    printer(ankety);

    return 0;
}
