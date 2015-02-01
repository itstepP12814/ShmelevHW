#pragma once
#include <io.h>
#include <stdio.h>
#include <string>

class CopyHandle{
protected:
	std::string fromPath;
	std::string toPath;
	_finddata_t* searchResultQueue;
	void changePathes();
	void searchAllFilesInDir();
public:
	CopyHandle(){};
	CopyHandle(const std::string _fromPath, const std::string _toPath):fromPath(_fromPath), toPath(_toPath){};
	~CopyHandle(){};

};