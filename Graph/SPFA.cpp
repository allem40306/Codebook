#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
 
#define S 50050
#define MAX 1e11
#define LL long long
 
using namespace std;
 
typedef struct {
    int d;
    LL l;
} XXX;
vector<XXX> map[S];
 
 
LL lon[S];
int cnt[S];
int n, m;
bool cycle;
bool inqueue[S];
 
void dfs(int start) {
    stack<int> st;
    st.push(start);
 
    bool book[S];
    memset(book, false, sizeof(book));
 
    while(!st.empty()) {
        int cur = st.top();
        // cout << cur << endl;
        st.pop();
        lon[cur] = -MAX;
        book[cur] = true;
 
        for(int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].d;
            if(!book[next]) st.push(next);
        }
    }
}
 
void spfa(int start) {
    memset(inqueue, false, sizeof(inqueue));
    for(int i = 0; i < S; i++) lon[i] = MAX;
    cycle = false;
 
    queue<int> q;
    q.push(start);
    lon[start] = 0;
    inqueue[start] = true;
 
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        inqueue[cur] = false;
        // cout << "AT: " << cur << " " << cnt[cur] << endl;
        cnt[cur]++;
        if(cnt[cur] > n) {
            dfs(cur);
            return ;
        }
 
        for(int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].d;
 
            if(lon[next] > lon[cur] + map[cur][i].l) {
                lon[next] = lon[cur] + map[cur][i].l;
                if(!inqueue[next] && cnt[cur] <= n) {
                    q.push(next);
                    inqueue[next] = true;
                }
            }
        }
    }
}
 
 
int main() {
    cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        int a, b;
        LL c;
        cin >> a >> b >> c;
 
        map[a].push_back((XXX) {b, c});
    }
 
    spfa(1);
 
    if(lon[n] >= MAX || lon[n] <= -MAX) cout << "QAQ" << endl;
    else cout << lon[n] << endl;
 
    return 0;
}