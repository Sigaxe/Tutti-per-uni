int cr (int p[], int n){
    if (n==0) return 0;
    q=-inf;                         //valore necessario per partire da zero
    for (i=1; i<=n; i++) q=max(q, p[i]+cr(p, n-i));
    return q;
}

{// queste due viaggiano in gruppo
int mcr (int p[], int n){           //versione Memorizzata
    //r new array
    for (i=0; i<=n; i++) r[i]=-inf;
    return mcra(p, n, r)
}
int mcra (int p[], int n, int r[]){
    if (r[n]>0) return r[n];        //significa che è già stato calcolato
    if (n==0) q=0;
    else {
        q=-inf;
        for (int i=1; i<=n; i++) q=max(q; p[i]+mcra(p, n-1, r));
        r[n]=q;
    }
    return q;
}
}

{//anche queste viaggiano in blocco
int bucr (int p[], int n){          //Bottom-Up cr, con approccio iterativo
    //r new array
    r[0]=0;
    for (j=1; j<=n; j++){
        p=-inf;
        for (int i=1; i<=j; i++) q=max(q, p[i]+r[j-i]);
    }
    return r[n];                    //questo restituisce il valore della soluzione ma non la soluzione completa
}

int Estreso_bucr (int p[], int n){
    // r,s new array di dimensione n+1
    r[0]=0;
    for (j=1; j<=n; j++){
        p=-inf;
        for (int i=1; i<=j; i++){
            if (q<p[i]+r[j-i]){
                q=p[i]+r[j-i]);
                s[j]=i;
                r[j]=q
            }
        }
    }
    return //coppia (r,s);
}

int pcrs (int p[], int n){
    (r,s)=Esteso_bucr(p,n)
    while (n>0){
        //stampa s[n]
        n=n-s[n];
    }
}

}
