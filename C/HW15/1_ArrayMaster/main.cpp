#include "header.h"

//copyArray(int m1,int m2, )

int main()
{
    //Здесь я оставлю параметры двумерного массива
    int m1 = 6;
    int m2 = 6;

    //Переменные выбора
    int changeTrigger = 0;
    int trigger = 0;

    int **pm = createFirstMatrix(m1,m2);

    printer(m1,m2,pm);

    cout << "Если хотите добавить в массив СТРОКУ - введите 1 и нажмите ВВОД." << endl << "Если хотите добавить КОЛОНКУ - введите 2" << endl << "Ваш выбор: ";
    cin >> trigger;
    cout << "Введите номер позиции: " << endl;
    cin >> changeTrigger;

     switch(trigger){
        case 1:
        ++m1; //Увеличивает новый массив на одну строку относительно предыдущего
        pm = createNewMatrix(m1,m2,trigger,pm);
        pm = stringMover(m1,m2,pm,changeTrigger);
        break;

        case 2:
        ++m2;//Увеличивает на одну колонку
        pm = createNewMatrix(m1,m2,trigger,pm);
        pm = columnMover(m1,m2,pm,changeTrigger);
        break;

        default:
        cout << "Вы ошиблись, повторите ввод" << endl;

    }
    printer(m1,m2,pm);
    //Удаление памяти
    for(int i=0; i<m1; ++i){
        delete []pm[i];
    }
    delete []pm;

    return 0;
}
