#include <iostream>

using namespace std;

int main (){
	int n;
    bool primo;
	cout<<"immettere il numero n: "<<endl; // inserimento dati
    cin>>n;

    cout<<endl;

    cout<<"I numeri primi fra i e "<<n<<" sono: "<<endl;

    for (int i=1;i<=n;i++){   //Controllo dei numeri da 1 a n saltando i numeri pari (poichè mai primi)
        primo=true;                       //variabile booleana di controllo
        for (int x=2;x<(i/2)+1;x++){   //ciclo per verificare che il numero preso in esame non sia divisibile per nessuno dei precedenti numeri
            if ((i%x)==0){
                primo=false;
                break;
            }
        }
        if (primo)
            cout<<i<<endl;     //stampa dei numeri
    }
return 0;}
