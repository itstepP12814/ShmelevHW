#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char a[]="Talin";
    int size = strlen(a);
    char*b = (char*) malloc((size*2)*sizeof(int));
    int i=0;
    int n=0;
    for(; i<size; ++i){
        b[n]=a[i];
        b[n+1]=a[i];
        ++n;++n;
    }
    cout << b;
    return 0;
}
