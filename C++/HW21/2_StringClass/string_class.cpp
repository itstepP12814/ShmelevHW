#include "string.h"
//����� ��������� �������� ����� ������ ������ � ������� ��������
String::String():memoryChunk(128){//����������� �� ���������
    s=(char*)malloc(memoryChunk); //Memorychunk - �� ������ ����������� ������ �� ������� ����� ��������������
    s[0]='\0';
    length = 0;
}

String::String(const char* str):memoryChunk(128){
    //����������� �����������
        length = strlen(str);
        //s =(char*) malloc(length*sizeof(char));
        s =(char*) malloc(length*sizeof(char));
        strcpy(s,str);
}

String::String(const String &source):memoryChunk(128){ //����������� ����������� (���������� ������� �������� ����� �������, ��� �������� � ������� � �.�.)
    s = (char*) malloc(source.length*sizeof(char));
    strcpy(s,source.s);
}/*����� �� �������� ����� ������ �� ��������������� � �������� ���������
�������*/

String::String(const size_t chunkSize):memoryChunk(chunkSize){//����������� �� ���������
    s=(char*)malloc(memoryChunk); //Memorychunk - �� ������ ����������� ������ �� ������� ����� ��������������
    s[0]='\0';
    length = 0;
}

void String::printToStream(ostream &str){ //� �������� ��������� �������� �������� ����� � ������� ����� ������ ������
    str << s; //cout �������� �������� ������ ostream, �� �������� ��� � �������� ��������� � �������� str (�������� �� ������, �.�. ����������� cout ���������). ����� ����� �� ����� ������������ str ��� ����� �� �����, ������ ��������� ����� cout, ������ ������� ������ ostream �� ����� �������� �� ����� � ��, ����� ������� ������ ������������� ������� ��� ������ �� �����
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
