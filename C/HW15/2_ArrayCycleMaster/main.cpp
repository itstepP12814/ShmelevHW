#include "header.h"

//copyArray(int m1,int m2, )

int main() {
    //Здесь я оставлю параметры двумерного массива
    int m1 = 6;
    int m2 = 6;

    //Переменные выбора
    int kuda = 0;
    int to = 0;
    int trigger = 0;

    int **pm = createMatrix(m1,m2);

    printer(m1,m2,pm);

    cout << "Что будем двигать? (1 - СТОЛБЦЫ, 2 - СТРОКИ): " << endl;
    cin >> trigger;
    cout << "Укажите куда будем двигать? ";
    if(trigger == 1) {
        cout << "(1 - ВЛЕВО, 2 - ВПРАВО): " << endl;
    }
    else {
        if(trigger == 2) {
            cout << "(1 - ВВЕРХ, 2 - ВНИЗ): " << endl;
        }
    };
    cin >> kuda;
    cout << "Сколько элементов сдвинем? Введите: " << endl;
    cin >> to;
    ++to;

    switch(trigger)
    {
    case 1:
        pm = shiftColumns(m1,m2,pm,to,kuda);
        break;

    case 2:
        pm = shiftRows(m1,m2,pm,to,kuda);
        break;

    default:
        cout << "Вы ошиблись, повторите ввод" << endl;

    }
    printer(m1,m2,pm);
    //Удаление памяти
    for(int i=0; i<m1; ++i) {
        delete []pm[i];
    }
    delete []pm;

    return 0;
}
