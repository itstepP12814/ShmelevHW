/*Перепишите класс stack одного из предыдущих домашних заданий таким образом, чтобы генерировать 
исключения для такого количества условий, какое Вы считаете приемлемым. (Например, невозможность 
выделить нужное количество памяти, переполнение стека и т.д.)*/

#include <iostream>
#include <exception>

using namespace std;
class Stack
{
public:
	Stack(){};
	~Stack(){};
	static int stopThisInsanity;
	static int bytesInStack;
	void recursiveCall(){
		bytesInStack += sizeof(char)* 5000;
		if (bytesInStack > 950000){
			exception ex;
			throw ex;
		}
		char trashGen[5000];
		cout << stopThisInsanity++ << " - " << bytesInStack << " bytes in stack" << endl;
		Stack ob;
		ob.recursiveCall();
	}
};
int Stack::stopThisInsanity = 0;
int Stack::bytesInStack = 0;

int main(){
	try{
		Stack ob;
		ob.recursiveCall();
	}
	catch (exception ex){
		cout << "Stack overflow.\n";
	}
}