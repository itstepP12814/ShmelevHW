#include <time.h>
#include <iostream>
using namespace std;

time_t* func(time_t *ptime) {
    static time_t last;
    static time_t timer;
    last = timer;
    timer = time(ptime);
    return ptime;
}
/*
int main(){
    time_t *ptime;
    struct tm *out;
    ptime = func(ptime);
    out = localtime(ptime);
    cout << asctime(out) << endl;
}
*/
