#include "header.h"
//Идея: создать массив в который запихнуть харктеристики фильмов и через обращения к нему реализовать вывод, обработку и добаление.
int main()
{
VideoShop* DataBase = createArray();// Создается массив для списка фильмов

//Добавление фильмов-------------------------------------------------------------------------------------
    VideoShop movie1 = {"Lock, Stock & Two Stocking Barrels", "Guy Richi", Criminal, excellent, 15};
    DataBase[1] = movie1;
    VideoShop movie2 = {"Django", "Kventin Tarantino", Western, excellent, 30};
    DataBase[2] = movie2;
    VideoShop movie3 = {"Good, Bad, Evil", "NoBody", Western, good, 35};
    DataBase[3] = movie3;
    VideoShop movie4 = {"Pursuit for happyness", "Joe Lorens", Melodrama, excellent, 30};
    DataBase[4] = movie4;
    VideoShop movie5 = {"BBC Dolphins", "BBC TV", Documental, bad, 8};
    DataBase[5] = movie5;
    VideoShop movie6 = {"Pacific Rim", "Gieljermo Del Toro", Action, good, 17};
    DataBase[6] = movie6;
    VideoShop movie7 = {"Godzilla", "Fox Chaler", Action, good, 20};
    DataBase[7] = movie7;
//----------------------------------------------------------------------------------------------

    // endOfList - переменная начала конца О_о списка базы фильмов
    int endOfList=7;
    int* pointerEndOfList = &endOfList;
    int genre;

//-------------Меню--------------------------------------------------------------
    cout << "Добро пожаловать в Видеомагазин." << endl;
    while(2+2==4){
    int youChoose;
    cout << "------------------------------------------------------------" << endl;
    cout << "\t1 - Просмотреть доступные фильмы" << endl;
    cout << "\t2 - Добавить фильм" << endl;
    cout << "\t3 - Лучшие фильмы в жанре" << endl;
    cout << "\t4 - Поиск" << endl;
    cout << "Введите номер пункта: ";
    cin >> youChoose;

    switch(youChoose){
        case 1:
        showAll(DataBase, &pointerEndOfList);
        break;
        case 2:
        add_New_Movie(DataBase, &pointerEndOfList);
        break;
        case 3:
        chooseGenre(DataBase,&pointerEndOfList);
        break;
        case 4:{
            int searchChoose;
            cout << endl << "РАЗДЕЛ ПОИСКА:" << endl;
            cout << "1 - Поиск фильма по названию" << endl;
            cout << "2 - Поиск фильма по имени режисера" << endl;
            cout << "3 - Поиск фильма по жанру" << endl;
            cout << "Введите номер пункта: ";
            cin >>searchChoose;

            switch(searchChoose){
                case 1:
                searcherMoviename(DataBase,&pointerEndOfList);
                break;
                case 2:
                searcherDirector(DataBase,&pointerEndOfList);
                break;
                case 3:
                searcherGenre(DataBase,&pointerEndOfList);
                break;
                default:
                cout << "Вы неверно выбрали вид поиска" << endl;
                break;
            }
        }
        break;
        default:
        cout << "Вы сделали неверный выбор." << endl << endl;
        break;
    }
}
   delete []DataBase;

   return 0;
}
/*ОБЩАЯ ИДЕЯ ДОБАВЛЕНИЯ:
Создаем массив в который помещаем переменную со структурой VideoShop.
Каждая такая переменная ложится в стек, поэтому есть возмодность
создавать каждый раз новую переменную для каждого вызова функции
добавления фильма.
Затем мы запрашиваем данные у пользователя и ложим их в подпеременные структуры,
под именем вышеописанной переменной. Присваиваем эту переменную ячейке массива.
Затем создаем локальную переменную для вывода в функции printer и присваиваем ей
значение ячейки. Выводим отдельные элементы структуры.
*/
