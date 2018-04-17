#include <iostream>
#include <fstream>

using namespace std;

struct s{
	float info;		//dichiarazione della struct
	s* punt;		
};

void inserisci_testa(s*& p, float x){	//funzione inserisci_testa, richiamata da inserisci fondo nel caso in cui la lista sia vuota
	s* t=new s;				
	t->info=x;
	t->punt=p;
	p=t;
return;}

void inserisci_fondo(s*& p, float x){	//funzione inserisci_fondo
	if (p==NULL)
		inserisci_testa(p, x);
	else {
		s* t=new s;
		t->info=x;
		t->punt=NULL;

		s* z=p;
		while (z->punt!=NULL)
			z=z->punt;
		z->punt=t;
	}		
return;}

float ricerca_max(s* p){		//ricerca del massimo
	float massimo=p->info;
	while (p->punt!=NULL){
		if (p->info>massimo){
			massimo=p->info;
		}
		p=p->punt;
	}
return massimo;}

int main(){
	char nf[64];
	cout<<"Inserire nome file: ";	//inserimento del nome del file
	cin.getline(nf,64);
	
	ifstream fi;			//apertura dello stream del file
	fi.open(nf);
	
	while (fi.fail()){		//controllo sulla corretta apertura del file e inserimento in caso contrario
		fi.clear();
		cout<<"Errore nel nome del file, inserire nuovamente :"<<endl;
		cin.getline(nf,64);
		fi.open(nf);
	}
	
	s* l;	//dichiarazione di un puntatore alla lista
	l=NULL;	//dichiarazione di una lista vuota
	float x;//dichiarazione di una variabile
	
	while (true){
		fi>>x;					//input tipato nella variabile x
		if (fi.eof() || x==EOF)	break;		//termine della lettura in caso do avvenuta lettura di EOF
		if (fi.fail) {
			cout<<"Errore nella lettura dati"<<endl;	//termine del programma in caso di lettura di dati di tipo errato
			return 0;
		}
		
		inserisci_fondo(l,x);			//inserimento del valore nella lista concatenata
	}	

	cout<<"Massimo trovato: "<<ricerca_max(l)<<endl;
return 0;}
