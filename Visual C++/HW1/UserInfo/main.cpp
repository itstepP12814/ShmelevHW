// ���� WINDOWS.H �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows. 
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
using namespace std;

// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������");	/* ��� ������ ���� */

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	TCHAR* name = TEXT("���: ���������� �����.");
	TCHAR* specialization = TEXT("�������������: ����-���������.");
	TCHAR* age = TEXT("�������: 22 ����.");

	TCHAR* title = TEXT("�, ��!");
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
