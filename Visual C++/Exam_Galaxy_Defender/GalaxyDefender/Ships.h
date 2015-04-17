#pragma once
#include "MainHeader.h"

class Hero;
class LaserRay;

class Move { //Как бы интерфейс
protected:
	virtual int moveRight();
	virtual int moveLeft();
	virtual int moveForward();
	virtual int moveBack();
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
	LaserRay(Coo _shipCoo) : width(1), heigth(1), raySpeed(1), rayCoo(_shipCoo){};
	~LaserRay(){};
	int moveForward(){
		return rayCoo.y -= (1 * raySpeed);
	}
};

class SpaceShip : public Move
{
public:	
	Coo shipCoo;
protected:
	static const int FULL_HEALTH = 100;
	static const int ENEMY_SPEED = 2000; //миллисекунд на клетку
	static const int HERO_SPEED = 500;//миллисекунд на клетку
	int moveSpeed;
	int health;
	SpaceShip(){}
	SpaceShip(int _x, int _y, int _health, int _moveSpeed) : shipCoo(_x,_y), health(_health), moveSpeed(_moveSpeed){
	}
	virtual ~SpaceShip(){}
};

class Enemy : public SpaceShip
{
public:
	Enemy() : SpaceShip(0, 0, 0, 0) {}
	Enemy(int _x, int _y, int _health, int _moveSpeed) : SpaceShip(_x, _y, _health, _moveSpeed) {};
	~Enemy(){}
	int moveForward(){
		return shipCoo.y + (1 * moveSpeed);
	}
	Coo getCoo(){
		return shipCoo;
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
	int moveLeft();
	int moveRight();
	bool fire(){
		shipGun->fire(shipCoo);
	}

protected:
	class LaserGun
	{
	public:
		static const int FIRE_FREQ = 100;
		int fireFreq;
		LaserGun():fireFreq(FIRE_FREQ){};
		~LaserGun(){};
		LaserRay fire (Coo _shipCoo){
			return LaserRay(_shipCoo);
		}
	};

	LaserGun* shipGun;
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

int Hero::moveLeft(){
	return shipCoo.x -= 1 * moveSpeed;
}

int Hero::moveRight(){
	return	shipCoo.x += 1 * moveSpeed;
}
