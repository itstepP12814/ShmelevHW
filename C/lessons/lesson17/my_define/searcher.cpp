#ifndef HEADER_H_INCLUDED
#include "header.h"
#endif

defineStruct* inFileSearch(defineStruct* defineUnit, const int SIZE_OF_ARRAY)
{

    FILE* filePointer;
    char buffer[500];
    char bufferForNameOfDirrective[300];
    char* firstSpace;
    char* secondSpace;

    filePointer = fopen(FILENAME, "r");
    fgets(buffer,499,filePointer);
    for(int i=0; !feof(filePointer); ++i)
    {
        if(strstr(buffer,"#define "))
        {
            firstSpace = strchr(buffer, ' '); //������� ������ ������ � ����� ����� ����
            //������������ ������ ������ ������
            ++firstSpace;//���������� ������
            strcpy(bufferForNameOfDirrective, firstSpace); //����� ����� ������ � ������ � ���������

            secondSpace = strrchr(bufferForNameOfDirrective, ' '); //������� ������ ������ � ������ ��� ����� � ��������
            ++secondSpace;
            strcpy(defineUnit[i].valueOfDirrective, secondSpace); //����� �������� � ���������
            int sizeOfName = strcspn(bufferForNameOfDirrective, defineUnit[i].valueOfDirrective); //�������� ���������� ������ � �����
            --sizeOfName; //������� ������
            strncpy(defineUnit[i].nameOfDirrective, bufferForNameOfDirrective, sizeOfName);

            fgets(buffer,499,filePointer);
        }

        else
        {
            --i;
            fgets(buffer,499,filePointer); //�������� ������ ��� ���� ����� ��������� � �� ������� ������� ����� ��� ��� ��������� ����� ��������
            continue;
        }

    }

    fclose(filePointer);

    return defineUnit;
}

int sizeCalculateForDefineArray(void)
{
    FILE* filePointer;
    char buffer[500];
    int counter = 0;

    filePointer = fopen(FILENAME, "r");
    while(!feof(filePointer))
    {
        fgets(buffer,499,filePointer);
        if(strstr(buffer, "#define "))
        {
            ++counter;
        }
    }
    return counter;
}
