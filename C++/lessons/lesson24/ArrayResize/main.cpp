#include "responsivearray.h"

int main()
{
    ResponsiveArray x;
    cout << x.getSize() << endl;
    int n=20;
    x[6]=n;
    cout << x[6] << endl;
    cout << x.getSize() << endl;
    return 0;
}
