#include "header.h"

void showAll(VideoShop* DataBase, int ** endOfList) {
    for(int i=1; i<=(**endOfList); ++i) {
        printer(i, DataBase);
    }
}

void chooseGenre(VideoShop* DataBase, int**endOfList) {
    cout << "Выберите жанр: Боевик (1), Вестерн(2), Криминал(3), Документальный(4), Мелодрама(5)" << endl;
    int genre;
    cin >> genre; --genre;

    VideoShop* GenreBase = new VideoShop[100];
    for(int i=1; i<(**endOfList); ++i) {
        if(DataBase[i].genre == genre) {
            GenreBase[i] = DataBase[i];
        }
    }
    showBest(&*endOfList, GenreBase);
}

void showBest(int **endOfList, VideoShop* GenreBase) {
    int* goodMovies = new int[100];

    int max_rating = -1;//Проверяю какой рейтинг в жанре максимальный
    for(int i=1; i<=(**endOfList); ++i) {
        if(GenreBase[i].rating>max_rating) {
            max_rating = GenreBase[i].rating;
        }
    }
    cout << "Лучшие фильмы в жанре:" << endl;
    for(int i=1; i<=(**endOfList); ++i) {
        if(GenreBase[i].rating == max_rating){
            namePrinter(i, GenreBase);
        }
    }

}

//Отфильтровать все фильмы по искомому жанру и выделить их номера в отдельный массив, который передать в эту функцию
//Тут проверить максмальный рейтинг фильмов и вывести фильмы с макс. рейтингом
