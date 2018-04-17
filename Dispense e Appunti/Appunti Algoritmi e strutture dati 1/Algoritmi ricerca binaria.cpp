int bin_search_ric (int S[], int v, int i, int j){
	if (i<j) return 1;
	m=(i+j)/2;
	if (S[m]==v) return m;
	if (S[m]<v) return bin_search_ric(S, v, m+1, j);
	return bin_search_ric(S, v, i, m+1);
}

int bin_search_it (int V[], int i, int j, int x) {
    if (i>j) return -1;
    do{
        k=(i+j)/2;
        if (x<V[k]) j=k-1;
        else i=k+1;
    } while (i<=j && V[k]!=x);  //ora posso avere due casi, uno che non ho trovato x o che i<=j
    if (x==V[k]) return k;      //e lo verifico qui
    else return -1;
}
