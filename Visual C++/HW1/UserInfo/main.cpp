// Файл WINDOWS.H содержит определения, макросы, и структуры 
// которые используются при написании приложений под Windows. 
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
using namespace std;

// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");	/* Имя класса окна */

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	TCHAR* name = TEXT("Имя: Константин Шмелёв.");
	TCHAR* specialization = TEXT("Специальность: Врач-гигиенист.");
	TCHAR* age = TEXT("Возраст: 22 года.");

	TCHAR* title = TEXT("О, ДА!");
	MessageBox (
		0,
		name,
		title,
		MB_OK | MB_ICONINFORMATION
		);
	MessageBox(
		0,
		specialization,
		title,
		MB_OK | MB_ICONINFORMATION
		);
	MessageBox(
		0,
		age,
		title,
		MB_OK | MB_ICONINFORMATION
		);
	
	int commonLenght = lstrlen(name) + lstrlen(age) + lstrlen(specialization);
	TCHAR numberOfWideChars[100];
	swprintf_s(numberOfWideChars, 100, TEXT("%d"), commonLenght);
	MessageBox(
		0,
		numberOfWideChars,
		title,
		MB_OK | MB_ICONINFORMATION
		);
	return 0;
}
