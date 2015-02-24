#include <iostream>
#include "Shelude.h"
int main(){
	try{
		Shelude("stadium_shelude.csv");
	}
	catch(exception ex){
		cerr << ex.what();
	}
	return 0;
}