#include "Fration.h"

void Fraction::print()const{
    cout << numerator << "/" << denominator << endl;
}

const Fraction Fraction::operator*(const Fraction &secondFract){
    int newNumerator = numerator*secondFract.numerator;
    int newDenominator = denominator*secondFract.denominator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}

const Fraction Fraction::operator/(const Fraction &secondFract){
    int newNumerator = numerator*secondFract.denominator;
    int newDenominator = denominator*secondFract.numerator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}

const Fraction Fraction::operator+(const Fraction &secondFract){
    int newNumerator = (numerator*secondFract.denominator)+(denominator*secondFract.numerator);
    int newDenominator = denominator*secondFract.denominator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}

const Fraction Fraction::operator-(const Fraction &secondFract){
    int newNumerator = (numerator*secondFract.denominator)-(denominator*secondFract.numerator);
    int newDenominator = denominator*secondFract.denominator;

    Fraction newFract(newNumerator,newDenominator);
    return newFract;
}
