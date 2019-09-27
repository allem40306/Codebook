PII treeCentroid(int u, int f, int sz)
{
    // cout << u << ' ' << f << ' ' << sz << '\n';
    treeSz[u] = 1;
    PII res(__INT_MAX__, -1);
    int mx = 0;
    for(size_t i = 0; i != G[u].size(); ++i)
    {
        PII &e = G[u][i];
        int v = e.first;
        if(v == f || vis[v] == true)
        {
            continue;
        }
        res = min(res, treeCentroid(v, u, sz));
        // cout << u << ' ' << res.first << ' '<< res.second << '\n';
        treeSz[u] += treeSz[v];
        mx = max(mx, treeSz[v]);
    }
    mx = max(mx, sz - treeSz[u]);
    // cout << u << ':' << mx << ' ' << u << '\n';
    return min(res, {mx, u});
}