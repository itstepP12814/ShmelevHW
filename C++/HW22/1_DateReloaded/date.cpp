#include "date.h"

Date::Date()
{
    secondsStore = time(NULL);//Записываем количество секунд в перемунную типа time_t
    actualDate = localtime(&secondsStore); //Переписываем данные в структуру tm
    strftime(showDate,9, dateFormat, actualDate);//Записываем отформатированные данные
 cout << "Timer activated.\n";
}

Date::Date(time_t newSeconds)
{
    secondsStore = newSeconds; //здесь задаем произвольное число секунд
    actualDate = localtime(&secondsStore);
    strftime(showDate,9, dateFormat, actualDate);
}

Date::~Date()
{
    cout << "\nEnd Times...";
}

   const void Date::datePrinter()const{
    cout << showDate << endl;
}

const Date Date::operator+(const int &daysAdd)const{
    time_t seconds = daysAdd*24*60*60;
    time_t tempSeconds = this->secondsStore+seconds;
    Date tempObj(tempSeconds);//инициализируем временный объект необходимым количеством секунд
    return tempObj;
}

const int Date::operator-(const Date& dateTwo)const{
    time_t resultSeconds = this->secondsStore - dateTwo.secondsStore;
    int tempDays = ((resultSeconds/60)/60)/24;
    return tempDays;
}
