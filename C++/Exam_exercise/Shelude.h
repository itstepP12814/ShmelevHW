#pragma once
#include <time.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std; 

class Entertainment;

class Shelude
{
private:
	class workTime{ //Время открытия и закрытия заведения
	public:
		workTime():
			open_hour(0), open_minute(0), close_hour(0), close_minute(0)
		{}
		workTime(int _open_hour, int _open_minute, int _close_hour, int _close_minute) :
			open_hour(_open_hour), open_minute(_open_minute), close_hour(_close_hour), close_minute(_close_minute)
		{
			open_time.tm_hour = open_hour;
			open_time.tm_min = open_minute;
			close_time.tm_hour = close_hour;
			close_time.tm_min = close_minute;
			/*cout << open_time.tm_hour << endl;
			cout << open_time.tm_min << endl;
			cout << close_time.tm_hour << endl;
			cout << close_time.tm_hour << endl;*/
		}
		tm getOpenTime(){ return open_time; }
		tm getCloseTime(){ return close_time; }
	protected:
		int open_hour;
		int open_minute;
		int close_hour;
		int close_minute;

		tm open_time;
		tm close_time;
	};

	vector<workTime> arrayOfTime;
	bool Shelude::readSheludeFile(const string filename);

	const int numberDaysInWeek = 7;
	map <string, workTime> time;
	workTime* timeInfo;

protected:
	Shelude(const string filename);
	~Shelude(){}

public:
	friend Entertainment;
	map <string, vector <tm>> getShelude();

	void setDayTime(const string day, int _open_hour, int _open_minute, int _close_hour, int _close_minute){
		workTime dayTime(_open_hour, _open_minute, _close_hour, _close_minute);
		time[day] = dayTime;
	}
};