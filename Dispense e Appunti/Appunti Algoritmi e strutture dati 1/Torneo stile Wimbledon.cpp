Torneo_wimbledon(int V[], int l, int r){
    if (l==r) return V[l];
    int c=(l+r)/2
    H_1=Torneo_wimbledon(V, l, c)
    H_2=Torneo_wimbledon(V, c+1, l)
return max(H_1, H_2);}
