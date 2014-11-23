#include "date.h"

Date::Date()
{
    secondsStore = time(NULL);//���������� ���������� ������ � ���������� ���� time_t
    actualDate = localtime(&secondsStore); //������������ ������ � ��������� tm
    strftime(showDate,9, dateFormat, actualDate);//���������� ����������������� ������
 cout << "Timer activated.\n";
}

Date::Date(time_t newSeconds)
{
    secondsStore = newSeconds; //����� ������ ������������ ����� ������
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
    Date tempObj(tempSeconds);//�������������� ��������� ������ ����������� ����������� ������
    return tempObj;
}

const int Date::operator-(const Date& dateTwo)const{
    time_t resultSeconds = this->secondsStore - dateTwo.secondsStore;
    int tempDays = ((resultSeconds/60)/60)/24;
    return tempDays;
}
