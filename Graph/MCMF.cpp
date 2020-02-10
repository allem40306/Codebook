template <typename T> struct MCMF
{
    int n, pre[MXV];
    T dis[MXV], cap[MXV][MXV], flow[MXV][MXV], cost[MXV][MXV];
    vector<int> edges[MXV];
    bitset<MXV> inque;
    queue<int> q;
    void init(int _n)
    {
        n = _n;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));
        for (int i = 0; i <= n; ++i)
        {
            edges[i].clear();
        }
    }
    void addEdge(int u, int v, T c)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
        cost[u][v] = cost[v][u] = c;
    }
    bool spfa(int s, int t)
    {
        fill(begin(dis), end(dis), INF);
        inque.reset();
        while (!q.empty())
        {
            q.pop();
        }
        dis[s] = 0;
        q.push(s);
        inque[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inque[u] = false;
            for (int v : edges[u])
            {
                if (flow[v][u] > 0 && dis[v] > dis[u] + (-cost[v][u]))
                {
                    dis[v] = dis[u] + (-cost[v][u]);
                    pre[v] = u;
                    if (!inque[v])
                    {
                        q.push(v);
                        inque[v] = true;
                    }
                }
                else if (cap[u][v] > flow[u][v] && dis[v] > dis[u] + cost[u][v])
                {
                    dis[v] = dis[u] + cost[u][v];
                    pre[v] = u;
                    if (!inque[v])
                    {
                        q.push(v);
                        inque[v] = true;
                    }
                }
            }
        }
        return dis[t] != INF;
    }
    void update(int s, int t, T bottleneck)
    {
        for (int u = t; u != s; u = pre[u])
        {
            flow[pre[u]][u] += bottleneck;
            flow[u][pre[u]] -= bottleneck;
        }
    }
    T findbottleneck(int s, int t)
    {
        T bottleneck = INF;
        for (int u = t; u != s; u = pre[u])
        {
            bottleneck = min(bottleneck, cap[pre[u]][u] - flow[pre[u]][u]);
        }
        return bottleneck;
    }
    void sol(int s, int t)
    {
        T mnCost = 0, mxFlow = 0;
        while (spfa(s, t))
        {
            T bottleneck = findbottleneck(s, t);
            update(s, t, bottleneck);
            mxFlow += bottleneck;
            mnCost += bottleneck * dis[t];
        }
    }
};