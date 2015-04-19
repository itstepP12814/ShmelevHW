#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include "Model.h"
#include <vector>

using namespace std;

Model* my_throw;
HWND hStartButton;
HWND hDialog;
HINSTANCE hInst;

int leftPoint;
int topPoint;

const int pxFixY = 200;
const int pxFixX = 150;
const int pxLenFix = 30;

vector <HWND> ballObj;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
VOID CALLBACK TimerProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow){
	hInst = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message)
	{
	case WM_CLOSE:{
					  EndDialog(hWnd, 0); // закрываем модальный диалог
					  DestroyWindow(hWnd); // разрушаем окно
					  PostQuitMessage(0); // останавливаем цикл обработки сообщений
	}
		return TRUE;
	case WM_INITDIALOG:{
						   hDialog = hWnd;
						   hStartButton = GetDlgItem(hWnd, ID_GO);
	}
	case WM_COMMAND:{
						if ((HWND)lParam == hStartButton){
							TCHAR angleText[1024];
							TCHAR speedText[1024];
							HWND hAngle = GetDlgItem(hWnd, IDC_EDIT1);
							HWND hSpeed = GetDlgItem(hWnd, IDC_EDIT2);
							GetWindowText(hAngle, angleText, 1024);
							GetWindowText(hSpeed, speedText, 1024);
							int angleNum = _ttoi(angleText);
							int speedNum = _ttoi(speedText);
							my_throw = new Model(400, 200, angleNum, speedNum);
							SetTimer(hWnd, 123, 100, TimerProc);
						}
	}
		return TRUE;
	}
	return FALSE;
}


VOID CALLBACK TimerProc(
	HWND hwnd,        // handle to window for timer messages 
	UINT message,     // WM_TIMER message 
	UINT idTimer,     // timer identifier 
	DWORD dwTime)     // current system time 
{
	topPoint = pxFixY - (my_throw->ball.y)*pxLenFix;
	leftPoint = pxFixX + (my_throw->ball.x)*pxLenFix;
	ballObj.push_back(CreateWindowEx(0, TEXT("BUTTON"), 0, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, leftPoint, topPoint, 5, 5, hDialog, 0, hInst, 0));
	my_throw->updateFieldState();
	if (my_throw->ball.y <= 0){
		KillTimer(hDialog, 123);
	}
}