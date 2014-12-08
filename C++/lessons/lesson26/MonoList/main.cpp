#include <iostream>
#include <cstdlib>
using namespace std;

/*������ ������������� ������, ����� ������� ������� � ����� � � ������ ������, � ��� �� ������������� ���������� ������*/

struct Item{
    int number;
    Item* next;
};

class MonoList{
    private:
        int junk; ///���������� ��� �������� ������ � ������ ����������� �������������� ��������� []
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
                begin = new Item; ///������� ����� ��������� � ����������� � ������ ������
                if(begin !=NULL){
                    sizeList=1;
                }
                end = begin; ///... � ����� ������, ���� ��������� � ������ ���� ����
                begin->next = NULL; ///���������� � ��������� ������
            }
            else{
                Item* temp; ///���������� ��� ���������� �������� ��������� �� �������� ������ ������
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
                begin = new Item; ///������� ����� ��������� � ����������� � ������ ������
                if(begin !=NULL){
                    sizeList=1;
                }
                end = begin; ///... � ����� ������, ���� ��������� � ������ ���� ����
                begin->next = NULL; ///���������� � ��������� ������
            }
            else{
                Item* temp; ///���������� ��� ���������� �������� ��������� �� �������� ����� ������
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
                return junk; ///����� ������ ���-�� �������
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

int MonoList::sizeList=0; //����������� ���������� ��������������� �� ���������� ������ - ��-������� �� �������.

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
