#pragma once
#include "MainHeader.h"
#define ENEMY_NUMBER 10
#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10

class GameField
{
public:
	Coo fieldSize;
	Coo deadLine;
private:
	Hero* galaxyDef;
	vector <Enemy> arrayHorde;
	vector <LaserRay> rayArray;
	int numEnemies;
	bool updateGameState(){}
public:
	GameField(int _rows, int _cols) : fieldSize{ _rows, _cols }{
		deadLine.x = -1; //-1 обозначает что эта координата не ипользуется
		deadLine.y = fieldSize.y - 2; //Смещаем дедлайн на две клетки выше игрока
		numEnemies = ENEMY_NUMBER;
		//выдаем им координаты на поле
		int enemies = 0;
		for (int i = 0; i < fieldSize.y; ++i){
			for (int j = 0; j < fieldSize.x; ++j){
				Enemy enemySource(j, i, 100, 1); //Прародитель кораблей противников
				arrayHorde.push_back(enemySource);
				if (arrayHorde.size() >= numEnemies){
					break;
				}
			}
		}
		galaxyDef = &(Hero::getInstance((fieldSize.x)/2, fieldSize.y, 100, 2)); //Создаем нашего героя
	};
	~GameField(){};
	bool createRay(Coo _shipCoo){
		LaserRay tempRay(_shipCoo);
		rayArray.push_back(tempRay);
	}
};

class Game
{
public:
	int score;
	int roundNumber;
	GameField* currentField;
	Game() :roundNumber(1), score(0)
	{
		currentField = new GameField(FIELD_WIDTH, FIELD_HEIGHT);
		//Задаем размеры поля
	}

	~Game()
	{
		delete currentField;
	}
	Coo getFieldSize(){
		return currentGame->currentField->fieldSize;
	}
};


