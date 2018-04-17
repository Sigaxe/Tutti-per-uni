#include <iostream>
using namespace std;
/*
 Classe che realizza il tipo di dato astratto
"numero razionale"
*/

class Razionale {
    private:    int n;
                int d;
                int mcd(int x, int y){         //MCD calcolato utilizzando l'algoritmo euclideo
                    while (x>0){
                        if(x==y || x==0 || y == 0) return x;
                        if(x>y) x=x-y;
                        else {
                                int tmp = y;
                                y = x;
                                x = tmp;}
                    }
                    return y;}

                void semplifica() {int x=mcd(n,d); n=n/x;d=d/x;}  //semplificazione tramite MCD

    public:     Razionale () {n=0;d=1;}     //costruttore di classe senza parametri
                Razionale (int a) {n=a; d=1; semplifica();}   //costruttore di classe con un parametro
                Razionale (int a, int b) {                  //costruttore con due parametri e controllo sull'inserimento del denominatore
                    n=a;
                    if (b==0) {
                        cout<<"Errore nell'assegnamento del denominatore"<<endl;
                        d=1;
                    }
                    else d=b;
                    semplifica();
                }

                Razionale operator+ (Razionale x) {             //funzione somma tramite overloading
                    Razionale risultato;
                    risultato.n = n * x.d + x.n * d;
                    risultato.d = d * x.d;
                    risultato.semplifica();
                    return risultato;
                }
                Razionale operator* (Razionale x) {          //funzione prodotto tramite overloading
                    Razionale risultato;
                    risultato.n = n * x.n;
                    risultato.d = d * x.d;
                    risultato.semplifica();
                    return risultato;
                }

                bool operator< (Razionale x) {return (n*x.d < x.n*d);}   //confronto fra frazioni tramite l'uso del minore

                void stampa (ostream& dest) {       //stampa dei numeri razionali
                    dest<<n;
                    if (d!=1) dest<<"/"<<d;
                    else return;}

                void leggi (istream& sorg) {        //lettura di numeri razionali
                    char sep;
                    sorg>>n;
                    sep=sorg.get();
                    if (sep=='\n') {d=1; return;}
                    if (sep!='/') {
                            cin.ignore(1);
                            cout<<"ATTENZIONE!: separatore non valido"<<endl;
                            d=1;
                    }
                    else sorg>>d;
                    if (d==0) {
                        cout<<"ATTENZIONE!: denominatore nullo"<<endl;
                        d=1;}
                    semplifica();
                }
};

ostream& operator<< (ostream& dest, Razionale a) {a.stampa(dest); return dest;} //overloading dell'operatore <<
istream& operator>> (istream& sorg, Razionale& a) {a.leggi(sorg); return sorg;} //overloading dell'operatore >>


int main() {

 Razionale a;
 Razionale b(4,6);
 Razionale c(4);
 Razionale d(9,3);

 cout << "razionale a: " << a << endl; //0
 cout << "razionale b: " << b << endl; //2/3
 cout << "razionale c: " << c << endl; //4
 cout << "razionale d: " << d << endl; //3

 a = b + c;
 cout << "razionale b+c: " << a << endl; // 14/3
 a = b * 3;
 cout << "razionale b*3: " << a << endl; // 2
 a = Razionale(2) * 5;
 cout << "razionale 2*5: " << a << endl; // 10
 a = b + Razionale(1,3);
 cout << "razionale b+1/3: " << a << endl; // 1

 if(b < 2) cout << "minore" << endl;
 else cout << "maggiore" << endl;
 Razionale x,y;
 cout << "Dai una frazione o un intero:";
 cin >> x;
 cout << "Numero letto: " << x << endl;
 cout << "Dai una frazione o un intero:";
 cin >> y;
 cout << "Numero letto: " << y << endl;
 cout << "somma di x e y: " << x + y <<endl;
 Razionale z;
 cout << "Dai una frazione o un intero:";
 cin >> z;
 cout << "Numero letto: " << z << endl;


// system("pause");
 return 0;
}




/* traccia esecuzione
razionale a: 0
razionale b: 2/3
razionale c: 4
razionale d: 3
razionale b+c: 14/3
razionale b*3: 2
razionale 2*5: 10
razionale b+1/3: 1
minore
Dai una frazione o un intero: 2/3
Numero letto: 2/3
Dai una frazione o un intero: 3
Numero letto: 3
somma di x e y: 11/3
Dai una frazione o un intero: 5/0
ATTENZIONE!: denominatore nullo
Numero letto: 5
*/
