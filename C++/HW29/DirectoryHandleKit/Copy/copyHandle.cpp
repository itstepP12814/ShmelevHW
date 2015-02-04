#include "copyHandle.h"
#include <iostream>

//if (done == -1){
//	const char* pathPtr = (toPath.c_str());
//	int check_mkdir = _mkdir(pathPtr);
//	if (check_mkdir == -1){
//		throw std::exception("Can't create dirrectory for copying.\n");
//	}
//}

//_finddata_t searchAllFilesInDir(const std::string path, _finddata_t searchResultQueue){	//Поиск всех файлов + проверка существования дирректории
//	long done = _findfirst((path + "\\*").c_str(), &searchResultQueue);
//	return searchResultQueue;
//}

bool showSearchResult(_finddata_t searchResultQueue, long done){ //Показ результатов поиска
	int endFlag = done;
	while (endFlag != -1){
		printf("%s\n", &searchResultQueue.name);
		endFlag = _findnext(done, &searchResultQueue);
	}
	return true;
}

int answerInterpretation(const _finddata_t& ob){
	if (ob.attrib == _A_SUBDIR){
		printf("Destination folder already exist. Combine?\n\t1 - Yes\n\t2 - Yes, for all\n\t3 - Skip\n\t4 - Cancel\nEnter answer number: ");
	}
	else
	{
		printf("File already exist. Replace?\n\t1 - Yes\n\t2 - Yes, for all\n\t3 - Skip\n\t4 - Cancel\nEnter answer number: ");
	}
	int choice = NULL;
	scanf_s("%d", &choice);
	switch (choice){
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	default:
		printf("Wrong choice. Try again.\n");
		answerInterpretation(ob);
		break;
	}
}

bool allFileCopy(std::string fromPath, std::string toPath, int choice){ //Метод копирования файлов
	_finddata_t searchResultQueueFrom;
	_finddata_t searchResultQueueTo;
	long done = _findfirst((fromPath + "\\*").c_str(), &searchResultQueueFrom);
	long doneTo = _findfirst((toPath + "\\*").c_str(), &searchResultQueueTo);
	if (doneTo == -1){
		const char* pathPtr = (toPath.c_str());
		int check_mkdir = _mkdir(pathPtr);
		if (check_mkdir == -1){
			throw std::exception("Can't create dirrectory for copying.\n");
		}
	}
	int endFlag = done;
	char buffer[256];
	endFlag = _findnext(done, &searchResultQueueFrom);
	endFlag = _findnext(done, &searchResultQueueFrom);
	std::ofstream inFile;
	std::ifstream fromFile;
	while (endFlag != -1){
		if (searchResultQueueFrom.attrib == _A_SUBDIR){ //Проверяем наличие поддиректории
			std::string folderName = (const char*)searchResultQueueFrom.name;
			std::string newFromPath = fromPath + "\\" + folderName;
			std::string newToPath = toPath + "\\" + folderName;
			_finddata_t tempData;
			long localDone = _findfirst(newToPath.c_str(), &tempData); //Проверяем наличие аналогичной дирректории в месте назначения
			if (localDone == -1){ //Если её нет - то создаем
				const char* pathPtr = (newToPath.c_str());
				int check_mkdir = _mkdir(pathPtr);
				if (check_mkdir == -1){
					throw std::exception("Can't create dirrectory for copying.\n");
				}
			}
			else{ //Если есть - уточняем, хочет ли пользователь совместить дирректории
				if (choice == 1 || choice == 0){ //Задаем повторный вопрос если пользователь согласился на однократную замену, или если замена будет происходить впервые
					choice = answerInterpretation(tempData);
				}
				if (choice == 3){ //Если пользователь хочет пропустить папку, прерываем работу функции
					return true; 
				}
				if (choice == 4){ //Если выбрал отмену - прерываем программу
					throw std::exception("Operation aborted by user.\n");
				}
				//Если пользователь согласился на постоянную замену, перестаем задавать вопрос и пропускаем выполнение дальше
			}
			allFileCopy(newFromPath, newToPath, choice); //Запускаем рекурсивно функцию для копирования
		}

		else{
			std::string filename = (const char*)searchResultQueueFrom.name;
			std::string fromPathFull = fromPath + "\\" + filename;
			std::string toPathFull = toPath + "\\" + filename;
			//printf("Copying from %s to %s.\n", &fromPath, &toPath);
			std::cout << "From " << fromPathFull << " to " << toPathFull << std::endl;
			fromFile.open(fromPathFull, std::ios::in | std::ios::binary);
			inFile.open(toPathFull, std::ios::out | std::ios::binary);
			if (!fromFile.is_open()){
				throw std::exception("Error: access to file.\n");
			}
			fromFile.read(buffer, sizeof(char));
			printf("Copying in progress...\n");
			while (!fromFile.eof()){
				inFile.write(buffer, sizeof(char));
				fromFile.read(buffer, sizeof(char));
			}
			printf("\r%s -> done\n", &filename);
			fromFile.close();
			inFile.close();
		}
		endFlag = _findnext(done, &searchResultQueueFrom);
	}
	return true;
	
}