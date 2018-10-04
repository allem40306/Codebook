void btb(int &x){
	x=0;
	for(int i=0,j=1;i<n;i++,j*=2)x+=b[i]*j;
	return;
}
int main(){
	memset(dp,0,sizeof(dp));
    for(int i=1,st;i<=n;i++){//st:state
        for(int jj=0;jj<n;jj++)b[n-jj-1]=(jj<i);
        do{
            btb(st);
            for(int x=0;x<n;x++){
                if(!b[x])continue;
                if(i==1)dp[x][st]=dis[x][0];
                for(int y=0;y<n;y++){
                    if(x!=y&&b[y]&&(dp[x][st]==0||dp[x][st]>dp[y][st-(1<<x)]+dis[y][x])){
                        dp[x][st]=dp[y][st-(1<<x)]+dis[y][x];
                    }
                }
            }
        }while(next_permutation(b,b+n));
    }
    cout<<dp[0][(1<<n)-1]<<'\n';
}