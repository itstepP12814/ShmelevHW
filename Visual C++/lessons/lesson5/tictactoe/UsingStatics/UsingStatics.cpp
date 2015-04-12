/*
1. ���������� gameover � ��� �������
2. + �������� ������ ����� ���� 
3. �������� �������������:
	�������-�������
	�������-���������
*/

#include <windows.h>
#include <vector>
#include <map>
#include <tchar.h>
#include <cstdlib>
#include "resource.h"
#include <string>
#define UNINIT 100000000

using namespace std;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK clearField(HWND hExWnd, LPARAM lParam);

HWND hButton;
TCHAR szCoordinates[20];
HINSTANCE hInst;
int WIDTH = 50, HEIGHT = 50; 
int LEFT_MARGIN = 30;
int TOP_MARGIN = 30;
int LEFT = LEFT_MARGIN;
int TOP = TOP_MARGIN;

enum Figure {Empty, Krestik, Nolik, UnInit};

class Model {

public:
	const size_t height, width;
	enum GameState { Draw, XWINS, OWINS };
	vector<vector<Figure> > field;  
	Figure win = UnInit;
	Figure move;
	bool gameover;
public:
	Model(size_t height_, size_t width_)
		:
		height(height_), width(width_),
		field(height, vector<Figure>(width, Empty)),
		win(Empty), move(Krestik),
		gameover(false)
	{
	}

	Figure checkGameState(Figure moveChar){
		int winFlag;
		//�������� �� �������
		for (int i = 0; i < field.size(); ++i){
			for (int j = 0; j < field[i].size(); ++j){
				if (i == 0){
					//�������� ������� ������ ��� ����� ��������� �� ����� ������ ����
					winFlag = 0;
				}
				if (field[i][j] == moveChar){
					//���� ������ ����� � ������ ��� ���� - �������
					winFlag++;
					if (winFlag == 3){
						return moveChar;
					}
				}
			}
		}
		//��������� �� ��������
		for (int i = 0; i < field.size(); ++i){
			for (int j = 0; j < field[i].size(); ++j){
				if (i == 0){
					//�������� ������� ������ ��� ����� ��������� �� ����� ������ ����
					winFlag = 0;
				}
				if (field[j][i] == moveChar){
					//���� ������ ����� � ������ ��� ���� - �������
					winFlag++;
					if (winFlag == 3){
						return moveChar;
					}
				}
			}
		}
	}
	bool makemove(size_t row, size_t col) {
		if (field[row][col] == Empty) {
			field[row][col] = move;
			if (move == Krestik) {
				move = Nolik;
			}
			else {
				move = Krestik;
			}
			if (checkGameState(Krestik)) {
				win = Krestik;
			}
			else{
				if (checkGameState(Nolik)){
					win = Nolik;
				}
			}
		}
		return false;
	}
};


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(0);
	hInst = hInstance;
	// ������ ������� ���� ���������� �� ������ ���������� �������
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc); 
}

struct coo {
	size_t row, col;
};

map<HWND, coo> buttons;
map<HWND, coo> :: iterator it;

Model* game;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	switch(message)
	{
	case WM_COMMAND: {

		//////// NEW GAME
		if (wParam == IDC_NEW_GAME){
			delete game;
			game = new Model(3, 3);
			EnumChildWindows(hWnd, clearField, 0);
		}
		else{
			it = buttons.find((HWND)lParam);
			int i = it->second.row;
			int j = it->second.col;
			game->makemove(i, j);
			if (game->win == Krestik){
				MessageBox(hWnd, TEXT("�������� ��������"), TEXT("���� ��������"), MB_OK);
			}
			if (game->win == Nolik){
				MessageBox(hWnd, TEXT("�������� ������"), TEXT("���� ��������"), MB_OK);
			}
			//if (game->gameover)
			//MessageBox(hWnd, TEXT("GAMEOVER"), TEXT("GAMEOVER"), MB_OK);
			//else

			/// VIEW
			for (auto p : buttons) {
				i = p.second.row;
				j = p.second.col;

				switch (game->field[i][j]) {
				case Krestik:
					SetWindowText(p.first, TEXT("X"));
					break;
				case Nolik:
					SetWindowText(p.first, TEXT("O"));
					break;
				}
			}


			/// END VIEW
		}
	/// ���� ������ ��� ����������  - ������� ���
	/// �� ������ ��������� �� ����� ������ ����� ���������
	/// ���������� ���� ���� ��������� � ������� ������
		return TRUE; 
	}
		case WM_CLOSE:
			EndDialog(hWnd, 0); // ��������� ��������� ������
			return TRUE;
		// WM_INITDIALOG - ������ ��������� �������� ����� �������� ����������� ����, �� ����� ��� ������������ �� �����
		case WM_INITDIALOG:	
			
			game = new Model(3, 3);

			SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 350 /*width*/, 280 /*height*/, SWP_NOMOVE);
			
			//������ ������ � ������� CreateWindowEx
			for (int ico = 0; ico < 3; ico++)
			{
				for (int jco = 0; jco < 3; jco++)
				{
					buttons[CreateWindowEx(0, TEXT("BUTTON"), 0,
						WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
						LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0)

					] = coo{ ico, jco};
					LEFT += 50;
				}
				LEFT = LEFT_MARGIN;
				TOP += 50;
			}


			return TRUE;
		case WM_MOUSEMOVE:
			wsprintf(szCoordinates, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // ������� ���������� ������� ����
		//	SetWindowText(hStatic1, szCoordinates);	// ������ ��������� �� ������
			return TRUE;
		case WM_LBUTTONDOWN:
	//		SetWindowText(hStatic2, TEXT("������ ����� ������ ����"));
			return TRUE;
		case WM_RBUTTONDOWN:
		//	SetWindowText(hStatic2, TEXT("������ ������ ������ ����"));
			return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK clearField(HWND hExWnd, LPARAM lParam){
	if (hExWnd != GetDlgItem(0, IDC_NEW_GAME)){
		SetWindowText(hExWnd, TEXT(""));
	}
	return TRUE;
}