//init sz=1 trie[0]=0
void insert(string s){
    int u=0,v;
    for(int i=0;i<r.size();i++){
        v=r[i]-'a';
        if(!trie[u][v]){
            memset(trie[sz],0,sizeof(trie[sz]));
            val[sz]=0;
            trie[u][v]=sz++;
        }
        u=trie[u][v];
    }
    val[u]=1;
    return;
}
void search(string s,int i){
    int u=0,v;
    dp[i]=0;
    for(int j=i;j<s.size();j++){
        v=s[j]-'a';
        if(!trie[u][v])return;
        u=trie[u][v];
        if(val[u])dp[i]=(dp[i]+dp[j+1])%MOD;
    }
    return;
}