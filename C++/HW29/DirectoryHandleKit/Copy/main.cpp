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
	CopyHandle ob(userPathFrom,userPathTo);
	try{
		ob.allFileCopy();
	}
	catch (std::exception ex){
		printf("%s\n", ex.what());
	}

	return 0;
}