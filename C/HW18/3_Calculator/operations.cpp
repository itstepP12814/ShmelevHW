#include "header.h"

double addition(double firstElement, double secondElement){
    return firstElement+secondElement;
}

double subtraction(double firstElement, double secondElement){
    return firstElement-secondElement;
}

double multiplication(double firstElement, double secondElement){
    return firstElement*secondElement;
}

double devision(double firstElement, double secondElement){
    return firstElement/secondElement;
}

double exponentiation(double firstElement, double secondElement){
    return pow(firstElement, secondElement);
}

void (*operationChooser[])(double, double) = {addition,subtraction,multiplication,devision,exponentiation};
