/*Программа демострирует работу в многопоточном режиме. Есть два потока для вычисления простых чисел
(параллельные вычисления), а так же два потока для инкремента (синхронизированы критической секцией,
не параллельны)*/

#include <Windows.h>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

CRITICAL_SECTION cs;
LONGLONG x = 0;
vector <long> finalResult;
int numberOfThreads = 4;
long NEEDLE_NUMBER = 100000;

long simpleNumberCheck(int num){
	for (int i = num - 1; i >= 2; --i){
		if (num % i){ //Не делиться (кандидат на простое)
			continue;
		}
		else{
			return 0;
		}
	}
	return num;
}

DWORD WINAPI IncThread(LPVOID lp){
	EnterCriticalSection(&cs);
	for (int i = 0; i < 10000000; i++){
		InterlockedIncrement64(&x);
		/*x++;*/
	}
	LeaveCriticalSection(&cs);
	return 1;
}

DWORD WINAPI DecThread(LPVOID lp){
	EnterCriticalSection(&cs); //Есть критическая секция - потоки будут синхронизированы (паралельность отсутствует)
	for (int i = 0; i < 10000000; i++){
		InterlockedIncrement64(&x);
		/*x--;*/
	}
	LeaveCriticalSection(&cs);
	return 1;
}

DWORD WINAPI numberSearch(LPVOID lp){
	vector <long> result; //Cюда складываем результат поиска простых чисел
	for (int i = (int)lp + 3; i < NEEDLE_NUMBER; i+=2){
		result.push_back(simpleNumberCheck(i));
	}
	finalResult.reserve(finalResult.size() + result.size());
	finalResult.insert(finalResult.end(), result.begin(), result.end());
	//Не используется критическая секция
	//Вычисление будет идти на двух ядрах параллельно (в два потока)
	return true;
}

int main()
{
//	InitializeCriticalSection(&cs);//Только инициализируем критическую секцию - не входим в неё пока.
	unsigned int start_time = clock(); // начальное время
	vector <HANDLE> threads;
	for (int i = 0; i < numberOfThreads; ++i){
		threads.push_back(CreateThread(NULL, 0, numberSearch, (LPVOID)i, 0, NULL));
	}
	/*CreateThread(NULL, 0, IncThread, 0, 0, NULL),
	CreateThread(NULL, 0, DecThread, 0, 0, NULL)*/
	WaitForMultipleObjects(threads.size(), threads.data(), TRUE, INFINITE);
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time;

	if (finalResult.size() != 0){
		for (auto number : finalResult){
			if (number != 0){
				cout << number << " ";
			}
		}
	}
	cout << endl << "Used threads: " << numberOfThreads << endl;
	cout << "Run time: " << search_time << " milliseconds." << endl;
	//DeleteCriticalSection(&cs);
	
	return 0;
}