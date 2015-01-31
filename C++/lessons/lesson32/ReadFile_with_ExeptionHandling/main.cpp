#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

class StringException:public exception{
    string comment;
public:
    void voice(){cout << comment;};
    StringException(const string& message):comment(message){};
    virtual ~StringException() _GLIBCXX_USE_NOEXCEPT {};
};

class Reader{
public:
    Reader(){};
    ~Reader(){};

    class Item{
        public:
        Item(){};
        Item(string _name, string _lastName):name(_name), lastName(_lastName){};
        ~Item(){};
        string name;
        string lastName;
    };

    Item items[1000];
    size_t sizeOfArray = 0;

    void read(){
        string localName;
        string localLastName;
        ifstream input("DB.csv", std::ios::in);
        if(!input){
                string message = "File not found\n";
                StringException ex (message);
                throw ex;
        }
        int i=0;
        while(!input.eof()){
            input >> localName;
            input >> localLastName;
            items[i] = Item(localName,localLastName);
            ++sizeOfArray;
            ++i;
        }
    }
};

class Json_reader:public Reader{
    Json_reader(){};
    virtual Json_reader(){};
    virtual void read(){
        string localName;
        string localLastName;
        string str;
        ifstream input("DB.json", std::ios::in);
        if(!input){
                string message = "File not found\n";
                StringException ex (message);
                throw ex;
        }
        int i=0;
        while(!input.eof()){
            getline(input,str);
            for(int i=0; i<str.size(); ++i){
                if(str[i])////
            }
            items[i] = Item(localName,localLastName);
            ++sizeOfArray;
            ++i;
        }
    }
};

int main()
{
    Reader t1;
    try{ ///Инициализируем проверку
        t1.read();
    } catch(StringException ex){ ///В случае исключения выдаем сообщение
        ex.voice();
    }
    for(int i=0; i<t1.sizeOfArray; ++i){
        cout << t1.items[i].name << " " << t1.items[i].lastName << endl;
    }
    return 0;
}
