#include <iostream>

using namespace std;

int molt (int a, int b){            //Teta(n^2)
    int p=0;
    while (a>0){
        if (a%2) p=p+b;             //ottengo il risultato in p
        a=a/2;
        b=b*2;
    }
return p;}


int molt_ric (int a, int b){        //Teta(n^2)
    if (a==0) return 0;
    z=molt_ric(a/2,b);
    if (a%2) return (z*2+b);
    else return z*2;}
