#include <iostream>

using namespace std;

void insertionSort(int A[],int n){
    int x,i,j,t;
    for(i=1;i<n;i++)
    {
        x=A[i];
        j=i-1;
        while(j>=0&&A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    return;
}

void selection_sort(int A[], int n){
	int min, imin;
	for (int i=0; i<n-1; i++){
		min=A[i];
		imin=i;
		for (int k=i+1; k<n; k++)
			if (A[k]<min) {
							min=A[k]; 
							imin=k;
			}
		A[imin]=A[i];
		V[i]=min;
	}
return;}

void torneoItaliana(int V[], int n){
	int b[n],z[n],i,j;
	for (i=0; i<n; i++) b[i]=0;
	for (i=0; i<n; i++)
		for (j=i+1; j<n; j++){
			if (V[i]<V[j]) b[j]++;
			else b[i]++;
		}
	for (i=0; i<n; i++) z[b[i]]=V[i];
	for (i=0; i<n; i++) V[i]=z[i];
    return;
}

void bubble_sort(int A[], int n){
	for (int k=1; k<n; k++)
		for (int j=n-1; j>=k; j--)
			if (A[j-1]>A[j]) Scambia(A, j-1, j);
return;}
