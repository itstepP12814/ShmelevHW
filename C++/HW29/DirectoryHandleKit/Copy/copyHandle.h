#pragma once
#include <io.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <exception>
#include <direct.h>

class CopyHandle{
protected:
	std::string fromPath;
	std::string toPath;
	long doneFrom = 0;
	long doneTo = 0;
	_finddata_t searchResultQueueFrom;
	_finddata_t searchResultQueueTo;
	bool maskCreate();
	_finddata_t searchAllFilesInDir(const std::string& path, _finddata_t& searchResultQueue, long& done);
	bool showSearchResult(_finddata_t& searchResultQueue, long& done);
public:
	CopyHandle(){};
	CopyHandle(const std::string _fromPath, const std::string _toPath):fromPath(_fromPath), toPath(_toPath){};
	~CopyHandle(){ _findclose(doneFrom); _findclose(doneTo); }; //Чистим память от результатов поиска
	bool allFileCopy();
};