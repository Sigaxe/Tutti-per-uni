#include <iostream>
using namespace std;


int E1 (int n){                     //Teta(n^2)
    int s=0;
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++)
            s++;
return s;}

int E2 (int n){                     //Teta(n)
for (int i=0; i<n; i++){
    s += (n-i);
return s;}

int E3 (int n) {return n*(n-1)/2;}   //Teta(1)
