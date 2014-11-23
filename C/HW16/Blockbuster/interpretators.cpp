#include "header.h"

void ratePrintInterpretator(int str) {

    const char* rateDescriptions[3] = {"Плохо","Хорошо","Отлично"};
    if ((str < 0)||(str > 2)) {
        cout << "Ошибка интерпретации рейтинга";
    }
    else {
        cout << rateDescriptions[str];
    }
}

void genrePrintInterpretator(int str) {
    const char* genrDescriptions[5] = {"Боевик","Вестерн","Криминал","Документальный","Мелодрама"};
    if ((str < 0)||(str > 4)) {
        cout << "Ошибка интерпретации жанра";
    }
    else {
        cout << genrDescriptions[str];
    }
}
