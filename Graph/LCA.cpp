const int LOG = 20;
int par[N][LOG];
int tin[N], tout[N];
int timer = 0;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    par[v][0] = p;
    for (int it : G[v])
    {
        if (it != p)
            dfs(it, v);
    }
    tout[v] = ++timer;
}

void Doubling()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < LOG; ++j)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

bool anc(int v, int u) { return tin[v] <= tin[u] && tout[u] <= tout[v]; }

int LCA(int v, int u)
{
    if (anc(v, u))
        return v;
    for (int j = LOG - 1; j >= 0; --j)
    {
        if (!anc(par[v][j], u))
            v = par[v][j];
    }
    return par[v][0];
}

int main()
{
    dfs(root, root);
    Doubling();
}