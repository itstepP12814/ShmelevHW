#include "linkedList.h"

/*Сделать программу которая позволяет фильтровать вводимый текст, и вырезать запрещенные слова из фраз,
а затем выводить их исправленные версии.*/
int main()
{
    cout << "Don't use next words: ";
    for(int i=0; i<BANLIST_SIZE; ++i){
        cout << linkedList::banList[i] << " ";
    }
    cout << "\nThanks!\n";

    linkedList lol;
    lol.inputPhrase();
    lol.showPhrase();
    lol.censor();
    lol.showPhrase();

    return 0;
}
