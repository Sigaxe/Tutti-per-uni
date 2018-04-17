#include <iostream>
#include <cstring>

using namespace std;

int ricerca (char A[], int i, char del[]){

    for (int k=i;k<strlen(A);k++){          //scorro tutti i valori dell'array da analizzare fino a quando non trovo un carattere speciale
        for (int j=0;j<strlen(del);j++){
            if (del[j]==A[k]){
                A[0]=del[j];        //per evitare di passare per riferimento un'altra variabile, sovrascrivo il carattere speciale
                return ++k;         //trovato nel primo carattere dell'array da analizzare, e successivamente richiamarlo
            }
        }
    }
return -1;  //se il confronto non ha resituito nessun risultato, il programma ritorna -1
}

int main (){
	char testo[1000];
	char speciali[]={'.', ',', ';', ':', '-','!', '?'};
	int inizio;
	int trovato;

	cout<<"Inserisci il testo, terminato da a capo: "<<endl; //Immissione testo da analizzare
    cin.getline(testo,1000,'\n');

    cout<<"Inserire posizione in cui iniziare la ricerca (>=0): "; //immissione carattere d'inizio dell'analisi e controllo sul dato
    do{
		cin>>inizio;
        	if (inizio<0 || cin.fail()){
        		cin.clear();
                cin.ignore(256,'\n');
                cout<<"Dato non valido. Reinserire: ";
        	}
        	else
        		break;
	}while(true);

    inizio--; //decremento necessario perchèì l'utente si riferisce al primo carattere mentre l'array comincia da 0

    trovato=ricerca(testo, inizio, speciali); //inserisco nella variabile trovato il valore di ricerca (per comodità)

    if (trovato==-1)            //stampa del risultato
        cout<<"Carattere speciale non trovato"<<endl;
    else
        cout<<"Carattere speciale "<<testo[0]<<" trovato in posizione "<<trovato++<<endl;

return 0;}
