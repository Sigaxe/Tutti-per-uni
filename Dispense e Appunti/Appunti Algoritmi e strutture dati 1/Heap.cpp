struct heap{        //dichiarazione struttura heap
    int V[101];     //vettore che contiene l'albero
    int n;          //dimensione del vettore, alias numero di nodi
};

void fixup(heap& H,int k){  //aggiusta il percorso dell'heap che parte dala foglia k
    while((k>1)&&(H.V[k/2]<H.V[k])){
            scambia(H.V,k/2,k);
            k=k/2;
    }
    return;
}

void fixdown(heap& H,int k){  //aggiusta il sottoheap che ha come radice il nodo k
    int j=2*k;                // nell'ipotesi che il sottoalbero radicato in k soddisfi le regole, eccetto in k
    if(j<=H.n){
        if((j<H.n)&&(H.V[j]<H.V[j+1]))
            j++;
        if(H.V[k]<H.V[j]){
            scambia(H.V,k,j);
            fixdown(H,j);
        }
    }
    return;
}

void f_insert(heap& H,int x){   //inserisce l'elemento x nell'albero in modo corretto
    H.V[++H.n]=x;
    fixup(H,H.n);
}

void buildHeap(heap& H){        //costruisce un heap a partire da un array generico
    for(int j=(H.n)/2;j>=1;j--)
        fixdown(H,j);
}

void heapSort(int A[],int d){   //ordina l'array V
    heap H;
    int i;
    for(i=0;i<d;i++)
        H.V[i+1]=A[i];
    H.n=d;
    buildHeap(H);
    for(i=d-1;i>=0;i--)
        A[i]=getmax(H);
    return;
}

int getmax(heap& H){   //estrae il massimo dall'heap e lo riordina
    int massimo=H.V[1];
    scambia(H.V,1,H.n);
    H.n--;
    fixdown(H,1);
    return massimo;
}
