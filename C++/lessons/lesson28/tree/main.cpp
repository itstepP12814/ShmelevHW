#include <iostream>

using namespace std;

class Tree{
private:
    struct Item{
    public:
        string key;
        int Value;
        Item* Left;
        Item* Right;
        Item(const string inKey):Left(nullptr), Right(nullptr), key(inKey){}
        ~Item(){
            delete Right;
            delete Left;
        }
    };
    Item* root;
    size_t sizeOfTree;
public:
    int& operator[](const string& index){
        Item** current = &root;
        while((*current)!=nullptr){
            if(index == (*current)->key){
                return (*current)->Value;
            }
            if(index < (*current)->key){
                current = &((*current)->Left);
            }
            else{
                current = &((*current)->Left);
            }
        }
        (*current) = new Item(index);
        ++sizeOfTree;
        return (*current)->Value;
    }

    void showTree(Item* node){
        if(node){
            showTree(node->Left);
            cout << node->key << " " << node->Value << endl;
            showTree(node->Right);
        }
    }

    Item* getRoot(){return root;}

    Tree(){};
    ~Tree(){};

};

int main()
{
    Tree happy;
    happy["LEXA"] = 1924;
    happy["XAX"] = 1943;
    happy["LEXASA"] = 1624;
    happy["AFG"] = 2224;

    happy.showTree(happy.getRoot());

    return 0;
}
