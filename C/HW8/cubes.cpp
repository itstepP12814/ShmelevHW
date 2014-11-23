#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int randomizerComp();
int randomizerUser();
int cub();
void artist(int rand1_user, int rand2_user);


int main ()
{
    srand (time(NULL));
    int firstMove = 0;
    int startGame = 0;
    int sumGame_user, aveGame_user, aveGame_comp = 0;
    int sumGame_comp = 0;

    cout << "Добро пожаловать в игру \"Кости\". Посоревнуйтесь с компьютером в удаче." << endl << "Хотите ходить первым? (1 - Да, 0 - Нет): ";
    cin >> firstMove;
    cout << endl << endl << "Начинаем? (Введите 1 и нажите ВВОД): ";
    cin >> startGame;

    for (int i = 0; startGame = 1 && i<6; ++i)
    {
    if (firstMove == 1){
        sumGame_user += randomizerUser();
        sumGame_comp += randomizerComp();
        }
    else {
        sumGame_comp += randomizerComp();
        sumGame_user += randomizerUser();
    }
        startGame = 0;
        cout << "Чтобы начать следующий раунд, введите 1 и нажмите ВВОД: ";
        cin >> startGame;
        cout << endl;
    }
    aveGame_user = sumGame_user/5;
    aveGame_comp = sumGame_comp/5;

    cout << "Сумма Ваших очков: " << sumGame_user << "(в среднем " << aveGame_user << ")" << endl << "Сумма очков компьютера: " << sumGame_comp << "(в среднем " << aveGame_user << ")" << endl;
    if (sumGame_user>sumGame_comp){
    cout << "Вы ПОБЕДИЛИ!";}
    if (sumGame_comp>sumGame_user){cout << "Вы ПРОИГРАЛИ!";}
    if (sumGame_comp==sumGame_user) {
    cout << "У вас НИЧЬЯ.";}
}

int randomizerUser()
{

    int rand1_user,rand2_user,sum_user = 0;

//Для игрока
    rand1_user = rand()%6+1;
    rand2_user = rand()%6+1;

    sum_user = rand1_user+rand2_user;
    cout << "Ваш счет:" << endl << rand1_user << " и " << rand2_user << endl << "Сумма: " << sum_user << endl;
    artist(rand1_user, rand2_user);
    return sum_user;
}

int randomizerComp()
{
    int rand1_comp,rand2_comp, sum_comp =0;
//Для компьютера
    rand1_comp = rand()%6+1;
    rand2_comp = rand()%6+1;
    sum_comp = rand1_comp+rand2_comp;
    cout << "Счёт компьютера:" << endl << rand1_comp << " и " << rand2_comp << endl << "Сумма: " << sum_comp << endl;
    artist(rand1_comp, rand2_comp);
    return sum_comp;
}

void artist(int rand1_user, int rand2_user)
{
    int probel1_dr_stroka = 6-rand1_user;
    int probel2_dr_stroka = 6-rand2_user;
    int counter = 0;
    cout << "*****   *****" << endl << "*";

    for (int mainTrigger = 0; mainTrigger<2; ++mainTrigger)
    {
        if (mainTrigger==1 && rand1_user==0)
        {
            cout << "   ";
        }
        for (int i = 0; rand1_user>0 && i<3; ++i)
        {
            cout << ".";
            --rand1_user;

            for (; rand1_user==0 && i < 2; ++i)
            {
                cout << " ";
            }

        }
        ++counter;

        cout << "*   *";
        if (mainTrigger==1 && rand2_user==0)
        {
            cout << "   ";
        }
        for (int i = 0; rand2_user>0 && i<3; ++i)
        {
            cout << ".";
            --rand2_user;
            ++counter;
            for (; rand2_user==0 && i < 2; ++i)
            {
                cout << " ";
            }
        }
        counter = 0;
        cout << "*" << endl << "*";
    }

    cout << "****   *****" << endl;
}

