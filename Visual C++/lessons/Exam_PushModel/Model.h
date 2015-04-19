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
	float V; //��������
	float Vy; //�������� �� �
	float Vy0; //��������� �������� �� �
	float Vx; //�������� �� �
	float Vx0; //��������� �������� �� �
	float t = 0; //����� 
	float ax; //���������
	float ay; //���������
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
