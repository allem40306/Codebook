struct edge{
    int s,t;
    LL d;
    edge(){};
    edge(int s,int t,LL d):s(s),t(t),d(d){}
};

struct heap{
    LL d;
    int p; //point
    heap(){};
    heap(LL d,int p):d(d),p(p){}
    bool operator <(const heap& b)const{
        return d>b.d;
    }
};
struct Dijkstra{
    int n,m;
    bool vis[N];
    vector<edge>edges;
    vector<int>g[N];
    LL d[N];
    int f[N];
    void init(int nn){
        n=nn;
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        edges.clear();
    }
    void add_edge(int s,int t,LL d){
        edges.push_back(edge(s,t,d));
        g[s].push_back(edges.size()-1);
    }
    void dijkstra(int ss){
        priority_queue<heap>Q;
        for(int i=0;i<n;i++){
            d[i]=INF;
        }
        d[ss]=0;
        f[ss]=-1;
        memset(vis,0,sizeof(vis));
        Q.push(heap(0,ss));
        heap x;
        while(!Q.empty()){
            x=Q.top(); Q.pop();
            int p=x.p;
            if(vis[p])continue;
            vis[p]=1;
            for(int i=0;i<g[p].size();i++){
                edge& e=edges[g[p][i]];
                if(d[e.t]>d[p]+e.d){
                    d[e.t]=d[p]+e.d;
                    f[e.t]=g[p][i];
                    Q.push(heap(d[e.t],e.t));
                }
            }
        }
    }
}d1,d2;