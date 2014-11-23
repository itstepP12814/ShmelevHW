#include <iostream>
#include <math.h>

using namespace std;

template <typename T> T calculate(T *num1, T *num2, char *op){
    T answer;
    switch (*op){
        case '+':
        answer = *num1 + *num2;
        return answer;
        break;

        case '*':
        answer = (*num1)*(*num2);
        return answer;
        break;

        case '-':
        answer = *num1 - *num2;
        return answer;
        break;

        case '/':
        answer = (*num1)/(*num2);
        return answer;
        break;

        case '^':
        answer = pow(*num1, *num2);
        return answer;
        break;

        default:
        cout << "Вы выбрали неверную операцию" << endl;
        break;
    }
}

int main()
{

    float firstNumber, secondNumber;
    char operation;
    char trigger;

    cout << "Калькулятор." << endl;
    cout << "Введите первое число: ";
    cin >> firstNumber;
    cout << "Введите операцию для чисел ( + | - | / | * | ^ ): " << endl;
    cin >> operation;
    cout << "Введите второе число: " << firstNumber << operation;
    cin >> secondNumber;
    cout << secondNumber;
    cout << endl;
    cout << "Ваш ответ: " << endl << calculate(&firstNumber,&secondNumber,&operation) << endl;

    cout << "Нужен ещё расчет?" << endl << "(Y/N): ";
    cin >> trigger;

    switch (trigger){
        case 'y':
        case 'Y':
            main();
        break;

        case 'n':
        case 'N':
        cout << "Всего доброго!";
        break;

        default:
        cout << "Всего доброго!";
        break;
    }
    return 0;
}
