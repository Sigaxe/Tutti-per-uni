#include <iostream>

using namespace std;

int main (){
	int n;          //dichiaro la prima variabile n che mi servirà per l'array semidinamico A

	while (true){
        cout<<"Dammi il numero di elementi della prima sequenza: ";     //inserimento di n e controllo sul dato
        cin>>n;
        if (cin.fail() || n<0){
            cout<<"Errore! Dammi il numero di elementi della prima sequenza: ";
            cin.clear();
            cin.ignore(256,'\n');
        }
        else break;
	}

	int A[n];                           //dichiaro l'array semidinamico A e procedo all'inserimento
	for (int i=0; i<n; i++){
        cout<<"Dammi un numero: ";
        cin>>A[i];
	}

	cout<<endl();

	int m;                              // ripeto il procedimento per l'array semidinamico B

	while (true){
        cout<<"Dammi il numero di elementi della seconda sequenza: ";
        cin>>m;
        if (cin.fail()|| m<0){
            cout<<"Errore! Dammi il numero di elementi della seconda sequenza: ";
            cin.clear();
            cin.ignore(256,'\n');
        }
        else break;
	}

    int B[m];                       //inserimento dati in B
	for (int i=0; i<m; i++){
        cout<<"Dammi un numero: ";
        cin>>B[i];
	}

	int z;         //dichiaro la variabile z, utile a ricercarte il massimo fra n e m

	if (n>=m)
        z=n;
    else
        z=m;

    int C[z];   //dichiaro l'array C di dimensione massima fra n e m, servirà successivamente a contenere le intersezioni fra A e B

	int cont=0;

	for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){      //scorro elemento per elemento alla ricerca di due elementi equivalenti e durante l'inserimento all'interno
            if (A[i]==B[j]){        //di C sfrutto un'altra variabile chiamata contatore incrementandola
                C[cont]=A[i];
                cont++;
            }
        }
	}

    if (cont==0)        //cont timane a zero se non esiste un'intersezione fra A e B
        cout<<"L'intersezione tra le due sequenze date e' vuota"<<endl;
    else {
        cout<<"l'intersezione fra le due sequenze e': "<<endl;
        for (int i=0;i<cont;i++){                               //stampa (formattata) di tutti gli elementi uguali trovati
            cout.width(5);
            cout<<C[i];
        }
    }

return 0;}
