#include <iostream>
#include <cstring>

using namespace std;

struct Elem {
    char nome[100];                //dichiarazione della struct
    int cont;
};

void modifica (Elem A[], int& m, char s[]){             //
    bool v=false;
    for (int i=0; i<m; i++){
        if (strcmp(A[i].nome, s)==0){     //controllo se la stringa è già presente nella struttura o meno tramite
            v=true;                      //un controllo in un ciclo. La variabile booleana v serve proprio a questo
            A[i].cont++;    //aumento del contatore nel caso in cui la stringa scelta non sia presente
        }
    }
    if (!v){                    //caso nel quale la variabile s non è presente nell'array
        strcpy(A[m].nome,s);
        A[m].cont=1;
        m++;
    }
}

int main (){
	cout<<"Inserisci il testo, terminato da a capo: "<<endl;
    int massimo=0, z=0, contatore=0, limite=3000;  //z e contatore sono contatori. Limite è la dimensione massima del testo che l'utente può inserire
    char stringa[1000][256];            //dichiaro una matrice di stringhe in cui inserire per colonna le parti di stringa inserite dall'utente separate da uno spazio

    char inserito[limite];      //array in cui verranno inseriti i caratteri digitati dall'utente
    cin.getline(inserito, limite);

    for (int i=0;i<strlen(inserito);i++){   //divisione della stringa inserita dall'utente in base al carattere di spazio
        if (inserito[i]==' '){
            stringa[contatore][z]='\0';     //caso in cui il carattere analizzato sia uno spazio: lo spazio viene scritto come un delimitatore di stringa
            contatore++;                    //nella matrice, la riga della matrice viene incrementata, il contatore (che conta il numero di parole, quindi di righe della
            z=0;                            //matrice viene aumentata e z (il contatore che tiene traccia della posizione del carattere) azzerato (perchè viene incrementata la riga)
        }
        else {
            stringa[contatore][z]=inserito[i];  //caso in cui il carattere è un altro qualsiasi
            z++;
        }
    }

    Elem conta[1000];       //dichiarazione della struttura

    for (int i=0; i<contatore k; i++){
        modifica(conta, massimo, stringa[i]);       //richiesta in maniera ciclica, per ogni parola trovata, la funzione modifica
    }

    cout<<"Numero di occorrenze di ciascuna parola nel testo: "<<endl;
    for (int i=0; i<=massimo; i++){
        if (strcmp(conta[i].nome, "")==0) break;    //nel caso in cui l'utente abbai inserito più dei uno spazio
        cout<<conta[i].nome;    //stampa dell'array trovato
        cout<<"     ";
        cout<<conta[i].cont<<endl;
    }

return 0;}
