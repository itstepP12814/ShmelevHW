/*Программа для копирования каталогов (копируются все вложенные папки и файлы).
0. Использовать отладочный путь
1. Найти все файлы
2. Записать файл в память, извлечь в файл <- для всех файлов
3. Изменить путь дирректории

4. Получить путь до папки
*/

#include "copyHandle.h"
int main(int argc, char* argv[]){

	std::string userPathFrom = argv[1];
	std::string userPathTo = argv[2];
	//std::cout << userPathFrom;
	//allFileCopy(userPathFrom, userPathTo);
	//userPathFrom = pathCheck(userPathFrom.c_str());
	//userPathTo = pathCheck(userPathFrom.c_str());
	try{
		allFileCopy(userPathFrom,userPathTo,0);
	}
	catch (std::exception ex){
		printf("%s\n", ex.what());
	}

	return 0;
}