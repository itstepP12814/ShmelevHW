#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE* filePointer; //Объявляем указатель на поток открытого файла
    char buffer[100];
    cout << "Ввод в файл: ";
    cin >> buffer; //Буфер
    filePointer = fopen("basefile2","wb"); //Кладем в указатель адрес на поток, открывая файл на запись (w) в бинарном режиме (b)
    fputs(buffer,filePointer);

    cout << "Вывод из файла: ";
    fgets(buffer, 99, filePointer);
    cout << buffer << endl;
    fclose(filePointer); //Закрываем поток



    return 0;
}
