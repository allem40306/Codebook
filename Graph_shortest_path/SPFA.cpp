struct Edge
{
    int at;
    long long cost;
};
int n;
long long dis[MAXN];
vector<Edge> G[MAXN];
void init()
{
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
        dis[i] = INF;
    }
}
bool SPFA(int st)
{
    vector<int> cnt(n, 0);
    vector<bool> inq(n, false);
    queue<int> q;

    q.push(st);
    dis[st] = 0;
    inq[st] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        inq[now] = false;
        for (auto &e : G[now])
        {
            if (dis[e.at] > dis[now] + e.cost)
            {
                dis[e.at] = dis[now] + e.cost;
                if (!inq[e.at])
                {
                    cnt[e.at]++;
                    if (cnt[e.at] > n)
                    {
                        // negative cycle
                        return false;
                    }
                    inq[e.at] = true;
                    q.push(e.at);
                }
            }
        }
    }
    return true;
}