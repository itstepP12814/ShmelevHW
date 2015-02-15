#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passport
{
public:
	Passport(string _name, string _lastname, string _passport_number, bool _married, string _sex) :
		name(_name), lastname(_lastname), passport_number(_passport_number), married(_married), sex(_sex){};
	virtual ~Passport(){};
	void showInfo(){
		cout << name << endl;
		cout << lastname << endl;
		cout << passport_number << endl;
		cout << "Married: " << married << endl;
		cout << sex << endl;
	}
protected:
	string name;
	string lastname;
	string passport_number;
	bool married;
	string sex;
};

class ForeignPassport : public Passport{
private:
	vector <string> vises;
	string additionalNumber;
public:
	ForeignPassport(string _name, string _lastname, string _passport_number, string _additionalNumber, bool _married, string _sex) :
		Passport(_name, _lastname, _passport_number, _married, _sex), additionalNumber(_additionalNumber)
	{
		fillVises();
	};
	~ForeignPassport(){};
	
	void showInfo(){
		Passport::showInfo();  //Вызываем родительский метод, но к его выводу добавляем дополнительную информацию
		if (!vises.empty()){
			cout << "Vises:" << endl;
			for (vector<string>::iterator itt = vises.begin(); itt < vises.end(); ++itt){
				cout << *itt << endl; //Итератор нужно разыменовывать
			}
		}
		cout << "Additional number: " << additionalNumber << endl;
	}

	bool fillVises(){
		bool check = true;
		do{
			cout << "Do you want add visa? Y - 1/N - 2: ";
			int answer;
			cin >> answer;
			switch (answer){
			case 1:{
				string input;
				cout << "Enter the visa: ";
				cin >> input;
				vises.push_back(input);
			}
			break;
			case 2:{
				check = false;
			}
				   break;
			default:
				cerr << "Wrong choice. Try again.\n";
				check = fillVises();
			}
		}
			while (check == true);
		return true;
	}
};