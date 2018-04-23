#include <iostream>

using namespace std;

int x_alla_y_ric(int x, int y){
	if (y==0) return 1;
	ris=x_alla_y_ric(x, y/2);
	ris=ris*ris;
	if (y%2) ris=ris*x;
return ris;}

int x_alla_y_iterativo(int x, int y){
	int r=1;
	while (y>0) {
		if (y%2==1)
            r=r*x;
        x=x*x;
		y=y/2;
	}
    return r;
}
