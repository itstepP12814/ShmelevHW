#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int handleExpression(string expression){
	vector <string> exprStrings;
	for (string::iterator itr = expression.begin(); itr != expression.end(); ++itr){
		if (&(*itr) != " " && &(*itr) != "+" && &(*itr) != "-" && &(*itr) != "=" && &(*itr) != "*" && &(*itr) != "/"){
			exprStrings.push_back(&(*itr));
		}
		else{
			if (&(*itr) != " "){

			}
		}
	}
}

int main(){
	string str = "8 2 5 * + 1 3 2 * + 4 - /";
	handleExpression(str);
	return 0;
}