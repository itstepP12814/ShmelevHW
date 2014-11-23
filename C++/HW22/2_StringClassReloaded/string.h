#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class String{
    public:
    String();
    String(const char* str);
    String(const size_t chunkSize);
    String(const String &source);
    void printToStream(ostream &str);
    void customString();
    String operator*(const String& str)const;
    ~String();

    private:
        const size_t  memoryChunk;
        char* s;
        size_t length; //size_t интовый ансигнед тип данных для компилятора, дает более эффективное ассемблирование
};

#endif // STRING_H
