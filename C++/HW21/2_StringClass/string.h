#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class String{
    public:
    String(); //констурктор для создания большой строки
    String(const char* str); //констурктор для
    String(const size_t chunkSize);
    String(const String &source); //конструктор копирования
    void printToStream(ostream &str);
    void customString();
    ~String();

    private:
        const size_t  memoryChunk;
        char* s;
        size_t length; //size_t интовый ансигнед тип данных для компилятора, дает более эффективное ассемблирование
};

#endif // STRING_H
