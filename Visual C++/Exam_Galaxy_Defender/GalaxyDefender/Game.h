#pragma once
#include <vector>
#include "Ships.h"

class GameField
{
public:
	Coo fieldSize;
	Coo deadLine;
	Hero* galaxyDef;
	vector <Enemy> arrayHorde;
	vector <LaserRay> rayArray;
private:
	static const int ENEMY_NUMBER = 10;
	int numEnemies;
	bool updateGameState(){}
public:
	GameField(size_t _rows, size_t _cols) : fieldSize{ _rows, _cols }{
		deadLine.x = -1; //-1 обозначает что эта координата не ипользуется
		deadLine.y = fieldSize.y - 2; //Смещаем дедлайн на две клетки выше игрока
		numEnemies = ENEMY_NUMBER;
		//выдаем им координаты на поле
		int enemies = 0;
		for (size_t i = 0; i < fieldSize.y; ++i){
			for (size_t j = 0; j < fieldSize.x; ++j){
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
private:
	static const int FIELD_HEIGHT = 20;
	static const int FIELD_WIDTH = 10;
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
		return currentField->fieldSize;
	}
	vector <Enemy>& getEnemies(){
		return currentField->arrayHorde;
	}
};

Game* currentGame;

