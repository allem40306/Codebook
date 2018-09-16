long long f[N]={1},i,t,p;
int main(){
    for(int i=1;i<=100;i++){
        f[i]=f[i-1]*(4*i-2)%mod;
        for(t=i+1,p=mod-2;p;t=(t*t)%mod,p>>=1LL){
            if(p&1){f[i]*=t;f[i]%=mod;}
        }
    }
}