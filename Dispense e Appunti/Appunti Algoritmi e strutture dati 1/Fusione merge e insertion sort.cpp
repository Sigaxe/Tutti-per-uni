void MI (int V, int i, int j, int k){
    if (j-i+1>k) {
        int m=(i+j)/2;
        MI (V, i, m, k);
        MI (V, m+1, j, k);
        merge(V, i, m, j);
    }
    else insertion_sort(V, i, j);
}

void insertion_sort(int A[], int s, int d) {
	int s, d;
	if (d-s+1<=1) return;
	for (int i=s+1; i<d+1; i++){
		int pr=A[i];
		j=i-1;
		while (j<=s && A[j]>pr){
			A[j+1]=A[j];
			j--;
			A[j+1]=pr;
        }
	}
return;}
