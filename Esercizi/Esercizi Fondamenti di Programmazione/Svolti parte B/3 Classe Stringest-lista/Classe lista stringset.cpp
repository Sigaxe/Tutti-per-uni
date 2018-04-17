#include <iostream>
#include <string>

using namespace std;

struct righe {              //definizione del singolo nodo
            string info;
            righe* punt;
};

class StringSet {
    private:
        righe* l;                   //puntatore iniziale della lista

    public:
        bool contains (string x) const {    //funzione che verifica che una data stringa
            righe* t=l;                     //sia contenuta o meno in unoggetto
			while (t!=NULL){
                if (t->info==x) return true;    //scorro la lista e verifico se uno dei nodi ha la stringa
				else t=t->punt;
            }
            return false;
        }

        void add (string x) {       //funzione add che aggiunge un nodo all'oggetto solo se presente
            if (!contains(x)){
				righe* t=new righe;
				t->info=x;
				t->punt=l;
				l=t;
			}
		}

        StringSet () {l=NULL;}      //costruttore senza parametri

        StringSet (string V[], int n) {     //costruttore in due parametri  che richiama la funzione add
            l=NULL;
			for (int i=0; i<n; i++) {
				add(V[i]);
			}
        }

		StringSet (const StringSet& x) {    //costruttore di copia: ridefinito per copiare correttamente
			if (x.l!=NULL){                 //un oggetto
                l=new righe;
                righe* t=x.l;
                righe* q=l;
                while(t!=NULL){
                    q->info=t->info;
                    if (t->punt==NULL) q->punt=NULL;
                    else q->punt=new righe;
                    q=q->punt;
                    t=t->punt;
                }
            }
			else l=NULL;
		}

		~StringSet () {             //distruttore
			while (l!=NULL){
                righe* t=l->punt;
                delete l;
                l=t;
			}
		}

		void remove (string x) {        //remove: elimina il nodo corrispondente all'informazione richiesta
            if (contains(x)){           //altrimenti ritorna un errore
                righe* t=l;
                righe* q=l;     //puntatore secondario utilizzato per scorrere la lista e utile a far
                int n=0;        //puntare il nodo precedente a quello che contiene l'informazione al successivo
                while(t!=NULL){
                    if (t->info==x){
                        for (int i=0; i<n-1; i++) q=q->punt;    //scorro col puntatore
                        q->punt=t->punt;
                        if (n==0) l=q->punt;
                        delete t;                       //elimino il nodo
                        return;
                    }
                    else {n++; t=t->punt;}
                }
            }
            else {string e="elemento non presente"; throw e;}
		}

        int size () const {     //funzione che ritorna la dimensione della lista
            righe* t=l;
            int n=0;
            while (t!=NULL) {
                n++;
                t=t->punt;
            }
            return n;
        }

        bool operator< (const StringSet& x) {   //ridefinizione dell'operatore minore
            righe* t=l;
			while (t!=NULL){
                if (!(x.contains(t->info))){
					return false;
				}
				else t=t->punt;
            }
            return true;
        }

        StringSet operator+ (const StringSet& x) const {    //ridefinizione dell'operatore più
            StringSet y;
            righe* t=x.l;
            while(t!=NULL){
				if (!contains(t->info)){
					y.add(t->info);
				}
				t=t->punt;
			}
            return y;
        }

		StringSet operator* (const StringSet& x) const {        //ridefinizione dell'operatore *
			StringSet y;
			righe* t=l;
			while(t!=NULL){
				if (x.contains(t->info)){
					y.add(t->info);
				}
				t=t->punt;
			}
			return y;
		}

	ostream& stampa (ostream& dest) const {     //funzione stampa
		dest<<"{";
        righe* t=l;
		while (t!=NULL){
			dest<<t->info;
			if (t->punt!=NULL){
                dest<<", ";
			}
			t=t->punt;
		}
		dest<<"}";
		return dest;
	}
};

ostream& operator<< (ostream& dest, const StringSet& x) {return x.stampa(dest);}   //ridefinizione operatore <<


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
