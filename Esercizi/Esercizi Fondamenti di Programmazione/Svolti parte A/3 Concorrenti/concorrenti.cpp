#include <iostream>

using namespace std;

int main (){
	int concorrenti;
	cout<<"Quanti concorrenti? ";    //richiesta all'utente del numero di partecipanti
	while (true){

        cin>>concorrenti;

        if (concorrenti>20)
            cout<<"Troppi concorrenti (max 20). Inserire nuovamente: ";         //verifica del numero di concorrenti
        else if (concorrenti<=0)
            cout<<"E' necessario un numero maggiore di zero di partecipanti. Inserire nuovamente: ";
        else if (cin.fail()){                           //inserimento di un numero di concorrenti non valido
                cout<<"Dato non corretto. Inserire nuovamente: ";
                cin.clear();
                cin.ignore(256,'\n');
        }
        else break;
	}

    float pec[concorrenti][2];          //dichiaro l'array bidimensionale pec (Prove e Concorrenti) in cui il numero del concorrente è la riga e i valori della singola riga sono il valore delle prove

    cout<<endl<<"Prima prova:"<<endl;       //inserimento dei valori della prima prova per tutti i concorrenti e i relativi controlli
    for(int i=0;i<concorrenti;i++){
       while (true) {
            cout<<"Votazione concorrente numero "<<i+1<<": ";
            cin>>pec[i][0];

            if (cin.fail()){
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Dato non corretto, inserire nuovamente"<<endl;
            }
            else break;
        }
    }

    cout<<endl<<"Seconda prova:"<<endl;          //inserimento dei valori della seconda prova per tutti i concorrenti e i relativi controlli
    for(int i=0;i<concorrenti;i++){
        while (true) {
            cout<<"Votazione concorrente numero "<<i+1<<" : ";
            cin>>pec[i][1];

            if (cin.fail()){
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Dato non corretto, inserire nuovamente"<<endl;
            }
            else break;
        }
    }

    float massimo=(pec[0][0]+pec[0][1])/2.0;   //calcolo del valore massimo (atleta vincitore) e il numero dell'atleta
    int indice=0;
    for (int i=0;i<concorrenti;i++){
        if(((pec[i][0]+pec[i][1])/2.0)>=massimo){
            indice=i;
            massimo=(pec[i][0]+pec[i][1])/2.0;
        }
    }
    cout<<endl<<"Il vincitore e' il concorrente numero "<<indice+1<<endl;   //stampa del valore medio massimo e del relativo giocatore
    cout<<"Media del vincitore: "<<massimo<<endl;

return 0;}
