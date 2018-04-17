#include <iostream>

using namespace std;

int main (void){
    int s;
    float misura;   //dichiarato float per l'eventuale inserimento dei numeri non interi

    cout<<"Programma di conversione pollici <---> centimetri"<<endl<<endl;
    cout<<"Tipo di conversione: "<<endl<<"\t1. pollici --> cm"<<endl<<"\t2. cm --> pollici"<<endl<<"Digitare la scelta: ";

    cin>>s;             //inserimento della scelta da parte dell'utente
    cout<<endl;

    if (s==1){          //primo caso: stampo la misura fornita in cm per ottenere i pollici(moltiplicando per la costante 2.54)
        cout<<"Fornire il numero in pollici: ";
        cin>>misura;
        cout<<misura<<" pollici equivalgono a "<<misura*2.54<<endl;
    }
    else if (s==2) {            //secondo caso: i numeri sono stai forniti in pollici ed è necessaria una conversione in metri
        cout<<"Fornire il numero in centimetri: ";
        cin>>misura;
        cout<<misura<<" centimetri equivalgono a "<<misura/2.54<<endl;
    }
    else                //caso di inserimento non valido (non corrispondente a 1 o 2 o un carattere)
        cout<<"Scelta non valida!";

return 0;}
