#include <iostream>
#include <string>

using namespace std;

/* 
  Classe che realizza il tipo di dato astratto "insieme di stringhe"
*/   
// class StringSet {...}

 
// main di prova

int main() 
{
  StringSet S1;
  cout << "S1: " << S1 << endl;
  cout << "Cardinalita' di S1: " << S1.size() << endl;

  string frase[] = {"il","cane","e","il","gatto"};
  StringSet S2(frase,5);
  cout << "S2: " << S2 << endl;
  cout << "Cardinalita' di S2: " << S2.size() << endl;
  
  const StringSet empty;
  cout << "Insieme vuoto: " << empty << endl;
  cout << "Cardinalita' di insieme vuoto: " << empty.size() << endl;
  cout << "Unione di insieme vuoto e S2: " << empty + S2 << endl;

  try {
	S1.add("cane");
  	S1.add("gatto");
  	S1.add("il");
  	S1.add("e");
  
  	if (S1.contains("gatto"))
      	cout << S1 << " contiene la stringa 'gatto'" << endl;
  	else
      	cout << S1 << " non contiene la stringa 'gatto'" << endl;
      
  	if (S1 < S2 && S2 < S1)
      	cout << "I due insiemi sono uguali" << endl;
  	else
      	cout << " I due insiemi sono diversi" << endl;
      
	S2.remove("il");	
	S2.remove("gatto");
    cout << "S2 modificato: " << S2 << endl;
    
  	StringSet S3;
  	S3.add("e");
  	S3.add("il");
  	S3.add("cavallo");
  	cout << "S3: " << S3 << endl;
  	
  	StringSet S4;
  	S4 = S2 * S3;	
  	cout << "Intersezione di S2 e S3: " << S4 << endl;
  	  	
  	StringSet S5;
	S5 = S2 + S3;	
  	cout << "Unione di S2 e S3: " << S3 << endl;
  	
  	cout << "Intersezione di S2 e insieme vuoto: " << S2 * empty << endl;
  	
	string aux;                // test gestione eccezioni
	for (int i=0; i<100; i++)
    	{aux = aux + '*';
  	     S3.add(aux);     
		}  
	S3.remove("coniglio");
  }
  catch(string e) {
	 cout << "Eccezione: " << e << endl;
  }   

  system("pause");
  return 0;
}

/* Output:

S1: {}
Cardinalita' di S1: 0
S2: {gatto, e, cane, il}
Cardinalita' di S2: 4
Insieme vuoto: {}
Cardinalita' di insieme vuoto: 0
Unione di insieme vuoto e S2: {il, cane, e, gatto}
{e, il, gatto, cane} contiene la stringa 'gatto'
I due insiemi sono uguali
S2 modificato: {e, cane}
S3: {cavallo, il, e}
Intersezione di S2 e S3: {e}
Unione di S2 e S3: {cavallo, il, e}
Intersezione di S2 e insieme vuoto: {}
Eccezione: elemento non presente
Premere un tasto per continuare . . .

*/
