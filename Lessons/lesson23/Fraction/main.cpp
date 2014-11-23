#include "Fration.h"
#include <math.h>

int main()
{
    Fraction x(2,3);
    Fraction y(2,3);
    x.print();
    y.print();
    cout << endl;

    int iteration = 100;
    static Fraction piResult(2);
    for(int i=1; i<=iteration; ++i) {
        Fraction pi(pow((2*i),2), ((2*i-1)*(2*i+1))); ///что-то здесь не так....
          piResult = piResult*pi;
    }
    piResult.print();

    return 0;
}
