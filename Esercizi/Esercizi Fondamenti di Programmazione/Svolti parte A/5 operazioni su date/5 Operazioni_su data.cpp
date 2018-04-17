#include <iostream>

using namespace std;

struct data {               //definita una struct data visibile in tutto il programma (per ragioni di scope)
        int giorno;         //contenente tre interi giorni, mesi e anni
        int mese;
        int anno;
	};

bool bisestile (int a){                         //funzione per il controllo dell'anno bisestile
    if ((a%4==0 && !(a%100==0)) || a%400==0)
        return true;
    else
        return false;
}

int giorni_mese (int a, int m){     //funzione che resituisce i giorni dei mesi corrispondenti, realizzata
    int g;                          //con uno switch per comodità
    switch (m){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        g=31;
        break;
    case 4: case 6: case 9: case 11:
        g=30;
        break;
    case 2:
        if (bisestile(a)) g=29;
        else g=28;
        break;
    }
    return g;
}

bool controlla_data (data d){       //funzione di controllo sul dato

    if (d.anno<0 || cin.fail()){       //controllo inserimento corretto della data (anche sul tipo)
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }

    else if (d.mese<0 || cin.fail() || d.mese>12){
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }

    else if (d.giorno<0 || cin.fail() || d.giorno>giorni_mese(d.anno, d.mese)){
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }

    else return true;
}

void avanza_di_un_giorno(data& d){      //avanzamento di un giorno e gestione dei casi limite
    d.giorno++;                         //funzione void perché agisce per side-effect (modificando la struct d)
    if (d.giorno>giorni_mese(d.anno, d.mese)){
        d.giorno=d.giorno-giorni_mese(d.anno, d.mese);
        d.mese++;
        if (d.mese>12){
            d.anno++;
            d.mese=d.mese-12;
        }
    }
}

int main (){
	data d={7,12,2017};     //dichiarazione di una struct necessaria a passare i controlli sul dato nel
                            //caso di un immediato inserimento errato
	int n;

	bool ciclo=false;       //variabile necessaria a ripetere il ciclo d'inserimento dati

	do {
        cout<<"Immetti il giorno: ";    //inserimento dati
        cin>>d.giorno;

        cout<<"Immetti il mese: ";
        cin>>d.mese;

        cout<<"Immetti l'anno: ";
        cin>>d.anno;

        if (controlla_data(d)==false){      //chiamata alla funzione per l'inserimento dei dati
            ciclo=true;
            cout<<endl<<"Errore nella data, inserire nuovamente"<<endl;
        }

	} while(ciclo);     //il ciclo viene ripetuto il caso di inserimento errato (ciclo=true)

    cout<<endl;

    cout<<"Immetti il numero di giorni da sommare: ";       //immissione del giorno da sommare
    cin>>n;

    for (int i=1;i<=n;i++){         //avanzamento dei giorni richiesto
        avanza_di_un_giorno(d);
    }

    cout<<"La nuova data e': "<<d.giorno<<"/"<<d.mese<<"/"<<d.anno<<endl;       //stampa della nuova data

return 0;}
