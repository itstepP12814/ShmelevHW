using namespace std;
#include <Windows.h>
#include <windowsx.h>
#include "resource.h"
#include <vector>
#define CHECKING_TIMER 1
class Player
{
public:
	bool parity;
	Player(bool _parity):parity(_parity){};
	~Player(){};
} playerOne(true), playerTwo(false);

int gameTurn = 0;
vector <int> hResButtons;
BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp);
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
	//SetTimer(hWnd, CHECKING_TIMER, 1000, TimerProc);
	switch (message)
	{
		case WM_CLOSE:{
			// ��������� ����������� ������
			DestroyWindow(hWnd); // ��������� ����
			PostQuitMessage(0); // ������������� ���� ��������� ���������
		}
		return TRUE;
		case WM_COMMAND:
		{
						   
			for (auto p : hResButtons){
				if (LOWORD(wp) == p){
					bool parity = gameTurn % 2;
					if (parity == playerOne.parity){
						TCHAR gameChar[2];
						wsprintf(gameChar, TEXT("X"));
						SetWindowText((HWND)lp, gameChar);
						HWND hAdviceText = GetDlgItem(hWnd, IDC_STATIC_02);
						SetWindowText(hAdviceText, TEXT("����� \"O\""));
					}
					else{
						TCHAR gameChar[2];
						wsprintf(gameChar, TEXT("O"));
						SetWindowText((HWND)lp, gameChar);
						HWND hAdviceText = GetDlgItem(hWnd, IDC_STATIC_02);
						SetWindowText(hAdviceText, TEXT("����� \"X\""));
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
	// �������� ���������� ����������
	HINSTANCE hInstance = GetModuleHandle(0);
	TCHAR commonClassName[100];
	GetClassName(hExWnd, commonClassName, 100);
	int id;
	if (!lstrcmp(commonClassName, TEXT("Button"))){
		hResButtons.push_back(GetDlgCtrlID(hExWnd));
	}
	return TRUE;
}

//VOID CALLBACK TimerProc(
//	HWND hwnd,        // handle to window for timer messages 
//	UINT message,     // WM_TIMER message 
//	UINT idTimer,     // timer identifier 
//	DWORD dwTime)     // current system time 
//{
//	while (1){
//		
//	}
//}