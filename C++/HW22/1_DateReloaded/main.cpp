#include "date.h"

int main()
{
    Date timer1;
    timer1.datePrinter();
    cout << "+10 days\n";
    Date timer2 = timer1+10;
    timer2.datePrinter();
    int days = timer2-timer1;
    cout << "Timer 1 minus Timer 2 = " << days << endl;
    return 0;
}
