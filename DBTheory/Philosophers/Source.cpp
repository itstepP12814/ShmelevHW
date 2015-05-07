using namespace std;
#include <vector>
struct Fork{};
struct Plate{};
class Philosopher
{
public:
	Philosopher(){};
	~Philosopher(){};

private:

};

class Controller
{
public:
	vector <Philosopher> phils;
	vector <Fork> forks;
	vector <Plate> plates;
	Controller(){
		for (int i = 0; i < 5; ++i){
			Philosopher temp_p;
			Fork temp_f;
			Plate temp_pl;
			phils.push_back(temp_p);
			forks.push_back(temp_f);
			plates.push_back(temp_pl);
		}
	};
	~Controller();

	bool makeNewStep(){

	}

};

int main(){
	return 0;
}

