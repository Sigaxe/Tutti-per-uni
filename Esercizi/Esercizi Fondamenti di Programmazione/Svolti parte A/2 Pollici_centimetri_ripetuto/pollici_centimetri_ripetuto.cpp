#include <iostream>

using namespace std;

int main (void){
    int s;
    float misura;   //dichiarato float per l'eventuale inserimento dei numeri non interi
    bool verifica; // variabile di verifica per il controllo sulla scelta

    do{
        verifica=false;
        cout<<"Programma di conversione pollici <---> centimetri"<<endl<<endl;
        cout<<"scegli un'operazione: "<<endl<<"\t1. conversione pollici --> cm"<<endl<<"\t2. conversione cm --> pollici"<<endl;
        cout<<"\t3. smetti"<<endl;
        cout<<"Scelta: ";

        cin>>s;             //inserimento della scelta da parte dell'utente

        if (cin.fail() || s>3 || s<0){  //controllo sul dato inserito
            cin.clear();
            cin.ignore(256,'\n');
            verifica=true;
            cout<<"Scelta non valida - ripeti"<<endl;
        }

        } while (verifica);

    if (s==1){          //primo caso: stampo la misura fornita in cm per ottenere i pollici(moltiplicando per la costante 2.54)
        cout<<"Fornire il numero in pollici: ";
        cin>>misura;
        cout<<misura<<" pollici equivalgono a "<<misura*2.54<<endl;
    }
    else if (s==2){            //secondo caso: i numeri sono stai forniti in pollici ed è necessaria una conversione in metri
        cout<<"Fornire il numero in centimetri: ";
        cin>>misura;
        cout<<misura<<" centimetri equivalgono a "<<misura/2.54<<endl;
    }
    else if (s==3){               //terzo caso, fine programma
        cout<<"Arrivederci!!";
    }
return 0;}
