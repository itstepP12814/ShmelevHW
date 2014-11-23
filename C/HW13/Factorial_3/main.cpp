#include <iostream>

using namespace std;

int fact(int *num){
    int answer;
    int *panswer = &answer;

    *panswer = *num;
    (*num)--;
    while (*num != 0){
    *panswer *= *num;
    (*num)--;
    }
    return *panswer;
}

int main()
{   int num;
    cout << "Введите число для получения его факториала: ";
    cin >> num;
    cout << fact(&num);
    return 0;
}
