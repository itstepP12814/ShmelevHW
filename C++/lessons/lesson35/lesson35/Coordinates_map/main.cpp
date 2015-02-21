#include <iostream>
#include <exception>
#include <map>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

class Point{
public:
	Point(int _x, int _y) : x(_x), y(_y){}
	~Point(){}
	int x;
	int y;
	bool operator<(const Point cityCoordinates) const{
		return (pow(x, 2) + pow(y, 2)) < (pow(cityCoordinates.x, 2) + pow(cityCoordinates.y, 2));
	}
};
Point myPosition(5, 5);
int main(){
	//Point Minsk(0, 0);
	//Point Pinsk(2, 10);
	//Point Moskow(20, 3);
	//Point Brest(10, -4);

	map <Point, string> geo;

	geo[Point(0, 0)] = "Minsk";
	geo[Point(2, 10)] = "Pinsk";
	geo[Point(20, 3)] = "Moskow";
	geo[Point(10, -4)] = "Brest";

	for (pair<Point,string> p : geo){
		cout << p.second << endl;
	}

}