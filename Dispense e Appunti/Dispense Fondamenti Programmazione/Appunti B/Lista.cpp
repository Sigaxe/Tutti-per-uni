struct elem {       //necessario e comodo definire una struct esterna
    int info;
    elem* punt;
};
class Lista {
    private: elem* l;

    public:
        Lista () {l=null;}
        void inserisci_testa (int x){
            elem*t =new elem;
            t -> info=x;
            t -> punt=l;
            l=t;
            return;
        }
        void stampa(ostream& dest){
            elem* t=l;
            while (t!=null) {dest<<t -> info<<" "; t=t->punt;}
            return;
        }
        void stampa_ricorsiva(ostream& dest) {
            if (l==null) return;
            elem* t=l;
            dest<<l->info;
            l=l->punt;
            stampa(dest);
            l=t;
            return;
        }
        int lungh() const {
            int n=0;
            elem* t=l;
            while (t!=null) {n++; t=t-> punt;}
            return n;
        }
        int lungh_ricorsiva() {
            if (l==null) return 0;
            elem* t=l;
            l=l->punt;
            int n=lungh_ricorsiva() +1;
            l=t;
            return n;
        }
        int estrai_testa (){
            if (!lungh) throw "Nessun elemento da estrarre";
            int z=l -> info;
            elem* t=l;
            l=l->punt;
            delete t;
            return z;
        }
        ~Lista (){      //distruttore della classe
            while(l!=null){
                elem* t=l->punt;
                delete l;
                l=t;
            }
        }
};
