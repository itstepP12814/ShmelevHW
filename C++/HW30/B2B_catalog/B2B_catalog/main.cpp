#include "catalog.h"

int main(){
	Catalog ob;
	ob.readDB();
	ob.search("kostya", 2);
	//ob.showAll();
	return 0;
}