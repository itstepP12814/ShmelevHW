#include "cleaner.h"

//#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

int main()
{
    setlocale( LC_ALL,"Russian" ); //Русский язык для консоли Windows
    trasher();
    cout << endl << endl << "Нажмите ENTER, чтобы очистить консоль" << endl;
    cleaner();
    return 0;
}
