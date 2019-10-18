int MST()
{
    DisjointSet djs;
    vector<Edge> edges;
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0, from, to, w; i < m; i++)
    {
        cin >> from >> to >> w;
        edges.push_back({from, to, w});
    }
    sort(edges.begin(), edges.end());
    djs.init(n);
    for (auto edge : edges)
    {
        // Union also check if to vertex haven't connected   
        if (djs.Union(edge.from, edge.to))
        {
            ans += edge.w;
        }
    }
    return ans;
}