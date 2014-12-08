#include <iostream>

using namespace std;

struct Item{
    int number;
    Item* next;
};

class MonoList{
    private:
        int junk;
        Item* begin;
        Item* end;
    public:
        MonoList():begin(NULL), end(NULL){};
        void push_front(int number){
            if(begin==NULL){
                begin = new Item;
                begin = end;
                begin->next = NULL;
            }
            else{
                Item* temp;
                temp =
            }
        }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
