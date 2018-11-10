#include <bits/stdc++.h>
using namespace std;
const int N=1<<15;
int n,m,cur;
long long int dp[2][N];
 
void update(int a,int b){
    if(b&(1<<m)){
        dp[cur][b^(1<<m)]+=dp[1-cur][a];
    }
}
 
int main(){
    while(cin>>n>>m){
        if((n*m)&1){
            cout<<"0\n";
            continue;
        }
        if(n==1||m==1){
            cout<<"1\n";
            continue;
        }
        if(n<m)swap(n,m);
        memset(dp,0,sizeof(dp));
        cur=0;
        dp[0][(1<<m)-1]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cur^=1;
                memset(dp[cur],0,sizeof(dp[cur]));
                for(int k=0;k<(1<<m);k++){
                    update(k,k<<1);
                    if(i&&!(k&(1<<m-1)))update(k,(k<<1)^(1<<m)^1);
                    if(j&&!(k&1))update(k,(k<<1)^3);
                }
            }
        }
        cout<<dp[cur][(1<<m)-1]<<'\n';
    }
}