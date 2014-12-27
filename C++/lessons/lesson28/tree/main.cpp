#include <iostream>

using namespace std;

class Item{
public:
    Item(){};
    ~Item(){};
    int key;
    string value;
    Item* left;
    Item* right;
    Item* next;
    Item* prev;
} root;

string& operator[](int i){
    Item** current = &root;
    while(*current != nullptr){
        if((*current)->key == i){
            return *current->value;
        }
        if(i<(*current->key)){
            current = &current->left;
        }
        else{
            current = &current->right;
        }
    }
    *current =
}

int main()
{

    return 0;
}
