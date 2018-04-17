int trova_k (int V[], int n){
    if (V[n-1]==0) return n;
    else if (V[0]==1) return 0;
    else return cerca_k (V, 0, n-1);
}

int cerca_k (int V[], int i, int j){
    if (V[i]==0){
        if (2*i+1<j) return cerca_k (v, 2*i+1, j);
        else return ricerca_binaria (V, i, j);
    }
    return ricerca_binaria (V, i/2, i);
}


int ric_a_salti_it (int V, int n){
    int i=0;
    while (i<=n-1 && V[i]==i+1) i=2*i+1;    //questo sarebbe il "salto"
    if (i==0) return i+1;
    if (i>n+1) return ric_bin (V, i/2, n-1);
    else return ric_bin (V, i/2, i);
}
