#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class String{

    public:
    String(); //констурктор для создания большой строки
    String(const char* str); //констурктор для
    String(const String &source); //конструктор копирования
    void printToStream(ostream &str);
//    ~String();

    private:
        char* s;
        size_t length; //size_t интовый ансигнед тип данных для компилятора, дает более эффективное ассемблирование
};

String::String(){
    s=(char*)malloc(sizeof(char));
    s[0]=0;
    length = 0;
}

String::String(const char* str){ //Здесь описываем созлание новой пустой строки с нулевым символом
        length = strlen(str);
        s =(char*) malloc(length*sizeof(char));
        strcpy(s,str);
}

String::String(const String &source){
    s = (char*) malloc(source.length*sizeof(char));
    strcpy(s,source.s);
} /*Здесь мы получаем длину строки из передаваемового в качестве аргумента
обьекта*/

void String::printToStream(ostream &str){ //В качестве аргумента передаем выходной поток в который будем писать строку
    str << s; //cout является обьектом класса ostream, мы передаем его в качестве аргумента и называем str (передаем по ссылке, т.к. копирование cout запрещено). После этого мы можем использовать str как вывод на экран, причем передавая кроме cout, другие обьекты класса ostream мы можем выводить на экран и их, таким образом создав универсальное решение для вывода на экран
}

/*String randomName(){
    String res("Olya");
    return res;
}
*/

int main()
{
    char* ololo = "Hello";
    String x(ololo);
    String y(x);
    x.printToStream(cout);
    y.printToStream(cout);
    //String n[randomName()];
    return 0;
}
