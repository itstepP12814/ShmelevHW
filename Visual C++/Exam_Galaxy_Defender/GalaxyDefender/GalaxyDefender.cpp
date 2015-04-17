#include <map>
#include <vector>
#include <Windows.h>
#include "resource.h"
#include "Ships.h"
#include "Game.h"

//Отступы
#define TOP 10
#define LEFT 10
//Физические размеры элементов
#define WIDTH 50
#define HEIGHT 50

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
		}
			return TRUE;
	}	
	return FALSE;
}

bool fillField(HWND hWin){
	vector <Enemy> enemies = currentGame->getEnemies();
	vector <Enemy>::iterator em_itr;

	for (size_t i = 0; i < currentGame->getFieldSize().x; ++i){
		for (size_t j = 0; j < currentGame->getFieldSize().y; ++j){
			if (em_itr != enemies.end()){
				int leftPoint = LEFT + (WIDTH*j);
				int topPoint = TOP + (HEIGHT*i);
				enemy_ships[CreateWindowEx(0, TEXT("E"), 0,
					WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER,
					leftPoint, topPoint, WIDTH, HEIGHT, hWin, 0, hInst, 0)]
					= *em_itr;

				em_itr++;
			}
			
		}
	}
	return true;
}