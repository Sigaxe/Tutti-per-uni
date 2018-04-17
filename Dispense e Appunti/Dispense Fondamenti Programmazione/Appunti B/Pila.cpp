class Pila{                             //Pila chiamata anche Stack
    private:
        int* A;                         //puntatore alla pila
        int top;                        //numero di elementi nello stack
        int dim;                        //dimensione totale dello stack
        void allarga(){                 //funzione per aumentare di 10 la dimensione della pila
            int* temp= new int[dim+10]; //dichiaro un puntatore e un array temporaneo
            for (int i=0; i<dim; i++)
                temp[i]=A[i];           //copio tutti i valori della pila nel temporaneo
            delete[] A;                 //libero la memoria degli elementi puntati dall'array
            A=temp;                     //faccio ri-puntare A alla nuova pila temporanea (ora effettiva)
            dim+=10;                    //aumento la dimensione
            return;
        }
    public:
        Pila() {A=null;top=0;dim=0;}    //costruttore senza parametri: puntatore vuoto, no top, dimensione zero
        void push(int x) {
            if (top==dim) allarga();
            A[top]=x;
            top++;
            return;
        }
        int pop (){
            if  (top==0) throw "Pila vuota";
            top--;
            return A[top];
        }
        bool empty(){return (top==0 ? true : false)}
        int capacity() {return dim;}
};
