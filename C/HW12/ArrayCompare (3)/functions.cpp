#include "header.h"

int printer(int *massive, int SIZE){
    for(int i = 0; i<SIZE; ++i, ++massive)
    {
        cout << *massive << " ";
    }
    cout << endl;
}

int cleaner(int *arrayX, int SIZE){
    for(int i = 0; i<SIZE; ++i){
        *(arrayX+i) = 0;
    }
}

int searcher(int *arrayX, int Ot, int Do, int key){
    int x;
    while (1){
       x = (Ot+Do)/2; //Устанавливаем опорную точку посередине
       if(key<*(arrayX+x)){
            Do = x-1; //Если искомое меньше центрального элемента, то сдвигаем правую границу влево
       }
       else {
        if(key>*(arrayX+x)){ //И наоборот
            Ot = x+1;

        }
        else {
            return *(arrayX+x);
        }
       }
        if(Ot>Do){
            return -1;
        }
    }
}


//Если триггер = 1, то поиск общих элементов,
//Если 2 - поиск уникальных элементов первого массива
//Если 3 - поиск уникальных элементов второго массива
int comparer(int *arrayFirst, int *arraySecond, int *arrayResult, int SIZE, int trigger){ //Функция сравнения запускает функцию поиска, присваивает результаты поиска в массив и возвращает значение размера этого массива.
        int result_counter = 0; //Эта переменная считает количество найденных элементов и будет использоваться как новый размер массива для вывода его
        for(int i = 0; i<SIZE; ++i){
        switch(trigger){
        case 1:
        {
        int search_key = *(arrayFirst+i);
            if (search_key == searcher(arraySecond, 0, SIZE, search_key)){
            *(arrayResult+result_counter) = search_key; //Здесь result_counter позволяет записывать результаты поиска в массив по порядку.
            ++result_counter; //Здесь считается сколько найдено элементов и каким будет размер результирующего массива.
            }
            break;
        }
        case 2:
        {
        int search_key = *(arrayFirst+i);
            if (search_key != searcher(arraySecond, 0, SIZE, search_key)){
            *(arrayResult+result_counter) = search_key;
            ++result_counter;
            }
            break;
        }
        case 3:
        {
        int search_key = *(arraySecond+i);
            if (search_key != searcher(arrayFirst, 0, SIZE, search_key)){
            *(arrayResult+result_counter) = search_key;
            ++result_counter;
            }
            break;
        }
        case 4:
        {

        int search_key = *(arrayFirst+i);
            if (search_key != searcher(arraySecond, 0, SIZE, search_key)){
            *(arrayResult+result_counter) = search_key;
            ++result_counter;
            }
        search_key = *(arraySecond+i);
            if (search_key != searcher(arrayFirst, 0, SIZE, search_key)){
            *(arrayResult+result_counter) = search_key;
            ++result_counter;
            }

        /*
        result_counter += comparer(arrayFirst,arraySecond,arrayResult,SIZE,2); //Некорректно работающий рекурсивный вариант.
        result_counter += comparer(arrayFirst,arraySecond,arrayResult,SIZE,3);
        */
            break;
        }
        default:
        cout << "Ошибка" << endl;
        break;
        }
    }
     return result_counter;
    }

int sorter(int *arrayX, int SIZE){
    for(int i=0; i<SIZE; ++i){
        for(int j=SIZE-1; j>i;--j){
            if(*(arrayX+(j-1))>*(arrayX+j)){
                int x=*(arrayX+j);
                *(arrayX+j)=*(arrayX+(j-1));
                *(arrayX+(j-1))=x;
            }
        }
    }
}

int unity(int *m1, int *m2, int *m3, int SIZE) {
    for(int i = 0; i<SIZE; ++i, ++m3, ++m2, ++m1) {
        *m3 = *m1;
        ++m3;
        *m3 = *m2;
    }
}
