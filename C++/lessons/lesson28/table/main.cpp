#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

unsigned int digest(const std::string& str){
    unsigned int sum = 0;
    for(size_t i=0; i<str.length(); ++i){
        sum+=str[i]*i;
    }
    return sum;
}

const size_t N=32;
class Hashtable{
public:
    std::map<std::string,int>elements[N]; ///Массив
    int& operator[](std::string key){
        unsigned int i = digest(key)%N;
        return elements[i][key]; ///Набор пар ключ-значение
    }
};

int main()
{
    Hashtable tbl;
    tbl["kfffk"] = 23423;
    tbl["kfsdf"] = 234;
    tbl["gdffk"] = 23;
    tbl["kfsdg"] = 24;
    tbl["ksdfk"] = 51;
    tbl["kffsd"] = 988;

    for(int i=0; i<N; ++i){
        std::cout << i << " " << tbl.elements[i].size() << "\n";
    }
    return 0;
}
