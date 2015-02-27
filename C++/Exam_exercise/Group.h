#pragma once
#include "Entertainment.h"

class Group
{
public:

	Group(const int amount, const string day, tm& _freeTimeFrom, tm& _freeTimeAt) :
		numberOfFriends(amount), freeDay(day), freeTimeFrom(&_freeTimeFrom), freeTimeAt(&_freeTimeAt)
	{
	}

	~Group()
	{
	}

	template <class T> string checkEvalue(T obj){
		map <string, vector <int>> org_time = obj.getOrgShelude();
		for (auto p : org_time){
			string weekDay = p.first;
			if (weekDay == freeDay){
				if (p.second[0] == -1){
					continue;
				}
				else{
					struct tm opentime;
					struct tm closetime;
					opentime.tm_hour = p.second[0];
					opentime.tm_min = p.second[1];
					closetime.tm_hour = p.second[2];
					closetime.tm_min = p.second[3];
					const tm* c_opentime = &opentime;
					const tm* c_closetime = &closetime;

					int first = freeTimeFrom->tm_hour - c_closetime->tm_hour;
					int second = c_opentime->tm_hour - freeTimeAt->tm_hour;
					if ((first + second) >= 0){
						if (numberOfFriends <= obj.getCapacity()){
							return obj.getName();
						}
					}
				}
			}
		}
		return obj.getName() + ": Closed at this time.\n";
	}
private:
	int numberOfFriends;
	string freeDay;
	tm* freeTimeFrom;
	tm* freeTimeAt;
};