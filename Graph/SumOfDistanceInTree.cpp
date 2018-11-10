#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000,10240000")//递归太深，导致爆栈，所以使用扩栈语句
using namespace std;
 
const int N = 100009;
int dp[N] = {}, num[N];
vector<int> p[N];
bool f[N] = {};
 
void dfs(int s, int depth)
{
    int len = p[s].size();
    f[s] = 1;
    num[s] = 1;
    dp[1] += depth;
    for(int i=0; i<len; i++)
    {
        if(!f[p[s][i]])
        {
            dfs(p[s][i], depth+1);
            num[s] += num[p[s][i]];
        }
    }
}
 
void solve(int s, int n)
{
    int len = p[s].size();
    f[s] = 1;
    for(int i=0; i<len; i++)
    {
        if(!f[p[s][i]])
        {
            dp[p[s][i]] = dp[s]+n-num[p[s][i]]*2;
            solve(p[s][i], n);
        }
    }
}
 
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        p[a].push_back(b);
        p[b].push_back(a);
    }
    dfs(1, 0);
    memset(f, 0, sizeof(f));
    solve(1, n);
    for(int i=1; i<=n; i++)
        printf("%d\n", dp[i]);
    return 0;
}