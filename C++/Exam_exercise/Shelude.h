#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std; 

class Shelude
{
private:
	const int numberDaysInWeek = 7;
	map <vector<string>, tm*> time;
	struct tm* workTime;
public:

	Shelude(){
		vector <string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
		for (pair <vector<string>, tm*> p : time){
			for (vector<string>::iterator itr = daysOfWeek.begin(); itr != daysOfWeek.end(); ++itr){
				p.first.push_back(*itr);
			}
		}
	}
	
	~Shelude(){}
};

