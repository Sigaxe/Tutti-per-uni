#include <iostream>
#include <cstring>

using namespace std;

struct testo {		//dichiarazione della struct contentente un campo informazione di tipo stringa e un puntatore
	char info[64];	
	testo* punt;
};

void inserisci_testa(testo*& l, char stringa[]){	//funzione inserisci testa leggermente modificata per 
	testo* t=new testo;				//il supporto alle stringhe nel campo informazione
	strcpy(t->info,stringa);
	t->punt=l;
	l=t;
return;}


bool confronta (testo* s1, testo* s2){		//funzione confronta

	if (s1==NULL || s2==NULL) return false;	//ritorna false se le stringhe sono vuote

	while(s1->punt!=NULL){			//confronto delle stringhe (se sono di lunghezza differente il confronto ha successo ugualmente)
		if (strcmp(s1->info, s2->info)!=0) return false;	
		s1=s1->punt;
		s2=s2->punt;
	}
return true;}

int main(){

	cout<<"Dai la prima sequenza di stringhe ('$$$' per smettere): "<<endl; //inserimento e controllo sul dato per l'uscita dal ciclo d'immissione
	char stringa1[64];							// della prima lista di stringhe
	testo* l1;
	
	do {						//inserimento nel campo informazione tramite una stringa temporanea
		cin.getline(stringa1, 64);

		if (strcmp(stringa1,"$$$")==0) break;		
		
		inserisci_testa(l1, stringa1);
	}while(true);
	
	cout<<"Dai la prima sequenza di stringhe ('$$$' per smettere): "<<endl;		//inserimento della seconda stringa equivalente al primo
	char stringa2[64];
	testo* l2;
	
	do {
		cin.getline(stringa2, 64);
		
		if (strcmp(stringa2,"$$$")==0) break;		
		
		inserisci_testa(l2, stringa2);
	}while(true);
	
	cout<<"Le due sequenze sono ";			//richiamo alla funzione confronta per verificare che le stringhe siano effettivamente equivalenti
	if (confronta(l1, l2))
		cout<<"uguali"<<endl;
	else
		cout<<"diverse"<<endl;
return 0;}
