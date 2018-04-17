#include <iostream>

using namespace std;

int main (){
    int l=0;

    cout<<"Programma di stampa rettangoli isosceli"<<endl;   //Inserimento dati e presentazione del programma
    cout<<"Inserire la lunghezza di un cateto (l>0)"<<endl;
    cin>>l;

    while (true){    //restituzione di un messaggio d'errore con reiserimento delle variabile in caso di immissione non valida
        if (cin.fail() || l<=0){
            cout<<"Immissione non valida. Inserire nuovamente il valore di l"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin>>l;
        }
        else break;
    }

    cout<<endl;

    for(int r=l;r>0;r--){           //stampa del triangolo attraverso due stmt for nidificati
        for (int c=0;c<=l-r;c++)
            cout<<"*";
        cout<<endl;
    }


return 0;}
