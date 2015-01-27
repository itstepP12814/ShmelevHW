#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;

class GaiTree{
    public:
        struct Offense{
            int running_a_red;
            int speeding;
            int illegal_parking;
        };
        struct Car{
            string number; //key
            Offense list; //value
            Car* leftCar;
            Car* rightCar;
            Car(const string& inKey):leftCar(NULL), rightCar(NULL), number(inKey), list({0,0,0}){}
            ~Car(){
                delete leftCar;
                delete rightCar;
            }
        };

        Car* root;
        size_t sizeOfTree;

        friend void listPrinter(Car* node);

        GaiTree():root(nullptr), sizeOfTree(NULL){};///Обязательная инициализация нулями
        ~GaiTree(){};

        Offense& operator[](const string& index){
            Car** current = &root;
            while((*current)!=nullptr){ ///Почему? == работает, а != нет? Потому что кодблокс "молодец"? Нужно было занулить указатель
                if(index == (*current)->number){
                    return (*current)->list;
                }
                if(index > (*current)->number){
                    current = &((*current)->rightCar);
                }
                else{
                    current = &((*current)->leftCar);
                }
            }
            (*current) = new Car(index);
            ++sizeOfTree;
            return (*current)->list;
        }

        void showTree(Car* node){
            if(node){
                listPrinter(node);
                showTree(node->leftCar);
                showTree(node->rightCar);
            }
        }

        void searchCar(const string& needleNumber, Car* node){
            if(node){
                searchCar(needleNumber, node->leftCar);
                if(node->number == needleNumber){
                    listPrinter(node);
                }
                searchCar(needleNumber, node->rightCar);
            }
        }

     /*   void searchFromRange(string letterSequenceFirst, string letterSequenceLast, Car* node){
            string alphabet[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
            string numSequenceFirst = "\0";
            size_t sizeStr = letterSequenceFirst.size();
            for(int j=0; j<=sizeStr; ++j){
                for(int i=0; i<10; ++i){
                    char key[1];
                    sprintf(key, "%d", i);
                    if(letterSequenceFirst.front()==key[0]){
                        numSequenceFirst+=letterSequenceFirst.substr(0,1);
                        letterSequenceFirst.erase(0,1);
                        --sizeStr;
                        cout << numSequenceFirst << endl << letterSequenceFirst << endl;
                        break;

                    }
                }
            }
            int intSequence = atoi(numSequenceFirst.c_str());
            cout << intSequence;
            int DexForNumSequenceFirst = 1; //Следующий десяток от числа номера
            while(intSequence%DexForNumSequenceFirst){
                DexForNumSequenceFirst*=10;
            }
            cout << DexForNumSequenceFirst;

        }
        */

        void searchByRange(const string& letterSequenceFirst, const string& letterSequenceLast, Car* node){
            if(node){
                if(node->number >= letterSequenceFirst && node->number <= letterSequenceLast){
                    listPrinter(node);
                }
                searchByRange(letterSequenceFirst, letterSequenceLast, node->leftCar);
                searchByRange(letterSequenceFirst, letterSequenceLast, node->rightCar);
            }
        }
};


void listPrinter(GaiTree::Car* node){
    cout << "Car Number: " << node->number << endl;
    cout << "\tOffense list:" << endl << "Running a red: " << node->list.running_a_red << endl;
    cout << "Speeding: " << node->list.speeding << endl;
    cout << "Illegal parking: " << node->list.illegal_parking << endl << endl;
}

int main()
{
    GaiTree DB1;

    DB1["A371GB"] = {3,5,7};
    DB1["B748UI"] = {1,2,1};
    DB1["C677FF"] = {2,0,4};

    DB1.showTree(DB1.root);

    cout << "\nSearch by number:\n\n";
    DB1.searchCar("2371GB", DB1.root);

    cout << "\nSearch by range:\n\n";
    DB1.searchByRange("A371GB", "C444NF", DB1.root);

    return 0;
}
