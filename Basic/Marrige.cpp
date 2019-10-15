int t, n, b[N][N], bi[N], g[N][N], bg[N], gb[N];

void sol()
{
    deque<int> dq;
    memset(gb, 0, sizeof(gb));
    memset(bi, 0, sizeof(bi));
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    while (!dq.empty())
        {
            int x = dq.front();
            dq.pop_front();
            int y = b[x][++bi[x]];
            if (!gb[y])
                {
                    gb[y] = x;
                    bg[x] = y;
                }
            else if (g[y][x] < g[y][gb[y]])
                {
                    dq.push_back(gb[y]);
                    gb[y] = x;
                    bg[x] = y;
                }
            else
                {
                    dq.push_back(x);
                }
        }
    for (int i = 1; i <= n; i++)
        {
            cout << bg[i] << '\n';
        }
}

int main()
{
    int x;
    cin >> t;
    for (int i = 0; i < t; i++)
        {
            cin >> n;
            for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                        {
                            cin >> b[i][j];
                        }
                }
            for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                        {
                            cin >> x;
                            g[i][x] = j;
                        }
                }
            if (i)
                cout << '\n';
            sol();
        }
}