#pragma once
#include "MainHeader.h"


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
	bool updateGameState(){
		gameAI.moveEnemyShipsForward();
	}
public:
	GameField(int _rows, int _cols) : fieldSize{ _rows, _cols }{
		deadLine.x = -1; //-1 обозначает что эта координата не ипользуется
		deadLine.y = fieldSize.y - 2; //Смещаем дедлайн на две клетки выше игрока
		numEnemies = ENEMY_NUMBER;
		//выдаем им координаты на поле
		int enemies = 0;
		for (int i = 0; i < fieldSize.y; ++i){
			for (int j = 0; j < fieldSize.x; ++j){
				Enemy enemySource(? ? ? ); //Прародитель кораблей противников
					arrayHorde.shipCoo.x = j;
					enem.shipCoo.y = i;
				if (arrayHorde.size() >= numEnemies){
					break;
				}
			}
		}
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


