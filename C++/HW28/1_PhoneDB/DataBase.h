#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string.h>
#include <fstream>

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
                ///Почему выдает segfault?
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

        /**Чтобы удалить узел нам нужно проверить, есть ли у него потомки.
        (1)Если потомков нет - удаляем узел.
        (2)Если потомок только один, то переписываем его указатель на предка удаляемого узла, а узел - удаляем.

        При наличии двух потомков, появляется необходимость перестроить дерево, т.к. появляется пролема следующего плана: после удаления узла
        у нас останется две ветки, которые нужно будет куда-то присоединить, но после удаления узла для этого освободиться только одно место -
        место где удаленный узел был присоединен к предку. Таким образом:

        (3)Если потомка два, то находим самый ЛЕВЫЙ узел(m) ПРАВОГО дерева удаляемого узла, и переписываем его данные на место удаляемого узла. Затем удаляем оригинал.
        Этот самый левый узел(m) может иметь только одного потомка (правого), который мы присоединяем к предку узла (m). Такие дела.
        */

        Item** parentNavigation(Item* node){ ///Метод определяет каким указателем родитель указывает на передаваемый аргумент
            Item* current = node->parent;
            Item** pointerFromParentToNode = nullptr; ///Запишем сюда указатель из родителя на удаляемого потомка, пригодиться
            if(current->left != nullptr){ ///Если удаляемый узел в левом указателе родителя - сохраняем левый указатель родителя
                if(current->left->name == node->name){
                        pointerFromParentToNode = &((*current).left);
                }
            }
            if(current->right != nullptr){ ///Если удаляемый узел в правом указателе родителя - сохраняем правый указатель родителя
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

            ///Первый случай
            if(node!=0 && node->left == nullptr && node->right == nullptr && node->name == name){//Если узел без потомков
                Item** pointerFromParentToNode = parentNavigation(node);
                (*pointerFromParentToNode) = nullptr; ///Затираем указатель родителя указывающий на удаляемого потомка
                delete node; ///Удаляем узел
            }
            ///Второй случай
            if(node!=0 && (node->left == nullptr ^ node->right == nullptr) && node->name == name){//
                Item** pointerFromParentToNode = parentNavigation(node);
                (*pointerFromParentToNode) = findAloneChild(node);
                delete node;
            }

            ///Третий случай
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
            ///Проверка удаления
            if(!node){
                cout << "Contact deleted.\n";
            }
            else{
                cout << "Error\n";
                //cout << node->name;
            }

        }

        void findByNumber(Item* node, const string& needle){
            if(node){
            findByNumber(node->left, needle);
            findByNumber(node->right, needle);
            int check=0;
                for(int i=0; i<3; ++i){
                    if(node->phoneNumber[i]==needle){
                        ++check;
                    }
                }
                if(check!=0){
                    printData(node);
                }
            }
        }

        bool saveDB(Item* node);
        void saveFunction(Item* node, ofstream& output);
        bool readDB(Item* node);
};

#endif // DATABASE_H
