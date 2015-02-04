#include "moveHandle.h"

int main(int argc, char* argv[]){
	std::string userPathFrom = "D:\\test";
	std::string userPathTo = "D:\\test2";

	try{
		moveAll(userPathFrom, userPathTo,0);
		int dirRemoveCheck = _rmdir(userPathFrom.c_str());
		if (dirRemoveCheck == -1){
			throw std::exception("Can't remove a folder.\n");
		}
	}
	catch (std::exception ex){
		printf("%s\n", ex.what());
	}
	return 0;
}