/*��������� ��� ����������� ��������� (���������� ��� ��������� ����� � �����).
0. ������������ ���������� ����
1. ����� ��� �����
2. �������� ���� � ������, ������� � ���� <- ��� ���� ������
3. �������� ���� �����������

4. �������� ���� �� �����
*/

#include "copyHandle.h"
int main(){

	std::string userPathFrom = "D:\\test";
	std::string userPathTo = "D:\\test2";
	//std::cout << userPathFrom;
	//allFileCopy(userPathFrom, userPathTo);
	try{
		allFileCopy(userPathFrom,userPathTo,0);
	}
	catch (std::exception ex){
		printf("%s\n", ex.what());
	}

	return 0;
}