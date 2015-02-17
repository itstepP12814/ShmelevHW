#include "slotmachine.h"

int main()
{
    slotLine firstBar;
    slotLine secondBar;
    slotLine thirdBar;
    char tempForOutput[3];
    int newGame = 1;
    char keyEnter = 0;

while(newGame == 1){

    for(int i=0; i<10000; ++i){
        printf(" %c |  |  \r", tempForOutput[0]=firstBar.spin());
    }
    for(int i=0; i<20000; ++i){
        printf(" %c | %c |  \r", tempForOutput[0], tempForOutput[1]=secondBar.spin());
    }
    for(int i=0; i<3000; ++i){
        printf(" %c | %c | %c \r", tempForOutput[0], tempForOutput[1], tempForOutput[2]=thirdBar.spin());
    }
    cout << endl;
    char checkSybmol = tempForOutput[0];
    if(checkSybmol == tempForOutput[1] && checkSybmol == tempForOutput[2]){
        cout << "You Win! Congrats!\n";
    }
    else{
        cout << "You LOSE! Try Again? It's free\n";
    }
    newGame = 0;
    keyEnter = 0;
    cout << "Press Enter to start game\n";
    if(getch()==13){
        newGame=1;
    }
    else{
        newGame=0;
    }
}
    return 0;
}
