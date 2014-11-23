//Попытка разобраться в наследовании и работе с массивами объектов
#include <iostream>

class pr_child;

class  pr
{
public:
    int x;
    pr_child* m;

    pr();
    ~pr(){std::cout << "pr destroy\n";};
};

class pr_child:public pr {
public:
    pr_child();
};

pr_child::pr_child():pr() {
    std::cout << "pr_child was created\n";
}

pr::pr(){
        std::cout << "pr was created and include " << std::endl;

        int n = 10;
        for(int i=0; i<n; i++) {
            m = new pr_child[10];
        }
    }

int main() {
    pr first();
}
