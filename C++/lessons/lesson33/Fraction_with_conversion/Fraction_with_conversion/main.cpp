#include "Fration.h"
#include <math.h>
#include <map>
#include <string>
int main()
{
	//Fraction n = 20;
	Fraction a(10, 20);
	double lol = a;
	a.print();
	cout << lol;
    cout << endl;
    //n.findNOD();

	map <Fraction, string> binTree;
	binTree[Fraction(4, 8)] = "Chetyre vosmyh";
	binTree[Fraction(5, 7)] = "Pyat Sedmyh";
	binTree[Fraction(1, 3)] = "Odna tretia";

	double needle = 0.4;

	for (map<Fraction, string>::iterator itt = binTree.begin(); itt != binTree.end(); ++itt){
		if ((double)itt->first < needle){
			cout << itt->first << " " << itt->second;
		}
	}
	

    return 0;
}
