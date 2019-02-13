struct Edge{
    int t, w;
};
int v, e;
int d[N], cnt[N];
bitset<N> inq;
queue<int>Q;
vector<Edge>G[N];

void addEdge(int from, int to, int w){
    G[from].push_back({to,w});
}

bool hasnegativeCycle(){
    while(!Q.empty())Q.pop();
    for(int i = 1; i <= v;i++){
        inq[i] = true;
        cnt[i] = d[i] = 0;
        Q.push(i);
    }
    while(!Q.empty()){
        int s = Q.front(); Q.pop();
        inq[s] = false;
        for(Edge it: G[s]){
            if(d[it.t] > d[s] + it.w){
                d[it.t] = d[s] + it.w;
                if(inq[it.t])continue;
                Q.push(it.t);
                inq[it.t] = true;
                if(++cnt[it.t] > v)return true;
            }
        }
    }
    return false;
}