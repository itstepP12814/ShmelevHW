// Файл WINDOWS.H содержит определения, макросы, и структуры 
// которые используются при написании приложений под Windows. 
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");	/* Имя класса окна */

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	srand(time(NULL));

	// 1. Определение класса окна
	wcl.cbSize = sizeof(wcl);	// размер структуры WNDCLASSEX
	// Перерисовать всё окно, если изменён размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - стиль класса окна
	wcl.lpfnWndProc = WindowProc;	// адрес оконной процедуры
	wcl.cbClsExtra = 0;		// используется Windows 
	wcl.cbWndExtra = 0; 	// используется Windows 
	wcl.hInstance = hInst;	// дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// заполнение окна белым цветом
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна

	// 2. Регистрация класса окна
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

	// 3. Создание окна
	// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		szClassWindow,	//имя класса окна
		TEXT("Каркас Windows приложения"), // заголовок окна
		WS_OVERLAPPEDWINDOW,				// стиль окна
		/* Заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна  */
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		CW_USEDEFAULT,	// ширина окна
		CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL);		// указатель на область данных приложения

	HWND button = CreateWindow(
		TEXT("BUTTON"),
		TEXT("Угадать число"),
		WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_DEFPUSHBUTTON,
		200,
		200,
		400,
		150,
		hWnd,
		(HMENU)100,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);

	// 4. Отображение окна
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна

	// 5. Запуск цикла обработки сообщений

	while (GetMessage(&lpMsg, NULL, 0, 0)) // получение очередного сообщения из очереди сообщений
	{
		TranslateMessage(&lpMsg);	// трансляция сообщения
		DispatchMessage(&lpMsg);	// диспетчеризация сообщений
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	int result = 0;
	TCHAR* title = TEXT("Результат угадывания");
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
				swprintf_s(resultInfo, 100, TEXT("Мы отгадали ваше число! Нам понадобилось для этого %f попыток)"), guessCounter);
				MessageBox(
					hWnd,
					resultInfo,
					TEXT("Получилось!"),
					MB_OK | MB_ICONINFORMATION
					);
				break;
			}
			MessageBox(0, TEXT("Извините, мы старались..."), TEXT("Не получилось"), MB_OK | MB_ICONINFORMATION);
			break;
		}
	}
		break;
	case WM_DESTROY: // сообщение о завершении программы
		PostQuitMessage(0); // посылка сообщения WM_QUIT
		break;
	default:
		// все сообщения, которые не обрабатываются в данной оконной функции 
		// направляются обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
