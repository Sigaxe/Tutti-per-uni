void quickSort(int A[],int i,int f)
{
    int m;
    if(i>=f)
        return;
    m=f_partition(A,i,f);
    quickSort(A,i,m-1);
    quickSort(A,m+1,f);
}
int f_partition(int A[],int i,int f)
{
    int inf=i,sup=f;
    while(inf<=sup){
        while(A[sup]>A[i])
            sup--;
        while(inf<=sup&&A[inf]<=A[i])
            inf++;
        if(inf<sup){
            scambia(A,inf,sup);
            inf++;
            sup--;
        }
    }
    scambia(A,i,sup);
    return sup;
}

