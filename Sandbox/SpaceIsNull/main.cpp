#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    /*
    cout << "Использование обычного ввода" << endl;
    char buffer[20];
    cin >> buffer;
    int amount = strlen(buffer);
    cout << buffer << endl << "Количество знаков: " << amount << endl;
    */
    cout << "Использование функции getline" << endl;
    std::string buffer2;
    std::getline(std::cin, buffer2);
    cout << buffer2 << endl;

    return 0;
}
