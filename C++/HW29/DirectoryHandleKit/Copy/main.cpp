/*��������� ��� ����������� ��������� (���������� ��� ��������� ����� � �����).
0. ������������ ���������� ����
1. ����� ��� �����
2. �������� ���� � ������, ������� � ���� <- ��� ���� ������
3. �������� ���� �����������

4. �������� ���� �� �����
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