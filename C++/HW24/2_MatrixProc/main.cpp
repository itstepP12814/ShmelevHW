#include "matrix.h"

int main()
{
    Matrix ololo(6,6);
    Matrix azaza(6,6);
    ololo.showArray();
    azaza = azaza*ololo;
    azaza.showArray();
        return 0;
}
