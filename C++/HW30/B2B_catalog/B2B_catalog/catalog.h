#pragma once
#include <string>
#include <fstream>
#include <exception>
#include <vector>
class Catalog;
class Item{
public:
	friend Catalog;
	Item(){};
	~Item(){};
	std::string nameCorp;
	std::string owner;
	std::string phone;
	std::string address;
	std::string lineOfBusiness;

};

class Catalog {
public:
	std::string filename = "DB.csv";
	std::vector <Item> DB_array;
	size_t sizeBD = 0;
	void addNew();
	void showAll();
	void readDB();
	void search(const std::string& needle, int trigger);
	Catalog(){};
	virtual ~Catalog(){};
};