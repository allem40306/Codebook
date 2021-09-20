struct Mat
{
    int sz;
    LL x[MXN][MXN];
    Mat() { memset(x, 0, sizeof(x)); }
    Mat(int _sz)
    {
        sz = _sz;
        memset(x, 0, sizeof(x));
    }
    Mat operator*(Mat a)
    {
        Mat res(sz);
        FOR(i, 1, sz + 1) FOR(j, 1, sz + 1) FOR(k, 1, sz + 1)
        {
            res.x[i][j] += x[i][k] * a.x[k][j];
            res.x[i][j] %= MOD;
        }
        return res;
    }
    void output()
    {
        FOR(i, 1, sz + 1) FOR(j, 1, sz + 1) cout << x[i][j] << " \n"[j == sz];
    }
};