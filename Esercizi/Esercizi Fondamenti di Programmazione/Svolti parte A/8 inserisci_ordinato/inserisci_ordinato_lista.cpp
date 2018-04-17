#include <iostream>

using namespace std;

struct s{
	int info;
	s* punt;
};

void stampa (s* p){			//funzione stampa
	while(p!=NULL){
		cout<<p->info;
		p=p->punt;
	}
return;}

void inserisci_testa(s*& p, int x){	//funzione inserisci_testa, richiamata da inserisci fondo nel caso in cui la lista sia vuota
	s* t=new s;			//o nel caso in cui il valore intero sia inferiore a tutti quelli già presenti nella lista
	t->info=x;
	t->punt=p;
	p=t;
return;}

void inserisci_fondo(s*& p, int x){	//funzione inserisci_fondo
	s* t=new s;
	t->info=x;
	t->punt=NULL;

	t->info=x;
	s* z=p;
	while (z->punt!=NULL)
		z=z->punt;
	z->punt=t;
return;}

void inserisci_ordinato(s*& p, int x){
	bool test=false;
	if (p==NULL || x<p->info) {inserisci_testa(p, x); return;}
	s* z=p;
	while(z->punt!=NULL){
		if ((x<=(z->punt)->info)&&(!(test))){
			s* q=new s;
			q->info=x;
			q->punt=z->punt;
			z->punt=q;
			test=true;
		}
		else
			z=z->punt;
	}
	if (z->punt==NULL && z->info<x) inserisci_fondo(z, x);
return;}

int lunghezza(s* p){
	int n=0;
	while (p->punt!=NULL){
		n++;
		p=p->punt;
	}
return n;}

int main (void){
	s* l=NULL;
	int n=1;

	cout<<"Dai una sequenza di interi (negativo per smettere): "<<endl;
	do {
		cin>>n;
		if (n<0) break;
		inserisci_ordinato(l, n);
	}while(true);

	cout<<"letti e memorizzati "<<lunghezza(l)+1<<" numeri"<<endl<<"Lista ordinata: ";
	stampa(l);
	cout<<endl;

return 0;}
