void merge_sort (int V[], int i, int j) {
    if (i<j) {
        k=(i+j)/2;
        merge_sort(V, i, k);
        merge_sort(V, k+1, j);
        merge(V, i, k, j);          //algoritmo di unione degli array
    }
return;}

void merge_sort_versione_cormen (A, i, j, k){
    int n1=j-i+1;
    int n2=k-j;
    L = new array [n1];
    R = new array [n2];
    for (h=0; h<n; h++) {
        L[h]=A[i+h];
        R[h]=A[j+h-1];
    }
    L[n1]= infinito     //sentinella di L
    R[n2]= infinito     //sentinella di R

    //comincia l'algoritmo vero e proprio
    p_1=0;
    p_2=0;
    for (int p=i; p<=k,p++) {
        if (L[p_1]<= R[p_2]){
            A[p]=L[p_1];
            p++;
        }
        else {
            A[p]=R[p_2];
            p++;
        }
    }
}

void mergesort(A[], int s, int c, int e){   //versione del merge sort senza merge ma con sentinelle
    int i=s;
    int* B = new array [n];
    int j=c+1;
    int k=0;
    while (i<=c && j<=e) {
        if (A[i]<=A[j]) B[k++]=A[i++];
        else B[k++]=A[j++]              //può capitare che una delle due parti si esaurisca
    }
    while (i<=c) B[k++]=A[i++];
    while (j<=e) B[k++]=A[j++];
    for (i=s; i<=e; i++){
       //completare
    }
return;}
