#include <iostream>
#include "person.h"
using namespace std;

int main()
{
    Person Anna;
    int menu;
    int editChoice;

    while(1)
    {
        cout << "\n1 - Show profile\n";
        cout << "2 - Edit profile\n";
        cout << "3 - EXIT\n";
        cout << "Enter your choice: ";
        cin >> menu;
        switch(menu)
        {
        case 1:
            Anna.print();
            break;
        case 2:
            cout << "\n\n\t1 - Edit name\n";
            cout << "\t2 - Edit age\n";
            cout << "\t3 - Edit sex\n";
            cout << "\t4 - Edit phone number\n";
            cout << "\t5 - Back\n";
            cout << "Enter your choice: ";
            cin >> editChoice;
            if(editChoice >0 && editChoice <5)
            {
                Anna.editProfile(editChoice);
            }
            else
            {
                if(editChoice == 5)
                {
                    break;
                }
                else
                {
                    cout << "You make wrong choice. Sorry.\n";
                    continue;
                }
            }
            break;
        case 3:
            cout << "Bye!\n";
            exit(0);
            break;
        default:
            cout << "Wrong choice\n";
            continue;
        }
    }
    return 0;
}
