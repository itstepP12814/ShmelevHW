#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <exception>
#include <string>
#include <vector>
using namespace std;

class Player;

class Field
{
public:
	friend Player;
	Field(int _height, int _width) : height(_height), width(_width){
		cout << "Field size: " << width << "x" << height << endl;
		dir = { "south", "north", "west", "east" };
	};
	~Field(){};
	int height;
	int width;
	vector <string> dir;
};

struct Position{
	int x;
	int y;
};

class Player
{
private:
	Position current_position;
	string direction;
public:
	Field* landscape;
	Player(Field& field_c){
		landscape = &field_c;
		int x = rand() % (1+(landscape->width))+1;
		int y = rand() % (1+(landscape->height))+1;

		current_position = { x, y };
		cout << "Player start position: " << current_position.x << "x" << current_position.y << endl;
	};
	~Player(){};

	bool move(){
		int direction_number = rand() % 4 + 1;
		switch (direction_number)
		{
		case 1:
			if ((current_position.y - 1) > 0 && (current_position.y - 1) <= landscape->height){
				direction = landscape->dir[direction_number-1];
				--(current_position.y);
			}
			break;
		case 2:
			if ((current_position.x + 1) > 0 && (current_position.x + 1) <= landscape->width){
				direction = landscape->dir[direction_number - 1];
				++(current_position.x);
			}
			break;
		case 3:
			if ((current_position.y + 1) > 0 && (current_position.y + 1) <= landscape->height){
				direction = landscape->dir[direction_number - 1];
				++(current_position.y);
			}
			break;
		case 4:
			if ((current_position.x - 1) > 0 && (current_position.x - 1) <= landscape->width){
				direction = landscape->dir[direction_number - 1];
				--(current_position.x);
			}
			break;
		default:
			throw exception("Error: wrong rand work.\n");
			break;
		}
	}

	int getX(){ return current_position.x; };
	int getY(){ return current_position.y; };
	string getDirection(){ return direction; };

};

int main(){
	srand(time(NULL));
	Field a1(5, 6);
	Player alex(a1);
	cout << "Current positions: \n";
	while (1){
		alex.move();
		//cout << alex.getDirection() << endl;
		cout << alex.getX() << "x" << alex.getY() << endl;
		int l = time(0);
		while (l == time(0));
	}
	
	return 0;
}