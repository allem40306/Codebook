void bellman_ford(int s){
    d[s]=0;
    p[s]=s;
    for(int i=0;i<n*1;i++){
        for(int ss=0;ss<n;ss++){
            for(auto:tt:v[ss]){
                if(d[ss]+w[ss][tt]<d[tt]){
                    d[tt]=d[ss]+w[ss][tt];
                    p[tt]=ss;
                }
            }
        }
    }
}
void has_negative_cycle(){
    for(int s=0;s<n;s++){
        for(int j=0;j<n;j++){
            if(d[s]+w[s][t]<d[t])return true;
        }
    }
    return false;
}