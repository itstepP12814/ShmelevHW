#include "Fration.h"

void Fraction::print()const {
    cout << numerator << "/" << denominator << endl;
}

const Fraction Fraction::operator*(const Fraction &secondFract) {
    int newNumerator = numerator*secondFract.numerator;
    int newDenominator = denominator*secondFract.denominator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}

const Fraction Fraction::operator/(const Fraction &secondFract) {
    int newNumerator = numerator*secondFract.denominator;
    int newDenominator = denominator*secondFract.numerator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}

const Fraction Fraction::operator+(const Fraction &secondFract) {
    int newNumerator = (numerator*secondFract.denominator)+(denominator*secondFract.numerator);
    int newDenominator = denominator*secondFract.denominator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}

const Fraction Fraction::operator-(const Fraction &secondFract) {
    int newNumerator = (numerator*secondFract.denominator)-(denominator*secondFract.numerator);
    int newDenominator = denominator*secondFract.denominator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}


int Fraction::findNOD() {
    int NOD;
    ///пускать этот код только в случае когда А>B, присваивать им значения числителя и знаменателя соответсвенно
    int A = 1;
    int B = 1;
    int a = numerator;
    int b = denominator;

    while(B!=0) {
        int multiNumber = 1;
        while(a>(b*multiNumber)) {
            ++multiNumber;
        }
        B = a-(b*multiNumber);
        A = b;
        if(B!=0) {
            a = A;
            b = B;
        }
    }
    NOD = b;
    cout << NOD;
}
