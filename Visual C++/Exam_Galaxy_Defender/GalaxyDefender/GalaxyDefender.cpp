#include <map>
#include <vector>
#include <Windows.h>
#include <tchar.h>
#include <exception>
#include "resource.h"
#include "Ships.h"
#include "Game.h"
#include "GameOperators.h"

#define GAME_WORLD_TIMER 666

const int LEFT = 10, TOP = 10, pxResolution = 30; 

map <HWND, SpaceShip*> enemy_ships;
EnemyOperator* villian;
HWND hDialog;
HINSTANCE hInst;
Coo physFieldCoo;

bool fillField(HWND hWin);
class Game;

BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp);
VOID CALLBACK gameTimer(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){
	MSG msg;
	hInst = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_GAME_DIALOG), NULL, (DLGPROC)DialogProc);
	ShowWindow(hDialog, nCmdShow);
	UpdateWindow(hDialog);
	while (GetMessage(&msg, 0, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp){
	DWORD Error = GetLastError();
	switch (message)
	{
		case WM_CLOSE:{
			// закрываем немодальный диалог
			DestroyWindow(hWnd); // разрушаем окно
			PostQuitMessage(0); // останавливаем цикл обработки сообщений
		}
			return TRUE;

		case WM_INITDIALOG:{
				hDialog = hWnd;
				currentGame = new Game();	 //Начинаем новую игру
				villian = new EnemyOperator();
				physFieldCoo.x = (currentGame->getFieldSize().x)*pxResolution;
				physFieldCoo.y = (currentGame->getFieldSize().y)*pxResolution;
				fillField(hDialog);
				SetTimer(hWnd, GAME_WORLD_TIMER, 1000, gameTimer);
		}
		case WM_COMMAND:{
				
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
		return FALSE;
	}
	return TRUE;
}

bool fillField(HWND hWin){
	Hero* galaxyDef = currentGame->currentField->galaxyDef;

	vector <Enemy*> enemies = currentGame->getEnemies();
	vector <Enemy*>::iterator em_itr = enemies.begin();
	vector <Hero*> defenders = {galaxyDef};
	vector <Hero*>::iterator def_itr = defenders.begin();
	

	for (size_t i = 0; i < currentGame->getFieldSize().x; ++i){
		for (size_t j = 0; j < currentGame->getFieldSize().y; ++j){
			if (em_itr != enemies.end()){
				//Получаем размер корабля импользуя его размеры (относительно абстрактного поля) и разрешение физического поля
				int shipWidth = (*em_itr)->width * pxResolution;
				int shipHeigth = (*em_itr)->height * pxResolution;
				//Устанавливаем координаты на физическом поле
				int leftPoint = LEFT + ((*em_itr)->getCoo().x*pxResolution);
				int topPoint = TOP + ((*em_itr)->getCoo().y*pxResolution);
				HWND enH = 0;
				enH = CreateWindowEx(0, TEXT("BUTTON"), 0, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, leftPoint, topPoint, shipWidth, shipHeigth, hWin, 0, hInst, 0);
				DWORD Error = GetLastError();
				if (enH != 0){
					enemy_ships[enH] = *em_itr;
					em_itr++;
				}
				else{
					TCHAR errorBuf[100];
					wsprintf(errorBuf, TEXT("%d"), &Error);
					MessageBox(hWin, errorBuf, TEXT("Ошибка"), MB_OK | MB_ICONEXCLAMATION);
					return false;
				}
			}
			if (def_itr != defenders.end()){
				int shipWidth = (*def_itr)->width * pxResolution;
				int shipHeigth = (*def_itr)->height * pxResolution;
				//Устанавливаем координаты на физическом поле
				int leftPoint = LEFT + ((*def_itr)->shipCoo.x*shipWidth);
				int topPoint = TOP + ((*def_itr)->shipCoo.y*shipHeigth);
				HWND enH = 0;
				enH = CreateWindowEx(0, TEXT("BUTTON"), 0, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, leftPoint, topPoint, shipWidth, shipHeigth, hWin, 0, hInst, 0);
			}
		}
	}
	
	return true;
}

BOOL CALLBACK enumChildAndClear(HWND hExWnd, LPARAM lParam){
	TCHAR buf[100];
	GetClassName(hExWnd, buf, 100);
	if (!lstrcmp(buf, TEXT("Button"))){
		DestroyWindow(hExWnd);
	}
	return TRUE;
}

bool clearField(HWND hWin){
	EnumChildWindows(hWin, enumChildAndClear, 0);
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

VOID CALLBACK gameTimer(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime) 
{
	if (!currentGame->gameOver){
		currentGame->gameOver = !(villian->makeNextStep());
		clearField(hwnd);
		fillField(hwnd);
	}
	else{
		KillTimer(hDialog, GAME_WORLD_TIMER);
		MessageBox(hwnd, TEXT("Вы проиграли"), TEXT("Игра окончена"), MB_OK);
	}
}