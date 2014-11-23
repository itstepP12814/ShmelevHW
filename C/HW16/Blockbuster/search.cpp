#include "header.h"

void searcherMoviename(VideoShop* DataBase, int** endOfLine) {
    char key[128];
    int checker = 0;
    cout << "Поиск по названию фильма." << endl;
    cout << "Введите запрос для поиска: ";
    cin >> key;

    for(int i=0; i<=(**endOfLine); ++i) {
        if(strstr(DataBase[i].moviename, key)) {
            printer(i,DataBase);
            ++checker;
        }
    }
    if(checker==0){cout << "Ничего не найдено." << endl;}
}

void searcherDirector(VideoShop* DataBase, int** endOfLine) {
    char key[128];
    int checker = 0;
    cout << "Поиск по имени режисера." << endl;
    cout << "Введите запрос для поиска: ";
    cin >> key;

    for(int i=0; i<=(**endOfLine); ++i) {
        if(strstr(DataBase[i].director, key)) {
            printer(i,DataBase);
            ++checker;
        }
    }
    if(checker==0){cout << "Ничего не найдено." << endl;}
}

void searcherGenre(VideoShop* DataBase, int** endOfLine) {
    int key;
    int checker = 0;
    cout << "Поиск по жанру." << endl;
    cout << "Выберите жанр: Боевик (1), Вестерн(2), Криминал(3), Документальный(4), Мелодрама(5)" << endl;
    cin >> key; --key;

    for(int i=0; i<=(**endOfLine); ++i) {
        if(DataBase[i].genre == key) {
            printer(i,DataBase);
            ++checker;
        }
    }
    if(checker==0){cout << "Ничего не найдено." << endl;}
}
