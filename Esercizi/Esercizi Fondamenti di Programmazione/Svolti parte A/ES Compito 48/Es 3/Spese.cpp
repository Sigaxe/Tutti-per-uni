#include <iostream>

using namespace std;

void controllo_sul_dato(int& a){
	do{
		cin>>a;
        	if (cin.fail()){
        		cin.clear();
                	cin.ignore(256,'\n');
                	cout<<"Dato non valido. Reinserire: ";
        	}
        	else
        		break;
	}while(true);
}

int main (){
	cout<<"Hello world!"<<endl;


return 0;}
