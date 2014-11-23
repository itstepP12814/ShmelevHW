#include "header.h"

int printer(int m1, int m2, int **pm){
//Вывод значений
    for(int i=0; i<m1; ++i){
        for(int j=0; j<m2; ++j){
          cout << pm[i][j] << " ";
        }
        cout << endl;
    }
}

