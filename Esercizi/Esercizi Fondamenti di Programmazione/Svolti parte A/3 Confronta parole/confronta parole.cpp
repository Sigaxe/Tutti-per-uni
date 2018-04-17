#include <iostream>
#include <cstring>

using namespace std;

int main (){
	char a[101],b[101];

	while (true){       //apertura del ciclo per continuare l'esecuzione
        bool v=true;
        bool va=true;               //dichiarazioni di variabili booleane di confronto
        bool vb=true;

        cout<<"Dai la prima parola: ";      //l'utente fornisce la prima parola, su cui il controllo della sequenza di uscita dal programma
        cin.getline(a,101,'\n');
        if (strcmp(a,"$$$")==0){
            cout<<"Terminato!"<<endl;
            break;
        }

        cout<<"Dai la seconda parola: ";   //inserimento seconda parola
        cin.getline(b,101,'\n');


        if (strcmp(a,b)==0){        //caso in cui le due stringhe siano uguali
            cout<<"Le due parole sono uguali"<<endl;
            v=false;
        }

        if (strcmp(a,b)<0)          //caso in cui la prima stringa preceda la seconda
            cout<<"La parola "<<a<<" precede "<<b;

        if (strcmp(a,b)>0)      //caso in cui la seconda stringa preceda la prima
            cout<<"La parola "<<b<<" precede "<<a;

        for (int i=0;i<strlen(a);i++)   //Se la prima parola è prefisso della seconda, la variabile "va" diventa false
            if (a[i]!=b[i]){            //in modo che la stampa del prefisso errato non avvenga
                va=false;
                break;
            }

        for (int i=0;i<strlen(b);i++)   //caso contrario al precedente in cui vb diventa false se b è prefisso di a
            if (b[i]!=a[i]){
                vb=false;
                break;
            }


        if (va && v)
            cout<<"; "<<a<<" e' un prefisso di "<<b<<endl;      //stampa solo se a è prefisso di b

        if (vb && v)
            cout<<"; "<<b<<" e' un prefisso di "<<a<<endl;      //stampa solo se b è prefisso di a

        cout<<endl<<endl;
	}
return 0;}
