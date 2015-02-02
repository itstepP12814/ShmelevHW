#include "copyHandle.h"
#include <iostream>

bool CopyHandle::maskCreate(){
	return 0;
}

_finddata_t CopyHandle::searchAllFilesInDir(const std::string& path, _finddata_t& searchResultQueue, long& done){	//Поиск всех файлов + проверка существования дирректории
	done = _findfirst((path + "\\*").c_str(), &searchResultQueue);
	if (done == -1){
		throw std::exception("Dirrectory %s not found.\n");
	}
	return searchResultQueue;
}

bool CopyHandle::showSearchResult(_finddata_t& searchResultQueue, long& done){ //Показ результатов поиска
	int endFlag = done;
	while (endFlag != -1){
		printf("%s\n", &searchResultQueue.name);
		endFlag = _findnext(done, &searchResultQueue);
	}
	return true;
}

bool CopyHandle::allFileCopy(){ //Метод копирования файлов
	searchResultQueueFrom = searchAllFilesInDir(fromPath,searchResultQueueFrom,doneFrom);
	searchResultQueueTo = searchAllFilesInDir(toPath,searchResultQueueTo,doneTo);
	
	/*const char* pathPtr = (toPath.c_str());
	int check_mkdir = _mkdir(pathPtr);
	if (check_mkdir == -1){
			throw std::exception("Can't create dirrectory for copying.\n");
	}*/

	int endFlag = doneFrom;
	char* buffer;
	buffer = new char;
	endFlag = _findnext(doneFrom, &searchResultQueueFrom);
	endFlag = _findnext(doneFrom, &searchResultQueueFrom);
	while (endFlag != -1){
		std::string filename = (const char*)searchResultQueueFrom.name;
		std::string fromPathFull = fromPath + "\\" + filename;
		std::string toPathFull = toPath + "\\" + filename;
		std::cout << fromPathFull << std::endl << toPathFull << std::endl;
		std::ifstream fromFile(fromPathFull, std::ios::out | std::ios::binary);
		std::ofstream inFile(toPathFull, std::ios::in | std::ios::binary);
		if (!fromFile){
			throw std::exception("Error: access to file.\n");
		}
		fromFile.read(buffer, sizeof(char));
		while (!fromFile.eof()){
			inFile.write(buffer, sizeof(char));
			fromFile.read(buffer, sizeof(char));
		}
		endFlag = _findnext(doneFrom, &searchResultQueueFrom);
	}
	return true;
	
}