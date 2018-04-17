int ta (int c[][], d[], int N){
    for (int s=2; s<=N-1; s++)
        for (int i=0; i<=N-s;i++){
            j=i+s;
            for (int k=i+1; k<=j; k++) m_i=c[i][k]+c[k][j]+d[j]-d[i]
            if (m_i<c[i][j]) c[i][j]=m_i;
        }
}
