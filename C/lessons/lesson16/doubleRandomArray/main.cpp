#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int m1, m2;
    cout << "Высота: ";
    cin >> m1;
    cout << "Ширина: ";
    cin >> m2;

    int ** m = new int*[m1];
    for (int i=0; i<m1; ++i){
        m[i] = new int[m2];
    }

    srand(time(NULL));

    for(int i=0; i<m1; ++i){
    cout << endl;
        for(int j=0; j<m2; ++j){
            m[i][j]=rand()%20+1;
            cout << m[i][j] << " ";
        }
    }

    for(int i=0; i<m1; ++i){
        delete[] m[i];
    }
    delete[] m;

    return 0;
}
