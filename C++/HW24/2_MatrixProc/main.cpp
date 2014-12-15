#include "matrix.h"

int main()
{
    Matrix ololo(6,6);
    Matrix azaza(6,6);
    ololo.showArray();
    azaza.transpose();
    azaza.showArray();
    ololo[1][2] = 123;
    cout << endl << ololo[1][2] << endl;

        return 0;
}
