#pragma once
using namespace std;

class Coo
{
public:
	size_t x;
	size_t y;
	Coo() :x(0), y(0){}
	Coo(size_t _x, size_t _y) : x(_x), y(_y){}
	~Coo(){}
};