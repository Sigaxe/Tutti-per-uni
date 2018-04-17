/*
  Scrivere un programma che chieda all'utente di inserire due numeri
  razionali (rappresentati come numeratore/denominatore), ne calcoli
  la somma, e quindi stampi su std output il risultato.
  Realizzare la nozione di numero razionale come un tipo di dato astratto
  tramite il costrutto di class
*/

#include <iostream>

using namespace std;

class Razionale {
   private:
      int n;    // Numeratore.
      int d;    // Denominatore.
   public:
      // Inizializzazione
      Razionale() {                   // Costruttore senza parametri
         n = 0;
         d = 1;
         }
      Razionale(int num, int den) {   // Costruttore con 2 parametri
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else
            d = den;
         }

      // Legge il numero razionale nella forma `n/d'.
      void leggi(istream& s_in) {
         int num, den;
         char sep;
         s_in >> num >> sep >> den;
         n = num;
         if (den == 0) {
            cout << "ATTENZIONE!: denominatore nullo" << endl;
            d = 1;
            }
         else
            d = den;
         return;
         }

      // Stampa il numero razionale nella forma `n/d'.
      void stampa(ostream& s_out) {
         s_out << n << '/' << d;
         return;
         }

      // Esegue la somma tra `x' e l'oggetto di invocazione.
      Razionale somma(Razionale x) {
         Razionale risultato;
         risultato.d = d * x.d;
         risultato.n = n * x.d + x.n * d;
         return risultato;
         }
};

int main() {
   Razionale a,b,c;
   cout << "Dai la prima frazione (n/d): ";
   a.leggi(cin);
   cout << "Dai la seconda frazione (n/d): ";
   b.leggi(cin);
   c = a.somma(b);
   cout << "La somma e': ";
   c.stampa(cout);
   cout << endl;

//   system("pause");
   return 0;
}
