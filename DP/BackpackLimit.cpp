struct State{
    LL w, val;
};
struct Data{
    LL v,w,m;
};

int main() {
    LL n, W;
    cin >> n >> W;
    vector<Data> d(n);
    vector<LL> dp(W + 5, -INF);
    dp[0] = 0;
    for(LL i = 0; i < n; ++i)
    {
        cin >> d[i].v >> d[i].w >> d[i].m;
    }
    deque<State> dq[MXW];
    for(int i = 0; i < n; ++i)
    {
        LL v = d[i].v, w = d[i].w, m = d[i].m;
        for(int j = 0; j <= W; ++j)
        {
            if(j < w)
            {
                dq[j].clear();
                dq[j].pb({j,dp[j]});
                continue;
            }
            int id = j % w;
            while(dq[id].front().w + m * w < j)dq[id].pop_front();
            LL tmp = dq[id].front().val + (j - dq[id].front().w) / w * v;
            while(!dq[id].empty() && dq[id].back().val + (j - dq[id].back().w) / w * v <= dp[j])
                dq[id].pop_back();
            dq[id].push_back({j,dp[j]});
            dp[j] = max(dp[j], tmp);
        }
    }
    LL ans = -INF;
    for(int i = 0; i <= W; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}