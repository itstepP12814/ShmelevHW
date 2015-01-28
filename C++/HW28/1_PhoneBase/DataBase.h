#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>

using namespace std;
class DataBase
{
    public:
        DataBase(){};
        virtual ~DataBase(){};
        struct Item{
            public:
            Item(const string _name):left(nullptr),right(nullptr),name(_name){};
            ~Item(){delete left; delete right;};
            Item* left;
            Item* right;
            string name;
            string phoneNumber[3];
        };
        Item* root = nullptr;
        Item* operator[](const string& index){
            Item** current = &root;
            while((*current)!=nullptr){
                if(index == (*current)->name){
                    return (*current);
                }
                if(index > (*current)->name){
                    current = &((*current)->right);
                }
                else{
                    current = &((*current)->left);
                }
            }
            (*current) = new Item(index);
            return (*current);
        }
};

#endif // DATABASE_H
