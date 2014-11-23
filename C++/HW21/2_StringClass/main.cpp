#include "string.h"


/*String randomName(){
    String res("Olya");
    return res;
}
*/

int main()
{
    char* ololo = "Hello";
    String x(ololo);
    String y(x);
    x.customString();
    x.printToStream(cout);
    y.printToStream(cout);
    //String n[randomName()];
    return 0;
}
