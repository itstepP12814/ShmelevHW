#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student{
protected:
	string name;
	int height; 
public:
	Student(){};
	Student(string _name, int _height):name(_name),height(_height){};
	virtual ~Student(){};
	bool goToUniversity();
	void getName(){
		cout << name << endl;
	}
};
 
