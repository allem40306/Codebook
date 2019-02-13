struct Edge{
    int from,to,w;
};
vector<Edge>E;
vector<int>v[N];
bitset<N> vis;
void init(){
    E.clear();
    for(int i=0;i<N;i++){
        v[i].clear();
    }
}

void addEdge(int from,int to,int w){
    v[from].push_back(E.size());
    E.push_back(Edge{from,to,w});
}

void dijkstra(int s,int d[],int p[]){// set d[] INF && set p[] -1
    d[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>>pq;
    vis.reset();
    pq.push(MP(d[s],s));
    while(!pq.empty()){
        PII k=pq.top(); pq.pop();
        if(vis[k.second])continue;
        vis[k.second]=true;
        for(auto it:v[k.second]){
            Edge e=E[it];
            if(d[e.to]>d[e.from]+e.w){
                d[e.to]=d[e.from]+e.w;
                p[e.to]=e.from;
                pq.push(MP(d[e.to],e.to));
            }
        }
    }
}