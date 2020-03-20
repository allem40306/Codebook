const int LOG = 20;
vector<int> tin(MXV), tout(MXV), depth(MXV);
int par[MXV][LOG];
int timer = 0;
vector<int> G[MXV];

void dfs(int u, int f)
{
    tin[u] = ++timer;
    par[u][0] = f;
    for (int v : G[u])
    {
        if (v != f)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

void Doubling(int n)
{
    for (int j = 1; j < LOG; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

bool anc(int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; }

int LCA(int u, int v)
{
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    if (anc(u, v))
    {
        return u;
    }
    for (int j = LOG - 1; j >= 0; --j)
    {
        if (!anc(par[u][j], v))
            u = par[u][j];
    }
    return par[u][0];
}

int dis(int u, int v)
{
    int lca = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

/*
dfs(root, root);
Doubling(n);
*/