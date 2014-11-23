#include "header.h"

void printer(int number, VideoShop* base){
VideoShop movie = base[number];
cout << endl;
cout << "Название: " << movie.moviename << endl;
cout << "Режисер: " << movie.director << endl;
cout << "Жанр: "; genrePrintInterpretator(movie.genre); cout<< endl;
cout << "Рейтинг: "; ratePrintInterpretator(movie.rating); cout << endl;
cout << "Цена: $" << movie.cost << endl << endl;

}

void namePrinter(int number, VideoShop* base){
VideoShop movie = base[number];
cout << movie.moviename << endl;
}
