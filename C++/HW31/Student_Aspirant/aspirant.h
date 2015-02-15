#pragma once
#include "student.h"
class Aspirant:public Student{
public:
	Aspirant(string _name, int _height):Student(_name, _height){};
	//Дочерний конструктор инициализируется базовым
	//Инициализация базовых полей из списка инициализации
	//дочернего констуктора невозможна.
	~Aspirant(){};
	bool writeWork();
}; 

