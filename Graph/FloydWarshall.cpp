template <typename T> struct FloydWarshall
{
    T d[MXV][MXV];
    void init() { memset(d, 0x3f, sizeof(d)); }
    void floydWarshall(int n)
    {
        for (int k = 1; k <= n; ++k)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
};

/*
usage
FloydWarshall<int> floydWarshall; // declare with distace's type
floydWarshall.init(); // initialize
FloydWarshall.floydWarshall(); // calculate all-pair shortest path
*/