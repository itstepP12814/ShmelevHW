#pragma once
#include <string>
#include <exception>
#include <io.h>
#include <fstream>
#include <direct.h>
#include <stdio.h>
bool moveAll(std::string fromPath, std::string toPath, int choice);
int answerInterpretation(const _finddata_t& ob);
