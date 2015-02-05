#include "removeHandle.h"

int main(int argc, char* argv[]){
	std::string userPath = argv[1];
	try{
		removeDirrectory(userPath,0);
		int dirRemoveCheck = _rmdir(userPath.c_str());
		if (dirRemoveCheck == -1){
			throw std::exception("Can't remove a folder.\n");
		}
	}
	catch (std::exception ex){
		printf("%s\n", ex.what());
	}
	return 0;
}