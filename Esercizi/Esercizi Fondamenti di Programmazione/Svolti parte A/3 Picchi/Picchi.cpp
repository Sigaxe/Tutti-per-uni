#include <iostream>

using namespace std;

int main (){
    int n;
	cout<<"Immettere dimensione della matrice: ";       //richiesta della dimensione della matrice e controllo sul tipo di dato inserito
	while (true){
        cin>>n;

        if (cin.fail()){
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Dato non corretto, inserire nuovamente: ";
            }
        else break;
	}

	int M[n][n];

	cout<<"Immettere altitudini: "<<endl<<endl<<endl;       //immissione dei valori nella matrice
	for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"\b";
            cin>>M[i][j];
        }
	}

	cout<<"Matrice data: "<<endl<<endl;  //stampa a schermo della matrice
	for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout.width(5);
            cout<<M[i][j];
        }
        cout<<endl;
	}

	cout<<endl<<"I picchi sono: "<<endl<<endl;      //ricerca e stampa dei picchi
	for (int i=1;i<n-1;i++){
        for (int j=1;j<n-1;j++){
            if (M[i][j]>M[i-1][j] && M[i][j]>M[i+1][j] && M[i][j]>M[i][j+1] && M[i][j]>M[i][j-1])
            cout<<"picco "<<M[i][j]<<" in "<<"["<<i+1<<"]"<<"["<<j+1<<"]"<<endl;
        }
	}
    cout<<endl;
return 0;}
