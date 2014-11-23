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
            firstSpace = strchr(buffer, ' '); //Находим первый пробел и текст после него
            //Обрабатываем строку справа налево
            ++firstSpace;//Пропускаем пробел
            strcpy(bufferForNameOfDirrective, firstSpace); //Здесь ложим строку с именем и значением

            secondSpace = strrchr(bufferForNameOfDirrective, ' '); //Находим второй пробел в буфере для имени и значения
            ++secondSpace;
            strcpy(defineUnit[i].valueOfDirrective, secondSpace); //Имеем значение в структуре
            int sizeOfName = strcspn(bufferForNameOfDirrective, defineUnit[i].valueOfDirrective); //Получаем количество знаков в имени
            --sizeOfName; //Удаляем пробел
            strncpy(defineUnit[i].nameOfDirrective, bufferForNameOfDirrective, sizeOfName);

            fgets(buffer,499,filePointer);
        }

        else
        {
            --i;
            fgets(buffer,499,filePointer); //Получаем строку для того чтобы проверить её на наличие дефайна перед тем как запустить новую итерацию
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
