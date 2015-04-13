#pragma once
#include "MainHeader.h"

class SpaceShip
{
public:	
	Coo shipCoo;
protected:
	int moveSpeed;
	int health;
	SpaceShip(int _x, int _y, int _health, int _moveSpeed) :shipCoo{ _x, _y }, health(_health), moveSpeed(_moveSpeed){}
	virtual ~SpaceShip(){}
};

class SingletonDestroyer //Система деструкции для синглтона
{
private:
	Hero* p_instance;
public:
	~SingletonDestroyer();
	void initialize(Hero* p);
};

class Hero : public SpaceShip //паттерн синглтон
{
private:
	static Hero * p_instance;
	static SingletonDestroyer destroyer;
	// Конструкторы и оператор присваивания недоступны клиентам
	Hero(int _x, int _y, int _health, int _moveSpeed) : SpaceShip(_x, _y, _health, _moveSpeed){}
	Hero(const Hero&);
	Hero& operator=(Hero&);
	~Hero(){}
	friend class SingletonDestroyer;
protected:
	class LaserGun
	{
	public:
		LaserGun(){};
		~LaserGun(){};
		class LaserRay
		{
		public:
			LaserRay(){};
			~LaserRay(){};
		};
		LaserRay* deathRay;
	};

	LaserGun* shipGun;

	static Hero& getInstance(int _x_, int _y_, int _health_, int _moveSpeed_);
	static Hero& getInstance(void);
};

Hero* Hero::p_instance = 0;

SingletonDestroyer Hero::destroyer;

SingletonDestroyer::~SingletonDestroyer() {
	delete p_instance;
}
void SingletonDestroyer::initialize(Hero* p) {
	p_instance = p;
}

Hero& Hero::getInstance(int _x_, int _y_, int _health_, int _moveSpeed_) {
	if (!p_instance){
		p_instance = new Hero(_x_, _y_, _health_, _moveSpeed_);
		destroyer.initialize(p_instance);
	}

	return *p_instance;
}

Hero& Hero::getInstance() {
	return *p_instance;
}
