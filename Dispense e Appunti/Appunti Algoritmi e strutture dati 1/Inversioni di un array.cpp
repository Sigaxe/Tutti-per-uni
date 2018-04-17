//merge sort leggermente modificato

void merge_sort_inversioni (int V[], int i, int j, int& c) {
    if (i<j) {
        k=(i+j)/2;
        merge_sort(V, i, k, c);
        merge_sort(V, k+1, j, c);
        merge(V, i, k, j, c);
    }
return;}

void merge_inversioni (int* a, int i, int j, int k, int& c){
    p_1=i;
    p_2=j+1;
    p=i;
    while (p_1<=j && p2<=k){
        if (A[p_1]<=A[p_2]) b[p]=a[p_1++];
        else {
            c+=j-p_1+1;                      //unica istruzione differente dal merge sort
            b[p]=a[p_2++];
        }
        p++;
    }
    if (p_1<j) {
        while(p_2<=k){
            b[p]=a[p_2++];
            p++;
        }
    }
    if (p_2>k){
        while (p_1<=j){
            b[p]=a[p_1++];
            p++;
        }
    }
    for (p=i; p<=k; p++)
        a[p]=b[p];
}
