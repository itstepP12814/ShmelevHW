#include "person.h"

Person::Person()
{
    cout << "\nEnter name: ";
    cin >> nameOfPerson;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter sex (1 - Male, 2 - Female): ";
    cin >> sexOfPerson;
    cout << "Enter phone number: +375";
    cin >> phoneNumber;

    print();
}

void Person::editProfile(int choice)
{
    switch(choice)
    {
    case 1:
    {
        cout << "\nEnter new name: ";
        cin >> nameOfPerson;
    }
    break;
    case 2:
    {
        cout << "\nEnter new age: ";
        cin >> age;
    }
    break;
    case 3:
    {
        cout << "\nEnter sex: ";
        cin >> sexOfPerson;
    }
    break;
    case 4:
    {
        cout << "\nEnter new phone number: ";
        cin >> phoneNumber;
    }
    break;
    default:
        cout << "You make wrong choice. Sorry.\n";
        exit(0);
        break;
    }
}

void Person::print(){
    cout << "\nName: " << nameOfPerson << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: ";
        switch(sexOfPerson){
        case 1:
            cout << "Male";
            break;
        case 2:
            cout << "Female";
            break;
        default:
            cout << "Undefined";
            break;
        }
    cout << "\nPhone number: +375" << phoneNumber << endl;
}

Person::~Person()
{
    cout << "Profile was deleted\n";
}
