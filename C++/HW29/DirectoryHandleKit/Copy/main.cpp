/*Программа для копирования каталогов (копируются все вложенные папки и файлы).
0. Использовать отладочный путь
1. Найти все файлы
2. Записать файл в память, извлечь в файл <- для всех файлов
3. Изменить путь дирректории

4. Получить путь до папки
*/
#include "copyHandle.h"
int main(){

	std::string userPathFrom = "D:\\test";
	std::string userPathTo = "D:\\test2";
	//std::cout << userPathFrom;
	CopyHandle ob(userPathFrom,userPathTo);
	try{
		ob.allFileCopy();
	}
	catch (std::exception ex){
		printf("%s\n", ex.what());
	}

	return 0;
}