#include "string.h"
//«десь описываем созлание новой пустой строки с нулевым символом
String::String():memoryChunk(128){// онструктор по умолчанию
    s=(char*)malloc(memoryChunk); //Memorychunk - мы задали стандартный размер на который будем ориенироватьс€
    s[0]='\0';
    length = 0;
}

String::String(const char* str):memoryChunk(128){
    //—тандартный конструктор
        length = strlen(str);
        //s =(char*) malloc(length*sizeof(char));
        s =(char*) malloc(length*sizeof(char));
        strcpy(s,str);
}

String::String(const String &source):memoryChunk(128){ // онструктор копировани€ (определ€ет пор€док создани€ копий обьекта, при передаче в функции и т.д.)
    s = (char*) malloc(source.length*sizeof(char));
    strcpy(s,source.s);
}/*«десь мы получаем длину строки из передаваемового в качестве аргумента
обьекта*/

String::String(const size_t chunkSize):memoryChunk(chunkSize){// онструктор по умолчанию
    s=(char*)malloc(memoryChunk); //Memorychunk - мы задали стандартный размер на который будем ориенироватьс€
    s[0]='\0';
    length = 0;
}

void String::printToStream(ostream &str){ //¬ качестве аргумента передаем выходной поток в который будем писать строку
    str << s; //cout €вл€етс€ обьектом класса ostream, мы передаем его в качестве аргумента и называем str (передаем по ссылке, т.к. копирование cout запрещено). ѕосле этого мы можем использовать str как вывод на экран, причем передава€ кроме cout, другие обьекты класса ostream мы можем выводить на экран и их, таким образом создав универсальное решение дл€ вывода на экран
}

void String::customString(){
    cout << "Enter length of string: ";
    cin >> length;
    cout << "Enter text: ";
    cin >> s;
}
String::~String(){
    free(s);
}
