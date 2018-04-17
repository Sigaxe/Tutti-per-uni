int MC (int d[], int n){
    //inizializzo i costi[i][i]=0
    for (int s=1; s<=n; s++)
        for (i=0; i<n-s; i++){
            j=i+s;
            costi[i][j]=+inf;
            for (int k=i; k<j; k++){
                c_v=costi[i][k]+costi[k+1][j];
                c_v=c_v+d[i]*d[k+1]*d[j+1];
                if (c_v<costi[i][j]){
                    costi[i][j]=c_v;
                    indice[][]=k;
                }
            }
        }
    return costi[0][n-1];
}
