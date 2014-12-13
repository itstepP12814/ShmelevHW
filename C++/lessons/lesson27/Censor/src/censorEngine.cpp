#include "censorEngine.h"

linkedList::linkedList():beginOfList(NULL), endOfList(NULL){}

linkedList::~linkedList(){}

void linkedList::push_front(string str){
    if(endOfList==NULL){
        beginOfList = new WordElement; ///—оздаем новую структуру и присваиваем еЄ началу списка
        endOfList = beginOfList; ///... и концу списка, ведь структура в списке пока одна
        beginOfList->next = NULL; ///«аписываем в указатель ничего
        beginOfList->prev = NULL;
    }
    else{
        endOfList = (endOfList->next = new WordElement{WordFromClass, NULL, endOfList});
        cout << endOfList->word;
    }
}
