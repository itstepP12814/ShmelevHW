#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    /*
    cout << "������������� �������� �����" << endl;
    char buffer[20];
    cin >> buffer;
    int amount = strlen(buffer);
    cout << buffer << endl << "���������� ������: " << amount << endl;
    */
    cout << "������������� ������� getline" << endl;
    std::string buffer2;
    std::getline(std::cin, buffer2);
    cout << buffer2 << endl;

    return 0;
}
