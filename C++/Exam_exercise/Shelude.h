#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std; 

class Shelude
{
private:
	class workTime{ //Время открытия и закрытия заведения
	public:
		workTime(int _open_hour, int _open_minute, int _close_hour, int _close_minute) :
			open_hour(_open_hour), open_minute(_open_minute), close_hour(_close_hour), close_minute(_close_minute)
		{
			open_time->tm_hour = open_hour;
			open_time->tm_min = open_minute;
			open_time->tm_hour = close_hour;
			open_time->tm_hour = close_minute;
		}
	private:
		int open_hour;
		int open_minute;
		int close_hour;
		int close_minute;

		tm* open_time;
		tm* close_time;
	};
	const int numberDaysInWeek = 7;
	map <string, workTime> time;
public:

	Shelude(){//Здесь следует передавать имя файла расписания для конкретного заведения
		//По задумке должен читать CSV файл, с расписанием 
		vector <string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
		for (pair <string, workTime> p : time){
			for (vector<string>::iterator itr = daysOfWeek.begin(); itr != daysOfWeek.end(); ++itr){
				//Перебираем дни недели, присваиваем их дереву соответсвия день-время
				p.first = *itr;
				workTime dayTime(_open_hour, _open_minute, _close_hour, _close_minute);
			}
		}
	}
	~Shelude(){}

	void setDayTime(const string day, int _open_hour, int _open_minute, int _close_hour, int _close_minute){
		workTime dayTime(_open_hour, _open_minute, _close_hour, _close_minute);
		time[day] = dayTime;
	}
};

