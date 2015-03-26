using namespace std;
#include <Windows.h>
#include <windowsx.h>
#include "resource.h"
#include <vector>
#define MIN_SIZE 10
HINSTANCE hInst;
static int elementID = 0;
struct StaticElement{
	HWND handle;
	int x, y, number, height, width;
};
vector <StaticElement> elArr;
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

StaticElement findNeedleElement(int cursorPosX, int cursorPosY){
//Функция поиска элемента по координатам
	vector <StaticElement> searchResults;
	StaticElement finalResult;
	//Ищем все подпадающие под координаты элементы
	if (elArr.size() != 0){
		for (vector<StaticElement>::iterator p = elArr.begin(); p != elArr.end(); ++p){
			StaticElement elem = *p;
			if (cursorPosX >= elem.x && cursorPosX <= (elem.width + elem.x) &&
				cursorPosY >= elem.y && cursorPosY <= (elem.height + elem.y))
			{
				searchResults.push_back(elem);
			}
		}
		//В этой точке может быть один и более элементов
		if (searchResults.size() > 1){
			int maxNumber = 0;
			//Ищем элемент с наибольшим номером среди результатов поиска
			for (vector<StaticElement>::iterator p = searchResults.begin(); p != searchResults.end(); ++p){
				if ((*p).number > maxNumber){
					maxNumber = (*p).number;
				}
			}
			//Получаем элемент
			for (vector<StaticElement>::iterator p = searchResults.begin(); p != searchResults.end(); ++p){
				if ((*p).number == maxNumber){
					finalResult = *p;
				}
			}
		}
		else{
			finalResult = searchResults[0];
		}
		return finalResult;
	}
	else{
		StaticElement nullEl = { 0, 0, 0, 0, 0, 0 };
		return nullEl;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow){
	MSG msg;
	HWND hDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	ShowWindow(hDialog, nCmdShow);
	//SetFocus(hDialog);
	//UpdateWindow(hDialog);
	while (GetMessage(&msg, 0, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp){
	static int x1, x2, y1, y2;
	switch (message)
	{
	case WM_CLOSE:{
			// закрываем немодальный диалог
			DestroyWindow(hWnd); // разрушаем окно
			PostQuitMessage(0); // останавливаем цикл обработки сообщений
			}
			return TRUE;
	case WM_RBUTTONDOWN:{
			y1 = GET_Y_LPARAM(lp);
			x1 = GET_X_LPARAM(lp);
			}
			return TRUE;
	case WM_RBUTTONUP:{
			y2 = GET_Y_LPARAM(lp);
			x2 = GET_X_LPARAM(lp);
			int elementHeight = y2 - y1;
			int elementWidth = x2 - x1;
			int x3 = x1;
			int y3 = y1;
				if (elementHeight >= MIN_SIZE && elementWidth >= MIN_SIZE){
					HWND hElement = CreateWindowEx(0, TEXT("STATIC"), 0,
						WS_BORDER | WS_CHILD | WS_VISIBLE, x3, y3, elementWidth, elementHeight, hWnd, (HMENU)elementID, hInst, 0);
					//Создаем обьект структуры с данными элемента
					StaticElement tempEl = { hElement, x1, y1, elementID, elementHeight, elementWidth };
					elArr.push_back(tempEl);
					TCHAR elementText[100];
					wsprintf(elementText, TEXT("Элемент №%d"), elementID+1);
					SetWindowText(tempEl.handle, elementText);
					++elementID;
				}
				else{
					if (elementHeight != 0 && elementWidth != 0){
						//Если хоть немного смещается курсор при клике
						MessageBox(hWnd, TEXT("Элемент не может быть менее 10х10."), TEXT("Предупреждение"), MB_OK | MB_ICONWARNING);
					}
					else{ //Случай, когда пользователь просто делает клик в точке
						int cursorPosY = GET_Y_LPARAM(lp);
						int cursorPosX = GET_X_LPARAM(lp);
						StaticElement result = findNeedleElement(cursorPosX, cursorPosY);
						TCHAR captionStr[100];
						wsprintf(captionStr, TEXT("Выбрано: Элемент №%d - %dx%d, X:%d, Y:%d"),
							result.number + 1, result.height, result.width, result.x, result.y);
						SetWindowText(hWnd, captionStr);
					}
				}
			}
			return TRUE;
	case WM_LBUTTONDBLCLK:{
		//Удаляем элемент
		int cursorPosY = GET_Y_LPARAM(lp);
		int cursorPosX = GET_X_LPARAM(lp);
		StaticElement result = findNeedleElement(cursorPosX, cursorPosY);
		DestroyWindow(result.handle);
			if (elArr.size() != 0){
				vector<StaticElement>::iterator itr;
				for (itr = elArr.begin(); itr != elArr.end(); ++itr){
					if ((*itr).handle == result.handle){break;}
				}
				elArr.erase(itr);
			}
		}
			return TRUE;
	}
	return FALSE;
}
