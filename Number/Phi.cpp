LL phi(LL m){
    facs.clear();
    LL x=m,sq=(LL)sqrt(m);
    phi=1;
    for(LL i=2;i<=sq;i++){
        if(x%i)continue;
        phi*=i-1; x/=i;
        facs.push_back(i);
        while(x%i==0){
            phi*=i;
            x/=i;
        }
    }
    if(x>1)phi*=x-1;
    return phi;
}