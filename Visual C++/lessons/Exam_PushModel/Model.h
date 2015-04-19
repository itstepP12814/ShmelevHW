#pragma once
#include <math.h>
struct Coo{
	float x;
	float y;
};

class Model
{
public:
	Coo fieldSize;
	Coo ball;
	const static float G;
	const float speed;
	const float angle;
	long actualTime;
	float V; //Скорость
	float Vy; //Скорость по у
	float Vy0; //Начальная скорость по у
	float Vx; //Скорость по х
	float Vx0; //Начальная скорость по х
	float t = 0; //Время 
	float ax; //Ускорение
	float ay; //Ускорение
	const float dt = 0.1;

	Model(size_t _width, size_t _height, float _angle, int _speed) :
		 angle(_angle), speed(_speed), ax(0), ay(-G)
	{
		fieldSize = { _width, _height };
		V = speed;
		
		Vy0 = V*sin((float)angle*3.1415/180);
		Vx0 = V*cos((float)angle*3.1415/180);
		Vx = Vx0;
		Vy = Vy0;

		ball = { 0, 0 };
	}

	~Model()
	{
	}

	bool updateFieldState(){
		t += dt;
		Vx += ax*dt;
		Vy += ay*dt;
		ball.x += Vx * dt;
		ball.y += Vy * dt;
		return true;
	}

};

const float Model::G = 9.8;
