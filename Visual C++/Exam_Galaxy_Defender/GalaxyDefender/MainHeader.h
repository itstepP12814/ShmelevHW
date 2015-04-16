#pragma once
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include "resource.h"
#include "AI.h"
#include "Game.h"
#include "Ships.h"

#define FULL_HEALTH 100
#define ENEMY_SPEED 2000 //миллисекунд на клетку
#define HERO_SPEED 500//миллисекунд на клетку

using namespace std;

class Coo
{
public:
	int x;
	int y;
	Coo() :x(0), y(0){}
	Coo(int _x, int _y) : x(_x), y(_y){}
	Coo& operator=(Coo& ob){
		x = ob.x;
		y = ob.y;
		return *this;
	};
	Coo (const Coo& object)
	{
		x = object.x;
		y = object.y;
	}
};