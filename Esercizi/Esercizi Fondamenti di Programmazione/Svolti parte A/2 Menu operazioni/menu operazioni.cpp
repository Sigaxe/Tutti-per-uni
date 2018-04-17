#include <iostream>

using namespace std;

int main (){
	int s, num, fat=1;;
	do{
        cout<<"scegli una delle seguenti operazioni: "<<endl;
        cout<<"\t1. valore assoluto"<<endl<<"\t2. quadrato"<<endl<<"\t3. sommatoria"<<endl<<"\t4. fattoriale"<<endl<<"\t5. smetti"<<endl;
        cout<<"operzione scelta? ";

        cin>>s;  //richiesta di scelta operazione

        if (cin.fail() || s<1 || s>5){              //gestione di input errato
            cout<<"Scelta non valida"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
        }

        switch (s){                         //differenziazione in base al valore scelto in s
            case 1:
                do{
                    cout<<"Inserire un numero intero: ";        //valore assoluto
                    cin>>num;

                    if (cin.fail())
                        cout<<"Dato non valido"<<endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                }while (cin.fail());

                cout<<"Il valore assoluto di "<<num<<" e' ";

                if (num<=0)
                    cout<<-num<<endl;
                else cout<<num<<endl;

                cout<<endl;
                break;

            case 2:         //quadrato del numero
                do{
                    cout<<"Inserire un numero intero: ";
                    cin>>num;

                    if (cin.fail())
                        cout<<"Dato non valido"<<endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                }while (cin.fail());

                cout<<"Il quadrato e' "<<num*num<<endl;

                cout<<endl;
                break;

            case 3:         //Sommatoria di tutti i numeri precedenti al numero inserito
                do{
                    cout<<"Inserire un numero intero (>=0): ";
                    cin>>num;
                    if (num<=0 || cin.fail())
                        cout<<"Dato non valido"<<endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                }while (num<=0 || cin.fail());

                cout<<"La sommatoria e': "<<num*(num+1)/2<<endl;

                cout<<endl;
                break;

            case 4:  //Fattoriale
                do{
                    cout<<"Inserire un numero intero (>=0): ";
                    cin>>num;
                    if (num<=0 || cin.fail())
                        cout<<"Dato non valido"<<endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                }while (num<=0 || cin.fail());

                for (int i=2;i<=num;i++){
                    fat=fat*i;
                }

                cout<<"Il fattoriale e': "<<fat<<endl;
                fat=1;

                cout<<endl;
                break;

                case 5:         //terminazione del programma
                    cout<<"Terminato"<<endl;
        }
    }while (s!=5);
return 0;}
