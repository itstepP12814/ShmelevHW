#include <iostream>
#include <stdio.h>
/*Установить 2-ой, i-ый, сбросить 3-й бит, инвертировать i-ый бит, если 1ый установлен, сказать привет
*/

using namespace std;

char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}

void printer(unsigned int x){
    char buff[30];
    itoa(x,buff,2);
    printf("%s\n", buff);
}

int main()
{
    unsigned int x = 426;
    cout << "Исходное число: ";
    printer(x);

    cout << "Установлен второй бит: ";
    int z;
    z=x|4;
    printer(z);

    int key;
    cout << "Введите бит для установки: ";
    cin >> key;
    int h = 1 << key;
    z=x|h;
    printer(z);

    cout << "Сброшен третий бит: ";
    z=x&(~(1<<3));
    printer(z);

    cout << "Введите бит для инверсии: ";
    cin >> key;
    h = 1<<key;
    z=x^key;
    printer(z);

    return 0;
}
