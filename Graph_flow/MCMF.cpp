using LL = long long;
struct MCMF
{
    struct Edge
    {
        int u, v;
        LL cost, cap;
    };
    int n, pre[MXV], cnt[MXV];
    vector<Edge> edges;
    vector<int> G[MXV];
    LL dis[MXV], ansFlow, ansCost;
    bitset<MXV> inque;
    void init(int _n)
    {
        n = _n;
        edges.clear();
        for (int i = 0; i <= n; ++i)
            G[i].clear();
    }
    void addEdge(int u, int v, LL cost, LL cap)
    {
        G[u].push_back(edges.size());
        edges.push_back({u, v, cost, cap});
        G[v].push_back(edges.size());
        edges.push_back({v, u, -cost, 0});
    }
    bool spfa(int s, int t)
    {
        queue<int> q;
        bool negative = false;
        fill(begin(dis), end(dis), INF);
        fill(begin(pre), end(pre), -1);
        fill(begin(cnt), end(cnt), 0);
        inque.reset();
        dis[s] = 0;
        cnt[s] = 1;
        q.push(s);
        inque[s] = true;
        while (!q.empty() && !negative)
        {
            int u = q.front();
            q.pop();
            inque[u] = false;
            for (int i : G[u])
            {
                Edge &e = edges[i];
                int v = e.v;
                LL cost = e.cost, cap = e.cap;
                if (dis[v] > dis[u] + cost && cap > 0)
                {
                    dis[v] = dis[u] + cost;
                    pre[v] = i;
                    if (inque[v])
                        continue;
                    q.push(v);
                    inque[v] = true;
                    ++cnt[v];
                    if (cnt[v] == n + 2)
                    {
                        negative = true;
                        break;
                    }
                }
            }
        }
        return dis[t] != INF;
    }
    LL update(int u, LL limit)
    {
        if (pre[u] == -1)
            return limit;
        int i = pre[u];
        Edge &e = edges[i];
        LL f = update(e.u, min(limit, e.cap));
        ansCost += f * e.cost;
        edges[i].cap -= f;
        edges[i ^ 1].cap += f;
        return f;
    }
    PLL sol(int s, int t)
    {
        ansFlow = ansCost = 0;
        while (spfa(s, t))
            ansFlow += update(t, INF);
        return make_pair(ansFlow, ansCost);
    }
};

/*
usage
MCMF<int> mcmf; // declare
mcmf.init(n); // initialize, n vertexs
mcmf.add_edge(x, y, z); // add edge from x to y, weight is z
mcmf.sol(s, t, d) // calculate cost flow, start from s to t max flow 
*/