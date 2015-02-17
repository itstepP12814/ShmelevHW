#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

struct contactBase{
    string name;
    string phoneNumber;
};

class Writer{
public:
    Writer(){};
    virtual ~Writer(){};
    virtual void write(contactBase[], int) = 0;
};
class Writer_txt: public Writer{
    public:
    Writer_txt(){};
    virtual ~Writer_txt(){};
    virtual void write(contactBase people[], int size){
        FILE* filePointer; //Объявляем указатель на поток открытого файла
        filePointer = fopen("contacts.txt","wb"); //Кладем в указатель адрес на поток, открывая файл на запись (w) в бинарном режиме (b)
        for(int i=0; i<size; ++i){
            string result = people[i].name + " " + people[i].phoneNumber + "\r\n";
            cout << "Ввод в файл" << endl;
            fputs(result.c_str(),filePointer);
        }
        fclose(filePointer); //Закрываем поток
    }
};

class Writer_json: public Writer{
public:
    Writer_json(){};
    virtual ~Writer_json(){};
    virtual void write(contactBase people[],int size){
        ofstream output("contacts.json", std::ofstream::out);
            output << "[";
            for(int i = 0; i<size; ++i){
                output << "{ name: " << "\"" << people[i].name << "\"" << ", " << "number: "<< "\"" << people[i].phoneNumber << "\"}";
                if(i!=size-1){
                    output << ", ";
                }
            }
            output << "]";

    }
};

int main()
{
    const int size = 3;
    contactBase people[size] = {{"Jonathan", "+37544778585"},{"Kramer", "+35567686784"},{"Grazer", "+35565657585"}};
    Writer* a[2] = {new Writer_txt, new Writer_json};
    a[0]->write(people,size);
    a[1]->write(people,size);
    return 0;
}
