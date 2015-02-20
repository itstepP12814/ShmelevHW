/*Написать программу, которая использует класс string для анализа строки, 
содержащей математическое выражение, например, вида - (2+3)*4+1. Строка 
вводится с клавиатуры. Программа выдает результат вычисления выражения.*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <exception>
using namespace std;

const int handleExpression(string expression){
	vector <string> exprStrings; //Массив для хранения каждого символа выражения в виду отдельной строки
	stack <int> polkaStack; //Стек для хранения чисел и операторов для польской записи
	for (unsigned int i = 0; i < expression.length(); ++i){
		string temp;
		for (; expression[i] != ' ' && i < expression.length(); ++i){
			temp += expression.substr(i, 1);
		}
		exprStrings.push_back(temp);
	}
	for (vector<string>::iterator itr = exprStrings.begin(); itr != exprStrings.end(); ++itr){
		if (*itr != " " && *itr != "+" && *itr != "-" && *itr != "=" && *itr != "*" && *itr != "/"){
			polkaStack.push(stoi(*itr));
		}
		else{
			int number2 = polkaStack.top(); //Читаем вершину стека и удаляем элемент из стека
			polkaStack.pop();
			int number1 = polkaStack.top();
			polkaStack.pop();
			char binOperator = *(*itr).c_str(); //Преобразование из указателя на строку (итератор) в чар
			int operatorNumber = static_cast<int>(binOperator); //Преобразование из чара в номер символа
			switch (operatorNumber)
			{
			case '+':
				polkaStack.push(number1 + number2);
				break;
			case '-':
				polkaStack.push(number1 - number2);
				break;
			case '*':
				polkaStack.push(number1 * number2);
				break;
			case '/':
				polkaStack.push(number1 / number2);
				break;
			default:
				throw exception("Error: Wrong operator found.\n");
				break;
			}
		}
	}
	return polkaStack.top();
}

const string toPolishNotationConverter(string str){
	str.push_back('\0');
	string polkaExpression = "\0";
	stack <char> polkaStack;
	int bracketCounter = 0; //Считаем скобки - закрыто должно быть столько же сколько было открыто
	int localOperCounter = 0; //Считаем знаки операций - нам нужно знать сколько возвращать знаков из стека после закрытия скобки
	for (string::iterator itr = str.begin(); itr != str.end(); ++itr){
		int charNumber = static_cast<int>(*itr);
		switch (charNumber)
		{
		case '(':
		{
			polkaStack.push(*itr);
			++bracketCounter;
			break;
		}
		case ')':
		case '\0':
		{
			while (localOperCounter != 0){	//Мы должны извлечь все операторы из стека в строку, перед закрытием скобки, либо завершением выражения...
				char operChar = polkaStack.top(); 
				string temp(1,operChar);
				if (temp != "("){ //...кроме "(", её нужно просто выкинуть из стека
					polkaExpression += " " + temp;
					--localOperCounter;
				}
				else{
					--bracketCounter;
				}
				polkaStack.pop();
			}
			
			break;
		}
		case '+': //Знаки отправляем в стек
		case '-':
		case '*':
		case '/':
		{
			polkaStack.push(*itr);
			++localOperCounter;
			break;
		}

		default:{ //Если ничего не подошло, значит в итераторе - цифра, её отправляем сразу в строку

			string number(1,*itr);
			polkaExpression += " " + number;
			while (*(itr + 1) != ' ' && *(itr + 1) != '\0' && *(itr + 1) != '+' && *(itr + 1) != '-' && *(itr + 1) != '*' && *(itr + 1) != '/' && *(itr + 1) != '(' && *(itr + 1) != ')' && itr != str.end()){
				++itr;
				string add_number(1, *itr);
				polkaExpression += add_number;
			}
			break;
		}
		}
	}
	polkaExpression.erase(0, 1); //Вырезаем первый пробел
	return polkaExpression;
}
int main(){
	//Как пример:
	//(8+4+8)/(9-7)*20
	//8 4 8 + + 9 7 - / 20 *
	try{
		string userInput;
		cout << "Enter expression: ";
		cin >> userInput;
		string str = toPolishNotationConverter(userInput);
		cout << "Your expression in polish notation: " << str << endl;
		//8 4 8 + + 9 7 - / 20 *
		int result = handleExpression(str);
		cout << "Answer: " << result << endl;
	}
	catch (exception ex){
		cerr << ex.what() << endl;
	}
	return 0;
}
