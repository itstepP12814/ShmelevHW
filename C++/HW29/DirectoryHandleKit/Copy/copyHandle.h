#pragma once
#include <io.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <exception>
#include <direct.h>

bool showSearchResult(_finddata_t& searchResultQueue, long& done);
bool allFileCopy(std::string fromPath, std::string toPath, int choice);