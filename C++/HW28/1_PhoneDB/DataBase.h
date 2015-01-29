#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string.h>

using namespace std;
class DataBase
{
    public:
        DataBase(){};
        virtual ~DataBase(){};
        struct Item{
            public:
            Item(const string _name):left(nullptr),right(nullptr),name(_name){};
            ~Item(){
                ///delete left; delete right; delete parent;
                ///������ ������ segfault?
                };
            Item* left;
            Item* right;
            Item* parent;
            string name;
            string phoneNumber[3];
        };
        Item* root = nullptr;
        size_t sizeOfTree = 0;
        Item* operator[](const string& index){
            Item** current = &root;
            Item* parentTemp = nullptr;

            while((*current)!=nullptr){
                if(index == (*current)->name){
                    return (*current);
                }
                if(index > (*current)->name){
                    parentTemp = (*current);
                    current = &((*current)->right);
                }
                else{
                    parentTemp = (*current);
                    current = &((*current)->left);
                }
            }
            (*current) = new Item(index);

            if(sizeOfTree!=0){
            (*current)->parent = parentTemp;
            //cout << (*current)->name << ":" << (*current)->parent->name << endl;
            }
            ++sizeOfTree;
            return (*current);
        }

        void printData(Item* node);
        Item* getRoot(){return root;};
        void showAll(Item* node){
            if(node){
            showAll(node->left);
            printData(node);
            showAll(node->right);
            }
        }

        /**����� ������� ���� ��� ����� ���������, ���� �� � ���� �������.
        (1)���� �������� ��� - ������� ����.
        (2)���� ������� ������ ����, �� ������������ ��� ��������� �� ������ ���������� ����, � ���� - �������.

        ��� ������� ���� ��������, ���������� ������������� ����������� ������, �.�. ���������� ������� ���������� �����: ����� �������� ����
        � ��� ��������� ��� �����, ������� ����� ����� ����-�� ������������, �� ����� �������� ���� ��� ����� ������������ ������ ���� ����� -
        ����� ��� ��������� ���� ��� ����������� � ������. ����� �������:

        (3)���� ������� ���, �� ������� ����� ����� ����(m) ������� ������ ���������� ����, � ������������ ��� ������ �� ����� ���������� ����. ����� ������� ��������.
        ���� ����� ����� ����(m) ����� ����� ������ ������ ������� (�������), ������� �� ������������ � ������ ���� (m). ����� ����.
        */

        Item** parentNavigation(Item* node){ ///����� ���������� ����� ���������� �������� ��������� �� ������������ ��������
            Item* current = node->parent;
            Item** pointerFromParentToNode = nullptr; ///������� ���� ��������� �� �������� �� ���������� �������, �����������
            if(current->left != nullptr){ ///���� ��������� ���� � ����� ��������� �������� - ��������� ����� ��������� ��������
                if(current->left->name == node->name){
                        pointerFromParentToNode = &((*current).left);
                }
            }
            if(current->right != nullptr){ ///���� ��������� ���� � ������ ��������� �������� - ��������� ������ ��������� ��������
                if(current->right->name == node->name){
                    pointerFromParentToNode = &((*current).right);
                }
            }
            return pointerFromParentToNode;
        }

        Item* findAloneChild(Item* node){
            Item* child = nullptr;
                if(node->left){
                    child = node->left;
                }
                else{
                    child = node->right;
                }
                return child;
        }

        bool delNode(const string& name){
            Item* node = operator[](name);

            ///������ ������
            if(node!=0 && node->left == nullptr && node->right == nullptr && node->name == name){//���� ���� ��� ��������
                Item** pointerFromParentToNode = parentNavigation(node);
                (*pointerFromParentToNode) = nullptr; ///�������� ��������� �������� ����������� �� ���������� �������
                delete node; ///������� ����
            }
            ///������ ������
            if(node!=0 && (node->left == nullptr ^ node->right == nullptr) && node->name == name){//
                Item** pointerFromParentToNode = parentNavigation(node);
                (*pointerFromParentToNode) = findAloneChild(node);
                delete node;
            }

            ///������ ������
            if(node!=0 && node->left != nullptr && node->right != nullptr && node->name == name){//
                Item* current = node->right;
                while(current->left != nullptr){
                    current = current->left;
                }
                node->name = current->name;
                for(int i=0; i<3; ++i){
                    node->phoneNumber[i] = current->phoneNumber[i];
                }
                Item** pointerFromParentToNode = parentNavigation(current);
                (*pointerFromParentToNode) = findAloneChild(current);
                delete current;
            }
            ///�������� ��������
            if(!node){
                cout << "Contact deleted.\n";
            }
            else{
                cout << "Error\n";
                //cout << node->name;
            }

        }
};

#endif // DATABASE_H
