#include <iostream>

using namespace std;

int main (){
    int corrente, futuro, eta;

	cout<<"Inserisci l'anno corrente: ";
	cin>>corrente;

    cout<<"Inserisci la tua eta': ";
	cin>>eta;

    cout<<"Inserisci l'anno per calcolare la tua eta': ";       //ottengo le informazioni necessarie
	cin>>futuro;

	if ((futuro-corrente)>=0)
        cout<<"la tua eta' nel "<<futuro<<" sara' di "<<eta+(futuro-corrente)<<" anni"<<endl;   //cojndizione per sommare all'età inserita la differenza dell'anno corrente e di quello richiesto per ottenere un avanzamento di età dell'utente
    else if ((futuro-corrente)<0 && !(corrente-eta>futuro)) //condizione per la quale l'utente ha chiesto un anno precedente a quello corrente (seconda condizione necessaria per non ricadere sia nel secondo che nel terzo caso)
        cout<<"La tua eta' nel "<<futuro<<" era di "<<(eta-(corrente-futuro))<<" anni"<<endl;
    else if ((futuro-corrente)<0 && corrente-eta>futuro)        //l'utente ha richiesto un'età inferiore alla data di nascita e quindi non corretta (mostrata con l'opportuno messaggio di errore)
        cout<<"Nel "<<futuro<<" non eri ancora nato"<<endl;
return 0;}
