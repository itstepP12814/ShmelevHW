#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int printer(int *massive, int SIZE) {
    for(int i = 0; i<SIZE; ++i, ++massive)
    {
        cout << *massive << " ";
    }
    cout << endl;
}

/*int randomizer(int massive[], int SIZE) {  //По непонятной мне причине, функция создания случайных чисел создавала для разных массивов одинаковые числа.
    srand(time(NULL));

    for (int i = 0; i<SIZE; ++i)
    {
        massive[i] = rand()%SIZE+1;
    }
    return 0;
}*/
/*срабатывало я так думаю потому, что в течение одной миллисекунды шло обращение к функции=Юполучались одинаковые
рандомные числа, я тоже с таким сталкивался*/

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
    for(int i = 0; i<SIZE;++i, ++m3, ++m2, ++m1) {
        *m3 = *m1;
        ++m3;
        *m3 = *m2;
    }
}

int main() {
    int const SIZE = 10;
    int const dSIZE = 20;

    int array1[SIZE] = {23,65,785,434,34,7,55,47,43,234};
    int array2[SIZE] = {54,25,12,66,11,75,867,43,77,43};
    int array3[SIZE*2];

    cout << "Первый массив: " << endl;
    sorter(array1,SIZE);
    printer(array1,SIZE);
    cout << "Второй массив: " << endl;
    sorter(array2,SIZE);
    printer(array2,SIZE);

    cout << "Объединённый третий массив: " << endl;
    unity(array1,array2,array3,SIZE);
    sorter(array3,dSIZE);
    printer(array3,dSIZE);

    cout << endl;

    return 0;
}
