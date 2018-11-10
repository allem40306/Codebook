#include <iostream>
 
#define INF 1e9
#define LL long long
 
using namespace std;
 
int main() {
    int n;
 
    while(cin >> n) {
        LL dis[n][n];
        LL ans = INF;
 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                cin >> dis[i][j];
                if(dis[i][j] == 0) dis[i][j] = INF;
            }
 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                ans = min(ans, dis[i][j] + dis[j][i]);
                for(int k = 0; k < n; k++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
 
                    ans = min(ans, dis[i][j] + dis[k][i] + dis[j][k]);
                }
            }
        }
 
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
 
    return 0;
}