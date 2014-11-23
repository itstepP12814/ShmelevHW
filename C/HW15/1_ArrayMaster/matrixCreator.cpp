#include "header.h"

int** createNewMatrix(int m1, int m2, int trigger, int **pm){
    int m1_old;
    int m2_old;
    if (trigger == 1){m1_old = m1-1; m2_old = m2;}  //Эти коэфициенты пригодятся для переписки значений из старого массива
    else {if(trigger == 2){m2_old = m2-1; m1_old = m1;}}

    //Создание нового массива
    int **newMatrix = new int*[m1];
    for(int i=0; i<m1; ++i){
        newMatrix[i] = new int[m2];
    }
    //Присвоение значений старого массива
    for(int i=0; i<m1_old; ++i){
        for(int j=0; j<m2_old; ++j){
           newMatrix[i][j] = pm [i][j];
        }
    }
    newMatrix = writer(m1,m2,newMatrix,trigger);
    //Удаление памяти старого массива
    for(int i=0; i<m1; ++i){
        delete []pm[i];
    }
    delete []pm;

    //Выделение новой чистой памяти
    pm = new int*[m1];
    for(int i=0; i<m1; ++i){
        pm[i] = new int[m2];
    }
    //Присвоение нового массива старому названию
    pm = newMatrix;
    return pm;
    for(int i=0; i<m1; ++i){
        delete []newMatrix[i];
    }
    delete []newMatrix;
}

int **createFirstMatrix(int m1, int m2){
  //Выделение памяти под массивы
    int **pm = new int*[m1];
    for(int i=0; i<m1; ++i){
        pm[i] = new int[m2];
    }

    //Присвоение значений
    for(int i=0; i<m1; ++i){
        for(int j=0; j<m2; ++j){
           pm[i][j] = i+1;
        }
    }
    return pm;
    }
