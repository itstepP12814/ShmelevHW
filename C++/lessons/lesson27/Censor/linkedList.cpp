#include "linkedList.h"


linkedList::linkedList():beginOfList(NULL), endOfList(NULL) {}
linkedList::~linkedList() {}
const string linkedList::banList[BANLIST_SIZE] = {"ramu","rama","ramy","ramoy","rame","mokrij","mokryi","mokroy","mokraja","mokroje","mokroje","jozhik"};

int linkedList::amountOfWords = 0;
void linkedList::push_back(string str) {

    if(endOfList==NULL) {
        beginOfList = new WordElement; ///—оздаем новую структуру и присваиваем еЄ началу списка
        endOfList = beginOfList; ///... и концу списка, ведь структура в списке пока одна
        beginOfList->next = NULL; ///«аписываем в указатель ничего
        beginOfList->prev = NULL;
        beginOfList->word = str;
        ++amountOfWords;
    }
    else {
        ///—права налево: строкова€ инициализаци€ структуры(str - поле word, NULL - поле next и endOfList - поле prev,
        ///затем создаетс€ новое слово с этими параметрами (структура) и присваиваетс€ указателю на следующий элемент от
        ///от конца списка, и наконец, результат присваиваетс€ указателю на конец массива.
        endOfList = (endOfList->next = new WordElement {str, NULL, endOfList});
        ++amountOfWords;
    }
}

void linkedList::showPhrase() {
    WordElement* tempPtr = beginOfList;
    for(int i=0; i<amountOfWords; ++i) {
        cout << tempPtr->word << " ";
        tempPtr = tempPtr->next; ///ѕереписываем указатель на следующее слово
    }
    cout << endl;
}

void linkedList::inputPhrase() {
    string str;
    while(str.back()!='.') { ///обращение к послежнему символу слова, если оно заканчиваетс€ точкой, то это последнее слово во фразе
        cin >> str; ///cin каждый раз считывает следующее слово, отделенное пробелами
        push_back(str); ///ƒобавл€ем слово в конец нашей строки.
    }
}

void linkedList::censor() {
    WordElement* tempPtr = beginOfList;
    int localAmount = amountOfWords;
    for(int i=0; i<localAmount; ++i) {
        bool banCheck = false;///ѕеременна€ дл€ проверки того, было ли удалено слово, и совершен ли переход к следующему
        for(int j=0; j<BANLIST_SIZE; ++j) { ///ѕровер€ем по списку запрещенных слов
            size_t found = tempPtr->word.find(banList[j]); ///ѕоиск запрещенного слова
            size_t foundWithDot = tempPtr->word.find(banList[j]+"."); ///ѕоиск запрещенного слова, с точкой на конце
            if(found != std::string::npos || foundWithDot != std::string::npos) { ///≈сли хоть одно совпало
                WordElement* destroyPtr = tempPtr;
                if(destroyPtr->prev != NULL) {
                    destroyPtr->prev->next = destroyPtr->next; ///—в€зываем указатель next предыдущего элемента с телом следующего элемента
                }
                if(destroyPtr->next != NULL) {
                    destroyPtr->next->prev = destroyPtr->prev; ///и наоборот
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
