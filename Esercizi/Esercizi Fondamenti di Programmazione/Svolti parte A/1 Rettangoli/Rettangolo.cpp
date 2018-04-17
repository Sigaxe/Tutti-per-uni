#include <iostream>

using namespace std;

int main (){
	int colonne, righe, c_colonne=1, c_righe=1;
	char interno;

    cout<<"Inserisci quante riche vuoi: ";
    cin>>righe;                                 //inserimento righe

    if (righe<=0) {
        cout<<"Numero non accettato"<<endl;    //il programma termina immediatamaente nel caso in cui le righe siano negative
        return 0;
    }
    cout<<"Inserisci quante colonne vuoi: ";        //inserimento colonne
    cin>>colonne;

    if (colonne<=0) {
        cout<<"Numero non accettato"<<endl;  //il programma termina immediatamente nel caso in cui le colonne inserite siano negative
        return 0;
    }

    cout<<"inserisci il carattere che riempira' il rettangolo: "; //inserimento del carattere riempitivo dall'utente
    cin>>interno;

    while(c_righe<=righe){                  //posiziono il cursore sulla prima riga per poi nei cicli succfessivi verso il basso
        while(c_colonne<=colonne){          //quindi lo posiziono sulla prima colonna per poi scorrere verso destra

            if (c_colonne==1 || c_colonne==colonne ||c_righe==1 || c_righe==righe)
                cout<<"*";          //stampo l'asterisco nel caso in cui il cursore sia sulla cornice
            else
                cout<<interno;      //altrimenti stampo il carattere  inserito dall'utente

            c_colonne=c_colonne+1;
        }
        c_colonne=1;            //necessari (questa istruzione e le successive) per far progredire il ciclo in avanti
        c_righe=c_righe+1;
        cout<<endl;
    }

return 0;}
