#include "linkedList.h"

/*������� ��������� ������� ��������� ����������� �������� �����, � �������� ����������� ����� �� ����,
� ����� �������� �� ������������ ������.*/
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
