#ifndef CENSORENGINE_H
#define CENSORENGINE_H
#include <iostream>
using namespace std;

struct WordElement{
    string word;
    WordElement* next;
    WordElement* prev;
};

class linkedList
{
    public:
        linkedList();
        virtual ~linkedList();
        void push_front(string str);
    private:
        string WordFromClass;
        WordElement* endOfList;
        WordElement* beginOfList;
};

#endif // CENSORENGINE_H
