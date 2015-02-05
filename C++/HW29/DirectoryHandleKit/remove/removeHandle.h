#pragma once
#include <string>
#include <exception>
#include <io.h>
#include <fstream>
#include <direct.h>
#include <stdio.h>
bool removeDirrectory(std::string onePath, int choice);
int answerInterpretation(const _finddata_t& ob);
