#ifndef SOLVER_H
#define SOLVER_H

#include <math.h>
#include <iostream>

using namespace std;

int linear_solver(int a, int b);
long linear_solver(long a, long b);
float linear_solver(float a, float b);
double linear_solver(double a, double b);

int quadratic_solver(int a, int b, int c);
long quadratic_solver(long a, long b, long c);
float quadratic_solver(float a, float b, float c);
double quadratic_solver(double a, double b, double c);
#endif // SOLVER_H
