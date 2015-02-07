#ifndef FRATION_H
#define FRATION_H
#include <iostream>

using namespace std;


class Fraction
{
    public:
        int numerator;
        int denominator;
        Fraction (int a, int b):numerator(a), denominator(b){};
		//Fraction(int a) :numerator(a), denominator(1){};
		explicit Fraction(int a) :numerator(a), denominator(1){}; //Со словом explicit неявное преобразование запрещено
        void print()const;
        int findNOD();
		operator double(){ return ((double)numerator) / denominator; } //Перегрузка операции преобразования Fraction в double
        const Fraction operator*(const Fraction &secondFract);
        const Fraction operator/(const Fraction &secondFract);
        const Fraction operator+(const Fraction &secondFract);
        const Fraction operator-(const Fraction &secondFract);

        ///перегрузить *,/,+,-,++,--
        ///рассчитать число Пи
};

#endif // FRATION_H
