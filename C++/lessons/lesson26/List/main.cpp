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
            end = begin;
            begin->next = NULL;
            begin->prev = NULL;
        }
        else { // for following elements
            begin->prev = new Item;
            begin->prev->prev = NULL;
            begin->prev->next = begin;
            begin = begin->prev;
        }

        begin->number = number;
    }

    void push_back(int number) {
        if (end == NULL) {  // for the 1st element
            begin = new Item;
            end = begin;
            begin->next = NULL;
            begin->prev = NULL;
        }
        else {
            end->next = new Item;
            end->next->next = NULL;
            end->next->prev = end;
            end = end->next;
        }
        end->number = number;
    }

    int& operator[](size_t index) {
        Item* iterator = begin;

        if (!iterator) {
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

    list.push_back(3);

    for (int i = 0; i < 11; i++) {
        cout << list[i];
    }
    return 0;
}
