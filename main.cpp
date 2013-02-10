#include"data.h"
int main(){
	base a;
	a.add_new_rec("Andrey","Nagorny",18,1000);
	a.add_new_rec("Ivan","Ivanov",16,800);
	a.add_new_rec("Dmitry","Osipov",32,9800);
//	a.sort(ID);
	a.delete_rec(18);
	return 0;
}
