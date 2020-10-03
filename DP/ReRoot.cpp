LL dp[MXV], num[MXV], aa[MXV], sum = 0;
vector<LL> p[MXV];
bitset<MXV> vis;

void dfs(int s, LL depth)
{
    vis[s] = 1;
    num[s] = aa[s];
    dp[1] += depth * aa[s];
    for (int v : p[s])
    {
        if (!vis[v])
        {
            dfs(v, depth + 1);
            num[s] += num[v];
        }
    }
}

void solve(int s, int n)
{
    vis[s] = 1;
    for (int v : p[s])
    {
        if (!vis[v])
        {
            dp[v] = dp[s] + sum - num[v] * 2;
            solve(v, n);
        }
    }
}