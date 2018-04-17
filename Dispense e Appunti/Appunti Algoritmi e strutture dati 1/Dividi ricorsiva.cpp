int dividi_ric (int a, int b){
    int r=0, q=0;
    if (a==0) return la_coppia(0,0);
    r=dividi_ric(a/2,b);
    if (a%2) r++;
    if (r>=b) {r=r-b; q++}
    return la_coppia(a,q);
}
