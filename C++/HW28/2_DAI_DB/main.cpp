#include <iostream>
#include <cstdlib>
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

        void searchFromDiapason(const string& firstStr, Car* node){
            const char* tempFirst = firstStr.c_str();
            int integerPieceOfFirstStr = atoi(tempFirst);
            cout << integerPieceOfFirstStr;
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

    DB1["2371GB"] = {3,5,7};
    DB1["6748UI"] = {1,2,1};
    DB1["5677FF"] = {2,0,4};

    DB1.showTree(DB1.root);

    cout << "\nSearch by number:\n\n";
    DB1.searchCar("2371GB", DB1.root);

    cout << "\nSearch from diapason:\n\n";
    DB1.searchFromDiapason("2371GB",DB1.root);
    return 0;
}
