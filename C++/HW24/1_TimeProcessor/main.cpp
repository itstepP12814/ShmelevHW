#include "timeclass.h"

int main()
{
    timeClass timer;
    timeClass timer2;

    timer = timer+timer2;
    timer.timeFormatter('Europe');
    cout << endl << timer.getTime();
    return 0;
}
