#pragma once
#include <vector>
#include "MainHeader.h"
#include "Game.h"
class EnemyOperator
{
public:
		EnemyOperator()
		{
			shipsForNav = currentGame->currentField->arrayHorde;
		}
		~EnemyOperator(){}

	bool makeNextStep(){
		return moveEnemyShipsForward();
	}

private:
	vector <Enemy*> shipsForNav;
	bool moveEnemyShipsForward(){
		for (auto enemyShip : shipsForNav){
			if (enemyShip->shipCoo.y <= currentGame->currentField->deadLine.y){
				enemyShip->moveForward();
			}
			else{
				return false;
			}
		}
		return true;
	}
};

