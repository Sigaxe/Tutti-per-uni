#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int separa (int n, int A[], int P[], int N[], int& n_pos, int& n_neg){     //dichiaro una funzione che ritorna il numero di zeri
    int contatore=0;                                                        //all'interno del file ma lavoro per side-effect
    n_pos=n_neg=0;

    for (int i=0;i<n;i++){  //inserisco nell'array positivo valori negativi
        P[i]=-1;
    }
    for (int i=0;i<n;i++){   //inserisco nell'array negativo valori positivi
        N[i]=1;
    }

    for (int i=0; i<n;i++){
        if (A[i]<0){           //inserisco (sovrascrivendo i valori positivi) nell'array negativo i valori negativi dell'array iniziale
            N[n_neg]=A[i];
            n_neg++;
        }

        if (A[i]>0){        //inserisco (sovrascrivendo i valori negativi) nell'array positivo i valori positivi dell'array iniziale
            P[n_pos]=A[i];
            n_pos++;
        }

        if (A[i]==0)
            contatore++;    //contatore che restituirà il numero di zeri nel file
    }

return contatore;}

int main (){
    char nf[256];

    cout<<"Dai il nome del file di input: "<<endl;  //inserimento nome file
    cin.getline(nf,256,'\n');

    ifstream f_c;   //apertura di un primo stream per la lettura del contenuto del file di nome dato
    f_c.open(nf);

    if (f_c.fail()){                                //test della corretta apertura
        cout<<"Il testo non e' stato trovato. Errore "<<endl;
        return 0;
	}

	int n=0;                    //dichiarazione del contatore (n), di un carattere di verifica (a) e uno di supporto (b)
	char a=f_c.get(), b='x';    //attraverso il ciclo si verificano tutti i caratteri presenti nel file e se sono degli
	while (true){               //spazi il contatore viene incrementato. Nel caso in cui l'utente abbia lasciato uno spazio
        a=f_c.get();            //alla fine del file, il secondo statement if gestisce il caso appositamente
        if (a==EOF){
            if (b!=32){
                n++;
            }
            break;
        }
        if (a==32){
            n++;
        }
        b=a;
	}

	f_c.close();

	ifstream f_i;       //apertura dello stram d'input
    f_i.open(nf);

    int S[n];                       //dichiarazione e inserimento nell'array di valori
    for (int i=0; i<n;i++){
        f_i>>S[i];
    }

    f_i.close();            //chiusura del file

    int Spos[n],Sneg[n],n_n,n_p;        //dichiarazione di array e variabile utilizzate nella funzione 'separa'

    int zeri=separa(n,S,Spos,Sneg,n_p,n_n);      //chiamata alla funzione 'separa' che ritorna il numero di zeri

    char nfpos[strlen(nf)];
    for (int i=0;i<strlen(nf);i++) {nfpos[i]=nf[i];}        //creazione del nome <nome file>_pos.txt
    nfpos[strlen(nf)+4]='\0';
    nfpos[strlen(nf)+3]='t';
    nfpos[strlen(nf)+2]='x';
    nfpos[strlen(nf)+1]='t';
    nfpos[strlen(nf)]='.';
    nfpos[strlen(nf)-1]='s';
    nfpos[strlen(nf)-2]='o';
    nfpos[strlen(nf)-3]='p';
    nfpos[strlen(nf)-4]='_';

    ofstream fop;                       //apertura del nuovo file contente solo numeri positivi
    fop.open(nfpos);

    for(int i=0;i<n_p;i++){             //stampa su file dei numeri positivi
        if (Spos[i]>0){
            fop<<Spos[i]<<" ";
        }
    }
    fop.close();    //chiusura del file


    char nfneg[strlen(nf)];
    for (int i=0;i<strlen(nf);i++) {nfneg[i]=nf[i];}    //creazione del file con <nome file>_neg.txt
    nfneg[strlen(nf)+4]='\0';
    nfneg[strlen(nf)+3]='t';
    nfneg[strlen(nf)+2]='x';
    nfneg[strlen(nf)+1]='t';
    nfneg[strlen(nf)]='.';
    nfneg[strlen(nf)-1]='g';
    nfneg[strlen(nf)-2]='e';
    nfneg[strlen(nf)-3]='n';
    nfneg[strlen(nf)-4]='_';
    ofstream fon;                   //apertura del file output di numeri negativi
    fon.open(nfneg);

    for(int i=0;i<n_n;i++){             //stampa su file dei numeri positivi
        if (Sneg[i]<0)
            fon<<Sneg[i]<<" ";
    }

    fon.close();            //chiusura del file

    cout<<"Lettura terminata correttamente"<<endl;

    cout<<"Numero di zeri eliminati: "<<zeri<<endl;       //messaggio di riuscita e stampa finale del programma

return 0;}
