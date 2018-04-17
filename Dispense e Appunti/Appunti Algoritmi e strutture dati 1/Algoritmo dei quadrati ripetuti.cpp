#include <iostream>

using namespace std;

int x_alla_y_ric(int x, int y){
	if (y==0) return 1;
	ris=x_alla_y_ric(x, y/2);
	ris=ris*ris;
	if (y%2) ris=ris*x;
return ris;}

int x_alla_y_iterativo(int x, int y){
	int z=1;
	if (y%2) z=x;
	y=y/2;
	while (y!=2) {
		x=x*x;
		if (y%2) z=z*x
		y=y/2;
	}
return z;}
