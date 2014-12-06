#include <iostream>
#include <cstdlib>
using namespace std;

struct Item {
	int number;
	Item* next;
	Item* prev;
};

class DoubleList {
	int junk;
	Item* begin;
	Item* end;
public:
	DoubleList() : begin(NULL),end(NULL) {};
	void push_front(int number) {
		if (begin == NULL) {  // for the 1st element
			begin = new Item;
			begin->next = NULL;
			begin->prev = NULL;
			end->prev = NULL;
			end->next = NULL;
		}
		else { // for following elements
			begin->prev = new Item;
			begin->prev->prev = NULL;
			begin->prev->next = begin;
			begin = begin->prev;
		}

		begin->number = number;
	}

	void push_back(int number){
        if (end == NULL) {  // for the 1st element
			end-> = new Item;
			end->next = NULL;
			end->prev = NULL;
		}
		else{
            end->prev
		}
	}
	int& operator[](size_t index) {
		Item* iterator = begin;

		if (!iterator){
			cout << "\nArray empty\n";
            return junk;
        }

		for (size_t i = 0; i < index; ++i) {
			if (iterator->next != NULL) {
				iterator = iterator->next;
			}
			else {
				cerr << " ERROR\n";
				return junk;
			}
		}
		return iterator->number;
	}
};
int main() {
	DoubleList list;

	for (int i = 0; i < 10; i++) {
		list.push_front(i);
	}

	for (int i = 0; i < 10; i++) {
		cout << list[i];
	}
	return 0;
}
