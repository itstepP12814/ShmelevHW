#include "cleaner.h"

#define CODE_OF_ENTER 10 //Определяет знак новой строки при вводе

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
    #define CONSOLE_CLEAR_COMMAND "clear"
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) //Нашел это в Гугле, но где именно defined ловит значения WIN32/Linux, найти так и не смог.
    #define CONSOLE_CLEAR_COMMAND "cls"
#endif // defined


using namespace std;

int cleaner()
{
    int c;
    if(getchar()==CODE_OF_ENTER)
    {
        system(CONSOLE_CLEAR_COMMAND);
    }
    return 0;
}
