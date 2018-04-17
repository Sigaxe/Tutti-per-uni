#include <iostream>

using namespace std;

int main (){
    int indice=0, contatore=0;  //dichiarazione di un indice, e un contatore utile per la stampa delle variabili allocate
    int* A[1000];       //array di puntatori
    int* x=new int;                 //dichiarazione di una variabile in cui immettere i dati inseriti dall'utente
    bool trovato=false;         //variabile booleana utile al controllo

    cout<<"Dai una sequenza di numeri interi (negativo per smettere): "<<endl;
    while (true){
        trovato=false;

        cin>>*x;        //viene inserito il valore di x dall'utente

        if (*x<0 || indice==1000) break;        //uscita dal ciclo while in caso di superamente del limite massimo
                                                //dell'arrray o de il valore di x è minore di 0
        for (int i=0;i<indice; i++){    //ricerca all'interno dell'array
            if (*x==*A[i]){
                trovato=true;       //se la ricerca ha avuto successo, la variabile viene settata su true
                break;
            }
        }

        if (trovato==false){            //nel caso in cui la ricerca non abbia avuto buon fine, nell'array di puntatori
            A[indice]=new int(*x);      //viene aggiunto un nuovo puntatore che punta ad una nuova variabile appena
            contatore++;                //creata con lo stesso valore appena inserito e il contatore viene incrementato
        }
        else{
            A[indice]=x;                //altrimenti viene semplicemente immesso il valore di x nel puntatore, di modo
        }                               //che l'array in quella posizione punti alla stessa cella di x

        indice++;                       //incremento dell'indice per considerare la cella successiva dell'array nel prossimo ciclo

        delete x;
        x= NULL;
        x=new int;                      //creazione di un nuovo puntatore per x
    }

    cout<<"Allocate "<<contatore<<" variabili"<<endl;       //stampa del numero di variabile allocate

    cout<<"Sequenza: ";
    for (int i=0; i<indice; i++){                       //stampa del numero della sequenza di valori inseriti
        cout<<*A[i]<<"  ";
    }

return 0;}
