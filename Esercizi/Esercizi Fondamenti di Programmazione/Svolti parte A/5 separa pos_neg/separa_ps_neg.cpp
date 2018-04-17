#include <iostream>

using namespace std;

void separa (int n, int A[], int P[], int N[], int& n_pos, int& n_neg){ //dichiaro una funzione void poichè i
    n_pos=n_neg=0;                                                  // parametri da restituire sono più di uno
                                                                    //e lavor per side-effect
    for (int i=0;i<n;i++){              //inserisco nell'array positivo valori negativi
        P[i]=-1;
    }
    for (int i=0;i<n;i++){              //inserisco nell'array negativo valori positivi
        N[i]=1;
    }

    for (int i=0; i<n;i++){
        if (A[i]<0){           //inserisco (sovrascrivendo i valori negativi) nell'array positivo i valori positivi dell'array iniziale
            N[n_neg]=A[i];
            n_neg++;
        }

        if (A[i]>0){        //inserisco (sovrascrivendo i valori positivi) nell'array negativo i valori negativi dell'array iniziale
            P[n_pos]=A[i];
            n_pos++;
        }
    }
}

int main (){
	int n;
	cout<<"Quanti numeri vuoi inserire? ";   //dichiarazione e inserimento del numero di elementi per l'array semi-dinamico e controllo sui dati
    do{
        cin>>n;
        if (n<0 || cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Dato non valido. Reinserire: ";
        }
        else
            break;
    }while(true);

    int S[n];                               //dichiarazione, inserimento e controllo dati sull'array di valori iniziale
    cout<<"Immettere i valori: "<<endl;
    for (int i=0; i<n;i++){
        do{
            cin>>S[i];
           if (cin.fail()){
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Dato non valido. Reinserire: ";
            }
            else
                break;
        }while(true);
    }

    int Spos[n],Sneg[n],n_n,n_p;        //dichiarazione di array e variabile utilizzate nella funzione 'separa'

    separa(n,S,Spos,Sneg,n_p,n_n);      //chiamata alla funzione 'separa'

    cout<<"Numeri positivi: ";          //stampa dei numeri positivi
    for(int i=0;i<n_p;i++){
        if (Spos[i]>0)
            cout<<Spos[i]<<" ";
    }

    cout<<endl;

    cout<<"Numeri negativi: ";      //stampa dei numeri negativi
    for(int i=0;i<n_n;i++){
        if (Sneg[i]<0)
            cout<<Sneg[i]<<" ";
    }
    cout<<endl;

return 0;}
