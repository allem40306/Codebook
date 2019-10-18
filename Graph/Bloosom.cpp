int lca(int x, int y)
{
    MSET(vis, false);
    while (true)
    {
        x = base[x];
        vis[x] = true;
        if (match[x] ==−1)
            break;
        x = fr[match[x]];
    }
    while (true)
    {
        y = base[y];
        if (vis[y])
            return y;
        y = fr[match[y]];
    }
    return −1;
}
void set_path(int x, int fa)
{
    int y;
    while (x != fa)
    {
        y = match[x];
        blossom[base[x]] = true;
        blossom[base[y]] = true;
        y = fr[y];
        if (base[y] != fa)
            fr[y] = match[x];
        x = y;
    }
}
void flower(int x, int y)
{
    MSET(blossom, false);
    int fa = lca(x, y);
    set_path(x, fa);
    set_path(y, fa);
    if (base[x] != fa)
        fr[x] = y;
    if (base[y] != fa)
        fr[y] = x;
    REP(i, 1, n)
    if (blossom[base[i]])
    {
        base[i] = fa;
        if (!inq[i])
        {
            q.push(i);
            inq[i] = true;
        }
    }
}
bool bfs(int root)
{
    int cur, y, nxt;
    q = queue<int>();
    MSET(inq, false);
    MSET(fr,−1);
    REP(i, 1, n) base[i] = i;
    q.push(root);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        inq[cur] = false;
        for (int i = first[cur]; ~i; i = in[i].next)
            if (base[cur] != base[in[i].t] && match[cur] != in[i].t)
            {
                if (in[i].t == root || (~match[in[i].t] && ~fr[match[in[i].t]]))
                    flower(cur, in[i].t);
                else if (fr[in[i].t] == −1)
                {
                    fr[in[i].t] = cur;
                    if (match[in[i].t] == −1)
                    {
                        cur = in[i].t;
                        while (cur !=−1)
                        {
                            y = fr[cur];
                            nxt = match[y];
                            match[cur] = y;
                            match[y] = cur;
                            cur = nxt;
                        }
                        return true;
                    }
                    else
                    {
                        q.push(match[in[i].t]);
                        inq[match[in[i].t]] = true;
                    }
                }
            }
    }
    return false;
}
int do_match()
{
    int re = 0;
    MSET(match,−1);
    REP(i, 1, n) if (match[i] == −1 && bfs(i)) re++;
    return re;
}