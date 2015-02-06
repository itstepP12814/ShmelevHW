#include "catalog.h"
#include <iostream>
void Catalog::addNew(){
	Item newItem;
	std::ofstream outFile(filename, std::ios::out|std::ios::app);
	if (!outFile.is_open()){
		throw std::exception("Error: Can't open file for write.\n");
	}
	std::cout << "Adding of new Item:\nEnter name of corporation: ";
	std::cin >> newItem.nameCorp;
	std::cout << "Enter Owner of corporation: ";
	std::cin >> newItem.owner;
	std::cout << "Enter phone number: ";
	std::cin >> newItem.phone;
	std::cout << "Enter post address: ";
	std::cin >> newItem.address;
	std::cout << "Enter line of business:";
	std::cin >> newItem.lineOfBusiness;

	std::cout << newItem.nameCorp << " " << newItem.owner << " " << newItem.phone << " " << newItem.address << " " << newItem.lineOfBusiness << std::endl;
	outFile << "\n" << newItem.nameCorp << ";" << newItem.owner << ";" << newItem.phone << ";" << newItem.address << ";" << newItem.lineOfBusiness << ";";
	outFile.close();
}

void Catalog::showAll(){
	std::ifstream inFile(filename, std::ios::in);
	if (!inFile.is_open()){
		throw std::exception("Error: Can't open file to read.\n");
	}
	while (!inFile.eof()){
		Item newItem;
		std::string buffer;
		inFile >> buffer;
		size_t stop_position = buffer.find(";");
		if (stop_position == -1){
			std::cerr << "Error: string not contain readable data\n";
			continue;
		}
		else{
			while (!buffer.empty()){
				size_t start_position = 0;
				newItem.nameCorp = buffer.substr(start_position, stop_position);
				buffer.erase(start_position, stop_position + 1);
				stop_position = buffer.find(";");
				newItem.owner = buffer.substr(start_position, stop_position);
				buffer.erase(start_position, stop_position + 1);
				stop_position = buffer.find(";");
				newItem.phone = buffer.substr(start_position, stop_position);
				buffer.erase(start_position, stop_position + 1);
				stop_position = buffer.find(";");
				newItem.address = buffer.substr(start_position, stop_position);
				buffer.erase(start_position, stop_position + 1);
				stop_position = buffer.find(";");
				newItem.lineOfBusiness = buffer.substr(start_position, stop_position);
				buffer.erase(start_position, stop_position + 1);
			}
		}
		DB_array.push_back(newItem);
	}

	for (int i = 0; i < DB_array.size(); ++i){
		std::cout << DB_array[i].nameCorp << " " << DB_array[i].owner << " " << DB_array[i].phone << " " << DB_array[i].address << " " << DB_array[i].lineOfBusiness << std::endl;
	}

}