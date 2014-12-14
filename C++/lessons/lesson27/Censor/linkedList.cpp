#include "linkedList.h"


linkedList::linkedList():beginOfList(NULL), endOfList(NULL) {}
linkedList::~linkedList() {}
const string linkedList::banList[BANLIST_SIZE] = {"ramu","rama","ramy","ramoy","rame","mokrij","mokryi","mokroy","mokraja","mokroje","mokroje","jozhik"};

int linkedList::amountOfWords = 0;
void linkedList::push_back(string str) {

    if(endOfList==NULL) {
        beginOfList = new WordElement; ///������� ����� ��������� � ����������� � ������ ������
        endOfList = beginOfList; ///... � ����� ������, ���� ��������� � ������ ���� ����
        beginOfList->next = NULL; ///���������� � ��������� ������
        beginOfList->prev = NULL;
        beginOfList->word = str;
        ++amountOfWords;
    }
    else {
        ///������ ������: ��������� ������������� ���������(str - ���� word, NULL - ���� next � endOfList - ���� prev,
        ///����� ��������� ����� ����� � ����� ����������� (���������) � ������������� ��������� �� ��������� ������� ��
        ///�� ����� ������, � �������, ��������� ������������� ��������� �� ����� �������.
        endOfList = (endOfList->next = new WordElement {str, NULL, endOfList});
        ++amountOfWords;
    }
}

void linkedList::showPhrase() {
    WordElement* tempPtr = beginOfList;
    for(int i=0; i<amountOfWords; ++i) {
        cout << tempPtr->word << " ";
        tempPtr = tempPtr->next; ///������������ ��������� �� ��������� �����
    }
    cout << endl;
}

void linkedList::inputPhrase() {
    string str;
    while(str.back()!='.') { ///��������� � ���������� ������� �����, ���� ��� ������������� ������, �� ��� ��������� ����� �� �����
        cin >> str; ///cin ������ ��� ��������� ��������� �����, ���������� ���������
        push_back(str); ///��������� ����� � ����� ����� ������.
    }
}

void linkedList::censor() {
    WordElement* tempPtr = beginOfList;
    int localAmount = amountOfWords;
    for(int i=0; i<localAmount; ++i) {
        bool banCheck = false;///���������� ��� �������� ����, ���� �� ������� �����, � �������� �� ������� � ����������
        for(int j=0; j<BANLIST_SIZE; ++j) { ///��������� �� ������ ����������� ����
            size_t found = tempPtr->word.find(banList[j]); ///����� ������������ �����
            size_t foundWithDot = tempPtr->word.find(banList[j]+"."); ///����� ������������ �����, � ������ �� �����
            if(found != std::string::npos || foundWithDot != std::string::npos) { ///���� ���� ���� �������
                WordElement* destroyPtr = tempPtr;
                if(destroyPtr->prev != NULL) {
                    destroyPtr->prev->next = destroyPtr->next; ///��������� ��������� next ����������� �������� � ����� ���������� ��������
                }
                if(destroyPtr->next != NULL) {
                    destroyPtr->next->prev = destroyPtr->prev; ///� ��������
                    tempPtr = tempPtr->next;
                }
                destroyPtr->prev = nullptr;
                destroyPtr->next = nullptr;
                --amountOfWords;
                banCheck = true;
                break;
            }
        }
        if(banCheck == false && tempPtr->next != nullptr){
            tempPtr = tempPtr->next;
        }
    }
}
