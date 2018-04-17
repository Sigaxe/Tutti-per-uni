#include <iostream>
#include <cstring>

using namespace std;

int main (){
    char A[1001];           //A è una stringa utilizzata per l'inserimento dei valori inseriti dall'utente
    int x=0;                //x verrà utilizzato per da contatore
    bool pal=true;          //pal è una variabile utilizzata per il test

    cout<<"inserire una frase (max 1000 caratteri): ";
    cin.getline(A,1001,'\n');       //inserimento dei valori in A

    int l=strlen(A);        //dichiarazione di una stringa di un numero di valori pari ad A
    char F[l];

    for (int i=0;i<l;i++){
        if (A[i]>=65&&A[i]<=90){        //ciclo di inserimento dei valori in f. Solo le lettere sono inserite in F
            F[x]=A[i];                  //altri tipi di valori vengono ignorati
            x++;
        }
        else if (A[i]>=97&&A[i]<=122){  //caso in cui una lettera sia minuscola: viene inserita maiuscola
            F[x]=A[i]-32;
            x++;
        }
    }

    for (int i=0;i<l;i++){      //ciclo necessario per non considerare eventuali caratteri che non sono
        if (!(F[i]>=65&&F[i]<=90)){         //lettere in fondo all'array e per modificare la lunghezza
            F[i]='\0';                  //considerata dell'array
            l=i;
    }

    if (l%2==0){
        for (int i=0;i<=(l/2)-1;i++){       //il controllo viene effettuato in questo modo per verificare se
            if (F[i]!=F[l-i-1])             //la frase è palindroma o meno viene effettuata in questo modo se
                pal=false;                  //il numero di caratteri è pari
        }
    }

    if (l%2==1){
        for (int i=0;i<((l-1)/2);i++){      //il metodo utilizzato è identico anche per le frasi di lunghezza
            if (F[i]!=F[l-i-1])             //dispari, cambia solo la condizione
                pal=false;
        }
    }

    if (pal){
        cout<<"La frase e' palindroma!"<<endl;
    }
    else{
        cout<<"La frase non e' palindroma!"<<endl;
    }
return 0;}
