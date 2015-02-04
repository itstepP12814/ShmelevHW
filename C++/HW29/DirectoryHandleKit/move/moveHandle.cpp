#include "moveHandle.h"

bool SAVE_CHOICE_STATE = false;

int answerInterpretation(const _finddata_t& ob){
	if (ob.attrib == _A_SUBDIR){
		printf("Destination folder %s already exist. Combine?\n\t1 - Yes\n\t2 - Yes, for all\n\t3 - Skip\n\t4 - Cancel\nEnter answer number: ", &ob.name);
	}
	else
	{
		printf("File %s already exist. Replace?\n\t1 - Yes\n\t2 - Yes, for all\n\t3 - Skip\n\t4 - Cancel\nEnter answer number: ", &ob.name);
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

bool moveAll(std::string fromPath, std::string toPath, int choice){
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
		if (searchResultQueueFrom.attrib == _A_SUBDIR){ //��������� ������� �������������
			std::string folderName = (const char*)searchResultQueueFrom.name;
			std::string newFromPath = fromPath + "\\" + folderName;
			std::string newToPath = toPath + "\\" + folderName;
			_finddata_t tempData;
			long localDone = _findfirst(newToPath.c_str(), &tempData); //��������� ������� ����������� ����������� � ����� ����������
			if (localDone == -1){ //���� � ��� - �� �������
				const char* pathPtr = (newToPath.c_str());
				int check_mkdir = _mkdir(pathPtr);
				if (check_mkdir == -1){
					throw std::exception("Can't create dirrectory for copying.\n");
				}
			}
			else{ //���� ���� - ��������, ����� �� ������������ ���������� �����������
				if (choice == 1 || choice == 0){ //������ ����������� ��������� ������, ���� ������������ ���������� �� ����������� ������, ��� ���� ������ ����� ����������� �������
					choice = answerInterpretation(tempData);
				}
				if (choice == 3){ //���� ������������ ����� ���������� �����, ��������� ������ �������
					_findclose(localDone);
					return true;
				}
				if (choice == 4){ //���� ������ ������ - ��������� ���������
					_findclose(localDone);
					throw std::exception("Operation aborted by user.\n");
				}
				//���� ������������ ���������� �� ���������� ������, ��������� �������� ������ � ���������� ���������� ������
			}
			moveAll(newFromPath, newToPath, choice); //��������� ���������� ������� ��� �����������
			_findclose(localDone);//������� ���������� ������ �� ������
			int dirRemoveCheck = _rmdir(newFromPath.c_str());
			if (dirRemoveCheck == -1){
				throw std::exception("Can't remove a folder.\n");
			}
		}

		else{ //��� ������
			std::string filename = (const char*)searchResultQueueFrom.name;
			std::string fromPathFull = fromPath + "\\" + filename;
			std::string toPathFull = toPath + "\\" + filename;
			//��������� ������� ������������ ����� � ����� ����������
			_finddata_t fileData;
			long filesDone = _findfirst(toPathFull.c_str(), &fileData);
			if (filesDone != -1){ //���� ���� ����������
				if (SAVE_CHOICE_STATE == false){ //���� �� ����� �������� ��� �����, �� ���������, �� ��������� �� ����� �������������.
					int answer = answerInterpretation(fileData);
					if (answer == 2){ //���� ��������� - ���������� ���� � ���������� ��������
						SAVE_CHOICE_STATE = true;
					}
					if (answer == 3){
						endFlag = _findnext(done, &searchResultQueueFrom);
						_findclose(filesDone);
						continue;
					}
					if (answer == 4){
						throw std::exception("Operation aborted by user.\n");
					}
				}
			}
			printf("Moving from %s to %s.\n", &fromPath, &toPath);
			int checkRename = rename(fromPathFull.c_str(), toPathFull.c_str());
			if (checkRename != 0){
				throw std::exception("Can't moving the file.\n");
			}
			printf("Moving in progress...\n");
			printf("\r%s -> done\n", &filename);

		}
		endFlag = _findnext(done, &searchResultQueueFrom);
	}
	_findclose(done);
	_findclose(doneTo);
	return true;
}