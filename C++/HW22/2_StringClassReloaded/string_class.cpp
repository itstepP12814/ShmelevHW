#include "string.h"
//Здесь описываем созлание новой пустой строки с нулевым символом
String::String():memoryChunk(128) { //Конструктор по умолчанию
    s=(char*)malloc(memoryChunk); //Memorychunk - мы задали стандартный размер на который будем ориенироваться
    s[0]='\0';
    length = 0;
    cout << "Standart Constructor\n";
}

String::String(const char* str):memoryChunk(128) {
    //Стандартный конструктор
    length = strlen(str);
    //s =(char*) malloc(length*sizeof(char));
    s =(char*) malloc(length*sizeof(char));
    strcpy(s,str);
    cout << "Char Convert Constructor\n";
}

String::String(const String &source):memoryChunk(128) { //Конструктор копирования (определяет порядок создания копий обьекта, при передаче в функции и т.д.)
    s = (char*) malloc(source.length*sizeof(char));
    strcpy(s,source.s);
    cout << "Copy Constructor\n";
}/*Здесь мы получаем длину строки из передаваемового в качестве аргумента
обьекта*/

String::String(const size_t chunkSize):memoryChunk(chunkSize) { //
    s=(char*)malloc(memoryChunk);
    s[0]='\0';
    length = 0;
    cout << "Another Standart Constructor\n";
}

void String::printToStream(ostream &str) { //В качестве аргумента передаем выходной поток в который будем писать строку
    str << s; //cout является обьектом класса ostream, мы передаем его в качестве аргумента и называем str (передаем по ссылке, т.к. копирование cout запрещено). После этого мы можем использовать str как вывод на экран, причем передавая кроме cout, другие обьекты класса ostream мы можем выводить на экран и их, таким образом создав универсальное решение для вывода на экран
}

void String::customString() {
    cout << "Enter length of string: ";
    cin >> length;
    cout << "Enter text: ";
    cin >> s;
}
String::~String() {
    free(s);
    cout << "\nString deleted\n";
}

String String::operator*(const String& str)const {
    String tempString;
    int recordPosition=0; //переменная для управления записью в массив
    int copyLenght = length;
    int copyStrLenght = str.length;
    for(int i=0; i<copyLenght; ++i) {
        for(int j=0; j<copyStrLenght; ++j) {
            if(s[i] == str.s[j]) {
                tempString.s[recordPosition]=s[i];
                ++recordPosition;
            }
        }
    }
    return tempString;
}
