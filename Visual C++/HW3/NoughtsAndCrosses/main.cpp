using namespace std;
#include <Windows.h>
#include <windowsx.h>
#include <exception>
#include "resource.h"
#include <vector>
#define CHECKING_TIMER 101

class Player
{
public:
	bool parity;
	Player(bool _parity):parity(_parity){};
	~Player(){};
} playerOne(true), playerTwo(false);

struct UserPair{
	HWND hButton;
	char gameChar;
};

vector <UserPair> hResButtons;
bool setGameChar(HWND hNeedle, char gameChar){
	vector<UserPair>::iterator p = hResButtons.begin();
	for (; (p != hResButtons.end()); ++p){
		if (hNeedle == (*p).hButton){
			p->gameChar = gameChar;
			return true;
		}
	}
	return false;
}
int buttonCounter = 0;
int gameTurn = 0;
int gameOver = 0;
BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp);
VOID CALLBACK TimerProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);
BOOL CALLBACK EnumFunc(HWND hExWnd, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){
	
	MSG msg;
	HWND hDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	EnumChildWindows(hDialog, EnumFunc, 0);
	ShowWindow(hDialog, nCmdShow);
	while (GetMessage(&msg, 0, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp){
	if (gameOver == 0){
		SetTimer(hWnd, CHECKING_TIMER, 50, TimerProc);
	}
	else{
		KillTimer(hWnd, CHECKING_TIMER);
	}
	switch (message)
	{
		case WM_CLOSE:{
			// закрываем немодальный диалог
			DestroyWindow(hWnd); // разрушаем окно
			PostQuitMessage(0); // останавливаем цикл обработки сообщений
		}
		return TRUE;
		case WM_COMMAND:
		{
			for (auto p : hResButtons){
				if ((HWND)lp == p.hButton){
					bool parity = gameTurn % 2;
					TCHAR gameChar[2];
					HWND hAdviceText = GetDlgItem(hWnd, IDC_STATIC_02);
					if (parity != playerOne.parity){
							if (setGameChar((HWND)lp, 'X')){ //Отмечаем значение кнопки
							wsprintf(gameChar, TEXT("X"));
							SetWindowText((HWND)lp, gameChar);
							SetWindowText(hAdviceText, TEXT("Ходят \"O\" (Игрок 2)"));
						}
						else{
							MessageBox(hWnd, TEXT("Ошибка при выполнении хода."), TEXT("Ошибка"), MB_ICONWARNING | MB_OK);
							return FALSE;
						}
					}
					else{
						if (setGameChar((HWND)lp, 'O')){ //Отмечаем значение кнопки
							wsprintf(gameChar, TEXT("O"));
							SetWindowText((HWND)lp, gameChar);
							SetWindowText(hAdviceText, TEXT("Ходят \"X\" (Игрок 1)"));
						}
						else{
							MessageBox(hWnd, TEXT("Ошибка при выполнении хода."), TEXT("Ошибка"), MB_ICONWARNING | MB_OK);
							return FALSE;
						}
					}
					gameTurn++;
				}
			}
		}
		return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK EnumFunc(HWND hExWnd, LPARAM lParam){
	// получаем дескриптор приложения
	HINSTANCE hInstance = GetModuleHandle(0);
	TCHAR commonClassName[100];
	GetClassName(hExWnd, commonClassName, 100);
	if (!lstrcmp(commonClassName, TEXT("Button"))){
		//Нумеруем кнопки
		UserPair tempStruct = { hExWnd, '\0' };
		hResButtons.push_back(tempStruct);
		TCHAR text[2];
		wsprintf(text, TEXT("%d"), hResButtons.size());
		SetWindowText(hExWnd, text);
	}
	return TRUE;
}

VOID CALLBACK TimerProc(
	HWND hwnd,        // handle to window for timer messages 
	UINT message,     // WM_TIMER message 
	UINT idTimer,     // timer identifier 
	DWORD dwTime)     // current system time 
{
	if (gameOver == 0){
		int matchCounter = 0;
		for (auto p : hResButtons){
			if (p.gameChar == 'X'){
				++matchCounter;
			}
			if (matchCounter == 3){
				MessageBox(hwnd, TEXT("Игра окончена"), TEXT("Game Over"), MB_OK);
				gameOver = 1;
				break;
			}
		}
	}
}