#include <iostream>
#include <string>
using namespace std;

class Mammal{ //абстрактный общий родительский класс
   // public:
      protected:
        string name; //поле недоступно извне
      public:
        Mammal (string n); //вызываем констуктор

        Mammal(const Mammal &source){ //конструктор копирования
            cout << " a copy of " << source.name << " was born\n";
            name = "Copy of " + source.name;
        }
        ~Mammal(){
            cout << "Mammal gone...\n";
        }
        void voice();
        string getName() {return name;} //делаем функцию для отображения имени при доступе извне для name
        void setName(string newName) {name = newName;}
};

class Cat:public Mammal{
    public:
        Cat(string n):Mammal(n){ //:Mammal (n) вызывает конструктор Mammal
            cout << n << " is a cat \n";
        }
        ~Cat(){cout << "Cat " << name << " gone...\n";}

        void greetAnotherCat (Cat &guest){
            cout << "Cat " << name << " says hello to " << guest.name << endl;
        }
        void voice(){
            cout << "Cat" << name << " says Meow!\n";
        }
};

void Mammal::voice(){
    cout << name << " says Yo!\n";

}

Mammal::Mammal(string n){ //обьявление конструктора
    name = n;
}

int main()
{
    //Mammal x;
    Mammal x("Grey"); //Здесь мы создаем переменную классу, и передаем аргументы, т.к. это спрашивает
    cout << x.getName()<<endl;
    //x.name = "Grey";
    x.voice();
    x.setName("FatBoy");
    x.voice();
    Cat y("Thomas");
    Cat t("Jonh");
    y.voice();

    y.greetAnotherCat(t);

    return 0;
}
//Добавить класс "собака"
