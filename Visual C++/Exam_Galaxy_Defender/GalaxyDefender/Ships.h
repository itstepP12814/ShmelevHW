#pragma once
#include "MainHeader.h"

class Hero;
class LaserRay;

//class Move { //Как бы интерфейс
//protected:
//	virtual int moveRight();
//	virtual int moveLeft();
//	virtual int moveForward();
//	virtual int moveBack();
//};

class LaserRay
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

class SpaceShip
{
public:	
	Coo shipCoo;
	static const int FULL_HEALTH = 100;
	static const int ENEMY_SPEED = 2000; //миллисекунд на клетку
	static const int HERO_SPEED = 500;//миллисекунд на клетку
	int moveSpeed;
	int health;
	int width;
	int height;
	SpaceShip(){}
	SpaceShip(int _x, int _y, int _health, int _moveSpeed, int _width, int _height) : shipCoo(_x,_y), health(_health), moveSpeed(_moveSpeed), width(_width), height(_height){
	}
	virtual ~SpaceShip(){}
};

class Enemy : public SpaceShip
{
public:
	Enemy(int _x, int _y, int _health, int _moveSpeed, int _width, int _heigth) : SpaceShip(_x, _y, _health, _moveSpeed, _width, _heigth) {};
	int moveForward(){
		return shipCoo.y += (1 * moveSpeed);
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
	Hero(int _x, int _y, int _health, int _moveSpeed, int _width, int _heigth) : SpaceShip(_x, _y, _health, _moveSpeed, _width, _heigth){
		shipGun = new LaserGun();
	}
	Hero(const Hero&);
	Hero& operator=(Hero&);
	friend class SingletonDestroyer;

public:
	static Hero& getInstance(int _x, int _y, int _health, int _moveSpeed, int _width, int _heigth);
	static Hero& getInstance(void);
	bool fire(){
		shipGun->fire(shipCoo);
	}
	int moveLeft(){
		return shipCoo.x -= 1 * moveSpeed;
	}

	int moveRight(){
		return	shipCoo.x += 1 * moveSpeed;
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

Hero& Hero::getInstance(int _x, int _y, int _health, int _moveSpeed, int _width, int _heigth) {
	if (!p_instance){
		p_instance = new Hero(_x, _y, _health, _moveSpeed, _width, _heigth);
		destroyer.initialize(p_instance);
	}

	return *p_instance;
}

Hero& Hero::getInstance() {
	return *p_instance;
}
