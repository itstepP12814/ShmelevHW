#include <iostream>
#include "Entertainment.h"
#include "Shelude.h"
#include "Group.h"

/*10. В городе доступны различные развлечения - бары, рюмочные, клубы, рестораны, аттракционы в парке, кино,
компьютерные клубы, спортивные учреждения, стадионы, концерты и.т.д. Некоторые из них можно посещать в одиночку,
некторые - парой, некоторые компанией. Кроме этого, некоторые работают в выходные, в будни, во все дни недели, 
по утрам, в обед, по вечерам, по ночам, в любое время. Выбрать из перечня развлечений варианты в соответствии с 
требованиями - например, найти все развлечения с утра для компании.*/

template <class T> void printSheludes(T obj){
	string name = obj.getName();
	map <string, vector <int>> timeOfWork = obj.getOrgShelude();
	cout << name << ": \n";
	for (auto p : timeOfWork){
		string weekDay = p.first;
		string closed = "";
		if (p.second[0] == -1){
			string output = weekDay + ": " + "Closed.\n";
			cout << output;
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
			char buffer1[7];
			char buffer2[7];
			strftime(buffer1, 7, "%H:%M", c_opentime);
			strftime(buffer2, 7, "%H:%M", c_closetime);
			string output = weekDay + ": " + (string)buffer1 + " - " + (string)buffer2 + "\n";
			cout << output;
		}
	}
	cout << endl;
}

int main(){
	try{
		Stadium Manchester("Manchester", 20000);
		MassageRoom Hosse("Hosse Massage Room", 1, "Julia Ala");
		Stadium Dallas("Dallas", 40000, 1000);
		Bar Chili("Chili", 20, false);
		MassageRoom ChillOut("Chill-Out Massage Room", 1, "Ann Leichtenchtein");
		Bar Drunk_John("Drunk John", 20, true);
		
		printSheludes(Drunk_John);
		printSheludes(Dallas);
		printSheludes(Chili);
		printSheludes(ChillOut);
		printSheludes(Manchester);
		printSheludes(Hosse);

		tm freeTimeFrom;
		freeTimeFrom.tm_hour = 20;
		tm freeTimeAt;
		freeTimeAt.tm_hour = 1;
		tm* c_freeTimeFrom = &freeTimeFrom;
		tm* c_freeTimeAt = &freeTimeAt;


		Group party(10, "Sunday", *c_freeTimeFrom, *c_freeTimeAt);
		cout << endl << party.checkEvalue(Manchester) << endl;
		cout << endl << party.checkEvalue(Dallas) << endl;
		cout << endl << party.checkEvalue(Hosse) << endl;
		cout << endl << party.checkEvalue(Chili) << endl;
		cout << endl << party.checkEvalue(Drunk_John) << endl;
		cout << endl << party.checkEvalue(ChillOut) << endl;

	}
	catch(exception ex){
		cerr << ex.what();
	}
	return 0;
}