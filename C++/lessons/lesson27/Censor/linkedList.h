#ifndef CENSORENGINE_H
#define CENSORENGINE_H
#include <iostream>
#include <string>
#include <string.h>

#define BANLIST_SIZE 12

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
        void inputPhrase();
        void showPhrase();
        void censor();

        static int amountOfWords;
        static const string banList[BANLIST_SIZE];
    private:
        void push_back(string str);
        WordElement* endOfList;
        WordElement* beginOfList;
};

#endif // CENSORENGINE_H
