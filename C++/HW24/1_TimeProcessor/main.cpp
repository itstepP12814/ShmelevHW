#include "timeclass.h"

int main()
{
    timeClass timer;
    timer.timeInput();
    timer.timeFormatter('Europe');
    cout << endl << timer.getTime();
    return 0;
}
