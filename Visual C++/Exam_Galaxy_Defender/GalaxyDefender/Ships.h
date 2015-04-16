#pragma once
#include "MainHeader.h"

#define FIRE_FREQ 100


class Move { //Как бы интерфейс
protected:
	virtual bool moveRight();
	virtual bool moveLeft();
	virtual bool moveForward();
	virtual bool moveBack();
};

class SpaceShip : public Move
{
public:	
	Coo shipCoo;
protected:
	int moveSpeed;
	int health;
	SpaceShip(){}
	SpaceShip(int _x, int _y, int _health, int _moveSpeed) : shipCoo(_x,_y), health(_health), moveSpeed(_moveSpeed){
	}
	virtual ~SpaceShip(){}
};

class Enemy : public SpaceShip{
public:
	Enemy() : SpaceShip(0, 0, 0, 0) {}
	Enemy(int _x, int _y, int _health, int _moveSpeed) : SpaceShip(_x, _y, _health, _moveSpeed) {};
	~Enemy(){}
	bool moveForward(){
		if (shipCoo.y + (1 * moveSpeed) >= currentGame->getFieldSize().x)
		{
			shipCoo.y += 1 * moveSpeed;
			return true;
		}
		else{
			return false;
		}
	}
};

class SingletonDestroyer //Система деструкции для синглтона
{
private:
	Hero* p_instance;
public:
	~SingletonDestroyer();
	void initialize(Hero* p);
};

class Hero : public SpaceShip//паттерн синглтон
	//Создавать единственный обьект класса следует через функцию getInstance
{
private:
	static Hero * p_instance;
	static SingletonDestroyer destroyer;
	// Конструкторы и оператор присваивания недоступны клиентам
	Hero(int _x, int _y, int _health, int _moveSpeed) : SpaceShip(_x, _y, _health, _moveSpeed){
		shipGun = new LaserGun();
	}
	Hero(const Hero&);
	Hero& operator=(Hero&);
	~Hero(){}
	friend class SingletonDestroyer;

public:
	static Hero& getInstance(int _x_, int _y_, int _health_, int _moveSpeed_);
	static Hero& getInstance(void);
	bool moveLeft();
	bool moveRight();
	bool fire(){
		shipGun->fire(shipCoo);
	}

protected:
	class LaserGun
	{
	public:
		int fireFreq;
		LaserGun():fireFreq(FIRE_FREQ){};
		~LaserGun(){};
		bool fire(Coo _shipCoo){
			currentGame->currentField->createRay(_shipCoo);
		}
	};

	LaserGun* shipGun;
};

class LaserRay : public Move
{
protected:
	int width;
	int heigth;
	int raySpeed;
	friend class LaserGun;
	Coo rayCoo;
public:
	LaserRay(Coo _shipCoo) : width(1), heigth(1), rayCoo(_shipCoo){};
	~LaserRay(){};
	bool moveForward(){
		if (rayCoo.y - (1 * raySpeed) <= currentGame->getFieldSize().y){
			rayCoo.y -= (1 * raySpeed);
			return true;
		}
		else
		{
			return false;
		}
	}
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

bool Hero::moveLeft(){
	if (shipCoo.x-(1*moveSpeed) >= 0)
	{
		shipCoo.x -= 1 * moveSpeed;
		return true;
	}
	else{
		return false;
	}
}

bool Hero::moveRight(){
	if (shipCoo.x + (1 * moveSpeed) >= currentGame->getFieldSize().x)
	{
		shipCoo.x += 1 * moveSpeed;
		return true;
	}
	else{
		return false;
	}
}
