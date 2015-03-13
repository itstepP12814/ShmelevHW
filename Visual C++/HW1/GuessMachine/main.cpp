// ���� WINDOWS.H �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows. 
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������");	/* ��� ������ ���� */

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	srand(time(NULL));

	// 1. ����������� ������ ����
	wcl.cbSize = sizeof(wcl);	// ������ ��������� WNDCLASSEX
	// ������������ �� ����, ���� ������ ������ �� ����������� ��� �� ���������
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - ����� ������ ����
	wcl.lpfnWndProc = WindowProc;	// ����� ������� ���������
	wcl.cbClsExtra = 0;		// ������������ Windows 
	wcl.cbWndExtra = 0; 	// ������������ Windows 
	wcl.hInstance = hInst;	// ���������� ������� ����������
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// �������� ������������ �������	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ���������� ���� ����� ������
	wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;	// ��� ������ ����
	wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����

	// 2. ����������� ������ ����
	if (!RegisterClassEx(&wcl))
		return 0; // ��� ��������� ����������� - �����

	// 3. �������� ����
	// ��������� ���� �  ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0,		// ����������� ����� ����
		szClassWindow,	//��� ������ ����
		TEXT("������ Windows ����������"), // ��������� ����
		WS_OVERLAPPEDWINDOW,				// ����� ����
		/* ���������, �����, ����������� ������ �������, ��������� ����, ������ ������������ � ���������� ����  */
		CW_USEDEFAULT,	// �-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// ������ ����
		CW_USEDEFAULT,	// ������ ����
		NULL,			// ���������� ������������� ����
		NULL,			// ���������� ���� ����
		hInst,		// ������������� ����������, ���������� ����
		NULL);		// ��������� �� ������� ������ ����������

	HWND button = CreateWindow(
		TEXT("BUTTON"),
		TEXT("������� �����"),
		WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_DEFPUSHBUTTON,
		200,
		200,
		400,
		150,
		hWnd,
		(HMENU)100,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);

	// 4. ����������� ����
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // ����������� ����

	// 5. ������ ����� ��������� ���������

	while (GetMessage(&lpMsg, NULL, 0, 0)) // ��������� ���������� ��������� �� ������� ���������
	{
		TranslateMessage(&lpMsg);	// ���������� ���������
		DispatchMessage(&lpMsg);	// ��������������� ���������
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	int result = 0;
	TCHAR* title = TEXT("��������� ����������");
	switch (uMessage)
	{
	case WM_COMMAND:
	if(LOWORD(wParam) == 100){
		TCHAR guessResult[100];
		int guessCounter = 0;
		while (result != IDCANCEL){
			double numResult = rand() % 100 + 1;
			swprintf(guessResult, TEXT("%f"), numResult);
			result = MessageBox(
				hWnd,
				guessResult,
				title,
				MB_YESNOCANCEL | MB_ICONQUESTION
				);
			if (result == IDNO){
				++guessCounter;
				continue;
			}
			if (result == IDYES){
				++guessCounter;
				TCHAR resultInfo[100];
				swprintf_s(resultInfo, 100, TEXT("�� �������� ���� �����! ��� ������������ ��� ����� %f �������)"), guessCounter);
				MessageBox(
					hWnd,
					resultInfo,
					TEXT("����������!"),
					MB_OK | MB_ICONINFORMATION
					);
				break;
			}
			MessageBox(0, TEXT("��������, �� ���������..."), TEXT("�� ����������"), MB_OK | MB_ICONINFORMATION);
			break;
		}
	}
		break;
	case WM_DESTROY: // ��������� � ���������� ���������
		PostQuitMessage(0); // ������� ��������� WM_QUIT
		break;
	default:
		// ��� ���������, ������� �� �������������� � ������ ������� ������� 
		// ������������ ������� Windows �� ��������� �� ���������
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
