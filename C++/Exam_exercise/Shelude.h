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
			if (open_hour >= -1 && open_hour < 24 && open_minute >= -1 && open_minute < 60 && close_hour >= -1 && close_hour < 24 && close_minute >= -1 && close_minute < 60){
				if (open_hour == -1 && open_minute == -1 && close_hour == -1 && close_minute == -1){
					nullflag = true;
				}
			}
			else{
				throw exception("Error: wrong time format fetched from the shelude file.\n");
			}
		}
		bool getNullFlagStatus(){ return nullflag; }

		bool nullflag = false;
		int open_hour;
		int open_minute;
		int close_hour;
		int close_minute;
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
	map <string, vector <int>> getShelude();

	void setDayTime(const string day, int _open_hour, int _open_minute, int _close_hour, int _close_minute){
		workTime dayTime(_open_hour, _open_minute, _close_hour, _close_minute);
		time[day] = dayTime;
	}
};