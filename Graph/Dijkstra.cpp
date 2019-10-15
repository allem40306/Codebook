struct Dijkstra
{
    const int INF = 1000000000;
    int d[MXV], p[MXV];
    vector<Edge> E;
    vector<int> v[MXV];
    bitset<MXV> vis;

    void init()
    {
        fill(d, d + MXV, INF);
        memset(p, 0, sizeof(p));
        E.clear();
        for (int i = 0; i < MXV; i++)
        {
            v[i].clear();
        }
        vis.reset();
    }

    void addEdge(int from, int to, int w)
    {
        v[from].push_back(E.size());
        E.push_back(Edge{from, to, w});
    }

    void dijkstra(int s)
    {
        d[s] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> states;
        vis.reset();
        states.push(MP(d[s], s));
        while (!states.empty())
        {
            PII state = states.top();
            states.pop();
            if (vis[state.second])
            {
                continue;
            }
            vis[state.second] = true;
            for (int u : v[state.second])
            {
                Edge e = E[u];
                if (d[e.to] > d[e.from] + e.w)
                {
                    d[e.to] = d[e.from] + e.w;
                    p[e.to] = e.from;
                    states.push(MP(d[e.to], e.to));
                }
            }
        }
    }
};

/*
Usage
Dijkstra dijkstra; // declare
dijkstra.init();
dijsktra.addEdge(int from, int to, int w); // add a directional Edge
dijkstra.dijkstra(int s) // calculation shortest distance from s
*/