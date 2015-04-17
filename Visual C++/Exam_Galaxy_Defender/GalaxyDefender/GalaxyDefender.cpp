#include <map>
#include <vector>
#include <Windows.h>
#include <tchar.h>
#include <exception>
#include "resource.h"
#include "Ships.h"
#include "Game.h"

const int LEFT = 10, TOP = 10, WIDTH = 50, HEIGHT = 50; 

map <HWND, SpaceShip> enemy_ships;
HWND hDialog;
HINSTANCE hInst;

bool fillField(HWND hWin);
class Game;

BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){
	MSG msg;
	hInst = hInstance;
	hDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_GAME_DIALOG), NULL, DialogProc);
	ShowWindow(hDialog, nCmdShow);
	UpdateWindow(hDialog);
	while (GetMessage(&msg, 0, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp){
	switch (message)
	{
		case WM_CLOSE:{
			// закрываем немодальный диалог
			DestroyWindow(hWnd); // разрушаем окно
			PostQuitMessage(0); // останавливаем цикл обработки сообщений
		}
			return TRUE;

		case WM_INITDIALOG:{
				currentGame = new Game();	 //Начинаем новую игру
				fillField(hDialog);
				//SetWindowLong(hWnd, GWL_STYLE, WS_POPUP);
		}
			return TRUE;
	}	
	return FALSE;
}

BOOL CALLBACK EnumChild(HWND hExWnd, LPARAM lParam){
	TCHAR buf[100];
	GetClassName(hExWnd, buf, 100);
	if (!lstrcmp(buf, TEXT("Button"))){
		MessageBox(hExWnd, buf, TEXT("Имя класса"), MB_OK);
	}
	return TRUE;
}

bool fillField(HWND hWin){
	vector <Enemy> enemies = currentGame->getEnemies();
	vector <Enemy>::iterator em_itr = enemies.begin();

	for (size_t i = 0; i < currentGame->getFieldSize().x; ++i){
		for (size_t j = 0; j < currentGame->getFieldSize().y; ++j){
			if (em_itr != enemies.end()){
				int leftPoint = LEFT + (WIDTH*j);
				int topPoint = TOP + (HEIGHT*i);
				HWND enH = 0;
				enH = CreateWindowEx(0, TEXT("BUTTON"), 0, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, leftPoint, topPoint, WIDTH, HEIGHT, hWin, 0, hInst, 0);
				DWORD Error = GetLastError();
				if (enH != 0){
					enemy_ships[enH] = *em_itr;
					em_itr++;
				}
				else{
					TCHAR errorBuf[100];
					wsprintf(errorBuf, TEXT("%d"), &Error);
					MessageBox(hWin, errorBuf, TEXT("Ошибка"), MB_OK | MB_ICONEXCLAMATION);
					break;
				}
			}
			
		}
	}
	//EnumChildWindows(hWin, EnumChild, 0);
	return true;
}

bool ShowLastError(HWND hErrorWin){
	TCHAR errorText[100];
	LPTSTR cstr;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR)&cstr,
		0,
		NULL
		);
	wsprintf(errorText, TEXT("%s"), &cstr);
	MessageBox(hErrorWin, errorText, TEXT("Last Error"), MB_OK);
	return true;
}