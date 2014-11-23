#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char a[] ="Hello, how do you do?";
    int numbersOfChars [20];
    int counter;
    int size = strlen(a);
    char* b = (char*) malloc(size);
    for(int i=0; i<size; ++i) {
        if(a[i]==','||a[i]=='.'||a[i]==';'||a[i]==':'||a[i]=='?') {
            ++counter;
            numbersOfChars[i]=i;
        }
    }

    b = (char*) realloc(b,(size+counter));

    for(int i=0; i<size; ++i) {
        if(i==numbersOfChars[i]) {
           b[i] = " ";
        }
        else{
           b[i]=a[i];
        }
    }



    for(int i=0; i<size; ++i) {
        if(a[i]==','||a[i]=='.'||a[i]==';'||a[i]==':'||a[i]=='?') {

        }
    }


    return 0;
}
