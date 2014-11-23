#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c, size;

    int *pa = &a;
    int *pb = &b;
    int *pc = &c;

    int *ppa = pa;
    int *ppb = pb;
    int *ppc = pc;

    *ppc = *ppa + *ppb;

    cout << "Первое слагаемое: " << *ppa << endl <<"Второе слагаемое: " << *ppb << endl <<"Сумма: " << *ppc << endl;
}
