#include "timeclass.h"

int main()
{
    timeClass timer;
    timeClass timer2;
    timeClass timer3 = timer+timer2;
    timer3.timeFormatter('Europe');
    cout << endl << timer3.getTime();
    return 0;
}
