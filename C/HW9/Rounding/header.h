#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T, typename N> T rounder(N a, T precision){
    cout << fixed << setprecision(precision) << a;
}

#endif // HEADER_H_INCLUDED
