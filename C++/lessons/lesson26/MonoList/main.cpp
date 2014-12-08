#include <iostream>
#include <cstdlib>
using namespace std;

/*—оздаю односв€занный список, делаю функции вставки в конец и в начало списка, а так же перегруженные квадратные скобки*/

struct Item{
    int number;
    Item* next;
};

class MonoList{
    private:
        int junk; ///ѕеременна€ дл€ возврата мусора в случае неотработки перегруженного оператора []
        static int sizeList;
        Item* begin;
        Item* end;
    public:
        MonoList():begin(NULL), end(NULL){};
        ~MonoList(){};
        int getSize(void){
            return sizeList;
        }

        void push_front(int number){
            if(begin==NULL){
                begin = new Item; ///—оздаем новую структуру и присваиваем еЄ началу списка
                if(begin !=NULL){
                    sizeList=1;
                }
                end = begin; ///... и концу списка, ведь структура в списке пока одна
                begin->next = NULL; ///«аписываем в указатель ничего
            }
            else{
                Item* temp; ///ѕеременна€ дл€ временного хранени€ указател€ на исходное начало списка
                temp =  begin;
                begin = new Item;
                if(begin !=NULL){
                    ++sizeList;
                }
                begin->next = temp;
            }
            begin->number = number;
        }

        void push_back(int number){
            if(begin==NULL){
                begin = new Item; ///—оздаем новую структуру и присваиваем еЄ началу списка
                if(begin !=NULL){
                    sizeList=1;
                }
                end = begin; ///... и концу списка, ведь структура в списке пока одна
                begin->next = NULL; ///«аписываем в указатель ничего
            }
            else{
                Item* temp; ///ѕеременна€ дл€ временного хранени€ указател€ на исходный конец списка
                end->next = new Item;
                if(begin !=NULL){
                    ++sizeList;
                }
                end = end->next;
            }
            end->number = number;
        }

        int& operator[](size_t index){
            Item* iterator = begin;
            if(!iterator){
                cerr << "Error\n";
                return junk; ///ћетод должен что-то вернуть
            }
            else{
                for(int i=0; i<index; ++i){
                    if(iterator->next !=NULL){
                        iterator = iterator->next;
                    }
                    else{
                        cerr << "Error\n";
                        return junk;
                    }
                }
                return iterator->number;
            }
        }

};

int MonoList::sizeList=0; //—татическую переменную инициализировал за переделами класса - по-другому не выходит.

int main()
{
    MonoList list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    for(int i=0; i<list.getSize(); ++i){
        cout << list[i];
    }
    return 0;
}
