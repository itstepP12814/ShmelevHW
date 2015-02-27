#include <iostream>
#include "Entertainment.h"
#include "Shelude.h"

//template <typename T> string printSheludes(T obj){
string printSheludes(Stadium& obj){
	map <string, vector <tm>> timeOfWork = obj.getOrgShelude();
	for (auto p : timeOfWork){
		struct tm* opentime = &(p.second[0]);
		struct tm* closetime = &(p.second[1]);
		char buffer1[5];
		char buffer2[5];
		strftime(buffer1, 5, "%H:%M", opentime);
		strftime(buffer2, 5, "%H:%M", closetime);
		string output = (string)buffer1 + (string)buffer2;
		return output;
	}

	return "ok\n";
}

int main(){
	try{
		Stadium Manchester("Manchester", 20000);
		Stadium Dallas("Dallas", 40000, 1000);
		/*Bar Drunk_John("Drunk John", 20, true);
		Bar Chili("Chili", 20, false);
		MassageRoom Hosse("Hosse Massage Room", 1, "Julia Ala");
		MassageRoom ChillOut("Chill-Out Massage Room", 1, "Ann Leichtenchtein");
		*/
		cout << printSheludes(Dallas);
	}
	catch(exception ex){
		cerr << ex.what();
	}
	return 0;
}