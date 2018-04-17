#include <iostream>

using namespace std;

void inverti(int A[], int i, int f){
    int t=0;
    if ( i>=f){
        return;
    }

    else {                              //passo induttivo, solo se l'indice finale è maggiore dell'indice iniziale
        t=A[i];                         //scambio valori con il metodo della variabile temporaea
        A[i]=A[f];
        A[f]=t;
        inverti(A, ++i, --f);
    }
}

int main (){
	int n;
	cout<<"Quanti numeri vuoi inserire? ";     //preparazione alla creazione dell'array semidinamico
	cin>>n;

    int prova[n];                                   //crerazione dell'array
    cout<<"Inserire "<<n<< " numeri"<<endl;

    for (int i=0;i<n;i++){                          //immissione dati
        cin>>prova[i];
    }

    inverti(prova, 0, n-1);                         //chiamata alla funzione

    for (int i=0;i<n;i++){                          //stampa dell'array invertito
        cout<<prova[i]<<"  ";
    }

return 0;}
