#include <iostream>
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
            Car(const string inKey):leftCar(NULL), rightCar(NULL), number(inKey), list({0,0,0}){}
            ~Car(){
                delete leftCar;
                delete rightCar;
            }
        };

        Car* root;
        size_t sizeOfTree;

        GaiTree(){};
        ~GaiTree(){};

        Offense& operator[](const string& index){
            Car** current = &root;
            while((*current) != nullptr){ ///Почему? == работает, а != нет? Потому что кодблокс "молодец".
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
};

int main()
{
    GaiTree DB1;

    DB1["2371GB"] = {3,5,7};
    DB1["6748UI"] = {1,2,1};
    DB1["5677FF"] = {2,0,4};

    cout << DB1["2371GB"].running_a_red;
    return 0;
}
