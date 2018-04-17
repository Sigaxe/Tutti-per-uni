#include <iostream>
#include <fstream>

using namespace std;

int raddoppia(float*& a, int n){	//dichiarazione della funzione raddoppia
	float* p=new float [n*2];
	for (int i=0;i<n;i++)
		p[i]=a[i];
	delete []a;
	a=p;				//attribuisco al vecchio puntatore il valore del nuovo array	
return n*2;}				//ritorno il doppio di n

float ricerca_max(float a[], int n){	//funzione di ricerca del massimo
	float massimo=a[0];
	for (int i=0; i<n; i++){
		if (a[i]>massimo){
			massimo=a[i];
		}
	}
return massimo;}			//ritorno il valore massimo


int main(){
	char nf[64];
	cout<<"Inserire nome file: ";		//inserimento del nome del file
	cin.getline(nf,64);
	
	ifstream fi;			//apertura dello stream di input
	fi.open(nf);
	
	while (fi.fail()){		//caso di inserimento del nome del file di input errato
		cout<<"Errore nel nome del file, inserire nuovamente :"<<endl;
		cin.getline(nf,64);	//richiesta continua d'inserimento
		fi.open(nf);
	}
	
	float* D;
	int dim=4, i=0;
	D = new float [dim];	//dichiarazione di un puntatore ad un array e la rispettiva dimensione
	
	while (true){
		if (i==dim) 	//verifica del dimensionamento corretto per l'inserimento dei dati nell'array dinamico
			dim=raddoppia(D, dim);	//raddoppio della dimensione nel caso in cui la verifica precedente sia vera
		
		fi>>D[i];	//inserimento del dato in input nell'array

		if (fi.eof())	break;	//l'uscita dal ciclo avviene quando il carattere appena estratto è EOF
		
		if (fi.fail()){		//in caso di lettura errata dei valori in input il programma termina immediatamente
			cout<<"Errore nella lettura dei dati nel file";
			return 0;
		}	
		i++;		//incremento dell'indice
	}
	cout<<"Massimo trovato: "<<ricerca_max(D, dim)<<endl;	//richiamo alla funzione di ricerca del massimo
return 0;}
