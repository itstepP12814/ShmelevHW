#include "student.h"
#include "aspirant.h"
int main(){
	Student Vasya("Vasya",176);
	Aspirant Gena("Gena", 185);
	Vasya.getName();
	Vasya.goToUniversity();
	Gena.getName();
	Gena.goToUniversity();
	Gena.writeWork();
	return 0; 
}