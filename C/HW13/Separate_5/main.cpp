#include <iostream>

using namespace std;

int main()
{
    int first = 10;
    int second = 2;
    int answer;

    int *pFirst = &first;
    int *pSecond = &second;
    int *pAnswer = &answer;

    int **ppFirst = &pFirst;
    int **ppSecond = &pSecond;
    int **ppAnswer = &pAnswer;

    if (**ppSecond != 0){
        **ppAnswer = **ppFirst / **ppSecond;
    }
    cout << "Делим " << **ppFirst << " на " << **ppSecond << endl << "Ответ: " << **ppAnswer;
    return 0;
}
