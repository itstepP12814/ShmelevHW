#include "Passport.h"

int main(){
	Passport Shmelev("Konstantin","Shmelev", "928174298374", false, "male");
	Shmelev.showInfo();
	ForeignPassport FShmelev("Konstantin", "Shmelev", "928174298374", "MP353487", false, "male");
	FShmelev.showInfo();
	return 0;
}