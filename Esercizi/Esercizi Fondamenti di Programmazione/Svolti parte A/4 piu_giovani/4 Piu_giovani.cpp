#include <iostream>

using namespace std;

int main (){
	struct persona{
        char cognome[50];           //dichiarazione della struct persona
        int eta;
	};
    int n;                      //dichiarazione della variabile per l'array semidinamico

    cout<<"Quante persone vuoi immettere (max 10)? ";       //inserimento dati e controllo sul dato
    while (true){
        cin>>n;
        if (cin.fail()||n>10||n<0){
            cout<<"Errore! Quante persone vuoi immettere (max 10)? ";
            cin.clear();
            cin.ignore(256,'\n');
        }
        else break;
    }

    persona persone [n];    //dichiarazione dell'array di struct persone

    cout<<endl;

    for (int i=0;i<n;i++){              //immissione del cognome e dell'età per ogni persona (riga) dell'array "persona" (tabella)
        cout<<"Immetti il cognome: ";
        cin>>persone[i].cognome;

        cout<<"Immetti l'eta': ";
        cin>>persone[i].eta;

        cout<<endl;
    }

    int minimo=persone[0].eta;      //ricerca dell'età minima all'interno della colonna delle età

    for (int i=0;i<n;i++){
        if (persone[i].eta<minimo)
            minimo=persone[i].eta;
    }

    cout<<"I piu' giovani sono: "<<endl;        //stampa dei cognomi delle persone che hanno un età pari a quella trovata nella ricerca precedente
    for (int i=0;i<n;i++){
        if (persone[i].eta==minimo)
            cout<<"    "<<persone[i].cognome<<endl;
    }

return 0;}
