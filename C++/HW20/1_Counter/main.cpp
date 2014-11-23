#include "Counter.h"

int main()
{
    int destiny;

    Counter first;

    cout << "\n1 - Show common amount." << endl;
    cout << "2 - Increase at 1." << endl;
    cout << "3 - Reset at minimum." << endl;
    cout << "4 - Set what you like borders." << endl;
    cout << "Choose your destiny: ";
    cin >> destiny;
    cout << endl;

    while(1)
    {
        switch(destiny)
        {
        case 1:
            first.counterOutput();
            break;
        case 2:
            first.plusOne();
            break;

        case 3:
            first.resetCounter();
            break;

        case 4:
            first.changeBorders();
            break;

        default:
            cout << "Wrong choice\n";
            break;
        }
        cout << "1 - Show common amount." << endl;
        cout << "2 - Increase at 1." << endl;
        cout << "3 - Reset at 0." << endl;
        cout << "4 - Set what you like borders." << endl;
        cout << "Choose your destiny: ";
        cin >> destiny;
        cout << endl;
    }
    /* Попытка создать меню на основе массива указателей на методы.
    Такой подход не годиться, так как функция не принадлежит каждому обьекту.

        first.menu[4] = {first.counterOutput, first.plusOne, first.resetCounter, first.changeBorders};

         while(1){
                 cout << "1 - Show common amount." << endl;
                 cout << "2 - Increase at 1." << endl;
                 cout << "3 - Reset at 0." << endl;
                 cout << "4 - Set what you like borders." << endl;
                 cout << "Choose your destiny: ";
                 cin >> destiny;
                 cout << endl;
            menu[destiny-1]();
         }
    */
    return 0;
}
