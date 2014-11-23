#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
using namespace std;

class Date
{
    public:
        Date();
        Date(time_t newSeconds); //конструктор создающий обьект с определенным заранее количеством секунд, расчитывает дату
        virtual ~Date();

        const void datePrinter()const;

        const int operator-(const Date& dateTwo)const;//перегрузка минуса
        const Date operator+(const int& daysAdd)const; //перегрузка бинарного плюса
    private:
        time_t secondsStore; //тут храниться количество секунд с 70х
        tm* actualDate; //структура для упорядочивания данных о времени
        char* dateFormat = "%d/%m/%y"; //строка формата вывода времени
        char showDate[9]; //переменная для вывода времени
};

#endif // DATE_H
