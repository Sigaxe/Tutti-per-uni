#include <iostream>
using namespace std;


//Soluzione 1                       Teta(n^3)
int s1 (int A[], int n){
	int maxs=A[0];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++){
            int sum=0;
            for (int k=i;k<=j;k++)
                sum += A[k];
            if (sum>max) maxs=sum;
        }
return maxs;}

//Soluzione 2                       Teta(n^2)
int s2 (int A[], int n) {
    maxs=A[0];
    for (int i=0;i<n;i++){
        sum=0;
        for (int j=i;j<n;j++){
            sum=sum+A[j];
            if (sum<maxs) maxs=sum;
        }
    }
return maxs;}

//Soluzione 3                       Teta(n)
int s3 (int A[], int n){
    maxs=0
    sum=0;
    for (s=0; s<n; s++){
        sum += A[s];
        if (maxs<sum) maxs=sum;
        if (sum<0) sum=0;   //eventuale "reset" della somma
    }
return maxs;}
