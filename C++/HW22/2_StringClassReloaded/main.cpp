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
    String n("one");
    String f("two");

    String z = n*f;
    z.printToStream(cout);
    //z.printToStream(cout);
    //String n[randomName()];
    return 0;
}
