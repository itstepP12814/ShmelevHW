#pragma once
#include "Shelude.h"
#include <iostream>
class Entertainment
{
protected:
	Shelude* workTime;
	Entertainment(string _name, int _capacity) :
		name(_name), capacity(_capacity){
		const string filename = name + " shelude.csv";
		cout << filename << endl;
		workTime = new Shelude(filename);
		if (workTime == nullptr){
			throw exception("Error: shelude not loaded\n");
		}
	}
	virtual ~Entertainment(){};
public:
	string name;
	int capacity;
	map <string, vector <tm>> getOrgShelude(){
		/*map <string, vector <tm>> temp = workTime->getShelude();
		for (auto p : temp){
			cout << p.first << ": " << p.second[0].tm_hour << ":" << p.second[0].tm_min << " - " << p.second[1].tm_hour << ":" << p.second[1].tm_min << endl;
		}*/
		return workTime->getShelude();
	}
};

class Stadium : public Entertainment{
public:
	Stadium(string _name, int _capacity) : Entertainment(_name, _capacity){}
	Stadium(string _name, int _capacity, int _parkingCapacity) :
		parkingCapacity(_parkingCapacity), Entertainment(_name, _capacity){}
	~Stadium(){}
private:
	int parkingCapacity;
};

class Bar : public Entertainment{
private:
	bool music_automate;
public:
	Bar(string _name, int _capacity, bool _music_automate) :
		Entertainment(_name, _capacity), music_automate(_music_automate)
	{}
	~Bar(){}
};

class MassageRoom : public Entertainment{
public:
	MassageRoom(string _name, int _capacity, string _massager_name) :
		Entertainment(_name, _capacity), massager_name(_massager_name)
	{}
	~MassageRoom(){};

private:
	string massager_name;
};