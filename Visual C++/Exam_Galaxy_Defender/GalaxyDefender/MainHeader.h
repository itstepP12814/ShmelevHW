#include <Windows.h>
#include <tchar.h>
#include <vector>
#include "resource.h"
#include "AI.h"
#include "Game.h"
#include "Ships.h"

#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10
#define ENEMY_NUMBER 10
#define FULL_HEALTH 100
#define ENEMY_SPEED 2000 //миллисекунд на клетку
#define HERO_SPEED 500//миллисекунд на клетку
#define FIRE_FREQ 100
using namespace std;


class Coo
{
public:
	int x;
	int y;
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