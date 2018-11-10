#include <iostream>
#include <stack> 
#include <vector>
#include <cstring>
 
#define S 50050
 
using namespace std;
 
vector<int> map[S];
stack<int> ans;
int state[S];
bool head[S];
bool valid;
int n, m;
 
void dfs(int cur) {
    state[cur] = 1;
 
    for(auto next : map[cur])
        if(!state[next]) dfs(next);
        else if(state[next] == 1) {
            valid = false;
            return ;
        }
 
    state[cur] = 2;
 
    ans.push(cur);
}
 
void topology_sort() {
    for(int i = 1; i <= n; i++) 
        if(valid && head[i]) dfs(i);
     
    if(!valid) {
        cout << -1 << endl;
        return ;
    }
 
    while(!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
}
 
int main() {
    cin >> n >> m;
 
    memset(head, true, sizeof(head));
 
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
 
        head[b] = false;
 
        map[a].push_back(b);
    }
 
    memset(state, 0, sizeof(state));
    valid = true;
 
    topology_sort();
 
    return 0;
}