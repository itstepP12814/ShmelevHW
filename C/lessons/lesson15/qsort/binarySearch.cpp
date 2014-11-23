#include "header.h"

int binarySearch(int key, int mas[], int SIZE) {
    int i = 0;
    int m = -1; //Результат поиска
    int j = SIZE-1;

    if(key < mas[i] || key > mas[j]) {
        return m;
    }

    else {
        if(mas[i]==key) {
            m=i;
        }
        else {
            if(mas[j]==key) {
                m=j;
            }
            else {
                while((j-i)>1) {
                    m = (i+j)/2;
                    if(mas[m]==key) {
                        break;
                    }
                    else {
                        if(key>mas[m]) {
                            i=m;
                        }
                        else {
                            if(key<mas[m]) {
                                j=m;
                            }
                        }
                    }

                }
            }

        }

    }
    return m;
}
