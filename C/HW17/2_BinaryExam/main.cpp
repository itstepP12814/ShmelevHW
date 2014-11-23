#include "header.h"

int main()
{
    student base[NUMBER_OF_STUDENTS];

//Fili, Kili, Oin, Gloin, Thorin, Dwalin, Balin, Bifur, Bofur, Bombur, Dori, Nori, Ori
    strcpy(base[0].name, "Fili");
    strcpy(base[1].name, "Kili");
    strcpy(base[2].name, "Oin");
    strcpy(base[3].name, "Gloin");
    strcpy(base[4].name, "Dwalin");
    strcpy(base[5].name, "Balin");
    strcpy(base[6].name, "Bifur");
    strcpy(base[7].name, "Bofur");
    strcpy(base[8].name, "Bombur");
    strcpy(base[9].name, "Dori");
    strcpy(base[10].name, "Nori");
    strcpy(base[11].name, "Ori");
    /*void (*menu[])(int)={func1,};
    if(choice>=0&&choice<=5){
    menu[choice-1](p);
    }
    */

//Присваивание номеров групп
    for(int i=0; i<6; ++i) {
        base[i].group = 1;
        if(!i%2) {
            base[i].exam = 1;
        }
    }
    for(int i=6; i<12; ++i) {
        base[i].group = 2;
        if(!i%2) {
            base[i].exam = 1;
        }
    }
//---------------------------------------------------

    void (*menu[])(student*) = {printerShowAll,printerShowWinners,printerShowLoosers};
    int trigger, choice;

    while(1==1) {
        cout << "1 - Вывести всех" << endl << "2 - Вывести сдавших" << endl << "3 - Вывести должников" << endl;
        cin >> choice;

        if(choice==2) {
            trigger=1;
        }
        else {
            if(choice==3) {
                trigger=0;
            }
        }

        qsort(base, NUMBER_OF_STUDENTS, sizeof(student), compare);

        menu[choice-1](base);
    }
    /*
    cout << "Все ученики: " << endl
    printerShowAll(base);
    cout << endl << endl;
    cout << "Список сдавших зачет:" << endl;
    printerShowList(base, 1); //второй аргумент - 1, если нужны сдавшие и 0, если нужны должники
    cout << "Список должников:" << endl;
    printerShowList(base, 0);
    */
    return 0;
}
