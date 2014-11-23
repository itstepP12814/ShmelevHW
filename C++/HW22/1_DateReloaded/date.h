#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
using namespace std;

class Date
{
    public:
        Date();
        Date(time_t newSeconds); //����������� ��������� ������ � ������������ ������� ����������� ������, ����������� ����
        virtual ~Date();

        const void datePrinter()const;

        const int operator-(const Date& dateTwo)const;//���������� ������
        const Date operator+(const int& daysAdd)const; //���������� ��������� �����
    private:
        time_t secondsStore; //��� ��������� ���������� ������ � 70�
        tm* actualDate; //��������� ��� �������������� ������ � �������
        char* dateFormat = "%d/%m/%y"; //������ ������� ������ �������
        char showDate[9]; //���������� ��� ������ �������
};

#endif // DATE_H
