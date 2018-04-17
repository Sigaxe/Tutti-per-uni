#include <iostream>
#include <cstring>

using namespace std;

int main (){
    struct persona{         //dichiarazione della struct persona
        char nome [50];
        char ndt [50];
    };

    int scelta;         //dichiarazione della variabile scelta (per l'inserimento dell'opzione scelta), di n_elem utile a registrare il numjero di elemewnti nell'array
    int n_elem;
    bool verifica=true; //e di verifica, valore booleano

    persona dati_persona [100]; //dichiarazione dell'array di struct

    for (int i=0;i<100;i++){            //immissione dati e controllo sulla parola chiave per la terminazione dell'immissione dati
        cout<<"Immetti nome: ";
        cin>>dati_persona[i].nome;
        if (strcmp(dati_persona[i].nome, "stop")==0) {
            n_elem=i;
            cout<<"Dati immessi correttamente!"<<endl<<endl;
            break;
        }

        cout<<"Immetti il numero: ";        //immissione del numero di telefono per ogni nome
        cin>>dati_persona[i].ndt;
    }

    cout<<"Scegli un'operazione: "<<endl<<"\t1. cerca un nome"<<endl<<"\t2. cerca un numero di telefono"<<endl<<"\t3. stampa l'intera rubrica"<<endl<<"\t4. smetti"<<endl<<endl;

    while(true){
        verifica=true;              //scelta dell'operazione dall'utente
        cout<<"Operazione? ";
        cin>>scelta;
        if (scelta==4) {
            cout<<"Arrivederci!"<<endl<<endl;
            break;
        }

        switch (scelta){                //switch per la scelta dell'operazione
            case 1:
                cout<<"inserisci il nome: ";
                char ricerca_nome[50];          //ricerca del nome grazie alla variabile ricerca_nome
                cin>>ricerca_nome;
                for (int i=0;i<n_elem;i++){
                    if (strcmp(dati_persona[i].nome, ricerca_nome)==0){
                        cout<<"Il numero di "<<ricerca_nome<<" e' "<<dati_persona[i].ndt;
                        verifica=false;
                        break;
                        }
                }

                if (verifica)       //caso in cui il numero non sia stato trovato
                    cout<<"Non esiste il nome in elenco";

                cout<<endl<<endl;
                break;

            case 2:
                cout<<"Inserisci il numero: ";      //ricerca del numero di telefono grazie alla variabile ricerca_num
                char ricerca_num[50];
                cin>>ricerca_num;
                for (int i=0;i<n_elem;i++){
                    if (strcmp(dati_persona[i].ndt, ricerca_num)==0){
                        cout<<"Il numero "<<ricerca_num<<" e' "<<dati_persona[i].nome;
                        verifica=false;
                        break;
                        }
                }

                if (verifica)   //caso in cui il numero non sia stata trovato
                    cout<<"Numero non esistente";
                cout<<endl<<endl;
                break;

            case 3:
                cout<<endl;
                for (int i=0;i<n_elem;i++){
                    cout<<"\t"<<dati_persona[i].nome;
                    cout.width(10);
                    cout<<dati_persona[i].ndt<<endl;
                }
                cout<<endl<<endl;
                break;

            default:
                cout<<"Operazione non valida"<<endl<<endl;
        }
    }
return 0;}
