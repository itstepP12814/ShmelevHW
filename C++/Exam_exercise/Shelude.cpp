#include "Shelude.h"
vector <const string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

Shelude::Shelude(const string filename){//Здесь следует передавать имя файла расписания для конкретного заведения
	//По задумке должен читать CSV файл, с расписанием 
	readSheludeFile(filename);
		vector<workTime>::iterator t_itr = arrayOfTime.begin();
		vector<string>::iterator d_itr = daysOfWeek.begin();
		for (int i = 0; d_itr != daysOfWeek.end() && t_itr != arrayOfTime.end(); ++d_itr, ++t_itr, ++i){
			//Перебираем дни недели, присваиваем их дереву соответсвия день-время
			time[*d_itr] = *t_itr;
		}
}

bool Shelude::readSheludeFile(const string filename){
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
		for (string::iterator itr = buffer.begin(); itr != buffer.end() && sequenceForRead != ""; itr += 13){
			while (*itr == ';'){
				++itr;
			}
			int hour_open = -1;
			int min_open = -1;
			int hour_close = -1;
			int min_close = -1;
			int checkParse = sscanf_s(sequenceForRead.c_str(), "%2d:%2d - %2d:%2d", &hour_open, &min_open, &hour_close, &min_close);
			if (checkParse == EOF){
				throw exception("Error: can't read info into cell from the file.\n");
			}
			if (checkParse != 0){
				sequenceForRead.erase(0, 14);
			}
			timeInfo = new workTime(hour_open, min_open, hour_close, min_close);
			arrayOfTime.push_back(*timeInfo);
		}
	}
	if (arrayOfTime.size() < numberDaysInWeek || arrayOfTime.size() > numberDaysInWeek){
		throw exception("Error: miss or overflow some cells.\n");
	}
	else{
		return true;
	}
}

map <string, vector <tm>> Shelude::getShelude(){
	map <string, vector <tm>> returnShelude;
	map <string, workTime>::iterator s_itr = time.begin();
	for (; s_itr != time.end(); ++s_itr){
		vector<tm> timeBuffer;
		timeBuffer.push_back(s_itr->second.getOpenTime());
		timeBuffer.push_back(s_itr->second.getCloseTime());
		returnShelude[s_itr->first] = timeBuffer;
	}
	return returnShelude;
}