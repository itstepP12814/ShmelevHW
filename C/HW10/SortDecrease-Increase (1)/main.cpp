#include "sorter.h"

int main()
{
    int trigger = 1;
    int const SIZE = 5;
    int array1[SIZE];

    srand(time(NULL));

    cout << "Программа сортировки массива по убыванию/возрастанию" << endl << "Массив для сортировки введен.";
    cout << "Введите 1, чтобы отсортировать массив. Чтобы сортировать по возрастанию, введите 2." << endl;
    cin >> trigger;

    cout << "Массив до сортировки:" << endl;

    for (int i = 0; i<SIZE; ++i){
        array1[i] = rand()%100;
        cout << array1[i] << endl;
    }

    cout << "Массив после сортировки: " << endl;
    sorter (array1, SIZE, trigger);

        return 0;
}
