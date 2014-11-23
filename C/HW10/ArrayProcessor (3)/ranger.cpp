#include "header.h"

int ranger(int array1[],int SIZE)
{

    srand(time(NULL));

    int array_ranger[SIZE]; //Обьявляем запастной массив, в него будет скидывать цифры, меняя их местами
    int j = 0; //Переменная - случаный индекс для определения ного места каждого элемента

    for (int i = 0; i<SIZE; ++i)  //Заполняем запастной массив нулями
    {
        array_ranger[i] = 0;
    }
    for (int i = 0; i<SIZE;)
    {
        j = rand()%(SIZE+1); //Генерируем случайное новый индекс

        if(array_ranger[j] == 0)  //Ставим сюда элемент при условии что здесь не стоит уже другой элемент
        {
            array_ranger[j] = array1[i];
            ++i;
        }
    }

    for(int i = 0; i<SIZE; ++i)  //Заполняем основной массив новым порядком элементов
    {
        array1[i]=array_ranger[i];
    }
}
