#include "header.h"
void autoSetTime(void) {
    time_t timer = time(NULL); //получаем количество секунд
    tm* actualTime = localtime(&timer); //формируем структуру tm с текущим временем
    binaryTimer.hours = actualTime->tm_hour; //переносим данные из элементов структуры tm в бинарные поля
    binaryTimer.minutes = actualTime->tm_min;
    binaryTimer.seconds = actualTime->tm_sec;
    triggerIfAuto = 1;
}

void manualSetTime(void) {
    int second, minute, hour;
    cout << "Введите час: ";
    cin >> hour;
    cout << "Введите минуту: ";
    cin >> minute;
    cout << "Введите секунду: ";
    cin >> second;

    binaryTimer.hours = hour; //переносим данные из элементов структуры tm в бинарные поля
    binaryTimer.minutes = minute;
    binaryTimer.seconds = second;
    triggerIfAuto = 0;
}

void timePrint(void) {
    if(triggerIfAuto == 1) {
        autoSetTime();
    }
    char timeOutput[10];
    tm reserve;
    tm* timeInfo = &reserve;//Создал переменную для того чтобы указатель имел выделенную ему область памяти. До этого здесь была проблема
    timeInfo->tm_hour = binaryTimer.hours;
    timeInfo->tm_min = binaryTimer.minutes;
    timeInfo->tm_sec = binaryTimer.seconds;

    char* format = "%H:%M:%S"; //задаем формат вывода времени
    strftime(timeOutput,10,format,timeInfo); //Создаем чаровую строку с временеми

    cout << "Время: " << timeOutput << endl;
}

int main() {
    autoSetTime(); //Устанавливаем время первый раз автоматически
    do {
        void (*menu[])(void) = {autoSetTime,manualSetTime,timePrint};

        int choice;
        cout << "1 - Установить время системы" << endl << "2 - Установить время самостоятельно" << endl << "3 - Показать время" << endl;
        cin >> choice;
        --choice;

        menu[choice] ();
    }
    while(1==1);
    return 0;
}
