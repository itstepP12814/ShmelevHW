#define _UNICODE
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	TCHAR* text = L"������";
	locale mylocale("rus_rus.866");
	wcout.imbue(mylocale);
	wcout << text << endl;
	_tprintf(TEXT("%s\n"), text);

	vector <wstring> russiansLastNames = { TEXT("�����"), TEXT("�����"), TEXT("�������") };
	for (vector <wstring>::iterator p = russiansLastNames.begin(); p != russiansLastNames.end(); ++p){
		wcout << *p << endl;
	}
	sort(russiansLastNames.begin(), russiansLastNames.end());
	cout << endl;
	for (vector <wstring>::iterator p = russiansLastNames.begin(); p != russiansLastNames.end(); ++p){
		wcout << *p << endl;
	}

	return 0;
}