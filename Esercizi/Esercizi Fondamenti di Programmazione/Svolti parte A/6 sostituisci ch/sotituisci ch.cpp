#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main (){
	char nf[50]; //il primo carattere è da scambiare e il secondo è quello con cui verrà scambiato

	cout<<"Dai il nome del file (max 50 caratteri): "<<endl;        //inserimento nome file
	cin.getline(nf,50);

	ifstream f_i;           //apertura dello stream di input al programma
	f_i.open(nf);

	if (f_i.fail()){        //test della corretta apertura
        cout<<"Il testo non è stato trovato. Errore "<<endl;
        return 0;
	}

	ofstream f_o;                       //apertura dello stream in output al programma e nomina del file di output
	char nnf[4+strlen(nf)]={"new_"};
	strcat(nnf,nf);
    f_o.open(nnf);

    char primo='a',secondo='a';
    int cont=0, cont_sost=0;

	while(primo!=EOF && secondo!=EOF){      //ciclo di lettura di ogni singolo carattere nella variabile primo,
        primo=f_i.get();
        if (primo=='c'){                    //e test per la sostituzione corretta dei caratteri con relativo
            secondo=f_i.get();              //incremento dei contatori
            if (secondo=='h'){
                f_o.put('k');
                cont_sost++;
            }
            else{
                f_o.put(primo);
                f_o.put(secondo);
                cont++;
            }
        }
        else {
            if (primo!=EOF){
                f_o.put(primo);
            }
        }
        cont++;
	}

    cout<<"Copiati "<<cont<<" caratteri - fatte "<<cont_sost<<" sostituzioni"<<endl;    //stampa finale e chiusura del programma
    f_i.close();
    f_o.close();

return 0;}
