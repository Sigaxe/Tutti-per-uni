int fib_1 (int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    return fib_1(n-1)+fib_2(n-2);
}

int fib_2 (int n){                      //versione che usa Teta(n) spazio
    //f new array
    f[1]=f[2]=1;
    for (int i=3; i<=n; i++) f[i]=f[i-1]+f[i-2];
    return f[n];
}

int fib_3 (int n){                      //versione che usa Teta(1) spazio
    a=b=1;
    for (int i=3; i<=n; i++) {c=a+b; a=b; b=c;}
    return b;
}
