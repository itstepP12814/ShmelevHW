#include "header.h"

VideoShop* add_New_Movie(VideoShop *base_Name_Director, int** endOfList) {
    VideoShop newMovie;
    cout << "Добавление нового фильма в базу." << endl << "Введите название фильма (латинскими): ";
    cin >> newMovie.moviename;
    cout << "Введите имя режисера(латинскими): ";
    cin >> newMovie.director;
    cout << "Выберите жанр: Боевик (1), Вестерн(2), Криминал(3), Документальный(4), Мелодрама(5)" << endl;
    cin >>newMovie.genre; //Как реализовать ввод?
    --newMovie.genre;
    cout << "Как вы оцениваете фильм? Плохо(1), Хорошо(2), Отлично(3):" << endl;
    cin >> newMovie.rating;
    --newMovie.rating;
    cout << "Введите стоимость диска ($): ";
    cin >> newMovie.cost;
    cout << endl;

    **endOfList += 1; //Следующая строка для данных нового фильма
    //Буду складывать переменную со структурой в отдельные ячейки массива чтобы отделить фильмы
    base_Name_Director[**endOfList] = newMovie;

    return base_Name_Director;
}


