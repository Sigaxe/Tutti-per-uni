#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct S {              //dichiarazione della struct S
    int c1;
    float c2;
};


int main (){
	int lunghezza_max=100;      //dichiarazione di una variabile per la lunghezza del nome del file
	char nome[lunghezza_max];

	cout<<"Inserire nome file"<<endl;           //inserimento file
	cin.getline(nome, lunghezza_max);

	ifstream fi;            //apertura dello stream in input al programma
	fi.open(nome);

	if (fi.fail()){     //test della corretta apertura
        cout<<"Errore nell'apertura del file, programma terminato immediatamente";
        return 0;
	}


	int indice;     //indice utilizzato successivamente per la scrittura nei files di output e dichiarazione
	int intero;     // di un intero e di un numero reale per la lettura dei dati
	float reale;

	S T[1000];      //dichiarazione della tabella

	for (int i=0;i<1000;i++){
        fi>>intero;     //lettura del dato intero

        if (fi.eof()){
            cout<<"Lettura terminata correttamente";        //chiusura corretta del file
            indice=i;
            break;
        }

        if (fi.fail()){
            cout<<"Errore nella lettura dati, programma terminato"; //termine nel caso di lettura di dati di tipo diverso
            return 0;
        }

        fi>>reale;
        if (fi.fail()){
            cout<<"Errore nella lettura dati, programma terminato"; //termine nel caso di lettura di dati di tipo diverso
            return 0;
        }

        T[i].c1=intero;     //copia delle variabili nella struct
        T[i].c2=reale;
	}

    char nomec1 [lunghezza_max+9];
    char nomec2 [lunghezza_max+9];      //dichiarazione di due nuove stringhe per contenere i due nuovi nomi dei due nuovi file
                                        //e successiva elaborazione delle stringhe per contenere i nuovi nomi
    strcpy(nomec1,"campi1_di_");
    strcpy(nomec2,"campi2_di_");

    strcat(nomec1,nome);
    strcat(nomec2,nome);

    ofstream fc1;               //dichiarazione e apertura di due nuovi stram di output per la stampa dei valori della tabella
    ofstream fc2;

    fc1.open(nomec1);
    fc2.open(nomec2);

    for (int i=0; i<indice; i++){       //immissione dati dei nuovi file
        fc1<<T[i].c1<<endl;
        fc2<<T[i].c2<<endl;
    }

    fi.close();     //chiusura degli stream
    fc1.close();
    fc2.close();

return 0;}
