#include "removeHandle.h"

bool SAVE_CHOICE_STATE = false;

int answerInterpretation(const _finddata_t& ob){
	if (ob.attrib == _A_SUBDIR){
		printf("Folder %s only for Read/System/Hidden. Delete anyway?\n\t1 - Yes\n\t2 - Yes, for all\n\t3 - Skip\n\t4 - Cancel\nEnter answer number: ", &ob.name);
	}
	else
	{
		printf("File %s only for Read/System/Hidden. Delete anyway?\n\t1 - Yes\n\t2 - Yes, for all\n\t3 - Skip\n\t4 - Cancel\nEnter answer number: ", &ob.name);
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
		printf("Error: Wrong choice. Try again.\n");
		answerInterpretation(ob);
		break;
	}
}

bool removeDirrectory(std::string onePath, int choice){
	_finddata_t searchResultQueue;
	long done = _findfirst((onePath + "\\*").c_str(), &searchResultQueue);
	if (done != -1){
		int endFlag = done;
		endFlag = _findnext(done, &searchResultQueue);
		endFlag = _findnext(done, &searchResultQueue);
		std::ofstream inFile;
		std::ifstream fromFile;
		while (endFlag != -1){
			if (searchResultQueue.attrib &_A_SUBDIR){ //Проверяем наличие поддиректории
				std::string folderName = (const char*)searchResultQueue.name;
				std::string newPath = onePath + "\\" + folderName;
				if (searchResultQueue.attrib &_A_RDONLY){
					if (choice == 1 || choice == 0){ //Задаем рекурсивный повторный вопрос, если пользователь согласился на однократную замену, или если удаление будет происходить впервые
						choice = answerInterpretation(searchResultQueue);
					}
					if (choice == 3){ //Если пользователь хочет пропустить папку, прерываем работу функции
						return true;
					}
					if (choice == 4){ //Если выбрал отмену - прерываем программу
						throw std::exception("Operation aborted by user.\n");
					}
					//Если пользователь согласился на постоянную замену, перестаем задавать вопрос и пропускаем выполнение дальше
				}
				removeDirrectory(newPath, choice); //Запускаем рекурсивно функцию для удаления
				int dirRemoveCheck = _rmdir(newPath.c_str());
				if (dirRemoveCheck == -1){
					printf("Error: Can't remove a folder \"%s\".\n", &searchResultQueue.name);
					throw std::exception();
				}
			}

			else{ //Для файлов
				std::string filename = (const char*)searchResultQueue.name;
				std::string pathFull = onePath + "\\" + filename;
				_finddata_t fileData;
				long filesDone = _findfirst(pathFull.c_str(), &fileData);
				if (searchResultQueue.attrib &_A_RDONLY || searchResultQueue.attrib &_A_HIDDEN || searchResultQueue.attrib &_A_SYSTEM){ 
					if (SAVE_CHOICE_STATE == false){ //Если не нужно удалять все файлы, то проверить, не появилась ли такая необходимость.
						int answer = answerInterpretation(fileData);
						if (answer == 2){ //Если появилась - установить флаг о постоянном пропуске
							SAVE_CHOICE_STATE = true;
						}
						if (answer == 3){
							endFlag = _findnext(done, &searchResultQueue);
							_findclose(filesDone);
							continue;
						}
						if (answer == 4){
							_findclose(filesDone);
							throw std::exception("Operation aborted by user.\n");
						}
					}
				}
				printf("Removing %s from %s.\n", &fileData.name, &pathFull);
				int checkRename = remove(pathFull.c_str());
				if (checkRename != 0){
					throw std::exception("Can't remove the file.\n");
				}
				printf("Moving in progress...\n");
				printf("\r%s -> done\n", &filename);
			}
			endFlag = _findnext(done, &searchResultQueue);
		}
		_findclose(done);
		return true;
	}
	else{
		throw std::exception("Error: Path does not exist.\n");
	}
}