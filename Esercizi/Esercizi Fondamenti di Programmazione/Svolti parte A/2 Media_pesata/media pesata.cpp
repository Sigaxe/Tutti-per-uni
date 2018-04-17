#include <iostream>

using namespace std;

int main (){
	int cfu, voto, s_cfu=0, num=0, n_voti=0; //num= numeratore della frazione della media

    while (voto>0){
        cout<<"Immettere un voto (negativo per smettere): ";
        cin>>voto;

        if (voto>=18 && voto<=30){                  //controllo dell'immissione corretta dei voti
            cout<<"Immettere i CFU del corso: ";
            cin>>cfu;

            n_voti=n_voti+1;                    //se il voto è stato inserito correttamente allora si possono calcolare
            num=num+(voto*cfu);                 //il numeratore, il numero di voti (richiesto più avanti), e la somma dei
            s_cfu=s_cfu+cfu;                    //CFU (il denominatore della frazione media)
        }
        else if ((voto<18 || voto>30) && voto>0)                    //caso in cui il voto non corrisponde ai criteri
            cout<<"Il voto deve essere compreso tra 18 e 30"<<endl;
    }

    cout<<endl<<"Hai immesso "<<n_voti<<" voti"<<endl;   //typecasting necessaria per restituire il valore in floating point
    cout<<"La tua media e': "<<(float)num/s_cfu;        //(è stato scelto di tenerli interi fino a prima poichè logicamente interi)

return 0;}

