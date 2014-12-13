#include "censorEngine.h"

linkedList::linkedList():beginOfList(NULL), endOfList(NULL){}

linkedList::~linkedList(){}

void linkedList::push_front(string str){
    if(endOfList==NULL){
        beginOfList = new WordElement; ///������� ����� ��������� � ����������� � ������ ������
        endOfList = beginOfList; ///... � ����� ������, ���� ��������� � ������ ���� ����
        beginOfList->next = NULL; ///���������� � ��������� ������
        beginOfList->prev = NULL;
    }
    else{
        endOfList = (endOfList->next = new WordElement{WordFromClass, NULL, endOfList});
        cout << endOfList->word;
    }
}
