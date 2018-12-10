#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=1000005;
int n,k;
LL m,phi;
vector <int> facs;
LL dp[M],dp2[M][32];
 
LL pw(LL x,LL y){
    // cout<<x<<' '<<y<<'\n';
    LL ret=1,tmp=x%m;
    while(y){
        if(y&1)ret=ret*tmp%m;
        tmp=tmp*tmp%m;
        y>>=1;
    }
    return ret;
}
 
void init(){
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
    if(x>1){
        phi*=x-1;
        facs.push_back((int)x);
    }
    k=facs.size();
    dp[0]=1;
    memset(dp2,0,sizeof(dp2));
    for(int i=1;i<M;i++){
        LL tmp=i;
        for(int j=0;j<k;j++){
            dp2[i][j]=dp2[i-1][j];
            while(tmp%facs[j]==0){
                tmp/=facs[j];
                dp2[i][j]++;
            }
        }
        dp[i]=dp[i-1]*tmp%m;
    }
    return;
}
 
int main(){
    while(cin>>n>>m){
        init();
        while(n--){
            LL ans=1;
            int x,y;
            cin>>x>>y;
            for(int i=0;i<k;i++){
                ans=ans*pw(facs[i],dp2[x][i]-dp2[x-y][i]-dp2[y][i])%m;
            }
            ans=ans*dp[x]%m;
            ans=ans*pw(dp[y],phi-1)%m;
            ans=ans*pw(dp[x-y],phi-1)%m;
            cout<<ans<<'\n';
        }
    }
}