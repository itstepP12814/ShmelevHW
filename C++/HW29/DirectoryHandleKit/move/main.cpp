#include "moveHandle.h"

//int main(int argc, char* argv[]){
//	std::string userPathFrom = argv[1];
//	std::string userPathTo = argv[2];

int main(){
	std::string userPathFrom = "D:\\test3";
	std::string userPathTo = "D:\\test";

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