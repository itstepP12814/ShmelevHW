#include "header.h"

int linear_solver(int a, int b){
    int result;

    b = -(b);
    result = a/b;

return result;
}

long linear_solver(long a, long b){
    long result;

    b = -(b);
    result = a/b;

return result;
}

float linear_solver(float a, float b){
    float result;

    b = -(b);
    result = a/b;

return result;
}

double linear_solver(double a, double b){
    double result;

    b = -(b);
    result = a/b;

return result;
}

//Перегруженные функции квадратичных уравнений

int quadratic_solver(int a, int b, int c){
    int x1;
    int x2;

    x1 = ((-(b) + sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));
    x2 = ((-(b) - sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));

    if (x1 == x2){
        cout << endl << "Корень уравнения: " << x1;
    }
    else{
        cout << endl << "Корень уравнения: " << x1 << " и " << x2;
    }
    return 0;
}

long quadratic_solver(long a, long b, long c){
    long x1;
    long x2;

    x1 = ((-(b) + sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));
    x2 = ((-(b) - sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));

    if (x1 == x2){
        cout << endl << "Корень уравнения: " << x1;
    }
    else{
        cout << endl << "Корень уравнения: " << x1 << " и " << x2;
    }
    return 0;
}

float quadratic_solver(float a, float b, float c){
    float x1;
    float x2;

    x1 = ((-(b) + sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));
    x2 = ((-(b) - sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));

    if (x1 == x2){
        cout << endl << "Корень уравнения: " << x1;
    }
    else{
        cout << endl << "Корень уравнения: " << x1 << " и " << x2;
    }
    return 0;
}

double quadratic_solver(double a, double b, double c){
    double x1;
    double x2;

    x1 = ((-(b) + sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));
    x2 = ((-(b) - sqrt(pow((b),2)-(4*(a)*(c))))/2*(a));

    if (x1 == x2){
        cout << endl << "Корень уравнения: " << x1;
    }
    else{
        cout << endl << "Корень уравнения: " << x1 << " и " << x2;
    }
    return 0;
}
