int POW(int a, int b, int mod){
    int ret = 1;
    int tmp = 1;
    for(int i = 0; i < b; i++){
        tmp *= a;
        if(tmp > mod)break;
    }
    tmp = (tmp >= mod) ? mod : 0;
    for(; b; b >>= 1){
        if(b & 1)ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret + tmp;
}

int dfs(int d, int MOD){
    if(d == n - 1){
        if(a[d] >= MOD)return (a[d] % MOD) + MOD;
        return a[d];
    }
    int k = dfs(d + 1, phi[MOD]);
    return POW(a[d], k, MOD);
}
