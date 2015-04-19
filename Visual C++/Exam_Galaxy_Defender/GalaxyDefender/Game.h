#pragma once
#include <vector>
#include "Ships.h"
class GameField
{
public:
	Coo fieldSize;
	Coo deadLine;
	Hero* galaxyDef;
	vector <Enemy*> arrayHorde;
	vector <LaserRay*> rayArray;
private:
	static const int ENEMY_NUMBER = 20;
	unsigned int numEnemies;
public:
	GameField(size_t _rows, size_t _cols) : fieldSize{ _rows, _cols }{
		deadLine.x = -1; //-1 обозначает что эта координата не ипользуется
		deadLine.y = fieldSize.y - 1; //Смещаем дедлайн на клетку выше игрока
		numEnemies = ENEMY_NUMBER;
		//выдаем им координаты на поле
		int enemies = 0;
		int shipWidth = 1;
		int shipHeigth = 1;
		for (size_t i = 0; i < fieldSize.y; i+=shipHeigth){
			for (size_t j = 0; j < fieldSize.x; j+=shipWidth){
				Enemy* enemySource = new Enemy(j, i, 100, 1, shipWidth, shipHeigth); //Прародитель кораблей противников
				arrayHorde.push_back(enemySource);
				if (arrayHorde.size() >= numEnemies){
					break;
				}
			}
			if (arrayHorde.size() >= numEnemies){
				break;
			}
		}
		galaxyDef = &(Hero::getInstance((fieldSize.x)/2, fieldSize.y, 100, 1, 1, 1)); //Создаем нашего героя
	};
	~GameField(){};
	bool createRay(Coo _shipCoo){
		LaserRay* tempRay = new LaserRay(_shipCoo);
		rayArray.push_back(tempRay);
	}

};

class Game
{
private:
	static const int FIELD_HEIGHT = 10;
	static const int FIELD_WIDTH = 10;
public:
	bool gameOver;
	int score;
	int roundNumber;
	GameField* currentField;
	Game() :roundNumber(1), score(0), gameOver(false)
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
	vector <Enemy*>& getEnemies(){
		return currentField->arrayHorde;
	}
};

Game* currentGame;

