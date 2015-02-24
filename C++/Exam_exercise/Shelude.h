#pragma once
#include <time.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std; 

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
			close_time.tm_hour = close_minute;
			/*cout << open_time.tm_hour << endl;
			cout << open_time.tm_min << endl;
			cout << close_time.tm_hour << endl;
			cout << close_time.tm_hour << endl;*/
		}

		vector <const tm*> getTime(){
			const tm* temp_open = &open_time;
			const tm* temp_close = &close_time;
			vector <const tm*> return_array.push_back(temp_open);
			vector <const tm*> return_array.push_back(temp_close);
			return return_array;
		}
	private:
		int open_hour;
		int open_minute;
		int close_hour;
		int close_minute;

		tm open_time;
		tm close_time;
	};

	vector<workTime> arrayOfTime;

	bool readSheludeFile(const string filename){
		ifstream input(filename, std::ifstream::in);
		if (!input.is_open()){
			throw exception("Error: can't open the file.\n");
		}
		const string bufferDays = "Monday;Tuesday;Wednesday;Thursday;Friday;Saturday;Sunday";
		const string emptyLine = ";;;;;;";
		bool firstTimeFlag = true;
		while (!input.eof()){
			string buffer;
			getline(input, buffer, '\n'); 
			//Если не нашло первую строку с днями недели
			if (buffer.find(bufferDays) == string::npos && firstTimeFlag == true){
				throw exception("Error: wrong file format (database)");
			}
			else{
				if (firstTimeFlag == true){
					firstTimeFlag = false;
					if (!buffer.find(emptyLine)) continue;
					continue;
				}
			}
			firstTimeFlag = false;
			if (!buffer.find(emptyLine)) continue;
			string sequenceForRead = buffer;
			for (string::iterator itr = buffer.begin(); itr != buffer.end() && sequenceForRead != ""; itr+=13){
				int hour_open = -1;
				int min_open = -1;
				int hour_close = -1;
				int min_close = -1;
				int checkParse = sscanf_s(sequenceForRead.c_str(), "%2d:%2d - %2d:%2d", &hour_open, &min_open, &hour_close, &min_close);
				if (checkParse == EOF){

					throw exception("Error: can't read info into cell from the file.\n");
				}
				sequenceForRead.erase(0, 14);
				workTime currentDayTime(hour_open, min_open, hour_close, min_close);
				arrayOfTime.push_back(currentDayTime);
				if (*(itr + 1) == ';'){
					++itr;
				}
			}
		}
		if (arrayOfTime.size() < numberDaysInWeek || arrayOfTime.size() > numberDaysInWeek){
			throw exception("Error: miss or overflow some cells.\n");
		}
		else{
			return true;
		}
	}

	const int numberDaysInWeek = 7;
	map <string, workTime> time;
public:

	Shelude(const string filename){//Здесь следует передавать имя файла расписания для конкретного заведения
		//По задумке должен читать CSV файл, с расписанием 
		vector <string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
		readSheludeFile(filename);
		for (pair <string, workTime> p : time){
			vector<workTime>::iterator t_itr = arrayOfTime.begin();
			vector<string>::iterator d_itr = daysOfWeek.begin();
			for (int i = 0; d_itr != daysOfWeek.end() && t_itr != arrayOfTime.end(); ++d_itr, ++t_itr, ++i){
				//Перебираем дни недели, присваиваем их дереву соответсвия день-время
				p.first = *d_itr;
				p.second = *t_itr;
			}
		}
	}
	~Shelude(){}

	vector <const tm*> getWeekTime(){
		return ;
	}

	void setDayTime(const string day, int _open_hour, int _open_minute, int _close_hour, int _close_minute){
		workTime dayTime(_open_hour, _open_minute, _close_hour, _close_minute);
		time[day] = dayTime;
	}
};

