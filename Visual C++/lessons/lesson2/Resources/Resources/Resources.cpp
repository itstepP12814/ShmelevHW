/*При нажатии на кнопки 1 2 3 менять изображение курсора*/
#include <windows.h>
#include "resource.h"
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");
HICON hIcon;
HCURSOR hCursor1, hCursor2, hCursor3;

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);	
	wcl.style = CS_HREDRAW | CS_VREDRAW;	
	wcl.lpfnWndProc = WindowProc;	
	wcl.cbClsExtra = 0;	
	wcl.cbWndExtra = 0; 	
	wcl.hInstance = hInst;	
	wcl.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)); // иконка загружается из ресурсов приложения	
	wcl.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1));	// курсор загружается из ресурсов приложения	
	wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH); 
	wcl.lpszMenuName = NULL;	
	wcl.lpszClassName = szClassWindow;	
	wcl.hIconSm = NULL;	
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Ресурсы"), WS_OVERLAPPEDWINDOW,	
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while(GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);	
		DispatchMessage(&Msg);	
	}
	return Msg.wParam;
}	


LRESULT CALLBACK WindowProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY: 
			PostQuitMessage(0);
			break;
		case WM_CREATE:
			{
				// получаем дескриптор приложения
				HINSTANCE hInstance = GetModuleHandle(0); 
				// загружаем иконку из ресурсов приложения
				hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)); 
				// загружаем курсоры из ресурсов приложения
				hCursor1 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
				hCursor2 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR2)); 
				hCursor3 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_POINTER_COPY));
			}
			break;
		case WM_KEYDOWN:
			if (wParam == '1'){
				SetCursor(hCursor1);
				SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor1));
			}
			if (wParam == '2'){
				SetCursor(hCursor2);
				SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor2));
			}
			if (wParam == '3'){
				SetCursor(hCursor2);
				SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor3));
			}
			break;
		//case WM_MOUSEMOVE:
		//	{
		//		// устанавливаем тот или иной курсор в зависимости от местонахождения указателя мыши
		//		RECT rect;
		//		GetClientRect(hWnd, &rect);
		//		int x = LOWORD(lParam);
		//		int y = HIWORD(lParam);
		//		if(x >= rect.right / 4 && x <= rect.right * 3 / 4 && 
		//		   y >= rect.bottom / 4 && y <= rect.bottom * 3 / 4)
		//			SetCursor(hCursor1); 
		//		else
		//			SetCursor(hCursor2); 
		//	}
		//	break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

