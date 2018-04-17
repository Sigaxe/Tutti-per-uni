#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main (){
	char da_s, scam; //il primo carattere è da scambiare e il secondo è quello con cui verrà scambiato

	cout<<"Dai i due caratteri che vuoi scambiare (senza spazi): "<<endl;
	cin.get(da_s);
	cin.get(scam);

	ifstream f_i;
	f_i.open("testo.txt");
	if (f_i.fail()){
        cout<<"Il testo non è stato trovato. Errore "<<endl;
        return 0;
	}

	char scritta[100];
	f_i.getline(scritta,100);

	int contatore=0;
	for (int i=0; i<=strlen(scritta); i++){
        if (scritta[i]=='e'){
            scritta[i]='o';
            contatore++;
        }
        else if (scritta[i]=='o'){
            scritta[i]='e';
            contatore++;
        }
	}

    ofstream f_o;
    f_o.open("testo_codificato.txt");

    for (int i=0; i<=strlen(scritta);i++){
        f_o.put(scritta[i]);
    }

    cout<<"Copiati "<<strlen(scritta)<<" caratteri - fatte "<<contatore<<" sostituzioni"<<endl;

return 0;}
