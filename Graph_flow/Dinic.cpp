using LL = long long;
struct Dinic
{
    int n, s, t, level[MXV], now[MXV];
    struct Edge
    {
        int v;
        LL rf; // rf: residual flow
        int re;
    };
    vector<Edge> e[MXV];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i <= n; i++)
            e[i].clear();
    }
    void add_edge(int u, int v, LL f)
    {
        e[u].push_back({v, f, (int)e[v].size()});
        e[v].push_back({u, f, (int)e[u].size() - 1});
        // for directional graph
        // e[v].push_back({u, 0, (int)e[u].size() - 1});
    }
    bool bfs()
    {
        fill(level, level + n + 1, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto it : e[u])
            {
                if (it.rf > 0 && level[it.v] == -1)
                {
                    level[it.v] = level[u] + 1;
                    q.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    LL dfs(int u, LL limit)
    {
        if (u == t)
            return limit;
        LL res = 0;
        while (now[u] < (int)e[u].size())
        {
            Edge &it = e[u][now[u]];
            if (it.rf > 0 && level[it.v] == level[u] + 1)
            {
                LL f = dfs(it.v, min(limit, it.rf));
                res += f;
                limit -= f;
                it.rf -= f;
                e[it.v][it.re].rf += f;
                if (limit == 0)
                    return res;
            }
            else
                ++now[u];
        }
        if (!res)
            level[u] = -1;
        return res;
    }
    LL flow(LL res = 0)
    {
        while (bfs())
        {
            memset(now, 0, sizeof(now));
            res += dfs(s, INF);
        }
        return res;
    }
};

/*
usage
Dinic dinic; // declare
dinic.init(n, s, t); // initialize, n vertexs, start from s to t
dinic.add_edge(x, y, z); // add edge from x to y, weight is z
dinic.flow() // calculate max flow 
*/